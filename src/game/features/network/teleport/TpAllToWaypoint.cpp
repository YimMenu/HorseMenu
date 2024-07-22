#include "core/commands/Command.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "game/backend/Players.hpp"
#include "util/teleport.hpp"

namespace YimMenu::Features
{
	class TpAllToWaypoint : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			for (auto& [idx, player] : Players::GetPlayers())
			{
				Teleport::TeleportPlayerToCoords(player, Teleport::GetWaypointCoords());
			}
		}
	};

	static TpAllToWaypoint _TpAllToWaypoint{"tpalltowaypoint", "Teleport To Waypoint", "Teleport all players to your active waypoint"};
}