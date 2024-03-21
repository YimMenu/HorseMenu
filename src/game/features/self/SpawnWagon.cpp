#include "core/commands/Command.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/features/Features.hpp"
#include "util/VehicleSpawner.hpp"


namespace YimMenu::Features
{
	class SpawnWagon : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			if (SpawnVehicle("wagonarmoured01x", Self::PlayerPed))
			{
				Notifications::Show("Vehicle Spawner", "Wagon Spawned!", NotificationType::Success);
				return;
			}
			Notifications::Show("Vehicle Spawner", "Failed to spawn vehicle!", NotificationType::Error);
			return;
		}
	};

	static SpawnWagon _SpawnWagon{"spawnwagon", "Spawn Wagon", "Spawns the bounty hunter wagon into the game."};
}