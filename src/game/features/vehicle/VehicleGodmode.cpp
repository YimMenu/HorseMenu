#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	class VehicleGodmode : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (Self::GetVehicle())
				Self::GetVehicle().SetInvincible(true);
		}

		virtual void OnDisable() override
		{
			if (Self::GetVehicle())
				Self::GetVehicle().SetInvincible(false);
		}
	};

	static VehicleGodmode _VehicleGodmode{"vehiclegodmode", "Vehicle God Mode", "Blocks all incoming damage to your current vehicle"};
}