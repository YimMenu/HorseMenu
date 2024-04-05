#include "core/commands/BoolCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/features/Features.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Natives.hpp"
#include "network/CNetGamePlayer.hpp"


namespace YimMenu
{
	std::string RemoveColorFromName(std::string name)
	{
		std::string::size_type start_pos = 0;
		std::string newstr               = name;

		while ((start_pos = newstr.find("~", start_pos)) != std::string::npos)
		{
			std::string::size_type end_pos = newstr.find("~", start_pos + 1);

			if (end_pos != std::string::npos)
			{
				newstr.erase(start_pos, end_pos - start_pos + 1);
			}
			else
			{
				break;
			}
		}

		return newstr;
	}

}

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
			Notifications::Show("Spoofed Name Detected",
			    std::string("Spoofed Name Detected from ").append(RemoveColorFromName(player->GetName())),
			    NotificationType::Warning);
		LOG(INFO) << player->GetName() << " is joining your session.";
	}

	void Info::PlayerHasLeft(CNetGamePlayer* player)
	{
		BaseHook::Get<Info::PlayerHasLeft, DetourHook<decltype(&Info::PlayerHasLeft)>>()->Original()(player);

		LOG(INFO) << player->GetName() << " has left your session.";
	}
}