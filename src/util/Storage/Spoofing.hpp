#pragma once
#include "game/rdr/Player.hpp"

#include <network/netPeerAddress.hpp>
#include <string>
#include <unordered_map>
#include <network/rlGamerHandle.hpp>

namespace YimMenu
{
	struct Spoofing
	{
		// TODO: Move this stuff
		bool spoofName;
		std::string spoofedName = "Terminus";
		bool spoofIP;
		std::array<int, 4> spoofedIP = {127, 0, 0, 1};
		bool spoofRID;
		int64_t spoofedRID = 696969;

		struct RemotePlayerTeleport
		{
			std::uint16_t m_PlayerNetId;
			rage::fvector3 m_Position;
		};

		std::unordered_map<uint16_t, RemotePlayerTeleport> m_RemotePlayerTeleports;
	};
	inline YimMenu::Spoofing g_SpoofingStorage;
}