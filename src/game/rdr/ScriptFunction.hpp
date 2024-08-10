#pragma once
#include "core/memory/Pattern.hpp"
#include "util/Joaat.hpp"

#include <type_traits>

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

		void RunScript(rage::scrThread* thread, rage::scrProgram* program, const std::vector<uint64_t>& args, void* returnValue, uint32_t returnSize);

		void CallImpl(const std::vector<uint64_t>& args, void* returnValue = 0, uint32_t returnSize = 0);

		void StaticCallImpl(const std::vector<uint64_t>& args, void* returnValue = 0, uint32_t returnSize = 0);

	public:
		ScriptFunction(joaat_t hash, SimplePattern pattern);

		template<typename Ret = void, typename... Args>
		Ret StaticCall(Args... args)
		{
			std::vector<uint64_t> params;
			(params.push_back(*reinterpret_cast<std::uint64_t*>(&args)), ...);

			if constexpr (!std::is_same_v<Ret, void>)
			{
				Ret returnValue;
				StaticCallImpl(params, &returnValue, sizeof(returnValue));
				return returnValue;
			}
			else
			{
				StaticCallImpl(params);
			}
		}

		template<typename Ret = void, typename... Args>
		Ret Call(Args... args)
		{
			std::vector<uint64_t> params;
			(params.push_back(*reinterpret_cast<std::uint64_t*>(&args)), ...);

			if constexpr (!std::is_same_v<Ret, void>)
			{
				Ret returnValue;
				CallImpl(params, &returnValue, sizeof(returnValue));
				return returnValue;
			}
			else
			{
				CallImpl(params);
			}
		}

		template<typename... Args>
		void operator()(Args... args)
		{
			std::vector<uint64_t> params;
			(params.push_back(*reinterpret_cast<std::uint64_t*>(&args)), ...);
			CallImpl(params);
		}
	};

	namespace ScriptFunctions
	{
		static inline ScriptFunction GiveItemDatabaseAward("interactive_campfire"_J, "22 05 24");
		static inline ScriptFunction GiveLootTableAward("interactive_campfire"_J, "22 02 14 00 00 2F");
		static inline ScriptFunction TriggerMoonshineProduction("net_moonshine_manager"_J, "22 00 15");
	}
}