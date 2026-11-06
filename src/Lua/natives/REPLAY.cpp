#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static bool LUA_NATIVE_REPLAY_REPLAY_SYSTEM_HAS_REQUESTED_A_SCRIPT_CLEANUP()
	{
		auto retval = (bool)REPLAY::REPLAY_SYSTEM_HAS_REQUESTED_A_SCRIPT_CLEANUP();
		return retval;
	}

	static void LUA_NATIVE_REPLAY_SET_SCRIPTS_HAVE_CLEANED_UP_FOR_REPLAY_SYSTEM()
	{
		REPLAY::SET_SCRIPTS_HAVE_CLEANED_UP_FOR_REPLAY_SYSTEM();
	}

	static bool LUA_NATIVE_REPLAY_OPEN_VIDEO_EDITOR()
	{
		auto retval = (bool)REPLAY::OPEN_VIDEO_EDITOR();
		return retval;
	}

	static bool LUA_NATIVE_REPLAY_CLOSE_VIDEO_EDITOR(Any p0)
	{
		auto retval = (bool)REPLAY::CLOSE_VIDEO_EDITOR(p0);
		return retval;
	}

	static bool LUA_NATIVE_REPLAY_IS_VIDEO_EDITOR_RUNNING()
	{
		auto retval = (bool)REPLAY::IS_VIDEO_EDITOR_RUNNING();
		return retval;
	}

	void RegisterNatives_REPLAY(sol::state& L)
	{
		auto REPLAY = L["REPLAY"].get_or_create<sol::table>();
		REPLAY.set_function("REPLAY_SYSTEM_HAS_REQUESTED_A_SCRIPT_CLEANUP", LUA_NATIVE_REPLAY_REPLAY_SYSTEM_HAS_REQUESTED_A_SCRIPT_CLEANUP);
		REPLAY.set_function("SET_SCRIPTS_HAVE_CLEANED_UP_FOR_REPLAY_SYSTEM", LUA_NATIVE_REPLAY_SET_SCRIPTS_HAVE_CLEANED_UP_FOR_REPLAY_SYSTEM);
		REPLAY.set_function("OPEN_VIDEO_EDITOR", LUA_NATIVE_REPLAY_OPEN_VIDEO_EDITOR);
		REPLAY.set_function("CLOSE_VIDEO_EDITOR", LUA_NATIVE_REPLAY_CLOSE_VIDEO_EDITOR);
		REPLAY.set_function("IS_VIDEO_EDITOR_RUNNING", LUA_NATIVE_REPLAY_IS_VIDEO_EDITOR_RUNNING);
	}
}
