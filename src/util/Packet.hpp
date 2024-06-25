#pragma once
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Player.hpp"

#include <network/CNetGamePlayer.hpp>
#include <network/CNetworkPlayerMgr.hpp>
#include <network/netPlayerMgrBase.hpp>
#include <network/rlGamerInfo.hpp>
#include <rage/datBitBuffer.hpp>


namespace YimMenu
{
	class Packet
	{
	public:
		char m_Data[0x400]{};
		rage::datBitBuffer m_Buffer;

		Packet();
		void Send(uint32_t msg_id);
		void Send(Player player, int connection_id);
		void Send(int peer_id, int connection_id);

		inline operator rage::datBitBuffer&()
		{
			return m_Buffer;
		}

		template<typename T>
		inline void write(T data, int length)
		{
			m_Buffer.Write<T>(data, length);
		}

		inline void write_message(eNetMessageType message)
		{
			write<int>(0x3246, 14);
			if ((int)message > 0xFF)
			{
				write<bool>(true, 1);
				write<eNetMessageType>(message, 16);
			}
			else
			{
				write<bool>(false, 1);
				write<eNetMessageType>(message, 8);
			}
		}

		inline int get_data_length(rage::datBitBuffer& buffer)
		{
			int leftoverBit = (buffer.m_CurBit % 8) ? 1 : 0;
			return (buffer.m_CurBit / 8) + leftoverBit;
		}

		inline void write_peer_id(uint64_t peer_id)
		{
			char b[8];
			rage::datBitBuffer buf(b, 8);
			buf.WriteQword(peer_id, 64);
			m_Buffer.Write(b, 8 * get_data_length(buf));
		}
	};

}