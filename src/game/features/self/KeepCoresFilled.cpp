#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	static BoolCommand _DeadeyeCore{"keepdeadeyecorefilled", "Deadeye", "Keep Deadeye Core Filled", true};
	static BoolCommand _StaminaCore{"keepstaminacorefilled", "Stamina", "Keep Stamina Core Filled", true};
	static BoolCommand _HealthCore{"keephealthcorefilled", "Health", "Keep Health Core Filled", true};

	class KeepCoresFilled : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			auto ped = Self::GetPed();
			if (!ped || ped.IsDead())
				return;

			auto health_core = ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(ped.GetHandle(), (int)AttributeCore::ATTRIBUTE_CORE_HEALTH);
			auto stamina_care = ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(ped.GetHandle(), (int)AttributeCore::ATTRIBUTE_CORE_STAMINA);
			auto deadeye_core = ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(ped.GetHandle(), (int)AttributeCore::ATTRIBUTE_CORE_DEADEYE);

			// TODO: should 100 be hardcoded here?
			if (health_core < 100 && _HealthCore.GetState())
				ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(ped.GetHandle(), (int)AttributeCore::ATTRIBUTE_CORE_HEALTH, 100);
			if (stamina_care < 100 && _StaminaCore.GetState())
				ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(ped.GetHandle(), (int)AttributeCore::ATTRIBUTE_CORE_STAMINA, 100);
			if (deadeye_core < 100 && _DeadeyeCore.GetState())
				ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(ped.GetHandle(), (int)AttributeCore::ATTRIBUTE_CORE_DEADEYE, 100);
		}
	};

	static KeepCoresFilled _KeepCoresFilled{"keepcoresfilled", "Keep Cores Filled", "Keeps your Health, Stamina and Deadeye cores filled"};
}