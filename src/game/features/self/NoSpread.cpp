#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class NoSpread : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			PED::SET_PED_ACCURACY(Self::PlayerPed, 100);
		}

		virtual void OnDisable() override
		{
			PED::SET_PED_ACCURACY(Self::PlayerPed, 0); // Does not set it to miss every time, accuracy is weird.
		}
	};

	static NoSpread _NoSpread{"nospread", "No Spread", "Always perfect accuracy on shots"};
}
