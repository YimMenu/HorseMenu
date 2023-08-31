#include "Menu.hpp"

#include "core/filemgr/FileMgr.hpp"
#include "core/memory/ModuleMgr.hpp"
#include "game/backend/FiberPool.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/natives.hpp"
#include "util/Joaat.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/backend/ScriptMgr.hpp"

namespace YimMenu
{
	// this is fundamentally broken and should only be used as a test
	inline void CommandCheckboxDemo(joaat_t command_hash)
	{
		auto command = Commands::GetCommand<LoopedCommand>(command_hash);

		if (!command)
		{
			ImGui::Text("Unknown!");
			return;
		}

		bool enabled = command->GetState();
		if (ImGui::Checkbox(command->GetLabel().data(), &enabled))
			command->SetState(enabled);
	}

	void Menu::Main()
	{
		if (!GUI::IsOpen())
			return;

		if (ImGui::Begin("Test"))
		{

			static std::vector<int>* current_hotkey = nullptr;
			
			ImGui::BulletText("Hover over the command name to change its hotkey");
			ImGui::Spacing();
			for (auto& [hash, link] : g_HotkeySystem.m_CommandHotkeys)
			{
				ImGui::PushID(hash);

				ImGui::BeginGroup();

				auto command = Commands::GetCommand(hash);

				if (!command)
					continue;

				ImGui::Text(command->GetLabel().data());
				if (ImGui::IsItemHovered())
					current_hotkey = &link.Hotkey;
				else
					current_hotkey = nullptr;

				if (current_hotkey)
				{
					g_HotkeySystem.CreateHotkey(*current_hotkey);
				}

				ImGui::SameLine(175);
				ImGui::BeginGroup();

				if (link.Hotkey.empty())
				{
					ImGui::Text("No Hotkey Assigned");
				}
				else
				{
					ImGui::PushItemWidth(50);
					for (auto hotkey_modifier : link.Hotkey)
					{
						char key_label[32];
						strcpy(key_label, g_HotkeySystem.GetHotkeyLabel(hotkey_modifier).data());
						ImGui::InputText("##keylabel", key_label, 32, ImGuiInputTextFlags_ReadOnly);

						if (hotkey_modifier != link.Hotkey.back())
							ImGui::SameLine();
					}
					ImGui::PopItemWidth();

					ImGui::SameLine();
					if (ImGui::Button("Clear"))
					{
						link.Hotkey.clear();
					}
				}

				ImGui::EndGroup();

				ImGui::EndGroup();

				ImGui::PopID();
			}

			ImGui::Separator();

			CommandCheckboxDemo("keepcoresfilled"_J);
			CommandCheckboxDemo("keepbarsfilled"_J);
			CommandCheckboxDemo("keephorsecoresfilled"_J);
			CommandCheckboxDemo("keephorsebarsfilled"_J);

			if (ImGui::Button("Clear Crimes"))
			{
				FiberPool::Push([] {
					Commands::GetCommand("clearcrimes"_J)->Call();
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

				LOG(INFO) << "X: " << coords.x << ", Y: " << coords.y << ", Z: " << coords.z;
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