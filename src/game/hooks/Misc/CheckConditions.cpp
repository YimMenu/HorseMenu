#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/backend/MapEditor/MapEditor.hpp"

namespace YimMenu::Hooks
{
	bool Misc::CheckConditionIsMale(__int64 a1, __int64 a2)
	{
		auto result = BaseHook::Get<Misc::CheckConditionIsMale, DetourHook<decltype(&Misc::CheckConditionIsMale)>>()->Original()(a1, a2);
		if (!result)
		{
			auto slot = *reinterpret_cast<std::uint32_t*>(a1 + 0x10);
			auto ped = *reinterpret_cast<CPed**>(a2 + (uint64_t)(slot * 8) + 0xC0);
			if (ped && MapEditor::IsGameEntityRegisteredWithGlobalStore(ped))
				return true;
			else
				return false;
		}
		return true;
	}

	// TODO: this is actually CheckConditionNot, which negates the condition passed to it as a parameter in the XML files
	// hooking this globally causes bad stuff to happen, such as disabling some important safeguards
	// that's why we only apply it to editor peds to prevent any collateral damage that may result from this patch
	bool Misc::CheckConditionIsFemale(__int64 a1, __int64 a2)
	{
		auto result = BaseHook::Get<Misc::CheckConditionIsFemale, DetourHook<decltype(&Misc::CheckConditionIsFemale)>>()->Original()(a1, a2);
		if (!result)
		{
			auto ai_condition = *reinterpret_cast<std::uintptr_t*>(a1 + 0x10);
			if (!ai_condition)
				return false;
			auto slot = *reinterpret_cast<std::uint32_t*>(ai_condition + 0x10);
			slot = 0; // TODO
			auto ped = *reinterpret_cast<CPed**>(a2 + (uint64_t)(slot * 8) + 0xC0);
			if (ped && MapEditor::IsGameEntityRegisteredWithGlobalStore(ped))
				return true;
			else
				return false;
		}
		return true;
	}
}