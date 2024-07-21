#include "core/commands/LoopedCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class EagleEye : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			auto id = YimMenu::Self::GetPlayer().GetId();
			if (!PLAYER::_IS_SECONDARY_SPECIAL_ABILITY_ACTIVE(id)) // Checks if Eagle Eye is active before toggling it on
			{
				PLAYER::_SECONDARY_SPECIAL_ABILITY_SET_ACTIVE(id);                   // Toggles Eagle Eye on
				PLAYER::_EAGLE_EYE_SET_PLUS_FLAG_DISABLED(id, false); // Allows running while eagle eye is active	
			}
			PLAYER::_MODIFY_INFINITE_TRAIL_VISION(id, 1); // Sets Eagle Eye to Infinite
		}

		virtual void OnDisable() override
		{
			auto id = YimMenu::Self::GetPlayer().GetId();
			PLAYER::_SECONDARY_SPECIAL_ABILITY_SET_DISABLED(id, 1);             // Disables Eagle Eye
			PLAYER::_MODIFY_INFINITE_TRAIL_VISION(id, 0);                       // Turns off Infinite Eagle Eye
			PLAYER::_EAGLE_EYE_SET_PLUS_FLAG_DISABLED(id, false); // Setting to truee breaks it, leave it at false
		}
	};

	static EagleEye _EagleEye{"eagleeye", "Eagle Eye", "Enables infinite/always active Eagle Eye"};
}
