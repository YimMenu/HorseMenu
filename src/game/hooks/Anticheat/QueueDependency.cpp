#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include <Psapi.h>

namespace YimMenu::Hooks
{
	static bool IsAddressInGameRegion(uint64_t address)
	{
		static uint64_t moduleBase = NULL;
		static uint64_t moduleSize = NULL;
		if ((!moduleBase) || (!moduleSize))
		{
			MODULEINFO info;
			if (!GetModuleInformation(GetCurrentProcess(), GetModuleHandle(0), &info, sizeof(info)))
			{
				LOG(FATAL) << "GetModuleInformation failed!";
				return true;
			}
			else
			{
				moduleBase = (uint64_t)GetModuleHandle(0);
				moduleSize = (uint64_t)info.SizeOfImage;
			}
		}
		return address > moduleBase && address < (moduleBase + moduleSize);
	}

	static bool IsJumpInstruction(__int64 fptr)
	{
		if (!IsAddressInGameRegion(fptr))
			return false;

		auto value = *(uint8_t*)(fptr);
		return value == 0xE9;
	}

	static bool IsUnwantedDependency(__int64 cb)
	{
		auto f1 = *(__int64*)(cb);
		auto f2 = *(__int64*)(cb + 0x78);

		if (!IsAddressInGameRegion(f1) || (f2 && !IsAddressInGameRegion(f2)))
			return false;

		return IsJumpInstruction(f1) || IsJumpInstruction(f2);
	}

	void Anticheat::QueueDependency(__int64 dependency)
	{
		if (IsUnwantedDependency(dependency))
		{
			LOG(INFO) << "Caught unwanted dependency: RDR2.exe+" << std::hex << std::uppercase << (*(__int64*)(dependency) - (__int64)GetModuleHandleA(0));
			return;
		}

		BaseHook::Get<Anticheat::QueueDependency, DetourHook<decltype(&Anticheat::QueueDependency)>>()->Original()(dependency);
	}
}