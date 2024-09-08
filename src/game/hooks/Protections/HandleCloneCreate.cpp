#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/backend/Protections.hpp"

#include <network/CNetGamePlayer.hpp>

namespace YimMenu::Hooks
{
	int Protections::HandleCloneCreate(void* mgr, CNetGamePlayer* sender, uint16_t objectType, uint16_t objectId, int flags, void* guid, rage::datBitBuffer* buffer, int a8, int a9, bool isQueued)
	{
		YimMenu::Protections::SetSyncingPlayer(sender);
		auto ret = BaseHook::Get<Protections::HandleCloneCreate, DetourHook<decltype(&Protections::HandleCloneCreate)>>()->Original()(mgr, sender, objectType, objectId, flags, guid, buffer, a8, a9, isQueued);
		YimMenu::Protections::SetSyncingPlayer(nullptr);

		if (ret == 6)
			ret = 0;

		return ret;
	}
}