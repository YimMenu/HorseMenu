#include "core/hooking/DetourHook.hpp"
#include "game/backend/Protections.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Nodes.hpp"
#include "util/Joaat.hpp"

#include <network/netObject.hpp>

namespace Terminus::Hooks
{
	int Protections::AddObjectToCreationQueue(void* mgr, CNetGamePlayer* src, CNetGamePlayer* dst, NetObjType type, std::uint16_t net_id, int flags, void* a7, void* guid, int a9)
	{
		Terminus::Protections::SetSyncingPlayer(src);

		if (ShouldBlockSync(Pointers.GetSyncTreeForType(nullptr, (uint16_t)type), type, nullptr))
			return 0;

		Terminus::Protections::SetSyncingPlayer(nullptr);

		return BaseHook::Get<Protections::AddObjectToCreationQueue, DetourHook<decltype(&Protections::AddObjectToCreationQueue)>>()->Original()(mgr, src, dst, type, net_id, flags, a7, guid, a9);
	}
}