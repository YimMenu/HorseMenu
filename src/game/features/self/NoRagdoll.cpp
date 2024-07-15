#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	class NoRagdoll : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			Self::GetPed().SetRagdoll(false);
		}

        virtual void OnDisable() override
        {
			Self::GetPed().SetRagdoll(true);
        }
	};

	static NoRagdoll _NoRagdoll{"noragdoll", "No Ragdoll", "You will never ragdoll"};
}