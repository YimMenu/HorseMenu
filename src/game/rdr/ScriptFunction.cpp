#include "ScriptFunction.hpp"
#include "Scripts.hpp"
#include "game/pointers/Pointers.hpp"
#include <script/scrProgram.hpp>
#include <script/scrThread.hpp>
#include <rage/tlsContext.hpp>

namespace YimMenu
{
	// TODO: code duplication
	static std::optional<int32_t> GetCodeLocationByPattern(rage::scrProgram* program, const SimplePattern& pattern)
	{
		uint32_t code_size = program->GetFullCodeSize();
		for (uint32_t i = 0; i < (code_size - pattern.m_Bytes.size()); i++)
		{
			for (uint32_t j = 0; j < pattern.m_Bytes.size(); j++)
			{
				if (pattern.m_Bytes[j].has_value())
				{
					int loc = i + j;
					if (pattern.m_Bytes[j] != *program->GetCodeAddress(loc))
						goto incorrect;
				}
			}

			return i;
		incorrect:
			continue;
		}

		return std::nullopt;
	}

	std::optional<std::int32_t> ScriptFunction::GetPC()
	{
		if (m_Pc.has_value())
			return m_Pc;

		auto program = Scripts::FindScriptProgram(m_Hash);
		
		if (program)
		{
			m_Pc = GetCodeLocationByPattern(program, m_Pattern);

			if (!m_Pc.has_value())
			{
				LOG(FATAL) << "Failed to find pattern";
			}
		}
		else
		{
			LOG(FATAL) << "Failed to find script program";
		}

		return m_Pc;
	}

	ScriptFunction::ScriptFunction(joaat_t hash, SimplePattern pattern) :
	    m_Hash(hash),
	    m_Pattern(pattern)
	{
	}

	void ScriptFunction::Call(const std::vector<uint64_t>& args)
	{
		auto pc = GetPC();
		auto thread = Scripts::FindScriptThread(m_Hash);
		auto program = Scripts::FindScriptProgram(m_Hash);

		const auto globals_initialized = std::vector<std::uint8_t>(50, true); // std::vector<bool> does weird stuff so we aren't using that

		if (!pc || !thread || !program)
			return;

		auto old_thread = *Pointers.CurrentScriptThread;
		auto old_thread_running = rage::tlsContext::Get()->m_RunningScript;
		auto stack = reinterpret_cast<uint64_t*>(thread->m_Stack);
		auto context = thread->m_Context;

		for (auto& arg : args)
			stack[context.m_StackPointer++] = arg;

		stack[context.m_StackPointer++] = 0; // return address
		context.m_ProgramCounter = pc.value();
		context.m_State = rage::eThreadState::idle;

		Pointers.ScriptVM(stack, Pointers.ScriptGlobals, reinterpret_cast<bool*>(const_cast<uint8_t*>(globals_initialized.data())), program, &context);

		rage::tlsContext::Get()->m_RunningScript = old_thread_running;
		*Pointers.CurrentScriptThread = old_thread;
	}
}