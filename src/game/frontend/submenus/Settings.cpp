#include "settings.hpp"

#include "core/commands/Commands.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/features/Features.hpp"
#include "game/frontend/items/Items.hpp"

namespace YimMenu::Submenus
{
	// TODO: refactor this
	static void Hotkeys()
	{
		ImGui::BulletText("Hold the command name clicked to change its hotkey");
		ImGui::BulletText("Press any registered key to remove");

		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();

		for (auto& [Hash, Command] : Commands::GetCommands())
		{
			ImGui::PushID(Hash);

			if (g_HotkeySystem.m_CommandHotkeys.find(Hash) != g_HotkeySystem.m_CommandHotkeys.end())
				HotkeySetter(Hash).Draw();

			ImGui::Spacing();

			ImGui::PopID();
		}
	};

	Settings::Settings() :
	    Submenu::Submenu("Settings")
	{
		auto hotkeys     = std::make_shared<Category>("Hotkeys");
		auto gui         = std::make_shared<Category>("GUI");
		auto protections = std::make_shared<Category>("Protection");
		auto esp         = std::make_shared<Group>("ESP");
		auto context     = std::make_shared<Group>("Context Menu");
		auto misc        = std::make_shared<Group>("Misc");

		hotkeys->AddItem(std::make_shared<ImGuiItem>(Hotkeys));

		esp->AddItem(std::make_shared<BoolCommandItem>("esp"_J));
		esp->AddItem(std::make_shared<ConditionalItem>("esp"_J, std::make_shared<BoolCommandItem>("espname"_J, "Name")));
		esp->AddItem(std::make_shared<ConditionalItem>("esp"_J, std::make_shared<BoolCommandItem>("espdistance"_J, "Distance")));
		esp->AddItem(std::make_shared<ConditionalItem>("esp"_J, std::make_shared<BoolCommandItem>("espskeleton"_J, "Skeleton")));

		context->AddItem(std::make_shared<BoolCommandItem>("ctxmenu"_J));
		context->AddItem(std::make_shared<ConditionalItem>("ctxmenu"_J, std::make_shared<BoolCommandItem>("ctxmenuplayers"_J, "Players")));
		context->AddItem(std::make_shared<ConditionalItem>("ctxmenu"_J, std::make_shared<BoolCommandItem>("ctxmenupeds"_J, "Peds")));
		context->AddItem(std::make_shared<ConditionalItem>("ctxmenu"_J, std::make_shared<BoolCommandItem>("ctxmenuvehicles"_J, "Vehicles")));
		context->AddItem(std::make_shared<ConditionalItem>("ctxmenu"_J, std::make_shared<BoolCommandItem>("ctxmenuobjects"_J, "Objects")));

		protections->AddItem(std::make_shared<BoolCommandItem>("detectspoofednames"_J));
		protections->AddItem(std::make_shared<BoolCommandItem>("allowremotetp"_J));

		misc->AddItem(std::make_shared<BoolCommandItem>("popplayerlist"_J));

		gui->AddItem(esp);
		gui->AddItem(context);
		gui->AddItem(misc);
		AddCategory(std::move(hotkeys));
		AddCategory(std::move(gui));
		AddCategory(std::move(protections));
	}
}