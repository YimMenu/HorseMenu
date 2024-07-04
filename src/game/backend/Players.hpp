#pragma once
#include "game/rdr/Player.hpp"
#include "PlayerData.hpp"

namespace YimMenu
{
	class Players
	{
		std::unordered_map<uint8_t, Player> m_Players{};
		std::unordered_map<uint8_t, PlayerData> m_PlayerDatas{};
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

		static Player GetByRID(uint64_t rid)
		{
			return GetInstance().GetByRIDImpl(rid);
		}

		static Player GetByHostToken(uint64_t token)
		{
			return GetInstance().GetByHostTokenImpl(token);
		}

		static PlayerData& GetPlayerData(uint8_t idx)
		{
			return GetInstance().m_PlayerDatas[idx];
		}

	private:
		static Players& GetInstance()
		{
			static Players Instance;
			return Instance;
		}

		void TickImpl();
		Player GetByRIDImpl(uint64_t rid);
		Player GetByHostTokenImpl(uint64_t token);
	};
}