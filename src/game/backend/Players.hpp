#pragma once
#include "game/rdr/Player.hpp"

namespace YimMenu
{
	class Players
	{
		std::unordered_map<uint8_t, Player> m_Players{};
		Player m_SelectedPlayer = Player((uint8_t)0);

	public:
		static void Tick()
		{
			GetInstance().TickImpl();
		}

		static Player GetSelected()
		{
			return GetInstance().m_SelectedPlayer;
		}

		static void SetSelected(uint8_t idx)
		{
			GetInstance().m_SelectedPlayer = Player(idx);
		}

		static std::unordered_map<uint8_t, Player>& GetPlayers()
		{
			return GetInstance().m_Players;
		}

	private:
		static Players& GetInstance()
		{
			static Players Instance;
			return Instance;
		}

		void TickImpl();
	};
}