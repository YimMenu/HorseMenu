#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class VehicleGodmode : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			auto veh = Self::GetVehicle();
			if (veh)
			{
				veh.SetInvincible(true);
				if (veh.IsDraft())
				{
					for (int i = 0; i < veh.GetNumDraftAnimals(); i++)
					{
						auto ped = veh.GetPedInHarness(i);
						ped.SetInvincible(true);
					}
				}
			}
		}

		virtual void OnDisable() override
		{
			auto veh = Self::GetVehicle();
			if (veh)
			{
				veh.SetInvincible(false);
				if (veh.IsDraft())
				{
					for (int i = 0; i < veh.GetNumDraftAnimals(); i++)
					{
						auto ped = veh.GetPedInHarness(i);
						ped.SetInvincible(false);
					}
				}
			}
		}
	};

	static VehicleGodmode _VehicleGodmode{"vehiclegodmode", "Vehicle God Mode", "Blocks all incoming damage to your current vehicle"};
}