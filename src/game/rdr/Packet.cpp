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

	void Packet::Send(uint32_t msg_id, int connection_id, bool reliable, bool immediate)
	{
		int flags = 0;
		if (reliable)
			flags |= 1;
		if (immediate)
			flags |= 0x1000000;
		Pointers.QueuePacket(Pointers.NetworkPlayerMgr->m_NetConnectionManager, msg_id, connection_id, m_Data, (m_Buffer.m_CurBit + 7) >> 3, flags, nullptr);
	}

	void Packet::Send(Player player, int connection_id, bool reliable, bool immediate)
	{
		Send(player.GetMessageId(), connection_id, reliable, immediate);
	}
}