#include "core/commands/BoolCommand.hpp"
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
	bool GetMessageType(NetMessage& msgType, rage::datBitBuffer& buffer)
	{
		uint32_t pos;
		uint32_t magic;
		uint32_t length;
		uint32_t extended{};
		if ((buffer.m_FlagBits & 2) != 0 || (buffer.m_FlagBits & 1) == 0 ? (pos = buffer.m_CurBit) : (pos = buffer.m_MaxBit),
		    buffer.m_BitsRead + 15 > pos || !buffer.ReadDword((int*)&magic, 14) || magic != 0x3246 || !buffer.ReadDword((int*)&extended, 1))
		{
			msgType = NetMessage::MsgInvalid;
			return false;
		}
		length = extended ? 16 : 8;
		if ((buffer.m_FlagBits & 1) == 0 ? (pos = buffer.m_CurBit) : (pos = buffer.m_MaxBit),
		    length + buffer.m_BitsRead > pos && !buffer.ReadDword((int*)&msgType, length))
			return false;
		else
			return true;
	}
}

namespace YimMenu::Hooks
{
	// fix this, it crashes on load. likely a inframe issue
	bool Protections::ReceiveNetMessage(void* netConnectionManager, void* a2, rage::InFrame* frame)
	{
		/*
		if (frame->data == nullptr || frame->length == 0)
		{
			LOG(VERBOSE) << "RETURNING ORIGINAL DUE TO NULLPTR OR NO LENGTH";
			return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()
			    ->Original()(netConnectionManager, a2, frame);
		}

		LOG(VERBOSE) << "TRYING TO BUFF";
		rage::datBitBuffer buffer(frame->data, frame->length);
		buffer.m_FlagBits = 1;

		NetMessage msg_type;

		if (!GetMessageType(msg_type, buffer))
			return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()
			    ->Original()(netConnectionManager, a2, frame);

		switch (msg_type)
		{
		case NetMessage::MsgScriptMigrateHost: return true;
		}

		if (Features::_LogPackets.GetState())
		{
			LOG(VERBOSE) << "RECIEVED PACKED: "
			             << "TYPE = "
			             << " " << uintptr_t(uint32_t(msg_type)) << "LENGTH = "
			             << " " << frame->length;
		}
		*/

		LOG(INFO) << "CALLED, RETURNING ORIGINAL";


		return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()->Original()(netConnectionManager, a2, frame);
	}
}