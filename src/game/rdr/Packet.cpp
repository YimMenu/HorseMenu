#include "Packet.hpp"
#include "game/pointers/Pointers.hpp"

#include <network/CNetGamePlayer.hpp>
#include <network/CNetworkPlayerMgr.hpp>
#include <network/netPlayerMgrBase.hpp>
#include <network/rlGamerInfo.hpp>

namespace YimMenu
{
	Packet::Packet() :
	    m_Buffer(m_Data, sizeof(m_Data))
	{
	}

	void Packet::Send(uint32_t msg_id, int connection_id, bool reliable, bool immediate, bool out_of_frame)
	{
		int flags = 0;
		if (reliable && !out_of_frame)
			flags |= 1;
		if (immediate)
			flags |= 0x1000000;

		if (out_of_frame)
			Pointers.SendPacket(Pointers.NetworkPlayerMgr->m_NetConnectionManager, Pointers.GetPeerAddressByMessageId(Pointers.NetworkPlayerMgr->m_NetConnectionManager, msg_id), connection_id, m_Data, (m_Buffer.m_CurBit + 7) >> 3, flags); // technically also queues the packet, but whatever
		else
			Pointers.QueuePacket(Pointers.NetworkPlayerMgr->m_NetConnectionManager, msg_id, connection_id, m_Data, (m_Buffer.m_CurBit + 7) >> 3, flags, nullptr);
	}

	void Packet::Send(Player player, int connection_id, bool reliable, bool immediate, bool out_of_frame)
	{
		Send(player.GetMessageId(), connection_id, reliable, immediate, out_of_frame);
	}
}