#include "core/hooking/DetourHook.hpp"
#include "game/backend/NodeHooks.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Ped.hpp"
#include "util/Joaat.hpp"

namespace YimMenu::Hooks
{
	void Hooks::Toxic::SetTreeTargetObject(void* tree, rage::netObject* object)
	{
		NodeHooks::SetSyncingObject(object);

		BaseHook::Get<Toxic::SetTreeTargetObject, DetourHook<decltype(&Toxic::SetTreeTargetObject)>>()->Original()(tree, object);
	}
}