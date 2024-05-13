#include "core/commands/BoolCommand.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"


namespace YimMenu::Features
{
	BoolCommand _SpoofModel("spoofmodel", "Spoof Model", "Spoofs your model to other players!");
}

namespace YimMenu::Hooks
{
	void Spoofing::WritePlayerAppearanceDataNode(rage::netObject* player, void* node)
	{
		//LOG(VERBOSE) << "WROTE APPEARANCE";
		//LOG(VERBOSE) << node;

		BaseHook::Get<Spoofing::WritePlayerAppearanceDataNode, DetourHook<decltype(&Spoofing::WritePlayerAppearanceDataNode)>>()
		    ->Original()(player, node);
	}
}