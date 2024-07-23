#include "Shows.hpp"
#include "game/backend/NativeHooks.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Scripts.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Player.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Players.hpp"

#include <network/CNetObjectMgr.hpp>

namespace YimMenu::Submenus
{
	enum class ActorOverrideType
	{
		DEFAULT,
		SELF,
		PLAYER
	};

	struct ActorDefinition
	{
		ActorOverrideType Type = ActorOverrideType::DEFAULT;
		Player OverridePlayer{};
	};

	enum class SceneType
	{
		CAN_CAN_01,
		CAN_CAN_02,
		FIRE_BREATHER,
		FIRE_DANCER_01,
		FIRE_DANCER_02,
		SNAKE_DANCER_01,
		SNAKE_DANCER_02,
		SWORD_DANCER,
		ODD_FELLOWS,
		ESCAPE_ARTIST,
		FLEX_FIGHT,
		BAND_01,
		BAND_02,
	};

	constexpr auto g_SceneTypeScripts = std::to_array({
	    "show_mp_nbx_cancan_01"_J,
	    "show_mp_nbx_cancan_02"_J,
	    "show_mp_nbx_firebreath"_J,
	    "show_mp_nbx_firedance_01"_J,
	    "show_mp_nbx_firedance_02"_J,
	    "show_mp_nbx_snakedance_01"_J,
	    "show_mp_nbx_snakedance_02"_J,
	    "show_mp_nbx_sworddancer"_J,
	    "show_mp_nbx_oddfellows"_J,
	    "show_mp_nbx_escapeartist"_J,
	    "show_mp_nbx_flexfight"_J,
	    "show_mp_nbx_bigband_01"_J,
	    "show_mp_nbx_bigband_02"_J,
	});

	constexpr auto g_SceneTypeStrs = std::to_array({
	    "Cancan Dance (1)",
	    "Cancan Dance (2)",
	    "Fire Breather Dance",
	    "Fire Dance (1)",
	    "Fire Dance (2)",
	    "Snake Dance (1)",
	    "Snake Dance (2)",
	    "Sword Dance",
	    "Odd Fellows Scene",
	    "Escape Artist Scene",
	    "Flex Fight Scene",
	    "Band (Telephone)",
	    "Band (Saint Denis)",
	});

	// dances
	static ActorDefinition g_CanCanDancerOverrides[4];
	static ActorDefinition g_CanCanDanceConductorOverride;
	static ActorDefinition g_FireBreatherOverride;
	static ActorDefinition g_FireDancerOverride;
	static ActorDefinition g_SnakeDancerOverride;
	static ActorDefinition g_SwordDancerOverride;
	// scene
	static ActorDefinition g_OddFellowsMarjorieOverride;
	static ActorDefinition g_OddFellowsBruteOverride;
	static ActorDefinition g_OddFellowsMagnificoOverride;
	static ActorDefinition g_OddFellowsAudienceMemberOverride;
	static ActorDefinition g_EscapeArtistOverride;
	static ActorDefinition g_EscapeArtistAssistantOverride;
	static ActorDefinition g_FlexFightStrongwomanOverride;
	static ActorDefinition g_FlexFightAudienceMemberOverride;
	// band
	static ActorDefinition g_BandBassistOverride;
	static ActorDefinition g_BandDrummerOverride;
	static ActorDefinition g_BandPianistOverride;
	static ActorDefinition g_BandSingerOverride;

	// data
	static SceneType g_SelectedSceneType = SceneType::CAN_CAN_01;
	static int g_RunningSceneScriptID    = -1;
	static std::vector<::Entity> g_ShowEntities;

	static SceneType SceneTypeFromScript(joaat_t script)
	{
		for (auto i = 0; i < g_SceneTypeScripts.size(); i++)
			if (g_SceneTypeScripts[i] == script)
				return SceneType(i);

		return SceneType(0); // should not reach here
	}

	static Ped ProcessActorDef(ActorDefinition& def)
	{
		if (def.Type == ActorOverrideType::DEFAULT)
			return nullptr;
		else if (def.Type == ActorOverrideType::SELF)
			return Self::GetPed();
		else
		{
			if (!def.OverridePlayer.IsValid())
				return -1;

			return def.OverridePlayer.GetPed();
		}
	}

