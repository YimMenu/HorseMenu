#include "core/commands/BoolCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Player.hpp"

#include <rage/datBitBuffer.hpp>


namespace YimMenu::Features
{
	BoolCommand _LogPackets("logpackets", "Log Packets", "Log Packets");
}

namespace YimMenu::Hooks
{
	bool Protections::ReceiveNetMessage(void* netConnectionManager, void* a2, rage::InFrame* frame)
	{
		if (frame->get_event_type() != rage::InFrame::EventType::FrameReceived)
		{
			return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()
			    ->Original()(netConnectionManager, a2, frame);
		}

		if (frame->data == nullptr || frame->length == 0)
		{
			return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()
			    ->Original()(netConnectionManager, a2, frame);
		}

		rage::datBitBuffer buffer(frame->data, frame->length, true);
		buffer.m_FlagBits |= 1u;

		NetMessage msg_type;

		if (!Pointers.GetMessageType((uint32_t*)&msg_type, buffer))
		{
			return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()
			    ->Original()(netConnectionManager, a2, frame);
		}

		if (Features::_LogPackets.GetState())
		{
			LOG(VERBOSE) << "RECIEVED PACKED: "
			             << "TYPE = "
			             << " " << (uint32_t)msg_type << "LENGTH = "
			             << " " << frame->length;
		}

		switch (msg_type)
		{
		case NetMessage::MsgScriptMigrateHost:
		{
			LOG(VERBOSE) << "MIGRATE SCRIPT HOST";
			return true;
		}
		}

		return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()->Original()(netConnectionManager, a2, frame);
	}
}