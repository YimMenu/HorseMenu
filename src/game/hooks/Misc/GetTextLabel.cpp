#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"

namespace YimMenu::Hooks
{
	const char* Misc::GetTextLabel(void* _this, const char* label)
	{
		auto result = BaseHook::Get<Misc::GetTextLabel, DetourHook<decltype(&Misc::GetTextLabel)>>()->Original()(_this, label);
		if (!result || !result[0])
			return label;
		return result;
	}
}