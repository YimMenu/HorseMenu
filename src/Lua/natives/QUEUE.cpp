#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static bool LUA_NATIVE_QUEUE__EVENT_QUEUE_IS_EMPTY(Hash hash)
	{
		auto retval = (bool)QUEUE::_EVENT_QUEUE_IS_EMPTY(hash);
		return retval;
	}

	static void LUA_NATIVE_QUEUE__EVENT_QUEUE_POP(Hash hash)
	{
		QUEUE::_EVENT_QUEUE_POP(hash);
	}

	void RegisterNatives_QUEUE(sol::state& L)
	{
		auto QUEUE = L["QUEUE"].get_or_create<sol::table>();
		QUEUE.set_function("_EVENT_QUEUE_IS_EMPTY", LUA_NATIVE_QUEUE__EVENT_QUEUE_IS_EMPTY);
		QUEUE.set_function("_EVENT_QUEUE_POP", LUA_NATIVE_QUEUE__EVENT_QUEUE_POP);
	}
}
