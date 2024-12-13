#include "core/commands/BoolCommand.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"

#include <network/rlGamerInfo.hpp>

namespace YimMenu::Features
{
	BoolCommand _LogPostMessage{"logpostmessage", "Log Post Message", "Log messages sent via Post Message"};
}


namespace YimMenu::Hooks
{
	bool Protections::PPostMessage(int localGamerIndex, rage::rlGamerHandle* recipients, int numRecipients, const char* msg, unsigned int ttlSeconds)
	{
		if (Features::_LogPostMessage.GetState())
		{
			LOG(VERBOSE) << "PostMessage :: " << msg;
		}

		return BaseHook::Get<Protections::PPostMessage, DetourHook<decltype(&Protections::PPostMessage)>>()->Original()(localGamerIndex, recipients, numRecipients, msg, ttlSeconds);
	}
}