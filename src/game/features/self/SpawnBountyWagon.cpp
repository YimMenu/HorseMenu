#include "core/commands/Command.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/Self.hpp"
#include "util/VehicleSpawner.hpp"


namespace YimMenu::Features
{
	// TODO: this should not exist
	class SpawnBountyWagon : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			Vector3 dim1, dim2;
			MISC::GET_MODEL_DIMENSIONS(MISC::GET_HASH_KEY("wagonarmoured01x"), &dim1, &dim2);
			float offset = dim2.y * 1.6;

			Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(Self::GetPed().GetHandle());
			float rot   = Self::GetPed().GetRotation(0).z;
			Vector3 pos = Self::GetPed().GetPosition();

			int handle = SpawnVehicle("wagonarmoured01x", Vector3{pos.x + (dir.x * offset), pos.y + (dir.y * offset), pos.z}, rot);

			VEHICLE::SET_VEHICLE_HAS_BEEN_OWNED_BY_PLAYER(handle, true);
			VEHICLE::SET_PED_OWNS_VEHICLE(Self::GetPed().GetHandle(), handle);
		}
	};

	static SpawnBountyWagon _SpawnBountyWagon{"spawnbountywagon", "Spawn Bounty Wagon", "Spawns the bounty hunter wagon into the game."};
}