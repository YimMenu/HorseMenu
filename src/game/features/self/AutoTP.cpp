#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "util/teleport.hpp"

namespace YimMenu::Features
{
	class AutoTP : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			Vector3 coords = Teleport::GetWaypointCoords();
			if (coords != Vector3{0, 0, 0})
			{
				Teleport::TeleportEntity(YimMenu::Self::PlayerPed, rage::fvector3{coords.x, coords.y, coords.z}, true);
			}
		}
	};

	static AutoTP _AutoTP{"autotp", "Auto TP to Waypoint", "Automatically teleports you when you place a waypoint"};
}