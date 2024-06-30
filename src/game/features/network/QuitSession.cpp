#include "core/commands/Command.hpp"
#include "game/rdr/Natives.hpp"
#include "game/features/Features.hpp"
#include "core/frontend/Notifications.hpp"

namespace YimMenu::Features
{
	class QuitSession : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
            		NETWORK::NETWORK_SESSION_LEAVE_SESSION();
			Notifications::Show("Session", "Quitting to Main Menu...", NotificationType::Warning);
		}
	};

	static QuitSession _QuitSession{"quitsession", "Leave Session", "Leaves the current online session putting you at the main menu."};
}
