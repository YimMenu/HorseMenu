#pragma once
#include "core/memory/Pattern.hpp"
#include "util/Joaat.hpp"

namespace YimMenu
{
	class ScriptFunction
	{
		joaat_t m_Hash;
		SimplePattern m_Pattern;
		std::optional<std::int32_t> m_Pc;

		std::optional<std::int32_t> GetPC();
	public:
		ScriptFunction(joaat_t hash, SimplePattern pattern);

		// TODO: add static_call and return value support

		void Call(const std::vector<uint64_t>& args);
		
		template<typename... Args>
		void operator()(Args... args)
		{
			std::vector<uint64_t> params;
			(params.push_back(static_cast<std::uint64_t>(args)), ...);
			Call(params);
		}
	};
}