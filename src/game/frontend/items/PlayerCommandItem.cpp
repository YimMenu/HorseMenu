#include "Items.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "core/commands/Commands.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/Players.hpp"

namespace YimMenu
{
	PlayerCommandItem::PlayerCommandItem(joaat_t id) :
	    m_Command(Commands::GetCommand<PlayerCommand>(id))
	{
	}

	void PlayerCommandItem::Draw()
	{
		if (!m_Command)
		{
			ImGui::Text("Unknown!");
			return;
		}

		if (ImGui::Button(m_Command->GetLabel().data()))
		{
			FiberPool::Push([this] {
				if (Players::GetSelected().IsValid())
					m_Command->Call(Players::GetSelected());
			});
		}
	}
}