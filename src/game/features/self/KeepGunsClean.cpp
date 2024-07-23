#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class KeepGunsClean : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (WEAPON::IS_WEAPON_A_GUN(WEAPON::_GET_PED_CURRENT_HELD_WEAPON(Self::GetPed().GetHandle())))
			{
				if (auto weaponObj = WEAPON::_GET_PED_WEAPON_OBJECT(Self::GetPed().GetHandle(), true))
				{
					WEAPON::_SET_WEAPON_DEGRADATION(weaponObj, 0.0f);
					WEAPON::_SET_WEAPON_DIRT(weaponObj, 0.0f, true);
					WEAPON::_SET_WEAPON_SOOT(weaponObj, 0.0f, true);
				}
			}
		}
	};

	static KeepGunsClean _KeepGunsClean{"keepgunsclean", "Keep Guns Clean", "Keeps your Guns in Pristine condition"};
}