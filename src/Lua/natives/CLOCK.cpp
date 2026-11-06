#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_CLOCK_SET_CLOCK_TIME(int h, int m, int s)
	{
		CLOCK::SET_CLOCK_TIME(h, m, s);
	}

	static void LUA_NATIVE_CLOCK_PAUSE_CLOCK(bool pause, Any unused)
	{
		CLOCK::PAUSE_CLOCK(pause, unused);
	}

	static void LUA_NATIVE_CLOCK__PAUSE_CLOCK_THIS_FRAME(bool toggle)
	{
		CLOCK::_PAUSE_CLOCK_THIS_FRAME(toggle);
	}

	static void LUA_NATIVE_CLOCK_ADVANCE_CLOCK_TIME_TO(int h, int m, int s)
	{
		CLOCK::ADVANCE_CLOCK_TIME_TO(h, m, s);
	}

	static void LUA_NATIVE_CLOCK_ADD_TO_CLOCK_TIME(int h, int m, int s)
	{
		CLOCK::ADD_TO_CLOCK_TIME(h, m, s);
	}

	static int LUA_NATIVE_CLOCK_GET_CLOCK_HOURS()
	{
		auto retval = CLOCK::GET_CLOCK_HOURS();
		return retval;
	}

	static int LUA_NATIVE_CLOCK_GET_CLOCK_MINUTES()
	{
		auto retval = CLOCK::GET_CLOCK_MINUTES();
		return retval;
	}

	static int LUA_NATIVE_CLOCK_GET_CLOCK_SECONDS()
	{
		auto retval = CLOCK::GET_CLOCK_SECONDS();
		return retval;
	}

	static void LUA_NATIVE_CLOCK__SET_MILLISECONDS_PER_GAME_MINUTE(int ms)
	{
		CLOCK::_SET_MILLISECONDS_PER_GAME_MINUTE(ms);
	}

	static int LUA_NATIVE_CLOCK__GET_SECONDS_SINCE_BASE_YEAR()
	{
		auto retval = CLOCK::_GET_SECONDS_SINCE_BASE_YEAR();
		return retval;
	}

	static void LUA_NATIVE_CLOCK_SET_CLOCK_DATE(int d, int m, int y)
	{
		CLOCK::SET_CLOCK_DATE(d, m, y);
	}

	static int LUA_NATIVE_CLOCK_GET_CLOCK_DAY_OF_WEEK()
	{
		auto retval = CLOCK::GET_CLOCK_DAY_OF_WEEK();
		return retval;
	}

	static int LUA_NATIVE_CLOCK_GET_CLOCK_DAY_OF_MONTH()
	{
		auto retval = CLOCK::GET_CLOCK_DAY_OF_MONTH();
		return retval;
	}

	static int LUA_NATIVE_CLOCK_GET_CLOCK_MONTH()
	{
		auto retval = CLOCK::GET_CLOCK_MONTH();
		return retval;
	}

	static int LUA_NATIVE_CLOCK_GET_CLOCK_YEAR()
	{
		auto retval = CLOCK::GET_CLOCK_YEAR();
		return retval;
	}

	static int LUA_NATIVE_CLOCK_GET_MILLISECONDS_PER_GAME_MINUTE()
	{
		auto retval = CLOCK::GET_MILLISECONDS_PER_GAME_MINUTE();
		return retval;
	}

	static std::tuple<int, int, int, int, int, int> LUA_NATIVE_CLOCK_GET_POSIX_TIME(int year, int month, int day, int hour, int min, int sec)
	{
		std::tuple<int, int, int, int, int, int> return_values;
		CLOCK::GET_POSIX_TIME(&year, &month, &day, &hour, &min, &sec);
		std::get<0>(return_values) = year;
		std::get<1>(return_values) = month;
		std::get<2>(return_values) = day;
		std::get<3>(return_values) = hour;
		std::get<4>(return_values) = min;
		std::get<5>(return_values) = sec;

		return return_values;
	}

	static void LUA_NATIVE_CLOCK__GET_POSIX_TIME_STRUCT(uintptr_t outTime)
	{
		CLOCK::_GET_POSIX_TIME_STRUCT((Any*)outTime);
	}

	static void LUA_NATIVE_CLOCK__ADD_TIME_TO_DATE_TIME(uintptr_t inDateTime, uintptr_t timeToAdd, uintptr_t outDateTime)
	{
		CLOCK::_ADD_TIME_TO_DATE_TIME((Any*)inDateTime, (Any*)timeToAdd, (Any*)outDateTime);
	}

	void RegisterNatives_CLOCK(sol::state& L)
	{
		auto CLOCK = L["CLOCK"].get_or_create<sol::table>();
		CLOCK.set_function("SET_CLOCK_TIME", LUA_NATIVE_CLOCK_SET_CLOCK_TIME);
		CLOCK.set_function("PAUSE_CLOCK", LUA_NATIVE_CLOCK_PAUSE_CLOCK);
		CLOCK.set_function("_PAUSE_CLOCK_THIS_FRAME", LUA_NATIVE_CLOCK__PAUSE_CLOCK_THIS_FRAME);
		CLOCK.set_function("ADVANCE_CLOCK_TIME_TO", LUA_NATIVE_CLOCK_ADVANCE_CLOCK_TIME_TO);
		CLOCK.set_function("ADD_TO_CLOCK_TIME", LUA_NATIVE_CLOCK_ADD_TO_CLOCK_TIME);
		CLOCK.set_function("GET_CLOCK_HOURS", LUA_NATIVE_CLOCK_GET_CLOCK_HOURS);
		CLOCK.set_function("GET_CLOCK_MINUTES", LUA_NATIVE_CLOCK_GET_CLOCK_MINUTES);
		CLOCK.set_function("GET_CLOCK_SECONDS", LUA_NATIVE_CLOCK_GET_CLOCK_SECONDS);
		CLOCK.set_function("_SET_MILLISECONDS_PER_GAME_MINUTE", LUA_NATIVE_CLOCK__SET_MILLISECONDS_PER_GAME_MINUTE);
		CLOCK.set_function("_GET_SECONDS_SINCE_BASE_YEAR", LUA_NATIVE_CLOCK__GET_SECONDS_SINCE_BASE_YEAR);
		CLOCK.set_function("SET_CLOCK_DATE", LUA_NATIVE_CLOCK_SET_CLOCK_DATE);
		CLOCK.set_function("GET_CLOCK_DAY_OF_WEEK", LUA_NATIVE_CLOCK_GET_CLOCK_DAY_OF_WEEK);
		CLOCK.set_function("GET_CLOCK_DAY_OF_MONTH", LUA_NATIVE_CLOCK_GET_CLOCK_DAY_OF_MONTH);
		CLOCK.set_function("GET_CLOCK_MONTH", LUA_NATIVE_CLOCK_GET_CLOCK_MONTH);
		CLOCK.set_function("GET_CLOCK_YEAR", LUA_NATIVE_CLOCK_GET_CLOCK_YEAR);
		CLOCK.set_function("GET_MILLISECONDS_PER_GAME_MINUTE", LUA_NATIVE_CLOCK_GET_MILLISECONDS_PER_GAME_MINUTE);
		CLOCK.set_function("GET_POSIX_TIME", LUA_NATIVE_CLOCK_GET_POSIX_TIME);
		CLOCK.set_function("_GET_POSIX_TIME_STRUCT", LUA_NATIVE_CLOCK__GET_POSIX_TIME_STRUCT);
		CLOCK.set_function("_ADD_TIME_TO_DATE_TIME", LUA_NATIVE_CLOCK__ADD_TIME_TO_DATE_TIME);
	}
}
