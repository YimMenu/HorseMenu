#include "game/hooks/Hooks.hpp"
#include "core/hooking/DetourHook.hpp"

namespace YimMenu::Hooks
{
	void* Protections::CreatePoolItem(PoolUtils<Entity>* pool)
	{
		auto item = BaseHook::Get<Protections::CreatePoolItem, DetourHook<decltype(&Protections::CreatePoolItem)>>()->Original()(pool);

		if (!item)
		{
			auto callerOffset = (__int64)_ReturnAddress() - (__int64)GetModuleHandleA(0);
			LOGF(FATAL, "Pool full! Caller: RDR2.exe+0x{:X}, Size: {}", callerOffset, pool->size());
		}

		return item;
	}
}