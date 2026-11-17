#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_RECORDING_REPLAY_PREVENT_RECORDING_THIS_FRAME()
	{
		RECORDING::REPLAY_PREVENT_RECORDING_THIS_FRAME();
	}

	void RegisterNatives_RECORDING(sol::state& L)
	{
		auto RECORDING = L["RECORDING"].get_or_create<sol::table>();
		RECORDING.set_function("REPLAY_PREVENT_RECORDING_THIS_FRAME", LUA_NATIVE_RECORDING_REPLAY_PREVENT_RECORDING_THIS_FRAME);
	}
}
