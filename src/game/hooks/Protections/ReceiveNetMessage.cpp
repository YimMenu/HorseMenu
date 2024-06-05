#include "core/commands/BoolCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Player.hpp"

#include <rage/datBitBuffer.hpp>


namespace YimMenu::Features
{
	BoolCommand _LogPackets("logpackets", "Log Packets", "Log Packets");
}

namespace YimMenu
{
	// remove debug logs when done(it doesnt work rn)
	bool GetMessageType(NetMessage& msgType, rage::datBitBuffer& buffer)
	{
		LOG(VERBOSE) << "RUNNING GETMESSAGETYPE";
		try
		{
			int pos;
			int magic;
			int length;
			int extended{};
			if ((buffer.m_FlagBits & 2) != 0 || (buffer.m_FlagBits & 1) == 0 ? (pos = buffer.m_CurBit) : (pos = buffer.m_MaxBit),
			    buffer.m_BitsRead + 15 > pos || !buffer.ReadDword(&magic, 14) || magic != 0x3246 || !buffer.ReadDword(&extended, 1))
			{
				msgType = NetMessage::MsgInvalid;
				return false;
			}
			length = extended ? 16 : 8;
			if ((buffer.m_FlagBits & 1) != 0 ? (pos = buffer.m_MaxBit) : (pos = buffer.m_CurBit),
			    length + buffer.m_BitsRead > pos || !buffer.ReadDword((int*)&msgType, length))
			{
				LOG(VERBOSE) << "Failed SECOND";
				return false;
			}
			else
			{
				// debug notif
				Notifications::Show("ReceiveNetMessage", std::string("Passed through with a hash of").append(std::to_string((uint32_t)msgType)));
				return true;
			}
		}
		catch (std::exception& e)
		{
			LOG(VERBOSE) << "GetMessageType failed with exception: " << e.what();
			return false;
		}
	}
}

namespace YimMenu::Hooks
{

	bool Protections::ReceiveNetMessage(void* netConnectionManager, void* a2, rage::InFrame* frame)
	{
		/*
		if (frame->get_event_type() != rage::InFrame::EventType::FrameReceived)
		{
			LOG(VERBOSE) << (int)frame->get_event_type();
			return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()
			    ->Original()(netConnectionManager, a2, frame);
		}

		if (frame->data == nullptr || frame->length == 0)
		{
			LOG(VERBOSE) << "RETURNING ORIGINAL DUE TO NULLPTR OR NO LENGTH";
			return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()
			    ->Original()(netConnectionManager, a2, frame);
		}

		LOG(VERBOSE) << "FRAME INFO: "
		             << "DATA = " << frame->data << " LEN = " << frame->length;

		rage::datBitBuffer buffer(frame->data, frame->length);
		buffer.m_FlagBits |= 1;

		NetMessage msg_type;

		LOG(VERBOSE) << "Getting Message Type";
		if (!GetMessageType(msg_type, buffer))
		{
			return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()
			    ->Original()(netConnectionManager, a2, frame);
		}

		LOG(VERBOSE) << "MADE IT PAST GETMSGTYPE";
		switch (msg_type)
		{
		case NetMessage::MsgScriptMigrateHost: LOG(VERBOSE) << "MIGRATE SCRIPT HOST"; return true;
		}

		if (Features::_LogPackets.GetState())
		{
			LOG(VERBOSE) << "RECIEVED PACKED: "
			             << "TYPE = "
			             << " " << (uint32_t)msg_type << "LENGTH = "
			             << " " << frame->length;
		}
		*/

		//LOG(INFO) << "CALLED, RETURNING ORIGINAL";
		return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()->Original()(netConnectionManager, a2, frame);
	}
}