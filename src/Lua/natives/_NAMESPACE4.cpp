#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE__NAMESPACE4__REPORT_PLAYER_BAD_SPORT_BEHAVIOR(uintptr_t gamerHandle, int badSportBehaviorType)
	{
		_NAMESPACE4::_REPORT_PLAYER_BAD_SPORT_BEHAVIOR((Any*)gamerHandle, badSportBehaviorType);
	}

	void RegisterNatives__NAMESPACE4(sol::state& L)
	{
		auto _NAMESPACE4 = L["_NAMESPACE4"].get_or_create<sol::table>();
		_NAMESPACE4.set_function("_REPORT_PLAYER_BAD_SPORT_BEHAVIOR", LUA_NATIVE__NAMESPACE4__REPORT_PLAYER_BAD_SPORT_BEHAVIOR);
	}
}
