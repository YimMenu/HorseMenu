#include "core/commands/LoopedCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class EagleEye : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (!PLAYER::_IS_SECONDARY_SPECIAL_ABILITY_ACTIVE(YimMenu::Self::Id)) // Checks if Eagle Eye is active before toggling it on
			{
				PLAYER::_SECONDARY_SPECIAL_ABILITY_SET_ACTIVE(YimMenu::Self::Id); // Toggles Eagle Eye on
				PLAYER::_EAGLE_EYE_SET_PLUS_FLAG_DISABLED(YimMenu::Self::Id, false); // Allows running while eagle eye is active
				Notifications::Show("Eagle Eye", "Infinite Eagle eye has been enabled.  This allows you to run while eagle eye is active as well.", NotificationType::Success);
			}
			PLAYER::_MODIFY_INFINITE_TRAIL_VISION(YimMenu::Self::Id, 1); // Sets Eagle Eye to Infinite
		}

		virtual void OnDisable() override
		{
			PLAYER::_SECONDARY_SPECIAL_ABILITY_SET_DISABLED(YimMenu::Self::Id, 1); // Disables Eagle Eye
			PLAYER::_MODIFY_INFINITE_TRAIL_VISION(YimMenu::Self::Id, 0);           // Turns off Infinite Eagle Eye
			PLAYER::_EAGLE_EYE_SET_PLUS_FLAG_DISABLED(YimMenu::Self::Id, NULL); //Setting to truee breaks it, leave it at NULL
			Notifications::Show("Eagle Eye", "Infinite Eagle eye has been disabled.", NotificationType::Success);
		}
	};

	static EagleEye _EagleEye{"eagleeye", "Eagle Eye", "Enables Infinite/Always Active Eagle Eye."};
}
