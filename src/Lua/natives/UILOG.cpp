#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static bool LUA_NATIVE_UILOG__UILOG_IS_ENTRY_REGISTERED(int p0, Hash p1)
	{
		auto retval = (bool)UILOG::_UILOG_IS_ENTRY_REGISTERED(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_UILOG__UILOG_ADD_ENTRY_HASH(int p0, int p1, float x, float y, float z, Hash p5, Hash p6, Any p7)
	{
		UILOG::_UILOG_ADD_ENTRY_HASH(p0, p1, x, y, z, p5, p6, p7);
	}

	static void LUA_NATIVE_UILOG__UILOG_ADD_ITEM_TO_TASK_LIST(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7)
	{
		UILOG::_UILOG_ADD_ITEM_TO_TASK_LIST(p0, p1, p2, p3, p4, p5, p6, p7);
	}

	static void LUA_NATIVE_UILOG__UILOG_SET_ENTRY_ICON_TEXTURE(int p0, Hash p1, Hash icon, Hash iconDictionary)
	{
		UILOG::_UILOG_SET_ENTRY_ICON_TEXTURE(p0, p1, icon, iconDictionary);
	}

	static void LUA_NATIVE_UILOG__UILOG_SET_ENTRY_BRIEF_TEXTURE(int p0, Hash p1, Hash texture, Hash textureDictionary)
	{
		UILOG::_UILOG_SET_ENTRY_BRIEF_TEXTURE(p0, p1, texture, textureDictionary);
	}

	static void LUA_NATIVE_UILOG__UILOG_UPDATE_ENTRY_SUBHEADER(int p0, Hash p1, sol::stack_object p2)
	{
		UILOG::_UILOG_UPDATE_ENTRY_SUBHEADER(p0, p1, p2.is<const char*>() ? p2.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_UILOG__UILOG_SET_ENTRY_PINNED(int p0, Hash p1, bool p2)
	{
		UILOG::_UILOG_SET_ENTRY_PINNED(p0, p1, p2);
	}

	static void LUA_NATIVE_UILOG__UILOG_MARK_MISSION_COMPLETED(Hash p0)
	{
		UILOG::_UILOG_MARK_MISSION_COMPLETED(p0);
	}

	static void LUA_NATIVE_UILOG__UILOG_MARK_ENTRY_AVAILABILITY(int p0, Hash p1, int p2, sol::stack_object p3)
	{
		UILOG::_UILOG_MARK_ENTRY_AVAILABILITY(p0, p1, p2, p3.is<const char*>() ? p3.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_UILOG__UILOG_MARK_ALL_ENTRIES_AVAILABILITY(int p0, sol::stack_object p1)
	{
		UILOG::_UILOG_MARK_ALL_ENTRIES_AVAILABILITY(p0, p1.is<const char*>() ? p1.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_UILOG__UILOG_REMOVE_ENTRY(int p0, Hash p1)
	{
		UILOG::_UILOG_REMOVE_ENTRY(p0, p1);
	}

	static void LUA_NATIVE_UILOG__UILOG_SET_DISPLAY_COMPLETION_RATING(int logEntryType, Hash p1, bool p2)
	{
		UILOG::_UILOG_SET_DISPLAY_COMPLETION_RATING(logEntryType, p1, p2);
	}

	static void LUA_NATIVE_UILOG__0xA49D6D503E3EA847(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		UILOG::_0xA49D6D503E3EA847(p0, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_UILOG__0x763637F9B838B0A7(int p0, Hash p1, sol::stack_object p2)
	{
		UILOG::_0x763637F9B838B0A7(p0, p1, p2.is<const char*>() ? p2.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_UILOG__UILOG_CLEAR_ALL_ENTRIES()
	{
		UILOG::_UILOG_CLEAR_ALL_ENTRIES();
	}

	static void LUA_NATIVE_UILOG__UILOG_ADD_OR_UPDATE_OBJECTIVE(int p0, Hash p1, Hash p2, sol::stack_object p3, bool p4, bool p5, bool p6)
	{
		UILOG::_UILOG_ADD_OR_UPDATE_OBJECTIVE(p0, p1, p2, p3.is<const char*>() ? p3.as<const char*>() : nullptr, p4, p5, p6);
	}

	static void LUA_NATIVE_UILOG__0xA20398536B7F1134(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5)
	{
		UILOG::_0xA20398536B7F1134(p0, p1, p2, p3, p4, p5);
	}

	static void LUA_NATIVE_UILOG__UILOG_SET_CACHED_OBJECTIVE(sol::stack_object p0)
	{
		UILOG::_UILOG_SET_CACHED_OBJECTIVE(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_UILOG__UILOG_CLEAR_CACHED_OBJECTIVE()
	{
		UILOG::_UILOG_CLEAR_CACHED_OBJECTIVE();
	}

	static bool LUA_NATIVE_UILOG__UILOG_HAS_DISPLAYED_CACHED_OBJECTIVE()
	{
		auto retval = (bool)UILOG::_UILOG_HAS_DISPLAYED_CACHED_OBJECTIVE();
		return retval;
	}

	static void LUA_NATIVE_UILOG__UILOG_CLEAR_HAS_DISPLAYED_CACHED_OBJECTIVE()
	{
		UILOG::_UILOG_CLEAR_HAS_DISPLAYED_CACHED_OBJECTIVE();
	}

	static void LUA_NATIVE_UILOG__UILOG_SET_HAS_DISPLAYED_CACHED_OBJECTIVE()
	{
		UILOG::_UILOG_SET_HAS_DISPLAYED_CACHED_OBJECTIVE();
	}

	static const char* LUA_NATIVE_UILOG__UILOG_GET_CACHED_OBJECTIVE()
	{
		auto retval = UILOG::_UILOG_GET_CACHED_OBJECTIVE();
		return retval;
	}

	static void LUA_NATIVE_UILOG__UILOG_PRINT_CACHED_OBJECTIVE()
	{
		UILOG::_UILOG_PRINT_CACHED_OBJECTIVE();
	}

	static Any LUA_NATIVE_UILOG__UILOG_SET_PENDING_DETAILS_ID(int p0, Hash p1)
	{
		auto retval = UILOG::_UILOG_SET_PENDING_DETAILS_ID(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_UILOG__0x2A4765812202E671()
	{
		auto retval = UILOG::_0x2A4765812202E671();
		return retval;
	}

	static void LUA_NATIVE_UILOG__UILOG_ADD_TOTAL_TAKE_ENTRY(Hash p0, Hash p1, sol::stack_object p2, sol::stack_object p3, Hash p4)
	{
		UILOG::_UILOG_ADD_TOTAL_TAKE_ENTRY(p0, p1, p2.is<const char*>() ? p2.as<const char*>() : nullptr, p3.is<const char*>() ? p3.as<const char*>() : nullptr, p4);
	}

	static void LUA_NATIVE_UILOG__UILOG_SET_TOTAL_TAKE_SUMMARY(sol::stack_object p0, sol::stack_object p1)
	{
		UILOG::_UILOG_SET_TOTAL_TAKE_SUMMARY(p0.is<const char*>() ? p0.as<const char*>() : nullptr, p1.is<const char*>() ? p1.as<const char*>() : nullptr);
	}

	static int LUA_NATIVE_UILOG__UILOG_POST_NOTIFICATION(uintptr_t data)
	{
		auto retval = UILOG::_UILOG_POST_NOTIFICATION((Any*)data);
		return retval;
	}

	static void LUA_NATIVE_UILOG__0xDA0A30153FCC0FFD()
	{
		UILOG::_0xDA0A30153FCC0FFD();
	}

	void RegisterNatives_UILOG(sol::state& L)
	{
		auto UILOG = L["UILOG"].get_or_create<sol::table>();
		UILOG.set_function("_UILOG_IS_ENTRY_REGISTERED", LUA_NATIVE_UILOG__UILOG_IS_ENTRY_REGISTERED);
		UILOG.set_function("_UILOG_ADD_ENTRY_HASH", LUA_NATIVE_UILOG__UILOG_ADD_ENTRY_HASH);
		UILOG.set_function("_UILOG_ADD_ITEM_TO_TASK_LIST", LUA_NATIVE_UILOG__UILOG_ADD_ITEM_TO_TASK_LIST);
		UILOG.set_function("_UILOG_SET_ENTRY_ICON_TEXTURE", LUA_NATIVE_UILOG__UILOG_SET_ENTRY_ICON_TEXTURE);
		UILOG.set_function("_UILOG_SET_ENTRY_BRIEF_TEXTURE", LUA_NATIVE_UILOG__UILOG_SET_ENTRY_BRIEF_TEXTURE);
		UILOG.set_function("_UILOG_UPDATE_ENTRY_SUBHEADER", LUA_NATIVE_UILOG__UILOG_UPDATE_ENTRY_SUBHEADER);
		UILOG.set_function("_UILOG_SET_ENTRY_PINNED", LUA_NATIVE_UILOG__UILOG_SET_ENTRY_PINNED);
		UILOG.set_function("_UILOG_MARK_MISSION_COMPLETED", LUA_NATIVE_UILOG__UILOG_MARK_MISSION_COMPLETED);
		UILOG.set_function("_UILOG_MARK_ENTRY_AVAILABILITY", LUA_NATIVE_UILOG__UILOG_MARK_ENTRY_AVAILABILITY);
		UILOG.set_function("_UILOG_MARK_ALL_ENTRIES_AVAILABILITY", LUA_NATIVE_UILOG__UILOG_MARK_ALL_ENTRIES_AVAILABILITY);
		UILOG.set_function("_UILOG_REMOVE_ENTRY", LUA_NATIVE_UILOG__UILOG_REMOVE_ENTRY);
		UILOG.set_function("_UILOG_SET_DISPLAY_COMPLETION_RATING", LUA_NATIVE_UILOG__UILOG_SET_DISPLAY_COMPLETION_RATING);
		UILOG.set_function("_0xA49D6D503E3EA847", LUA_NATIVE_UILOG__0xA49D6D503E3EA847);
		UILOG.set_function("_0x763637F9B838B0A7", LUA_NATIVE_UILOG__0x763637F9B838B0A7);
		UILOG.set_function("_UILOG_CLEAR_ALL_ENTRIES", LUA_NATIVE_UILOG__UILOG_CLEAR_ALL_ENTRIES);
		UILOG.set_function("_UILOG_ADD_OR_UPDATE_OBJECTIVE", LUA_NATIVE_UILOG__UILOG_ADD_OR_UPDATE_OBJECTIVE);
		UILOG.set_function("_0xA20398536B7F1134", LUA_NATIVE_UILOG__0xA20398536B7F1134);
		UILOG.set_function("_UILOG_SET_CACHED_OBJECTIVE", LUA_NATIVE_UILOG__UILOG_SET_CACHED_OBJECTIVE);
		UILOG.set_function("_UILOG_CLEAR_CACHED_OBJECTIVE", LUA_NATIVE_UILOG__UILOG_CLEAR_CACHED_OBJECTIVE);
		UILOG.set_function("_UILOG_HAS_DISPLAYED_CACHED_OBJECTIVE", LUA_NATIVE_UILOG__UILOG_HAS_DISPLAYED_CACHED_OBJECTIVE);
		UILOG.set_function("_UILOG_CLEAR_HAS_DISPLAYED_CACHED_OBJECTIVE", LUA_NATIVE_UILOG__UILOG_CLEAR_HAS_DISPLAYED_CACHED_OBJECTIVE);
		UILOG.set_function("_UILOG_SET_HAS_DISPLAYED_CACHED_OBJECTIVE", LUA_NATIVE_UILOG__UILOG_SET_HAS_DISPLAYED_CACHED_OBJECTIVE);
		UILOG.set_function("_UILOG_GET_CACHED_OBJECTIVE", LUA_NATIVE_UILOG__UILOG_GET_CACHED_OBJECTIVE);
		UILOG.set_function("_UILOG_PRINT_CACHED_OBJECTIVE", LUA_NATIVE_UILOG__UILOG_PRINT_CACHED_OBJECTIVE);
		UILOG.set_function("_UILOG_SET_PENDING_DETAILS_ID", LUA_NATIVE_UILOG__UILOG_SET_PENDING_DETAILS_ID);
		UILOG.set_function("_0x2A4765812202E671", LUA_NATIVE_UILOG__0x2A4765812202E671);
		UILOG.set_function("_UILOG_ADD_TOTAL_TAKE_ENTRY", LUA_NATIVE_UILOG__UILOG_ADD_TOTAL_TAKE_ENTRY);
		UILOG.set_function("_UILOG_SET_TOTAL_TAKE_SUMMARY", LUA_NATIVE_UILOG__UILOG_SET_TOTAL_TAKE_SUMMARY);
		UILOG.set_function("_UILOG_POST_NOTIFICATION", LUA_NATIVE_UILOG__UILOG_POST_NOTIFICATION);
		UILOG.set_function("_0xDA0A30153FCC0FFD", LUA_NATIVE_UILOG__0xDA0A30153FCC0FFD);
	}
}
