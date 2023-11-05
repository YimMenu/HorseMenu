#include "Items.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/Command.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "core/frontend/widgets/toggle/imgui_toggle.hpp"

namespace YimMenu
{
	BoolCommandItem::BoolCommandItem(joaat_t id) :
	    m_Command(Commands::GetCommand<BoolCommand>(id))
	{
	}

	void BoolCommandItem::Draw()
	{
		if (!m_Command)
		{
			ImGui::Text("Unknown!");
			return;
		}

		bool enabled = m_Command->GetState();
		if (ImGui::Toggle(m_Command->GetLabel().data(), &enabled))
			m_Command->SetState(enabled);

		// TODO: refactor this

		auto windowLabel = std::format("{} Hotkey", m_Command->GetLabel());

		if (ImGui::IsItemHovered())
		{
			ImGui::SetTooltip(m_Command->GetDescription().data());
			if (GetAsyncKeyState(VK_OEM_3) & 0x8000)
				ImGui::OpenPopup(std::format("{} Hotkey", m_Command->GetLabel()).data());
		}

		ImGui::SetNextWindowSize(ImVec2(500, 120));
		if (ImGui::BeginPopupModal(windowLabel.data(), nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar))
		{
			ImGui::BulletText("Hover over the command name to change its hotkey");
			ImGui::BulletText("Press any registered key to remove");
			ImGui::Separator();

			HotkeySetter(m_Command->GetHash()).Draw();

			
			ImGui::Spacing();
			if (ImGui::Button("Close") || ((!ImGui::IsWindowHovered() && !ImGui::IsAnyItemHovered()) && ImGui::IsMouseClicked(ImGuiMouseButton_Left)))
				ImGui::CloseCurrentPopup();

			ImGui::EndPopup();
		}
	}
}