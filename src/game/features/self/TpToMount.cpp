#include "core/commands/Command.hpp"
#include "game/rdr/Natives.hpp"
#include "game/features/Features.hpp"
#include "util/teleport.hpp"

namespace YimMenu::Features
{
	class TpToMount : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
            if(ENTITY::DOES_ENTITY_EXIST(Self::Mount) && PED::GET_MOUNT(Self::PlayerPed) != Self::Mount)
                PED::SET_PED_ONTO_MOUNT(Self::PlayerPed, Self::Mount, -1, true);    
            else
                ;//TODO notify
		}
	};

	static TpToMount _TpToMount{"tptomount", "Teleport To Mount", "Get on your mount from anywhere"};
}