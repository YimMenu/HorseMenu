#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class KeepCoresFilled : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (!Self::PlayerPed || PED::IS_PED_DEAD_OR_DYING(Self::PlayerPed, true) || ENTITY::IS_ENTITY_DEAD(Self::PlayerPed))
				return;

			auto health_core = ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(Self::PlayerPed, (int)eAttributeCore::ATTRIBUTE_CORE_HEALTH);
			auto stamina_care = ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(Self::PlayerPed, (int)eAttributeCore::ATTRIBUTE_CORE_STAMINA);
			auto deadeye_core = ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(Self::PlayerPed, (int)eAttributeCore::ATTRIBUTE_CORE_DEADEYE);

			// TODO: should 100 be hardcoded here?
			if (health_core < 100)
				ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(Self::PlayerPed, (int)eAttributeCore::ATTRIBUTE_CORE_HEALTH, 100);
			if (stamina_care < 100)
				ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(Self::PlayerPed, (int)eAttributeCore::ATTRIBUTE_CORE_STAMINA, 100);
			if (deadeye_core < 100)
				ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(Self::PlayerPed, (int)eAttributeCore::ATTRIBUTE_CORE_DEADEYE, 100);
		}
	};

	static KeepCoresFilled _KeepCoresFilled{"keepcoresfilled", "Keep Cores Filled", "Keeps your Health, Stamina and Deadeye cores filled"};
}