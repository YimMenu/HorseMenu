#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
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
			auto afkTimer = ScriptGlobal(1102813).At(3919).As<int*>();
            *afkTimer = 999999;
		}
	};

	static AntiAfk _AntiAfk{"antiafk", "Anti Afk", "Prevents your from being idle kicked"};
}