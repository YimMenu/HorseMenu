#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class NoRagdoll : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
            if(PED::CAN_PED_RAGDOLL(Self::PlayerPed))
			    PED::SET_PED_CAN_RAGDOLL(Self::PlayerPed, false);
		}

        virtual void OnDisable() override
        {
            PED::SET_PED_CAN_RAGDOLL(Self::PlayerPed, true);
        }
	};

	static NoRagdoll _NoRagdoll{"noragdoll", "No Ragdoll", "You will never ragdoll"};
}