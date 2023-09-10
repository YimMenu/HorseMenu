#include "Self.hpp"
#include "game/frontend/manager/Widgets/Widgets.hpp"

namespace YimMenu::Submenus
{
	static void Main()
	{
		LoopedCommandToggle("keepbarsfilled"_J).Draw();
		LoopedCommandToggle("keepcoresfilled"_J).Draw();
		LoopedCommandToggle("infiniteammo"_J).Draw();
		LoopedCommandToggle("infiniteclip"_J).Draw();
		LoopedCommandToggle("keepclean"_J).Draw();
		LoopedCommandToggle("noclip"_J).Draw();
	};

	static void Horse()
	{
		LoopedCommandToggle("keephorsebarsfilled"_J).Draw();
		LoopedCommandToggle("keephorsecoresfilled"_J).Draw();
		LoopedCommandToggle("keephorseagitationlow"_J).Draw();
	};

	//Init mini submenus
	void Self::LoadSubmenus()
	{
		m_MiniSubmenus.push_back(std::make_shared<MiniSubmenu>("Main", Main));
		m_MiniSubmenus.push_back(std::make_shared<MiniSubmenu>("Horse", Horse));

		m_DefaultMiniSubmenu = m_MiniSubmenus.front();
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