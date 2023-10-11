#include "teleport.hpp"

#include "game/backend/ScriptMgr.hpp"

namespace YimMenu::Teleport
{
	bool TeleportEntity(Entity ent, Vector3& coords)
	{
		if (ENTITY::IS_ENTITY_A_PED(ent))
		{
			if (PED::IS_PED_ON_MOUNT(ent))
				ent = PED::GET_MOUNT(ent);
			if (PED::IS_PED_IN_ANY_VEHICLE(ent, false))
				ent = PED::GET_VEHICLE_PED_IS_USING(ent);
		}

		//TOOD request control of entity
		if (LoadGroundAtCoords(coords))
		{
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(ent, coords.x, coords.y, coords.z, false, false, false);
		}

		return true;
	}

	Vector3 GetWaypointCoords()
	{
		if (MAP::IS_WAYPOINT_ACTIVE())
			return MAP::_GET_WAYPOINT_COORDS();

		//TODO notify
		return Vector3{0, 0, 0};
	}

	bool LoadGroundAtCoords(Vector3& coords)
	{
		float groundZ;
		bool done = false;

		for (int i = 0; i < 20; i++)
		{
			for (int z = 0; z < 1000; z += 25)
			{
				float ground_iteration = static_cast<float>(z);
				if (i >= 1 && (z % 100 == 0))
				{
					STREAMING::REQUEST_COLLISION_AT_COORD(coords.x, coords.y, ground_iteration);
					ScriptMgr::Yield(1ms);
				}
				if (MISC::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, ground_iteration, &groundZ, false))
				{
					coords.z = groundZ + 1.f;
					done     = true;
				}
			}

			float height;
			if (done && WATER::GET_WATER_HEIGHT(coords.x, coords.y, coords.z, &height))
			{
				coords.z = height + 1.f;
			}

			if (done)
			{
				return true;
			}
		}

        //TODO notify
		coords.z = 1000.f;

		return false;
	}
}