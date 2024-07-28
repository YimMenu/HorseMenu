#include "PedSpawner.hpp"

#include "core/commands/HotkeySystem.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/NativeHooks.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/data/PedModels.hpp"


namespace YimMenu::Submenus
{
	void GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH(rage::scrNativeCallContext* ctx)
	{
		if (ctx->GetArg<int>(0) == "mp_intro"_J)
		{
			ctx->SetReturnValue<int>(1);
		}
		else
		{
			ctx->SetReturnValue<int>(NETWORK::NETWORK_AWARD_HAS_REACHED_MAXCLAIM(ctx->GetArg<int>(0)));
		}
	}

	void _GET_META_PED_TYPE(rage::scrNativeCallContext* ctx)
	{
		ctx->SetReturnValue<int>(4);
	}

	static bool IsPedModelInList(std::string model)
	{
		for (const auto& pedModel : Data::g_PedModels)
		{
			if (pedModel.model == model)
				return true;
		}

		return false;
	}

	static int PedSpawnerInputCallback(ImGuiInputTextCallbackData* data)
	{
		if (data->EventFlag == ImGuiInputTextFlags_CallbackCompletion)
		{
			std::string newText{};
			std::string inputLower = data->Buf;
			std::transform(inputLower.begin(), inputLower.end(), inputLower.begin(), ::tolower);
			for (const auto& pedModel : Data::g_PedModels)
			{
				std::string modelLower = pedModel.model;
				std::transform(modelLower.begin(), modelLower.end(), modelLower.begin(), ::tolower);
				if (modelLower.find(inputLower) != std::string::npos)
				{
					newText = pedModel.model;
				}
			}

			if (!newText.empty())
			{
				data->DeleteChars(0, data->BufTextLen);
				data->InsertChars(0, newText.c_str());
			}

			return 1;
		}
		return 0;
	}

