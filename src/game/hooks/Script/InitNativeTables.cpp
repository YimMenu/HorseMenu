#include "core/hooking/DetourHook.hpp"
#include "game/backend/NativeHooks.hpp"
#include "game/backend/ScriptPatches.hpp"
#include "game/hooks/Hooks.hpp"

namespace YimMenu::Hooks
{
	bool Script::InitNativeTables(rage::scrProgram* program)
	{
		bool ret = BaseHook::Get<Script::InitNativeTables, DetourHook<decltype(&InitNativeTables)>>()->Original()(program);
		if (g_Running)
		{
			NativeHooks::RegisterProgram(program);
			ScriptPatches::RegisterProgram(program);
		}
		return ret;
	}
}