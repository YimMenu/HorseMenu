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
			Hash current_weapon{};
			int max_ammo{};

			WEAPON::GET_CURRENT_PED_WEAPON(Self::PlayerPed, &current_weapon, false, false, false);
			WEAPON::GET_MAX_AMMO(Self::PlayerPed, &max_ammo, current_weapon);

			auto current_weapon_ammo_type = WEAPON::_GET_CURRENT_PED_WEAPON_AMMO_TYPE(Self::PlayerPed, WEAPON::_GET_PED_WEAPON_OBJECT(Self::PlayerPed, false));
			auto current_ammo = WEAPON::GET_PED_AMMO_BY_TYPE(Self::PlayerPed, current_weapon_ammo_type);

			if (current_ammo < max_ammo)
				WEAPON::SET_PED_AMMO_BY_TYPE(Self::PlayerPed, current_weapon_ammo_type, max_ammo);
		}
	};

	static InfiniteAmmo _InfiniteAmmo{"infiniteammo", "Infinite Ammo", "You will never run out of ammo"};
}