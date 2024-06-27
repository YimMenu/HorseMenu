#include "Players.hpp"

#include "game/pointers/Pointers.hpp"

#include <network/CNetGamePlayer.hpp>
#include <network/CNetworkPlayerMgr.hpp>
#include <network/rlGamerInfo.hpp>


namespace YimMenu
{
	void Players::TickImpl()
	{
		const auto& playerMgr = Pointers.NetworkPlayerMgr;
		if (!playerMgr || !g_Running)
			return;

		for (uint8_t idx = 0; idx < 32u; idx++)
		{
			if (const auto& netPlayer = playerMgr->m_PlayerList[idx];
			    netPlayer && (Pointers.GetNetPlayerFromPid(idx) == netPlayer /*game also does this*/) && netPlayer->IsValid())
			{
				m_Players[idx] = Player(idx);
			}
			else
			{
				m_Players.erase(idx);
			}
		}
	}

	Player Players::GetByHostTokenImpl(uint64_t hostToken)
	{
		for (auto& [idx, player] : Players::GetPlayers())
		{
			if (player.GetGamerInfo()->m_HostToken == hostToken)
			{
				return player;
			}
		}

		return nullptr;
	}
}