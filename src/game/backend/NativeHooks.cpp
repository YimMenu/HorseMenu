#include "NativeHooks.hpp"
#include <script/scrThread.hpp>
#include "game/rdr/invoker/Invoker.hpp"

// TODO: move this to classes

namespace rage
{
	class pgBase
	{
	public:
		virtual ~pgBase()         = default;
		virtual int return_zero() = 0;
		virtual void error()      = 0;

		void* unk_0000; // 0x0000
	};                  //Size: 0x0008
	static_assert(sizeof(pgBase) == 0x10);

	class scrProgram : public pgBase
	{
	public:
		std::uint8_t** m_CodeBlocks;           // 0x10
		std::uint32_t m_Hash;                  // 0x18
		std::uint32_t m_CodeSize;              // 0x1C
		std::uint32_t m_ArgCount;              // 0x20
		std::uint32_t m_LocalCount;            // 0x24
		std::uint32_t m_GlobalCount;           // 0x28
		std::uint32_t m_NativeCount;           // 0x2C
		void* m_LocalData;                     // 0x30
		void** m_GlobalData;                   // 0x38
		scrNativeHandler* m_NativeEntrypoints; // 0x40
		std::uint32_t m_ProcCount;             // 0x48
		char pad_004C[4];                      // 0x4C
		const char** m_ProcNames;              // 0x50
		std::uint32_t m_NameHash;              // 0x58
		std::uint32_t m_RefCount;              // 0x5C
		const char* m_Name;                    // 0x60
		const char** m_StringsData;            // 0x68
		std::uint32_t m_StringsCount;          // 0x70
		char m_Breakpoints[0x0C];              // 0x74 This is an atMap, which we don't have the class for ATM.

		bool is_valid() const
		{
			return m_CodeSize != 0;
		}

		std::uint32_t GetNumCodePages() const
		{
			return (m_CodeSize + 0x3FFF) >> 14;
		}

		std::uint32_t GetCodePageSize(std::uint32_t page) const
		{
			auto num = GetNumCodePages();
			if (page < num)
			{
				if (page == num - 1)
					return m_CodeSize & 0x3FFF;
				return 0x4000;
			}

			return 0;
		}

		std::uint32_t GetFullCodeSize() const
		{
			auto numPages = GetNumCodePages();
			if (!numPages)
				return 0;
			if (numPages == 1)
				--numPages;

			return (numPages * 0x4000) + (m_CodeSize & 0x3FFF);
		}

		std::uint8_t* GetCodePage(std::uint32_t page) const
		{
			return m_CodeBlocks[page];
		}

		std::uint8_t* GetCodeAddress(std::uint32_t index) const
		{
			if (index < m_CodeSize)
				return &m_CodeBlocks[index >> 14][index & 0x3FFF];

			return nullptr;
		}

		const char* GetString(std::uint32_t index) const
		{
			if (index < m_StringsCount)
				return &m_StringsData[index >> 14][index & 0x3FFF];

			return nullptr;
		}

		scrNativeHandler* GetAddressOfNativeEntrypoint(scrNativeHandler entrypoint)
		{
			for (std::uint32_t i = 0; i < m_NativeCount; ++i)
			{
				if (m_NativeEntrypoints[i] == entrypoint)
				{
					return m_NativeEntrypoints + i;
				}
			}

			return nullptr;
		}
	};
	static_assert(sizeof(scrProgram) == 0x80);
}

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
		auto old_native = NativeInvoker::GetNativeHandler(hook.m_Index);
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
		// TODO: hook existing programs
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
		else
		{
			LOG(INFO) << HEX(program->m_NameHash);
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