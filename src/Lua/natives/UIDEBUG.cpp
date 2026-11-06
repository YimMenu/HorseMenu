#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_UIDEBUG__BG_DISPLAY_TEXT(sol::stack_object text, float x, float y)
	{
		UIDEBUG::_BG_DISPLAY_TEXT(text.is<const char*>() ? text.as<const char*>() : nullptr, x, y);
	}

	static void LUA_NATIVE_UIDEBUG__BG_SET_TEXT_SCALE(float scaleX, float scaleY)
	{
		UIDEBUG::_BG_SET_TEXT_SCALE(scaleX, scaleY);
	}

	static void LUA_NATIVE_UIDEBUG__BG_SET_TEXT_COLOR(int red, int green, int blue, int alpha)
	{
		UIDEBUG::_BG_SET_TEXT_COLOR(red, green, blue, alpha);
	}

	void RegisterNatives_UIDEBUG(sol::state& L)
	{
		auto UIDEBUG = L["UIDEBUG"].get_or_create<sol::table>();
		UIDEBUG.set_function("_BG_DISPLAY_TEXT", LUA_NATIVE_UIDEBUG__BG_DISPLAY_TEXT);
		UIDEBUG.set_function("_BG_SET_TEXT_SCALE", LUA_NATIVE_UIDEBUG__BG_SET_TEXT_SCALE);
		UIDEBUG.set_function("_BG_SET_TEXT_COLOR", LUA_NATIVE_UIDEBUG__BG_SET_TEXT_COLOR);
	}
}
