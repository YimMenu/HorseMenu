#pragma once
#include "common.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Teleport
{
	inline bool LoadGroundAtCoords(Vector3& coords)
	{
		float groundZ;
		bool done = false;
		auto notificationId = Notifications::Show("Streaming", "Loading ground at coords", NotificationType::Info, 5000);

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
				Notifications::Erase(notificationId);

				return true;
			}
		}

		Notifications::Erase(notificationId);
		Notifications::Show("Streaming", "Failed loading ground at coords", NotificationType::Warning);

		coords.z = 1000.f;

		return false;
	}

	//Entity typdef is being ambiguous with Entity class
	inline bool TeleportEntity(int ent, Vector3& coords, bool loadGround)
	{
		if (ENTITY::IS_ENTITY_A_PED(ent))
		{
			if (PED::IS_PED_ON_MOUNT(ent))
				ent = PED::GET_MOUNT(ent);
			if (PED::IS_PED_IN_ANY_VEHICLE(ent, false))
				ent = PED::GET_VEHICLE_PED_IS_USING(ent);
		}

		//TOOD request control of entity
		if (loadGround)
		{
			if (LoadGroundAtCoords(coords))
			{
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(ent, coords.x, coords.y, coords.z, false, false, false);
				Notifications::Show("Teleport", "Teleported entity to coords", NotificationType::Success);
			}
		}
		else
		{
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(ent, coords.x, coords.y, coords.z, false, false, false);
			Notifications::Show("Teleport", "Teleported entity to coords", NotificationType::Success);
		}

		return true;
	}

	inline Vector3 GetWaypointCoords()
	{
		if (MAP::IS_WAYPOINT_ACTIVE())
			return MAP::_GET_WAYPOINT_COORDS();

		Notifications::Show("Waypoint", "You don't have a waypoint set", NotificationType::Error);

		return Vector3{0, 0, 0};
	}

	inline bool WarpIntoVehicle(int ped, int veh)
	{
		if (!ENTITY::DOES_ENTITY_EXIST(veh) || !ENTITY::DOES_ENTITY_EXIST(ped))
			return false;

		int seat   = -2;
		auto seats = VEHICLE::GET_VEHICLE_MODEL_NUMBER_OF_SEATS(ENTITY::GET_ENTITY_MODEL(veh));

		for (int i = -1; i < seats; i++)
		{
			if (VEHICLE::IS_VEHICLE_SEAT_FREE(veh, i))
			{
				seat = i;
				break;
			}
		}

		if (seat < -1)
		{
			Notifications::Show("Teleport", "No free seats in vehicle", NotificationType::Error);
			return false;
		}
		else
		{
			PED::SET_PED_INTO_VEHICLE(ped, veh, seat);
			return true;
		}
	}
}