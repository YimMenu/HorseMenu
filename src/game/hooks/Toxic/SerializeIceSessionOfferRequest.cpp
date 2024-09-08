#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "util/Joaat.hpp"

#include <network/rlGamerInfo.hpp>

#include "game/backend/PlayerData.hpp"
#include "game/backend/Players.hpp"

namespace YimMenu::Hooks
{
	bool Toxic::SerializeIceSessionOfferRequest(rage::datBitBuffer* buffer, __int64 request)
	{
		auto* peer_id        = (uint64_t*)(request + 0x10);
		auto* remote_peer_id = (uint64_t*)(request + 0xA8);

		for (auto& [_, player] : Players::GetPlayers())
		{
			if (player.GetGamerInfo() && player.GetGamerInfo()->m_PeerId == *remote_peer_id && player.GetData().m_PeerIdToSpoofTo.has_value())
			{
				*peer_id = player.GetData().m_PeerIdToSpoofTo.value();
			}
		}

		return BaseHook::Get<Toxic::SerializeIceSessionOfferRequest, DetourHook<decltype(&Toxic::SerializeIceSessionOfferRequest)>>()->Original()(buffer, request);
	}
}