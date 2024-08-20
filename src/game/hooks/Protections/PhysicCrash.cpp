#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"


namespace YimMenu::Hooks
{
	__int64 Protections::PhysicCrash(__int64 a1, unsigned int a2, int* a3)
	{
		unsigned int v11; // esi
		__int64 v9;       // rbx

		v9 = *(unsigned long long*)(a1 + 40) + 80i64 * a2;
		if (v9)
		{
			v11 = *(unsigned __int16*)(v9 + 72);
			if (v11 > 1000) 
			{
				return 0;
			}
		}

		return BaseHook::Get<Protections::PhysicCrash, DetourHook<decltype(&Protections::PhysicCrash)>>()->Original()(a1, a2, a3);
	}
}