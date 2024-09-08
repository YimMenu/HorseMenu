#include "game/hooks/Hooks.hpp"
#include "core/hooking/DetourHook.hpp"

namespace YimMenu::Hooks
{
	void* Protections::CreatePoolItem(rage::fwBasePool* pool, int size)
	{
		// pool might not actually be rage::fwBasePool
		if (pool->m_NextSlotIndex == -1)
		{
			auto callerOffset = (__int64)_ReturnAddress() - (__int64)GetModuleHandleA(0);
			LOGF(FATAL, "Pool full! Caller: RDR2.exe+0x{:X}, Size: {}, ItemSize: {}", callerOffset, pool->m_Size, size);
			return 0;
		}

		return BaseHook::Get<Protections::CreatePoolItem, DetourHook<decltype(&Protections::CreatePoolItem)>>()->Original()(pool, size);
	}
}