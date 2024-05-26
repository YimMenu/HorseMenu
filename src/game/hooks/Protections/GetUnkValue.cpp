#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"


namespace YimMenu::Hooks
{
	// there seem to be some false positives with this
	int Protections::GetUnkValue(int64_t* a1, unsigned int* a2)
	{
		if (auto ptr = *(uint64_t*)(a1 + 0xC10); !ptr)
		{
			Notifications::Show("Protections", "Blocked Fortitude's Nemesis Streaming Crash", NotificationType::Warning);
			return 0;
		}

		return BaseHook::Get<Protections::GetUnkValue, DetourHook<decltype(&Protections::GetUnkValue)>>()->Original()(a1, a2);
	}
}