#include "Network.hpp"
#include "Packet.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/Self.hpp"
#include "util/Helpers.hpp" /// TODO WHY DOES THIS STILL EXIST?!

#include <network/CNetObjectMgr.hpp>

namespace YimMenu::Network
{
	static int GetNextTokenValue(int prev_token)
	{
		for (int i = 0; i < 0x1F; i++)
		{
			if ((i << 27) - (prev_token << 27) > 0)
				return i;
		}

		return 0;
	}

	void ForceRemoveNetworkEntity(std::uint16_t net_id, int ownership_token, bool delete_locally)
	{
		auto mapped_id = (*Pointers.ObjectIdMap)[net_id];

		char buf[0x200]{};
		rage::datBitBuffer remove_buf(buf, sizeof(buf));
		int msgs_written = 0;

		if (ownership_token != -1)
		{
			remove_buf.Write<std::uint16_t>(mapped_id, 13);
			remove_buf.Write<int>(GetNextTokenValue(ownership_token), 5);
			msgs_written++;
		}
		else
		{
			// try all tokens if we don't know it
			for (int i = 0; i < 0x1F; i++)
			{
				remove_buf.Write<std::uint16_t>(mapped_id, 13);
				remove_buf.Write<int>(i, 5);
				remove_buf.Write<int>(false, 1);
				msgs_written++;
			}
		}

		Packet pack;
		pack.WriteMessageHeader(NetMessageType::PACKED_RELIABLES);
		pack.GetBuffer().Write<int>(4, 4); // remove
		pack.GetBuffer().Write(msgs_written, 5);
		pack.GetBuffer().Write(remove_buf.m_BitsRead, 13);
		Helpers::WriteArray(&buf, remove_buf.m_BitsRead, &pack.GetBuffer());
	
		for (auto& [_, player] : Players::GetPlayers())
		{
			if (player != Self::GetPlayer())
			{
				pack.Send(player, 7);
			}
		}

		if (delete_locally)
			if (auto object = Pointers.GetNetObjectById(net_id))
				(*Pointers.NetworkObjectMgr)->UnregisterNetworkObject(object, 8, true, true);
	}
}