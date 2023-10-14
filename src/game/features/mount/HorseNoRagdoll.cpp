#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class HorseNoRagdoll : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
            if(PED::CAN_PED_RAGDOLL(Self::Mount))
			    PED::SET_PED_CAN_RAGDOLL(Self::Mount, false);
		}

		//Doesn't work
        virtual void OnDisable() override
        {
            PED::SET_PED_CAN_RAGDOLL(Self::Mount, true);
        }
	};

	static HorseNoRagdoll _HorseNoRagdoll{"horsenoragdoll", "No Ragdoll", "Your horse will never ragdoll"};
}