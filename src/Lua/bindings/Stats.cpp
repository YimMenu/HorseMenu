#pragma once

#include "game/rdr/Stats.hpp"

#include "../LuaLibrary.hpp"
#include "../LuaModule.hpp"
#include "util/Joaat.hpp"


namespace Terminus::LuaJIT
{
	class LuaStatsLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	public:
		void Register(sol::state& L) override
		{
			/*@terminus.table Stats

			* function IsValid Returns whether the stat is valid.
			* param baseName<string>
			* param permutationName<string>
			* return boolean

			* function IsValid Returns whether the stat is valid.
			* param baseHash<integer> JOAAT hash
			* param permutationHash<integer> JOAAT hash
			* return boolean

			* function GetInt
			* param baseName<string>
			* param permutationName<string>
			* return integer
			
			* function GetInt
			* param baseHash<integer> JOAAT hash
			* param permutationHash<integer> JOAAT hash
			* return integer

			* function GetFloat
			* param baseName<string>
			* param permutationName<string>
			* return number
			
			* function GetFloat
			* param baseHash<integer> JOAAT hash
			* param permutationHash<integer> JOAAT hash
			* return number

			* function GetBool
			* param baseName<string>
			* param permutationName<string>
			* return boolean
			
			* function GetBool
			* param baseHash<integer> JOAAT hash
			* param permutationHash<integer> JOAAT hash
			* return boolean

			* function SetInt
			* param baseName<string>
			* param permutationName<string>
			* param value<integer>
			* param save<boolean?> Whether to save changes. Defaults to true.
			* return boolean success

			* function SetInt
			* param baseHash<integer> JOAAT hash
			* param permutationHash<integer> JOAAT hash
			* param value<integer>
			* param save<boolean?> Whether to save changes. Defaults to true.
			* return boolean success

			* function SetFloat
			* param baseName<string>
			* param permutationName<string>
			* param value<number>
			* param save<boolean?> Whether to save changes. Defaults to true.
			* return boolean success

			* function SetFloat
			* param baseHash<integer> JOAAT hash
			* param permutationHash<integer> JOAAT hash
			* param value<number>
			* param save<boolean?> Whether to save changes. Defaults to true.
			* return boolean success

			* function SetBool
			* param baseName<string>
			* param permutationName<string>
			* param value<boolean>
			* param save<boolean?> Whether to save changes. Defaults to true.
			* return boolean success

			* function SetBool
			* param baseHash<integer> JOAAT hash
			* param permutationHash<integer> JOAAT hash
			* param value<boolean>
			* param save<boolean?> Whether to save changes. Defaults to true.
			* return boolean success

			* function SetString
			* param baseName<string>
			* param permutationName<string>
			* param value<string>
			* param save<boolean?> Whether to save changes. Defaults to true.
			* return boolean success

			* function SetString
			* param baseHash<integer> JOAAT hash
			* param permutationHash<integer> JOAAT hash
			* param value<string>
			* param save<boolean?> Whether to save changes. Defaults to true.
			* return boolean success

			* function DecrementInt
			* param baseName<string>
			* param permutationName<string>
			* param value<integer>

			* function DecrementInt
			* param baseHash<integer> JOAAT hash
			* param permutationHash<integer> JOAAT hash
			* param value<integer>

			* function IncrementInt
			* param baseName<string>
			* param permutationName<string>
			* param value<integer>

			* function IncrementInt
			* param baseHash<integer> JOAAT hash
			* param permutationHash<integer> JOAAT hash
			* param value<integer>

			* function IncrementFloat
			* param baseName<string>
			* param permutationName<string>
			* param value<number>

			* function IncrementFloat
			* param baseHash<integer> JOAAT hash
			* param permutationHash<integer> JOAAT hash
			* param value<number>
			
			@*/
			auto stats = L["Stats"].get_or_create<sol::table>();

			stats["IsValid"] = sol::overload(
			    [](const std::string& base, const std::string& perm) {
				    auto id = Stats::MakeId(base, perm);
				    return Stats::IsValid(id);
			    },
			    [](joaat_t base, joaat_t perm) {
				    auto id = Stats::MakeId(base, perm);
				    return Stats::IsValid(id);
			    });

			stats["GetInt"] = sol::overload(
			    [](const std::string& base, const std::string& perm) {
				    auto id = Stats::MakeId(base, perm);
				    return Stats::GetInt(id);
			    },
			    [](joaat_t base, joaat_t perm) {
				    auto id = Stats::MakeId(base, perm);
				    return Stats::GetInt(id);
			    });

			stats["GetFloat"] = sol::overload(
			    [](const std::string& base, const std::string& perm) {
				    auto id = Stats::MakeId(base, perm);
				    return Stats::GetFloat(id);
			    },
			    [](joaat_t base, joaat_t perm) {
				    auto id = Stats::MakeId(base, perm);
				    return Stats::GetFloat(id);
			    });

			stats["GetBool"] = sol::overload(
			    [](const std::string& base, const std::string& perm) {
				    auto id = Stats::MakeId(base, perm);
				    return Stats::GetBool(id);
			    },
			    [](joaat_t base, joaat_t perm) {
				    auto id = Stats::MakeId(base, perm);
				    return Stats::GetBool(id);
			    });

			stats["SetInt"] = sol::overload(
			    [](const std::string& base, const std::string& perm, int value, sol::optional<bool> save) {
				    auto id = Stats::MakeId(base, perm);
				    return Stats::SetInt(id, value, save.value_or(true));
			    },
			    [](joaat_t base, joaat_t perm, int value, sol::optional<bool> save) {
				    auto id = Stats::MakeId(base, perm);
				    return Stats::SetInt(id, value, save.value_or(true));
			    });

			stats["SetFloat"] = sol::overload(
			    [](const std::string& base, const std::string& perm, float value, sol::optional<bool> save) {
				    auto id = Stats::MakeId(base, perm);
				    return Stats::SetFloat(id, value, save.value_or(true));
			    },
			    [](joaat_t base, joaat_t perm, float value, sol::optional<bool> save) {
				    auto id = Stats::MakeId(base, perm);
				    return Stats::SetFloat(id, value, save.value_or(true));
			    });

			stats["SetBool"] = sol::overload(
			    [](const std::string& base, const std::string& perm, bool value, sol::optional<bool> save) {
				    auto id = Stats::MakeId(base, perm);
				    return Stats::SetBool(id, value, save.value_or(true));
			    },
			    [](joaat_t base, joaat_t perm, bool value, sol::optional<bool> save) {
				    auto id = Stats::MakeId(base, perm);
				    return Stats::SetBool(id, value, save.value_or(true));
			    });

			stats["SetString"] = sol::overload(
			    [](const std::string& base, const std::string& perm, const std::string& value, sol::optional<bool> save) {
				    auto id = Stats::MakeId(base, perm);
				    return Stats::SetString(id, value, save.value_or(true));
			    },
			    [](joaat_t base, joaat_t perm, const std::string& value, sol::optional<bool> save) {
				    auto id = Stats::MakeId(base, perm);
				    return Stats::SetString(id, value, save.value_or(true));
			    });

			stats["DecrementInt"] = sol::overload(
			    [](const std::string& base, const std::string& perm, int value) {
				    auto id = Stats::MakeId(base, perm);
				    Stats::DecrementInt(id, value);
			    },
			    [](joaat_t base, joaat_t perm, int value) {
				    auto id = Stats::MakeId(base, perm);
				    Stats::DecrementInt(id, value);
			    });

			stats["IncrementInt"] = sol::overload(
			    [](const std::string& base, const std::string& perm, int value) {
				    auto id = Stats::MakeId(base, perm);
				    Stats::IncrementInt(id, value);
			    },
			    [](joaat_t base, joaat_t perm, int value) {
				    auto id = Stats::MakeId(base, perm);
				    Stats::IncrementInt(id, value);
			    });

			stats["IncrementFloat"] = sol::overload(
			    [](const std::string& base, const std::string& perm, float value) {
				    auto id = Stats::MakeId(base, perm);
				    Stats::IncrementFloat(id, value);
			    },
			    [](joaat_t base, joaat_t perm, float value) {
				    auto id = Stats::MakeId(base, perm);
				    Stats::IncrementFloat(id, value);
			    });
		}
	};

	LuaStatsLib _LuaStatsLib;
}
