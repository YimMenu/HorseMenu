#include "core/commands/Command.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class TpToMount : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			if (ENTITY::DOES_ENTITY_EXIST(Self::Mount))
				if (PED::GET_MOUNT(Self::PlayerPed) != Self::Mount)
					PED::SET_PED_ONTO_MOUNT(Self::PlayerPed, Self::Mount, -1, true);
				else
					Notifications::Show("Teleport", "Already on mount", NotificationType::Warning);

			else
				Notifications::Show("Teleport", "No current mount found", NotificationType::Error);
		}
	};

	static TpToMount _TpToMount{"tptomount", "Teleport To Horse", "Get on your horse from anywhere"};
}