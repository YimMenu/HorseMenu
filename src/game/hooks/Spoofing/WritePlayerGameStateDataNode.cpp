#include "core/commands/BoolCommand.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"

namespace YimMenu::Hooks
{
	void Spoofing::WritePlayerGameStateDataNode(rage::netObject* player, void* node)
	{
		LOG(VERBOSE) << "WROTE GAME STATE";
		LOG(VERBOSE) << node;

		BaseHook::Get<Spoofing::WritePlayerGameStateDataNode, DetourHook<decltype(&Spoofing::WritePlayerGameStateDataNode)>>()
		    ->Original()(player, node);
	}
}