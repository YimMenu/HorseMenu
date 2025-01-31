#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "game/backend/ScriptPatches.hpp"

namespace YimMenu::Features
{
	const char* locations[] = {"ANNESBURG_MINES", "ANNESBURG_FACTORY", "CALIGA_HALL", "BUTCHER_CREEK", "CARMODY_DELL", "TWIN_ROCKS", "CORNWALL_KEROSENE", "GUTHRIE_FARM", "DAIRY_FARM", "DOWNS_RANCH", "GRANGERS_HOGGERY", "OLD_FORT_WALLACE", "LARNED_SOD", "MACFARLANES_RANCH", "MACLEANS_RANCH", "ORANGE_PLANTATION", "PAINTED_SKY", "RATHSKELLER_FORK", "BRONTE", "SCARLET_HORSE_SHOP_OUTSIDE_PENS", "BRAITHWAITE_MANOR", "SISIKA"};

	class DisableGuardZones : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		std::shared_ptr<ScriptPatches::Patch> m_Patch1{};
		std::shared_ptr<ScriptPatches::Patch> m_Patch2{};
		std::shared_ptr<ScriptPatches::Patch> m_Patch3{};
		std::shared_ptr<ScriptPatches::Patch> m_Patch4{};
		std::shared_ptr<ScriptPatches::Patch> m_Patch5{};

		virtual void OnEnable() override
		{
			if (!m_Patch1)
			{
				m_Patch1 = ScriptPatches::AddPatch("net_main_offline"_J, true, "39 ? ? ? 66 03 05 8B ? ? 2F", 0, {0x41, 0x41, 0x13, 0x13}); // disable guarma warp
			}
			m_Patch1->Enable();

			if (!m_Patch2)
			{
				m_Patch2 = ScriptPatches::AddPatch("sisikapenitentiary"_J, true, "22 01 05 00 00 66 00 67 00", 5, {0x09, 0x50, 0x01, 0x01}); // disable sisika warp
			}
			m_Patch2->Enable();

			if (!m_Patch3)
			{
				m_Patch3 = ScriptPatches::AddPatch("short_update"_J, true, "22 00 06 00 00 03", 5, {0x50, 0x00, 0x00}); // disable sisika warp 2
			}
			m_Patch3->Enable();

			if (!m_Patch4)
			{
				m_Patch4 = ScriptPatches::AddPatch("serendipity"_J, true, "22 01 03 00 00 66 00 67 00 6D", 5, {0x2F, 0x50, 0x01, 0x01}); // disable grand korrigan warp
			}
			m_Patch4->Enable();

			if (!m_Patch5)
			{
				m_Patch5 = ScriptPatches::AddPatch("medium_update"_J, false, "22 00 10 00 00", 5, {0x50, 0x00, 0x00}); // disable invisible sniper
			}
			m_Patch5->Enable();
		}

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

		virtual void OnDisable()
		{
			m_Patch1->Disable();
			m_Patch2->Disable();
			m_Patch3->Disable();
			m_Patch4->Disable();
			m_Patch5->Disable();
		}
	};

	static DisableGuardZones _DisableGuardZones{"disableguardzones", "Disable Restricted Areas", "Allows you to enter restricted areas"};
}