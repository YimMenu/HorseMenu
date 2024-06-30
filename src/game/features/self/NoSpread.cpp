#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class AccuracyMax : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			PED::SET_PED_ACCURACY(Self::PlayerPed, 100);
		}
	};

	static AccuracyMax _AccuracyMax{"maxaccuracy", "No Spread", "Always perfect accuracy on shots"};
}
