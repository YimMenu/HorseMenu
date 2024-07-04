#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "game/backend/Players.hpp"
#include "game/pointers/Pointers.hpp"


namespace YimMenu::Hooks
{
	unsigned int Toxic::BroadcastNetArray(void* array, CNetGamePlayer* target, rage::datBitBuffer* buffer, std::uint16_t counter, std::uint32_t* elem_start)
	{
		auto data = *(void**)(((__int64)array)+0x1D8);

		int oldHostStateVal = 0;
		bool needToUseSessionSplitKick = ScriptGlobal(1207480).As<void*>() == data && Player(target).GetData().m_UseSessionSplitKick;
		if (needToUseSessionSplitKick)
		{
			oldHostStateVal = *ScriptGlobal(1207480).At(2505).At(0, 6).At(0, 3).As<int*>();
			*ScriptGlobal(1207480).At(2505).At(0, 6).At(0, 3).As<int*>() = 2;
			*Pointers.NetArrayPatch = 0xEB;
		}

		auto ret = BaseHook::Get<Toxic::BroadcastNetArray, DetourHook<decltype(&Toxic::BroadcastNetArray)>>()->Original()(array, target, buffer, counter, elem_start);

		if (needToUseSessionSplitKick)
		{
			*ScriptGlobal(1207480).At(2505).At(0, 6).At(0, 3).As<int*>() = oldHostStateVal;
			*Pointers.NetArrayPatch = 0x74;
		}

		return ret;
	}
}