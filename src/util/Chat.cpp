#include "Chat.hpp"
#include "Packet.hpp"
#include "game/frontend/ChatDisplay.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/Self.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Player.hpp"
#include "util/Helpers.hpp"

#include <rage/Guid.hpp>
#include <rage/datBitBuffer.hpp>

namespace YimMenu
{
	void SendChatMessage(const std::string& message)
	{
		if (!*Pointers.IsSessionStarted)
			return;

		auto self = Self::GetPlayer();
		Packet msg{};
		msg.write_message(eNetMessageType::MsgTextChat);
		Helpers::WriteBufferString(message.c_str(), 256, &msg.m_Buffer);
		msg.m_Buffer.Write<uint64_t>(self.GetGamerInfo()->m_HostToken, 64);
		msg.m_Buffer.Write<bool>(false, 1);

		for (auto& player : Players::GetPlayers())
		{
			if (player.second.IsValid())
			{
				msg.Send(player.second.GetMessageId());
			}
		}

		RenderChatMessage(message, self.GetName());
	}

	void RenderChatMessage(const std::string& message, const std::string& sender)
	{
		ChatDisplay::Show(sender, message);
	}
}