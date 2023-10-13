#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class InfiniteAmmo : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			WEAPON::SET_PED_INFINITE_AMMO(Self::PlayerPed, true, 0);
		}

		virtual void OnDisable() override
		{
			WEAPON::SET_PED_INFINITE_AMMO(Self::PlayerPed, false, 0);
		}
	};

	static InfiniteAmmo _InfiniteAmmo{"infiniteammo", "Infinite Ammo", "You will never run out of ammo"};
}