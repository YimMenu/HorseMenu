#include "util/Chat.hpp"

#include "core/commands/Command.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/frontend/ChatDisplay.hpp"
#include "game/frontend/GUI.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Natives.hpp"

#include "game/backend/MapEditor/Menu/NativeDrawing.hpp"


namespace YimMenu::Features
{
	class Chat : public Command
	{
		using Command::Command;

		std::mutex m_ChatMutex;

		virtual void OnCall() override
		{
			if (*Pointers.IsSessionStarted && MISC::UPDATE_ONSCREEN_KEYBOARD() != 0)
			{
				if (!m_ChatMutex.try_lock())
					return;

				char buffer[256]{};
				if (NativeUI::ShowTextBox("Enter Message", buffer, sizeof(buffer)))
					SendChatMessage(buffer);

				m_ChatMutex.unlock();
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