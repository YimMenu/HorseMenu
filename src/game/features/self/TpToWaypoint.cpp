#include "core/commands/Command.hpp"
#include "game/backend/Self.hpp"
#include "util/teleport.hpp"
#include "core/frontend/Notifications.hpp"

namespace Terminus::Features
{

	class TpToWaypoint : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			if (MAP::IS_WAYPOINT_ACTIVE())
			{
				// TODO!!!
				auto waypointCoords = Terminus::Teleport::GetWaypointCoords();
				Terminus::Teleport::TeleportEntity(Self::GetPed().GetHandle(), {waypointCoords.x, waypointCoords.y, 0.0f}, true);
			}
			else
			{
				Notifications::Show("Waypoint", "You don't have a waypoint set", NotificationType::Error);
			}
		}
	};

	static TpToWaypoint _TpToWaypoint{"tptowaypoint", "Teleport To Waypoint", "Teleport to your waypoint"};
}