	static Ped GetOverridePed(SceneType sceneType, joaat_t hash)
	{
		if (sceneType == SceneType::CAN_CAN_01 || sceneType == SceneType::CAN_CAN_02)
		{
			switch (hash)
			{
			case "CS_CANCAN_01"_J: return ProcessActorDef(g_CanCanDancerOverrides[0]);
			case "CS_CANCAN_02"_J: return ProcessActorDef(g_CanCanDancerOverrides[1]);
			case "CS_CANCAN_03"_J: return ProcessActorDef(g_CanCanDancerOverrides[2]);
			case "CS_CANCAN_04"_J: return ProcessActorDef(g_CanCanDancerOverrides[3]);
			case "CS_CANCANMAN_01"_J: return ProcessActorDef(g_CanCanDanceConductorOverride);
			}
		}
		else if (sceneType == SceneType::FIRE_BREATHER && hash == "CS_FIRE_BREATHER"_J)
		{
			return ProcessActorDef(g_FireBreatherOverride);
		}
		else if ((sceneType == SceneType::FIRE_DANCER_01 || sceneType == SceneType::FIRE_DANCER_02) && hash == "CS_FIRE_BREATHER"_J)
		{
			return ProcessActorDef(g_FireDancerOverride);
		}
		else if ((sceneType == SceneType::SNAKE_DANCER_01 || sceneType == SceneType::SNAKE_DANCER_02) && hash == "CS_SWORDDANCER"_J)
		{
			return ProcessActorDef(g_SnakeDancerOverride);
		}
		else if (sceneType == SceneType::SWORD_DANCER && hash == "CS_SWORDDANCER"_J)
		{
			return ProcessActorDef(g_SwordDancerOverride);
		}
		else if (sceneType == SceneType::ODD_FELLOWS)
		{
			switch (hash)
			{
			case "CS_MISSMARJORIE"_J: return ProcessActorDef(g_OddFellowsMarjorieOverride);
			case "CS_ODDFELLOWSPINHEAD"_J: return ProcessActorDef(g_OddFellowsBruteOverride);
			case "CS_MAGNIFICO"_J: return ProcessActorDef(g_OddFellowsMagnificoOverride);
			case "U_M_M_ODDFELLOWPARTICIPANT_01"_J: return ProcessActorDef(g_OddFellowsAudienceMemberOverride);
			};
		}
		else if (sceneType == SceneType::ESCAPE_ARTIST)
		{
			switch (hash)
			{
			case "CS_ESCAPEARTIST"_J: return ProcessActorDef(g_EscapeArtistOverride);
			case "CS_ESCAPEARTISTASSISTANT"_J: return ProcessActorDef(g_EscapeArtistAssistantOverride);
				// note that the band member isn't actually used in the scene, so we aren't adding an override for that
			};
		}
		else if (sceneType == SceneType::FLEX_FIGHT)
		{
			switch (hash)
			{
			case "CS_FEATSOFSTRENGTH"_J: return ProcessActorDef(g_FlexFightStrongwomanOverride);
			case "U_M_M_ODDFELLOWPARTICIPANT_01"_J: return ProcessActorDef(g_FlexFightAudienceMemberOverride);
			};
		}
		else if (sceneType == SceneType::BAND_01 || sceneType == SceneType::BAND_02)
		{
			switch (hash)
			{
			case "CS_BANDBASSIST"_J: return ProcessActorDef(g_BandBassistOverride);
			case "CS_BANDDRUMMER"_J: return ProcessActorDef(g_BandDrummerOverride);
			case "CS_BANDPIANIST"_J: return ProcessActorDef(g_BandPianistOverride);
			case "CS_BANDSINGER"_J: return ProcessActorDef(g_BandSingerOverride);
			};
		}

		return nullptr;
	}

	static void CREATE_PED(rage::scrNativeCallContext* ctx)
	{
		auto override = GetOverridePed(SceneTypeFromScript(SCRIPTS::GET_HASH_OF_THIS_SCRIPT_NAME()), ctx->GetArg<Hash>(0));
		if (override)
		{
			ctx->SetReturnValue(override.GetHandle());
			return;
		}

		auto ped = PED::CREATE_PED(ctx->GetArg<Hash>(0), ctx->GetArg<float>(1), ctx->GetArg<float>(2), ctx->GetArg<float>(3), ctx->GetArg<float>(4), ctx->GetArg<int>(5), ctx->GetArg<int>(6), ctx->GetArg<int>(7), ctx->GetArg<int>(8));
		g_ShowEntities.push_back(ped);
		ctx->SetReturnValue(std::move(ped));
	}

