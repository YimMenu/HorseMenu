#include "core/commands/BoolCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Player.hpp"

#include <network/InFrame.hpp>
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

		return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()->Original()(netConnectionManager, a2, frame);
	}
}