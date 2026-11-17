#pragma once

#include "../LuaLibrary.hpp"
#include "../LuaModule.hpp"
#include "game/rdr/Scripts.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/backend/Self.hpp"


namespace Terminus::LuaJIT
{
	class LuaNetworkLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	public:
		void Register(sol::state& L) override
		{
			/*@terminus.table Network
			* description
				Provides general network utilities.

			* function IsSessionStarted
			* return boolean

			* function ForceScriptHost
			* param scr<string|integer> Script name or hash

			* function TriggerScriptEvent Undocumented and untested. Do not use.
			* param bitset<integer>
			* param args<{ [integer]: integer }> An array of int args
			@*/
			auto network = L["Network"].get_or_create<sol::table>();

			network["IsSessionStarted"] = []() {
				return Pointers.IsSessionStarted ? *Pointers.IsSessionStarted : false;
			};

			network["ForceScriptHost"] = sol::overload(
				[](const std::string& scrName) {
					if (auto scr = Scripts::FindScriptThread(Joaat(scrName)))
						Scripts::ForceScriptHost(scr);
				},
				[](int hash) {
					if (auto scr = Scripts::FindScriptThread(static_cast<joaat_t>(hash)))
						Scripts::ForceScriptHost(scr);
				}
			);

			network["TriggerScriptEvent"] = [](int bitset, sol::table _args) {
				std::vector<int32_t> args{};
				for (auto&& [i, v] : _args)
				{
					if (!v.is<int>())
						continue;
					
					args.push_back(v.as<int32_t>());
				}

				if (args.size() >= 1)
					args[1] = Self::GetPed().GetPlayer();

				std::vector<std::int64_t> args64;
				for (auto arg : args)
					args64.push_back(static_cast<uint32_t>(arg));

				Scripts::SendScriptEvent(reinterpret_cast<uint64_t*>(args64.data()), args64.size(), args[0], bitset);
			};
		}
	};

	LuaNetworkLib _LuaNetworkLib;
}
