#include "game/frontend/menu/Menu.hpp"

#include "core/renderer/Renderer.hpp"
#include "game/frontend/menu/self/Self.hpp"
#include "game/frontend/menu/settings/Settings.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/FiberPool.hpp"
#include "core/commands/Commands.hpp"

namespace YimMenu
{
	void Menu::Init()
	{
		static auto SelfSubmenu = std::make_shared<Submenus::Self>();
		SelfSubmenu->LoadSubmenus(); //Loads mini submenus into memory.

		static auto SettingsSubmenu = std::make_shared<Submenus::Settings>();
		SettingsSubmenu->LoadSubmenus(); //Loads mini submenus into memory.

		Renderer::AddRendererCallBack(
		    [&] {
			    if (!GUI::IsOpen())
				    return;

			    //Think this add HTML&PHP with no CSS. Lol just for testing.

			    ImGui::SetNextWindowSize(ImVec2(610, 610 /*add auto resize*/), ImGuiCond_Once);
			    if (ImGui::Begin("HorseMenu"))
			    {
				    const auto& Pos = ImGui::GetCursorPos();

				    if (ImGui::Button("Unload"))
				    {
						if (ScriptMgr::CanTick())
						{
						    FiberPool::Push([] {
							    Commands::Shutdown();
							    g_Running = false;
						    });
						}
						else
						{
						    g_Running = false;
						}
				    }

				    if (!g_SubmenuHandler.GetActiveSubmenu())
					    g_SubmenuHandler.SetActiveSubmenu(SelfSubmenu);

				    if (ImGui::BeginChild("##submenus", ImVec2(120, 0), true))
				    {
					    //Arguably the only place this file should be edited at for more menus

					    g_SubmenuHandler.SubmenuOption("L" /*Logo Font*/, "Self", SelfSubmenu); //Ideally with the logo you'd have them squares that fit perfectly.
					    g_SubmenuHandler.SubmenuOption("L" /*Logo Font*/, "Settings", SettingsSubmenu);
				    }
				    ImGui::EndChild(); //Good practice to call endchild after the brackets

				    ImGui::SetCursorPos(ImVec2(Pos.x + 130, Pos.y));

				    if (ImGui::BeginChild("##minisubmenus", ImVec2(0, 50), true, ImGuiWindowFlags_NoScrollbar))
				    {
					    g_SubmenuHandler.RenderSubmenuCategories();
				    }
				    ImGui::EndChild();

				    ImGui::SetCursorPos(ImVec2(Pos.x + 130, Pos.y + 60));

				    if (ImGui::BeginChild("##options", ImVec2(0, 0), true))
				    {
					    auto ActiveSubmenu = g_SubmenuHandler.GetActiveSubmenu();

					    if (ActiveSubmenu && g_SubmenuHandler.GetActiveSubmenuDefaultMiniSubmenu() && !g_SubmenuHandler.GetActiveSubmenuActiveMiniSubmenu())
						    ActiveSubmenu.get()->SetActiveMiniSubmenu(ActiveSubmenu.get()->m_DefaultMiniSubmenu);

					    g_SubmenuHandler.RenderActiveSubmenu();
				    }
				    ImGui::EndChild();

				    ImGui::End();
			    }
		    },
		    -1);

		//Menu::ApplyTheme();
	}
}