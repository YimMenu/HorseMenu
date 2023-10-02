#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"

#include <entity/fwEntity.hpp>

namespace YimMenu::Hooks
{
	void* Protections::AllocateAnimData(__int64 _this, uint8_t phase)
	{
		auto result = BaseHook::Get<Protections::AllocateAnimData, DetourHook<decltype(&Protections::AllocateAnimData)>>()->Original()(_this, phase);
		if (result == nullptr)
		{
			LOG(FATAL) << __FUNCTION__ ": cannot allocate anim data: phase = " << (int)phase;
		}
		return result;
	}
}