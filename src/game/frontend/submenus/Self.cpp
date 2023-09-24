#include "Self.hpp"
#include "game/frontend/items/Items.hpp"

namespace YimMenu::Submenus
{
	Self::Self() :
	    Submenu::Submenu("Self")
	{
		auto main = std::make_shared<Category>("Main");
		main->AddItem(std::make_shared<BoolCommandItem>("godmode"_J));
		main->AddItem(std::make_shared<BoolCommandItem>("keepbarsfilled"_J));
		main->AddItem(std::make_shared<BoolCommandItem>("keepcoresfilled"_J));
		main->AddItem(std::make_shared<BoolCommandItem>("infiniteammo"_J));
		main->AddItem(std::make_shared<BoolCommandItem>("infiniteclip"_J));
		main->AddItem(std::make_shared<BoolCommandItem>("keepclean"_J));
		main->AddItem(std::make_shared<BoolCommandItem>("noclip"_J));
		main->AddItem(std::make_shared<BoolCommandItem>("voicechatoverride"_J)); // TODO: move this to spoofing or network
		AddCategory(std::move(main));

		auto horse = std::make_shared<Category>("Horse");
		horse->AddItem(std::make_shared<BoolCommandItem>("keephorsebarsfilled"_J));
		horse->AddItem(std::make_shared<BoolCommandItem>("keephorsecoresfilled"_J));
		horse->AddItem(std::make_shared<BoolCommandItem>("keephorseagitationlow"_J));
		AddCategory(std::move(horse));
	}
}