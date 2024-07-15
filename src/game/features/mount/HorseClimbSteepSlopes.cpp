#include "core/commands/LoopedCommand.hpp"
#include "game/rdr/Natives.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	class HorseClimbSteepSlopes : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (Self::GetMount())
			{
				PED::SET_PED_RESET_FLAG(Self::GetMount().GetHandle(), 204, true);
			}
		}
	};

	static HorseClimbSteepSlopes _HorseClimbSteepSlopes{"horseclimbsteepslopes", "Can Climb Steep Slopes", "Your horse can climb up/down steep slopes without sliding"};
}