#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class HorseNoRagdoll : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (Self::GetMount())
				Self::GetMount().SetRagdoll(false);
		}

        virtual void OnDisable() override
        {
			if (Self::GetMount())
				Self::GetMount().SetRagdoll(true);
        }
	};

	static HorseNoRagdoll _HorseNoRagdoll{"horsenoragdoll", "No Ragdoll", "Your horse will never ragdoll"};
}