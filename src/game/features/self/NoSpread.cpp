#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	class NoSpread : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (Self::GetPed())
				Self::GetPed().SetAccuracy(100);
		}

		virtual void OnDisable() override
		{
			if (Self::GetPed())
				Self::GetPed().SetAccuracy(0);
		}
	};

	static NoSpread _NoSpread{"nospread", "No Spread", "Always perfect accuracy on shots"};
}
