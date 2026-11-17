#pragma once

#include "../LuaLibrary.hpp"
#include "../LuaModule.hpp"


namespace Terminus::LuaJIT
{
	class LuaLogLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	private:
		static inline std::string LuaTostr(const sol::state_view& L, sol::variadic_args args)
		{
			auto moduleName = L["whodis"].get<std::string>();
			std::string output;
			for (auto arg : args)
			{
				if (!output.empty())
					output += '\t';

				sol::protected_function tostring = L["tostring"];
				sol::protected_function_result r = tostring(arg);
				output += r.valid() ? r.get<std::string>() : "";
			}
			return "[" + moduleName + "/main.lua]: " + output;
		}

		static inline std::string LuaFmt(const sol::state_view& L, const std::string& fmt, sol::variadic_args args)
		{
			auto moduleName = L["whodis"].get<std::string>();
			return "[" + moduleName + "/main.lua]: " + LuaStringFormat(L, fmt, args);
		}

	public:
		void Register(sol::state& L) override
		{
			L["print"] = [](sol::this_state s, sol::variadic_args args) {
				sol::state_view lua(s);
				LOG(INFO) << LuaTostr(lua, args);
			};

			/*@terminus.function printf Prints a formatted message. Formatting works the same as [string.format](lua://string.format)
			* param msg<string> Message.
			* param ...<any> Optional format arguments.
			@*/
			L["printf"] = [](sol::this_state s, const std::string& fmt, sol::variadic_args args) {
				sol::state_view lua(s);
				LOG(INFO) << LuaFmt(lua, fmt, args);
			};

			/*@terminus.table log
			* description
				Provides functions to output text to console and log file.

			* function info Logs an information message. Arguments are the same as [print](lua://print)
			* param ...<any>
			
			* function warning Logs a warning message. Arguments are the same as [print](lua://print)
			* param ...<any>
			
			* function debug Logs a debug message. Arguments are the same as [print](lua://print)
			* param ...<any>
			
			* function error Logs an error message. Arguments are the same as [print](lua://print)
			* param ...<any>

			* function finfo Logs a formatted information message. Formatting works the same as [string.format](lua://string.format)
			* param msg<string> Message.
			* param ...<any> Optional format arguments.
			
			* function fwarning Logs a formatted warning message. Formatting works the same as [string.format](lua://string.format)
			* param msg<string> Message.
			* param ...<any> Optional format arguments.
			
			* function fdebug Logs a formatted debug message. Formatting works the same as [string.format](lua://string.format)
			* param msg<string> Message.
			* param ...<any> Optional format arguments.
			
			* function ferror Logs a formatted error message. Formatting works the same as [string.format](lua://string.format)
			* param msg<string> Message.
			* param ...<any> Optional format arguments.
			@*/
			auto log = L["log"].get_or_create<sol::table>();

			log["info"] = [](sol::this_state s, sol::variadic_args args) {
				sol::state_view lua(s);
				LOG(INFO) << LuaTostr(lua, args);
			};

			log["warning"] = [&](sol::variadic_args args) {
				LOG(WARNING) << LuaTostr(L, args);
			};

			log["debug"] = [](sol::this_state s, sol::variadic_args args) {
				sol::state_view lua(s);
				LOG(INFO) << LuaTostr(lua, args);
			};

			log["error"] = [](sol::this_state s, sol::variadic_args args) {
				sol::state_view lua(s);
				LOG(INFO) << LuaTostr(lua, args);
			};

			log["finfo"] = [](sol::this_state s, const std::string& fmt, sol::variadic_args args) {
				sol::state_view lua(s);
				LOG(INFO) << LuaFmt(lua, fmt, args);
			};

			log["fwarning"] = [](sol::this_state s, const std::string& fmt, sol::variadic_args args) {
				sol::state_view lua(s);
				LOG(INFO) << LuaFmt(lua, fmt, args);
			};

			log["fdebug"] = [](sol::this_state s, const std::string& fmt, sol::variadic_args args) {
				sol::state_view lua(s);
				LOG(INFO) << LuaFmt(lua, fmt, args);
			};

			log["ferror"] = [](sol::this_state s, const std::string& fmt, sol::variadic_args args) {
				sol::state_view lua(s);
				LOG(INFO) << LuaFmt(lua, fmt, args);
			};
		}
	};

	LuaLogLib _LuaLogLib;
}