	static void CREATE_OBJECT(rage::scrNativeCallContext* ctx)
	{
		auto obj = OBJECT::CREATE_OBJECT(ctx->GetArg<int>(0), ctx->GetArg<float>(1), ctx->GetArg<float>(2), ctx->GetArg<float>(3), ctx->GetArg<int>(4), ctx->GetArg<int>(5), ctx->GetArg<int>(6), ctx->GetArg<int>(7), ctx->GetArg<int>(8));
		if (ctx->GetArg<int>(0) == -262339715)
		{
			// hide curtain
			ENTITY::SET_ENTITY_VISIBLE(obj, false);
			ENTITY::SET_ENTITY_COLLISION(obj, false, false);
		}
		g_ShowEntities.push_back(obj);
		ctx->SetReturnValue<int>(std::move(obj));
	}

	static void NETWORK_HAS_CONTROL_OF_ENTITY(rage::scrNativeCallContext* ctx)
	{
		ctx->SetReturnValue(TRUE);
	}

	static void CREATE_ANIM_SCENE(rage::scrNativeCallContext* ctx)
	{
		int handle = ANIMSCENE::_CREATE_ANIM_SCENE(ctx->GetArg<char*>(0), ctx->GetArg<int>(1), ctx->GetArg<char*>(2), ctx->GetArg<int>(3), ctx->GetArg<int>(4));
		FiberPool::Push([handle] {
			CAnimScene* scene = nullptr;
			Pointers.GetAnimSceneFromHandle(&scene, handle);
			if (scene)
			{
				char data[0x400];
				auto net = *(rage::netObject**)((__int64)scene + 0x30);
				for (auto& [id, player] : Players::GetPlayers())
				{
					if (id != Self::GetPlayer().GetId())
					{
						rage::datBitBuffer buffer(data, sizeof(data));
						(*Pointers.NetworkObjectMgr)->PackCloneCreate(net, player.GetHandle(), &buffer);
					}
				}
			}
		});
		ctx->SetReturnValue(std::move(handle));
	}

	inline void RenderActorDef(ActorDefinition& def, const std::string& name)
	{
		ImGui::SetNextItemWidth(100);
		ImGui::Combo(name.c_str(), (int*)&def.Type, "Default\0Yourself\0Player\0");
		if (def.Type == ActorOverrideType::PLAYER)
		{
			ImGui::SameLine();
			auto player_name = def.OverridePlayer.IsValid() ? def.OverridePlayer.GetName() : "<SELECT>";
			ImGui::SetNextItemWidth(150);
			if (ImGui::BeginCombo(("##playerselect" + name).c_str(), player_name))
			{
				for (auto& [id, plyr] : Players::GetPlayers())
				{
					if (!plyr.IsValid())
						continue;

					if (ImGui::Selectable(plyr.GetName(), plyr == def.OverridePlayer))
					{
						def.OverridePlayer = plyr;
					}

					if (plyr == def.OverridePlayer)
						ImGui::SetItemDefaultFocus();
				}
				ImGui::EndCombo();
			}
		}
	}

