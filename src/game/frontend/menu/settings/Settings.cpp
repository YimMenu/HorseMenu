#include "settings.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/frontend/manager/Widgets/Widgets.hpp"

namespace YimMenu
{
	//Mini Submenu 1
	void Hotkeys()
	{
		ImGui::BulletText("Hover over the command name to change its hotkey");
		ImGui::BulletText("Press any registered key to remove");
		ImGui::Spacing();

		for (auto [hash, command] : Commands::GetCommands())
		{
			ImGui::PushID(hash);

			HotkeySetter(hash).Draw();

			ImGui::Spacing();

			ImGui::PopID();
		}

	};

	//Init mini submenus
	void Settings::LoadSubmenus()
	{
		m_MiniSubMenus.push_back(std::make_shared<MiniSubmenu>("Hotkeys", Hotkeys));

		m_DefaultMiniSubmenu = m_MiniSubMenus.front();
	}

		//Script Tick If Needed
	void Settings::Update()
	{
		//TODO
	}

	//Call Everytime When Newly Entered
	void Settings::UpdateOnce()
	{
		//TODO
	}
}