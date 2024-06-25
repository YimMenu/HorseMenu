#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/ScriptGlobal.hpp"

namespace YimMenu::Features
{
	//TODO: fix this
	class OffTheRadar : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;
		static constexpr auto offTheRadar = ScriptGlobal(1102813).At(3);

		virtual void OnTick() override
		{
			if (offTheRadar.CanAccess())
				*offTheRadar.As<int*>() = 32;
		}

		virtual void OnDisable() override
		{
			if (offTheRadar.CanAccess())
				*offTheRadar.As<int*>() = 0;
		}
	};

	static OffTheRadar _OffTheRadar{"offtheradar", "Off The Radar", "You won't show up on the maps of other players"};
}