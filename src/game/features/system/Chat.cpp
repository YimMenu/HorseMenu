#include "util/Chat.hpp"

#include "core/commands/Command.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/frontend/ChatDisplay.hpp"
#include "game/frontend/GUI.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Natives.hpp"


namespace YimMenu::Features
{
	class Chat : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			if (*Pointers.IsSessionStarted && !SCRIPTS::IS_LOADING_SCREEN_VISIBLE() && MISC::UPDATE_ONSCREEN_KEYBOARD() != 0 && !GUI::IsOpen())
			{
				ScriptMgr::Yield(100ms); // Delay so hotkey key doesn't get mistaken as input
				MISC::DISPLAY_ONSCREEN_KEYBOARD(0, "Chat Message", "", "", "", "", "", 256);
				while (MISC::UPDATE_ONSCREEN_KEYBOARD() == 0)
				{
					ScriptMgr::Yield();
				}

				if (MISC::UPDATE_ONSCREEN_KEYBOARD() == 1)
					if (auto res = MISC::GET_ONSCREEN_KEYBOARD_RESULT())
						SendChatMessage(res);
			}
		}
	};

	class ClearChat : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			ChatDisplay::Clear();
		}
	};

	static Chat _Chat{"chathelper", "Chat", "Use this to open the chat"};
	static ClearChat _ClearChat{"clearchat", "Clear Chat", "Use this to clear the chat"};
}