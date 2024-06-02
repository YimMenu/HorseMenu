#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class ColorfulLantern : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			Hash currentWeapon;
			WEAPON::GET_CURRENT_PED_WEAPON(Self::PlayerPed, &currentWeapon, false, 0, false);

			if (currentWeapon != WEAPON_MELEE_LANTERN_ELECTRIC)
				return;

			Entity weaponEntity = WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(Self::PlayerPed, 0); // 0 is the hand attach point
			GRAPHICS::_SET_LIGHTS_TYPE_FOR_ENTITY(weaponEntity, 1);
			GRAPHICS::_SET_LIGHTS_INTENSITY_FOR_ENTITY(weaponEntity, 5.0f);
			GRAPHICS::_SET_LIGHTS_COLOR_FOR_ENTITY(weaponEntity, 255, 0, 0);
			GRAPHICS::UPDATE_LIGHTS_ON_ENTITY(weaponEntity);
		}
	};

	static ColorfulLantern _ColorfulLantern{"colorfullantern", "Colorful Lantern", "Makes your lantern colorful"};

}