#include "core/hooking/DetourHook.hpp"
#include "game/backend/Protections.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Nodes.hpp"

namespace YimMenu::Hooks
{
	void Protections::ResetSyncNodes()
	{
		Nodes::Reset();
		BaseHook::Get<Protections::ResetSyncNodes, DetourHook<decltype(&Protections::ResetSyncNodes)>>()->Original()();
	}
}