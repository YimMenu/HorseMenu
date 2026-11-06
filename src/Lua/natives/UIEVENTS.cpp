#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static bool LUA_NATIVE_UIEVENTS_EVENTS_UI_IS_PENDING(Hash hash)
	{
		auto retval = (bool)UIEVENTS::EVENTS_UI_IS_PENDING(hash);
		return retval;
	}

	static bool LUA_NATIVE_UIEVENTS_EVENTS_UI_GET_MESSAGE(Hash hash, uintptr_t eventData)
	{
		auto retval = (bool)UIEVENTS::EVENTS_UI_GET_MESSAGE(hash, (Any*)eventData);
		return retval;
	}

	static bool LUA_NATIVE_UIEVENTS_EVENTS_UI_PEEK_MESSAGE(Hash hash, uintptr_t eventData)
	{
		auto retval = (bool)UIEVENTS::EVENTS_UI_PEEK_MESSAGE(hash, (Any*)eventData);
		return retval;
	}

	static void LUA_NATIVE_UIEVENTS_EVENTS_UI_POP_MESSAGE(Hash hash)
	{
		UIEVENTS::EVENTS_UI_POP_MESSAGE(hash);
	}

	void RegisterNatives_UIEVENTS(sol::state& L)
	{
		auto UIEVENTS = L["UIEVENTS"].get_or_create<sol::table>();
		UIEVENTS.set_function("EVENTS_UI_IS_PENDING", LUA_NATIVE_UIEVENTS_EVENTS_UI_IS_PENDING);
		UIEVENTS.set_function("EVENTS_UI_GET_MESSAGE", LUA_NATIVE_UIEVENTS_EVENTS_UI_GET_MESSAGE);
		UIEVENTS.set_function("EVENTS_UI_PEEK_MESSAGE", LUA_NATIVE_UIEVENTS_EVENTS_UI_PEEK_MESSAGE);
		UIEVENTS.set_function("EVENTS_UI_POP_MESSAGE", LUA_NATIVE_UIEVENTS_EVENTS_UI_POP_MESSAGE);
	}
}
