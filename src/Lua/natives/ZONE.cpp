#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static Hash LUA_NATIVE_ZONE__GET_MAP_ZONE_AT_COORDS(float x, float y, float z, int type)
	{
		auto retval = ZONE::_GET_MAP_ZONE_AT_COORDS(x, y, z, type);
		return retval;
	}

	static Hash LUA_NATIVE_ZONE__GET_WATER_MAP_ZONE_AT_COORDS(float x, float y, float z)
	{
		auto retval = ZONE::_GET_WATER_MAP_ZONE_AT_COORDS(x, y, z);
		return retval;
	}

	void RegisterNatives_ZONE(sol::state& L)
	{
		auto ZONE = L["ZONE"].get_or_create<sol::table>();
		ZONE.set_function("_GET_MAP_ZONE_AT_COORDS", LUA_NATIVE_ZONE__GET_MAP_ZONE_AT_COORDS);
		ZONE.set_function("_GET_WATER_MAP_ZONE_AT_COORDS", LUA_NATIVE_ZONE__GET_WATER_MAP_ZONE_AT_COORDS);
	}
}
