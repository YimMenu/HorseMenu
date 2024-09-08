#include "AsyncLogger/Logger.hpp"
#include "core/commands/BoolCommand.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/backend/Players.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "network/rlGamerInfo.hpp"
#include "util/StrToHex.hpp"

#include <array>
#include <rage/datBitBuffer.hpp>

namespace YimMenu::Features
{
	BoolCommand _LogForwardPackets("logforwardpackets", "Log Forward Packets", "Log Forward Packets");
	BoolCommand _LogTerminusPackets("logterminuspackets", "Log Terminus Packets", "Log Terminus Packets");
	BoolCommand _LogPeerRelayPackets("logpeerrelaypackets", "Log Peer Relay Packets", "Log Peer Relay Packets");
	BoolCommand _LogUnpackedPackets("logunpackedpackets", "Log Unpacked Packets", "Log Unpacked Packets");
	BoolCommand _LogEndpointUpdates("logendpointupdates", "Log Endpoint Updates", "Log net connection endpoint address changes");
}

namespace YimMenu::Hooks
{
	uint32_t GetFlags(void* buffer, int sz)
	{
		auto newBuffer = rage::datBitBuffer(buffer, sz);
		newBuffer.m_FlagBits |= 1;

		newBuffer.Seek(16, true);
		uint32_t flags = newBuffer.Read<uint32_t>(8);
		return flags;
	}

	bool IsP2pForward(void* buffer, int sz)
	{
		auto flags = GetFlags(buffer, sz);
		if ((flags & 1) == 0 || *((char*)buffer + 4) != 2)
			return 0;
		return true;
	}

	bool IsP2pTerminus(void* buffer, int sz)
	{
		auto flags = GetFlags(buffer, sz);
		if ((flags & 1) == 0 || *((char*)buffer + 4) != 3)
			return 0;
		return true;
	}

	bool Protections::HandlePeerRelayPacket(__int64 _this, __int64 netSockFrom, void* buffer, unsigned int sizeOfBuffer)
	{
		bool ret = BaseHook::Get<Protections::HandlePeerRelayPacket, DetourHook<decltype(&Protections::HandlePeerRelayPacket)>>()
		               ->Original()(_this, netSockFrom, buffer, sizeOfBuffer);

		if (Features::_LogForwardPackets.GetState() && IsP2pForward(buffer, sizeOfBuffer))
		{
			auto packet = (unsigned char*)buffer;
			LOG(INFO) << "P2P forward packet: " << BytesToHexStr(packet, sizeOfBuffer) << " of size " << sizeOfBuffer;
		}
		else if (Features::_LogTerminusPackets.GetState() && IsP2pTerminus(buffer, sizeOfBuffer))
		{
			auto packet = (unsigned char*)buffer;
			LOG(INFO) << "P2P terminus packet: " << BytesToHexStr(packet, sizeOfBuffer) << " of size " << sizeOfBuffer;
		}

		return ret;
	}

	void Protections::UnpackPacket(__int64 _this, netAddress* sender, void* buffer, unsigned int sizeOfBuffer, bool allowRelayOverride)
	{
		BaseHook::Get<Protections::UnpackPacket, DetourHook<decltype(&Protections::UnpackPacket)>>()->Original()(_this, sender, buffer, sizeOfBuffer, allowRelayOverride);

		if (Features::_LogUnpackedPackets.GetState())
		{
			auto ip = std::string(std::to_string(sender->m_field1))
			              .append("." + std::to_string(sender->m_field2))
			              .append("." + std::to_string(sender->m_field3))
			              .append("." + std::to_string(sender->m_field4));

			auto packet = (unsigned char*)buffer;
			LOG(INFO) << "Unpacked Packet: " << BytesToHexStr(packet, sizeOfBuffer) << " Of Size " << sizeOfBuffer << " From: " << ip;
		}
	}

	void Protections::UpdateEndpointAddress(__int64 _this, void* peerID, netAddress* addrOrig, netAddress* relayAddrOrig)
	{
		BaseHook::Get<Protections::UpdateEndpointAddress, DetourHook<decltype(&Protections::UpdateEndpointAddress)>>()->Original()(_this, peerID, addrOrig, relayAddrOrig);

		if (Features::_LogEndpointUpdates.GetState())
		{
			auto address = std::string(std::to_string(addrOrig->m_field1))
			                       .append("." + std::to_string(addrOrig->m_field2))
			                       .append("." + std::to_string(addrOrig->m_field3))
			                       .append("." + std::to_string(addrOrig->m_field4));

			auto relay = std::string(std::to_string(relayAddrOrig->m_field1))
			                     .append("." + std::to_string(relayAddrOrig->m_field2))
			                     .append("." + std::to_string(relayAddrOrig->m_field3))
			                     .append("." + std::to_string(relayAddrOrig->m_field4));

			Player pl = nullptr;

			for (auto& [_, player] : YimMenu::Players::GetPlayers())
				if (player.GetGamerInfo()->m_PeerId == *(uint64_t*)peerID)
					pl = player;

			if (pl)
				LOGF(INFO, "rage::netConnectionManager::UpdateEndpointAddress for {} ({:X}) to {} (relay {})", pl.GetName(), *(uint64_t*)peerID, address, relay);
			else
				LOGF(INFO, "rage::netConnectionManager::UpdateEndpointAddress for {:X} to {} (relay {})", *(uint64_t*)peerID, address, relay);
		}
	}
}