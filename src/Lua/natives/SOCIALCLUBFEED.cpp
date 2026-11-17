#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static int LUA_NATIVE_SOCIALCLUBFEED__SC_FEED_SUBMIT_PRESET_MESSAGE(int type, int subType)
	{
		auto retval = SOCIALCLUBFEED::_SC_FEED_SUBMIT_PRESET_MESSAGE(type, subType);
		return retval;
	}

	static bool LUA_NATIVE_SOCIALCLUBFEED_SC_FEED_HUB_HAS_NEW_DATA()
	{
		auto retval = (bool)SOCIALCLUBFEED::SC_FEED_HUB_HAS_NEW_DATA();
		return retval;
	}

	void RegisterNatives_SOCIALCLUBFEED(sol::state& L)
	{
		auto SOCIALCLUBFEED = L["SOCIALCLUBFEED"].get_or_create<sol::table>();
		SOCIALCLUBFEED.set_function("_SC_FEED_SUBMIT_PRESET_MESSAGE", LUA_NATIVE_SOCIALCLUBFEED__SC_FEED_SUBMIT_PRESET_MESSAGE);
		SOCIALCLUBFEED.set_function("SC_FEED_HUB_HAS_NEW_DATA", LUA_NATIVE_SOCIALCLUBFEED_SC_FEED_HUB_HAS_NEW_DATA);
	}
}
