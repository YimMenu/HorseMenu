#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class SuperRun : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (auto ped = Self::GetPed())
			{
				if (PED::IS_PED_RAGDOLL(ped.GetHandle()))
					return;

				if (TASK::IS_PED_RUNNING(ped.GetHandle()) || TASK::IS_PED_SPRINTING(ped.GetHandle()))
					ENTITY::APPLY_FORCE_TO_ENTITY(ped.GetHandle(), 1, 0.0f, 20.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1, 1, 1, true, false, true);
			}
		}
	};

	static SuperRun _Superrun{"superrun", "Super Run", "Run faster than normal"};
}