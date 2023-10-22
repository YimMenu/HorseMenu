#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/ScriptGlobal.hpp"

namespace YimMenu::Features
{
	class OffTheRadar : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (*Pointers.IsSessionStarted)
			{
				auto offtheradar = ScriptGlobal(1102813).At(3).As<int*>();
				if (offtheradar)
					*offtheradar = 32;
			}
		}

		virtual void OnDisable() override
		{
			if (*Pointers.IsSessionStarted)
			{
				auto offtheradar = ScriptGlobal(1102813).At(3).As<int*>();
				if (offtheradar)
					*offtheradar = 0;
			}
		}
	};

	static OffTheRadar _OffTheRadar{"offtheradar", "Off The Radar", "You won't show up on the maps of other players"};
}