#include "Chat.hpp"

namespace YimMenu
{
	static const char* CreateVarString(const char* String)
	{
		return MISC::VAR_STRING(10, (char*)"LITERAL_STRING", String);
	}

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
		/*
		Guid<4> struct1;
		struct1.At<int32_t>(0) = 10000; // Duration

		Guid<3> struct2;
		struct2.At<const char*>(2) = CreateVarString(std::string(sender).append(" - ").append(message).c_str());

		UIFEED::_UI_FEED_POST_FEED_TICKER(struct1.get(), struct2.get(), 1);
		*/
		std::string text = std::string(sender).append(" -  ").append(message);
		Notifications::Show("Chat", text, NotificationType::Info);
	}
}