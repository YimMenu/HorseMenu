#include "settings.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/frontend/items/Items.hpp"
#include "Settings.hpp"
#include "game/features/Features.hpp"
#include "game/bigfeatures/ContextMenu.hpp"

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
		auto hotkeys = std::make_shared<Category>("Hotkeys");
		auto gui = std::make_shared<Category>("GUI");
		hotkeys->AddItem(std::make_shared<ImGuiItem>(Hotkeys));
		gui->AddItem(std::make_shared<BoolCommandItem>("esp"_J));
		AddCategory(std::move(hotkeys));
		AddCategory(std::move(gui));
	}
}