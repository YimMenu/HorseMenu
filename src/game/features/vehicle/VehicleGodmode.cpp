#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class VehicleGodmode : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			ENTITY::SET_ENTITY_INVINCIBLE(Self::Veh, true);
		}

		virtual void OnDisable() override
		{
			ENTITY::SET_ENTITY_INVINCIBLE(Self::Veh, false);
		}
	};

	static VehicleGodmode _Godmode{"vehiclegodmode", "Vehicle God Mode", "Blocks all incoming damage to your current vehicle"};
}