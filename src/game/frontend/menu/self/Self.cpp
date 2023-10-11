#include "Self.hpp"

#include "game/frontend/manager/Widgets/Widgets.hpp"
#include "game/services/notification_service/NotificationService.hpp"

namespace YimMenu
{
	//Mini Submenu 1
	void Main()
	{
		Column(
		    [] {
			    //ColumnOffset() :)

			    Child(
			        "Toggle Stuff",
			        [] {
				        LoopedCommandToggle("keepbarsfilled"_J).Draw();
				        LoopedCommandToggle("keepcoresfilled"_J).Draw();
				        LoopedCommandToggle("infiniteammo"_J).Draw();
				        LoopedCommandToggle("infiniteclip"_J).Draw();
				        LoopedCommandToggle("keepclean"_J).Draw();
				        LoopedCommandToggle("noragdoll"_J).Draw();
			        },
			        ImVec2(0, 250))
			        .Draw();

			    /* -DEMOS
				Child("Toggle Stuff 2", [] {
				    static bool abc = false;
				    Checkbox("Demo One", &abc).Draw();
				    Checkbox("Demo Two", &abc).Draw();
				    Button("Hello", nullptr).Draw();
			    }, ImVec2(0, 150)).Draw();

				NextColumn();

				Child("Toggle Stuff 3", [] {
				    Button("Hello 2 ", nullptr).Draw();
				    Button("Hello 3", nullptr).Draw();
			    }, ImVec2(0, 150)).Draw();*/
		    },
		    2)
		    .Draw();

		static int test = 0;
		if (ImGui::Button("Test"))
		{
			g_NotificationService.ShowNotification("Hello", std::to_string(test), NotificationType::Info, 5000);
			test++;
		}
	};

	void Horse()
	{
		Child("Horse Stuff", [] {
			LoopedCommandToggle("keephorsebarsfilled"_J).Draw();
			LoopedCommandToggle("keephorsecoresfilled"_J).Draw();
			LoopedCommandToggle("keephorseagitationlow"_J).Draw();
			LoopedCommandToggle("horsenoragdoll"_J).Draw();
			LoopedCommandToggle("horseinvincibility"_J).Draw();
		}).Draw();
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