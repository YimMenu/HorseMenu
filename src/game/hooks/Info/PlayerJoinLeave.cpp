#include "core/commands/BoolCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/features/Features.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Natives.hpp"
#include "network/CNetGamePlayer.hpp"


namespace YimMenu::Features
{
	BoolCommand _DetectSpoofedNames{"detectspoofednames", "Detect Spoofed Names", "Detects If a Player is Possibly Spoofing Their Name"};
}

namespace YimMenu::Hooks
{
	void Info::PlayerHasJoined(CNetGamePlayer* player)
	{
		BaseHook::Get<Info::PlayerHasJoined, DetourHook<decltype(&Info::PlayerHasJoined)>>()->Original()(player);

		if (player->GetName()[0] == '~' && Features::_DetectSpoofedNames.GetState())
			Notifications::Show("Spoofed Name Detected", std::string("Spoofed Name Detected from ").append(player->GetName()), NotificationType::Warning);
		LOG(INFO) << player->GetName() << " is joining your session.";
	}

	void Info::PlayerHasLeft(CNetGamePlayer* player)
	{
		BaseHook::Get<Info::PlayerHasLeft, DetourHook<decltype(&Info::PlayerHasLeft)>>()->Original()(player);

		LOG(INFO) << player->GetName() << " has left your session.";
	}
}