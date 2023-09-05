#include "settings.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/LoopedCommand.hpp"

namespace YimMenu
{
	//Mini Submenu 1
	void Hotkeys()
	{
		ImGui::BulletText("Hover over the command name to change its hotkey");
		ImGui::Spacing();

		static std::vector<int>* current_hotkey = nullptr;

		for (auto& [hash, link] : g_HotkeySystem.m_CommandHotkeys)
		{
			ImGui::PushID(hash);

			ImGui::BeginGroup();

			auto command = Commands::GetCommand(hash);

			if (!command)
				continue;

			ImGui::Text(command->GetLabel().data());
			if (ImGui::IsItemHovered())
				current_hotkey = &link.Hotkey, link.Listening = true;
			else
				current_hotkey = nullptr, link.Listening = false;

			if (current_hotkey)
			{
				g_HotkeySystem.CreateHotkey(*current_hotkey);
			}

			ImGui::SameLine(175);
			ImGui::BeginGroup();

			if (link.Hotkey.empty())
			{
				if (current_hotkey && *current_hotkey == link.Hotkey)
					ImGui::Text("Press any button...");
				else
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
	};

	//Init mini submenus
	void Settings::LoadSubmenus()
	{
		m_MiniSubMenus.push_back(std::make_shared<MiniSubmenu>("Hotkeys", Hotkeys));
	}

		//Script Tick If Needed
	void Settings::Update()
	{
		//TODO
	}

	//Call Everytime When Newly Entered
	void Settings::UpdateOnce()
	{
		//TODO
	}
}