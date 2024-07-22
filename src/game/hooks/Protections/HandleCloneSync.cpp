#include "core/hooking/DetourHook.hpp"
#include "game/backend/Protections.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Enums.hpp"

#include <network/CNetGamePlayer.hpp>

namespace YimMenu::Hooks
{
	int Protections::HandleCloneSync(void* mgr, CNetGamePlayer* src, CNetGamePlayer* dst, uint16_t objectType, uint16_t objectId, rage::datBitBuffer* buffer, int a7, int a8, void* a9)
	{
		YimMenu::Protections::SetSyncingPlayer(src);
		auto result = BaseHook::Get<Protections::HandleCloneSync, DetourHook<decltype(&Protections::HandleCloneSync)>>()->Original()(mgr, src, dst, objectType, objectId, buffer, a7, a8, a9);
		YimMenu::Protections::SetSyncingPlayer(nullptr);
		return result;
	}
}