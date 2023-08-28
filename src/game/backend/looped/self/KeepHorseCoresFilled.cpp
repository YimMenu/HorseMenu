#include "../../../rdr/Natives.hpp"
#include "../Looped.hpp"
#include "SelfLooped.hpp"


namespace YimMenu
{
	//TODO Outsource the actual refill to a seperate non-looped function to expand utility.
	void looped::KeepHorseCoresFilled()
	{
		if (!Self::refill_horse_cores || !ENTITY::DOES_ENTITY_EXIST(Self::mount))
			return;

		auto health_core = ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(Self::mount, (int)eAttributeCore::ATTRIBUTE_CORE_HEALTH);
		auto stamina_care = ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(Self::mount, (int)eAttributeCore::ATTRIBUTE_CORE_STAMINA);

		if (health_core < 100)
			ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(Self::mount, (int)eAttributeCore::ATTRIBUTE_CORE_HEALTH, 100);
		if (stamina_care < 100)
			ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(Self::mount, (int)eAttributeCore::ATTRIBUTE_CORE_STAMINA, 100);
	}
}