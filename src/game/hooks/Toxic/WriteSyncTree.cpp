#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Ped.hpp"
#include "util/Joaat.hpp"
#include "game/backend/NodeHooks.hpp"

namespace YimMenu::Hooks
{
	bool Hooks::Toxic::WriteSyncTree(void* tree, int type, int flags, rage::netObject* object, rage::datBitBuffer* buffer, void* a6, std::uint8_t player_id, void* a8)
	{
		NodeHooks::SetSyncingObject(object);
		NodeHooks::SetSyncingPlayer(Player(player_id));

		auto ret = BaseHook::Get<Toxic::WriteSyncTree, DetourHook<decltype(&Toxic::WriteSyncTree)>>()->Original()(tree, type, flags, object, buffer, a6, player_id, a8);

		NodeHooks::SetSyncingObject(nullptr);
		NodeHooks::SetSyncingPlayer(nullptr);

		return ret;
	}
}