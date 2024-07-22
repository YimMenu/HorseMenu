#include "Players.hpp"

#include "game/features/Features.hpp"
#include "game/pointers/Pointers.hpp"

#include <network/CNetGamePlayer.hpp>
#include <network/CNetworkPlayerMgr.hpp>
#include <network/rlGamerInfo.hpp>


namespace YimMenu
{
	Players::Players()
	{
		const auto& playerMgr = Pointers.NetworkPlayerMgr;
		if (!playerMgr)
			return;

		for (uint8_t idx = 0; idx < 32u; idx++)
		{
			if (const auto& netPlayer = playerMgr->m_PlayerList[idx];
			    netPlayer && (Pointers.GetNetPlayerFromPid(idx) == netPlayer) && netPlayer->IsValid())
			{
				m_Players[idx] = Player(idx);
				if (!m_PlayerDatas.contains(idx))
					m_PlayerDatas[idx] = PlayerData();
			}
		}
	}

	void Players::OnPlayerJoinImpl(CNetGamePlayer* player)
	{
		m_Players[player->m_PlayerIndex] = Player(player);
		m_PlayerDatas[player->m_PlayerIndex] = PlayerData();
	}

	void Players::OnPlayerLeaveImpl(CNetGamePlayer* player)
	{
		m_Players.erase(player->m_PlayerIndex);
		m_PlayerDatas.erase(player->m_PlayerIndex);
	}

	Player Players::GetByRIDImpl(uint64_t rid)
	{
		for (auto& [idx, player] : Players::GetPlayers())
		{
			if (player.GetGamerInfo()->m_GamerHandle.m_RockstarId == rid)
			{
				return player;
			}
		}

		return nullptr;
	}

	Player Players::GetByHostTokenImpl(uint64_t token)
	{
		for (auto& [idx, player] : Players::GetPlayers())
		{
			if (player.GetGamerInfo()->m_HostToken == token)
			{
				return player;
			}
		}

		return nullptr;
	}
}