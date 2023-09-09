#include "Widgets.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/Command.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/frontend/imguiwidgets/toggle/imgui_toggle.hpp"

namespace YimMenu
{
	LoopedCommandToggle::LoopedCommandToggle(joaat_t id) :
	    m_Id(id)
	{
	}

	void LoopedCommandToggle::Draw()
	{
		auto Command = YimMenu::Commands::GetCommand<LoopedCommand>(m_Id);

		if (!Command)
		{
			ImGui::Text("Unknown!");
			return;
		}

		bool Enabled = Command->GetState();
		if (ImGui::Toggle(Command->GetLabel().data(), &Enabled))
			Command->SetState(Enabled);

		auto WindowLabel = std::format("{} Hotkey", Command->GetLabel());


		ImGui::SetNextWindowSize(ImVec2(500, 120));
		if (ImGui::BeginPopupModal(WindowLabel.data(), nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar))
		{
			ImGui::BulletText("Hover over the command name to change its hotkey");
			ImGui::BulletText("Press any registered key to remove");
			ImGui::Separator();

			HotkeySetter(Command->GetHash()).Draw();

			
			ImGui::Spacing();
			if (ImGui::Button("Close") || ((!ImGui::IsWindowHovered() && !ImGui::IsAnyItemHovered()) && ImGui::IsMouseClicked(ImGuiMouseButton_Left)))
				ImGui::CloseCurrentPopup();

			ImGui::EndPopup();
		}

		if (ImGui::IsItemHovered())
		{
			ImGui::SetTooltip(std::format("{}\n\nPress shift to assign a hotkey", Command->GetDescription()).data());
			if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
				ImGui::OpenPopup(WindowLabel.data());
		}
	}
}