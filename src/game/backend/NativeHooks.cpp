#include "NativeHooks.hpp"

#include "game/rdr/invoker/Invoker.hpp"

#include <script/scrProgram.hpp>
#include <script/scrThread.hpp>


namespace YimMenu
{
	NativeHooks::Program::Program(rage::scrProgram* program) :
	    m_Program(program),
	    m_Hook(std::make_unique<VMTHook>("rage::scrProgram", program, 3))
	{
		m_Hook->Hook(0, ScrProgram_Dtor);
		m_Hook->Enable();
		m_OrigHandlers = new rage::scrNativeHandler[program->m_NativeCount];
		memcpy(m_OrigHandlers, program->m_NativeEntrypoints, program->m_NativeCount * sizeof(rage::scrNativeHandler));
	}

	void NativeHooks::Program::Apply(Hook hook)
	{
		auto old_native      = NativeInvoker::GetNativeHandler(hook.m_Index);
		auto old_native_addr = m_Program->GetAddressOfNativeEntrypoint(old_native);
		if (old_native_addr)
			*old_native_addr = hook.m_Replacement;
	}

	void NativeHooks::Program::Cleanup()
	{
		memcpy(m_Program->m_NativeEntrypoints, m_OrigHandlers, m_Program->m_NativeCount * sizeof(rage::scrNativeHandler));
		delete[] m_OrigHandlers;
		m_Hook->Disable();
	}

	void NativeHooks::Program::ScrProgram_Dtor(rage::scrProgram* _this, bool free_mem)
	{
		NativeHooks::UnregisterProgram(_this);
		(**reinterpret_cast<decltype(&NativeHooks::Program::ScrProgram_Dtor)**>(_this))(_this, free_mem);
	}

	NativeHooks::NativeHooks() :
	    m_RegisteredPrograms(),
	    m_RegisteredHooks()
	{
		for (int i = 0; i < 160; i++)
		{
			if (Pointers.ScriptPrograms[i] != nullptr)
				RegisterProgram(Pointers.ScriptPrograms[i]);

		}
		m_RegisteredHooks.emplace(ALL_SCRIPTS, std::vector<Hook>());
	}

	void NativeHooks::AddHookImpl(joaat_t script, NativeIndex index, rage::scrNativeHandler hook)
	{
		if (!g_Running)
			return;

		if (auto it = m_RegisteredHooks.find(script); it != m_RegisteredHooks.end())
		{
			it->second.push_back(Hook(index, hook));
		}
		else
		{
			std::vector<Hook> hooks = {Hook(index, hook)};
			m_RegisteredHooks.emplace(script, hooks);
		}

		for (auto& [scp, program] : m_RegisteredPrograms)
		{
			if (scp->m_NameHash == script || script == ALL_SCRIPTS)
			{
				program->Apply(Hook(index, hook));
			}
		}
	}

	void NativeHooks::RegisterProgramImpl(rage::scrProgram* program)
	{
		if (!g_Running)
			return;

		if (m_RegisteredPrograms.contains(program))
		{
			LOG(FATAL) << "We've already registered " << HEX(program->m_NameHash) << ". This is bad!";
			return;
		}

		auto t = new Program(program);
		m_RegisteredPrograms.emplace(program, std::move(t));

		auto& pgrm = m_RegisteredPrograms[program];

		if (auto it = m_RegisteredHooks.find(program->m_NameHash); it != m_RegisteredHooks.end())
		{
			for (auto& hook : it->second)
			{
				pgrm->Apply(hook);
			}
		}

		for (auto& hook : m_RegisteredHooks.at(ALL_SCRIPTS))
		{
			pgrm->Apply(hook);
		}
	}

	void NativeHooks::UnregisterProgramImpl(rage::scrProgram* program)
	{
		if (auto it = m_RegisteredPrograms.find(program); it != m_RegisteredPrograms.end())
		{
			it->second->Cleanup();
			m_RegisteredPrograms.erase(it);
		}
		else
		{
			LOG(FATAL) << "Cannot find program " << HEX(program->m_NameHash) << " in registry. This is bad!";
		}
	}

	void NativeHooks::DestroyImpl()
	{
		for (auto& [_, program] : m_RegisteredPrograms)
			program->Cleanup();
	}
}