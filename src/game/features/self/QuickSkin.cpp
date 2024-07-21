#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class QuickSkin : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (TASK::GET_IS_TASK_ACTIVE(Self::GetPed().GetHandle(), 628))
			{
				if (!SCRIPTS::GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH("fishing_core"_J))
				{
					TASK::CLEAR_PED_TASKS_IMMEDIATELY(Self::GetPed().GetHandle(), TRUE, TRUE);
				}
			}
		}
	};

	static QuickSkin _QuickSkin{"quickskin", "Quick Skin", "You will skin animals much faster"};
}