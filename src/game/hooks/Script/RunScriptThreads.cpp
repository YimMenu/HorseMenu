#include "core/hooking/DetourHook.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/hooks/Hooks.hpp"

namespace YimMenu::Hooks
{
	bool Script::RunScriptThreads(void* threads, int unk)
	{
		ScriptMgr::Tick();
		return BaseHook::Get<Script::RunScriptThreads, DetourHook<decltype(&RunScriptThreads)>>()->Original()(threads, unk);
	}
}