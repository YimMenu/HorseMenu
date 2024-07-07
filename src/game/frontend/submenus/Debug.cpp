#include "Debug.hpp"

#include "core/filemgr/FileMgr.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/rdr/Natives.hpp"
#include "Debug/Globals.hpp"
#include "Debug/Scripts.hpp"

namespace YimMenu::Submenus
{	
	Debug::Debug() :
	    Submenu::Submenu("Debug")
	{
		auto globals = std::make_shared<Category>("Globals");

		globals->AddItem(std::make_shared<ImGuiItem>([] {
			RenderGlobalsMenu();
		}));

		AddCategory(std::move(globals));

		auto threads = std::make_shared<Category>("Threads");

		threads->AddItem(std::make_shared<ImGuiItem>([] {
			RenderScriptsMenu();
		}));

		AddCategory(std::move(threads));

		auto debug = std::make_shared<Category>("Logging");
		debug->AddItem(std::make_shared<BoolCommandItem>("logclones"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logevents"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logtses"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logmetrics"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logpackets"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logpresenceevents"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logpostmessage"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logservermessages"_J));
		debug->AddItem(std::make_shared<CommandItem>("chathelper"_J));
		debug->AddItem(std::make_shared<ImGuiItem>([] {
			if (ImGui::Button("Bail to Loading Screen"))
			{
				FiberPool::Push([] {
					SCRIPTS::BAIL_TO_LANDING_PAGE(0);
				});
			}
		}));
		AddCategory(std::move(debug));
	}
}