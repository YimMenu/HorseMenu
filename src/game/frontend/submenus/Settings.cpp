#include "settings.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/frontend/items/Items.hpp"
#include "Settings.hpp"

namespace YimMenu::Submenus
{
	// TODO: refactor this
	static void Hotkeys()
	{
		ImGui::BulletText("Hover over the command name to change its hotkey");
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
		hotkeys->AddItem(std::make_shared<ImGuiItem>(Hotkeys));
		AddCategory(std::move(hotkeys));

		auto debug = std::make_shared<Category>("Debug");
		debug->AddItem(std::make_shared<BoolCommandItem>("logclones"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logevents"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logtses"_J));
		AddCategory(std::move(debug));
	}
}