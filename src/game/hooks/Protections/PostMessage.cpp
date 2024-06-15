#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"

#include <network/rlGamerInfo.hpp>


namespace YimMenu::Hooks
{
	bool Protections::PPostMessage(int localGamerIndex, rage::rlGamerInfo* recipients, int numRecipients, const char* msg, unsigned int ttlSeconds)
	{
		LOG(VERBOSE) << "Local Gamer Index: " << localGamerIndex;
		LOG(VERBOSE) << "Recipients name and rid: " << std::string(recipients->m_Name).c_str() << " "
		             << recipients->m_GamerHandle.m_rockstar_id;

		LOG(VERBOSE) << "Num recipients: " << numRecipients;
		LOG(VERBOSE) << "Message: " << msg;
		LOG(VERBOSE) << "TTL: " << ttlSeconds;

		return BaseHook::Get<Protections::PPostMessage, DetourHook<decltype(&Protections::PPostMessage)>>()->Original()(localGamerIndex, recipients, numRecipients, msg, ttlSeconds);
	}
}