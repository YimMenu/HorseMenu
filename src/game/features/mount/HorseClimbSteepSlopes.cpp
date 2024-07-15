#include "core/commands/LoopedCommand.hpp"
#include "game/rdr/Natives.hpp"
#include "game/features/Features.hpp"

namespace YimMenu::Features
{
	class HorseClimbSteepSlopes : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			PED::SET_PED_RESET_FLAG(Self::Mount, 204, true);
		}
	};

	static HorseClimbSteepSlopes _HorseClimbSteepSlopes{"horseclimbsteepslopes", "Can Climb Steep Slopes", "Your horse can climb up/down steep slopes without sliding"};
}