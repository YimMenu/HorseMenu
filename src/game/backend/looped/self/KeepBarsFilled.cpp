#include "../../../rdr/Natives.hpp"
#include "../Looped.hpp"
#include "SelfLooped.hpp"


namespace YimMenu
{
	//TODO Outsource the actual refill to a seperate non-looped function to expand utility.
	void looped::KeepBarsFilled()
	{
		if (!Self::refill_bars)
			return;

		auto health_bar  = ENTITY::GET_ENTITY_HEALTH(Self::ped);
		auto stamina_bar = PLAYER::_GET_PLAYER_STAMINA(Self::id);
		auto deadeye_bar = PLAYER::_GET_PLAYER_DEAD_EYE(Self::id);

		if (health_bar < ENTITY::GET_ENTITY_MAX_HEALTH(Self::ped, false))
			ENTITY::SET_ENTITY_HEALTH(Self::ped, ENTITY::GET_ENTITY_MAX_HEALTH(Self::ped, false), 0);
		if (stamina_bar < PED::_GET_PED_MAX_STAMINA(Self::ped))
			PED::_CHANGE_PED_STAMINA(Self::ped, PED::_GET_PED_MAX_STAMINA(Self::ped));
	}
}