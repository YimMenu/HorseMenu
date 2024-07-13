#pragma once

namespace YimMenu
{
	class ScriptData
	{
		uint32_t m_NumPages;

	public:
		uint32_t m_CodeSize;
		uint8_t** m_ByteCode;

		ScriptData(uint32_t code_size, uint8_t** bytecode, uint32_t num_pages) :
		    m_CodeSize(code_size),
		    m_ByteCode(bytecode),
		    m_NumPages(num_pages)
		{
		}

		ScriptData(const ScriptData& that)            = delete;
		ScriptData& operator=(const ScriptData& that) = delete;

		~ScriptData()
		{
			for (auto i = 0u; i < m_NumPages; i++)
			{
				delete[] m_ByteCode[i];
			}

			delete[] m_ByteCode;
			m_ByteCode = nullptr;
		}
	};
}