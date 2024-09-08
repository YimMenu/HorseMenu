#include "Kick.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/Players.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Submenus
{
	std::shared_ptr<Category> BuildKickMenu()
	{ 
		auto menu = std::make_shared<Category>("Kick");

		auto kicks   = std::make_shared<Group>("Kicks");

		kicks->AddItem(std::make_shared<PlayerCommandItem>("splitkick"_J));
		kicks->AddItem(std::make_shared<PlayerCommandItem>("popkick"_J));
		kicks->AddItem(std::make_shared<PlayerCommandItem>("icekick"_J));

		menu->AddItem(std::move(kicks));

		return menu;
	}
}