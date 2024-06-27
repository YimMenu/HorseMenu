#include "core/commands/Command.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/features/Features.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Natives.hpp"
#include "util/Chat.hpp"


namespace YimMenu::Features
{
	class ChatHelper : public Command
	{
		using Command::Command;


		virtual void OnCall() override
		{
			if (*Pointers.IsSessionStarted && !SCRIPTS::IS_LOADING_SCREEN_VISIBLE())
			{
				MISC::DISPLAY_ONSCREEN_KEYBOARD(0, "Chat Message", "", "Enter Chat Message Here", "", "", "", 256);
				while (MISC::UPDATE_ONSCREEN_KEYBOARD() == 0)
				{
					ScriptMgr::Yield();
				}

				SendChatMessage(MISC::GET_ONSCREEN_KEYBOARD_RESULT());
			}
			else
			{
				Notifications::Show("Chat", "Please wait until you are in a game to open the chat!", NotificationType::Error);
			}
		}
	};

	static ChatHelper _ChatHelper{"chathelper", "chathelper", "Background Helper for the Chat Feature"};
}