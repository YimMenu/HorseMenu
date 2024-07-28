#pragma once
#include "util/Joaat.hpp"
#include <unordered_set>

namespace YimMenu
{
	enum class DetectionType : std::uint32_t
	{
		TRIED_CRASH_PLAYER   = "TRIED_CRASH_PLAYER"_J,
		TRIED_KICK_PLAYER    = "TRIED_KICK_PLAYER"_J,
		MODDER_EVENTS   = "MODDER_EVENTS"_J,
		TRIED_ATTACH         = "TRIED_ATTACH"_J,
		REMOTE_TELEPORT      = "REMOTE_TELEPORT"_J,
		INVALID_PLAYER_MODEL = "INVALID_PLAYER_MODEL"_J,
	};

	std::unordered_map<DetectionType, std::string> g_DetectionDescs = {
	    {DetectionType::TRIED_CRASH_PLAYER, "Tried to crash you!"},
	    {DetectionType::TRIED_KICK_PLAYER, "Tried to kick you!"},
	    {DetectionType::MODDER_EVENTS, "Tried to call a native!"},
	    {DetectionType::TRIED_ATTACH, "Tried to attach to you!"},
	    {DetectionType::REMOTE_TELEPORT, "Tried to teleport to you!"},
	    {DetectionType::INVALID_PLAYER_MODEL, "Tried to use an invalid player model!"},
	};

	struct PersistentPlayerData
	{
		uint64_t Rid;
		std::string Name;
		bool BlockJoin = false;
		bool Trusted   = false;
		std::unordered_set<int> Detections;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(PersistentPlayerData, Rid, Name, BlockJoin, Trusted, Detections);
	};
}