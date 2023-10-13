#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/backend/Players.hpp"

namespace YimMenu::Hooks
{
	void Info::AssignPhysicalIndex(void* mgr, CNetGamePlayer* player, uint8_t newIndex)
	{
		if (newIndex == (uint8_t)-1)
		{
			Players::HandlePlayerLeave(player);
			BaseHook::Get<Info::AssignPhysicalIndex, DetourHook<decltype(&Info::AssignPhysicalIndex)>>()->Original()(mgr, player, newIndex);
		}
		else
		{
			BaseHook::Get<Info::AssignPhysicalIndex, DetourHook<decltype(&Info::AssignPhysicalIndex)>>()->Original()(mgr, player, newIndex);
			Players::HandlePlayerJoin(player);
		}
	}
}