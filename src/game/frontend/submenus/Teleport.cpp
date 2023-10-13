#include "Teleport.hpp"
#include "game/frontend/items/Items.hpp"

namespace YimMenu::Submenus
{
	Teleport::Teleport() :
	    Submenu::Submenu("Teleport")
	{
		auto main = std::make_shared<Category>("Main");
		main->AddItem(std::make_shared<CommandItem>("tptowaypoint"_J));
		main->AddItem(std::make_shared<CommandItem>("tptomount"_J));
		AddCategory(std::move(main));
	}
}