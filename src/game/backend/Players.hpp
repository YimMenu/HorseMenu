#pragma once
#include "game/rdr/Player.hpp"

namespace YimMenu
{
	class Players
	{
		std::multimap<std::string, Player> m_Players{};
		Player m_SelectedPlayer = nullptr;

	public:
		static void HandlePlayerJoin(CNetGamePlayer* player)
		{
			GetInstance().HandlePlayerJoinImpl(player);
		}

		static void HandlePlayerLeave(CNetGamePlayer* player)
		{
			GetInstance().HandlePlayerLeaveImpl(player);
		}

		static Player GetSelected()
		{
			return GetInstance().m_SelectedPlayer;
		}

		static void SetSelected(Player player)
		{
			GetInstance().m_SelectedPlayer = player;
		}

		static std::multimap<std::string, Player>& GetPlayers()
		{
			return GetInstance().m_Players;
		}

	private:
		static Players& GetInstance()
		{
			static Players Instance;
			return Instance;
		}

		void HandlePlayerJoinImpl(CNetGamePlayer* player);
		void HandlePlayerLeaveImpl(CNetGamePlayer* player);
	};
}