#pragma once
#include "core/memory/Pattern.hpp"
#include "util/Joaat.hpp"

namespace YimMenu
{
	struct ScriptData;

	class ScriptPatch
	{
		joaat_t m_Script;
		const SimplePattern m_Pattern;
		std::string m_Name;
		int32_t m_Offset;
		std::vector<uint8_t> m_Patch;
		std::vector<uint8_t> m_Original;
		bool* m_Bool;
		int32_t m_Ip;

		static uint8_t* GetCodeAddress(ScriptData* data, uint32_t index);
		static const std::optional<uint32_t> GetCodeLocationByPattern(ScriptData* data, const SimplePattern& pattern);

	public:
		void Enable(ScriptData* data);
		void Disable(ScriptData* data);

		inline joaat_t GetScript()
		{
			return m_Script;
		}

		ScriptPatch(joaat_t script, std::string name, const SimplePattern pattern, int32_t offset, std::vector<uint8_t> patch, bool* enable_bool);
		void Update(ScriptData* data);
	};
}