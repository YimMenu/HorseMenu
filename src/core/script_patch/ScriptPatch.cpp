#include "ScriptPatch.hpp"

#include "ScriptData.hpp"

namespace YimMenu
{

	ScriptPatch::ScriptPatch(joaat_t script, std::string name, const SimplePattern pattern, int32_t offset, std::vector<uint8_t> patch, bool* enable_bool) :
	    m_Script(script),
	    m_Name(name),
	    m_Pattern(pattern),
	    m_Offset(offset),
	    m_Patch(std::move(patch)),
	    m_Bool(enable_bool),
	    m_Ip(0)
	{
	}

	uint8_t* ScriptPatch::GetCodeAddress(ScriptData* data, uint32_t index)
	{
		return &data->m_ByteCode[index >> 14][index & 0x3FFF];
	}

	const std::optional<uint32_t> ScriptPatch::GetCodeLocationByPattern(ScriptData* data, const SimplePattern& pattern)
	{
		uint32_t code_size = data->m_CodeSize;
		for (uint32_t i = 0; i < (code_size - pattern.m_Bytes.size()); i++)
		{
			for (uint32_t j = 0; j < pattern.m_Bytes.size(); j++)
			{
				if (pattern.m_Bytes[j].has_value())
				{
					if (pattern.m_Bytes[j] != *GetCodeAddress(data, i + j))
						goto incorrect;
				}

				return i;
			incorrect:
				continue;
			}
		}

		return std::nullopt;
	}

	void ScriptPatch::Enable(ScriptData* data)
	{
		std::memcpy(GetCodeAddress(data, m_Ip), m_Patch.data(), m_Patch.size());
	}

	void ScriptPatch::Disable(ScriptData* data)
	{
		std::memcpy(GetCodeAddress(data, m_Ip), m_Original.data(), m_Original.size());
	}

	void ScriptPatch::Update(ScriptData* data)
	{
		if (m_Ip == 0)
		{
			auto result = GetCodeLocationByPattern(data, m_Pattern);
			if (!result.has_value())
			{
				LOG(FATAL) << "Failed to find pattern for script patch: " << m_Name;
			}
			m_Ip = result.value() + m_Offset;
			for (int i = 0; i < m_Patch.size(); i++)
			{
				m_Original.push_back(*GetCodeAddress(data, m_Ip + 1));
			}

			if (!m_Bool || *m_Bool)
				Enable(data);
			else
				Disable(data);
		}
	}
}