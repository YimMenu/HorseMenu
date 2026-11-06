#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static const char* LUA_NATIVE_UIPINNING__UIPINNING_GET_TOOLTIP_TEXT(Hash hash)
	{
		auto retval = UIPINNING::_UIPINNING_GET_TOOLTIP_TEXT(hash);
		return retval;
	}

	void RegisterNatives_UIPINNING(sol::state& L)
	{
		auto UIPINNING = L["UIPINNING"].get_or_create<sol::table>();
		UIPINNING.set_function("_UIPINNING_GET_TOOLTIP_TEXT", LUA_NATIVE_UIPINNING__UIPINNING_GET_TOOLTIP_TEXT);
	}
}
