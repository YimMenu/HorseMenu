#pragma once
#include "Detections.hpp"
#include <unordered_set>

namespace YimMenu
{
	class PlayerData
	{
	public:
		std::unordered_set<Detection> m_Detections{};
		bool m_UseSessionSplitKick{};
	};
}