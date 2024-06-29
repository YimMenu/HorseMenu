#include "Chat.hpp"

namespace YimMenu
{
	void SendChatMessage(const std::string& message)
	{
		if (!*Pointers.IsSessionStarted)
			return;

		Player self = Player(Self::Id);
		Packet msg{};
		msg.write_message(eNetMessageType::MsgTextChat);
		Helpers::WriteBufferString(message.c_str(), 256, &msg.m_Buffer);
		msg.m_Buffer.Write<uint64_t>(self.GetRID(), 64);

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