#include "Scripts.hpp"
#include <script/scrThread.hpp>
#include "game/pointers/Pointers.hpp"

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
		*Pointers.CurrentScriptThread = thread;
		callback();
		*Pointers.CurrentScriptThread = og_thread;
	}
}