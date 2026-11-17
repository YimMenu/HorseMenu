#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_WATER_DISABLE_WATER_LOOKUP()
	{
		WATER::DISABLE_WATER_LOOKUP();
	}

	static void LUA_NATIVE_WATER_ENABLE_WATER_LOOKUP()
	{
		WATER::ENABLE_WATER_LOOKUP();
	}

	static std::tuple<bool, float> LUA_NATIVE_WATER_GET_WATER_HEIGHT(float PosX, float PosY, float PosZ, float Height)
	{
		std::tuple<bool, float> return_values;
		std::get<0>(return_values) = (bool)WATER::GET_WATER_HEIGHT(PosX, PosY, PosZ, &Height);
		std::get<1>(return_values) = Height;

		return return_values;
	}

	static std::tuple<bool, float> LUA_NATIVE_WATER_GET_WATER_HEIGHT_NO_WAVES(float PosX, float PosY, float PosZ, float Height)
	{
		std::tuple<bool, float> return_values;
		std::get<0>(return_values) = (bool)WATER::GET_WATER_HEIGHT_NO_WAVES(PosX, PosY, PosZ, &Height);
		std::get<1>(return_values) = Height;

		return return_values;
	}

	static std::tuple<int, Vector3> LUA_NATIVE_WATER_TEST_PROBE_AGAINST_ALL_WATER(float StartPosX, float StartPosY, float StartPosZ, float EndPosX, float EndPosY, float EndPosZ, int BlockingFlags, Vector3 IntersectionPos)
	{
		std::tuple<int, Vector3> return_values;
		std::get<0>(return_values) = WATER::TEST_PROBE_AGAINST_ALL_WATER(StartPosX, StartPosY, StartPosZ, EndPosX, EndPosY, EndPosZ, BlockingFlags, &IntersectionPos);
		std::get<1>(return_values) = IntersectionPos;

		return return_values;
	}

	static std::tuple<int, float> LUA_NATIVE_WATER_TEST_VERTICAL_PROBE_AGAINST_ALL_WATER(float StartPosX, float StartPosY, float StartPosZ, int BlockingFlags, float Height)
	{
		std::tuple<int, float> return_values;
		std::get<0>(return_values) = WATER::TEST_VERTICAL_PROBE_AGAINST_ALL_WATER(StartPosX, StartPosY, StartPosZ, BlockingFlags, &Height);
		std::get<1>(return_values) = Height;

		return return_values;
	}

	static void LUA_NATIVE_WATER_REMOVE_EXTRA_CALMING_QUAD(int Idx)
	{
		WATER::REMOVE_EXTRA_CALMING_QUAD(Idx);
	}

	static void LUA_NATIVE_WATER__0x09A1C7DFDCE54FBC(int p0)
	{
		WATER::_0x09A1C7DFDCE54FBC(p0);
	}

	static void LUA_NATIVE_WATER__0xF0FBF193F1F5C0EA(Ped ped)
	{
		WATER::_0xF0FBF193F1F5C0EA(ped);
	}

	static void LUA_NATIVE_WATER__0xA33F5069B0CB89B8()
	{
		WATER::_0xA33F5069B0CB89B8();
	}

	static void LUA_NATIVE_WATER__0xB34A6009A0DB80B8(Entity entity)
	{
		WATER::_0xB34A6009A0DB80B8(entity);
	}

	static void LUA_NATIVE_WATER__SET_OCEAN_GUARMA_WATER_QUADRANT(float wavesHeight, float p1, int p2, float p3, float p4, float p5, float p6, float wavesStrength, int p8)
	{
		WATER::_SET_OCEAN_GUARMA_WATER_QUADRANT(wavesHeight, p1, p2, p3, p4, p5, p6, wavesStrength, p8);
	}

	static void LUA_NATIVE_WATER__RESET_GUARMA_WATER_STATE()
	{
		WATER::_RESET_GUARMA_WATER_STATE();
	}

	static void LUA_NATIVE_WATER__SET_WORLD_WATER_TYPE(int waterType)
	{
		WATER::_SET_WORLD_WATER_TYPE(waterType);
	}

	static int LUA_NATIVE_WATER__GET_WORLD_WATER_TYPE()
	{
		auto retval = WATER::_GET_WORLD_WATER_TYPE();
		return retval;
	}

	static void LUA_NATIVE_WATER__0x0DCEC6A92E497E17(Entity entity, int p1)
	{
		WATER::_0x0DCEC6A92E497E17(entity, p1);
	}

	static void LUA_NATIVE_WATER__0xE8126623008372AA()
	{
		WATER::_0xE8126623008372AA();
	}

	void RegisterNatives_WATER(sol::state& L)
	{
		auto WATER = L["WATER"].get_or_create<sol::table>();
		WATER.set_function("DISABLE_WATER_LOOKUP", LUA_NATIVE_WATER_DISABLE_WATER_LOOKUP);
		WATER.set_function("ENABLE_WATER_LOOKUP", LUA_NATIVE_WATER_ENABLE_WATER_LOOKUP);
		WATER.set_function("GET_WATER_HEIGHT", LUA_NATIVE_WATER_GET_WATER_HEIGHT);
		WATER.set_function("GET_WATER_HEIGHT_NO_WAVES", LUA_NATIVE_WATER_GET_WATER_HEIGHT_NO_WAVES);
		WATER.set_function("TEST_PROBE_AGAINST_ALL_WATER", LUA_NATIVE_WATER_TEST_PROBE_AGAINST_ALL_WATER);
		WATER.set_function("TEST_VERTICAL_PROBE_AGAINST_ALL_WATER", LUA_NATIVE_WATER_TEST_VERTICAL_PROBE_AGAINST_ALL_WATER);
		WATER.set_function("REMOVE_EXTRA_CALMING_QUAD", LUA_NATIVE_WATER_REMOVE_EXTRA_CALMING_QUAD);
		WATER.set_function("_0x09A1C7DFDCE54FBC", LUA_NATIVE_WATER__0x09A1C7DFDCE54FBC);
		WATER.set_function("_0xF0FBF193F1F5C0EA", LUA_NATIVE_WATER__0xF0FBF193F1F5C0EA);
		WATER.set_function("_0xA33F5069B0CB89B8", LUA_NATIVE_WATER__0xA33F5069B0CB89B8);
		WATER.set_function("_0xB34A6009A0DB80B8", LUA_NATIVE_WATER__0xB34A6009A0DB80B8);
		WATER.set_function("_SET_OCEAN_GUARMA_WATER_QUADRANT", LUA_NATIVE_WATER__SET_OCEAN_GUARMA_WATER_QUADRANT);
		WATER.set_function("_RESET_GUARMA_WATER_STATE", LUA_NATIVE_WATER__RESET_GUARMA_WATER_STATE);
		WATER.set_function("_SET_WORLD_WATER_TYPE", LUA_NATIVE_WATER__SET_WORLD_WATER_TYPE);
		WATER.set_function("_GET_WORLD_WATER_TYPE", LUA_NATIVE_WATER__GET_WORLD_WATER_TYPE);
		WATER.set_function("_0x0DCEC6A92E497E17", LUA_NATIVE_WATER__0x0DCEC6A92E497E17);
		WATER.set_function("_0xE8126623008372AA", LUA_NATIVE_WATER__0xE8126623008372AA);
	}
}