	void RenderShowsMenu()
	{
		static bool _run_once = ([] {
			for (auto& script : g_SceneTypeScripts)
			{
				NativeHooks::AddHook(script, NativeIndex::CREATE_PED, CREATE_PED);
				NativeHooks::AddHook(script, NativeIndex::NETWORK_HAS_CONTROL_OF_ENTITY, NETWORK_HAS_CONTROL_OF_ENTITY);
				NativeHooks::AddHook(script, NativeIndex::CREATE_OBJECT, CREATE_OBJECT);
				NativeHooks::AddHook(script, NativeIndex::_CREATE_ANIM_SCENE, CREATE_ANIM_SCENE);
			}
			return true;
		})();

		ImGui::Text("Warning: Modders might prevent themselves from being forced into shows");

		if (ImGui::Button("Teleport to Theater"))
		{
			FiberPool::Push([] {
				Self::GetPed().SetPosition({2546.5646f, -1301.4119f, 48.3564f});
			});
		}
		ImGui::SameLine();
		if (ImGui::Button("Unlock Theater Door"))
		{
			FiberPool::Push([] {
				if (OBJECT::IS_DOOR_REGISTERED_WITH_SYSTEM(340151973))
					OBJECT::DOOR_SYSTEM_SET_DOOR_STATE(340151973, 0);
			});
		}
		ImGui::SameLine();
		if (ImGui::Button("Lock Theater Door"))
		{
			FiberPool::Push([] {
				if (OBJECT::IS_DOOR_REGISTERED_WITH_SYSTEM(340151973))
					OBJECT::DOOR_SYSTEM_SET_DOOR_STATE(340151973, 1);
			});
		}

		ImGui::SetNextItemWidth(200);
		ImGui::Combo("Show", (int*)&g_SelectedSceneType, g_SceneTypeStrs.data(), g_SceneTypeStrs.size(), -1);

		if (g_SelectedSceneType == SceneType::CAN_CAN_01 || g_SelectedSceneType == SceneType::CAN_CAN_02)
		{
			RenderActorDef(g_CanCanDancerOverrides[0], "Dancer 1");
			RenderActorDef(g_CanCanDancerOverrides[1], "Dancer 2");
			RenderActorDef(g_CanCanDancerOverrides[2], "Dancer 3");
			RenderActorDef(g_CanCanDancerOverrides[3], "Dancer 4");
			RenderActorDef(g_CanCanDanceConductorOverride, "Conductor");
		}
		else if (g_SelectedSceneType == SceneType::FIRE_BREATHER)
		{
			RenderActorDef(g_FireBreatherOverride, "Breather");
		}
		else if ((g_SelectedSceneType == SceneType::FIRE_DANCER_01 || g_SelectedSceneType == SceneType::FIRE_DANCER_02))
		{
			RenderActorDef(g_FireDancerOverride, "Dancer");
		}
		else if ((g_SelectedSceneType == SceneType::SNAKE_DANCER_01 || g_SelectedSceneType == SceneType::SNAKE_DANCER_02))
		{
			RenderActorDef(g_SnakeDancerOverride, "Dancer");
		}
		else if (g_SelectedSceneType == SceneType::SWORD_DANCER)
		{
			RenderActorDef(g_SwordDancerOverride, "Dancer");
		}
		else if (g_SelectedSceneType == SceneType::ODD_FELLOWS)
		{
			RenderActorDef(g_OddFellowsMarjorieOverride, "Miss Marjorie");
			RenderActorDef(g_OddFellowsBruteOverride, "Brute");
			RenderActorDef(g_OddFellowsMagnificoOverride, "Magnifico the Magnificent");
			RenderActorDef(g_OddFellowsAudienceMemberOverride, "Audience Member");
		}
		else if (g_SelectedSceneType == SceneType::ESCAPE_ARTIST)
		{
			RenderActorDef(g_EscapeArtistOverride, "Escape Artist");
			RenderActorDef(g_EscapeArtistAssistantOverride, "Assistant");
		}
		else if (g_SelectedSceneType == SceneType::FLEX_FIGHT)
		{
			RenderActorDef(g_FlexFightStrongwomanOverride, "Strongwoman");
			RenderActorDef(g_FlexFightAudienceMemberOverride, "Audience Member");	
		}
		else if (g_SelectedSceneType == SceneType::BAND_01 || g_SelectedSceneType == SceneType::BAND_02)
		{
			RenderActorDef(g_BandBassistOverride, "Bassist");
			RenderActorDef(g_BandDrummerOverride, "Drummer");
			RenderActorDef(g_BandPianistOverride, "Pianist");
			RenderActorDef(g_BandSingerOverride, "Singer");
		}

		ImGui::BeginDisabled(g_RunningSceneScriptID != -1);
		if (ImGui::Button("Start"))
		{
			FiberPool::Push([] {
				auto hash = g_SceneTypeScripts[(int)g_SelectedSceneType];

				if (MISC::GET_NUMBER_OF_FREE_STACKS_OF_THIS_SIZE(7000) == 0)
				{
					return; // rare case, but whatever
				}

				while (!SCRIPTS::HAS_SCRIPT_WITH_NAME_HASH_LOADED(hash))
				{
					SCRIPTS::REQUEST_SCRIPT_WITH_NAME_HASH(hash);
					ScriptMgr::Yield();
				}

				g_RunningSceneScriptID = SCRIPTS::START_NEW_SCRIPT_WITH_NAME_HASH(hash, 7000);
				SCRIPTS::SET_SCRIPT_WITH_NAME_HASH_AS_NO_LONGER_NEEDED(hash);
			});
		}
		ImGui::EndDisabled();
		ImGui::SameLine();
		ImGui::BeginDisabled(g_RunningSceneScriptID == -1);
		if (ImGui::Button("Stop"))
		{
			FiberPool::Push([] {
				SCRIPTS::TERMINATE_THREAD(g_RunningSceneScriptID);
				MISC::CLEAR_AREA(2546.5646f, -1301.4119f, 48.3564f, 500.0f, -1); // clear stage area
				for (auto& entity : g_ShowEntities)
				{
					ENTITY::DELETE_ENTITY(&entity);
				}
				g_ShowEntities.clear();
				g_RunningSceneScriptID = -1;
			});
		}
		ImGui::EndDisabled();
	}
}