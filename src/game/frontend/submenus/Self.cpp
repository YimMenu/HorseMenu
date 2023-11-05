#include "Self.hpp"

#include "game/frontend/items/Items.hpp"

namespace YimMenu::Submenus
{
	Self::Self() :
	    Submenu::Submenu("Self")
	{
		auto main          = std::make_shared<Category>("Main");
		auto globalsGroup  = std::make_shared<Group>("Globals", ImVec2(0, 250));
		auto movementGroup = std::make_shared<Group>("Movement", ImVec2(0, 250));
		auto toolsGroup    = std::make_shared<Group>("Tools", ImVec2(0, 250));
		auto columns       = std::make_shared<Column>(2);

		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("godmode"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("noragdoll"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("offtheradar"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("invis"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("antiafk"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("keepbarsfilled"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("keepcoresfilled"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("infiniteammo"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("infiniteclip"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("keepclean"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("antilasso"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("antihogtie"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("voicechatoverride"_J)); // TODO: move this to spoofing or network

		toolsGroup->AddItem(std::make_shared<CommandItem>("suicide"_J));
		toolsGroup->AddItem(std::make_shared<CommandItem>("clearcrimes"_J));

		movementGroup->AddItem(std::make_shared<BoolCommandItem>("noclip"_J));

		columns->AddItem(globalsGroup);
		columns->AddItem(toolsGroup);
		columns->AddNextColumn();
		columns->AddItem(movementGroup);
		main->AddItem(columns);
		AddCategory(std::move(main));

		auto horse             = std::make_shared<Category>("Horse");
		auto horseGlobalsGroup = std::make_shared<Group>("Globals");
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("horsegodmode"_J));
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("horsenoragdoll"_J));
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("keephorsebarsfilled"_J));
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("keephorsecoresfilled"_J));
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("keephorseagitationlow"_J));
		horseGlobalsGroup->AddItem(std::make_shared<CommandItem>("tpmounttoself"_J));
		horse->AddItem(horseGlobalsGroup);
		AddCategory(std::move(horse));
	}
}