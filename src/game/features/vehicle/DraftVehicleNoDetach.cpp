#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class VehicleNoDetach : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			auto veh = Self::GetVehicle();
			if (veh && veh.IsDraft())
			{
				VEHICLE::_SET_DRAFT_VEHICLE_ANIMALS_CAN_DETACH(veh.GetHandle(), FALSE);
				for (int i = 0; i < veh.GetNumDraftAnimals(); i++)
				{
					auto ped = veh.GetPedInHarness(i);
					PED::SET_PED_CAN_RAGDOLL(ped.GetHandle(), FALSE);
				}
			}
		}

		virtual void OnDisable() override
		{
			auto veh = Self::GetVehicle();
			if (veh && veh.IsDraft())
			{
				VEHICLE::_SET_DRAFT_VEHICLE_ANIMALS_CAN_DETACH(veh.GetHandle(), TRUE);
				for (int i = 0; i < veh.GetNumDraftAnimals(); i++)
				{
					auto ped = veh.GetPedInHarness(i);
					PED::SET_PED_CAN_RAGDOLL(ped.GetHandle(), TRUE);
				}
			}
		}
	};

	static VehicleNoDetach _VehicleNoDetach{"vehiclenodetach", "Vehicle No Detach", "Makes it much harder for draft animals to detach from your vehicle"};
}