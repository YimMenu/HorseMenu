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
			if (PED::CAN_PED_RAGDOLL(Self::PlayerPed))
			{
				PED::SET_PED_CAN_RAGDOLL(Self::PlayerPed, FALSE);
				PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(Self::PlayerPed, FALSE);
			}
		}

        virtual void OnDisable() override
        {
            PED::SET_PED_CAN_RAGDOLL(Self::PlayerPed, TRUE);
	    PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(Self::PlayerPed, TRUE);
        }
	};

	static NoRagdoll _NoRagdoll{"noragdoll", "No Ragdoll", "You will never ragdoll"};
}
