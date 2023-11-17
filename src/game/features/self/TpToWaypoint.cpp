#include "core/commands/Command.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"
#include "util/teleport.hpp"

namespace YimMenu::Features
{
	class TpToWaypoint : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			if (MAP::IS_WAYPOINT_ACTIVE())
			{
				auto waypointCoords = YimMenu::Teleport::GetWaypointCoords();
				YimMenu::Teleport::TeleportEntity(Self::PlayerPed, {waypointCoords.x, waypointCoords.y, 0.0f}, true);
			}
			else
			{
				Notifications::Show("Waypoint", "You don't have a waypoint set", NotificationType::Error);
			}
		}
	};

	static TpToWaypoint _TpToWaypoint{"tptowaypoint", "Teleport To Waypoint", "Teleport to your waypoint"};
}