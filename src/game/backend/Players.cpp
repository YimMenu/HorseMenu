#include "Players.hpp"
#include <network/CNetGamePlayer.hpp>

namespace YimMenu
{
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