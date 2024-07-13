#include "core/commands/BoolCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/backend/Players.hpp"
#include "game/features/Features.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Player.hpp"
#include "util/Chat.hpp"
#include "util/Helpers.hpp"

#include <array>
#include <network/InFrame.hpp>
#include <network/rlGamerHandle.hpp>
#include <rage/datBitBuffer.hpp>


namespace YimMenu::Features
{
	BoolCommand _LogPackets("logpackets", "Log Packets", "Log Packets");
}

namespace YimMenu::Hooks
{
	static bool GetMessageType(eNetMessageType& type, rage::datBitBuffer& buffer)
	{
		if (buffer.Read<int>(14) != '2F')
			return false;
		bool extended = buffer.Read<bool>(1);
		type          = buffer.Read<eNetMessageType>(extended ? 16 : 8);
		return true;
	}

	bool Protections::ReceiveNetMessage(void* netConnectionManager, void* a2, rage::InFrame* frame)
	{
		if (frame->GetEventType() != rage::InFrame::EventType::FrameReceived)
		{
			return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()
			    ->Original()(netConnectionManager, a2, frame);
		}

		if (frame->m_Data == nullptr || frame->m_Length == 0)
		{
			return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()
			    ->Original()(netConnectionManager, a2, frame);
		}

		rage::datBitBuffer buffer(frame->m_Data, frame->m_Length);
		buffer.m_FlagBits |= 1u;

		eNetMessageType msg_type;

		if (!GetMessageType(msg_type, buffer))
		{
			return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()
			    ->Original()(netConnectionManager, a2, frame);
		}

		if (Features::_LogPackets.GetState())
		{
			static constexpr const auto unloggables = std::to_array({eNetMessageType::MsgCloneSync, eNetMessageType::MsgPackedCloneSyncACKs, eNetMessageType::MsgPackedEvents, eNetMessageType::MsgPackedReliables, eNetMessageType::MsgPackedEventReliablesMsgs, eNetMessageType::MsgNetArrayMgrUpdate, eNetMessageType::MsgNetArrayMgrUpdateAck});
			if (std::find(unloggables.begin(), unloggables.end(), msg_type) != unloggables.end())
			{
				LOG(VERBOSE) << "RECEIVED PACKET: "
				             << "TYPE = "
				             << " " << HEX((uint32_t)msg_type) << "LENGTH = "
				             << " " << frame->m_Length;
			}
		}

		switch (msg_type)
		{
		case eNetMessageType::MsgTextChat:
		{
			char message[256];
			uint64_t senderHostToken;
			Helpers::ReadString(message, sizeof(message) * 8, &buffer);
			senderHostToken = buffer.Read<uint64_t>(64);
			buffer.Read<bool>(1);

			Player sender = Players::GetByHostToken(senderHostToken);

			if (senderHostToken != 0)
			{
				RenderChatMessage(message, sender.GetName());
				break;
			}
			else
			{
				LOG(VERBOSE) << "Received chat message with null host token!";
			}
		}
		case (eNetMessageType)0x3A: // Before Merge Replace with actual message in enum
		{
			return true;
		}
		}

		return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()->Original()(netConnectionManager, a2, frame);
	}
}