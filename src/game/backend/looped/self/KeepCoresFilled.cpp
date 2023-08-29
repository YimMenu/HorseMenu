#include "../Looped.hpp"
#include "../../../rdr/Natives.hpp"
#include "SelfLooped.hpp"
#include "../../commands/FeatureCommand.hpp"


namespace YimMenu
{
	//TODO Outsource the actual refill to a seperate non-looped function to expand utility.
	void looped::KeepCoresFilled()
	{
		if (!Self::refill_cores)
			return;

		auto health_core  = ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(Self::ped, (int)eAttributeCore::ATTRIBUTE_CORE_HEALTH);
		auto stamina_care = ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(Self::ped, (int)eAttributeCore::ATTRIBUTE_CORE_STAMINA);
		auto deadeye_core = ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(Self::ped, (int)eAttributeCore::ATTRIBUTE_CORE_DEADEYE);

		if (health_core < 100)
			ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(Self::ped, (int)eAttributeCore::ATTRIBUTE_CORE_HEALTH, 100);
		if (stamina_care < 100)
			ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(Self::ped, (int)eAttributeCore::ATTRIBUTE_CORE_STAMINA, 100);
		if (deadeye_core < 100)
			ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(Self::ped, (int)eAttributeCore::ATTRIBUTE_CORE_DEADEYE, 100);
	}

	static FeatureCommand command{"keepcoresfilled", "Keep Cores Filled", looped::KeepCoresFilled, 0, true, &Self::refill_cores};
}