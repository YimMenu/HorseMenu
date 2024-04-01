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
			Vector3 dim1, dim2;
			MISC::GET_MODEL_DIMENSIONS(MISC::GET_HASH_KEY("wagonarmoured01x"), &dim1, &dim2);
			float offset = dim2.y * 1.6;

			Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(Self::PlayerPed);
			float rot   = (ENTITY::GET_ENTITY_ROTATION(Self::PlayerPed, 0)).z;
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(Self::PlayerPed, true, true);

			int handle = SpawnVehicle("wagonarmoured01x",
			    Vector3{pos.x + (dir.x * offset), pos.y + (dir.y * offset), pos.z},
			    ENTITY::GET_ENTITY_ROTATION(Self::PlayerPed, 0).z);
			VEHICLE::SET_PED_OWNS_VEHICLE(Self::PlayerPed, handle);
		}
	};

	static SpawnBountyWagon _SpawnBountyWagon{"spawnbountywagon", "Spawn Bounty Wagon", "Spawns the bounty hunter wagon into the game."};
}