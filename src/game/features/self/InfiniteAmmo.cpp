#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class InfiniteAmmo : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (Self::GetPed())
				WEAPON::SET_PED_INFINITE_AMMO(Self::GetPed().GetHandle(), true, 0);
		}

		virtual void OnDisable() override
		{
			if (Self::GetPed())
				WEAPON::SET_PED_INFINITE_AMMO(Self::GetPed().GetHandle(), false, 0);
		}
	};

	static InfiniteAmmo _InfiniteAmmo{"infiniteammo", "Infinite Ammo", "You will never run out of ammo"};
}