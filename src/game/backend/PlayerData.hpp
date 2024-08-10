#pragma once
#include "Detections.hpp"
#include "game/rdr/Player.hpp"
#include <unordered_set>

namespace YimMenu
{
	class PlayerData
	{
	public:
		std::unordered_set<Detection> m_Detections{};
		Player m_SpectatingPlayer{nullptr};
		bool m_UseSessionSplitKick{};
		bool m_BlockExplosions{};
		bool m_BlockParticles{};
		bool m_GhostMode{};
	};
}