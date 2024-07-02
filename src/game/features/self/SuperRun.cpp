#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class SuperRun : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (PED::IS_PED_RAGDOLL(Self::PlayerPed))
				return;

			if (TASK::IS_PED_RUNNING(Self::PlayerPed) || TASK::IS_PED_SPRINTING(Self::PlayerPed))
				ENTITY::APPLY_FORCE_TO_ENTITY(Self::PlayerPed, 1, 0.0f, 20.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1, 1, 1, TRUE, FALSE, TRUE);
		}
	};

	static SuperRun _Superrun{"superrun", "Super Run", "Run faster than normal"};
}