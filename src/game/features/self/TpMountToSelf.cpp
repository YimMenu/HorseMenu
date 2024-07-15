#include "core/commands/Command.hpp"
#include "game/backend/Self.hpp"
#include "core/frontend/Notifications.hpp"

namespace YimMenu::Features
{
	class TpToMountToSelf : public Command
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
				last_mount.SetPosition(Self::GetPed().GetPosition());
			}
			else
			{
				Notifications::Show("Teleport", "No current mount found", NotificationType::Error);
			}
		}
	};

	static TpToMountToSelf _TpToMountToSelf{"tpmounttoself", "Bring Horse", "Teleport your last horse to you"};
}