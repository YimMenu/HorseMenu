#include "util/Chat.hpp"

#include "core/commands/Command.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
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
				bool is_chat_cancelled = false;
				MISC::DISPLAY_ONSCREEN_KEYBOARD(0, "Chat Message", "", "", "", "", "", 256);
				while (MISC::UPDATE_ONSCREEN_KEYBOARD() == 0)
				{
					if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
					{
						MISC::CANCEL_ONSCREEN_KEYBOARD();
						is_chat_cancelled = true;
					}

					ScriptMgr::Yield();
				}

				if (!is_chat_cancelled)
					SendChatMessage(MISC::GET_ONSCREEN_KEYBOARD_RESULT());
			}
			else
			{
				Notifications::Show("Chat", "Please wait until you are in a game to open the chat!", NotificationType::Error);
			}
		}
	};

	static Chat _Chat{"chathelper", "Chat", "Use this to open the chat!"};
}