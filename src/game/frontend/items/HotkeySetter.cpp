#include "Items.hpp"
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
		auto Command = Commands::GetCommand(m_Id);

		if (!Command)
			ImGui::Text("Unkown Command");
		else
		{
			CommandLink* CommandHotkeyLink = &g_HotkeySystem.m_CommandHotkeys.at(Command->GetHash());

			if (!CommandHotkeyLink)
			{
				ImGui::Text("Unkown CommandLink");
			}
			else
			{
				ImGui::Button(Command->GetLabel().data());
				CommandHotkeyLink->m_BeingModified = ImGui::IsItemActive();

				if (CommandHotkeyLink->m_BeingModified)
				{
					g_HotkeySystem.CreateHotkey(CommandHotkeyLink->m_Chain);
				}

				ImGui::SameLine(200);
				ImGui::BeginGroup();

				if (CommandHotkeyLink->m_Chain.empty())
				{
					if (CommandHotkeyLink->m_BeingModified)
						ImGui::Text("Press any button...");
					else
						ImGui::Text("No Hotkey Assigned");
				}
				else
				{
					ImGui::PushItemWidth(35);
					for (auto HotkeyModifier : CommandHotkeyLink->m_Chain)
					{
						char KeyLabel[32];
						strcpy(KeyLabel, g_HotkeySystem.GetHotkeyLabel(HotkeyModifier).data());
						ImGui::InputText("##keylabel", KeyLabel, 32, ImGuiInputTextFlags_ReadOnly);
						if (ImGui::IsItemClicked())
							std::erase_if(CommandHotkeyLink->m_Chain, [HotkeyModifier](int i) {
								return i == HotkeyModifier;
							});

						ImGui::SameLine();
					}
					ImGui::PopItemWidth();

					ImGui::SameLine();
					if (ImGui::Button("Clear"))
					{
						CommandHotkeyLink->m_Chain.clear();
					}
				}

				ImGui::EndGroup();
			}
		}
	}
}