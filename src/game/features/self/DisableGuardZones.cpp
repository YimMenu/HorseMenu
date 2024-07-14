#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/ScriptGlobal.hpp"

namespace YimMenu::Features
{
	const char* locations[] = {"ANNESBURG_MINES", "ANNESBURG_FACTORY", "CALIGA_HALL", "BUTCHER_CREEK", "CARMODY_DELL", "TWIN_ROCKS", "CORNWALL_KEROSENE", "GUTHRIE_FARM", "DAIRY_FARM", "DOWNS_RANCH", "GRANGERS_HOGGERY", "OLD_FORT_WALLACE", "LARNED_SOD", "MACFARLANES_RANCH", "MACLEANS_RANCH", "ORANGE_PLANTATION", "PAINTED_SKY", "RATHSKELLER_FORK", "BRONTE", "SCARLET_HORSE_SHOP_OUTSIDE_PENS", "BRAITHWAITE_MANOR", "SISIKA"};

	class DisableGuardZones : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (*Pointers.IsSessionStarted)
			{
				for (const char* location : locations)
				{
					LAW::_DISABLE_GUARD_ZONE(location);
					LAW::_REMOVE_GUARD_ZONE(location);
				}
			}
		}
	};

	static DisableGuardZones _DisableGuardZones{"disableguardzones", "Disable Guard Zones", "Allow you to enter restricted areas such as Sisika"};
}