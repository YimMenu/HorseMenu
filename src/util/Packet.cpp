#include "Packet.hpp"

namespace YimMenu
{
	Packet::Packet() :
	    m_Buffer(m_Data, sizeof(m_Data))
	{
	}

	void Packet::Send(uint32_t msg_id)
	{
		Pointers.QueuePacket(Pointers.NetworkPlayerMgr->m_NetConnectionManager, msg_id, 15, m_Data, (m_Buffer.m_CurBit + 7) >> 3, 1, nullptr);
	}

	void Packet::Send(Player player, int connection_id)
	{
		Send(player.GetGamerInfo()->m_PeerId2, connection_id);
	}

	void Packet::Send(int peer_id, int connection_id)
	{
		Pointers.SendPacket(Pointers.NetworkPlayerMgr->m_NetConnectionManager, 0, connection_id, m_Data, (m_Buffer.m_CurBit + 7) >> 3, 0x1000000);
	}
}