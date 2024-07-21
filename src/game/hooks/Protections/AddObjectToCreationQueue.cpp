#include "core/hooking/DetourHook.hpp"
#include "game/backend/Protections.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Nodes.hpp"
#include "util/Joaat.hpp"

#include <network/netObject.hpp>

namespace YimMenu::Hooks
{
	int Protections::AddObjectToCreationQueue(void* mgr, NetObjType type, CNetGamePlayer* src, CNetGamePlayer* dst)
	{
		YimMenu::Protections::SetSyncingPlayer(src);

		if (ShouldBlockSync(Pointers.GetSyncTreeForType(nullptr, (uint16_t)type), type, nullptr))
			return -1;

		YimMenu::Protections::SetSyncingPlayer(nullptr);

		return BaseHook::Get<Protections::AddObjectToCreationQueue, DetourHook<decltype(&Protections::AddObjectToCreationQueue)>>()
		    ->Original()(mgr, type, src, dst);
	}
}