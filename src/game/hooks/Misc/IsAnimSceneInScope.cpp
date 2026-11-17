#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"

namespace Terminus::Hooks
{
	bool Misc::IsAnimSceneInScope(rage::netObject* scene, CNetGamePlayer* player, int* reason)
	{
		// sure
		if (reason)
			*reason = 4;
		
		return true;
	}
}