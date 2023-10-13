#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"

#include <rage/rlJson.hpp>
#include <rage/rlMetric.hpp>

namespace YimMenu::Hooks
{
	bool Anticheat::UnkFunction(__int64 cb)
	{
		auto module = *(__int64*)(cb + 0x20);
		*(char*)(module + 0x18) = 3;
		return true;
	}
}