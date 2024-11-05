#pragma once
#include "Detections.hpp"
#include "core/misc/RateLimiter.hpp"
#include "game/rdr/Player.hpp"
#include <unordered_set>
#include <chrono>

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

		RateLimiter m_VehicleFloodLimit{10s, 10};
		RateLimiter m_LargeVehicleFloodLimit{15s, 5};
		RateLimiter m_TickerMessageRateLimit{5s, 3};

		std::optional<std::uint64_t> m_PeerIdToSpoofTo{};
	};
}