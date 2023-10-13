#pragma once
#include "game/rdr/Player.hpp"

namespace YimMenu
{
	class Protections
	{
		Player m_SyncingPlayer{nullptr};

		static Protections& GetInstance()
		{
			static Protections Instance;
			return Instance;
		}
	public:
		static Player& GetSyncingPlayer()
		{
			return GetInstance().m_SyncingPlayer;
		}

		static void SetSyncingPlayer(Player player)
		{
			GetInstance().m_SyncingPlayer = player;
		}
	};
}