#pragma once
#include "Storage/Spoofing.hpp"
#include "common.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Entity.hpp"
#include "game/rdr/Vehicle.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Player.hpp"
#include "util/Joaat.hpp"

#include <entity/CDynamicEntity.hpp>
#include <network/CNetObjectMgr.hpp>
#include <network/netObject.hpp>


// TODO: remove this file!!!

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

	inline bool TeleportPlayerToCoords(Player player, Vector3 coords)
	{
		auto handle = player.GetPed().GetHandle();

		if (ENTITY::IS_ENTITY_DEAD(handle))
		{
			Notifications::Show("Teleport", "The player you want to teleport is dead!", NotificationType::Error);
			return false;
		}

		
		if (player.GetPed().GetMount())
		{
			player.GetPed().GetMount().ForceControl();
		}

		auto ent = Vehicle::Create("buggy01"_J, player.GetPed().GetPosition());
		auto ptr = ent.GetPointer<CDynamicEntity*>();

		if (!ptr || !ptr->m_NetObject)
		{
			Notifications::Show("Teleport", "Vehicle net object is null!", NotificationType::Error);
			return false;
		}

		ent.SetVisible(false);
		ent.SetCollision(false);
		ent.SetFrozen(true);

		auto vehId  = ptr->m_NetObject->m_ObjectId;
		auto playerId = player.GetPed().GetPointer<CDynamicEntity*>()->m_NetObject->m_ObjectId;
		Spoofing::RemotePlayerTeleport remoteTp = {playerId, {coords.x, coords.y, coords.z}};

		g_SpoofingStorage.m_RemotePlayerTeleports.emplace(vehId, remoteTp);

		if (player.IsValid() && PED::IS_PED_IN_ANY_VEHICLE(player.GetPed().GetHandle(), false))
			TASK::CLEAR_PED_TASKS_IMMEDIATELY(player.GetPed().GetHandle(), true, true);

		for (int i = 0; i < 40; i++)
		{
			ScriptMgr::Yield(25ms);

			Pointers.TriggerGiveControlEvent(player.GetHandle(), ptr->m_NetObject, 3);

			auto newCoords = ent.GetPosition();
			if (BUILTIN::VDIST(coords.x, coords.y, coords.z, newCoords.x, newCoords.y, newCoords.z) < 20 * 20 && VEHICLE::GET_PED_IN_VEHICLE_SEAT(ent.GetHandle(), 0) == handle)
			{
				break;
			}
		}

		ent.ForceControl();
		ent.Delete();

		std::erase_if(g_SpoofingStorage.m_RemotePlayerTeleports, [vehId](auto& obj) {
			return obj.first == vehId;
		});

		return true;
	}
}
