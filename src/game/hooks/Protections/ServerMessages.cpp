#include "core/commands/BoolCommand.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "util/Joaat.hpp"
#include "util/StrToHex.hpp"

#include <network/netServerMessages.hpp>


namespace YimMenu::Features
{
	BoolCommand _UnlimitedItems{"unlimiteditems", "Unlimited Items", "Never run out of items in your inventory!"};
	BoolCommand _LogServerMessages{"logservermessages", "Log Server Messages", "Log Server Messages"};
}

namespace YimMenu::Hooks
{
	bool Protections::ReceiveServerMessage(void* a1, rage::ServerMsg* a2)
	{
		if (Features::_LogServerMessages.GetState())
		{
			LOG(INFO) << __FUNCTION__ << ": " << a2->GetName() << ": "
			          << hexStr((unsigned char*)a2->GetMsgData()->data, a2->GetMsgData()->size);
		}
		return BaseHook::Get<ReceiveServerMessage, DetourHook<decltype(&ReceiveServerMessage)>>()->Original()(a1, a2);
	}

	bool Protections::SerializeServerRPC(rage::ServerRPCSerializer* ser, void* a2, const char* message, void* def, void* structure, const char* rpc_guid, void* a7)
	{
		bool ret = BaseHook::Get<SerializeServerRPC, DetourHook<decltype(&SerializeServerRPC)>>()->Original()(ser, a2, message, def, structure, rpc_guid, a7);
		if (Features::_LogServerMessages.GetState())
		{
			LOG(INFO) << __FUNCTION__ << ": " << message << ": " << hexStr((unsigned char*)ser->GetData(), ser->GetSize());
			if (rpc_guid)
				LOG(INFO) << "RPC Guid"
				             " = "
				          << rpc_guid;
		}
		if (Joaat(message) == "UseItems"_J && Features::_UnlimitedItems.GetState())
			return false;
		return ret;
	}
}