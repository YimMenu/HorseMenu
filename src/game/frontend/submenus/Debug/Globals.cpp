#include "Globals.hpp"
#include "DrawVariable.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "core/filemgr/FileMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/backend/SavedVariables.hpp"

// TODO: name compares are expensive, but this is way better than the old impl that reads the json file every frame

namespace YimMenu::Submenus
{
	static void SaveGlobal(SavedGlobal& global_obj)
	{
		for (auto& global : SavedVariables::GetSavedGlobals())
		{
			if (global.name == global_obj.name)
			{
				global = global_obj;
				SavedVariables::Save();
				return;
			}
		}

		SavedVariables::GetSavedGlobals().push_back(global_obj);
		SavedVariables::Save();
	}

	static void DeleteGlobal(SavedGlobal& global_obj)
	{
		std::erase_if(SavedVariables::GetSavedGlobals(), [&](SavedGlobal& g) {
			return g.name == global_obj.name;
		});
		SavedVariables::Save();
	}

	std::shared_ptr<Category> BuildGlobalsMenu()
	{
		auto globals = std::make_unique<Category>("Globals");

		static bool ensure_vars_loaded = ([] {
			SavedVariables::Init();
			return true;
		})();

		static char global_name[255]{};

		static SavedGlobal cur_global{};

		auto editor = std::make_unique<Group>("Editor");
		editor->AddItem(std::make_unique<ImGuiItem>([] {
			DrawSavedVariable(cur_global);
			DrawSavedVariableEdit(cur_global, cur_global.Read());
		}));

		auto saved = std::make_unique<Group>("Saved");
		saved->AddItem(std::make_unique<ImGuiItem>([] {
			if (ImGui::BeginListBox("##savedglobals", ImVec2(200, 200)))
			{
				for (auto& var : SavedVariables::GetSavedGlobals())
				{
					if (ImGui::Selectable(var.name.c_str(), var.name == cur_global.name))
					{
						cur_global = var;
						strncpy(global_name, var.name.c_str(), sizeof(global_name));
					}
				}
				ImGui::EndListBox();
			}
			ImGui::SameLine();
			if (ImGui::BeginListBox("##globalvalues", ImVec2(200, 200)))
			{
				for (auto& var : SavedVariables::GetSavedGlobals())
				{
					DrawSavedVariablePreview(var, var.Read());
				}
				ImGui::EndListBox();
			}

			ImGui::BeginGroup();

			ImGui::SetNextItemWidth(200.f);
			ImGui::InputTextWithHint("##global_name", "Name", global_name, sizeof(global_name));
			ImGui::SameLine();
			if (ImGui::Button("Save"))
			{
				cur_global.name = global_name;
				SaveGlobal(cur_global);
			}
			ImGui::SameLine();
			if (ImGui::Button("Delete"))
			{
				cur_global.name = global_name;
				DeleteGlobal(cur_global);
				cur_global = SavedGlobal();
			}

			ImGui::EndGroup();
		}));

		globals->AddItem(std::move(editor));
		globals->AddItem(std::move(saved));
		return globals;
	}
}