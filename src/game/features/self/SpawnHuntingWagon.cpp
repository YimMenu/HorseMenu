#include "core/commands/Command.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/features/Features.hpp"
#include "util/VehicleSpawner.hpp"


namespace YimMenu::Features
{
	class SpawnHuntingWagon : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int handle = SpawnVehicle("huntercart01", Self::PlayerPed);

			PLAYER::_SET_PLAYER_HUNTING_WAGON(Self::Id, handle);
			VEHICLE::SET_VEHICLE_HAS_BEEN_OWNED_BY_PLAYER(handle, true);
			VEHICLE::SET_PED_OWNS_VEHICLE(Self::PlayerPed, handle);
			Notifications::Show("Vehicle Spawner", "Wagon Spawned!", NotificationType::Success);
		};
	};

	static SpawnHuntingWagon _SpawnHuntingWagon{"spawnhuntingwagon", "Spawn Hunting Wagon", "Spawns the hunting wagon for the trader role."};
}