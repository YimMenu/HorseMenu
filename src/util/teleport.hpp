#pragma once
#include "common.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/rdr/Entity.hpp"
#include "game/rdr/Natives.hpp"


// TODO: remove this file

namespace YimMenu::Teleport
{
	inline bool LoadGroundAtCoords(rage::fvector3& location)
	{
		constexpr float max_ground_check = 1000.f;
		constexpr int max_attempts       = 300;
		float ground_z                   = location.z;
		int current_attempts             = 0;
		bool found_ground;
		float height;
	
		do
		{
			found_ground = MISC::GET_GROUND_Z_FOR_3D_COORD(location.x, location.y, max_ground_check, &ground_z, FALSE);
			STREAMING::REQUEST_COLLISION_AT_COORD(location.x, location.y, location.z);
	
			if (current_attempts % 10 == 0)
			{
				location.z += 25.f;
			}
	
			++current_attempts;
	
			ScriptMgr::Yield();
		} while (!found_ground && current_attempts < max_attempts);
	
		if (!found_ground)
		{
			return false;
		}
	
		if (WATER::GET_WATER_HEIGHT(location.x, location.y, location.z, &height))
		{
			location.z = height;
		}
		else
		{
			location.z = ground_z + 1.f;
		}
	
		return true;
	}

	// Entity typdef is being ambiguous with Entity class
	inline bool TeleportEntity(int ent, rage::fvector3 coords, bool loadGround = false)
	{
		if (ENTITY::IS_ENTITY_A_PED(ent))
		{
			if (PED::IS_PED_ON_MOUNT(ent))
				ent = PED::GET_MOUNT(ent);
			if (PED::IS_PED_IN_ANY_VEHICLE(ent, false))
				ent = PED::GET_VEHICLE_PED_IS_USING(ent);
		}

		// TODO: request control of entity
		if (loadGround)
		{
			if (LoadGroundAtCoords(coords))
			{
				Entity(ent).SetPosition(coords);
				Notifications::Show("Teleport", "Teleported entity to coords", NotificationType::Success);
			}
		}
		else
		{
			Entity(ent).SetPosition(coords);
			Notifications::Show("Teleport", "Teleported entity to coords", NotificationType::Success);
		}

		return true;
	}

	inline Vector3 GetWaypointCoords()
	{
		if (MAP::IS_WAYPOINT_ACTIVE())
			return MAP::_GET_WAYPOINT_COORDS();

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
