#include "Menu.hpp"

#include "core/filemgr/FileMgr.hpp"
#include "core/memory/ModuleMgr.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/commands/FeatureCommand.hpp"
#include "game/backend/commands/HotkeySystem.hpp"
#include "game/backend/looped/self/SelfLooped.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/natives.hpp"
#include "util/Joaat.hpp"

namespace YimMenu
{
	void Menu::Main()
	{
		if (!GUI::IsOpen())
			return;

		if (ImGui::Begin("Test"))
		{
			for (auto& [name, feature_command] : RegisteredCommands)
			{
				ImGui::PushID(Joaat(feature_command.GetName()));

				ImGui::BeginGroup();

				ImGui::Text(feature_command.GetLabel().data());

				ImGui::SameLine(175);

				if (ImGui::Checkbox("Change Hotkey", &feature_command.hotkey_listener))
				{
					if (feature_command.hotkey_listener)
						feature_command.hotkey_modifiers.clear();
				}

				if (feature_command.hotkey_listener)
				{
					g_HotkeySystem.CreateHotkey(feature_command.hotkey_modifiers);
				}

				ImGui::SameLine();
				ImGui::BeginGroup();

				if (feature_command.hotkey_modifiers.empty())
				{
					ImGui::Text("No Hotkey Assigned");
				}
				else
				{
					ImGui::PushItemWidth(50);
					for (auto hotkey_modifier : feature_command.hotkey_modifiers)
					{
						char key_label[32];
						strcpy(key_label, g_HotkeySystem.GetHotkeyLabel(hotkey_modifier).data());
						ImGui::InputText("##keylabel", key_label, 32, ImGuiInputTextFlags_ReadOnly);

						if (hotkey_modifier != feature_command.hotkey_modifiers.back())
							ImGui::SameLine();
					}
					ImGui::PopItemWidth();
				}

				ImGui::EndGroup();

				ImGui::EndGroup();

				ImGui::PopID();
			}

			ImGui::Separator();

			ImGui::Text(std::format("Deadeye: {}/{}", Self::deadeye, Self::max_deadeye).data());

			ImGui::Checkbox("Refill Cores", &Self::refill_cores);
			ImGui::Checkbox("Refill Bars", &Self::refill_bars);
			ImGui::Checkbox("Refill Horse Cores", &Self::refill_horse_cores);
			ImGui::Checkbox("Refill Horse Bars", &Self::refill_horse_bars);

			if (ImGui::Button("Clear Crimes"))
			{
				FiberPool::Push([] {
					RegisteredCommands.at("clearcrimes").Call();
				});
			}

			if (ImGui::Button("Suicide"))
			{
				auto player_ped = PLAYER::PLAYER_PED_ID();
				ENTITY::SET_ENTITY_HEALTH(player_ped, 0, 0);
			}

			if (ImGui::Button("Get Coords"))
			{
				auto coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false, false);

				LOG(INFO) << coords.x << "x\t" << coords.y << "y\t" << coords.z << "z";
			}

			if (ImGui::Button("Spawn Ped"))
			{
				LOG(INFO) << "Before spawn";
				FiberPool::Push([] {
					auto model_hash = "msp_mob0_males_01"_J; // most models don't work
					LOG(INFO) << "In fiber pool";

					STREAMING::REQUEST_MODEL(model_hash, false);
					while (!STREAMING::HAS_MODEL_LOADED(model_hash))
						ScriptMgr::Yield();

					auto coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false, false);
					auto ped = PED::CREATE_PED(model_hash, coords.x, coords.y, coords.z, 0.0f, false, false, false, false);
					ScriptMgr::Yield();
					PED::SET_PED_RANDOM_COMPONENT_VARIATION(ped, 0);
				});
			}

			if (ImGui::Button("Dump Entrypoints"))
			{
				DWORD64 base_address = (DWORD64)GetModuleHandleA(0);

				const auto file_path = FileMgr::GetProjectFile("./entrypoints.txt");
				auto file            = std::ofstream(file_path.Path(), std::ios::out | std::ios::trunc);

				for (auto& entry : g_Crossmap)
				{
					auto address = Pointers.GetNativeHandler(entry);

					file << std::hex << std::uppercase << "0x" << entry << " : RDR2.exe + 0x" << (DWORD64)address - base_address << std::endl;
				}

				file.close();
			}

			if (ImGui::Button("Unload"))
				g_Running = false;
		}
		ImGui::End();
	}
}