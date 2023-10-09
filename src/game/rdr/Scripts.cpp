#include "Scripts.hpp"
#include <script/scrThread.hpp>
#include <rage/tlsContext.hpp>
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Natives.hpp"

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

	void SendScriptEvent(uint64_t* data, int count, int bits)
	{
		if (auto thread = FindScriptThread("net_main_offline"_J))
		{
			RunAsScript(thread, [data, count, &bits] {
				SCRIPTS::TRIGGER_SCRIPT_EVENT(1, data, count, 0, &bits);
			});
		}
	}
}