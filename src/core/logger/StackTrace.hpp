#pragma once

namespace YimMenu
{
	class StackTrace
	{
	public:
		StackTrace();
		virtual ~StackTrace();

		const std::vector<uint64_t>& GetFramePointers();
		void NewStackTrace(EXCEPTION_POINTERS* exception_info);
		std::string GetString() const;

		friend std::ostream& operator<<(std::ostream& os, const StackTrace& st);
		friend std::ostream& operator<<(std::ostream& os, const StackTrace* st);

	private:
		struct ModuleInfo
		{
			ModuleInfo(std::filesystem::path path, void* base) :
			    m_Path(path),
			    m_Base(reinterpret_cast<uintptr_t>(base))
			{
				const auto dos_header = reinterpret_cast<IMAGE_DOS_HEADER*>(base);
				const auto nt_header  = reinterpret_cast<IMAGE_NT_HEADERS*>(m_Base + dos_header->e_lfanew);

				m_Size = nt_header->OptionalHeader.SizeOfCode;
			}

			std::filesystem::path m_Path;
			uintptr_t m_Base;
			size_t m_Size;
		};

	private:
		void DumpModuleInfo();
		void DumpRegisters();
		void DumpStacktrace();
		void DumpCPPExceptionInfo();
		void GrabStacktrace();
		const ModuleInfo* GetModuleByAddress(uint64_t addr) const;

		static std::string ExceptionCodeToString(const DWORD code);

	private:
		EXCEPTION_POINTERS* m_ExceptionInfo;

		std::stringstream m_Dump;
		std::vector<uint64_t> m_FramePointers;

		inline static std::vector<ModuleInfo> m_Modules;
	};

	inline std::ostream& operator<<(std::ostream& os, const StackTrace& st)
	{
		os << st.GetString();
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const StackTrace* st)
	{
		os << st->GetString();
		return os;
	}
}