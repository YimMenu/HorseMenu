#include "Shows.hpp"

#include "core/frontend/Notifications.hpp"

#include "game/backend/FiberPool.hpp"
#include "game/backend/NativeHooks.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Player.hpp"
#include "game/rdr/Scripts.hpp"

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

	constexpr auto g_SceneTypeScriptsMP = std::to_array({
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

	constexpr auto g_SceneTypeScriptsSP = std::to_array({
	    "show_nbx_cancan"_J,
	    "show_nbx_cancan_02"_J,
	    "show_nbx_firebreath"_J,
	    "show_nbx_firedance_01"_J,
	    "show_nbx_firedance_02"_J,
	    "show_nbx_snakedance_01"_J,
	    "show_nbx_snakedance_02"_J,
	    "show_nbx_sworddancer"_J,
	    "show_nbx_oddfellows"_J,
	    "show_nbx_escapeartist"_J,
	    "show_nbx_flexfight"_J,
	    "show_nbx_bigband"_J,
	    "show_nbx_bigband_02"_J,
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

	constexpr auto g_SceneTypeInts = std::to_array({
	    "new_theater_cancan",
	    "new_theater_cancan",
	    "new_theater_fireperformer",
	    "new_theater_fireperformer",
	    "new_theater_fireperformer",
	    "new_theater_snakedancer",
	    "new_theater_snakedancer",
	    "new_theater_snakedancer",
	    "new_theater_theOddFellows",
	    "new_theater_magician",
	    "",
	    "",
	    "",
	});

	constexpr auto g_ScriptSceneIds = std::to_array({
		5,
		6,
		12,
		13,
		14,
		16,
		17,
		19,
		20,
		10,
		15,
		7,
		8
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
	static SceneType g_RunningSceneType = SceneType::CAN_CAN_01;
	static int g_RunningSceneScriptID = -1;
	static int g_RunningSceneAnimscene = -1;
	static bool g_AutoCleanup = true;
	static bool g_SpawnAudience = true;
	static bool g_SetReady = false;
	static std::vector<Entity> g_ShowEntities;
	static std::vector<Ped> g_AudienceMembers;
	constexpr int NUM_AUDIENCE_MEMBERS = 56;

	// lighting control code

	// audience creation code from SP

	static rage::fvector3 GetAudienceMemberPos(int idx)
	{
		switch (idx)
		{
		case 0: return {2541.9539f, -1303.6516f, 47.51162f};
		case 1: return {2542.6248f, -1303.6276f, 47.50835f};
		case 2: return {2543.2527f, -1303.5038f, 47.51194f};
		case 3: return {2543.9138f, -1303.4467f, 47.50978f};
		case 4: return {2544.5544f, -1303.3499f, 47.51124f};
		case 5: return {2545.2117f, -1303.2858f, 47.48675f};
		case 6: return {2540.8508f, -1302.3906f, 47.83032f};
		case 7: return {2541.4048f, -1302.1624f, 47.83151f};
		case 8: return {2542.039f, -1301.9946f, 47.83165f};
		case 9: return {2542.659f, -1301.8953f, 47.83114f};
		case 10: return {2543.2808f, -1301.7847f, 47.83141f};
		case 11: return {2543.8872f, -1301.7189f, 47.8308f};
		case 12: return {2544.5361f, -1301.6354f, 47.831f};
		case 13: return {2545.165f, -1301.5907f, 47.81311f};
		case 14: return {2540.8162f, -1300.6383f, 48.12306f};
		case 15: return {2541.43f, -1300.4728f, 48.12244f};
		case 16: return {2542.0337f, -1300.3115f, 48.12096f};
		case 17: return {2542.644f, -1300.1532f, 48.12228f};
		case 18: return {2543.269f, -1300.0386f, 48.12248f};
		case 19: return {2543.8955f, -1299.9259f, 48.12423f};
		case 20: return {2545.1692f, -1299.8176f, 48.10023f};
		case 21: return {2540.8438f, -1298.8798f, 48.39516f};
		case 22: return {2541.4421f, -1298.742f, 48.39409f};
		case 23: return {2542.0696f, -1298.5867f, 48.39284f};
		case 24: return {2543.3018f, -1298.2754f, 48.39411f};
		case 25: return {2543.8982f, -1298.1788f, 48.39465f};
		case 26: return {2544.5361f, -1298.0916f, 48.39633f};
		case 27: return {2550.9575f, -1303.6145f, 47.48922f};
		case 28: return {2550.3018f, -1303.5435f, 47.48922f};
		case 29: return {2549.651f, -1303.4829f, 47.48394f};
		case 30: return {2549.0054f, -1303.4297f, 47.48394f};
		case 31: return {2548.3562f, -1303.3667f, 47.48394f};
		case 32: return {2547.7126f, -1303.341f, 47.48394f};
		case 33: return {2552.0967f, -1302.3553f, 47.80622f};
		case 34: return {2551.5093f, -1302.1925f, 47.80622f};
		case 35: return {2550.8994f, -1302.0336f, 47.80622f};
		case 36: return {2550.2979f, -1301.8839f, 47.80622f};
		case 37: return {2549.6611f, -1301.7599f, 47.80622f};
		case 38: return {2549.0374f, -1301.6827f, 47.80622f};
		case 39: return {2548.4128f, -1301.6241f, 47.80622f};
		case 40: return {2552.1223f, -1300.5559f, 48.09521f};
		case 41: return {2551.4993f, -1300.4144f, 48.09521f};
		case 42: return {2550.8713f, -1300.2426f, 48.09521f};
		case 43: return {2550.2546f, -1300.1294f, 48.09521f};
		case 44: return {2549.6353f, -1300.0294f, 48.09521f};
		case 45: return {2549.016f, -1299.9486f, 48.09521f};
		case 46: return {2552.1152f, -1298.8127f, 48.36841f};
		case 47: return {2551.4988f, -1298.6577f, 48.36841f};
		case 48: return {2550.2537f, -1298.388f, 48.36841f};
		case 49: return {2549.629f, -1298.3119f, 48.36841f};
		case 50: return {2549.001f, -1298.207f, 48.36841f};
		case 51: return {2548.3677f, -1298.1227f, 48.36841f};
		case 52: return {2547.7332f, -1298.0409f, 48.36841f};
		case 53: return {2553.102f, -1299.6674f, 49.214f};
		case 54: return {2553.1287f, -1302.3986f, 49.214f};
		case 55: return {2539.7886f, -1302.3699f, 49.214f};
		default: return {};
		}
	}

	static float GetAudienceMemberHeading(int idx)
	{
		switch (idx)
		{
		case 0: return 189.76f;
		case 1: return 194.54f;
		case 2: return 185.02f;
		case 3: return 185.67f;
		case 4: return 186.48f;
		case 5: return 189.64f;
		case 6: return 194.87f;
		case 7: return 197.45f;
		case 8: return 192.94f;
		case 9: return 190.4f;
		case 10: return 187.74f;
		case 11: return 188.21f;
		case 12: return 191.46f;
		case 13: return 187.8f;
		case 14: return 197.77f;
		case 15: return 197.28f;
		case 16: return 195.7f;
		case 17: return 194.38f;
		case 18: return 189.91f;
		case 19: return 187.19f;
		case 20: return 183.35f;
		case 21: return 195.68f;
		case 22: return 195.08f;
		case 23: return 197.6f;
		case 24: return 192.22f;
		case 25: return 187.31f;
		case 26: return 186.63f;
		case 27: return 174.21f;
		case 28: return 175.4f;
		case 29: return 177.33f;
		case 30: return 177.62f;
		case 31: return 175.4f;
		case 32: return 176.59f;
		case 33: return 165.32f;
		case 34: return 170.16f;
		case 35: return 170.37f;
		case 36: return 174.13f;
		case 37: return 175.59f;
		case 38: return 173.64f;
		case 39: return 178.62f;
		case 40: return 169.96f;
		case 41: return 171.41f;
		case 42: return 170.19f;
		case 43: return 171.15f;
		case 44: return 174.93f;
		case 45: return 177.61f;
		case 46: return 169.6f;
		case 47: return 171.53f;
		case 48: return 172.77f;
		case 49: return 174.2f;
		case 50: return 175.33f;
		case 51: return 175.1f;
		case 52: return 176.09f;
		case 53: return 152.8307f;
		case 54: return 152.8307f;
		case 55: return 190.6648f;
		default: return 0.0f;
		}
	}

	static Ped CreateAudienceMemberForSlot(int idx)
	{
		auto position = GetAudienceMemberPos(idx);
		auto heading  = GetAudienceMemberHeading(idx);
		auto model = POPULATION::GET_RANDOM_MODEL_FROM_POPULATION_SET("nbx_civilians"_J, idx < 12 ? 2 : 0, -156825994, false, true, position.x, position.y, position.z); // the model is already loaded in memory

		if (model == 0)
			return nullptr;

		auto ped = Ped::Create(model, position, heading);
		if (ped)
		{
			ped.SetInvincible(true);
			PED::SET_PED_KEEP_TASK(ped.GetHandle(), true);
		}

		return ped;
	}

	static void StartAudienceMemberTask(Ped ped, int idx)
	{
		auto position = GetAudienceMemberPos(idx);
		auto heading  = GetAudienceMemberHeading(idx);

		TASK::TASK_START_SCENARIO_AT_POSITION(ped.GetHandle(), "PROP_HUMAN_SEAT_CHAIR"_J, position.x, position.y, position.z, heading, -1, false, true, nullptr, 0.25f, false);
	}

	static void CreateAudienceMembers()
	{
		g_AudienceMembers.resize(NUM_AUDIENCE_MEMBERS, nullptr);
		for (int i = 0; i < NUM_AUDIENCE_MEMBERS; i++)
		{
			auto ped = CreateAudienceMemberForSlot(i);
			StartAudienceMemberTask(ped, i);
			g_AudienceMembers[i] = ped;
		}
	}

	static bool TryLoadSet(SceneType type)
	{
		// TODO: this is not networked
		auto set = g_SceneTypeInts[(int)g_SelectedSceneType];
		auto stage = INTERIOR::GET_INTERIOR_AT_COORDS(2546.453f, -1303.998f, 46.793f);

		if (INTERIOR::IS_INTERIOR_READY(stage) && INTERIOR::_IS_INTERIOR_ENTITY_SET_VALID(stage, set))
		{
			INTERIOR::ACTIVATE_INTERIOR_ENTITY_SET(stage, set, 1);
			return true;
		}

		return false;
	}

	static void UnloadSet(SceneType type)
	{
		auto set   = g_SceneTypeInts[(int)g_SelectedSceneType];
		auto stage = INTERIOR::GET_INTERIOR_AT_COORDS(2546.453f, -1303.998f, 46.793f);

		if (INTERIOR::IS_INTERIOR_READY(stage))
		{
			INTERIOR::DEACTIVATE_INTERIOR_ENTITY_SET(stage, set, 1);
		}
	}

	static SceneType SceneTypeFromScript(joaat_t script)
	{
		if (Scripts::UsingMPScripts())
		{
			for (auto i = 0; i < g_SceneTypeScriptsMP.size(); i++)
				if (g_SceneTypeScriptsMP[i] == script)
					return SceneType(i);
		}
		else
		{
			for (auto i = 0; i < g_SceneTypeScriptsSP.size(); i++)
				if (g_SceneTypeScriptsSP[i] == script)
					return SceneType(i);
		}

		return SceneType(0); // should not reach here
	}

	static Ped ProcessActorDef(ActorDefinition& def)
	{
		if (def.Type == ActorOverrideType::DEFAULT)
			return nullptr;
		else if (def.Type == ActorOverrideType::SELF)
		{
			return Self::GetPed();
		}
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
			case "CS_ESCAPEARTISTASSISTANT"_J:
				return ProcessActorDef(g_EscapeArtistAssistantOverride);
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
		if (!ped)
			Notifications::Show("Shows", "Failed to create actor, the show will not run! Use World > Clear All Peds if this issue persists or try changing sessions");
		g_ShowEntities.push_back(ped);
		Ped(ped).SetInvincible(true);
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
		Entity(obj).SetInvincible(true);
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
		g_RunningSceneAnimscene = handle;
		ctx->SetReturnValue(std::move(handle));
	}

	inline void RenderActorDef(ActorDefinition& def, const std::string& name)
	{
		ImGui::SetNextItemWidth(100);
		if (*Pointers.IsSessionStarted)
			ImGui::Combo(name.c_str(), (int*)&def.Type, "Default\0Yourself\0Player\0");
		else
			ImGui::Combo(name.c_str(), (int*)&def.Type, "Default\0Yourself\0");
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

	static void ShutdownShow()
	{
		UnloadSet(g_RunningSceneType);
		SCRIPTS::TERMINATE_THREAD(g_RunningSceneScriptID);
		MISC::CLEAR_AREA(2546.5646f, -1301.4119f, 48.3564f, 500.0f, -1); // clear stage area
		for (auto& entity : g_ShowEntities)
		{
			entity.Delete();
		}
		for (auto& entity : g_AudienceMembers)
		{
			if (entity)
			{
				entity.Delete();
			}
		}
		g_ShowEntities.clear();
		g_AudienceMembers.clear();
		g_RunningSceneScriptID  = -1;
		g_RunningSceneAnimscene = -1;
	}

	static void ShowsTick()
	{
		while (g_Running)
		{
			if (g_RunningSceneScriptID != -1 && g_RunningSceneAnimscene != -1)
			{
				if (!g_SetReady)
				{
					g_SetReady = TryLoadSet(g_RunningSceneType);
				}

				if (ANIMSCENE::_IS_ANIM_SCENE_PAUSED(g_RunningSceneAnimscene) || ANIMSCENE::IS_ANIM_SCENE_FINISHED(g_RunningSceneAnimscene, false))
				{
					ShutdownShow();
					return;
				}
			}
			ScriptMgr::Yield();
		}
	}

	void RenderShowsMenu()
	{
		static bool _run_once = ([] {
			static auto hook_natives = [](auto& script) {
				NativeHooks::AddHook(script, NativeIndex::CREATE_PED, CREATE_PED);
				NativeHooks::AddHook(script, NativeIndex::NETWORK_HAS_CONTROL_OF_ENTITY, NETWORK_HAS_CONTROL_OF_ENTITY);
				NativeHooks::AddHook(script, NativeIndex::CREATE_OBJECT, CREATE_OBJECT);
				NativeHooks::AddHook(script, NativeIndex::_CREATE_ANIM_SCENE, CREATE_ANIM_SCENE);
			};

			for (auto& script : g_SceneTypeScriptsMP)
				hook_natives(script);

			for (auto& script : g_SceneTypeScriptsSP)
				hook_natives(script);

			ScriptMgr::AddScript(std::make_unique<Script>(&ShowsTick));

			return true;
		})();

		if (*Pointers.IsSessionStarted)
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
				if (OBJECT::IS_DOOR_REGISTERED_WITH_SYSTEM(544106233))
					OBJECT::DOOR_SYSTEM_SET_DOOR_STATE(544106233, 0);
			});
		}
		ImGui::SameLine();
		if (ImGui::Button("Lock Theater Door"))
		{
			FiberPool::Push([] {
				if (OBJECT::IS_DOOR_REGISTERED_WITH_SYSTEM(340151973))
					OBJECT::DOOR_SYSTEM_SET_DOOR_STATE(340151973, 1);
				if (OBJECT::IS_DOOR_REGISTERED_WITH_SYSTEM(544106233))
					OBJECT::DOOR_SYSTEM_SET_DOOR_STATE(544106233, 1);
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
			RenderActorDef(g_OddFellowsBruteOverride, "Bertram");
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

		ImGui::Checkbox("Auto Cleanup", &g_AutoCleanup);
		if (*Pointers.IsSessionStarted)
		{
			ImGui::Checkbox("Spawn Audience Members", &g_SpawnAudience);
		}

		ImGui::BeginDisabled(g_RunningSceneScriptID != -1);
		if (ImGui::Button("Start"))
		{
			FiberPool::Push([] {
				std::uint32_t hash;
				if (Scripts::UsingMPScripts())
					hash = g_SceneTypeScriptsMP[(int)g_SelectedSceneType];
				else
					hash = g_SceneTypeScriptsSP[(int)g_SelectedSceneType];

				if (MISC::GET_NUMBER_OF_FREE_STACKS_OF_THIS_SIZE(7000) == 0)
				{
					return; // rare case, but whatever
				}

				while (!SCRIPTS::HAS_SCRIPT_WITH_NAME_HASH_LOADED(hash))
				{
					SCRIPTS::REQUEST_SCRIPT_WITH_NAME_HASH(hash);
					ScriptMgr::Yield();
				}

				if (Scripts::UsingMPScripts() && g_SpawnAudience)
					CreateAudienceMembers();

				if (Scripts::UsingMPScripts())
				{
					struct
					{
						SCR_INT InstanceId;
						SCR_INT ShowIndex;
						SCR_BOOL DisableLightingControls;
						SCR_INT PAD_0003; // unused
					} start_parameters{};

					start_parameters.InstanceId = -1;
					start_parameters.ShowIndex = g_ScriptSceneIds[static_cast<int>(g_SelectedSceneType)];
					start_parameters.DisableLightingControls = FALSE;

					g_RunningSceneScriptID = SCRIPTS::START_NEW_SCRIPT_WITH_NAME_HASH_AND_ARGS(hash, &start_parameters, sizeof(start_parameters) / sizeof(uint64_t), 7000);
				}
				else
				{
					g_RunningSceneScriptID = SCRIPTS::START_NEW_SCRIPT_WITH_NAME_HASH(hash, 7000);
				}

				g_RunningSceneType = g_SelectedSceneType;
				g_SetReady = false;
				SCRIPTS::SET_SCRIPT_WITH_NAME_HASH_AS_NO_LONGER_NEEDED(hash);
			});
		}
		ImGui::EndDisabled();
		ImGui::SameLine();
		ImGui::BeginDisabled(g_RunningSceneScriptID == -1);
		if (ImGui::Button("Stop"))
		{
			FiberPool::Push([] {
				ShutdownShow();
			});
		}
		ImGui::EndDisabled();
	}
}