#include "core/commands/Command.hpp"
#include "game/rdr/Natives.hpp"
#include "game/features/Features.hpp"
#include "core/frontend/Notifications.hpp"

namespace YimMenu::Features
{
	class TpToMountToSelf : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
            if(ENTITY::DOES_ENTITY_EXIST(Self::Mount))
				if(PED::GET_MOUNT(Self::PlayerPed) != Self::Mount)
                	ENTITY::SET_ENTITY_COORDS(Self::Mount, Self::Pos.x, Self::Pos.y, Self::Pos.z, true, false, false, true);    
				else
                	Notifications::Show("Teleport", "Already on mount", NotificationType::Warning);

            else
                Notifications::Show("Teleport", "No current mount found", NotificationType::Error);
		}
	};

	static TpToMountToSelf _TpToMountToSelf{"tpmounttoself", "Bring Horse", "Teleport your last horse to you"};
}