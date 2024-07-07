#include "Scripts.hpp"
#include "game/backend/Self.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/rdr/Scripts.hpp"
#include "game/rdr/data/ScriptNames.hpp"
#include "game/rdr/data/StackSizes.hpp"
#include "game/rdr/Natives.hpp"
#include <script/scrThread.hpp>
#include <script/scriptHandlerNetComponent.hpp>

static rage::scrThread* s_SelectedThread;
static int s_SelectedStackSize             = 128;
static int s_NumFreeStacks                 = -1;
static const char* s_SelectedScriptName    = "<SELECT>";
static const char* s_SelectedNewScriptName = "<SELECT>";
static const char* s_SelectedStackSizeStr  = "MICRO";
static std::chrono::high_resolution_clock::time_point s_LastStackUpdateTime{};

namespace
{
	static void UpdateFreeStackSizeCount()
	{
		s_NumFreeStacks = MISC::GET_NUMBER_OF_FREE_STACKS_OF_THIS_SIZE(s_SelectedStackSize);
	}
}

namespace YimMenu::Submenus
{
	void RenderScriptsMenu()
	{
		if (!Pointers.ScriptThreads || Pointers.ScriptThreads->size() == 0)
		{
			s_SelectedThread = nullptr;
			return;
		}

		if (ImGui::BeginCombo("Thread", s_SelectedThread ? s_SelectedScriptName : "<SELECT>"))
		{
			for (auto script : *Pointers.ScriptThreads)
			{
				if (script)
				{
					if (script->m_Context.m_State != rage::eThreadState::killed && script->m_Context.m_StackSize == 0)
						continue;

					ImGui::PushID(script->m_Context.m_ThreadId);

					if (script->m_Context.m_State == rage::eThreadState::killed)
						ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.1f, 0.1f, 1.f));

					if (ImGui::Selectable(Scripts::GetScriptName(script->m_Context.m_ScriptHash), s_SelectedThread == script))
					{
						s_SelectedThread     = script;
						s_SelectedScriptName = Scripts::GetScriptName(script->m_Context.m_ScriptHash);
					}

					if (s_SelectedThread == script)
						ImGui::SetItemDefaultFocus();

					if (script->m_Context.m_State == rage::eThreadState::killed)
						ImGui::PopStyleColor();

					ImGui::PopID();
				}
			}

			ImGui::EndCombo();
		}

		if (s_SelectedThread)
		{
			constexpr auto s_ThreadStateNames = std::to_array({"Idle", "Running", "Killed", "Paused", "Unk"});
			ImGui::Combo("State",
			    (int*)&s_SelectedThread->m_Context.m_State,
			    s_ThreadStateNames.data(),
			    s_ThreadStateNames.size(),
			    -1);
			ImGui::Text(std::format("StackSize: {}", s_SelectedThread->m_Context.m_StackSize).c_str());
			ImGui::Text(std::format("PC: 0x{:X}", s_SelectedThread->m_Context.m_ProgramCounter).c_str());

			if (s_SelectedThread->m_Context.m_State == rage::eThreadState::killed)
			{
				ImGui::Text(std::format("Exit Reason: {}", s_SelectedThread->m_ExitMessage).c_str());
			}
			else
			{
				if (s_SelectedThread->m_HandlerNetComponent)
				{
					auto handler = static_cast<rage::scriptHandlerNetComponent*>(s_SelectedThread->m_HandlerNetComponent);

					if (handler->GetHost())
					{
						ImGui::Text("Host: %s", Player(handler->GetHost()).GetName());
					}

					if (ImGui::Button("Force Host"))
					{
						FiberPool::Push([handler] {
							handler->DoHostMigration(Self::GetPlayer().GetHandle(), 0xFFFF, true);
						});
					}
				}

				if (ImGui::Button("Kill"))
				{
					if (s_SelectedThread->m_Context.m_StackSize != 0)
						s_SelectedThread->Kill();

					s_SelectedThread->m_Context.m_State = rage::eThreadState::killed;
				}
			}
		}

		ImGui::Text("New");

		if (ImGui::BeginCombo("Name", s_SelectedNewScriptName))
		{
			auto& map = *Pointers.IsSessionStarted ? Data::g_MpScriptNames : Data::g_SpScriptNames;
			for (auto& el : map)
			{
				if (ImGui::Selectable(el.second, el.second == s_SelectedNewScriptName))
				{
					s_SelectedNewScriptName = el.second;
				}

				if (el.second == s_SelectedNewScriptName)
					ImGui::SetItemDefaultFocus();
			}
			ImGui::EndCombo();
		}

		if (ImGui::BeginCombo("Stack Size", s_SelectedStackSizeStr))
		{
			for (auto& p : Data::g_StackSizes)
			{
				if (ImGui::Selectable(std::format("{} ({})", p.first, p.second).data(), s_SelectedStackSize == p.second))
				{
					s_SelectedStackSizeStr = p.first;
					s_SelectedStackSize    = p.second;

					FiberPool::Push([] {
						UpdateFreeStackSizeCount();
					});
				}

				if (p.second == s_SelectedStackSize)
					ImGui::SetItemDefaultFocus();
			}
			ImGui::EndCombo();
		}

		ImGui::Text(std::format("Free Stacks: {}", s_NumFreeStacks).c_str());

		if (ImGui::Button("Start"))
		{
			FiberPool::Push([] {
				auto hash = Joaat(s_SelectedNewScriptName);

				if (!SCRIPTS::DOES_SCRIPT_WITH_NAME_HASH_EXIST(hash))
				{
					return;
				}

				if (MISC::GET_NUMBER_OF_FREE_STACKS_OF_THIS_SIZE(s_SelectedStackSize) == 0)
				{
					return;
				}

				while (!SCRIPTS::HAS_SCRIPT_WITH_NAME_HASH_LOADED(hash))
				{
					SCRIPTS::REQUEST_SCRIPT_WITH_NAME_HASH(hash);
					ScriptMgr::Yield();
				}

				SCRIPTS::START_NEW_SCRIPT_WITH_NAME_HASH(hash, s_SelectedStackSize);
				SCRIPTS::SET_SCRIPT_WITH_NAME_HASH_AS_NO_LONGER_NEEDED(hash);

				UpdateFreeStackSizeCount();
			});
		};


		if (Pointers.ScriptThreads && Pointers.ScriptThreads->size() > 0 && std::chrono::high_resolution_clock::now() - s_LastStackUpdateTime > 100ms)
		{
			s_LastStackUpdateTime = std::chrono::high_resolution_clock::now();
			FiberPool::Push([] {
				UpdateFreeStackSizeCount();
			});
		}
	}
}