#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/ScriptGlobal.hpp"

namespace YimMenu::Features
{
	class AntiAfk : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;
		static constexpr auto timer = ScriptGlobal(1102813).At(3919);
		static constexpr auto afkSwitch = ScriptGlobal(1102813).At(3918);

		virtual void OnTick() override
		{
			if (*Pointers.IsSessionStarted)
			{
				if (timer.CanAccess(true) && afkSwitch.CanAccess(true))
				{
					*timer.As<int*>() = INT_MAX;
					*afkSwitch.As<bool*>() = false;
				}
			}
		}
	};

	static AntiAfk _AntiAfk{"antiafk", "Anti Afk", "Prevents you from being idle kicked"};
}