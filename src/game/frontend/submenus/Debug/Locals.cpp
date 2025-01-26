#include "DrawVariable.hpp"
#include "Locals.hpp"
#include "core/filemgr/FileMgr.hpp"
#include "game/backend/SavedVariables.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "game/pointers/Pointers.hpp"

#include <script/scrThread.hpp>

namespace YimMenu::Submenus
{
	static void SaveLocal(SavedLocal& local_obj)
	{
		for (auto& local : SavedVariables::GetSavedLocals())
		{
			if (local.name == local_obj.name && local.script == local_obj.script)
			{
				local = local_obj;
				SavedVariables::Save();
				return;
			}
		}

		SavedVariables::GetSavedLocals().push_back(local_obj);
		SavedVariables::Save();
	}

	static void DeleteLocal(SavedLocal& local_obj)
	{
		std::erase_if(SavedVariables::GetSavedLocals(), [&](SavedLocal& g) {
			return g.name == local_obj.name && g.script == local_obj.script;
		});
		SavedVariables::Save();
	}

	std::shared_ptr<Category> BuildLocalsMenu()
	{
		auto locals = std::make_unique<Category>("Locals");

		static bool ensure_vars_loaded = ([] {
			SavedVariables::Init();
			return true;
		})();

		static char local_name[255]{};

		static SavedLocal cur_local{};

		static rage::scrThread* cur_thread = nullptr;
		static const char* cur_script_name = nullptr;
		static std::uint32_t cur_script_hash = 0;

		auto script = std::make_unique<Group>("Script");

		script->AddItem(std::make_unique<ImGuiItem>([] {
			// TODO: pointless code reduplication
			if (!Pointers.ScriptThreads || Pointers.ScriptThreads->size() == 0)
			{
				cur_thread = nullptr;
				ImGui::TextDisabled("None");
				return;
			}

			ImGui::SetNextItemWidth(225.0f);
			if (ImGui::BeginCombo("Thread", cur_thread ? cur_script_name : "(Select)"))
			{
				for (auto script : *Pointers.ScriptThreads)
				{
					if (script)
					{
						if (script->m_Context.m_State == rage::eThreadState::killed || script->m_Context.m_StackSize == 0)
							continue;

						ImGui::PushID(script->m_Context.m_ThreadId);

						auto script_name = Scripts::GetScriptName(script->m_Context.m_ScriptHash);

						if (ImGui::Selectable(script_name, cur_thread == script))
						{
							cur_thread      = script;
							cur_script_name = script_name;
							cur_script_hash = script->m_Context.m_ScriptHash;
						}

						if (cur_thread == script)
							ImGui::SetItemDefaultFocus();

						ImGui::PopID();
					}
				}

				ImGui::EndCombo();
			}

			if (cur_thread && (cur_thread->m_Context.m_ScriptHash != cur_script_hash || cur_thread->m_Context.m_StackSize == 0 || cur_thread->m_Context.m_State == rage::eThreadState::killed))
				cur_thread = nullptr;

			if (!cur_thread)
				return;
		}));

		auto editor = std::make_unique<Group>("Editor");
		editor->AddItem(std::make_unique<ImGuiItem>([] {
			if (!cur_thread)
			{
				ImGui::TextDisabled("Invalid");
				return;
			}

			DrawSavedVariable(cur_local);
			DrawSavedVariableEdit(cur_local, cur_local.Read(cur_thread));
		}));

		auto saved = std::make_unique<Group>("Saved");
		saved->AddItem(std::make_unique<ImGuiItem>([] {
			if (!cur_thread)
			{
				ImGui::TextDisabled("Invalid");
				return;
			}

			auto script_idf = Scripts::GetScriptIdentifier(cur_thread);

			// refresh local if script changes (TODO not always the best idea)
			if (script_idf != cur_local.script)
			{
				cur_local        = SavedLocal();
				cur_local.script = script_idf;
			}

			if (ImGui::BeginListBox("##savedglobals", ImVec2(200, 200)))
			{
				for (auto& var : SavedVariables::GetSavedLocals())
				{
					if (var.script != script_idf)
						continue;

					if (ImGui::Selectable(var.name.c_str(), var.name == cur_local.name))
					{
						cur_local = var;
						strncpy(local_name, var.name.c_str(), sizeof(local_name));
					}
				}
				ImGui::EndListBox();
			}
			ImGui::SameLine();
			if (ImGui::BeginListBox("##globalvalues", ImVec2(200, 200)))
			{
				for (auto& var : SavedVariables::GetSavedLocals())
				{
					if (var.script != script_idf)
						continue;

					DrawSavedVariablePreview(var, var.Read(cur_thread));
				}
				ImGui::EndListBox();
			}

			ImGui::BeginGroup();

			ImGui::SetNextItemWidth(200.f);
			ImGui::InputText("##local_name", local_name, sizeof(local_name));
			ImGui::SameLine();
			if (ImGui::Button("Save"))
			{
				cur_local.name = local_name;
				SaveLocal(cur_local);
			}
			ImGui::SameLine();
			if (ImGui::Button("Delete"))
			{
				cur_local.name = local_name;
				DeleteLocal(cur_local);
				cur_local = SavedLocal();
			}

			ImGui::EndGroup();
		}));

		locals->AddItem(std::move(script));
		locals->AddItem(std::move(editor));
		locals->AddItem(std::move(saved));
		return locals;
	}
}