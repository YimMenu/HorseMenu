#include "core/commands/Command.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"
#include "game/backend/ScriptMgr.hpp"
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
				auto waypointCoords = Teleport::GetWaypointCoords();
				Teleport::TeleportEntity(Self::PlayerPed, waypointCoords);
			}
		}
	};

	static TpToWaypoint _TpToWaypoint{"tptowaypoint", "Teleport To Waypoint", "Teleport to your waypoint"};
}