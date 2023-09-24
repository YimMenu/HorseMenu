#include "Menu.hpp"
#include "core/renderer/Renderer.hpp"
#include "submenus/Self.hpp"
#include "submenus/Settings.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/FiberPool.hpp"
#include "core/commands/Commands.hpp"
#include "core/frontend/manager/UIManager.hpp"

namespace YimMenu
{
	void Menu::Init()
	{
		// Arguably the only place this file should be edited at for more menus
		UIManager::AddSubmenu(std::make_shared<Submenus::Self>());
		UIManager::AddSubmenu(std::make_shared<Submenus::Settings>());

		Renderer::AddRendererCallBack(
		    [&] {
			    if (!GUI::IsOpen())
				    return;

			    // Think this add HTML&PHP with no CSS. Lol just for testing.
			    ImGui::SetNextWindowSize(ImVec2(610, 610 /*add auto resize*/), ImGuiCond_Once);
			    if (ImGui::Begin("HorseMenu"))
			    {
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

					UIManager::Draw();
	
				    ImGui::End();
			    }
		    },
		    -1);
	}
}