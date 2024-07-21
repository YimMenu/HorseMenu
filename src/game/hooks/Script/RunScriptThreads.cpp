#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/backend/ScriptMgr.hpp"

namespace YimMenu::Hooks
{
	bool Script::RunScriptThreads(void* threads, int unk)
	{
		if (g_Running)
			ScriptMgr::Tick();
		return BaseHook::Get<Script::RunScriptThreads, DetourHook<decltype(&RunScriptThreads)>>()->Original()(threads, unk);
	}
}