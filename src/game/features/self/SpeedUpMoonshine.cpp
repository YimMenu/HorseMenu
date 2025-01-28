#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/ScriptFunction.hpp"
#include "game/rdr/ScriptGlobal.hpp"


namespace YimMenu::Features
{
	class FastMoonshine : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			static int LastCheck = 0;
			auto MoonshineGlobal = ScriptGlobal(1297600).At(Self::GetPlayer().GetId(), 87).At(19);

			if (!MoonshineGlobal.CanAccess(true) || MISC::GET_SYSTEM_TIME() - LastCheck < 1000)
				return;

			LastCheck = MISC::GET_SYSTEM_TIME();

			auto BottleProgression = MoonshineGlobal.At(16);

			if (*BottleProgression.As<int*>() < 20)
			{
				ScriptFunctions::TriggerMoonshineProduction();
			}
		}
	};

	static FastMoonshine _FastMoonshine{"fastmoonshine", "Fast Moonshine", "Speeds up moonshine production"};
}