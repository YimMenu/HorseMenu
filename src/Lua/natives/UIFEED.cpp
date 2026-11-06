#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static int LUA_NATIVE_UIFEED__UI_FEED_POST_HELP_TEXT(uintptr_t p0, uintptr_t p1, bool p2)
	{
		auto retval = UIFEED::_UI_FEED_POST_HELP_TEXT((Any*)p0, (Any*)p1, p2);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__UI_FEED_POST_LOCATION_SHARD(uintptr_t duration, uintptr_t data, bool p2, bool p3)
	{
		auto retval = UIFEED::_UI_FEED_POST_LOCATION_SHARD((Any*)duration, (Any*)data, p2, p3);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__UI_FEED_POST_OBJECTIVE(uintptr_t p0, uintptr_t p1, bool p2)
	{
		auto retval = UIFEED::_UI_FEED_POST_OBJECTIVE((Any*)p0, (Any*)p1, p2);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__UI_FEED_POST_FEED_TICKER(uintptr_t p0, uintptr_t p1, bool p2)
	{
		auto retval = UIFEED::_UI_FEED_POST_FEED_TICKER((Any*)p0, (Any*)p1, p2);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__UI_FEED_POST_SAMPLE_TOAST(uintptr_t p0, uintptr_t p1, bool p2, bool p3)
	{
		auto retval = UIFEED::_UI_FEED_POST_SAMPLE_TOAST((Any*)p0, (Any*)p1, p2, p3);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__0xAFF5BE9BA496CE40(uintptr_t p0, uintptr_t p1, bool p2, bool p3, Hash collectableCategory)
	{
		auto retval = UIFEED::_0xAFF5BE9BA496CE40((Any*)p0, (Any*)p1, p2, p3, collectableCategory);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__UI_FEED_POST_SAMPLE_TOAST_WITH_APP_LINK(uintptr_t p0, uintptr_t p1, bool p2, bool p3, bool p4)
	{
		auto retval = UIFEED::_UI_FEED_POST_SAMPLE_TOAST_WITH_APP_LINK((Any*)p0, (Any*)p1, p2, p3, p4);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__UI_FEED_POST_SAMPLE_NOTIFICATION(uintptr_t p0, uintptr_t p1, int p2, int p3)
	{
		auto retval = UIFEED::_UI_FEED_POST_SAMPLE_NOTIFICATION((Any*)p0, (Any*)p1, p2, p3);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__UI_FEED_POST_RANKUP_TOAST(uintptr_t p0, uintptr_t p1, int p2, int p3)
	{
		auto retval = UIFEED::_UI_FEED_POST_RANKUP_TOAST((Any*)p0, (Any*)p1, p2, p3);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__0x18D6869FBFFEC0F8(uintptr_t p0, uintptr_t p1, bool p2, bool p3)
	{
		auto retval = UIFEED::_0x18D6869FBFFEC0F8((Any*)p0, (Any*)p1, p2, p3);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__UI_FEED_POST_SAMPLE_TOAST_RIGHT(uintptr_t p0, uintptr_t p1, bool p2)
	{
		auto retval = UIFEED::_UI_FEED_POST_SAMPLE_TOAST_RIGHT((Any*)p0, (Any*)p1, p2);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__UI_FEED_POST_MISSION_NAME(uintptr_t p0, uintptr_t p1, bool p2)
	{
		auto retval = UIFEED::_UI_FEED_POST_MISSION_NAME((Any*)p0, (Any*)p1, p2);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__UI_FEED_POST_RETICLE_MESSAGE(uintptr_t p0, uintptr_t p1, bool p2)
	{
		auto retval = UIFEED::_UI_FEED_POST_RETICLE_MESSAGE((Any*)p0, (Any*)p1, p2);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__UI_FEED_POST_ONE_TEXT_SHARD(uintptr_t p0, uintptr_t p1, bool p2)
	{
		auto retval = UIFEED::_UI_FEED_POST_ONE_TEXT_SHARD((Any*)p0, (Any*)p1, p2);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__UI_FEED_POST_TWO_TEXT_SHARD(uintptr_t p0, uintptr_t p1, bool p2, bool p3)
	{
		auto retval = UIFEED::_UI_FEED_POST_TWO_TEXT_SHARD((Any*)p0, (Any*)p1, p2, p3);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__UI_FEED_POST_THREE_TEXT_SHARD(uintptr_t p0, uintptr_t p1, bool p2, bool p3, bool p4)
	{
		auto retval = UIFEED::_UI_FEED_POST_THREE_TEXT_SHARD((Any*)p0, (Any*)p1, p2, p3, p4);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__UI_FEED_POST_GAME_UPDATE_SHARD(uintptr_t p0, uintptr_t p1, bool p2)
	{
		auto retval = UIFEED::_UI_FEED_POST_GAME_UPDATE_SHARD((Any*)p0, (Any*)p1, p2);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__UI_FEED_POST_VOICE_CHAT_FEED(uintptr_t p0, uintptr_t p1, bool p2)
	{
		auto retval = UIFEED::_UI_FEED_POST_VOICE_CHAT_FEED((Any*)p0, (Any*)p1, p2);
		return retval;
	}

	static void LUA_NATIVE_UIFEED_UI_FEED_CLEAR_CHANNEL(int feedChannel, bool p1, bool p2)
	{
		UIFEED::UI_FEED_CLEAR_CHANNEL(feedChannel, p1, p2);
	}

	static void LUA_NATIVE_UIFEED__UI_FEED_CLEAR_ALL_CHANNELS()
	{
		UIFEED::_UI_FEED_CLEAR_ALL_CHANNELS();
	}

	static void LUA_NATIVE_UIFEED__UI_FEED_CLEAR_HELP_TEXT_FEED(int feedMessage, bool p1)
	{
		UIFEED::_UI_FEED_CLEAR_HELP_TEXT_FEED(feedMessage, p1);
	}

	static void LUA_NATIVE_UIFEED__0x6D85126F6CCF02C9(int feedChannel, int p1, bool p2)
	{
		UIFEED::_0x6D85126F6CCF02C9(feedChannel, p1, p2);
	}

	static int LUA_NATIVE_UIFEED__0x4E88A65968A55C78(uintptr_t p0, bool p1)
	{
		auto retval = UIFEED::_0x4E88A65968A55C78((Any*)p0, p1);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__0x0FD07141AD048AAE(uintptr_t p0, bool p1)
	{
		auto retval = UIFEED::_0x0FD07141AD048AAE((Any*)p0, p1);
		return retval;
	}

	static int LUA_NATIVE_UIFEED__UI_FEED_GET_MESSAGE_STATE(int feedMessage)
	{
		auto retval = UIFEED::_UI_FEED_GET_MESSAGE_STATE(feedMessage);
		return retval;
	}

	static int LUA_NATIVE_UIFEED_UI_FEED_GET_CURRENT_MESSAGE(int feedChannel)
	{
		auto retval = UIFEED::UI_FEED_GET_CURRENT_MESSAGE(feedChannel);
		return retval;
	}

	static bool LUA_NATIVE_UIFEED__0xB7223B91CD6B7E07(int feedChannel)
	{
		auto retval = (bool)UIFEED::_0xB7223B91CD6B7E07(feedChannel);
		return retval;
	}

	void RegisterNatives_UIFEED(sol::state& L)
	{
		auto UIFEED = L["UIFEED"].get_or_create<sol::table>();
		UIFEED.set_function("_UI_FEED_POST_HELP_TEXT", LUA_NATIVE_UIFEED__UI_FEED_POST_HELP_TEXT);
		UIFEED.set_function("_UI_FEED_POST_LOCATION_SHARD", LUA_NATIVE_UIFEED__UI_FEED_POST_LOCATION_SHARD);
		UIFEED.set_function("_UI_FEED_POST_OBJECTIVE", LUA_NATIVE_UIFEED__UI_FEED_POST_OBJECTIVE);
		UIFEED.set_function("_UI_FEED_POST_FEED_TICKER", LUA_NATIVE_UIFEED__UI_FEED_POST_FEED_TICKER);
		UIFEED.set_function("_UI_FEED_POST_SAMPLE_TOAST", LUA_NATIVE_UIFEED__UI_FEED_POST_SAMPLE_TOAST);
		UIFEED.set_function("_0xAFF5BE9BA496CE40", LUA_NATIVE_UIFEED__0xAFF5BE9BA496CE40);
		UIFEED.set_function("_UI_FEED_POST_SAMPLE_TOAST_WITH_APP_LINK", LUA_NATIVE_UIFEED__UI_FEED_POST_SAMPLE_TOAST_WITH_APP_LINK);
		UIFEED.set_function("_UI_FEED_POST_SAMPLE_NOTIFICATION", LUA_NATIVE_UIFEED__UI_FEED_POST_SAMPLE_NOTIFICATION);
		UIFEED.set_function("_UI_FEED_POST_RANKUP_TOAST", LUA_NATIVE_UIFEED__UI_FEED_POST_RANKUP_TOAST);
		UIFEED.set_function("_0x18D6869FBFFEC0F8", LUA_NATIVE_UIFEED__0x18D6869FBFFEC0F8);
		UIFEED.set_function("_UI_FEED_POST_SAMPLE_TOAST_RIGHT", LUA_NATIVE_UIFEED__UI_FEED_POST_SAMPLE_TOAST_RIGHT);
		UIFEED.set_function("_UI_FEED_POST_MISSION_NAME", LUA_NATIVE_UIFEED__UI_FEED_POST_MISSION_NAME);
		UIFEED.set_function("_UI_FEED_POST_RETICLE_MESSAGE", LUA_NATIVE_UIFEED__UI_FEED_POST_RETICLE_MESSAGE);
		UIFEED.set_function("_UI_FEED_POST_ONE_TEXT_SHARD", LUA_NATIVE_UIFEED__UI_FEED_POST_ONE_TEXT_SHARD);
		UIFEED.set_function("_UI_FEED_POST_TWO_TEXT_SHARD", LUA_NATIVE_UIFEED__UI_FEED_POST_TWO_TEXT_SHARD);
		UIFEED.set_function("_UI_FEED_POST_THREE_TEXT_SHARD", LUA_NATIVE_UIFEED__UI_FEED_POST_THREE_TEXT_SHARD);
		UIFEED.set_function("_UI_FEED_POST_GAME_UPDATE_SHARD", LUA_NATIVE_UIFEED__UI_FEED_POST_GAME_UPDATE_SHARD);
		UIFEED.set_function("_UI_FEED_POST_VOICE_CHAT_FEED", LUA_NATIVE_UIFEED__UI_FEED_POST_VOICE_CHAT_FEED);
		UIFEED.set_function("UI_FEED_CLEAR_CHANNEL", LUA_NATIVE_UIFEED_UI_FEED_CLEAR_CHANNEL);
		UIFEED.set_function("_UI_FEED_CLEAR_ALL_CHANNELS", LUA_NATIVE_UIFEED__UI_FEED_CLEAR_ALL_CHANNELS);
		UIFEED.set_function("_UI_FEED_CLEAR_HELP_TEXT_FEED", LUA_NATIVE_UIFEED__UI_FEED_CLEAR_HELP_TEXT_FEED);
		UIFEED.set_function("_0x6D85126F6CCF02C9", LUA_NATIVE_UIFEED__0x6D85126F6CCF02C9);
		UIFEED.set_function("_0x4E88A65968A55C78", LUA_NATIVE_UIFEED__0x4E88A65968A55C78);
		UIFEED.set_function("_0x0FD07141AD048AAE", LUA_NATIVE_UIFEED__0x0FD07141AD048AAE);
		UIFEED.set_function("_UI_FEED_GET_MESSAGE_STATE", LUA_NATIVE_UIFEED__UI_FEED_GET_MESSAGE_STATE);
		UIFEED.set_function("UI_FEED_GET_CURRENT_MESSAGE", LUA_NATIVE_UIFEED_UI_FEED_GET_CURRENT_MESSAGE);
		UIFEED.set_function("_0xB7223B91CD6B7E07", LUA_NATIVE_UIFEED__0xB7223B91CD6B7E07);
	}
}
