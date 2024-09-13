#pragma once
#include "util/Joaat.hpp"

namespace YimMenu
{
	enum class Detection : std::uint32_t
	{
		TRIED_CRASH_PLAYER   = "TRIED_CRASH_PLAYER"_J,
		TRIED_KICK_PLAYER    = "TRIED_KICK_PLAYER"_J,
		MODDER_EVENTS        = "MODDER_EVENTS"_J,
		TRIED_ATTACH         = "TRIED_ATTACH"_J,
		REMOTE_TELEPORT      = "REMOTE_TELEPORT"_J,
		INVALID_PLAYER_MODEL = "INVALID_PLAYER_MODEL"_J,
		SPOOFING_ROCKSTAR_ID = "SPOOFING_ROCKSTAR_ID"_J,
		SPOOFING_IP          = "SPOOFING_IP"_J,
		SPOOFING_NAME        = "SPOOFING_NAME"_J,
		SPOOFING_VC          = "SPOOFING_VC"_J,
		USED_SPECTATE        = "USED_SPECTATE"_J,
	};

	inline const std::unordered_map<Detection, std::string> g_DetectionDescs = {
	    {Detection::TRIED_CRASH_PLAYER, "Tried to crash you"},
	    {Detection::TRIED_KICK_PLAYER, "Tried to kick you"},
	    {Detection::MODDER_EVENTS, "Sent modder events"},
	    {Detection::TRIED_ATTACH, "Tried to attach to you"},
	    {Detection::REMOTE_TELEPORT, "Tried to teleport you"},
	    {Detection::INVALID_PLAYER_MODEL, "Used an invalid player model"},
	    {Detection::SPOOFING_ROCKSTAR_ID, "Has spoofed their Rockstar ID"},
	    {Detection::SPOOFING_IP, "Has spoofed their IP"},
	    {Detection::SPOOFING_NAME, "Has spoofed their name"},
	    {Detection::SPOOFING_VC, "Has spoofed voice chat"},
	    {Detection::USED_SPECTATE, "Used spectate"},
	};
}