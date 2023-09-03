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
	}
}