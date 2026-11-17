#include "LuaScripts.hpp"
#include "Lua/LuaMgr.hpp"
#include "Lua/LuaModule.hpp"
#include "game/frontend/items/Items.hpp"

#include <imgui_internal.h>

// TODO: This is just a test UI. Eventually we will expose a high level API (submenus, categories, commands, items, etc.)
// For now, modules can register a single draw function and that's it.

namespace Terminus::Submenus
{
	static std::shared_ptr<LuaJIT::LuaModule> selectedModule;

	LuaScripts::LuaScripts() :
	    Submenu::Submenu("Lua Scripts")
	{
		auto scripts = std::make_shared<Category>("Scripts");
		scripts->AddItem(std::make_shared<ImGuiItem>([] {
			auto& modules = LuaJIT::LuaManager::GetModules();

			ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 0.f);
			ImGui::BeginChild("##scriptLst", ImVec2(100.f, 0.f), ImGuiChildFlags_ResizeX, ImGuiWindowFlags_NoBackground);
			for (auto& m : LuaJIT::LuaManager::GetModules())
			{
				if (m->GetLoadState() != LuaJIT::LuaModule::RUNNING)
					continue;

				if (ImGui::Selectable(m->GetName().data(), (selectedModule && m == selectedModule)))
					selectedModule = m;

				ImGui::Separator();
			}
			ImGui::EndChild();

			ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2());
			ImGui::SameLine();
			ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical, 3.0f);
			ImGui::PopStyleVar(2);
			ImGui::SameLine();

			ImGui::SetNextWindowBgAlpha(0.0f);
			ImGui::BeginChild("##scritpCb");
			if (selectedModule && selectedModule->GetLoadState() == LuaJIT::LuaModule::RUNNING)
			{
				auto& cb = selectedModule->m_GuiCallback;
				if (!cb.valid())
					ImGui::TextWrapped("This module has no GUI to draw.");
				else
				{
					auto res = cb();
					if (!res.valid())
					{
						sol::error e = res;
						auto msg     = e.what();
						LOG(FATAL) << msg;
						selectedModule->Suspend(msg);
					}
				}
			}
			ImGui::EndChild();
		}));

		AddCategory(std::move(scripts));
	}
}
