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
	bool Protections::ReceiveServerMessage(void* a1, rage::ServerMsg* message)
	{
		if (Features::_LogServerMessages.GetState())
		{
			LOG(INFO) << __FUNCTION__ << ": " << message->GetName() << ": "
			          << hexStr((unsigned char*)message->GetMsgData()->data, message->GetMsgData()->size);
		}

		return BaseHook::Get<ReceiveServerMessage, DetourHook<decltype(&ReceiveServerMessage)>>()->Original()(a1, message);
	}

	bool Protections::SerializeServerRPC(rage::ServerRPCSerializer* serializer, void* a2, const char* message, void* def, void* structure, const char* RPCGuid, void* a7)
	{
		bool ret = BaseHook::Get<SerializeServerRPC, DetourHook<decltype(&SerializeServerRPC)>>()->Original()(serializer, a2, message, def, structure, RPCGuid, a7);

		if (Features::_LogServerMessages.GetState())
		{
			LOG(INFO) << __FUNCTION__ << ": " << message << ": "
			          << hexStr((unsigned char*)serializer->GetData(), serializer->GetSize());

			if (RPCGuid)
				LOG(INFO) << "RPC Guid"
				             " = "
				          << RPCGuid;
		}

		if (Joaat(message) == "UseItems"_J && Features::_UnlimitedItems.GetState())
			return false;

		return ret;
	}
}