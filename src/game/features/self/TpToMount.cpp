#include "core/commands/Command.hpp"
#include "game/backend/Self.hpp"
#include "core/frontend/Notifications.hpp"

namespace YimMenu::Features
{
	class TpToMount : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			if (Self::GetMount())
			{
				Notifications::Show("Teleport", "Already on mount", NotificationType::Warning);
				return;
			}

			if (auto last_mount = Self::GetPed().GetLastMount())
			{
				Self::GetPed().SetInMount(last_mount);
			}
			else
			{
				Notifications::Show("Teleport", "No current mount found", NotificationType::Error);
			}
		}
	};

	static TpToMount _TpToMount{"tptomount", "Teleport To Horse", "Get on your horse from anywhere"};
}