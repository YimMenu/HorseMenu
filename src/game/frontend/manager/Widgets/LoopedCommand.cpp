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
		auto command = YimMenu::Commands::GetCommand<LoopedCommand>(m_Id);

		if (!command)
		{
			ImGui::Text("Unknown!");
			return;
		}

		bool enabled = command->GetState();
		if (ImGui::Toggle(command->GetLabel().data(), &enabled))
			command->SetState(enabled);

		auto window_label = std::format("{} Hotkey", command->GetLabel());


		ImGui::SetNextWindowSize(ImVec2(500, 120));
		if (ImGui::BeginPopupModal(window_label.data(), nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar))
		{
			ImGui::BulletText("Hover over the command name to change its hotkey");
			ImGui::BulletText("Press any registered key to remove");
			ImGui::Separator();

			HotkeySetter(command->GetHash()).Draw();

			
			ImGui::Spacing();
			if (ImGui::Button("Close") || ((!ImGui::IsWindowHovered() && !ImGui::IsAnyItemHovered()) && ImGui::IsMouseClicked(ImGuiMouseButton_Left)))
				ImGui::CloseCurrentPopup();

			ImGui::EndPopup();
		}

		if (ImGui::IsItemHovered())
		{
			ImGui::SetTooltip(std::format("{}\n\nPress shift to assign a hotkey", command->GetDescription()).data());
			if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
				ImGui::OpenPopup(window_label.data());
		}
	}
}