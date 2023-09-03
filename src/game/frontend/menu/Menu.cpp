#include "game/frontend/menu/Menu.hpp"

#include "core/renderer/Renderer.hpp"
#include "game/frontend/menu/self/Self.hpp"

namespace YimMenu
{
	void Menu::Init()
	{
		static auto SelfSubmenu = std::make_shared<Self>();
		SelfSubmenu->LoadSubmenus(); //Loads mini submenus into memory.

		Renderer::AddRendererCallBack(
		    [&] {
			    if (!GUI::IsOpen())
				    return;

			    //Think this add HTML&PHP with no CSS. Lol just for testing.

			    ImGui::SetNextWindowSize(ImVec2(610, 610 /*add auto resize*/), ImGuiCond_Once);
			    if (ImGui::Begin("Main Window"))
			    {
				    const auto& pos = ImGui::GetCursorPos();

				    if (ImGui::Button("Unload"))
					    g_Running = false;

				    if (ImGui::BeginChild("##submenus", ImVec2(120, 0), true))
				    {
					    g_SubmenuHandler.SubmenuOption("L" /*Logo Font*/, "Self", SelfSubmenu); //Ideally with the logo you'd have them squares that fit perfectly.
				    }
				    ImGui::EndChild(); //Good practice to call endchild after the brackets

				    ImGui::SetCursorPos(ImVec2(pos.x + 130, pos.y));

				    if (ImGui::BeginChild("##minisubmenus", ImVec2(0, 50), true))
				    {
					    g_SubmenuHandler.RenderSubmenuCategories();
				    }
				    ImGui::EndChild();

				    ImGui::SetCursorPos(ImVec2(pos.x + 130, pos.y + 60));

				    if (ImGui::BeginChild("##options", ImVec2(0, 0), true))
				    {
					    ImGui::Text("Current Submenu %s", g_SubmenuHandler.GetActiveSubmenuName());
					    ImGui::Text("Current Mini Submenu %s", g_SubmenuHandler.GetActiveMiniSubMenuName());
					    ImGui::Separator();

					    g_SubmenuHandler.RenderActiveSubmenu();
				    }
				    ImGui::EndChild();

				    ImGui::End();
			    }
		    },
		    -1);
	}
}