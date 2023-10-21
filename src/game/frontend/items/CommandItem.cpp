#include "Items.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/Command.hpp"
#include "game/backend/FiberPool.hpp"

namespace YimMenu
{
	CommandItem::CommandItem(joaat_t id) :
	    m_Command(Commands::GetCommand<Command>(id))
	{
	}

	void CommandItem::Draw()
	{
		if (!m_Command)
		{
			ImGui::Text("Unknown!");
			return;
		}

		if (ImGui::Button(m_Command->GetLabel().data()))
		{
			FiberPool::Push([this] {
				m_Command->Call();
			});
		}

		// TODO: refactor this

		auto windowLabel = std::format("{} Hotkey", m_Command->GetLabel());

		if (ImGui::IsItemHovered())
		{
			ImGui::SetTooltip(m_Command->GetDescription().data());
			if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
				ImGui::OpenPopup(std::format("{} Hotkey", m_Command->GetLabel()).data());
		}

		ImGui::SetNextWindowSize(ImVec2(500, 120));
		if (ImGui::BeginPopupModal(windowLabel.data(), nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar))
		{
			ImGui::BulletText("Hold the command name clicked to change its hotkey");
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