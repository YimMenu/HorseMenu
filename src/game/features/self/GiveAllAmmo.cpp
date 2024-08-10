#include "core/commands/Command.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/data/AmmoTypes.hpp"

namespace YimMenu::Features
{
	class GiveAllAmmo : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			for (const auto& ammo : Data::g_AmmoTypes)
				WEAPON::_ADD_AMMO_TO_PED_BY_TYPE(Self::GetPed().GetHandle(), Joaat(ammo), 9999, 0x2CD419DC);
		}
	};

	static GiveAllAmmo _GiveAllAmmo{"giveallammo", "Give All Ammo", "Gives you all the kinds of ammo"};
}