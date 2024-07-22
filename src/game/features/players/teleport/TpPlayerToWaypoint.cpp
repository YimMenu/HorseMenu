#include "game/commands/PlayerCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "util/teleport.hpp"

namespace YimMenu::Features
{
	class TpPlayerToWaypoint : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			Teleport::TeleportPlayerToCoords(player, Teleport::GetWaypointCoords());
		}
	};

	static TpPlayerToWaypoint _TpPlayerToWaypoint{"tpplayertowaypoint", "Teleport To Waypoint", "Teleport the player to your active waypoint"};
}