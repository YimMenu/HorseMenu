#include "Self.hpp"
#include "game/frontend/manager/Widgets/Widgets.hpp"

#include "game/backend/ScriptMgr.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/rdr/ScriptGlobal.hpp"

namespace YimMenu::Submenus
{
	static void Main()
	{
		LoopedCommandToggle("godmode"_J).Draw();
		LoopedCommandToggle("keepbarsfilled"_J).Draw();
		LoopedCommandToggle("keepcoresfilled"_J).Draw();
		LoopedCommandToggle("infiniteammo"_J).Draw();
		LoopedCommandToggle("infiniteclip"_J).Draw();
		LoopedCommandToggle("keepclean"_J).Draw();
		LoopedCommandToggle("noclip"_J).Draw();
		LoopedCommandToggle("voicechatoverride"_J).Draw(); // TODO: move this to spoofing or network

		static int global = 0;
		static int value  = 0;
		ImGui::InputInt("Global", &global);
		ImGui::InputInt("Value", &value);
		if (ImGui::Button("Get"))
			value = *ScriptGlobal(global).As<int*>();
		ImGui::SameLine();
		if (ImGui::Button("Set"))
			*ScriptGlobal(global).As<int*>() = value;
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