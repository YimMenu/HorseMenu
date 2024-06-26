#include "core/commands/BoolCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/features/Features.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Player.hpp"
#include "util/Chat.hpp"

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
			LOG(VERBOSE) << "RECEIVED PACKET: "
			             << "TYPE = "
			             << " " << (uint32_t)msg_type << "LENGTH = "
			             << " " << frame->m_Length;
		}

		switch (msg_type)
		{
		case eNetMessageType::CMsgTextMsg:
		{
			char message[256];
			rage::rlGamerHandle handle{};
			const char* data = buffer.Read<const char*>(sizeof(message));
			memcpy(message, data, sizeof(message));
			DeserializeGamerHandle(handle, buffer);

			if (handle.m_rockstar_id != 0)
			{
				RenderChatMessage(message, Player(Self::Id).GetName()); // Need to get the real senders name
				break;
			}
		}
		}

		return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()->Original()(netConnectionManager, a2, frame);
	}
}