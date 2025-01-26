#include "core/commands/BoolCommand.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "util/Joaat.hpp"
#include "util/StrToHex.hpp"
#include "util/Protobufs.hpp"

#include <network/netServerMessages.hpp>


namespace YimMenu::Features
{
	BoolCommand _UnlimitedItems{"unlimiteditems", "Unlimited Items", "Never run out of items in your inventory!"};
	BoolCommand _LogServerMessages{"logservermessages", "Log Server Messages", "Log Server Messages"};
}

namespace YimMenu::Hooks
{
	bool Protections::ReceiveServerMessage(void* a1, rage::netRpcReader* reader)
	{
		if (Features::_LogServerMessages.GetState())
		{
			LOG(INFO) << __FUNCTION__ << ": " << reader->GetName() << ": " << BytesToHexStr((unsigned char*)reader->GetContext()->m_Data, reader->GetContext()->m_Size);
		}

		return BaseHook::Get<ReceiveServerMessage, DetourHook<decltype(&ReceiveServerMessage)>>()->Original()(a1, reader);
	}

	bool Protections::SerializeServerRPC(rage::netRpcBuilder* builder, void* a2, const char* message, void* def, void* structure, const char* RPCGuid, void* a7)
	{
		bool ret = BaseHook::Get<SerializeServerRPC, DetourHook<decltype(&SerializeServerRPC)>>()->Original()(builder, a2, message, def, structure, RPCGuid, a7);

		if (Features::_LogServerMessages.GetState())
		{
			LOG(INFO) << __FUNCTION__ << ": " << message << ":";
			PrintProtoBuffer(builder->GetData(), builder->GetSize(), def); // TODO this seems broken
		}

		if (Joaat(message) == "UseItems"_J && Features::_UnlimitedItems.GetState())
			return false;

		return ret;
	}

	void Protections::DeserializeServerMessage(rage::netRpcReaderContext* ctx, void* def, void* structure)
	{
		if (Features::_LogServerMessages.GetState())
		{
			if (!ctx->m_JsonReader)
			{
				LOG(INFO) << __FUNCTION__ " (proto) :: (at) RDR2.exe+0x" << std::hex << std::uppercase << ((__int64)_ReturnAddress() - (__int64)GetModuleHandleA(0));
				PrintProtoBuffer(ctx->m_Data, ctx->m_Size, def);
			}
			else
				LOG(INFO) << __FUNCTION__ << " (json) :: " << reinterpret_cast<char*>(ctx->m_Data);
		}

		BaseHook::Get<DeserializeServerMessage, DetourHook<decltype(&DeserializeServerMessage)>>()->Original()(ctx, def, structure);
	}
}