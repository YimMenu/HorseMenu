#include "game/backend/Self.hpp"
#include "game/backend/Players.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/rdr/Natives.hpp"
#include "util/teleport.hpp"

namespace YimMenu::Features
{
	class BringPlayer : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			Teleport::TeleportPlayerToCoords(player, Self::GetPed().GetPosition());
		}
	};

	static BringPlayer _BringPlayer{"bring", "Bring Player", "Teleport the player to you"};
}