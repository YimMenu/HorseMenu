#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static Any LUA_NATIVE_DEBUG__0xACF9CB705BEFA8CB()
	{
		auto retval = DEBUG::_0xACF9CB705BEFA8CB();
		return retval;
	}

	static Any LUA_NATIVE_DEBUG__0xA8D970D8A72640A6()
	{
		auto retval = DEBUG::_0xA8D970D8A72640A6();
		return retval;
	}

	static const char* LUA_NATIVE_DEBUG_GET_GAME_VERSION_NAME()
	{
		auto retval = DEBUG::GET_GAME_VERSION_NAME();
		return retval;
	}

	void RegisterNatives_DEBUG(sol::state& L)
	{
		auto DEBUG = L["DEBUG"].get_or_create<sol::table>();
		DEBUG.set_function("_0xACF9CB705BEFA8CB", LUA_NATIVE_DEBUG__0xACF9CB705BEFA8CB);
		DEBUG.set_function("_0xA8D970D8A72640A6", LUA_NATIVE_DEBUG__0xA8D970D8A72640A6);
		DEBUG.set_function("GET_GAME_VERSION_NAME", LUA_NATIVE_DEBUG_GET_GAME_VERSION_NAME);
	}
}
