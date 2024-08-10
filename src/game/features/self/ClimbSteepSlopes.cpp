#include "core/commands/LoopedCommand.hpp"
#include "game/rdr/Natives.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	class ClimbSteepSlopes : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			PED::SET_PED_RESET_FLAG(Self::GetPed().GetHandle(), 204, true);
		}
	};

	static ClimbSteepSlopes _ClimbSteepSlopes{"climbsteepslopes", "Can Climb Steep Slopes", "You can climb up/down steep slopes without sliding"};
}