#include "../../../rdr/Natives.hpp"
#include "../../commands/FeatureCommand.hpp"
#include "../Looped.hpp"
#include "SelfLooped.hpp"


namespace YimMenu
{
	//TODO Outsource the actual refill to a seperate non-looped function to expand utility.
	void looped::KeepHorseBarsFilled()
	{
		if (!Self::refill_horse_bars || !ENTITY::DOES_ENTITY_EXIST(Self::mount))
			return;

		auto health_bar  = ENTITY::GET_ENTITY_HEALTH(Self::mount);
		auto stamina_bar = PED::_GET_PED_STAMINA(Self::mount);

		if (health_bar < ENTITY::GET_ENTITY_MAX_HEALTH(Self::mount, 0))
			ENTITY::SET_ENTITY_HEALTH(Self::mount, ENTITY::GET_ENTITY_MAX_HEALTH(Self::mount, 0), 0);
		if (stamina_bar < PED::_GET_PED_MAX_STAMINA(Self::mount))
			PED::_CHANGE_PED_STAMINA(Self::mount, PED::_GET_PED_MAX_STAMINA(Self::mount));
	}

	static FeatureCommand command{"keephorsebarsfilled", "Keep Horse Bars Filled", looped::KeepHorseBarsFilled, 0, true, &Self::refill_horse_bars};
}