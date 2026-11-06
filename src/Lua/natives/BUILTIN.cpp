#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_BUILTIN_WAIT(int ms)
	{
		BUILTIN::WAIT(ms);
	}

	static int LUA_NATIVE_BUILTIN_TIMERA()
	{
		auto retval = BUILTIN::TIMERA();
		return retval;
	}

	static int LUA_NATIVE_BUILTIN_TIMERB()
	{
		auto retval = BUILTIN::TIMERB();
		return retval;
	}

	static void LUA_NATIVE_BUILTIN_SETTIMERA(int value)
	{
		BUILTIN::SETTIMERA(value);
	}

	static void LUA_NATIVE_BUILTIN_SETTIMERB(int value)
	{
		BUILTIN::SETTIMERB(value);
	}

	static float LUA_NATIVE_BUILTIN_TIMESTEP()
	{
		auto retval = BUILTIN::TIMESTEP();
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_SIN(float value)
	{
		auto retval = BUILTIN::SIN(value);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_COS(float value)
	{
		auto retval = BUILTIN::COS(value);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_SQRT(float value)
	{
		auto retval = BUILTIN::SQRT(value);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_POW(float base, float exponent)
	{
		auto retval = BUILTIN::POW(base, exponent);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_LOG10(float value)
	{
		auto retval = BUILTIN::LOG10(value);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_VMAG(float VecDirectionX, float VecDirectionY, float VecDirectionZ)
	{
		auto retval = BUILTIN::VMAG(VecDirectionX, VecDirectionY, VecDirectionZ);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_VMAG2(float VecDirectionX, float VecDirectionY, float VecDirectionZ)
	{
		auto retval = BUILTIN::VMAG2(VecDirectionX, VecDirectionY, VecDirectionZ);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_VDIST(float VecCoors1X, float VecCoors1Y, float VecCoors1Z, float VecCoors2X, float VecCoors2Y, float VecCoors2Z)
	{
		auto retval = BUILTIN::VDIST(VecCoors1X, VecCoors1Y, VecCoors1Z, VecCoors2X, VecCoors2Y, VecCoors2Z);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_VDIST2(float VecCoors1X, float VecCoors1Y, float VecCoors1Z, float VecCoors2X, float VecCoors2Y, float VecCoors2Z)
	{
		auto retval = BUILTIN::VDIST2(VecCoors1X, VecCoors1Y, VecCoors1Z, VecCoors2X, VecCoors2Y, VecCoors2Z);
		return retval;
	}

	static int LUA_NATIVE_BUILTIN_SHIFT_LEFT(int value, int bitShift)
	{
		auto retval = BUILTIN::SHIFT_LEFT(value, bitShift);
		return retval;
	}

	static int LUA_NATIVE_BUILTIN_SHIFT_RIGHT(int value, int bitShift)
	{
		auto retval = BUILTIN::SHIFT_RIGHT(value, bitShift);
		return retval;
	}

	static int LUA_NATIVE_BUILTIN_FLOOR(float value)
	{
		auto retval = BUILTIN::FLOOR(value);
		return retval;
	}

	static int LUA_NATIVE_BUILTIN_CEIL(float value)
	{
		auto retval = BUILTIN::CEIL(value);
		return retval;
	}

	static int LUA_NATIVE_BUILTIN_ROUND(float value)
	{
		auto retval = BUILTIN::ROUND(value);
		return retval;
	}

	static float LUA_NATIVE_BUILTIN_TO_FLOAT(int value)
	{
		auto retval = BUILTIN::TO_FLOAT(value);
		return retval;
	}

	static void LUA_NATIVE_BUILTIN_SET_THIS_THREAD_PRIORITY(int priority)
	{
		BUILTIN::SET_THIS_THREAD_PRIORITY(priority);
	}

	void RegisterNatives_BUILTIN(sol::state& L)
	{
		auto BUILTIN = L["BUILTIN"].get_or_create<sol::table>();
		BUILTIN.set_function("WAIT", LUA_NATIVE_BUILTIN_WAIT);
		BUILTIN.set_function("TIMERA", LUA_NATIVE_BUILTIN_TIMERA);
		BUILTIN.set_function("TIMERB", LUA_NATIVE_BUILTIN_TIMERB);
		BUILTIN.set_function("SETTIMERA", LUA_NATIVE_BUILTIN_SETTIMERA);
		BUILTIN.set_function("SETTIMERB", LUA_NATIVE_BUILTIN_SETTIMERB);
		BUILTIN.set_function("TIMESTEP", LUA_NATIVE_BUILTIN_TIMESTEP);
		BUILTIN.set_function("SIN", LUA_NATIVE_BUILTIN_SIN);
		BUILTIN.set_function("COS", LUA_NATIVE_BUILTIN_COS);
		BUILTIN.set_function("SQRT", LUA_NATIVE_BUILTIN_SQRT);
		BUILTIN.set_function("POW", LUA_NATIVE_BUILTIN_POW);
		BUILTIN.set_function("LOG10", LUA_NATIVE_BUILTIN_LOG10);
		BUILTIN.set_function("VMAG", LUA_NATIVE_BUILTIN_VMAG);
		BUILTIN.set_function("VMAG2", LUA_NATIVE_BUILTIN_VMAG2);
		BUILTIN.set_function("VDIST", LUA_NATIVE_BUILTIN_VDIST);
		BUILTIN.set_function("VDIST2", LUA_NATIVE_BUILTIN_VDIST2);
		BUILTIN.set_function("SHIFT_LEFT", LUA_NATIVE_BUILTIN_SHIFT_LEFT);
		BUILTIN.set_function("SHIFT_RIGHT", LUA_NATIVE_BUILTIN_SHIFT_RIGHT);
		BUILTIN.set_function("FLOOR", LUA_NATIVE_BUILTIN_FLOOR);
		BUILTIN.set_function("CEIL", LUA_NATIVE_BUILTIN_CEIL);
		BUILTIN.set_function("ROUND", LUA_NATIVE_BUILTIN_ROUND);
		BUILTIN.set_function("TO_FLOAT", LUA_NATIVE_BUILTIN_TO_FLOAT);
		BUILTIN.set_function("SET_THIS_THREAD_PRIORITY", LUA_NATIVE_BUILTIN_SET_THIS_THREAD_PRIORITY);
	}
}
