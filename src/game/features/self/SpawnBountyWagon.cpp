#include "core/commands/Command.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/features/Features.hpp"
#include "util/VehicleSpawner.hpp"


namespace YimMenu::Features
{
	class SpawnBountyWagon : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int handle = SpawnVehicle("wagonarmoured01x", Self::PlayerPed);
			VEHICLE::SET_PED_OWNS_VEHICLE(Self::PlayerPed, handle);
		}
	};

	static SpawnBountyWagon _SpawnBountyWagon{"spawnbountywagon", "Spawn Bounty Wagon", "Spawns the bounty hunter wagon into the game."};
}