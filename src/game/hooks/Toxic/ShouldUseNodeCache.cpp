#include "core/hooking/DetourHook.hpp"
#include "game/backend/NodeHooks.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Ped.hpp"
#include "util/Joaat.hpp"

namespace YimMenu::Hooks
{
	bool Hooks::Toxic::ShouldUseNodeCache(void* node, int flags)
	{
		if (NodeHooks::ShouldSkipNodeCache(reinterpret_cast<CProjectBaseSyncDataNode*>(node)))
			return false;

		return BaseHook::Get<Toxic::ShouldUseNodeCache, DetourHook<decltype(&Toxic::ShouldUseNodeCache)>>()->Original()(node, flags);
	}
}