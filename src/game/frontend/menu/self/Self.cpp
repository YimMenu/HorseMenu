#include "Self.hpp"
#include "game/frontend/manager/Widgets/Widgets.hpp"

namespace YimMenu
{
	//Mini Submenu 1
	void Main()
	{
		ImGui::Text("Test");
	};

	//Init mini submenus
	void Self::LoadSubmenus()
	{
		m_MiniSubMenus.push_back(std::make_shared<MiniSubmenu>("Main", Main));
	}

	//Mini Submenu Selectors(Can be automated)
	void Self::DrawMiniSubmenuSelectors()
	{
		for (auto& minisubmenu : m_MiniSubMenus)
		{
			MiniSubmenuOption(minisubmenu);

			if (m_MiniSubMenus.back() != minisubmenu)
				ImGui::SameLine();
		}

		//TODO Automation
	}

	//Script Tick If Needed
	void Self::Update()
	{
		//TODO
	}

	//Call Everytime When Newly Entered
	void Self::UpdateOnce()
	{
		//TODO
	}

}