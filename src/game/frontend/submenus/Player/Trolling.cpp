#include "Trolling.hpp"

namespace YimMenu::Submenus
{
	std::shared_ptr<Category> BuildTrollingMenu()
	{
		auto menu = std::make_shared<Category>("Trolling");

		auto attachments = std::make_shared<Group>("Attachments");

		menu->AddItem(std::make_shared<PlayerCommandItem>("cageplayersmall"_J));
		menu->AddItem(std::make_shared<PlayerCommandItem>("cageplayerlarge"_J));
		menu->AddItem(std::make_shared<PlayerCommandItem>("cageplayercircus"_J));
		attachments->AddItem(std::make_shared<PlayerCommandItem>("spank"_J));
		attachments->AddItem(std::make_shared<PlayerCommandItem>("rideonshoulders"_J));
		attachments->AddItem(std::make_shared<PlayerCommandItem>("touchplayer"_J));
		attachments->AddItem(std::make_shared<PlayerCommandItem>("slap"_J));
		attachments->AddItem(std::make_shared<CommandItem>("cancelattachment"_J));

		menu->AddItem(attachments);

		return menu;
	}
}