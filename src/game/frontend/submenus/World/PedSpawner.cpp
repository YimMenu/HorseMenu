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
		static bool dead, invis, godmode, freeze, companion, sedated;
		static int formation;
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
		ImGui::Checkbox("Sedated", &sedated);
		ImGui::Checkbox("Invisible", &invis);
		ImGui::Checkbox("GodMode", &godmode);
		ImGui::Checkbox("Frozen", &freeze);
		ImGui::Checkbox("Companion", &companion);
		if (companion)
		{
			if (ImGui::BeginCombo("Formation", groupFormations[formation]))
			{
				for (const auto& [num, name] : groupFormations)
				{
					bool is_selected = (formation == num);
					if (ImGui::Selectable(name, is_selected))
					{
						formation = num;
					}
					if (is_selected)
					{
						ImGui::SetItemDefaultFocus();
					}
				}
				ImGui::EndCombo();
			}
			if (ImGui::IsItemHovered())
				ImGui::SetTooltip("What formation should spawned companion use?");
		}
		ImGui::SliderFloat("Scale", &scale, 0.1, 10);

		if (ImGui::Button("Spawn"))
		{
			FiberPool::Push([] {
				auto ped = Ped::Create(Joaat(pedModelBuffer), Self::GetPed().GetPosition());

				if (!ped)
					return;

				ped.SetFrozen(freeze);

				if (dead)
					ped.Kill();

				ped.SetInvincible(godmode);

				ped.SetVisible(!invis);

				if (scale != 1.0f)
					ped.SetScale(scale);

				ped.SetConfigFlag(PedConfigFlag::IsTranquilized, sedated);

				spawnedPeds.push_back(ped);

				if (companion)
				{
					int group = PED::GET_PED_GROUP_INDEX(YimMenu::Self::GetPed().GetHandle());
					if (!PED::DOES_GROUP_EXIST(group))
					{
						group = PED::CREATE_GROUP(0);
						PED::SET_PED_AS_GROUP_LEADER(YimMenu::Self::GetPed().GetHandle(), group, true);
					}

					ENTITY::SET_ENTITY_AS_MISSION_ENTITY(ped.GetHandle(), false, false);
					PED::SET_PED_AS_GROUP_MEMBER(ped.GetHandle(), group);
					PED::SET_PED_CAN_BE_TARGETTED_BY_PLAYER(ped.GetHandle(), YimMenu::Self::GetPlayer().GetId(), false);
					PED::SET_PED_RELATIONSHIP_GROUP_HASH(ped.GetHandle(),
					PED::GET_PED_RELATIONSHIP_GROUP_HASH(YimMenu::Self::GetPed().GetHandle()));

					PED::SET_GROUP_FORMATION(PED::GET_PED_GROUP_INDEX(ped.GetHandle()), formation);

					DECORATOR::DECOR_SET_INT(ped.GetHandle(), "SH_CMP_companion", 1);

					if (ped.IsAnimal())
					{
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 104, 0.0);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 105, 0.0);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 10, 0.0);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 146, 0.0);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 113, 0.0);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 114, 0.0);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 115, 0.0);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 116, 0.0);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 117, 0.0);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 118, 0.0);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 119, 0.0);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 111, 0.0);
						FLOCK::SET_ANIMAL_TUNING_FLOAT_PARAM(ped.GetHandle(), 107, 0.0);
					}
					PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(ped.GetHandle(), true);

					ped.SetConfigFlag(PedConfigFlag::_0x16A14D9A, true);
					ped.SetConfigFlag(PedConfigFlag::_DisableHorseFleeILO, true);
					ped.SetConfigFlag(PedConfigFlag::_0x74F95F2E, true);
					ped.SetConfigFlag(PedConfigFlag::Avoidance_Ignore_All, true);
					ped.SetConfigFlag(PedConfigFlag::DisableShockingEvents, true);
					ped.SetConfigFlag(PedConfigFlag::DisablePedAvoidance, false);
					ped.SetConfigFlag(PedConfigFlag::DisableExplosionReactions, true);
					ped.SetConfigFlag(PedConfigFlag::DisableEvasiveStep, true);
					ped.SetConfigFlag(PedConfigFlag::DisableHorseGunshotFleeResponse, true);

					auto blip = MAP::BLIP_ADD_FOR_ENTITY("BLIP_STYLE_COMPANION"_J, ped.GetHandle());
					MAP::BLIP_ADD_MODIFIER(blip, "BLIP_MODIFIER_COMPANION_DOG"_J);
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