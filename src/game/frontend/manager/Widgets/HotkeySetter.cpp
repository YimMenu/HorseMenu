#include "Widgets.hpp"
#include "core/commands/Command.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/HotkeySystem.hpp"

namespace YimMenu
{
	HotkeySetter::HotkeySetter(joaat_t command_id) :
	    m_Id(command_id)
	{
	}

	void HotkeySetter::Draw()
	{
		auto command = Commands::GetCommand(m_Id);

		if (!command)
			ImGui::Text("Unkown Command");
		else
		{
			CommandLink* command_hotkey_link = &g_HotkeySystem.m_CommandHotkeys.at(command->GetHash());

			if (!command_hotkey_link)
			{
				ImGui::Text("Unkown CommandLink");
			}
			else
			{
				ImGui::Text(command->GetLabel().data());
				command_hotkey_link->Listening = ImGui::IsItemHovered();

				if (command_hotkey_link->Listening)
				{
					g_HotkeySystem.CreateHotkey(command_hotkey_link->Hotkey);
				}

				ImGui::SameLine(200);
				ImGui::BeginGroup();

				if (command_hotkey_link->Hotkey.empty())
				{
					if (command_hotkey_link->Listening)
						ImGui::Text("Press any button...");
					else
						ImGui::Text("No Hotkey Assigned");
				}
				else
				{
					ImGui::PushItemWidth(50);
					for (auto hotkey_modifier : command_hotkey_link->Hotkey)
					{
						char key_label[32];
						strcpy(key_label, g_HotkeySystem.GetHotkeyLabel(hotkey_modifier).data());
						ImGui::InputText("##keylabel", key_label, 32, ImGuiInputTextFlags_ReadOnly);
						if (ImGui::IsItemClicked())
							std::erase_if(command_hotkey_link->Hotkey, [hotkey_modifier](int i) {
								return i == hotkey_modifier;
							});

						ImGui::SameLine();
					}
					ImGui::PopItemWidth();

					ImGui::SameLine();
					if (ImGui::Button("Clear"))
					{
						command_hotkey_link->Hotkey.clear();
					}
				}

				ImGui::EndGroup();
			}
		}
	}
}