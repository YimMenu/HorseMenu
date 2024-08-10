#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu
{
	class FlamingHooves : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			// TODO: cleanup when player leaves horse?
			if (Self::GetMount())
				Self::GetMount().SetConfigFlag(PedConfigFlag::FlamingHoovesActive, true);
		}

		virtual void OnDisable() override
		{
			if (Self::GetMount())
				Self::GetMount().SetConfigFlag(PedConfigFlag::FlamingHoovesActive, false);
		}
	};

	static FlamingHooves _FlamingHooves{"flaminghooves", "Flaming Hooves", "Your horse will have flaming hooves."};

	class FlamingHoovesDraft : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			auto veh = Self::GetVehicle();
			if (veh && veh.IsDraft())
			{
				for (int i = 0; i < veh.GetNumDraftAnimals(); i++)
				{
					auto ped = veh.GetPedInHarness(i);
					PED::SET_PED_CONFIG_FLAG(ped.GetHandle(), (int)PedConfigFlag::FlamingHoovesActive, TRUE);
				}
			}
		}

		virtual void OnDisable() override
		{
			auto veh = Self::GetVehicle();
			if (veh && veh.IsDraft())
			{
				for (int i = 0; i < veh.GetNumDraftAnimals(); i++)
				{
					auto ped = veh.GetPedInHarness(i);
					PED::SET_PED_CONFIG_FLAG(ped.GetHandle(), (int)PedConfigFlag::FlamingHoovesActive, FALSE);
				}
			}
		}
	};

	static FlamingHoovesDraft _FlamingHoovesDraft{"flaminghoovesdraft", "Flaming Hooves", "Your draft animals will have flaming hooves"};
}