#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_PAD__SET_CONTROL_CONTEXT(int control, Hash context)
	{
		PAD::_SET_CONTROL_CONTEXT(control, context);
	}

	static Hash LUA_NATIVE_PAD__GET_CURRENT_CONTROL_CONTEXT(int control)
	{
		auto retval = PAD::_GET_CURRENT_CONTROL_CONTEXT(control);
		return retval;
	}

	static bool LUA_NATIVE_PAD__IS_CONTROL_ACTION_VALID(Hash action, int control)
	{
		auto retval = (bool)PAD::_IS_CONTROL_ACTION_VALID(action, control);
		return retval;
	}

	static bool LUA_NATIVE_PAD_IS_CONTROL_ENABLED(int control, Hash action)
	{
		auto retval = (bool)PAD::IS_CONTROL_ENABLED(control, action);
		return retval;
	}

	static bool LUA_NATIVE_PAD_IS_CONTROL_PRESSED(int control, Hash action)
	{
		auto retval = (bool)PAD::IS_CONTROL_PRESSED(control, action);
		return retval;
	}

	static bool LUA_NATIVE_PAD_IS_CONTROL_RELEASED(int control, Hash action)
	{
		auto retval = (bool)PAD::IS_CONTROL_RELEASED(control, action);
		return retval;
	}

	static bool LUA_NATIVE_PAD_IS_CONTROL_JUST_PRESSED(int control, Hash action)
	{
		auto retval = (bool)PAD::IS_CONTROL_JUST_PRESSED(control, action);
		return retval;
	}

	static bool LUA_NATIVE_PAD_IS_CONTROL_JUST_RELEASED(int control, Hash action)
	{
		auto retval = (bool)PAD::IS_CONTROL_JUST_RELEASED(control, action);
		return retval;
	}

	static int LUA_NATIVE_PAD_GET_CONTROL_VALUE(int control, Hash action)
	{
		auto retval = PAD::GET_CONTROL_VALUE(control, action);
		return retval;
	}

	static float LUA_NATIVE_PAD_GET_CONTROL_NORMAL(int control, Hash action)
	{
		auto retval = PAD::GET_CONTROL_NORMAL(control, action);
		return retval;
	}

	static float LUA_NATIVE_PAD_GET_CONTROL_UNBOUND_NORMAL(int control, Hash action)
	{
		auto retval = PAD::GET_CONTROL_UNBOUND_NORMAL(control, action);
		return retval;
	}

	static bool LUA_NATIVE_PAD_SET_CONTROL_VALUE_NEXT_FRAME(int control, Hash action, float value)
	{
		auto retval = (bool)PAD::SET_CONTROL_VALUE_NEXT_FRAME(control, action, value);
		return retval;
	}

	static bool LUA_NATIVE_PAD_IS_DISABLED_CONTROL_PRESSED(int control, Hash action)
	{
		auto retval = (bool)PAD::IS_DISABLED_CONTROL_PRESSED(control, action);
		return retval;
	}

	static bool LUA_NATIVE_PAD_IS_DISABLED_CONTROL_JUST_PRESSED(int control, Hash action)
	{
		auto retval = (bool)PAD::IS_DISABLED_CONTROL_JUST_PRESSED(control, action);
		return retval;
	}

	static bool LUA_NATIVE_PAD_IS_DISABLED_CONTROL_JUST_RELEASED(int control, Hash action)
	{
		auto retval = (bool)PAD::IS_DISABLED_CONTROL_JUST_RELEASED(control, action);
		return retval;
	}

	static float LUA_NATIVE_PAD_GET_DISABLED_CONTROL_NORMAL(int control, Hash action)
	{
		auto retval = PAD::GET_DISABLED_CONTROL_NORMAL(control, action);
		return retval;
	}

	static float LUA_NATIVE_PAD_GET_DISABLED_CONTROL_UNBOUND_NORMAL(int control, Hash action)
	{
		auto retval = PAD::GET_DISABLED_CONTROL_UNBOUND_NORMAL(control, action);
		return retval;
	}

	static int LUA_NATIVE_PAD_GET_CONTROL_HOW_LONG_AGO(int control)
	{
		auto retval = PAD::GET_CONTROL_HOW_LONG_AGO(control);
		return retval;
	}

	static int LUA_NATIVE_PAD__GET_DISABLED_CONTROL_HOW_LONG_AGO(int control)
	{
		auto retval = PAD::_GET_DISABLED_CONTROL_HOW_LONG_AGO(control);
		return retval;
	}

	static bool LUA_NATIVE_PAD_IS_USING_KEYBOARD_AND_MOUSE(int control)
	{
		auto retval = (bool)PAD::IS_USING_KEYBOARD_AND_MOUSE(control);
		return retval;
	}

	static Any LUA_NATIVE_PAD__0x43F35DDB2905D945(Any p0, Any p1)
	{
		auto retval = PAD::_0x43F35DDB2905D945(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_PAD__0xBD629C1C4F501C80(Any p0)
	{
		auto retval = PAD::_0xBD629C1C4F501C80(p0);
		return retval;
	}

	static bool LUA_NATIVE_PAD_HAVE_CONTROLS_CHANGED(int control)
	{
		auto retval = (bool)PAD::HAVE_CONTROLS_CHANGED(control);
		return retval;
	}

	static void LUA_NATIVE_PAD_SET_CONTROL_LIGHT_EFFECT_COLOR(int control, int red, int green, int blue)
	{
		PAD::SET_CONTROL_LIGHT_EFFECT_COLOR(control, red, green, blue);
	}

	static void LUA_NATIVE_PAD_CLEAR_CONTROL_LIGHT_EFFECT(int control)
	{
		PAD::CLEAR_CONTROL_LIGHT_EFFECT(control);
	}

	static void LUA_NATIVE_PAD_SET_CONTROL_LIGHT_EFFECT_FLASHING_COLOR(int control, int red, int green, int blue)
	{
		PAD::SET_CONTROL_LIGHT_EFFECT_FLASHING_COLOR(control, red, green, blue);
	}

	static void LUA_NATIVE_PAD_SET_CONTROL_SHAKE(int control, int Duration, int Frequency)
	{
		PAD::SET_CONTROL_SHAKE(control, Duration, Frequency);
	}

	static void LUA_NATIVE_PAD_SET_CONTROL_TRIGGER_SHAKE(int control, int leftDuration, int leftFrequency, int rightDuration, int rightFrequency)
	{
		PAD::SET_CONTROL_TRIGGER_SHAKE(control, leftDuration, leftFrequency, rightDuration, rightFrequency);
	}

	static void LUA_NATIVE_PAD_STOP_CONTROL_SHAKE(int control)
	{
		PAD::STOP_CONTROL_SHAKE(control);
	}

	static void LUA_NATIVE_PAD_SET_CONTROL_SHAKE_SUPPRESSED_ID(int control, int SupressId)
	{
		PAD::SET_CONTROL_SHAKE_SUPPRESSED_ID(control, SupressId);
	}

	static void LUA_NATIVE_PAD_CLEAR_CONTROL_SHAKE_SUPPRESSED_ID(int control)
	{
		PAD::CLEAR_CONTROL_SHAKE_SUPPRESSED_ID(control);
	}

	static bool LUA_NATIVE_PAD_IS_LOOK_INVERTED()
	{
		auto retval = (bool)PAD::IS_LOOK_INVERTED();
		return retval;
	}

	static void LUA_NATIVE_PAD_SET_INPUT_EXCLUSIVE(int control, Hash action)
	{
		PAD::SET_INPUT_EXCLUSIVE(control, action);
	}

	static void LUA_NATIVE_PAD_DISABLE_CONTROL_ACTION(int control, Hash action, bool disableRelatedActions)
	{
		PAD::DISABLE_CONTROL_ACTION(control, action, disableRelatedActions);
	}

	static void LUA_NATIVE_PAD_ENABLE_CONTROL_ACTION(int control, Hash action, bool enableRelatedActions)
	{
		PAD::ENABLE_CONTROL_ACTION(control, action, enableRelatedActions);
	}

	static void LUA_NATIVE_PAD_DISABLE_ALL_CONTROL_ACTIONS(int control)
	{
		PAD::DISABLE_ALL_CONTROL_ACTIONS(control);
	}

	static void LUA_NATIVE_PAD__0x5F217BC1190503D8(sol::stack_object rumbleCurve, float p1)
	{
		PAD::_0x5F217BC1190503D8(rumbleCurve.is<const char*>() ? rumbleCurve.as<const char*>() : nullptr, p1);
	}

	static void LUA_NATIVE_PAD__0x709BA8C08C5C008D()
	{
		PAD::_0x709BA8C08C5C008D();
	}

	static bool LUA_NATIVE_PAD__0x1252C029FC8EBB4D()
	{
		auto retval = (bool)PAD::_0x1252C029FC8EBB4D();
		return retval;
	}

	static void LUA_NATIVE_PAD__0x52C68E92D6E23ADD(Any p0)
	{
		PAD::_0x52C68E92D6E23ADD(p0);
	}

	void RegisterNatives_PAD(sol::state& L)
	{
		auto PAD = L["PAD"].get_or_create<sol::table>();
		PAD.set_function("_SET_CONTROL_CONTEXT", LUA_NATIVE_PAD__SET_CONTROL_CONTEXT);
		PAD.set_function("_GET_CURRENT_CONTROL_CONTEXT", LUA_NATIVE_PAD__GET_CURRENT_CONTROL_CONTEXT);
		PAD.set_function("_IS_CONTROL_ACTION_VALID", LUA_NATIVE_PAD__IS_CONTROL_ACTION_VALID);
		PAD.set_function("IS_CONTROL_ENABLED", LUA_NATIVE_PAD_IS_CONTROL_ENABLED);
		PAD.set_function("IS_CONTROL_PRESSED", LUA_NATIVE_PAD_IS_CONTROL_PRESSED);
		PAD.set_function("IS_CONTROL_RELEASED", LUA_NATIVE_PAD_IS_CONTROL_RELEASED);
		PAD.set_function("IS_CONTROL_JUST_PRESSED", LUA_NATIVE_PAD_IS_CONTROL_JUST_PRESSED);
		PAD.set_function("IS_CONTROL_JUST_RELEASED", LUA_NATIVE_PAD_IS_CONTROL_JUST_RELEASED);
		PAD.set_function("GET_CONTROL_VALUE", LUA_NATIVE_PAD_GET_CONTROL_VALUE);
		PAD.set_function("GET_CONTROL_NORMAL", LUA_NATIVE_PAD_GET_CONTROL_NORMAL);
		PAD.set_function("GET_CONTROL_UNBOUND_NORMAL", LUA_NATIVE_PAD_GET_CONTROL_UNBOUND_NORMAL);
		PAD.set_function("SET_CONTROL_VALUE_NEXT_FRAME", LUA_NATIVE_PAD_SET_CONTROL_VALUE_NEXT_FRAME);
		PAD.set_function("IS_DISABLED_CONTROL_PRESSED", LUA_NATIVE_PAD_IS_DISABLED_CONTROL_PRESSED);
		PAD.set_function("IS_DISABLED_CONTROL_JUST_PRESSED", LUA_NATIVE_PAD_IS_DISABLED_CONTROL_JUST_PRESSED);
		PAD.set_function("IS_DISABLED_CONTROL_JUST_RELEASED", LUA_NATIVE_PAD_IS_DISABLED_CONTROL_JUST_RELEASED);
		PAD.set_function("GET_DISABLED_CONTROL_NORMAL", LUA_NATIVE_PAD_GET_DISABLED_CONTROL_NORMAL);
		PAD.set_function("GET_DISABLED_CONTROL_UNBOUND_NORMAL", LUA_NATIVE_PAD_GET_DISABLED_CONTROL_UNBOUND_NORMAL);
		PAD.set_function("GET_CONTROL_HOW_LONG_AGO", LUA_NATIVE_PAD_GET_CONTROL_HOW_LONG_AGO);
		PAD.set_function("_GET_DISABLED_CONTROL_HOW_LONG_AGO", LUA_NATIVE_PAD__GET_DISABLED_CONTROL_HOW_LONG_AGO);
		PAD.set_function("IS_USING_KEYBOARD_AND_MOUSE", LUA_NATIVE_PAD_IS_USING_KEYBOARD_AND_MOUSE);
		PAD.set_function("_0x43F35DDB2905D945", LUA_NATIVE_PAD__0x43F35DDB2905D945);
		PAD.set_function("_0xBD629C1C4F501C80", LUA_NATIVE_PAD__0xBD629C1C4F501C80);
		PAD.set_function("HAVE_CONTROLS_CHANGED", LUA_NATIVE_PAD_HAVE_CONTROLS_CHANGED);
		PAD.set_function("SET_CONTROL_LIGHT_EFFECT_COLOR", LUA_NATIVE_PAD_SET_CONTROL_LIGHT_EFFECT_COLOR);
		PAD.set_function("CLEAR_CONTROL_LIGHT_EFFECT", LUA_NATIVE_PAD_CLEAR_CONTROL_LIGHT_EFFECT);
		PAD.set_function("SET_CONTROL_LIGHT_EFFECT_FLASHING_COLOR", LUA_NATIVE_PAD_SET_CONTROL_LIGHT_EFFECT_FLASHING_COLOR);
		PAD.set_function("SET_CONTROL_SHAKE", LUA_NATIVE_PAD_SET_CONTROL_SHAKE);
		PAD.set_function("SET_CONTROL_TRIGGER_SHAKE", LUA_NATIVE_PAD_SET_CONTROL_TRIGGER_SHAKE);
		PAD.set_function("STOP_CONTROL_SHAKE", LUA_NATIVE_PAD_STOP_CONTROL_SHAKE);
		PAD.set_function("SET_CONTROL_SHAKE_SUPPRESSED_ID", LUA_NATIVE_PAD_SET_CONTROL_SHAKE_SUPPRESSED_ID);
		PAD.set_function("CLEAR_CONTROL_SHAKE_SUPPRESSED_ID", LUA_NATIVE_PAD_CLEAR_CONTROL_SHAKE_SUPPRESSED_ID);
		PAD.set_function("IS_LOOK_INVERTED", LUA_NATIVE_PAD_IS_LOOK_INVERTED);
		PAD.set_function("SET_INPUT_EXCLUSIVE", LUA_NATIVE_PAD_SET_INPUT_EXCLUSIVE);
		PAD.set_function("DISABLE_CONTROL_ACTION", LUA_NATIVE_PAD_DISABLE_CONTROL_ACTION);
		PAD.set_function("ENABLE_CONTROL_ACTION", LUA_NATIVE_PAD_ENABLE_CONTROL_ACTION);
		PAD.set_function("DISABLE_ALL_CONTROL_ACTIONS", LUA_NATIVE_PAD_DISABLE_ALL_CONTROL_ACTIONS);
		PAD.set_function("_0x5F217BC1190503D8", LUA_NATIVE_PAD__0x5F217BC1190503D8);
		PAD.set_function("_0x709BA8C08C5C008D", LUA_NATIVE_PAD__0x709BA8C08C5C008D);
		PAD.set_function("_0x1252C029FC8EBB4D", LUA_NATIVE_PAD__0x1252C029FC8EBB4D);
		PAD.set_function("_0x52C68E92D6E23ADD", LUA_NATIVE_PAD__0x52C68E92D6E23ADD);
	}
}
