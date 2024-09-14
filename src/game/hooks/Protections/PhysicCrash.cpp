#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"


namespace YimMenu::Hooks
{
	int64_t Protections::PhysicCrash(int64_t a1, unsigned int a2, int* a3)
	{
		unsigned int v11; // esi
		int64_t v9;       // rbx

		v9 = *(uint64_t*)(a1 + 40) + 80i64 * a2;
		if (v9)
		{
			v11 = *(uint16_t*)(v9 + 72);
			if (v11 > 1000) 
			{
				return 0;
			}
		}

		return BaseHook::Get<Protections::PhysicCrash, DetourHook<decltype(&Protections::PhysicCrash)>>()->Original()(a1, a2, a3);
	}
}