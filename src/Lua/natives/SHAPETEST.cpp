#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static ScrHandle LUA_NATIVE_SHAPETEST_START_SHAPE_TEST_LOS_PROBE(float VecStartPosX, float VecStartPosY, float VecStartPosZ, float VecEndPosX, float VecEndPosY, float VecEndPosZ, int LOSFlags, Entity ExcludeEntityIndex, int Options)
	{
		auto retval = SHAPETEST::START_SHAPE_TEST_LOS_PROBE(VecStartPosX, VecStartPosY, VecStartPosZ, VecEndPosX, VecEndPosY, VecEndPosZ, LOSFlags, ExcludeEntityIndex, Options);
		return retval;
	}

	static Any LUA_NATIVE_SHAPETEST__0x04AA59CA40571C2E(Any p0, Any p1)
	{
		auto retval = SHAPETEST::_0x04AA59CA40571C2E(p0, p1);
		return retval;
	}

	static ScrHandle LUA_NATIVE_SHAPETEST_START_EXPENSIVE_SYNCHRONOUS_SHAPE_TEST_LOS_PROBE(float VecStartPosX, float VecStartPosY, float VecStartPosZ, float VecEndPosX, float VecEndPosY, float VecEndPosZ, int LOSFlags, Entity ExcludeEntityIndex, int Options)
	{
		auto retval = SHAPETEST::START_EXPENSIVE_SYNCHRONOUS_SHAPE_TEST_LOS_PROBE(VecStartPosX, VecStartPosY, VecStartPosZ, VecEndPosX, VecEndPosY, VecEndPosZ, LOSFlags, ExcludeEntityIndex, Options);
		return retval;
	}

	static ScrHandle LUA_NATIVE_SHAPETEST_START_SHAPE_TEST_BOX(float scrVecPosX, float scrVecPosY, float scrVecPosZ, float scrVecDimsX, float scrVecDimsY, float scrVecDimsZ, float eulerAnglesX, float eulerAnglesY, float eulerAnglesZ, int RotOrder, int LOSFlags, Entity ExcludeEntityIndex, int Options)
	{
		auto retval = SHAPETEST::START_SHAPE_TEST_BOX(scrVecPosX, scrVecPosY, scrVecPosZ, scrVecDimsX, scrVecDimsY, scrVecDimsZ, eulerAnglesX, eulerAnglesY, eulerAnglesZ, RotOrder, LOSFlags, ExcludeEntityIndex, Options);
		return retval;
	}

	static ScrHandle LUA_NATIVE_SHAPETEST_START_SHAPE_TEST_CAPSULE(float scrVecPosX, float scrVecPosY, float scrVecPosZ, float scrVecEndPosX, float scrVecEndPosY, float scrVecEndPosZ, float fRadius, int LOSFlags, Entity ExcludeEntityIndex, int Options)
	{
		auto retval = SHAPETEST::START_SHAPE_TEST_CAPSULE(scrVecPosX, scrVecPosY, scrVecPosZ, scrVecEndPosX, scrVecEndPosY, scrVecEndPosZ, fRadius, LOSFlags, ExcludeEntityIndex, Options);
		return retval;
	}

	static ScrHandle LUA_NATIVE_SHAPETEST_START_SHAPE_TEST_SWEPT_SPHERE(float scrVecPosX, float scrVecPosY, float scrVecPosZ, float scrVecEndPosX, float scrVecEndPosY, float scrVecEndPosZ, float fRadius, int LOSFlags, Entity ExcludeEntityIndex, int Options)
	{
		auto retval = SHAPETEST::START_SHAPE_TEST_SWEPT_SPHERE(scrVecPosX, scrVecPosY, scrVecPosZ, scrVecEndPosX, scrVecEndPosY, scrVecEndPosZ, fRadius, LOSFlags, ExcludeEntityIndex, Options);
		return retval;
	}

	static std::tuple<ScrHandle, Vector3, Vector3> LUA_NATIVE_SHAPETEST_START_SHAPE_TEST_MOUSE_CURSOR_LOS_PROBE(Vector3 vProbeStartPosOut, Vector3 vProbeEndPosOut, int LOSFlags, Entity ExcludeEntityIndex, int Options)
	{
		std::tuple<ScrHandle, Vector3, Vector3> return_values;
		std::get<0>(return_values) = SHAPETEST::START_SHAPE_TEST_MOUSE_CURSOR_LOS_PROBE(&vProbeStartPosOut, &vProbeEndPosOut, LOSFlags, ExcludeEntityIndex, Options);
		std::get<1>(return_values) = vProbeStartPosOut;
		std::get<2>(return_values) = vProbeEndPosOut;

		return return_values;
	}

	static std::tuple<int, int, Vector3, Vector3, Entity> LUA_NATIVE_SHAPETEST_GET_SHAPE_TEST_RESULT(ScrHandle shapeTestGuid, int bHitSomething, Vector3 vPos, Vector3 vNormal, Entity EntityIndex)
	{
		std::tuple<int, int, Vector3, Vector3, Entity> return_values;
		std::get<0>(return_values) = SHAPETEST::GET_SHAPE_TEST_RESULT(shapeTestGuid, &bHitSomething, &vPos, &vNormal, &EntityIndex);
		std::get<1>(return_values) = bHitSomething;
		std::get<2>(return_values) = vPos;
		std::get<3>(return_values) = vNormal;
		std::get<4>(return_values) = EntityIndex;

		return return_values;
	}

	void RegisterNatives_SHAPETEST(sol::state& L)
	{
		auto SHAPETEST = L["SHAPETEST"].get_or_create<sol::table>();
		SHAPETEST.set_function("START_SHAPE_TEST_LOS_PROBE", LUA_NATIVE_SHAPETEST_START_SHAPE_TEST_LOS_PROBE);
		SHAPETEST.set_function("_0x04AA59CA40571C2E", LUA_NATIVE_SHAPETEST__0x04AA59CA40571C2E);
		SHAPETEST.set_function("START_EXPENSIVE_SYNCHRONOUS_SHAPE_TEST_LOS_PROBE", LUA_NATIVE_SHAPETEST_START_EXPENSIVE_SYNCHRONOUS_SHAPE_TEST_LOS_PROBE);
		SHAPETEST.set_function("START_SHAPE_TEST_BOX", LUA_NATIVE_SHAPETEST_START_SHAPE_TEST_BOX);
		SHAPETEST.set_function("START_SHAPE_TEST_CAPSULE", LUA_NATIVE_SHAPETEST_START_SHAPE_TEST_CAPSULE);
		SHAPETEST.set_function("START_SHAPE_TEST_SWEPT_SPHERE", LUA_NATIVE_SHAPETEST_START_SHAPE_TEST_SWEPT_SPHERE);
		SHAPETEST.set_function("START_SHAPE_TEST_MOUSE_CURSOR_LOS_PROBE", LUA_NATIVE_SHAPETEST_START_SHAPE_TEST_MOUSE_CURSOR_LOS_PROBE);
		SHAPETEST.set_function("GET_SHAPE_TEST_RESULT", LUA_NATIVE_SHAPETEST_GET_SHAPE_TEST_RESULT);
	}
}
