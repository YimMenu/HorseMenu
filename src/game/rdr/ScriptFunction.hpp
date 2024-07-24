#pragma once
#include "core/memory/Pattern.hpp"
#include "util/Joaat.hpp"

namespace rage
{
	class scrThread;
	class scrProgram;
}

namespace YimMenu
{
	class ScriptFunction
	{
	private:
		joaat_t m_Hash;
		SimplePattern m_Pattern;
		std::optional<std::int32_t> m_Pc;

		std::optional<std::int32_t> GetPC();

		void RunScript(rage::scrThread* thread, rage::scrProgram* program, const std::vector<uint64_t>& args);

		void Call(const std::vector<uint64_t>& args);

		void StaticCall(const std::vector<uint64_t>& args);
	public:
		ScriptFunction(joaat_t hash, SimplePattern pattern);

		// TODO: return value support

		template<typename... Args>
		void StaticCall(Args... args)
		{
			std::vector<uint64_t> params;
			(params.push_back(static_cast<std::uint64_t>(args)), ...);
			StaticCall(params);
		}
		
		template<typename... Args>
		void operator()(Args... args)
		{
			std::vector<uint64_t> params;
			(params.push_back(static_cast<std::uint64_t>(args)), ...);
			Call(params);
		}
	};

	namespace ScriptFunctions
	{
		static inline ScriptFunction GiveItemDatabaseAward("interactive_campfire"_J, "22 05 24");
		static inline ScriptFunction GiveLootTableAward("interactive_campfire"_J, "22 02 14 00 00 2F");
	}
}