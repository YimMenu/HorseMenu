#include "Self.hpp"
#include "game/frontend/manager/Widgets/Widgets.hpp"

namespace YimMenu
{
	//Mini Submenu 1
	void Main()
	{
		LoopedCommandToggle("keepbarsfilled"_J).Draw();
		LoopedCommandToggle("keepcoresfilled"_J).Draw();
		LoopedCommandToggle("infiniteammo"_J).Draw();
		LoopedCommandToggle("infiniteclip"_J).Draw();
		LoopedCommandToggle("keepclean"_J).Draw();
	};

	void Horse()
	{
		LoopedCommandToggle("keephorsebarsfilled"_J).Draw();
		LoopedCommandToggle("keephorsecoresfilled"_J).Draw();
		LoopedCommandToggle("keephorseagitationlow"_J).Draw();
	};

	//Init mini submenus
	void Self::LoadSubmenus()
	{
		m_MiniSubMenus.push_back(std::make_shared<MiniSubmenu>("Main", Main));
		m_MiniSubMenus.push_back(std::make_shared<MiniSubmenu>("Horse", Horse));
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