	void RenderPedSpawnerMenu()
	{
		ImGui::PushID("peds"_J);

		static auto model_hook = ([]() {
			NativeHooks::AddHook("long_update"_J, NativeIndex::GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH, GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH);
			NativeHooks::AddHook("long_update"_J, NativeIndex::_GET_META_PED_TYPE, _GET_META_PED_TYPE);
			return true;
		}());

		static std::string pedModelBuffer;
		static float scale = 1;
		static bool dead, invis, godmode, freeze, companion;
		static std::vector<YimMenu::Ped> spawnedPeds;
		InputTextWithHint("##pedmodel", "Ped Model", &pedModelBuffer, ImGuiInputTextFlags_CallbackCompletion, nullptr, PedSpawnerInputCallback)
		    .Draw();
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("Press Tab to auto fill");
		if (!pedModelBuffer.empty() && !IsPedModelInList(pedModelBuffer))
		{
			ImGui::BeginListBox("##pedmodels", ImVec2(250, 100));

			std::string bufferLower = pedModelBuffer;
			std::transform(bufferLower.begin(), bufferLower.end(), bufferLower.begin(), ::tolower);
			for (const auto& pedModel : Data::g_PedModels)
			{
				std::string pedModelLower = pedModel.model;
				std::transform(pedModelLower.begin(), pedModelLower.end(), pedModelLower.begin(), ::tolower);
				if (pedModelLower.find(bufferLower) != std::string::npos && ImGui::Selectable(pedModel.model.data()))
				{
					pedModelBuffer = pedModel.model;
				}
			}

			ImGui::EndListBox();
		}

		ImGui::Checkbox("Spawn Dead", &dead);
		ImGui::Checkbox("Invisible", &invis);
		ImGui::Checkbox("GodMode", &godmode);
		ImGui::Checkbox("Frozen", &freeze);
		ImGui::Checkbox("Companion", &companion);
		ImGui::SliderFloat("Scale", &scale, 0.1, 10);
		if (ImGui::Button("Spawn"))
		{
			FiberPool::Push([] {
				auto ped = Ped::Create(Joaat(pedModelBuffer), Self::GetPed().GetPosition());

				if (!ped)
					return;

				if (freeze)
					ped.SetFrozen(true);

				if (dead)
					ped.Kill();

				if (godmode)
					ped.SetInvincible(true);

				if (invis)
					ped.SetVisible(false);

				if (scale != 1.0f)
					ped.SetScale(scale);

				spawnedPeds.push_back(ped);

				if (companion)
				{
					int group = PED::GET_PED_GROUP_INDEX(YimMenu::Self::GetPed().GetHandle());
					if (!PED::DOES_GROUP_EXIST(group))
					{
						group = PED::CREATE_GROUP(0);
						PED::SET_PED_AS_GROUP_LEADER(YimMenu::Self::GetPed().GetHandle(), group, true);
					}

					ENTITY::SET_ENTITY_AS_MISSION_ENTITY(ped.GetHandle(), true, false);
					PED::SET_PED_AS_GROUP_MEMBER(ped.GetHandle(), group);
					PED::SET_PED_CAN_BE_TARGETTED_BY_PLAYER(ped.GetHandle(), YimMenu::Self::GetPlayer().GetId(), false);
					PED::SET_PED_RELATIONSHIP_GROUP_HASH(ped.GetHandle(),
					    PED::GET_PED_RELATIONSHIP_GROUP_HASH(YimMenu::Self::GetPed().GetHandle()));
					DECORATOR::DECOR_SET_INT(ped.GetHandle(), "SH_CMP_companion", 1);
					ped.SetConfigFlag(PedConfigFlag::UseFollowLeaderThreatResponse, true);
					ped.SetMotivation(MotivationState::BRAVE_STATE, 100.f);
					PED::SET_PED_COMBAT_ATTRIBUTES(ped.GetHandle(), 58, false);
					PED::SET_PED_COMBAT_ATTRIBUTES(ped.GetHandle(), 38, false);
					PED::SET_PED_OWNS_ANIMAL(Self::GetPed().GetHandle(), ped.GetHandle(), true);

					auto blip = MAP::BLIP_ADD_FOR_ENTITY("BLIP_STYLE_COMPANION"_J, ped.GetHandle());
					MAP::BLIP_ADD_MODIFIER(blip, "BLIP_MODIFIER_COMPANION_DOG"_J);

					if (ped.IsAnimal())
					{
						FLOCK::SET_ANIMAL_TUNING_BOOL_PARAM(ped.GetHandle(), 44, 0);
						FLOCK::SET_ANIMAL_TUNING_BOOL_PARAM(ped.GetHandle(), 32, 1);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 74, 1);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 80, 1);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 115, 1);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 117, 1);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 119, 1);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 165, 5);
						FLOCK::_SET_ANIMAL_IS_WILD(ped.GetHandle(), false);
					}
				}
			});
		}
		ImGui::SameLine();
		if (ImGui::Button("Set Model"))
		{
			FiberPool::Push([] {
				auto model = Joaat(pedModelBuffer);

				for (int i = 0; i < 30 && !STREAMING::HAS_MODEL_LOADED(model); i++)
				{
					STREAMING::REQUEST_MODEL(model, false);
					ScriptMgr::Yield();
				}

				PLAYER::SET_PLAYER_MODEL(Self::GetPlayer().GetId(), model, false);
				Self::Update();
				PED::_SET_RANDOM_OUTFIT_VARIATION(Self::GetPed().GetHandle(), true);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
			});
		}
		ImGui::SameLine();
		if (ImGui::Button("Cleanup Peds"))
		{
			FiberPool::Push([] {
				for (auto it = spawnedPeds.begin(); it != spawnedPeds.end();)
				{
					if (it->IsValid())
					{
						if (it->GetMount())
						{
							it->GetMount().ForceControl();
							it->GetMount().Delete();
						}

						it->ForceControl();
						it->Delete();
					}
					it = spawnedPeds.erase(it);
				}
			});
		}

		ImGui::PopID();
	}
}