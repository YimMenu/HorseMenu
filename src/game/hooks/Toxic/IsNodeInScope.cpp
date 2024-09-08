#include "core/hooking/DetourHook.hpp"
#include "game/backend/NodeHooks.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Ped.hpp"
#include "util/Joaat.hpp"

#include <network/netObject.hpp>

namespace YimMenu::Hooks
{
	bool Hooks::Toxic::IsNodeInScope(void* node, void* a2, std::uint8_t playerId, int flags)
	{
		if (NodeHooks::ShouldForceInScope(reinterpret_cast<CProjectBaseSyncDataNode*>(node)))
			return true;

		return BaseHook::Get<Toxic::IsNodeInScope, DetourHook<decltype(&Toxic::IsNodeInScope)>>()->Original()(node, a2, playerId, flags);
	}
}