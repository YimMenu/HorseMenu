#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/invoker/Invoker.hpp"

namespace YimMenu::Hooks
{
	void Script::RegisterCompappNatives()
	{
		BaseHook::Get<Script::RegisterCompappNatives, DetourHook<decltype(&RegisterCompappNatives)>>()->Original()();
		NativeInvoker::CacheHandlers();
	}
}