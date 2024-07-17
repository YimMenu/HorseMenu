#pragma once
#include "core/misc/RateLimiter.hpp"

namespace YimMenu
{
	class PlayerData
	{
	public:
		bool m_UseSessionSplitKick{};
		RateLimiter m_TickerMessageRateLimit{5s, 3};
	};
}