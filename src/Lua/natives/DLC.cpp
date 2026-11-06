#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static bool LUA_NATIVE_DLC_IS_DLC_PRESENT(Hash NameHash)
	{
		auto retval = (bool)DLC::IS_DLC_PRESENT(NameHash);
		return retval;
	}

	static bool LUA_NATIVE_DLC_GET_IS_LOADING_SCREEN_ACTIVE()
	{
		auto retval = (bool)DLC::GET_IS_LOADING_SCREEN_ACTIVE();
		return retval;
	}

	static bool LUA_NATIVE_DLC__GET_SPECIAL_EDITION_CORE_STATS_BONUS_ENABLED()
	{
		auto retval = (bool)DLC::_GET_SPECIAL_EDITION_CORE_STATS_BONUS_ENABLED();
		return retval;
	}

	static bool LUA_NATIVE_DLC__GET_SPECIAL_EDITION_CASH_CAMP_BONUS_ENABLED()
	{
		auto retval = (bool)DLC::_GET_SPECIAL_EDITION_CASH_CAMP_BONUS_ENABLED();
		return retval;
	}

	void RegisterNatives_DLC(sol::state& L)
	{
		auto DLC = L["DLC"].get_or_create<sol::table>();
		DLC.set_function("IS_DLC_PRESENT", LUA_NATIVE_DLC_IS_DLC_PRESENT);
		DLC.set_function("GET_IS_LOADING_SCREEN_ACTIVE", LUA_NATIVE_DLC_GET_IS_LOADING_SCREEN_ACTIVE);
		DLC.set_function("_GET_SPECIAL_EDITION_CORE_STATS_BONUS_ENABLED", LUA_NATIVE_DLC__GET_SPECIAL_EDITION_CORE_STATS_BONUS_ENABLED);
		DLC.set_function("_GET_SPECIAL_EDITION_CASH_CAMP_BONUS_ENABLED", LUA_NATIVE_DLC__GET_SPECIAL_EDITION_CASH_CAMP_BONUS_ENABLED);
	}
}
