#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "core/frontend/Notifications.hpp"

namespace YimMenu::Features
{
	class EagleEye : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if(!PLAYER::_IS_SECONDARY_SPECIAL_ABILITY_ACTIVE(PLAYER::PLAYER_ID())) // Checks if Eagle Eye is active before toggling it on
			{
				PLAYER::_SECONDARY_SPECIAL_ABILITY_SET_ACTIVE(PLAYER::PLAYER_ID()); // Toggles Eagle Eye on
				Notifications::Show("Eagle Eye", "Infinite Eagle eye has been enabled.", NotificationType::Success);
				Notifications::Show("WARNING", "When this is active, it will always reactivate eagle eye for you, you still cannot run using it.", NotificationType::Warning);
			}
			PLAYER::_MODIFY_INFINITE_TRAIL_VISION(PLAYER::PLAYER_ID(), 1); // Sets Eagle Eye to Infinite
		}

		virtual void OnDisable() override
		{
			PLAYER::_SECONDARY_SPECIAL_ABILITY_SET_DISABLED(PLAYER::PLAYER_ID(), 1); // Disables Eagle Eye
			PLAYER::_MODIFY_INFINITE_TRAIL_VISION(PLAYER::PLAYER_ID(), 0); // Turns off Infinite Eagle Eye
			Notifications::Show("Eagle Eye", "Infinite Eagle eye has been disabled.", NotificationType::Success);
		}
	};

	static EagleEye _EagleEye{"eagleeye", "Eagle Eye", "Enables Infinite/Always Active Eagle Eye."};
}
