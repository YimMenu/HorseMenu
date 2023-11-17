#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Hooks
{
	void Info::AssignPhysicalIndex(void* mgr, CNetGamePlayer* player, uint8_t newIndex)
	{
		if (newIndex == PLAYER::PLAYER_ID())
			Notifications::Show("Online", "Joining a new public session.");

		BaseHook::Get<Info::AssignPhysicalIndex, DetourHook<decltype(&Info::AssignPhysicalIndex)>>()->Original()(mgr, player, newIndex);
	}
}