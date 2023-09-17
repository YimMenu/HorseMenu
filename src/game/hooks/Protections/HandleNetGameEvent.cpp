#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include <network/CNetGamePlayer.hpp>

namespace YimMenu::Hooks
{
	void Protections::HandleNetGameEvent(rage::netEventMgr* eventMgr, CNetGamePlayer* sourcePlayer, CNetGamePlayer* targetPlayer, NetEventType type, int index, int handledBits, std::int16_t unk, rage::datBitBuffer* buffer)
	{
		if (type == NetEventType::NETWORK_PTFX_EVENT && sourcePlayer)
		{
			LOG(WARNING) << "Blocked NETWORK_PTFX_EVENT from " << sourcePlayer->GetName();
			Pointers.SendEventAck(eventMgr, sourcePlayer, targetPlayer, index, handledBits);
			return;
		}

		BaseHook::Get<Protections::HandleNetGameEvent, DetourHook<decltype(&Protections::HandleNetGameEvent)>>()->Original()(eventMgr, sourcePlayer, targetPlayer, type, index, handledBits, unk, buffer);
	}
}