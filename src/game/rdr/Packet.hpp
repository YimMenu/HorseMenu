#pragma once
#include "game/rdr/Enums.hpp"
#include "game/rdr/Player.hpp"
#include <rage/datBitBuffer.hpp>


namespace YimMenu
{
	class Packet
	{
		char m_Data[0x400]{};
		rage::datBitBuffer m_Buffer;
	public:

		Packet();
		void Send(uint32_t msg_id, int connection_id, bool reliable = true, bool immediate = false, bool out_of_frame = false);
		void Send(Player player, int connection_id, bool reliable = true, bool immediate = false, bool out_of_frame = false);

		inline operator rage::datBitBuffer&()
		{
			return m_Buffer;
		}

		inline rage::datBitBuffer& GetBuffer()
		{
			return m_Buffer;
		}

		inline void WriteMessageHeader(NetMessageType message)
		{
			GetBuffer().Write<int>(0x3246, 14);
			if ((int)message > 0xFF)
			{
				GetBuffer().Write<bool>(true, 1);
				GetBuffer().Write<NetMessageType>(message, 16);
			}
			else
			{
				GetBuffer().Write<bool>(false, 1);
				GetBuffer().Write<NetMessageType>(message, 8);
			}
		}
	};

}