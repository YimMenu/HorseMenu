#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static int LUA_NATIVE_MISC_GET_NUMBER_OF_FREE_STACKS_OF_THIS_SIZE(int stackSize)
	{
		auto retval = MISC::GET_NUMBER_OF_FREE_STACKS_OF_THIS_SIZE(stackSize);
		return retval;
	}

	static int LUA_NATIVE_MISC__GET_NUMBER_OF_INSTRUCTIONS()
	{
		auto retval = MISC::_GET_NUMBER_OF_INSTRUCTIONS();
		return retval;
	}

	static int LUA_NATIVE_MISC__GET_MAX_NUM_INSTRUCTIONS()
	{
		auto retval = MISC::_GET_MAX_NUM_INSTRUCTIONS();
		return retval;
	}

	static bool LUA_NATIVE_MISC_IS_MAG_DEMO_1_ACTIVE()
	{
		auto retval = (bool)MISC::IS_MAG_DEMO_1_ACTIVE();
		return retval;
	}

	static void LUA_NATIVE_MISC_SET_RANDOM_SEED(int NewSeed)
	{
		MISC::SET_RANDOM_SEED(NewSeed);
	}

	static void LUA_NATIVE_MISC_SET_TIME_SCALE(float fNewTimeScale)
	{
		MISC::SET_TIME_SCALE(fNewTimeScale);
	}

	static void LUA_NATIVE_MISC_SET_MISSION_FLAG(bool MissionFlagValue)
	{
		MISC::SET_MISSION_FLAG(MissionFlagValue);
	}

	static bool LUA_NATIVE_MISC_GET_MISSION_FLAG()
	{
		auto retval = (bool)MISC::GET_MISSION_FLAG();
		return retval;
	}

	static void LUA_NATIVE_MISC__0x5801BE2DF2AF07EC(Any p0)
	{
		MISC::_0x5801BE2DF2AF07EC(p0);
	}

	static void LUA_NATIVE_MISC_SET_RANDOM_EVENT_FLAG(bool bThisScriptIsARandomEvent)
	{
		MISC::SET_RANDOM_EVENT_FLAG(bThisScriptIsARandomEvent);
	}

	static bool LUA_NATIVE_MISC_GET_RANDOM_EVENT_FLAG()
	{
		auto retval = (bool)MISC::GET_RANDOM_EVENT_FLAG();
		return retval;
	}

	static void LUA_NATIVE_MISC__0x9BF2C0C568C61641(Any p0)
	{
		MISC::_0x9BF2C0C568C61641(p0);
	}

	static void LUA_NATIVE_MISC_ACTIVITY_FEED_CREATE(sol::stack_object CaptionString, sol::stack_object CondensedCaptionString)
	{
		MISC::ACTIVITY_FEED_CREATE(CaptionString.is<const char*>() ? CaptionString.as<const char*>() : nullptr, CondensedCaptionString.is<const char*>() ? CondensedCaptionString.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_MISC_ACTIVITY_FEED_ADD_SUBSTRING_TO_CAPTION(sol::stack_object SubString)
	{
		MISC::ACTIVITY_FEED_ADD_SUBSTRING_TO_CAPTION(SubString.is<const char*>() ? SubString.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_MISC__0xFF252E2BAFB7330F(Any p0)
	{
		MISC::_0xFF252E2BAFB7330F(p0);
	}

	static void LUA_NATIVE_MISC_ACTIVITY_FEED_ACTION_START_WITH_COMMAND_LINE(sol::stack_object commandLineString, sol::stack_object labelString)
	{
		MISC::ACTIVITY_FEED_ACTION_START_WITH_COMMAND_LINE(commandLineString.is<const char*>() ? commandLineString.as<const char*>() : nullptr, labelString.is<const char*>() ? labelString.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_MISC_ACTIVITY_FEED_ACTION_START_WITH_COMMAND_LINE_ADD(sol::stack_object commandLineString)
	{
		MISC::ACTIVITY_FEED_ACTION_START_WITH_COMMAND_LINE_ADD(commandLineString.is<const char*>() ? commandLineString.as<const char*>() : nullptr);
	}

	static Any LUA_NATIVE_MISC__0xAF530E56505D1BD6(Any p0)
	{
		auto retval = MISC::_0xAF530E56505D1BD6(p0);
		return retval;
	}

	static void LUA_NATIVE_MISC_ACTIVITY_FEED_POST()
	{
		MISC::ACTIVITY_FEED_POST();
	}

	static const char* LUA_NATIVE_MISC__0xF81C53561D15F330()
	{
		auto retval = MISC::_0xF81C53561D15F330();
		return retval;
	}

	static void LUA_NATIVE_MISC__0x1096603B519C905F(sol::stack_object name)
	{
		MISC::_0x1096603B519C905F(name.is<const char*>() ? name.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_MISC__0xCC3EDC5614B03F61(int p0)
	{
		MISC::_0xCC3EDC5614B03F61(p0);
	}

	static void LUA_NATIVE_MISC_INFORM_CODE_OF_CONTENT_ID_OF_CURRENT_UGC_MISSION(sol::stack_object ContentIdString)
	{
		MISC::INFORM_CODE_OF_CONTENT_ID_OF_CURRENT_UGC_MISSION(ContentIdString.is<const char*>() ? ContentIdString.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_MISC__0xDA4D8EB04E8E2928(Any p0)
	{
		MISC::_0xDA4D8EB04E8E2928(p0);
	}

	static void LUA_NATIVE_MISC__0xB08C4FA25BC29DB9(Any p0)
	{
		MISC::_0xB08C4FA25BC29DB9(p0);
	}

	static Hash LUA_NATIVE_MISC__GET_PREV_WEATHER_TYPE_HASH_NAME()
	{
		auto retval = MISC::_GET_PREV_WEATHER_TYPE_HASH_NAME();
		return retval;
	}

	static Hash LUA_NATIVE_MISC__GET_NEXT_WEATHER_TYPE_HASH_NAME()
	{
		auto retval = MISC::_GET_NEXT_WEATHER_TYPE_HASH_NAME();
		return retval;
	}

	static void LUA_NATIVE_MISC__0x0730E518486DEEC3(Any p0)
	{
		MISC::_0x0730E518486DEEC3(p0);
	}

	static void LUA_NATIVE_MISC_SET_WEATHER_TYPE(Hash weatherType, bool p1, bool p2, bool transition, float transitionTime, bool p5)
	{
		MISC::SET_WEATHER_TYPE(weatherType, p1, p2, transition, transitionTime, p5);
	}

	static void LUA_NATIVE_MISC__SET_WEATHER_TYPE_2(Hash weatherType, int p1, int p2, int p3, bool p4)
	{
		MISC::_SET_WEATHER_TYPE_2(weatherType, p1, p2, p3, p4);
	}

	static int LUA_NATIVE_MISC__GET_RANDOM_WEATHER_TYPE_INDEX()
	{
		auto retval = MISC::_GET_RANDOM_WEATHER_TYPE_INDEX();
		return retval;
	}

	static Hash LUA_NATIVE_MISC__GET_RANDOM_WEATHER_TYPE()
	{
		auto retval = MISC::_GET_RANDOM_WEATHER_TYPE();
		return retval;
	}

	static void LUA_NATIVE_MISC_SET_RANDOM_WEATHER_TYPE(bool p0, bool p1)
	{
		MISC::SET_RANDOM_WEATHER_TYPE(p0, p1);
	}

	static void LUA_NATIVE_MISC_CLEAR_WEATHER_TYPE_PERSIST()
	{
		MISC::CLEAR_WEATHER_TYPE_PERSIST();
	}

	static void LUA_NATIVE_MISC__CLEAR_WEATHER_TYPE_PERSIST_OVERTIME(int milliseconds)
	{
		MISC::_CLEAR_WEATHER_TYPE_PERSIST_OVERTIME(milliseconds);
	}

	static std::tuple<Hash, Hash, float> LUA_NATIVE_MISC_GET_CURR_WEATHER_STATE(Hash prevTypeHashName, Hash nextTypeHashName, float interpVal)
	{
		std::tuple<Hash, Hash, float> return_values;
		MISC::GET_CURR_WEATHER_STATE(&prevTypeHashName, &nextTypeHashName, &interpVal);
		std::get<0>(return_values) = prevTypeHashName;
		std::get<1>(return_values) = nextTypeHashName;
		std::get<2>(return_values) = interpVal;

		return return_values;
	}

	static void LUA_NATIVE_MISC_SET_CURR_WEATHER_STATE(Hash prevTypeHashName, Hash nextTypeHashName, float interpVal, bool enabled)
	{
		MISC::SET_CURR_WEATHER_STATE(prevTypeHashName, nextTypeHashName, interpVal, enabled);
	}

	static void LUA_NATIVE_MISC__SET_WEATHER_TYPE_FROZEN(bool toggle)
	{
		MISC::_SET_WEATHER_TYPE_FROZEN(toggle);
	}

	static std::tuple<Hash, Hash> LUA_NATIVE_MISC__GET_FORCED_WEATHER(Hash weather, Hash p1)
	{
		std::tuple<Hash, Hash> return_values;
		MISC::_GET_FORCED_WEATHER(&weather, &p1);
		std::get<0>(return_values) = weather;
		std::get<1>(return_values) = p1;

		return return_values;
	}

	static void LUA_NATIVE_MISC__0x2916B30DC6C41179(Hash weatherType)
	{
		MISC::_0x2916B30DC6C41179(weatherType);
	}

	static void LUA_NATIVE_MISC__0xD3F943B88F55376A(Hash weatherType)
	{
		MISC::_0xD3F943B88F55376A(weatherType);
	}

	static void LUA_NATIVE_MISC__0x243CEDE8F916B994()
	{
		MISC::_0x243CEDE8F916B994();
	}

	static void LUA_NATIVE_MISC__SET_OVERRIDE_WEATHER(Hash weatherType)
	{
		MISC::_SET_OVERRIDE_WEATHER(weatherType);
	}

	static void LUA_NATIVE_MISC_CLEAR_OVERRIDE_WEATHER()
	{
		MISC::CLEAR_OVERRIDE_WEATHER();
	}

	static void LUA_NATIVE_MISC__SET_WEATHER_VARIATION(sol::stack_object weatherType, sol::stack_object variation)
	{
		MISC::_SET_WEATHER_VARIATION(weatherType.is<const char*>() ? weatherType.as<const char*>() : nullptr, variation.is<const char*>() ? variation.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_MISC__CLEAR_WEATHER_VARIATION(sol::stack_object weatherType, bool p1)
	{
		MISC::_CLEAR_WEATHER_VARIATION(weatherType.is<const char*>() ? weatherType.as<const char*>() : nullptr, p1);
	}

	static void LUA_NATIVE_MISC_WATER_OVERRIDE_SET_SHOREWAVEAMPLITUDE(float value)
	{
		MISC::WATER_OVERRIDE_SET_SHOREWAVEAMPLITUDE(value);
	}

	static void LUA_NATIVE_MISC_WATER_OVERRIDE_SET_OCEANWAVEMAXAMPLITUDE(float value)
	{
		MISC::WATER_OVERRIDE_SET_OCEANWAVEMAXAMPLITUDE(value);
	}

	static float LUA_NATIVE_MISC__GET_TEMPERATURE_AT_COORDS(float x, float y, float z)
	{
		auto retval = MISC::_GET_TEMPERATURE_AT_COORDS(x, y, z);
		return retval;
	}

	static void LUA_NATIVE_MISC_SET_WIND_SPEED(float WindSpeed)
	{
		MISC::SET_WIND_SPEED(WindSpeed);
	}

	static float LUA_NATIVE_MISC_GET_WIND_SPEED()
	{
		auto retval = MISC::GET_WIND_SPEED();
		return retval;
	}

	static void LUA_NATIVE_MISC_SET_WIND_DIRECTION(float WindDir)
	{
		MISC::SET_WIND_DIRECTION(WindDir);
	}

	static Vector3 LUA_NATIVE_MISC_GET_WIND_DIRECTION()
	{
		auto retval = MISC::GET_WIND_DIRECTION();
		return retval;
	}

	static void LUA_NATIVE_MISC_SET_RAIN(float RainVal)
	{
		MISC::SET_RAIN(RainVal);
	}

	static float LUA_NATIVE_MISC_GET_RAIN_LEVEL()
	{
		auto retval = MISC::GET_RAIN_LEVEL();
		return retval;
	}

	static void LUA_NATIVE_MISC__0x745808BB01CEC6B9(float p0)
	{
		MISC::_0x745808BB01CEC6B9(p0);
	}

	static void LUA_NATIVE_MISC__SET_SNOW_LEVEL(float level)
	{
		MISC::_SET_SNOW_LEVEL(level);
	}

	static float LUA_NATIVE_MISC_GET_SNOW_LEVEL()
	{
		auto retval = MISC::GET_SNOW_LEVEL();
		return retval;
	}

	static void LUA_NATIVE_MISC_FORCE_LIGHTNING_FLASH()
	{
		MISC::FORCE_LIGHTNING_FLASH();
	}

	static void LUA_NATIVE_MISC__FORCE_LIGHTNING_FLASH_AT_COORDS(float x, float y, float z, float p3)
	{
		MISC::_FORCE_LIGHTNING_FLASH_AT_COORDS(x, y, z, p3);
	}

	static void LUA_NATIVE_MISC__0xA9342743B634A462(Any p0)
	{
		MISC::_0xA9342743B634A462(p0);
	}

	static int LUA_NATIVE_MISC_GET_GAME_TIMER()
	{
		auto retval = MISC::GET_GAME_TIMER();
		return retval;
	}

	static int LUA_NATIVE_MISC__GET_GAME_TIMER_NON_SCALED_CLIPPED()
	{
		auto retval = MISC::_GET_GAME_TIMER_NON_SCALED_CLIPPED();
		return retval;
	}

	static int LUA_NATIVE_MISC_GET_SYSTEM_TIME()
	{
		auto retval = MISC::GET_SYSTEM_TIME();
		return retval;
	}

	static int LUA_NATIVE_MISC_GET_NUMBER_OF_MICROSECONDS_SINCE_LAST_CALL()
	{
		auto retval = MISC::GET_NUMBER_OF_MICROSECONDS_SINCE_LAST_CALL();
		return retval;
	}

	static int LUA_NATIVE_MISC_GET_SCRIPT_TIME_WITHIN_FRAME_IN_MICROSECONDS()
	{
		auto retval = MISC::GET_SCRIPT_TIME_WITHIN_FRAME_IN_MICROSECONDS();
		return retval;
	}

	static void LUA_NATIVE_MISC_RESET_SCRIPT_TIME_WITHIN_FRAME()
	{
		MISC::RESET_SCRIPT_TIME_WITHIN_FRAME();
	}

	static float LUA_NATIVE_MISC_GET_FRAME_TIME()
	{
		auto retval = MISC::GET_FRAME_TIME();
		return retval;
	}

	static float LUA_NATIVE_MISC_GET_SYSTEM_TIME_STEP()
	{
		auto retval = MISC::GET_SYSTEM_TIME_STEP();
		return retval;
	}

	static int LUA_NATIVE_MISC_GET_FRAME_COUNT()
	{
		auto retval = MISC::GET_FRAME_COUNT();
		return retval;
	}

	static void LUA_NATIVE_MISC__0x6BED40493A1AFDB8(uintptr_t p0, float p1)
	{
		MISC::_0x6BED40493A1AFDB8((Any*)p0, p1);
	}

	static float LUA_NATIVE_MISC__READ_INT_AS_FLOAT(int value)
	{
		auto retval = MISC::_READ_INT_AS_FLOAT(value);
		return retval;
	}

	static float LUA_NATIVE_MISC_GET_RANDOM_FLOAT_IN_RANGE(float MinFloat, float MaxFloat)
	{
		auto retval = MISC::GET_RANDOM_FLOAT_IN_RANGE(MinFloat, MaxFloat);
		return retval;
	}

	static int LUA_NATIVE_MISC_GET_RANDOM_INT_IN_RANGE(int MinInt, int MaxInt)
	{
		auto retval = MISC::GET_RANDOM_INT_IN_RANGE(MinInt, MaxInt);
		return retval;
	}

	static std::tuple<bool, float> LUA_NATIVE_MISC_GET_GROUND_Z_FOR_3D_COORD(float VecCoorsX, float VecCoorsY, float VecCoorsZ, float ReturnZ, bool p4)
	{
		std::tuple<bool, float> return_values;
		std::get<0>(return_values) = (bool)MISC::GET_GROUND_Z_FOR_3D_COORD(VecCoorsX, VecCoorsY, VecCoorsZ, &ReturnZ, p4);
		std::get<1>(return_values) = ReturnZ;

		return return_values;
	}

	static std::tuple<bool, float, Vector3> LUA_NATIVE_MISC_GET_GROUND_Z_AND_NORMAL_FOR_3D_COORD(float VecCoorsX, float VecCoorsY, float VecCoorsZ, float ReturnZ, Vector3 ReturnNormal)
	{
		std::tuple<bool, float, Vector3> return_values;
		std::get<0>(return_values) = (bool)MISC::GET_GROUND_Z_AND_NORMAL_FOR_3D_COORD(VecCoorsX, VecCoorsY, VecCoorsZ, &ReturnZ, &ReturnNormal);
		std::get<1>(return_values) = ReturnZ;
		std::get<2>(return_values) = ReturnNormal;

		return return_values;
	}

	static Any LUA_NATIVE_MISC__0xBBE5B63EFFB08E68(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6)
	{
		auto retval = MISC::_0xBBE5B63EFFB08E68(p0, p1, p2, p3, p4, p5, p6);
		return retval;
	}

	static float LUA_NATIVE_MISC_ASIN(float X)
	{
		auto retval = MISC::ASIN(X);
		return retval;
	}

	static float LUA_NATIVE_MISC_ACOS(float X)
	{
		auto retval = MISC::ACOS(X);
		return retval;
	}

	static float LUA_NATIVE_MISC_TAN(float X)
	{
		auto retval = MISC::TAN(X);
		return retval;
	}

	static float LUA_NATIVE_MISC_ATAN(float X)
	{
		auto retval = MISC::ATAN(X);
		return retval;
	}

	static float LUA_NATIVE_MISC_ATAN2(float Y, float X)
	{
		auto retval = MISC::ATAN2(Y, X);
		return retval;
	}

	static float LUA_NATIVE_MISC_GET_DISTANCE_BETWEEN_COORDS(float VecFirstCoorsX, float VecFirstCoorsY, float VecFirstCoorsZ, float VecSecondCoorsX, float VecSecondCoorsY, float VecSecondCoorsZ, bool bCheck3d)
	{
		auto retval = MISC::GET_DISTANCE_BETWEEN_COORDS(VecFirstCoorsX, VecFirstCoorsY, VecFirstCoorsZ, VecSecondCoorsX, VecSecondCoorsY, VecSecondCoorsZ, bCheck3d);
		return retval;
	}

	static float LUA_NATIVE_MISC_GET_ANGLE_BETWEEN_2D_VECTORS(float X1, float Y1, float X2, float Y2)
	{
		auto retval = MISC::GET_ANGLE_BETWEEN_2D_VECTORS(X1, Y1, X2, Y2);
		return retval;
	}

	static float LUA_NATIVE_MISC_GET_HEADING_FROM_VECTOR_2D(float VecX, float VecY)
	{
		auto retval = MISC::GET_HEADING_FROM_VECTOR_2D(VecX, VecY);
		return retval;
	}

	static Vector3 LUA_NATIVE_MISC_GET_CLOSEST_POINT_ON_LINE(float rPointToTestX, float rPointToTestY, float rPointToTestZ, float vStartX, float vStartY, float vStartZ, float vEndX, float vEndY, float vEndZ, bool bClampToLine)
	{
		auto retval = MISC::GET_CLOSEST_POINT_ON_LINE(rPointToTestX, rPointToTestY, rPointToTestZ, vStartX, vStartY, vStartZ, vEndX, vEndY, vEndZ, bClampToLine);
		return retval;
	}

	static std::tuple<bool, float> LUA_NATIVE_MISC_GET_LINE_PLANE_INTERSECTION(float vscrPntAX, float vscrPntAY, float vscrPntAZ, float vscrPntBX, float vscrPntBY, float vscrPntBZ, float vscrPntOnPlaneX, float vscrPntOnPlaneY, float vscrPntOnPlaneZ, float vscrNormalX, float vscrNormalY, float vscrNormalZ, float fTValue)
	{
		std::tuple<bool, float> return_values;
		std::get<0>(return_values) = (bool)MISC::GET_LINE_PLANE_INTERSECTION(vscrPntAX, vscrPntAY, vscrPntAZ, vscrPntBX, vscrPntBY, vscrPntBZ, vscrPntOnPlaneX, vscrPntOnPlaneY, vscrPntOnPlaneZ, vscrNormalX, vscrNormalY, vscrNormalZ, &fTValue);
		std::get<1>(return_values) = fTValue;

		return return_values;
	}

	static int LUA_NATIVE_MISC_SET_BIT(int Variable, int BitIndex)
	{
		MISC::SET_BIT(&Variable, BitIndex);
		return Variable;
	}

	static int LUA_NATIVE_MISC_CLEAR_BIT(int Variable, int BitIndex)
	{
		MISC::CLEAR_BIT(&Variable, BitIndex);
		return Variable;
	}

	static bool LUA_NATIVE_MISC__IS_BIT_FLAG_SET(uintptr_t bitFlags, int flag)
	{
		auto retval = (bool)MISC::_IS_BIT_FLAG_SET((Any*)bitFlags, flag);
		return retval;
	}

	static bool LUA_NATIVE_MISC__IS_ANY_BIT_FLAG_SET(uintptr_t bitFlags)
	{
		auto retval = (bool)MISC::_IS_ANY_BIT_FLAG_SET((Any*)bitFlags);
		return retval;
	}

	static int LUA_NATIVE_MISC__COUNT_BIT_FLAGS(uintptr_t bitFlags)
	{
		auto retval = MISC::_COUNT_BIT_FLAGS((Any*)bitFlags);
		return retval;
	}

	static void LUA_NATIVE_MISC__SET_BIT_FLAG(uintptr_t bitFlags, int flag)
	{
		MISC::_SET_BIT_FLAG((Any*)bitFlags, flag);
	}

	static void LUA_NATIVE_MISC__CLEAR_BIT_FLAG(uintptr_t bitFlags, int flag)
	{
		MISC::_CLEAR_BIT_FLAG((Any*)bitFlags, flag);
	}

	static void LUA_NATIVE_MISC__CLEAR_ALL_BIT_FLAGS(uintptr_t bitFlags)
	{
		MISC::_CLEAR_ALL_BIT_FLAGS((Any*)bitFlags);
	}

	static Hash LUA_NATIVE_MISC_GET_HASH_KEY(sol::stack_object InputString)
	{
		auto retval = MISC::GET_HASH_KEY(InputString.is<const char*>() ? InputString.as<const char*>() : nullptr);
		return retval;
	}

	static float LUA_NATIVE_MISC__GET_EASING_CURVE_VALUE(float t, float b, float d, int easingCurveType)
	{
		auto retval = MISC::_GET_EASING_CURVE_VALUE(t, b, d, easingCurveType);
		return retval;
	}

	static bool LUA_NATIVE_MISC_IS_POSITION_OCCUPIED(float VecCenterCoorsX, float VecCenterCoorsY, float VecCenterCoorsZ, float radius, bool bBuildingFlag, bool bVehicleFlag, bool bPedFlag, bool bObjectFlag, bool bDummyFlag, Entity ExcludeEntityIndex, bool bCheckAlive)
	{
		auto retval = (bool)MISC::IS_POSITION_OCCUPIED(VecCenterCoorsX, VecCenterCoorsY, VecCenterCoorsZ, radius, bBuildingFlag, bVehicleFlag, bPedFlag, bObjectFlag, bDummyFlag, ExcludeEntityIndex, bCheckAlive);
		return retval;
	}

	static void LUA_NATIVE_MISC_CLEAR_AREA(float VecCentreCoorsX, float VecCentreCoorsY, float VecCentreCoorsZ, float Radius, int iFlags)
	{
		MISC::CLEAR_AREA(VecCentreCoorsX, VecCentreCoorsY, VecCentreCoorsZ, Radius, iFlags);
	}

	static void LUA_NATIVE_MISC__CLEAR_VOLUME_AREA(Volume volume, int flag)
	{
		MISC::_CLEAR_VOLUME_AREA(volume, flag);
	}

	static void LUA_NATIVE_MISC_CLEAR_ANGLED_AREA_OF_VEHICLES(float vecAngledAreaPoint1X, float vecAngledAreaPoint1Y, float vecAngledAreaPoint1Z, float vecAngledAreaPoint2X, float vecAngledAreaPoint2Y, float vecAngledAreaPoint2Z, float DistanceOfOppositeFace, int iFlags)
	{
		MISC::CLEAR_ANGLED_AREA_OF_VEHICLES(vecAngledAreaPoint1X, vecAngledAreaPoint1Y, vecAngledAreaPoint1Z, vecAngledAreaPoint2X, vecAngledAreaPoint2Y, vecAngledAreaPoint2Z, DistanceOfOppositeFace, iFlags);
	}

	static void LUA_NATIVE_MISC_SET_CREDITS_ACTIVE(bool bActive)
	{
		MISC::SET_CREDITS_ACTIVE(bActive);
	}

	static void LUA_NATIVE_MISC_NETWORK_SET_SCRIPT_IS_SAFE_FOR_NETWORK_GAME()
	{
		MISC::NETWORK_SET_SCRIPT_IS_SAFE_FOR_NETWORK_GAME();
	}

	static void LUA_NATIVE_MISC_PAUSE_DEATH_ARREST_RESTART(bool bPaused)
	{
		MISC::PAUSE_DEATH_ARREST_RESTART(bPaused);
	}

	static void LUA_NATIVE_MISC_IGNORE_NEXT_RESTART(bool bIgnore)
	{
		MISC::IGNORE_NEXT_RESTART(bIgnore);
	}

	static void LUA_NATIVE_MISC_SET_FADE_IN_AFTER_DEATH_ARREST(bool bDoFade)
	{
		MISC::SET_FADE_IN_AFTER_DEATH_ARREST(bDoFade);
	}

	static void LUA_NATIVE_MISC_SET_FADE_IN_AFTER_LOAD(bool bFadeIn)
	{
		MISC::SET_FADE_IN_AFTER_LOAD(bFadeIn);
	}

	static std::tuple<bool, Vector3, float> LUA_NATIVE_MISC_OVERRIDE_SAVE_HOUSE(bool bOverride, float vecCoordsX, float vecCoordsY, float vecCoordsZ, float fHeading, bool bIsAnAutosave, Vector3 vecReturnCoords, float fReturnHeading)
	{
		std::tuple<bool, Vector3, float> return_values;
		std::get<0>(return_values) = (bool)MISC::OVERRIDE_SAVE_HOUSE(bOverride, vecCoordsX, vecCoordsY, vecCoordsZ, fHeading, bIsAnAutosave, &vecReturnCoords, &fReturnHeading);
		std::get<1>(return_values) = vecReturnCoords;
		std::get<2>(return_values) = fReturnHeading;

		return return_values;
	}

	static void LUA_NATIVE_MISC_SHOOT_SINGLE_BULLET_BETWEEN_COORDS(float VecStartCoorsX, float VecStartCoorsY, float VecStartCoorsZ, float VecEndCoorsX, float VecEndCoorsY, float VecEndCoorsZ, int DamageCaused, bool bPerfectAccuracy, Hash Weapon, Ped PedIndex, bool isAudible, bool isInvisible, float InitialVelocity, bool p13)
	{
		MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(VecStartCoorsX, VecStartCoorsY, VecStartCoorsZ, VecEndCoorsX, VecEndCoorsY, VecEndCoorsZ, DamageCaused, bPerfectAccuracy, Weapon, PedIndex, isAudible, isInvisible, InitialVelocity, p13);
	}

	static void LUA_NATIVE_MISC_FIRE_SINGLE_BULLET(uintptr_t args)
	{
		MISC::FIRE_SINGLE_BULLET((Any*)args);
	}

	static std::tuple<Vector3, Vector3> LUA_NATIVE_MISC_GET_MODEL_DIMENSIONS(Hash ModelHashKey, Vector3 returnMin, Vector3 returnMax)
	{
		std::tuple<Vector3, Vector3> return_values;
		MISC::GET_MODEL_DIMENSIONS(ModelHashKey, &returnMin, &returnMax);
		std::get<0>(return_values) = returnMin;
		std::get<1>(return_values) = returnMax;

		return return_values;
	}

	static bool LUA_NATIVE_MISC_IS_BIT_SET(int address, int offset)
	{
		auto retval = (bool)MISC::IS_BIT_SET(address, offset);
		return retval;
	}

	static void LUA_NATIVE_MISC__0x0A487CC74A517FB5(Any p0)
	{
		MISC::_0x0A487CC74A517FB5(p0);
	}

	static bool LUA_NATIVE_MISC_IS_MINIGAME_IN_PROGRESS()
	{
		auto retval = (bool)MISC::IS_MINIGAME_IN_PROGRESS();
		return retval;
	}

	static bool LUA_NATIVE_MISC_SHOULD_USE_METRIC_MEASUREMENTS()
	{
		auto retval = (bool)MISC::SHOULD_USE_METRIC_MEASUREMENTS();
		return retval;
	}

	static bool LUA_NATIVE_MISC__SHOULD_USE_METRIC_MEASUREMENTS_2()
	{
		auto retval = (bool)MISC::_SHOULD_USE_METRIC_MEASUREMENTS_2();
		return retval;
	}

	static bool LUA_NATIVE_MISC__SHOULD_USE_METRIC_TEMPERATURE()
	{
		auto retval = (bool)MISC::_SHOULD_USE_METRIC_TEMPERATURE();
		return retval;
	}

	static bool LUA_NATIVE_MISC__SHOULD_USE_METRIC_WEIGHT()
	{
		auto retval = (bool)MISC::_SHOULD_USE_METRIC_WEIGHT();
		return retval;
	}

	static bool LUA_NATIVE_MISC__SHOULD_USE_24_HOUR_CLOCK()
	{
		auto retval = (bool)MISC::_SHOULD_USE_24_HOUR_CLOCK();
		return retval;
	}

	static int LUA_NATIVE_MISC_COMPARE_STRINGS(sol::stack_object String1, sol::stack_object String2, bool bCaseSensitive, int numberOfCharactersToCompare)
	{
		auto retval = MISC::COMPARE_STRINGS(String1.is<const char*>() ? String1.as<const char*>() : nullptr, String2.is<const char*>() ? String2.as<const char*>() : nullptr, bCaseSensitive, numberOfCharactersToCompare);
		return retval;
	}

	static int LUA_NATIVE_MISC_ABSI(int n)
	{
		auto retval = MISC::ABSI(n);
		return retval;
	}

	static float LUA_NATIVE_MISC_ABSF(float n)
	{
		auto retval = MISC::ABSF(n);
		return retval;
	}

	static bool LUA_NATIVE_MISC_IS_PROJECTILE_IN_AREA(float VecMinCoorsX, float VecMinCoorsY, float VecMinCoorsZ, float VecMaxCoorsX, float VecMaxCoorsY, float VecMaxCoorsZ, bool bIsPlayer)
	{
		auto retval = (bool)MISC::IS_PROJECTILE_IN_AREA(VecMinCoorsX, VecMinCoorsY, VecMinCoorsZ, VecMaxCoorsX, VecMaxCoorsY, VecMaxCoorsZ, bIsPlayer);
		return retval;
	}

	static bool LUA_NATIVE_MISC_IS_PROJECTILE_TYPE_IN_AREA(float VecMinCoorsX, float VecMinCoorsY, float VecMinCoorsZ, float VecMaxCoorsX, float VecMaxCoorsY, float VecMaxCoorsZ, Hash WeaponType, bool bIsPlayer)
	{
		auto retval = (bool)MISC::IS_PROJECTILE_TYPE_IN_AREA(VecMinCoorsX, VecMinCoorsY, VecMinCoorsZ, VecMaxCoorsX, VecMaxCoorsY, VecMaxCoorsZ, WeaponType, bIsPlayer);
		return retval;
	}

	static bool LUA_NATIVE_MISC_IS_PROJECTILE_TYPE_IN_ANGLED_AREA(float vecAngledAreaPoint1X, float vecAngledAreaPoint1Y, float vecAngledAreaPoint1Z, float vecAngledAreaPoint2X, float vecAngledAreaPoint2Y, float vecAngledAreaPoint2Z, float DistanceOfOppositeFace, Hash WeaponType, bool bIsPlayer)
	{
		auto retval = (bool)MISC::IS_PROJECTILE_TYPE_IN_ANGLED_AREA(vecAngledAreaPoint1X, vecAngledAreaPoint1Y, vecAngledAreaPoint1Z, vecAngledAreaPoint2X, vecAngledAreaPoint2Y, vecAngledAreaPoint2Z, DistanceOfOppositeFace, WeaponType, bIsPlayer);
		return retval;
	}

	static bool LUA_NATIVE_MISC_IS_PROJECTILE_TYPE_WITHIN_DISTANCE(float vecCoorsX, float vecCoorsY, float vecCoorsZ, Hash WeaponType, float distance, bool bIsPlayer)
	{
		auto retval = (bool)MISC::IS_PROJECTILE_TYPE_WITHIN_DISTANCE(vecCoorsX, vecCoorsY, vecCoorsZ, WeaponType, distance, bIsPlayer);
		return retval;
	}

	static std::tuple<bool, Vector3> LUA_NATIVE_MISC_GET_COORDS_OF_PROJECTILE_TYPE_WITHIN_DISTANCE(Ped ped, Hash WeaponType, float distance, Vector3 positionOut, bool needsToBeStationary, bool mustBeOwnedByThisPed)
	{
		std::tuple<bool, Vector3> return_values;
		std::get<0>(return_values) = (bool)MISC::GET_COORDS_OF_PROJECTILE_TYPE_WITHIN_DISTANCE(ped, WeaponType, distance, &positionOut, needsToBeStationary, mustBeOwnedByThisPed);
		std::get<1>(return_values) = positionOut;

		return return_values;
	}

	static std::tuple<bool, Vector3, Entity> LUA_NATIVE_MISC_GET_PROJECTILE_OF_PROJECTILE_TYPE_WITHIN_DISTANCE(Ped ped, Hash WeaponType, float distance, Vector3 positionOut, Entity EntityIndex, bool needsToBeStationary, bool mustBeOwnedByThisPed)
	{
		std::tuple<bool, Vector3, Entity> return_values;
		std::get<0>(return_values) = (bool)MISC::GET_PROJECTILE_OF_PROJECTILE_TYPE_WITHIN_DISTANCE(ped, WeaponType, distance, &positionOut, &EntityIndex, needsToBeStationary, mustBeOwnedByThisPed);
		std::get<1>(return_values) = positionOut;
		std::get<2>(return_values) = EntityIndex;

		return return_values;
	}

	static bool LUA_NATIVE_MISC_IS_BULLET_IN_ANGLED_AREA(float VecPos1X, float VecPos1Y, float VecPos1Z, float VecPos2X, float VecPos2Y, float VecPos2Z, float AreaWidth, bool bIsPlayer)
	{
		auto retval = (bool)MISC::IS_BULLET_IN_ANGLED_AREA(VecPos1X, VecPos1Y, VecPos1Z, VecPos2X, VecPos2Y, VecPos2Z, AreaWidth, bIsPlayer);
		return retval;
	}

	static bool LUA_NATIVE_MISC_IS_BULLET_IN_AREA(float VecCoorsX, float VecCoorsY, float VecCoorsZ, float Radius, bool bIsPlayer)
	{
		auto retval = (bool)MISC::IS_BULLET_IN_AREA(VecCoorsX, VecCoorsY, VecCoorsZ, Radius, bIsPlayer);
		return retval;
	}

	static bool LUA_NATIVE_MISC_IS_BULLET_IN_BOX(float VecMinCoorsX, float VecMinCoorsY, float VecMinCoorsZ, float VecMaxCoorsX, float VecMaxCoorsY, float VecMaxCoorsZ, bool bIsPlayer)
	{
		auto retval = (bool)MISC::IS_BULLET_IN_BOX(VecMinCoorsX, VecMinCoorsY, VecMinCoorsZ, VecMaxCoorsX, VecMaxCoorsY, VecMaxCoorsZ, bIsPlayer);
		return retval;
	}

	static bool LUA_NATIVE_MISC_HAS_BULLET_IMPACTED_IN_AREA(float VecCoorsX, float VecCoorsY, float VecCoorsZ, float Radius, bool bIsPlayer, bool bEntryOnly)
	{
		auto retval = (bool)MISC::HAS_BULLET_IMPACTED_IN_AREA(VecCoorsX, VecCoorsY, VecCoorsZ, Radius, bIsPlayer, bEntryOnly);
		return retval;
	}

	static bool LUA_NATIVE_MISC_HAS_BULLET_IMPACTED_IN_BOX(float VecMinCoorsX, float VecMinCoorsY, float VecMinCoorsZ, float VecMaxCoorsX, float VecMaxCoorsY, float VecMaxCoorsZ, bool bIsPlayer, bool bEntryOnly)
	{
		auto retval = (bool)MISC::HAS_BULLET_IMPACTED_IN_BOX(VecMinCoorsX, VecMinCoorsY, VecMinCoorsZ, VecMaxCoorsX, VecMaxCoorsY, VecMaxCoorsZ, bIsPlayer, bEntryOnly);
		return retval;
	}

	static Any LUA_NATIVE_MISC__0x7A76104CC2CC69E8(Entity entity, int p1, int p2)
	{
		auto retval = MISC::_0x7A76104CC2CC69E8(entity, p1, p2);
		return retval;
	}

	static Any LUA_NATIVE_MISC__0xDC416CA762BC4F43(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5)
	{
		auto retval = MISC::_0xDC416CA762BC4F43(p0, p1, p2, p3, p4, p5);
		return retval;
	}

	static Any LUA_NATIVE_MISC__0x970339EFA4FDE518(Any p0, Any p1, Any p2)
	{
		auto retval = MISC::_0x970339EFA4FDE518(p0, p1, p2);
		return retval;
	}

	static bool LUA_NATIVE_MISC_IS_ORBIS_VERSION()
	{
		auto retval = (bool)MISC::IS_ORBIS_VERSION();
		return retval;
	}

	static bool LUA_NATIVE_MISC_IS_DURANGO_VERSION()
	{
		auto retval = (bool)MISC::IS_DURANGO_VERSION();
		return retval;
	}

	static bool LUA_NATIVE_MISC_IS_PC_VERSION()
	{
		auto retval = (bool)MISC::IS_PC_VERSION();
		return retval;
	}

	static bool LUA_NATIVE_MISC_IS_STADIA_VERSION()
	{
		auto retval = (bool)MISC::IS_STADIA_VERSION();
		return retval;
	}

	static bool LUA_NATIVE_MISC_IS_STRING_NULL(sol::stack_object StringToTest)
	{
		auto retval = (bool)MISC::IS_STRING_NULL(StringToTest.is<const char*>() ? StringToTest.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_MISC_IS_STRING_NULL_OR_EMPTY(sol::stack_object StringToTest)
	{
		auto retval = (bool)MISC::IS_STRING_NULL_OR_EMPTY(StringToTest.is<const char*>() ? StringToTest.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_MISC_IS_STRING_NULL_OR_EMPTY_OR_SPACES(sol::stack_object string)
	{
		auto retval = (bool)MISC::IS_STRING_NULL_OR_EMPTY_OR_SPACES(string.is<const char*>() ? string.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_MISC_ARE_STRINGS_EQUAL(sol::stack_object String1, sol::stack_object String2)
	{
		auto retval = (bool)MISC::ARE_STRINGS_EQUAL(String1.is<const char*>() ? String1.as<const char*>() : nullptr, String2.is<const char*>() ? String2.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_MISC__DOES_STRING_EXIST_IN_STRING(sol::stack_object string1, sol::stack_object string2)
	{
		auto retval = (bool)MISC::_DOES_STRING_EXIST_IN_STRING(string1.is<const char*>() ? string1.as<const char*>() : nullptr, string2.is<const char*>() ? string2.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_MISC__0x3C3C7B1B5EC08764()
	{
		MISC::_0x3C3C7B1B5EC08764();
	}

	static Any LUA_NATIVE_MISC__0x94E8CA3DEE952789(Any p0, Any p1)
	{
		auto retval = MISC::_0x94E8CA3DEE952789(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_MISC__0x5B4A8121A47D844D(Any p0)
	{
		auto retval = MISC::_0x5B4A8121A47D844D(p0);
		return retval;
	}

	static std::tuple<bool, int> LUA_NATIVE_MISC_STRING_TO_INT(sol::stack_object StringToConvert, int ReturnInteger)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)MISC::STRING_TO_INT(StringToConvert.is<const char*>() ? StringToConvert.as<const char*>() : nullptr, &ReturnInteger);
		std::get<1>(return_values) = ReturnInteger;

		return return_values;
	}

	static char LUA_NATIVE_MISC__INT_TO_STRING(int value, sol::stack_object format, char buffer)
	{
		MISC::_INT_TO_STRING(value, format.is<const char*>() ? format.as<const char*>() : nullptr, &buffer);
		return buffer;
	}

	static void LUA_NATIVE_MISC__0x74ACA66484CEBAF0(Any p0)
	{
		MISC::_0x74ACA66484CEBAF0(p0);
	}

	static void LUA_NATIVE_MISC__0x49C44FE78A135A1D(Any p0)
	{
		MISC::_0x49C44FE78A135A1D(p0);
	}

	static void LUA_NATIVE_MISC__0xF650DCF5D6F312C1(Any p0)
	{
		MISC::_0xF650DCF5D6F312C1(p0);
	}

	static const char* LUA_NATIVE_MISC__GET_STRING_FROM_FLOAT(float value, int digits)
	{
		auto retval = MISC::_GET_STRING_FROM_FLOAT(value, digits);
		return retval;
	}

	static const char* LUA_NATIVE_MISC__GET_STRING_FROM_VECTOR(float x, float y, float z)
	{
		auto retval = MISC::_GET_STRING_FROM_VECTOR(x, y, z);
		return retval;
	}

	static const char* LUA_NATIVE_MISC__GET_STRING_FROM_BOOL(bool value)
	{
		auto retval = MISC::_GET_STRING_FROM_BOOL(value);
		return retval;
	}

	static const char* LUA_NATIVE_MISC__CREATE_COLOR_STRING(int rgb)
	{
		auto retval = MISC::_CREATE_COLOR_STRING(rgb);
		return retval;
	}

	static int LUA_NATIVE_MISC_SET_BITS_IN_RANGE(int VariableToChange, int StartBit, int EndBit, int NewValue)
	{
		MISC::SET_BITS_IN_RANGE(&VariableToChange, StartBit, EndBit, NewValue);
		return VariableToChange;
	}

	static int LUA_NATIVE_MISC_GET_BITS_IN_RANGE(int VariableToRead, int StartBit, int EndBit)
	{
		auto retval = MISC::GET_BITS_IN_RANGE(VariableToRead, StartBit, EndBit);
		return retval;
	}

	static void LUA_NATIVE_MISC_SET_GAME_PAUSED(bool bDoPause)
	{
		MISC::SET_GAME_PAUSED(bDoPause);
	}

	static void LUA_NATIVE_MISC_SET_THIS_SCRIPT_CAN_BE_PAUSED(bool bScriptCanBePaused)
	{
		MISC::SET_THIS_SCRIPT_CAN_BE_PAUSED(bScriptCanBePaused);
	}

	static void LUA_NATIVE_MISC_SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(bool bCanRemoveBlipsCreatedByOtherScripts)
	{
		MISC::SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(bCanRemoveBlipsCreatedByOtherScripts);
	}

	static void LUA_NATIVE_MISC_SET_CHEAT_ACTIVE(int cheatId)
	{
		MISC::SET_CHEAT_ACTIVE(cheatId);
	}

	static void LUA_NATIVE_MISC__0xB711EB4BC8D06013()
	{
		MISC::_0xB711EB4BC8D06013();
	}

	static void LUA_NATIVE_MISC_POPULATE_NOW()
	{
		MISC::POPULATE_NOW();
	}

	static bool LUA_NATIVE_MISC_IS_GAME_SESSION_STATE_MACHINE_IDLE()
	{
		auto retval = (bool)MISC::IS_GAME_SESSION_STATE_MACHINE_IDLE();
		return retval;
	}

	static bool LUA_NATIVE_MISC__QUEUE_SAVEGAME_OPERATION(int p0)
	{
		auto retval = (bool)MISC::_QUEUE_SAVEGAME_OPERATION(p0);
		return retval;
	}

	static int LUA_NATIVE_MISC__GET_STATUS_OF_SAVEGAME_OPERATION(int p0)
	{
		auto retval = MISC::_GET_STATUS_OF_SAVEGAME_OPERATION(p0);
		return retval;
	}

	static Any LUA_NATIVE_MISC__0x6C7B68D3CE60E8DE(Any p0)
	{
		auto retval = MISC::_0x6C7B68D3CE60E8DE(p0);
		return retval;
	}

	static Any LUA_NATIVE_MISC__0x627B68D9CE6EE8DE(Any p0)
	{
		auto retval = MISC::_0x627B68D9CE6EE8DE(p0);
		return retval;
	}

	static Any LUA_NATIVE_MISC__0x7CF96F1250EF3221(Any p0)
	{
		auto retval = MISC::_0x7CF96F1250EF3221(p0);
		return retval;
	}

	static void LUA_NATIVE_MISC_COPY_SCRIPT_STRUCT(uintptr_t DestStruct, uintptr_t SourceStruct, int Size)
	{
		MISC::COPY_SCRIPT_STRUCT((Any*)DestStruct, (Any*)SourceStruct, Size);
	}

	static void LUA_NATIVE_MISC_ENABLE_DISPATCH_SERVICE(int dispatchType, bool bEnable)
	{
		MISC::ENABLE_DISPATCH_SERVICE(dispatchType, bEnable);
	}

	static void LUA_NATIVE_MISC_BLOCK_DISPATCH_SERVICE_RESOURCE_CREATION(int dispatchType, bool bBlock)
	{
		MISC::BLOCK_DISPATCH_SERVICE_RESOURCE_CREATION(dispatchType, bBlock);
	}

	static std::tuple<bool, int> LUA_NATIVE_MISC_CREATE_INCIDENT(int dispatchType, float vLocationX, float vLocationY, float vLocationZ, int iNumUnits, float fTime, int incidentIndex, Hash iOverrideRelGroupHash, int assassinsLevel)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)MISC::CREATE_INCIDENT(dispatchType, vLocationX, vLocationY, vLocationZ, iNumUnits, fTime, &incidentIndex, iOverrideRelGroupHash, assassinsLevel);
		std::get<1>(return_values) = incidentIndex;

		return return_values;
	}

	static std::tuple<bool, int> LUA_NATIVE_MISC__CREATE_INCIDENT_WITH_ENTITIES(int dispatchService, float x, float y, float z, ItemSet itemSet, float radius, int outIncidentID)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)MISC::_CREATE_INCIDENT_WITH_ENTITIES(dispatchService, x, y, z, itemSet, radius, &outIncidentID);
		std::get<1>(return_values) = outIncidentID;

		return return_values;
	}

	static void LUA_NATIVE_MISC_DELETE_INCIDENT(int incidentIndex)
	{
		MISC::DELETE_INCIDENT(incidentIndex);
	}

	static bool LUA_NATIVE_MISC_IS_INCIDENT_VALID(int incidentIndex)
	{
		auto retval = (bool)MISC::IS_INCIDENT_VALID(incidentIndex);
		return retval;
	}

	static void LUA_NATIVE_MISC__SET_INCIDENT_UNK(int incidentId)
	{
		MISC::_SET_INCIDENT_UNK(incidentId);
	}

	static int LUA_NATIVE_MISC_ADD_POP_MULTIPLIER_AREA(float minWSX, float minWSY, float minWSZ, float maxWSX, float maxWSY, float maxWSZ, float pedDensity, float trafficDensity, bool localOnly, bool bCameraGlobalMultiplier)
	{
		auto retval = MISC::ADD_POP_MULTIPLIER_AREA(minWSX, minWSY, minWSZ, maxWSX, maxWSY, maxWSZ, pedDensity, trafficDensity, localOnly, bCameraGlobalMultiplier);
		return retval;
	}

	static bool LUA_NATIVE_MISC_DOES_POP_MULTIPLIER_AREA_EXIST(int index)
	{
		auto retval = (bool)MISC::DOES_POP_MULTIPLIER_AREA_EXIST(index);
		return retval;
	}

	static void LUA_NATIVE_MISC_REMOVE_POP_MULTIPLIER_AREA(int index, bool localOnly)
	{
		MISC::REMOVE_POP_MULTIPLIER_AREA(index, localOnly);
	}

	static int LUA_NATIVE_MISC__ADD_POP_MULTIPLIER_VOLUME(Volume volume, float pedDensity, float vehicleDensity, bool p3, bool p4)
	{
		auto retval = MISC::_ADD_POP_MULTIPLIER_VOLUME(volume, pedDensity, vehicleDensity, p3, p4);
		return retval;
	}

	static bool LUA_NATIVE_MISC__DOES_POP_MULTIPLIER_AREA_EXIST_FOR_VOLUME(Volume volume)
	{
		auto retval = (bool)MISC::_DOES_POP_MULTIPLIER_AREA_EXIST_FOR_VOLUME(volume);
		return retval;
	}

	static void LUA_NATIVE_MISC__REMOVE_POP_MULTIPLIER_AREA_FOR_VOLUME(Volume volume, int p1)
	{
		MISC::_REMOVE_POP_MULTIPLIER_AREA_FOR_VOLUME(volume, p1);
	}

	static void LUA_NATIVE_MISC__0xF569E33FB72ED28E()
	{
		MISC::_0xF569E33FB72ED28E();
	}

	static void LUA_NATIVE_MISC_RESET_DISPATCH_IDEAL_SPAWN_DISTANCE()
	{
		MISC::RESET_DISPATCH_IDEAL_SPAWN_DISTANCE();
	}

	static void LUA_NATIVE_MISC_SET_DISPATCH_IDEAL_SPAWN_DISTANCE(float fIdealSpawnDistance)
	{
		MISC::SET_DISPATCH_IDEAL_SPAWN_DISTANCE(fIdealSpawnDistance);
	}

	static void LUA_NATIVE_MISC__RESET_DISPATCH_MIN_SPAWN_DISTANCE()
	{
		MISC::_RESET_DISPATCH_MIN_SPAWN_DISTANCE();
	}

	static void LUA_NATIVE_MISC__SET_DISPATCH_MIN_SPAWN_DISTANCE(float minSpawnDistance)
	{
		MISC::_SET_DISPATCH_MIN_SPAWN_DISTANCE(minSpawnDistance);
	}

	static void LUA_NATIVE_MISC__RESET_DISPATCH_MAX_SPAWN_DISTANCE()
	{
		MISC::_RESET_DISPATCH_MAX_SPAWN_DISTANCE();
	}

	static void LUA_NATIVE_MISC__SET_DISPATCH_MAX_SPAWN_DISTANCE(float maxSpawnDistance)
	{
		MISC::_SET_DISPATCH_MAX_SPAWN_DISTANCE(maxSpawnDistance);
	}

	static void LUA_NATIVE_MISC__0x4B0501A468B749F8()
	{
		MISC::_0x4B0501A468B749F8();
	}

	static void LUA_NATIVE_MISC__0x6BCF7B5CD338281A(Any p0, Any p1, Any p2)
	{
		MISC::_0x6BCF7B5CD338281A(p0, p1, p2);
	}

	static Any LUA_NATIVE_MISC__ADD_DISPATCH_SPAWN_BLOCKING_AREA(Volume volume)
	{
		auto retval = MISC::_ADD_DISPATCH_SPAWN_BLOCKING_AREA(volume);
		return retval;
	}

	static void LUA_NATIVE_MISC_REMOVE_DISPATCH_SPAWN_BLOCKING_AREA(int iIndex)
	{
		MISC::REMOVE_DISPATCH_SPAWN_BLOCKING_AREA(iIndex);
	}

	static void LUA_NATIVE_MISC_RESET_WANTED_RESPONSE_NUM_PEDS_TO_SPAWN()
	{
		MISC::RESET_WANTED_RESPONSE_NUM_PEDS_TO_SPAWN();
	}

	static void LUA_NATIVE_MISC_ADD_TACTICAL_NAV_MESH_POINT(float vPositionX, float vPositionY, float vPositionZ, int p3)
	{
		MISC::ADD_TACTICAL_NAV_MESH_POINT(vPositionX, vPositionY, vPositionZ, p3);
	}

	static void LUA_NATIVE_MISC_CLEAR_TACTICAL_NAV_MESH_POINTS()
	{
		MISC::CLEAR_TACTICAL_NAV_MESH_POINTS();
	}

	static void LUA_NATIVE_MISC_DISPLAY_ONSCREEN_KEYBOARD(int keyboardTypeFlag, sol::stack_object prompt, sol::stack_object description, sol::stack_object initialValue1, sol::stack_object initialValue2, sol::stack_object initialValue3, sol::stack_object initialValue4, int maxLength)
	{
		MISC::DISPLAY_ONSCREEN_KEYBOARD(keyboardTypeFlag, prompt.is<const char*>() ? prompt.as<const char*>() : nullptr, description.is<const char*>() ? description.as<const char*>() : nullptr, initialValue1.is<const char*>() ? initialValue1.as<const char*>() : nullptr, initialValue2.is<const char*>() ? initialValue2.as<const char*>() : nullptr, initialValue3.is<const char*>() ? initialValue3.as<const char*>() : nullptr, initialValue4.is<const char*>() ? initialValue4.as<const char*>() : nullptr, maxLength);
	}

	static int LUA_NATIVE_MISC_UPDATE_ONSCREEN_KEYBOARD()
	{
		auto retval = MISC::UPDATE_ONSCREEN_KEYBOARD();
		return retval;
	}

	static const char* LUA_NATIVE_MISC_GET_ONSCREEN_KEYBOARD_RESULT()
	{
		auto retval = MISC::GET_ONSCREEN_KEYBOARD_RESULT();
		return retval;
	}

	static void LUA_NATIVE_MISC_CANCEL_ONSCREEN_KEYBOARD()
	{
		MISC::CANCEL_ONSCREEN_KEYBOARD();
	}

	static void LUA_NATIVE_MISC_NEXT_ONSCREEN_KEYBOARD_RESULT_WILL_DISPLAY_USING_THESE_FONTS(int fontBitField)
	{
		MISC::NEXT_ONSCREEN_KEYBOARD_RESULT_WILL_DISPLAY_USING_THESE_FONTS(fontBitField);
	}

	static void LUA_NATIVE_MISC_ACTION_MANAGER_ENABLE_ACTION(Hash iActionHash, bool bEnable)
	{
		MISC::ACTION_MANAGER_ENABLE_ACTION(iActionHash, bEnable);
	}

	static bool LUA_NATIVE_MISC_ACTION_MANAGER_IS_ACTION_ENABLED(Hash hash)
	{
		auto retval = (bool)MISC::ACTION_MANAGER_IS_ACTION_ENABLED(hash);
		return retval;
	}

	static int LUA_NATIVE_MISC_GET_REAL_WORLD_TIME()
	{
		auto retval = MISC::GET_REAL_WORLD_TIME();
		return retval;
	}

	static void LUA_NATIVE_MISC_SET_SUPER_JUMP_THIS_FRAME(Ped PedIndex)
	{
		MISC::SET_SUPER_JUMP_THIS_FRAME(PedIndex);
	}

	static void LUA_NATIVE_MISC_SCRIPT_RACE_INIT(int numCheckpoints, int numLaps, int numPlayers, int localPlayerIndex)
	{
		MISC::SCRIPT_RACE_INIT(numCheckpoints, numLaps, numPlayers, localPlayerIndex);
	}

	static void LUA_NATIVE_MISC_SCRIPT_RACE_SHUTDOWN()
	{
		MISC::SCRIPT_RACE_SHUTDOWN();
	}

	static void LUA_NATIVE_MISC_SCRIPT_RACE_PLAYER_HIT_CHECKPOINT(Ped pedIndex, int checkpoint, int lap, int time)
	{
		MISC::SCRIPT_RACE_PLAYER_HIT_CHECKPOINT(pedIndex, checkpoint, lap, time);
	}

	static std::tuple<bool, int, int> LUA_NATIVE_MISC_SCRIPT_RACE_GET_PLAYER_SPLIT_TIME(Ped pedIndex, int time, int position)
	{
		std::tuple<bool, int, int> return_values;
		std::get<0>(return_values) = (bool)MISC::SCRIPT_RACE_GET_PLAYER_SPLIT_TIME(pedIndex, &time, &position);
		std::get<1>(return_values) = time;
		std::get<2>(return_values) = position;

		return return_values;
	}

	static void LUA_NATIVE_MISC_START_END_USER_BENCHMARK()
	{
		MISC::START_END_USER_BENCHMARK();
	}

	static void LUA_NATIVE_MISC_STOP_END_USER_BENCHMARK()
	{
		MISC::STOP_END_USER_BENCHMARK();
	}

	static void LUA_NATIVE_MISC_RESET_END_USER_BENCHMARK()
	{
		MISC::RESET_END_USER_BENCHMARK();
	}

	static void LUA_NATIVE_MISC_SAVE_END_USER_BENCHMARK()
	{
		MISC::SAVE_END_USER_BENCHMARK();
	}

	static bool LUA_NATIVE_MISC_UI_STARTED_END_USER_BENCHMARK()
	{
		auto retval = (bool)MISC::UI_STARTED_END_USER_BENCHMARK();
		return retval;
	}

	static int LUA_NATIVE_MISC_GET_BENCHMARK_ITERATIONS()
	{
		auto retval = MISC::GET_BENCHMARK_ITERATIONS();
		return retval;
	}

	static int LUA_NATIVE_MISC_GET_BENCHMARK_PASS()
	{
		auto retval = MISC::GET_BENCHMARK_PASS();
		return retval;
	}

	static Any LUA_NATIVE_MISC__0xDC057B86FC157031()
	{
		auto retval = MISC::_0xDC057B86FC157031();
		return retval;
	}

	static void LUA_NATIVE_MISC__0x9A252AA23D7098F2()
	{
		MISC::_0x9A252AA23D7098F2();
	}

	static bool LUA_NATIVE_MISC__DOES_ITEM_HAVE_VALID_BASE(ScrHandle item)
	{
		auto retval = (bool)MISC::_DOES_ITEM_HAVE_VALID_BASE(item);
		return retval;
	}

	static int LUA_NATIVE_MISC__GET_ITEM_TYPE(ScrHandle handle)
	{
		auto retval = MISC::_GET_ITEM_TYPE(handle);
		return retval;
	}

	static bool LUA_NATIVE_MISC__IS_BASE_A_PERSISTENT_CHARACTER(ScrHandle handle)
	{
		auto retval = (bool)MISC::_IS_BASE_A_PERSISTENT_CHARACTER(handle);
		return retval;
	}

	static bool LUA_NATIVE_MISC__IS_BASE_A_COVER_POINT(ScrHandle handle)
	{
		auto retval = (bool)MISC::_IS_BASE_A_COVER_POINT(handle);
		return retval;
	}

	static void LUA_NATIVE_MISC__0x553D67295DDD2309(Entity entity)
	{
		MISC::_0x553D67295DDD2309(entity);
	}

	static Volume LUA_NATIVE_MISC__GET_VOLUME_FROM_INDEXED_ITEM(ScrHandle item)
	{
		auto retval = MISC::_GET_VOLUME_FROM_INDEXED_ITEM(item);
		return retval;
	}

	static Entity LUA_NATIVE_MISC__GET_ENTITY_FROM_ITEM(ScrHandle item)
	{
		auto retval = MISC::_GET_ENTITY_FROM_ITEM(item);
		return retval;
	}

	static Ped LUA_NATIVE_MISC__GET_PED_FROM_INDEXED_ITEM(ScrHandle item)
	{
		auto retval = MISC::_GET_PED_FROM_INDEXED_ITEM(item);
		return retval;
	}

	static Vehicle LUA_NATIVE_MISC__GET_VEHICLE_FROM_INDEXED_ITEM(ScrHandle item)
	{
		auto retval = MISC::_GET_VEHICLE_FROM_INDEXED_ITEM(item);
		return retval;
	}

	static Object LUA_NATIVE_MISC__GET_OBJECT_FROM_INDEXED_ITEM(ScrHandle item)
	{
		auto retval = MISC::_GET_OBJECT_FROM_INDEXED_ITEM(item);
		return retval;
	}

	static Any LUA_NATIVE_MISC__0x33982467B1E349EF(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6)
	{
		auto retval = MISC::_0x33982467B1E349EF(p0, p1, p2, p3, p4, p5, p6);
		return retval;
	}

	static Any LUA_NATIVE_MISC__0x8314FC2013ECE2DA(Any p0, Any p1, Any p2)
	{
		auto retval = MISC::_0x8314FC2013ECE2DA(p0, p1, p2);
		return retval;
	}

	static void LUA_NATIVE_MISC__0x4D5C9CC7E7E23E09()
	{
		MISC::_0x4D5C9CC7E7E23E09();
	}

	static bool LUA_NATIVE_MISC_REGISTER_INTERACTION_LOCKON_PROMPT(Entity entity, sol::stack_object text, float radius, float p3, int flag, float p5, float p6, Prompt prompt, bool p8, int p9)
	{
		auto retval = (bool)MISC::REGISTER_INTERACTION_LOCKON_PROMPT(entity, text.is<const char*>() ? text.as<const char*>() : nullptr, radius, p3, flag, p5, p6, prompt, p8, p9);
		return retval;
	}

	static bool LUA_NATIVE_MISC_UNREGISTER_INTERACTION_LOCKON_PROMPT(Entity entity)
	{
		auto retval = (bool)MISC::UNREGISTER_INTERACTION_LOCKON_PROMPT(entity);
		return retval;
	}

	static void LUA_NATIVE_MISC__0xFC6ECB9170145ECE()
	{
		MISC::_0xFC6ECB9170145ECE();
	}

	static Any LUA_NATIVE_MISC__0x35165C658077CD0B()
	{
		auto retval = MISC::_0x35165C658077CD0B();
		return retval;
	}

	static bool LUA_NATIVE_MISC__0x4B101DBCC9482F2D(Ped ped)
	{
		auto retval = (bool)MISC::_0x4B101DBCC9482F2D(ped);
		return retval;
	}

	static bool LUA_NATIVE_MISC__IS_MISSION_CREATOR_ACTIVE()
	{
		auto retval = (bool)MISC::_IS_MISSION_CREATOR_ACTIVE();
		return retval;
	}

	static void LUA_NATIVE_MISC__0xA3A8926951471C82()
	{
		MISC::_0xA3A8926951471C82();
	}

	static void LUA_NATIVE_MISC__CREATE_AI_MEMORY(uintptr_t args, int aiMemoryType)
	{
		MISC::_CREATE_AI_MEMORY((Any*)args, aiMemoryType);
	}

	static bool LUA_NATIVE_MISC__GET_AI_PED_DOES_HAVE_EVENT_MEMORY(uintptr_t args, int p1)
	{
		auto retval = (bool)MISC::_GET_AI_PED_DOES_HAVE_EVENT_MEMORY((Any*)args, p1);
		return retval;
	}

	static void LUA_NATIVE_MISC__0xEB946B9E579729AD(Ped ped, Any p1)
	{
		MISC::_0xEB946B9E579729AD(ped, p1);
	}

	static void LUA_NATIVE_MISC__SET_AI_MEMORY_REACTIONS_ENABLED(bool enabled)
	{
		MISC::_SET_AI_MEMORY_REACTIONS_ENABLED(enabled);
	}

	static Any LUA_NATIVE_MISC__0x8DB104CCEBCD58C5(Any p0, Any p1)
	{
		auto retval = MISC::_0x8DB104CCEBCD58C5(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_MISC__0x68319452C5064ABA(Any p0, Any p1)
	{
		MISC::_0x68319452C5064ABA(p0, p1);
	}

	static void LUA_NATIVE_MISC__0xDE2C3B74D2B3705C(Any p0, Any p1)
	{
		MISC::_0xDE2C3B74D2B3705C(p0, p1);
	}

	static void LUA_NATIVE_MISC__0x49F3241C28EBBFBC(int p0)
	{
		MISC::_0x49F3241C28EBBFBC(p0);
	}

	static void LUA_NATIVE_MISC__0x183672FE838A661B(uintptr_t data)
	{
		MISC::_0x183672FE838A661B((Any*)data);
	}

	static void LUA_NATIVE_MISC__0x38C0C9CAE1544500(Hash p0)
	{
		MISC::_0x38C0C9CAE1544500(p0);
	}

	static void LUA_NATIVE_MISC__0x154340E87D8CC178(Any p0)
	{
		MISC::_0x154340E87D8CC178(p0);
	}

	static void LUA_NATIVE_MISC__0x94FCADCF9F0C368E(Any p0)
	{
		MISC::_0x94FCADCF9F0C368E(p0);
	}

	static bool LUA_NATIVE_MISC__0x0D0AE5081F88CFE1(Hash p0)
	{
		auto retval = (bool)MISC::_0x0D0AE5081F88CFE1(p0);
		return retval;
	}

	static void LUA_NATIVE_MISC__0xAF3A84C7DE6A1DC5(Any p0, Any p1)
	{
		MISC::_0xAF3A84C7DE6A1DC5(p0, p1);
	}

	static void LUA_NATIVE_MISC__LOOT_TABLES_GET_INFO(Ped ped, bool p1, bool p2, Hash lootTableKey, uintptr_t p4, Any p5)
	{
		MISC::_LOOT_TABLES_GET_INFO(ped, p1, p2, lootTableKey, (Any*)p4, p5);
	}

	static Any LUA_NATIVE_MISC__0xB1F6665AA54DCD5C(Any p0)
	{
		auto retval = MISC::_0xB1F6665AA54DCD5C(p0);
		return retval;
	}

	static Any LUA_NATIVE_MISC__0x8BB99B85444544D9(Any p0, Any p1)
	{
		auto retval = MISC::_0x8BB99B85444544D9(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_MISC__0x6F02B5E50511721E(Any p0)
	{
		auto retval = MISC::_0x6F02B5E50511721E(p0);
		return retval;
	}

	static Any LUA_NATIVE_MISC__0xCC1BAF72D571DB8D(Any p0, Any p1, Any p2)
	{
		auto retval = MISC::_0xCC1BAF72D571DB8D(p0, p1, p2);
		return retval;
	}

	static bool LUA_NATIVE_MISC__IS_PED_DECOMPOSED(Ped ped)
	{
		auto retval = (bool)MISC::_IS_PED_DECOMPOSED(ped);
		return retval;
	}

	static void LUA_NATIVE_MISC_SET_PED_DECOMPOSED(Ped ped, bool toggle)
	{
		MISC::SET_PED_DECOMPOSED(ped, toggle);
	}

	static void LUA_NATIVE_MISC__0xAB26DEEE120FD3FD(Any p0, Any p1)
	{
		MISC::_0xAB26DEEE120FD3FD(p0, p1);
	}

	static void LUA_NATIVE_MISC__0x082C043C7AFC3747(int compositeId, bool p1)
	{
		MISC::_0x082C043C7AFC3747(compositeId, p1);
	}

	static void LUA_NATIVE_MISC_DISABLE_LOOTING_COMPOSITE_LOOTABLE_THIS_FRAME(int compositeId, bool p1)
	{
		MISC::DISABLE_LOOTING_COMPOSITE_LOOTABLE_THIS_FRAME(compositeId, p1);
	}

	static void LUA_NATIVE_MISC__0xBB282CF5D2333FB8(Any p0, Any p1)
	{
		MISC::_0xBB282CF5D2333FB8(p0, p1);
	}

	static void LUA_NATIVE_MISC__0xAD44856A1CD29635(Any p0, Any p1, Any p2)
	{
		MISC::_0xAD44856A1CD29635(p0, p1, p2);
	}

	static Any LUA_NATIVE_MISC__0x38C2BF94D15F464D(Any p0)
	{
		auto retval = MISC::_0x38C2BF94D15F464D(p0);
		return retval;
	}

	static void LUA_NATIVE_MISC__0x3A87FDA8F1B6CDFB(Any p0, Any p1, Any p2)
	{
		MISC::_0x3A87FDA8F1B6CDFB(p0, p1, p2);
	}

	static void LUA_NATIVE_MISC__0x4647842FE8F31C1E(Any p0, Any p1)
	{
		MISC::_0x4647842FE8F31C1E(p0, p1);
	}

	static bool LUA_NATIVE_MISC__GET_LOOTING_EVENT_HAS_FIRED(Ped ped, sol::stack_object eventName)
	{
		auto retval = (bool)MISC::_GET_LOOTING_EVENT_HAS_FIRED(ped, eventName.is<const char*>() ? eventName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_MISC__SET_LOOT_PELT_SATCHEL_ITEM(Ped ped, Any item)
	{
		MISC::_SET_LOOT_PELT_SATCHEL_ITEM(ped, item);
	}

	static void LUA_NATIVE_MISC__0x96282005C5C6801F(Any p0, Any p1)
	{
		MISC::_0x96282005C5C6801F(p0, p1);
	}

	static void LUA_NATIVE_MISC__0xF63FA29D4A9ACA86(Any p0, Any p1)
	{
		MISC::_0xF63FA29D4A9ACA86(p0, p1);
	}

	static void LUA_NATIVE_MISC__0x8C0F6A3D7236DEEB(Any p0, Any p1)
	{
		MISC::_0x8C0F6A3D7236DEEB(p0, p1);
	}

	static void LUA_NATIVE_MISC__0x7FA58CED69405F9A(Any p0, Any p1)
	{
		MISC::_0x7FA58CED69405F9A(p0, p1);
	}

	static void LUA_NATIVE_MISC__0xA08111B053D84B4D(Any p0)
	{
		MISC::_0xA08111B053D84B4D(p0);
	}

	static bool LUA_NATIVE_MISC__IS_GLOBAL_BLOCK_VALID(int index)
	{
		auto retval = (bool)MISC::_IS_GLOBAL_BLOCK_VALID(index);
		return retval;
	}

	static void LUA_NATIVE_MISC__SET_GLOBAL_BLOCK_IS_LOADED(int index, bool toggle)
	{
		MISC::_SET_GLOBAL_BLOCK_IS_LOADED(index, toggle);
	}

	static bool LUA_NATIVE_MISC_GAME_FRAMEWORK_MANAGER_INIT(Hash transitionMode)
	{
		auto retval = (bool)MISC::GAME_FRAMEWORK_MANAGER_INIT(transitionMode);
		return retval;
	}

	static void LUA_NATIVE_MISC__GAME_FRAMEWORK_MANAGER_SHUTDOWN()
	{
		MISC::_GAME_FRAMEWORK_MANAGER_SHUTDOWN();
	}

	static Hash LUA_NATIVE_MISC__GAME_FRAMEWORK_MANAGER_GET_MODE()
	{
		auto retval = MISC::_GAME_FRAMEWORK_MANAGER_GET_MODE();
		return retval;
	}

	static bool LUA_NATIVE_MISC__IS_PLAYER_OWNING_STANDALONE_SP()
	{
		auto retval = (bool)MISC::_IS_PLAYER_OWNING_STANDALONE_SP();
		return retval;
	}

	static Any LUA_NATIVE_MISC__0x0358B8A41916C613(Any p0, Any p1, Any p2, Any p3)
	{
		auto retval = MISC::_0x0358B8A41916C613(p0, p1, p2, p3);
		return retval;
	}

	static void LUA_NATIVE_MISC__SET_GAME_LOGIC_PAUSED()
	{
		MISC::_SET_GAME_LOGIC_PAUSED();
	}

	static void LUA_NATIVE_MISC_STOP_CURRENT_LOADING_PROGRESS_TIMER()
	{
		MISC::STOP_CURRENT_LOADING_PROGRESS_TIMER();
	}

	static void LUA_NATIVE_MISC__0xDBDA48EC456ED908()
	{
		MISC::_0xDBDA48EC456ED908();
	}

	void RegisterNatives_MISC(sol::state& L)
	{
		auto MISC = L["MISC"].get_or_create<sol::table>();
		MISC.set_function("GET_NUMBER_OF_FREE_STACKS_OF_THIS_SIZE", LUA_NATIVE_MISC_GET_NUMBER_OF_FREE_STACKS_OF_THIS_SIZE);
		MISC.set_function("_GET_NUMBER_OF_INSTRUCTIONS", LUA_NATIVE_MISC__GET_NUMBER_OF_INSTRUCTIONS);
		MISC.set_function("_GET_MAX_NUM_INSTRUCTIONS", LUA_NATIVE_MISC__GET_MAX_NUM_INSTRUCTIONS);
		MISC.set_function("IS_MAG_DEMO_1_ACTIVE", LUA_NATIVE_MISC_IS_MAG_DEMO_1_ACTIVE);
		MISC.set_function("SET_RANDOM_SEED", LUA_NATIVE_MISC_SET_RANDOM_SEED);
		MISC.set_function("SET_TIME_SCALE", LUA_NATIVE_MISC_SET_TIME_SCALE);
		MISC.set_function("SET_MISSION_FLAG", LUA_NATIVE_MISC_SET_MISSION_FLAG);
		MISC.set_function("GET_MISSION_FLAG", LUA_NATIVE_MISC_GET_MISSION_FLAG);
		MISC.set_function("_0x5801BE2DF2AF07EC", LUA_NATIVE_MISC__0x5801BE2DF2AF07EC);
		MISC.set_function("SET_RANDOM_EVENT_FLAG", LUA_NATIVE_MISC_SET_RANDOM_EVENT_FLAG);
		MISC.set_function("GET_RANDOM_EVENT_FLAG", LUA_NATIVE_MISC_GET_RANDOM_EVENT_FLAG);
		MISC.set_function("_0x9BF2C0C568C61641", LUA_NATIVE_MISC__0x9BF2C0C568C61641);
		MISC.set_function("ACTIVITY_FEED_CREATE", LUA_NATIVE_MISC_ACTIVITY_FEED_CREATE);
		MISC.set_function("ACTIVITY_FEED_ADD_SUBSTRING_TO_CAPTION", LUA_NATIVE_MISC_ACTIVITY_FEED_ADD_SUBSTRING_TO_CAPTION);
		MISC.set_function("_0xFF252E2BAFB7330F", LUA_NATIVE_MISC__0xFF252E2BAFB7330F);
		MISC.set_function("ACTIVITY_FEED_ACTION_START_WITH_COMMAND_LINE", LUA_NATIVE_MISC_ACTIVITY_FEED_ACTION_START_WITH_COMMAND_LINE);
		MISC.set_function("ACTIVITY_FEED_ACTION_START_WITH_COMMAND_LINE_ADD", LUA_NATIVE_MISC_ACTIVITY_FEED_ACTION_START_WITH_COMMAND_LINE_ADD);
		MISC.set_function("_0xAF530E56505D1BD6", LUA_NATIVE_MISC__0xAF530E56505D1BD6);
		MISC.set_function("ACTIVITY_FEED_POST", LUA_NATIVE_MISC_ACTIVITY_FEED_POST);
		MISC.set_function("_0xF81C53561D15F330", LUA_NATIVE_MISC__0xF81C53561D15F330);
		MISC.set_function("_0x1096603B519C905F", LUA_NATIVE_MISC__0x1096603B519C905F);
		MISC.set_function("_0xCC3EDC5614B03F61", LUA_NATIVE_MISC__0xCC3EDC5614B03F61);
		MISC.set_function("INFORM_CODE_OF_CONTENT_ID_OF_CURRENT_UGC_MISSION", LUA_NATIVE_MISC_INFORM_CODE_OF_CONTENT_ID_OF_CURRENT_UGC_MISSION);
		MISC.set_function("_0xDA4D8EB04E8E2928", LUA_NATIVE_MISC__0xDA4D8EB04E8E2928);
		MISC.set_function("_0xB08C4FA25BC29DB9", LUA_NATIVE_MISC__0xB08C4FA25BC29DB9);
		MISC.set_function("_GET_PREV_WEATHER_TYPE_HASH_NAME", LUA_NATIVE_MISC__GET_PREV_WEATHER_TYPE_HASH_NAME);
		MISC.set_function("_GET_NEXT_WEATHER_TYPE_HASH_NAME", LUA_NATIVE_MISC__GET_NEXT_WEATHER_TYPE_HASH_NAME);
		MISC.set_function("_0x0730E518486DEEC3", LUA_NATIVE_MISC__0x0730E518486DEEC3);
		MISC.set_function("SET_WEATHER_TYPE", LUA_NATIVE_MISC_SET_WEATHER_TYPE);
		MISC.set_function("_SET_WEATHER_TYPE_2", LUA_NATIVE_MISC__SET_WEATHER_TYPE_2);
		MISC.set_function("_GET_RANDOM_WEATHER_TYPE_INDEX", LUA_NATIVE_MISC__GET_RANDOM_WEATHER_TYPE_INDEX);
		MISC.set_function("_GET_RANDOM_WEATHER_TYPE", LUA_NATIVE_MISC__GET_RANDOM_WEATHER_TYPE);
		MISC.set_function("SET_RANDOM_WEATHER_TYPE", LUA_NATIVE_MISC_SET_RANDOM_WEATHER_TYPE);
		MISC.set_function("CLEAR_WEATHER_TYPE_PERSIST", LUA_NATIVE_MISC_CLEAR_WEATHER_TYPE_PERSIST);
		MISC.set_function("_CLEAR_WEATHER_TYPE_PERSIST_OVERTIME", LUA_NATIVE_MISC__CLEAR_WEATHER_TYPE_PERSIST_OVERTIME);
		MISC.set_function("GET_CURR_WEATHER_STATE", LUA_NATIVE_MISC_GET_CURR_WEATHER_STATE);
		MISC.set_function("SET_CURR_WEATHER_STATE", LUA_NATIVE_MISC_SET_CURR_WEATHER_STATE);
		MISC.set_function("_SET_WEATHER_TYPE_FROZEN", LUA_NATIVE_MISC__SET_WEATHER_TYPE_FROZEN);
		MISC.set_function("_GET_FORCED_WEATHER", LUA_NATIVE_MISC__GET_FORCED_WEATHER);
		MISC.set_function("_0x2916B30DC6C41179", LUA_NATIVE_MISC__0x2916B30DC6C41179);
		MISC.set_function("_0xD3F943B88F55376A", LUA_NATIVE_MISC__0xD3F943B88F55376A);
		MISC.set_function("_0x243CEDE8F916B994", LUA_NATIVE_MISC__0x243CEDE8F916B994);
		MISC.set_function("_SET_OVERRIDE_WEATHER", LUA_NATIVE_MISC__SET_OVERRIDE_WEATHER);
		MISC.set_function("CLEAR_OVERRIDE_WEATHER", LUA_NATIVE_MISC_CLEAR_OVERRIDE_WEATHER);
		MISC.set_function("_SET_WEATHER_VARIATION", LUA_NATIVE_MISC__SET_WEATHER_VARIATION);
		MISC.set_function("_CLEAR_WEATHER_VARIATION", LUA_NATIVE_MISC__CLEAR_WEATHER_VARIATION);
		MISC.set_function("WATER_OVERRIDE_SET_SHOREWAVEAMPLITUDE", LUA_NATIVE_MISC_WATER_OVERRIDE_SET_SHOREWAVEAMPLITUDE);
		MISC.set_function("WATER_OVERRIDE_SET_OCEANWAVEMAXAMPLITUDE", LUA_NATIVE_MISC_WATER_OVERRIDE_SET_OCEANWAVEMAXAMPLITUDE);
		MISC.set_function("_GET_TEMPERATURE_AT_COORDS", LUA_NATIVE_MISC__GET_TEMPERATURE_AT_COORDS);
		MISC.set_function("SET_WIND_SPEED", LUA_NATIVE_MISC_SET_WIND_SPEED);
		MISC.set_function("GET_WIND_SPEED", LUA_NATIVE_MISC_GET_WIND_SPEED);
		MISC.set_function("SET_WIND_DIRECTION", LUA_NATIVE_MISC_SET_WIND_DIRECTION);
		MISC.set_function("GET_WIND_DIRECTION", LUA_NATIVE_MISC_GET_WIND_DIRECTION);
		MISC.set_function("SET_RAIN", LUA_NATIVE_MISC_SET_RAIN);
		MISC.set_function("GET_RAIN_LEVEL", LUA_NATIVE_MISC_GET_RAIN_LEVEL);
		MISC.set_function("_0x745808BB01CEC6B9", LUA_NATIVE_MISC__0x745808BB01CEC6B9);
		MISC.set_function("_SET_SNOW_LEVEL", LUA_NATIVE_MISC__SET_SNOW_LEVEL);
		MISC.set_function("GET_SNOW_LEVEL", LUA_NATIVE_MISC_GET_SNOW_LEVEL);
		MISC.set_function("FORCE_LIGHTNING_FLASH", LUA_NATIVE_MISC_FORCE_LIGHTNING_FLASH);
		MISC.set_function("_FORCE_LIGHTNING_FLASH_AT_COORDS", LUA_NATIVE_MISC__FORCE_LIGHTNING_FLASH_AT_COORDS);
		MISC.set_function("_0xA9342743B634A462", LUA_NATIVE_MISC__0xA9342743B634A462);
		MISC.set_function("GET_GAME_TIMER", LUA_NATIVE_MISC_GET_GAME_TIMER);
		MISC.set_function("_GET_GAME_TIMER_NON_SCALED_CLIPPED", LUA_NATIVE_MISC__GET_GAME_TIMER_NON_SCALED_CLIPPED);
		MISC.set_function("GET_SYSTEM_TIME", LUA_NATIVE_MISC_GET_SYSTEM_TIME);
		MISC.set_function("GET_NUMBER_OF_MICROSECONDS_SINCE_LAST_CALL", LUA_NATIVE_MISC_GET_NUMBER_OF_MICROSECONDS_SINCE_LAST_CALL);
		MISC.set_function("GET_SCRIPT_TIME_WITHIN_FRAME_IN_MICROSECONDS", LUA_NATIVE_MISC_GET_SCRIPT_TIME_WITHIN_FRAME_IN_MICROSECONDS);
		MISC.set_function("RESET_SCRIPT_TIME_WITHIN_FRAME", LUA_NATIVE_MISC_RESET_SCRIPT_TIME_WITHIN_FRAME);
		MISC.set_function("GET_FRAME_TIME", LUA_NATIVE_MISC_GET_FRAME_TIME);
		MISC.set_function("GET_SYSTEM_TIME_STEP", LUA_NATIVE_MISC_GET_SYSTEM_TIME_STEP);
		MISC.set_function("GET_FRAME_COUNT", LUA_NATIVE_MISC_GET_FRAME_COUNT);
		MISC.set_function("_0x6BED40493A1AFDB8", LUA_NATIVE_MISC__0x6BED40493A1AFDB8);
		MISC.set_function("_READ_INT_AS_FLOAT", LUA_NATIVE_MISC__READ_INT_AS_FLOAT);
		MISC.set_function("GET_RANDOM_FLOAT_IN_RANGE", LUA_NATIVE_MISC_GET_RANDOM_FLOAT_IN_RANGE);
		MISC.set_function("GET_RANDOM_INT_IN_RANGE", LUA_NATIVE_MISC_GET_RANDOM_INT_IN_RANGE);
		MISC.set_function("GET_GROUND_Z_FOR_3D_COORD", LUA_NATIVE_MISC_GET_GROUND_Z_FOR_3D_COORD);
		MISC.set_function("GET_GROUND_Z_AND_NORMAL_FOR_3D_COORD", LUA_NATIVE_MISC_GET_GROUND_Z_AND_NORMAL_FOR_3D_COORD);
		MISC.set_function("_0xBBE5B63EFFB08E68", LUA_NATIVE_MISC__0xBBE5B63EFFB08E68);
		MISC.set_function("ASIN", LUA_NATIVE_MISC_ASIN);
		MISC.set_function("ACOS", LUA_NATIVE_MISC_ACOS);
		MISC.set_function("TAN", LUA_NATIVE_MISC_TAN);
		MISC.set_function("ATAN", LUA_NATIVE_MISC_ATAN);
		MISC.set_function("ATAN2", LUA_NATIVE_MISC_ATAN2);
		MISC.set_function("GET_DISTANCE_BETWEEN_COORDS", LUA_NATIVE_MISC_GET_DISTANCE_BETWEEN_COORDS);
		MISC.set_function("GET_ANGLE_BETWEEN_2D_VECTORS", LUA_NATIVE_MISC_GET_ANGLE_BETWEEN_2D_VECTORS);
		MISC.set_function("GET_HEADING_FROM_VECTOR_2D", LUA_NATIVE_MISC_GET_HEADING_FROM_VECTOR_2D);
		MISC.set_function("GET_CLOSEST_POINT_ON_LINE", LUA_NATIVE_MISC_GET_CLOSEST_POINT_ON_LINE);
		MISC.set_function("GET_LINE_PLANE_INTERSECTION", LUA_NATIVE_MISC_GET_LINE_PLANE_INTERSECTION);
		MISC.set_function("SET_BIT", LUA_NATIVE_MISC_SET_BIT);
		MISC.set_function("CLEAR_BIT", LUA_NATIVE_MISC_CLEAR_BIT);
		MISC.set_function("_IS_BIT_FLAG_SET", LUA_NATIVE_MISC__IS_BIT_FLAG_SET);
		MISC.set_function("_IS_ANY_BIT_FLAG_SET", LUA_NATIVE_MISC__IS_ANY_BIT_FLAG_SET);
		MISC.set_function("_COUNT_BIT_FLAGS", LUA_NATIVE_MISC__COUNT_BIT_FLAGS);
		MISC.set_function("_SET_BIT_FLAG", LUA_NATIVE_MISC__SET_BIT_FLAG);
		MISC.set_function("_CLEAR_BIT_FLAG", LUA_NATIVE_MISC__CLEAR_BIT_FLAG);
		MISC.set_function("_CLEAR_ALL_BIT_FLAGS", LUA_NATIVE_MISC__CLEAR_ALL_BIT_FLAGS);
		MISC.set_function("GET_HASH_KEY", LUA_NATIVE_MISC_GET_HASH_KEY);
		MISC.set_function("_GET_EASING_CURVE_VALUE", LUA_NATIVE_MISC__GET_EASING_CURVE_VALUE);
		MISC.set_function("IS_POSITION_OCCUPIED", LUA_NATIVE_MISC_IS_POSITION_OCCUPIED);
		MISC.set_function("CLEAR_AREA", LUA_NATIVE_MISC_CLEAR_AREA);
		MISC.set_function("_CLEAR_VOLUME_AREA", LUA_NATIVE_MISC__CLEAR_VOLUME_AREA);
		MISC.set_function("CLEAR_ANGLED_AREA_OF_VEHICLES", LUA_NATIVE_MISC_CLEAR_ANGLED_AREA_OF_VEHICLES);
		MISC.set_function("SET_CREDITS_ACTIVE", LUA_NATIVE_MISC_SET_CREDITS_ACTIVE);
		MISC.set_function("NETWORK_SET_SCRIPT_IS_SAFE_FOR_NETWORK_GAME", LUA_NATIVE_MISC_NETWORK_SET_SCRIPT_IS_SAFE_FOR_NETWORK_GAME);
		MISC.set_function("PAUSE_DEATH_ARREST_RESTART", LUA_NATIVE_MISC_PAUSE_DEATH_ARREST_RESTART);
		MISC.set_function("IGNORE_NEXT_RESTART", LUA_NATIVE_MISC_IGNORE_NEXT_RESTART);
		MISC.set_function("SET_FADE_IN_AFTER_DEATH_ARREST", LUA_NATIVE_MISC_SET_FADE_IN_AFTER_DEATH_ARREST);
		MISC.set_function("SET_FADE_IN_AFTER_LOAD", LUA_NATIVE_MISC_SET_FADE_IN_AFTER_LOAD);
		MISC.set_function("OVERRIDE_SAVE_HOUSE", LUA_NATIVE_MISC_OVERRIDE_SAVE_HOUSE);
		MISC.set_function("SHOOT_SINGLE_BULLET_BETWEEN_COORDS", LUA_NATIVE_MISC_SHOOT_SINGLE_BULLET_BETWEEN_COORDS);
		MISC.set_function("FIRE_SINGLE_BULLET", LUA_NATIVE_MISC_FIRE_SINGLE_BULLET);
		MISC.set_function("GET_MODEL_DIMENSIONS", LUA_NATIVE_MISC_GET_MODEL_DIMENSIONS);
		MISC.set_function("IS_BIT_SET", LUA_NATIVE_MISC_IS_BIT_SET);
		MISC.set_function("_0x0A487CC74A517FB5", LUA_NATIVE_MISC__0x0A487CC74A517FB5);
		MISC.set_function("IS_MINIGAME_IN_PROGRESS", LUA_NATIVE_MISC_IS_MINIGAME_IN_PROGRESS);
		MISC.set_function("SHOULD_USE_METRIC_MEASUREMENTS", LUA_NATIVE_MISC_SHOULD_USE_METRIC_MEASUREMENTS);
		MISC.set_function("_SHOULD_USE_METRIC_MEASUREMENTS_2", LUA_NATIVE_MISC__SHOULD_USE_METRIC_MEASUREMENTS_2);
		MISC.set_function("_SHOULD_USE_METRIC_TEMPERATURE", LUA_NATIVE_MISC__SHOULD_USE_METRIC_TEMPERATURE);
		MISC.set_function("_SHOULD_USE_METRIC_WEIGHT", LUA_NATIVE_MISC__SHOULD_USE_METRIC_WEIGHT);
		MISC.set_function("_SHOULD_USE_24_HOUR_CLOCK", LUA_NATIVE_MISC__SHOULD_USE_24_HOUR_CLOCK);
		MISC.set_function("COMPARE_STRINGS", LUA_NATIVE_MISC_COMPARE_STRINGS);
		MISC.set_function("ABSI", LUA_NATIVE_MISC_ABSI);
		MISC.set_function("ABSF", LUA_NATIVE_MISC_ABSF);
		MISC.set_function("IS_PROJECTILE_IN_AREA", LUA_NATIVE_MISC_IS_PROJECTILE_IN_AREA);
		MISC.set_function("IS_PROJECTILE_TYPE_IN_AREA", LUA_NATIVE_MISC_IS_PROJECTILE_TYPE_IN_AREA);
		MISC.set_function("IS_PROJECTILE_TYPE_IN_ANGLED_AREA", LUA_NATIVE_MISC_IS_PROJECTILE_TYPE_IN_ANGLED_AREA);
		MISC.set_function("IS_PROJECTILE_TYPE_WITHIN_DISTANCE", LUA_NATIVE_MISC_IS_PROJECTILE_TYPE_WITHIN_DISTANCE);
		MISC.set_function("GET_COORDS_OF_PROJECTILE_TYPE_WITHIN_DISTANCE", LUA_NATIVE_MISC_GET_COORDS_OF_PROJECTILE_TYPE_WITHIN_DISTANCE);
		MISC.set_function("GET_PROJECTILE_OF_PROJECTILE_TYPE_WITHIN_DISTANCE", LUA_NATIVE_MISC_GET_PROJECTILE_OF_PROJECTILE_TYPE_WITHIN_DISTANCE);
		MISC.set_function("IS_BULLET_IN_ANGLED_AREA", LUA_NATIVE_MISC_IS_BULLET_IN_ANGLED_AREA);
		MISC.set_function("IS_BULLET_IN_AREA", LUA_NATIVE_MISC_IS_BULLET_IN_AREA);
		MISC.set_function("IS_BULLET_IN_BOX", LUA_NATIVE_MISC_IS_BULLET_IN_BOX);
		MISC.set_function("HAS_BULLET_IMPACTED_IN_AREA", LUA_NATIVE_MISC_HAS_BULLET_IMPACTED_IN_AREA);
		MISC.set_function("HAS_BULLET_IMPACTED_IN_BOX", LUA_NATIVE_MISC_HAS_BULLET_IMPACTED_IN_BOX);
		MISC.set_function("_0x7A76104CC2CC69E8", LUA_NATIVE_MISC__0x7A76104CC2CC69E8);
		MISC.set_function("_0xDC416CA762BC4F43", LUA_NATIVE_MISC__0xDC416CA762BC4F43);
		MISC.set_function("_0x970339EFA4FDE518", LUA_NATIVE_MISC__0x970339EFA4FDE518);
		MISC.set_function("IS_ORBIS_VERSION", LUA_NATIVE_MISC_IS_ORBIS_VERSION);
		MISC.set_function("IS_DURANGO_VERSION", LUA_NATIVE_MISC_IS_DURANGO_VERSION);
		MISC.set_function("IS_PC_VERSION", LUA_NATIVE_MISC_IS_PC_VERSION);
		MISC.set_function("IS_STADIA_VERSION", LUA_NATIVE_MISC_IS_STADIA_VERSION);
		MISC.set_function("IS_STRING_NULL", LUA_NATIVE_MISC_IS_STRING_NULL);
		MISC.set_function("IS_STRING_NULL_OR_EMPTY", LUA_NATIVE_MISC_IS_STRING_NULL_OR_EMPTY);
		MISC.set_function("IS_STRING_NULL_OR_EMPTY_OR_SPACES", LUA_NATIVE_MISC_IS_STRING_NULL_OR_EMPTY_OR_SPACES);
		MISC.set_function("ARE_STRINGS_EQUAL", LUA_NATIVE_MISC_ARE_STRINGS_EQUAL);
		MISC.set_function("_DOES_STRING_EXIST_IN_STRING", LUA_NATIVE_MISC__DOES_STRING_EXIST_IN_STRING);
		MISC.set_function("_0x3C3C7B1B5EC08764", LUA_NATIVE_MISC__0x3C3C7B1B5EC08764);
		MISC.set_function("_0x94E8CA3DEE952789", LUA_NATIVE_MISC__0x94E8CA3DEE952789);
		MISC.set_function("_0x5B4A8121A47D844D", LUA_NATIVE_MISC__0x5B4A8121A47D844D);
		MISC.set_function("STRING_TO_INT", LUA_NATIVE_MISC_STRING_TO_INT);
		MISC.set_function("_INT_TO_STRING", LUA_NATIVE_MISC__INT_TO_STRING);
		MISC.set_function("_0x74ACA66484CEBAF0", LUA_NATIVE_MISC__0x74ACA66484CEBAF0);
		MISC.set_function("_0x49C44FE78A135A1D", LUA_NATIVE_MISC__0x49C44FE78A135A1D);
		MISC.set_function("_0xF650DCF5D6F312C1", LUA_NATIVE_MISC__0xF650DCF5D6F312C1);
		MISC.set_function("_GET_STRING_FROM_FLOAT", LUA_NATIVE_MISC__GET_STRING_FROM_FLOAT);
		MISC.set_function("_GET_STRING_FROM_VECTOR", LUA_NATIVE_MISC__GET_STRING_FROM_VECTOR);
		MISC.set_function("_GET_STRING_FROM_BOOL", LUA_NATIVE_MISC__GET_STRING_FROM_BOOL);
		MISC.set_function("_CREATE_COLOR_STRING", LUA_NATIVE_MISC__CREATE_COLOR_STRING);
		MISC.set_function("SET_BITS_IN_RANGE", LUA_NATIVE_MISC_SET_BITS_IN_RANGE);
		MISC.set_function("GET_BITS_IN_RANGE", LUA_NATIVE_MISC_GET_BITS_IN_RANGE);
		MISC.set_function("SET_GAME_PAUSED", LUA_NATIVE_MISC_SET_GAME_PAUSED);
		MISC.set_function("SET_THIS_SCRIPT_CAN_BE_PAUSED", LUA_NATIVE_MISC_SET_THIS_SCRIPT_CAN_BE_PAUSED);
		MISC.set_function("SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT", LUA_NATIVE_MISC_SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT);
		MISC.set_function("SET_CHEAT_ACTIVE", LUA_NATIVE_MISC_SET_CHEAT_ACTIVE);
		MISC.set_function("_0xB711EB4BC8D06013", LUA_NATIVE_MISC__0xB711EB4BC8D06013);
		MISC.set_function("POPULATE_NOW", LUA_NATIVE_MISC_POPULATE_NOW);
		MISC.set_function("IS_GAME_SESSION_STATE_MACHINE_IDLE", LUA_NATIVE_MISC_IS_GAME_SESSION_STATE_MACHINE_IDLE);
		MISC.set_function("_QUEUE_SAVEGAME_OPERATION", LUA_NATIVE_MISC__QUEUE_SAVEGAME_OPERATION);
		MISC.set_function("_GET_STATUS_OF_SAVEGAME_OPERATION", LUA_NATIVE_MISC__GET_STATUS_OF_SAVEGAME_OPERATION);
		MISC.set_function("_0x6C7B68D3CE60E8DE", LUA_NATIVE_MISC__0x6C7B68D3CE60E8DE);
		MISC.set_function("_0x627B68D9CE6EE8DE", LUA_NATIVE_MISC__0x627B68D9CE6EE8DE);
		MISC.set_function("_0x7CF96F1250EF3221", LUA_NATIVE_MISC__0x7CF96F1250EF3221);
		MISC.set_function("COPY_SCRIPT_STRUCT", LUA_NATIVE_MISC_COPY_SCRIPT_STRUCT);
		MISC.set_function("ENABLE_DISPATCH_SERVICE", LUA_NATIVE_MISC_ENABLE_DISPATCH_SERVICE);
		MISC.set_function("BLOCK_DISPATCH_SERVICE_RESOURCE_CREATION", LUA_NATIVE_MISC_BLOCK_DISPATCH_SERVICE_RESOURCE_CREATION);
		MISC.set_function("CREATE_INCIDENT", LUA_NATIVE_MISC_CREATE_INCIDENT);
		MISC.set_function("_CREATE_INCIDENT_WITH_ENTITIES", LUA_NATIVE_MISC__CREATE_INCIDENT_WITH_ENTITIES);
		MISC.set_function("DELETE_INCIDENT", LUA_NATIVE_MISC_DELETE_INCIDENT);
		MISC.set_function("IS_INCIDENT_VALID", LUA_NATIVE_MISC_IS_INCIDENT_VALID);
		MISC.set_function("_SET_INCIDENT_UNK", LUA_NATIVE_MISC__SET_INCIDENT_UNK);
		MISC.set_function("ADD_POP_MULTIPLIER_AREA", LUA_NATIVE_MISC_ADD_POP_MULTIPLIER_AREA);
		MISC.set_function("DOES_POP_MULTIPLIER_AREA_EXIST", LUA_NATIVE_MISC_DOES_POP_MULTIPLIER_AREA_EXIST);
		MISC.set_function("REMOVE_POP_MULTIPLIER_AREA", LUA_NATIVE_MISC_REMOVE_POP_MULTIPLIER_AREA);
		MISC.set_function("_ADD_POP_MULTIPLIER_VOLUME", LUA_NATIVE_MISC__ADD_POP_MULTIPLIER_VOLUME);
		MISC.set_function("_DOES_POP_MULTIPLIER_AREA_EXIST_FOR_VOLUME", LUA_NATIVE_MISC__DOES_POP_MULTIPLIER_AREA_EXIST_FOR_VOLUME);
		MISC.set_function("_REMOVE_POP_MULTIPLIER_AREA_FOR_VOLUME", LUA_NATIVE_MISC__REMOVE_POP_MULTIPLIER_AREA_FOR_VOLUME);
		MISC.set_function("_0xF569E33FB72ED28E", LUA_NATIVE_MISC__0xF569E33FB72ED28E);
		MISC.set_function("RESET_DISPATCH_IDEAL_SPAWN_DISTANCE", LUA_NATIVE_MISC_RESET_DISPATCH_IDEAL_SPAWN_DISTANCE);
		MISC.set_function("SET_DISPATCH_IDEAL_SPAWN_DISTANCE", LUA_NATIVE_MISC_SET_DISPATCH_IDEAL_SPAWN_DISTANCE);
		MISC.set_function("_RESET_DISPATCH_MIN_SPAWN_DISTANCE", LUA_NATIVE_MISC__RESET_DISPATCH_MIN_SPAWN_DISTANCE);
		MISC.set_function("_SET_DISPATCH_MIN_SPAWN_DISTANCE", LUA_NATIVE_MISC__SET_DISPATCH_MIN_SPAWN_DISTANCE);
		MISC.set_function("_RESET_DISPATCH_MAX_SPAWN_DISTANCE", LUA_NATIVE_MISC__RESET_DISPATCH_MAX_SPAWN_DISTANCE);
		MISC.set_function("_SET_DISPATCH_MAX_SPAWN_DISTANCE", LUA_NATIVE_MISC__SET_DISPATCH_MAX_SPAWN_DISTANCE);
		MISC.set_function("_0x4B0501A468B749F8", LUA_NATIVE_MISC__0x4B0501A468B749F8);
		MISC.set_function("_0x6BCF7B5CD338281A", LUA_NATIVE_MISC__0x6BCF7B5CD338281A);
		MISC.set_function("_ADD_DISPATCH_SPAWN_BLOCKING_AREA", LUA_NATIVE_MISC__ADD_DISPATCH_SPAWN_BLOCKING_AREA);
		MISC.set_function("REMOVE_DISPATCH_SPAWN_BLOCKING_AREA", LUA_NATIVE_MISC_REMOVE_DISPATCH_SPAWN_BLOCKING_AREA);
		MISC.set_function("RESET_WANTED_RESPONSE_NUM_PEDS_TO_SPAWN", LUA_NATIVE_MISC_RESET_WANTED_RESPONSE_NUM_PEDS_TO_SPAWN);
		MISC.set_function("ADD_TACTICAL_NAV_MESH_POINT", LUA_NATIVE_MISC_ADD_TACTICAL_NAV_MESH_POINT);
		MISC.set_function("CLEAR_TACTICAL_NAV_MESH_POINTS", LUA_NATIVE_MISC_CLEAR_TACTICAL_NAV_MESH_POINTS);
		MISC.set_function("DISPLAY_ONSCREEN_KEYBOARD", LUA_NATIVE_MISC_DISPLAY_ONSCREEN_KEYBOARD);
		MISC.set_function("UPDATE_ONSCREEN_KEYBOARD", LUA_NATIVE_MISC_UPDATE_ONSCREEN_KEYBOARD);
		MISC.set_function("GET_ONSCREEN_KEYBOARD_RESULT", LUA_NATIVE_MISC_GET_ONSCREEN_KEYBOARD_RESULT);
		MISC.set_function("CANCEL_ONSCREEN_KEYBOARD", LUA_NATIVE_MISC_CANCEL_ONSCREEN_KEYBOARD);
		MISC.set_function("NEXT_ONSCREEN_KEYBOARD_RESULT_WILL_DISPLAY_USING_THESE_FONTS", LUA_NATIVE_MISC_NEXT_ONSCREEN_KEYBOARD_RESULT_WILL_DISPLAY_USING_THESE_FONTS);
		MISC.set_function("ACTION_MANAGER_ENABLE_ACTION", LUA_NATIVE_MISC_ACTION_MANAGER_ENABLE_ACTION);
		MISC.set_function("ACTION_MANAGER_IS_ACTION_ENABLED", LUA_NATIVE_MISC_ACTION_MANAGER_IS_ACTION_ENABLED);
		MISC.set_function("GET_REAL_WORLD_TIME", LUA_NATIVE_MISC_GET_REAL_WORLD_TIME);
		MISC.set_function("SET_SUPER_JUMP_THIS_FRAME", LUA_NATIVE_MISC_SET_SUPER_JUMP_THIS_FRAME);
		MISC.set_function("SCRIPT_RACE_INIT", LUA_NATIVE_MISC_SCRIPT_RACE_INIT);
		MISC.set_function("SCRIPT_RACE_SHUTDOWN", LUA_NATIVE_MISC_SCRIPT_RACE_SHUTDOWN);
		MISC.set_function("SCRIPT_RACE_PLAYER_HIT_CHECKPOINT", LUA_NATIVE_MISC_SCRIPT_RACE_PLAYER_HIT_CHECKPOINT);
		MISC.set_function("SCRIPT_RACE_GET_PLAYER_SPLIT_TIME", LUA_NATIVE_MISC_SCRIPT_RACE_GET_PLAYER_SPLIT_TIME);
		MISC.set_function("START_END_USER_BENCHMARK", LUA_NATIVE_MISC_START_END_USER_BENCHMARK);
		MISC.set_function("STOP_END_USER_BENCHMARK", LUA_NATIVE_MISC_STOP_END_USER_BENCHMARK);
		MISC.set_function("RESET_END_USER_BENCHMARK", LUA_NATIVE_MISC_RESET_END_USER_BENCHMARK);
		MISC.set_function("SAVE_END_USER_BENCHMARK", LUA_NATIVE_MISC_SAVE_END_USER_BENCHMARK);
		MISC.set_function("UI_STARTED_END_USER_BENCHMARK", LUA_NATIVE_MISC_UI_STARTED_END_USER_BENCHMARK);
		MISC.set_function("GET_BENCHMARK_ITERATIONS", LUA_NATIVE_MISC_GET_BENCHMARK_ITERATIONS);
		MISC.set_function("GET_BENCHMARK_PASS", LUA_NATIVE_MISC_GET_BENCHMARK_PASS);
		MISC.set_function("_0xDC057B86FC157031", LUA_NATIVE_MISC__0xDC057B86FC157031);
		MISC.set_function("_0x9A252AA23D7098F2", LUA_NATIVE_MISC__0x9A252AA23D7098F2);
		MISC.set_function("_DOES_ITEM_HAVE_VALID_BASE", LUA_NATIVE_MISC__DOES_ITEM_HAVE_VALID_BASE);
		MISC.set_function("_GET_ITEM_TYPE", LUA_NATIVE_MISC__GET_ITEM_TYPE);
		MISC.set_function("_IS_BASE_A_PERSISTENT_CHARACTER", LUA_NATIVE_MISC__IS_BASE_A_PERSISTENT_CHARACTER);
		MISC.set_function("_IS_BASE_A_COVER_POINT", LUA_NATIVE_MISC__IS_BASE_A_COVER_POINT);
		MISC.set_function("_0x553D67295DDD2309", LUA_NATIVE_MISC__0x553D67295DDD2309);
		MISC.set_function("_GET_VOLUME_FROM_INDEXED_ITEM", LUA_NATIVE_MISC__GET_VOLUME_FROM_INDEXED_ITEM);
		MISC.set_function("_GET_ENTITY_FROM_ITEM", LUA_NATIVE_MISC__GET_ENTITY_FROM_ITEM);
		MISC.set_function("_GET_PED_FROM_INDEXED_ITEM", LUA_NATIVE_MISC__GET_PED_FROM_INDEXED_ITEM);
		MISC.set_function("_GET_VEHICLE_FROM_INDEXED_ITEM", LUA_NATIVE_MISC__GET_VEHICLE_FROM_INDEXED_ITEM);
		MISC.set_function("_GET_OBJECT_FROM_INDEXED_ITEM", LUA_NATIVE_MISC__GET_OBJECT_FROM_INDEXED_ITEM);
		MISC.set_function("_0x33982467B1E349EF", LUA_NATIVE_MISC__0x33982467B1E349EF);
		MISC.set_function("_0x8314FC2013ECE2DA", LUA_NATIVE_MISC__0x8314FC2013ECE2DA);
		MISC.set_function("_0x4D5C9CC7E7E23E09", LUA_NATIVE_MISC__0x4D5C9CC7E7E23E09);
		MISC.set_function("REGISTER_INTERACTION_LOCKON_PROMPT", LUA_NATIVE_MISC_REGISTER_INTERACTION_LOCKON_PROMPT);
		MISC.set_function("UNREGISTER_INTERACTION_LOCKON_PROMPT", LUA_NATIVE_MISC_UNREGISTER_INTERACTION_LOCKON_PROMPT);
		MISC.set_function("_0xFC6ECB9170145ECE", LUA_NATIVE_MISC__0xFC6ECB9170145ECE);
		MISC.set_function("_0x35165C658077CD0B", LUA_NATIVE_MISC__0x35165C658077CD0B);
		MISC.set_function("_0x4B101DBCC9482F2D", LUA_NATIVE_MISC__0x4B101DBCC9482F2D);
		MISC.set_function("_IS_MISSION_CREATOR_ACTIVE", LUA_NATIVE_MISC__IS_MISSION_CREATOR_ACTIVE);
		MISC.set_function("_0xA3A8926951471C82", LUA_NATIVE_MISC__0xA3A8926951471C82);
		MISC.set_function("_CREATE_AI_MEMORY", LUA_NATIVE_MISC__CREATE_AI_MEMORY);
		MISC.set_function("_GET_AI_PED_DOES_HAVE_EVENT_MEMORY", LUA_NATIVE_MISC__GET_AI_PED_DOES_HAVE_EVENT_MEMORY);
		MISC.set_function("_0xEB946B9E579729AD", LUA_NATIVE_MISC__0xEB946B9E579729AD);
		MISC.set_function("_SET_AI_MEMORY_REACTIONS_ENABLED", LUA_NATIVE_MISC__SET_AI_MEMORY_REACTIONS_ENABLED);
		MISC.set_function("_0x8DB104CCEBCD58C5", LUA_NATIVE_MISC__0x8DB104CCEBCD58C5);
		MISC.set_function("_0x68319452C5064ABA", LUA_NATIVE_MISC__0x68319452C5064ABA);
		MISC.set_function("_0xDE2C3B74D2B3705C", LUA_NATIVE_MISC__0xDE2C3B74D2B3705C);
		MISC.set_function("_0x49F3241C28EBBFBC", LUA_NATIVE_MISC__0x49F3241C28EBBFBC);
		MISC.set_function("_0x183672FE838A661B", LUA_NATIVE_MISC__0x183672FE838A661B);
		MISC.set_function("_0x38C0C9CAE1544500", LUA_NATIVE_MISC__0x38C0C9CAE1544500);
		MISC.set_function("_0x154340E87D8CC178", LUA_NATIVE_MISC__0x154340E87D8CC178);
		MISC.set_function("_0x94FCADCF9F0C368E", LUA_NATIVE_MISC__0x94FCADCF9F0C368E);
		MISC.set_function("_0x0D0AE5081F88CFE1", LUA_NATIVE_MISC__0x0D0AE5081F88CFE1);
		MISC.set_function("_0xAF3A84C7DE6A1DC5", LUA_NATIVE_MISC__0xAF3A84C7DE6A1DC5);
		MISC.set_function("_LOOT_TABLES_GET_INFO", LUA_NATIVE_MISC__LOOT_TABLES_GET_INFO);
		MISC.set_function("_0xB1F6665AA54DCD5C", LUA_NATIVE_MISC__0xB1F6665AA54DCD5C);
		MISC.set_function("_0x8BB99B85444544D9", LUA_NATIVE_MISC__0x8BB99B85444544D9);
		MISC.set_function("_0x6F02B5E50511721E", LUA_NATIVE_MISC__0x6F02B5E50511721E);
		MISC.set_function("_0xCC1BAF72D571DB8D", LUA_NATIVE_MISC__0xCC1BAF72D571DB8D);
		MISC.set_function("_IS_PED_DECOMPOSED", LUA_NATIVE_MISC__IS_PED_DECOMPOSED);
		MISC.set_function("SET_PED_DECOMPOSED", LUA_NATIVE_MISC_SET_PED_DECOMPOSED);
		MISC.set_function("_0xAB26DEEE120FD3FD", LUA_NATIVE_MISC__0xAB26DEEE120FD3FD);
		MISC.set_function("_0x082C043C7AFC3747", LUA_NATIVE_MISC__0x082C043C7AFC3747);
		MISC.set_function("DISABLE_LOOTING_COMPOSITE_LOOTABLE_THIS_FRAME", LUA_NATIVE_MISC_DISABLE_LOOTING_COMPOSITE_LOOTABLE_THIS_FRAME);
		MISC.set_function("_0xBB282CF5D2333FB8", LUA_NATIVE_MISC__0xBB282CF5D2333FB8);
		MISC.set_function("_0xAD44856A1CD29635", LUA_NATIVE_MISC__0xAD44856A1CD29635);
		MISC.set_function("_0x38C2BF94D15F464D", LUA_NATIVE_MISC__0x38C2BF94D15F464D);
		MISC.set_function("_0x3A87FDA8F1B6CDFB", LUA_NATIVE_MISC__0x3A87FDA8F1B6CDFB);
		MISC.set_function("_0x4647842FE8F31C1E", LUA_NATIVE_MISC__0x4647842FE8F31C1E);
		MISC.set_function("_GET_LOOTING_EVENT_HAS_FIRED", LUA_NATIVE_MISC__GET_LOOTING_EVENT_HAS_FIRED);
		MISC.set_function("_SET_LOOT_PELT_SATCHEL_ITEM", LUA_NATIVE_MISC__SET_LOOT_PELT_SATCHEL_ITEM);
		MISC.set_function("_0x96282005C5C6801F", LUA_NATIVE_MISC__0x96282005C5C6801F);
		MISC.set_function("_0xF63FA29D4A9ACA86", LUA_NATIVE_MISC__0xF63FA29D4A9ACA86);
		MISC.set_function("_0x8C0F6A3D7236DEEB", LUA_NATIVE_MISC__0x8C0F6A3D7236DEEB);
		MISC.set_function("_0x7FA58CED69405F9A", LUA_NATIVE_MISC__0x7FA58CED69405F9A);
		MISC.set_function("_0xA08111B053D84B4D", LUA_NATIVE_MISC__0xA08111B053D84B4D);
		MISC.set_function("_IS_GLOBAL_BLOCK_VALID", LUA_NATIVE_MISC__IS_GLOBAL_BLOCK_VALID);
		MISC.set_function("_SET_GLOBAL_BLOCK_IS_LOADED", LUA_NATIVE_MISC__SET_GLOBAL_BLOCK_IS_LOADED);
		MISC.set_function("GAME_FRAMEWORK_MANAGER_INIT", LUA_NATIVE_MISC_GAME_FRAMEWORK_MANAGER_INIT);
		MISC.set_function("_GAME_FRAMEWORK_MANAGER_SHUTDOWN", LUA_NATIVE_MISC__GAME_FRAMEWORK_MANAGER_SHUTDOWN);
		MISC.set_function("_GAME_FRAMEWORK_MANAGER_GET_MODE", LUA_NATIVE_MISC__GAME_FRAMEWORK_MANAGER_GET_MODE);
		MISC.set_function("_IS_PLAYER_OWNING_STANDALONE_SP", LUA_NATIVE_MISC__IS_PLAYER_OWNING_STANDALONE_SP);
		MISC.set_function("_0x0358B8A41916C613", LUA_NATIVE_MISC__0x0358B8A41916C613);
		MISC.set_function("_SET_GAME_LOGIC_PAUSED", LUA_NATIVE_MISC__SET_GAME_LOGIC_PAUSED);
		MISC.set_function("STOP_CURRENT_LOADING_PROGRESS_TIMER", LUA_NATIVE_MISC_STOP_CURRENT_LOADING_PROGRESS_TIMER);
		MISC.set_function("_0xDBDA48EC456ED908", LUA_NATIVE_MISC__0xDBDA48EC456ED908);
	}
}
