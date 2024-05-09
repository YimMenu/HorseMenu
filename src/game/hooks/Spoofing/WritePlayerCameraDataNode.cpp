#include "core/commands/BoolCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"

namespace rage
{
	class CPlayerCameraDataNode;
}


namespace YimMenu::Features
{
	BoolCommand _HideSpectate("hidespectate", "Hide Spectate", "Hides spectate from other players");
}

namespace YimMenu::Hooks
{
	void Spoofing::WritePlayerCameraDataNode(rage::netObject* player, rage::CPlayerCameraDataNode* node)
	{
		LOG(VERBOSE) << "WROTE CAMERA DATA";
		BaseHook::Get<Spoofing::WritePlayerCameraDataNode, DetourHook<decltype(&Spoofing::WritePlayerCameraDataNode)>>()->Original()(player, node);
	}
}