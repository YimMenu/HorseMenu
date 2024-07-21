#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class AutoCock : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (Self::GetPed())
				WEAPON::_SET_FORCE_CURRENT_WEAPON_INTO_COCKED_STATE(Self::GetPed().GetHandle(), 0);
		}
	};

	static AutoCock _AutoCock{"autocock", "Auto Cock", "Automatically cock your weapon"};
}