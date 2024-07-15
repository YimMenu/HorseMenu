#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Ped.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class HorseSuperRun : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (Self::GetMount())
			{
				if (Self::GetMount().GetRagdoll())
					return;

				if (TASK::IS_PED_RUNNING(Self::GetMount().GetHandle()) || TASK::IS_PED_SPRINTING(Self::GetMount().GetHandle()))
					ENTITY::APPLY_FORCE_TO_ENTITY(Self::GetMount().GetHandle(), 1, 0.0f, 20.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1, 1, 1, TRUE, FALSE, TRUE);
			}
		}
	};

	static HorseSuperRun _HorseSuperRun{"horsesuperrun", "Super Run", "Your horse will faster than normal"};
}