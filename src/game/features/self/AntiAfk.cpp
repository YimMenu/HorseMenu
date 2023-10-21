#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/ScriptGlobal.hpp"

namespace YimMenu::Features
{
	class AntiAfk : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (*Pointers.IsSessionStarted)
			{
				auto timer     = ScriptGlobal(1102813).At(3919).As<int*>();
				auto afkswitch = ScriptGlobal(1102813).At(3918).As<int*>();
				if (timer && afkswitch)
					*timer = 999999, *afkswitch = 0;
			}
		}
	};

	static AntiAfk _AntiAfk{"antiafk", "Anti Afk", "Prevents you from being idle kicked"};
}