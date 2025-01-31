#include "Scripts.hpp"
#include <script/scrThread.hpp>
#include <script/scrProgram.hpp>
#include <script/scriptHandlerNetComponent.hpp>
#include <network/CNetworkPlayerMgr.hpp>
#include <rage/tlsContext.hpp>
#include "game/backend/ScriptMgr.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/data/ScriptNames.hpp"

namespace YimMenu::Scripts
{
	rage::scrThread* FindScriptThread(joaat_t hash)
	{
		for (auto& thread : *Pointers.ScriptThreads)
		{
			if (thread && thread->m_Context.m_ThreadId && thread->m_Context.m_ScriptHash == hash)
			{
				return thread;
			}
		}

		return nullptr;
	}

	rage::scrProgram* FindScriptProgram(joaat_t hash)
	{
		for (int i = 0; i < 160; i++)
		{
			if (Pointers.ScriptPrograms[i] && Pointers.ScriptPrograms[i]->m_NameHash == hash)
			{
				return Pointers.ScriptPrograms[i];
			}
		}

		return nullptr;
	}

	void RunAsScript(rage::scrThread* thread, std::function<void()> callback)
	{
		auto og_thread = *Pointers.CurrentScriptThread;
		auto og_running_in_scrthread  = rage::tlsContext::Get()->m_RunningScript;
		*Pointers.CurrentScriptThread = thread;
		rage::tlsContext::Get()->m_RunningScript = true; // required to evade thread checks
		callback();
		rage::tlsContext::Get()->m_RunningScript = og_running_in_scrthread;
		*Pointers.CurrentScriptThread = og_thread;
	}

	void SendScriptEvent(uint64_t* data, int count, int metadataIndex, int bits)
	{
		if (auto thread = FindScriptThread("net_main_offline"_J))
		{
			RunAsScript(thread, [data, count, metadataIndex, &bits] {
				SCRIPTS::TRIGGER_SCRIPT_EVENT(1, data, count, metadataIndex, &bits);
			});
		}
	}

	const char* GetScriptName(joaat_t hash)
	{
		if (UsingMPScripts())
		{
			for (int i = 0; i < Data::g_MpScriptNames.size(); i++)
			{
				if (Data::g_MpScriptNames[i].first == hash)
					return Data::g_MpScriptNames[i].second;
			}
		}
		else
		{
			for (int i = 0; i < Data::g_SpScriptNames.size(); i++)
			{
				if (Data::g_SpScriptNames[i].first == hash)
					return Data::g_SpScriptNames[i].second;
			}
		}

		return "Unknown";
	}

	void ForceScriptHost(rage::scrThread* thread)
	{
		auto handler = reinterpret_cast<rage::scriptHandlerNetComponent*>(thread->m_HandlerNetComponent);
		handler->DoHostMigration(Pointers.NetworkPlayerMgr->m_LocalPlayer, 0xFFFF, true);
	}

	bool UsingMPScripts()
	{
		return Pointers.ScriptGlobals[14] != nullptr; // TODO
	}

	ScriptIdentifier GetScriptIdentifier(rage::scrThread* thread)
	{
		return ScriptIdentifier(thread ? thread->m_Context.m_ScriptHash : 0, UsingMPScripts());
	}

	bool RequestScript(joaat_t script)
	{
		if (!SCRIPTS::HAS_SCRIPT_WITH_NAME_HASH_LOADED(script))
		{
			SCRIPTS::REQUEST_SCRIPT_WITH_NAME_HASH(script);
			for (int i = 0; i < 150 && !SCRIPTS::HAS_SCRIPT_WITH_NAME_HASH_LOADED(script); i++)
				ScriptMgr::Yield(10ms);
		}

		if (SCRIPTS::HAS_SCRIPT_WITH_NAME_HASH_LOADED(script))
			return true;
		
		return false;
	}
}