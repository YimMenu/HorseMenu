#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_GOOGLE_ANALYTICS__GOOGLE_ANALYTICS_PUSH_PAGE(sol::stack_object pageName)
	{
		GOOGLE_ANALYTICS::_GOOGLE_ANALYTICS_PUSH_PAGE(pageName.is<const char*>() ? pageName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_GOOGLE_ANALYTICS__GOOGLE_ANALYTICS_POP_PAGE(sol::stack_object pageName)
	{
		GOOGLE_ANALYTICS::_GOOGLE_ANALYTICS_POP_PAGE(pageName.is<const char*>() ? pageName.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_GOOGLE_ANALYTICS__GOOGLE_ANALYTICS_START_EVENT(sol::stack_object eventCategory, sol::stack_object eventAction, sol::stack_object eventLabel, int eventValue)
	{
		auto retval = (bool)GOOGLE_ANALYTICS::_GOOGLE_ANALYTICS_START_EVENT(eventCategory.is<const char*>() ? eventCategory.as<const char*>() : nullptr, eventAction.is<const char*>() ? eventAction.as<const char*>() : nullptr, eventLabel.is<const char*>() ? eventLabel.as<const char*>() : nullptr, eventValue);
		return retval;
	}

	static bool LUA_NATIVE_GOOGLE_ANALYTICS__GOOGLE_ANALYTICS_END_EVENT()
	{
		auto retval = (bool)GOOGLE_ANALYTICS::_GOOGLE_ANALYTICS_END_EVENT();
		return retval;
	}

	void RegisterNatives_GOOGLE_ANALYTICS(sol::state& L)
	{
		auto GOOGLE_ANALYTICS = L["GOOGLE_ANALYTICS"].get_or_create<sol::table>();
		GOOGLE_ANALYTICS.set_function("_GOOGLE_ANALYTICS_PUSH_PAGE", LUA_NATIVE_GOOGLE_ANALYTICS__GOOGLE_ANALYTICS_PUSH_PAGE);
		GOOGLE_ANALYTICS.set_function("_GOOGLE_ANALYTICS_POP_PAGE", LUA_NATIVE_GOOGLE_ANALYTICS__GOOGLE_ANALYTICS_POP_PAGE);
		GOOGLE_ANALYTICS.set_function("_GOOGLE_ANALYTICS_START_EVENT", LUA_NATIVE_GOOGLE_ANALYTICS__GOOGLE_ANALYTICS_START_EVENT);
		GOOGLE_ANALYTICS.set_function("_GOOGLE_ANALYTICS_END_EVENT", LUA_NATIVE_GOOGLE_ANALYTICS__GOOGLE_ANALYTICS_END_EVENT);
	}
}
