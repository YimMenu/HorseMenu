#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "util/teleport.hpp"

namespace YimMenu::Features
{
	class AutoTP : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (MAP::IS_WAYPOINT_ACTIVE() && Self::GetPed())
			{
				Vector3 coords = Teleport::GetWaypointCoords();
				if (coords != Vector3{0, 0, 0})
				{
					Teleport::TeleportEntity(Self::GetPed().GetHandle(), rage::fvector3{coords.x, coords.y, coords.z}, true);
				}
			}
		}
	};

	static AutoTP _AutoTP{"autotp", "Auto TP to Waypoint", "Automatically teleports you when you place a waypoint"};
}