#pragma once

#include "../LuaLibrary.hpp"
#include "../LuaModule.hpp"
#include "game/rdr/Scripts.hpp"


namespace Terminus::LuaJIT
{
	class LuaScrLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	private:
		static inline void RegisterTask(sol::protected_function fn, sol::optional<int> delay, sol::this_state s)
		{
			if (auto mod = GetModuleFromLuaState(s.lua_state(), "Failed to run script! Module pointer is null."))
			{
				int millis = std::max(0, delay.value_or(0));
				mod->RegisterTask(fn, static_cast<std::chrono::milliseconds>(millis));
			}
		}

	public:
		void Register(sol::state& L) override
		{
			/*@terminus.table Script

			* function RunInFiber Executes a callback in a fiber context
			* param callback<function> The callback to execute

			* function RunInFiberAfterDelay Executes a callback in a fiber context after a delay
			* param callback<function> The callback to execute
			* param delay<integer> Delay in milliseconds.
			
			* function Sleep
			* param ms<integer> Sleep time in milliseconds
			
			* function Yield
			* param ms<integer?> Optional yield time in milliseconds
			
			* function IsActive
			* param scrName<string> Name of the game script to check. Ex: `"aberdeenpigfarm"`
			* return boolean state
			
			* function RunAsScript
			* param scrName<string> Name of the game script. Ex: `"net_camp_manager"`
			* param fn<function> Callback to execute once in the script's thread context.
			@*/
			auto scrTable = L["Script"].get_or_create<sol::table>();

			// TODO: give each task a fiber slice
			scrTable["RunInFiber"] = [](sol::protected_function fn, sol::this_state state) {
				RegisterTask(fn, 0, state);
			};

			scrTable["RunInFiberAfterDelay"] = [](sol::protected_function fn, int delayMs, sol::this_state state) {
				RegisterTask(fn, delayMs, state);
			};

			scrTable["Sleep"] = sol::yielding([](int millis) {
				return millis;
			});

			scrTable["Yield"] = sol::yielding([](sol::optional<int> millis) {
				return millis.value_or(0);
			});

			scrTable["IsActive"] = [](const std::string& name) {
				return Scripts::FindScriptThread(Joaat(name)) != nullptr;
			};

			scrTable["RunAsScript"] = [](const std::string& name, sol::protected_function fn) {
				if (auto scr = Scripts::FindScriptThread(Joaat(name)))
					Scripts::RunAsScript(scr, fn);
				else
					LOG(FATAL) << "Can not run as script '" << name << "'. Thread not found!";
			};
		}
	};

	LuaScrLib _LuaScrLib;
}
