#include "Players.hpp"
#include <network/CNetGamePlayer.hpp>
#include <network/CNetworkPlayerMgr.hpp>
#include "game/pointers/Pointers.hpp"

namespace YimMenu
{
	Players::Players()
	{
		if (*Pointers.IsSessionStarted)
			for (int i = 0; i < 32; i++)
				if (Pointers.NetworkPlayerMgr->m_PlayerList[i] && Pointers.NetworkPlayerMgr->m_PlayerList[i]->IsValid())
					HandlePlayerJoinImpl(Pointers.NetworkPlayerMgr->m_PlayerList[i]);
	}

	void Players::HandlePlayerJoinImpl(CNetGamePlayer* player)
	{
		m_Players.insert({ player->GetName(), player });
	}

	void Players::HandlePlayerLeaveImpl(CNetGamePlayer* player)
	{
		if (m_SelectedPlayer == player)
			m_SelectedPlayer = nullptr;

		if (auto it = std::find_if(m_Players.begin(),
		        m_Players.end(),
		        [player](const auto& p) {
			        return p.second == Player(player);
		        });
		    it != m_Players.end())
		{
			m_Players.erase(it);
		}
	}
}