#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "core/commands/BoolCommand.hpp"

namespace YimMenu::Features
{
	BoolCommand _UseRelayConnections("userelaycxns", "Use Relay Connections", "Blocks certain kick types. Note that this may cause connection problems and does not hide your IP address");
}

namespace YimMenu::Hooks
{
	constexpr uint8_t g_JmpPatch[] = {0xE9, 0x83, 0x00, 0x00, 0x00, 0x90};
	constexpr uint8_t g_JmpRestore[] = {0x0F, 0x84, 0x82, 0x00, 0x00, 0x00};

	void Protections::DecideConnectionMethod(void* _this, void* a2)
	{
		if (Features::_UseRelayConnections.GetState())
		{
			*Pointers.DecideConnectionMethodDefVal = 3;
			memcpy(Pointers.DecideConnectionMethodJmp, g_JmpPatch, sizeof(g_JmpPatch));
		}
		BaseHook::Get<Protections::DecideConnectionMethod, DetourHook<decltype(&Protections::DecideConnectionMethod)>>()->Original()(_this, a2);
		if (Features::_UseRelayConnections.GetState())
		{
			memcpy(Pointers.DecideConnectionMethodJmp, g_JmpRestore, sizeof(g_JmpRestore));
			*Pointers.DecideConnectionMethodDefVal = 1;
		}
	}
}