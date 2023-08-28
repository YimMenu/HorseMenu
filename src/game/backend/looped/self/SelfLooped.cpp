#include "SelfLooped.hpp"
#include "../Looped.hpp"
#include "../../../rdr/Natives.hpp"

namespace YimMenu
{
	void looped::SelfLoop()
	{
		Self::ped = PLAYER::PLAYER_PED_ID();
		Self::id  = PLAYER::PLAYER_ID();
		Self::pos = ENTITY::GET_ENTITY_COORDS(Self::ped, true, true);
		Self::rot = ENTITY::GET_ENTITY_ROTATION(Self::ped, 2);

		Self::deadeye = PLAYER::_GET_PLAYER_DEAD_EYE(Self::id);
		Self::max_deadeye = PLAYER::_GET_PLAYER_MAX_DEAD_EYE(Self::id, 0);

		if (PED::IS_PED_IN_ANY_VEHICLE(Self::ped, true))
			Self::veh = PED::GET_VEHICLE_PED_IS_IN(Self::ped, true);

		if (PED::IS_PED_ON_MOUNT(Self::ped))
			Self::mount = PED::GET_MOUNT(Self::ped);
		
		if (!ENTITY::DOES_ENTITY_EXIST(Self::mount) && ENTITY::DOES_ENTITY_EXIST(PED::_GET_LAST_MOUNT(Self::ped)))
			Self::mount = PED::_GET_LAST_MOUNT(Self::ped);
	}
}
