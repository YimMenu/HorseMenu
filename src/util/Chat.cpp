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
		msg.m_Buffer.Write<const char*>(message.c_str(), 256);
		SerializeGamerHandle(self.GetGamerInfo()->m_GamerHandle, msg.m_Buffer);

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
		Guid<4> struct1;
		struct1[0] = 10000; // Duration

		Guid<4> struct2;
		struct2.At<const char*>(1) = CreateVarString(message.c_str());

		UIFEED::_UI_FEED_POST_FEED_TICKER(struct1.get(), struct2.get(), true);
	}

	void SerializeGamerHandle(rage::rlGamerHandle& hnd, rage::datBitBuffer& buffer)
	{
		buffer.Write<uint8_t>(hnd.m_platform, sizeof(hnd.m_platform) * 8);
		if (hnd.m_platform == 3)
		{
			WriteRockstarId(hnd.m_rockstar_id, buffer);
			buffer.Write<uint8_t>(hnd.unk_0009, sizeof(hnd.unk_0009) * 8);
		}
	}

	void DeserializeGamerHandle(rage::rlGamerHandle& hnd, rage::datBitBuffer& buffer)
	{
		if ((hnd.m_platform = buffer.Read<uint8_t>(sizeof(hnd.m_platform) * 8)) != 3)
			return;
		ReadRockstarId(&hnd.m_rockstar_id, buffer);
		hnd.unk_0009 = buffer.Read<uint8_t>(sizeof(hnd.unk_0009) * 8);
	}

	bool ReadRockstarId(uint64_t* rockstarId, rage::datBitBuffer& buffer)
	{
		return buffer.ReadQword(rockstarId, sizeof(rockstarId) * 8);
	}

	bool WriteRockstarId(uint64_t rockstarId, rage::datBitBuffer& buffer)
	{
		return buffer.WriteQword(rockstarId, sizeof(rockstarId) * 8);
	}
}