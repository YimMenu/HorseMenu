#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static Volume LUA_NATIVE_VOLUME__CREATE_VOLUME_BY_HASH(Hash volumeType, float x, float y, float z, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ)
	{
		auto retval = VOLUME::_CREATE_VOLUME_BY_HASH(volumeType, x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ);
		return retval;
	}

	static Volume LUA_NATIVE_VOLUME_CREATE_VOLUME_BOX(float x, float y, float z, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ)
	{
		auto retval = VOLUME::CREATE_VOLUME_BOX(x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ);
		return retval;
	}

	static Volume LUA_NATIVE_VOLUME_CREATE_VOLUME_CYLINDER(float x, float y, float z, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ)
	{
		auto retval = VOLUME::CREATE_VOLUME_CYLINDER(x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ);
		return retval;
	}

	static Volume LUA_NATIVE_VOLUME_CREATE_VOLUME_SPHERE(float x, float y, float z, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ)
	{
		auto retval = VOLUME::CREATE_VOLUME_SPHERE(x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ);
		return retval;
	}

	static Volume LUA_NATIVE_VOLUME_CREATE_VOLUME_AGGREGATE()
	{
		auto retval = VOLUME::CREATE_VOLUME_AGGREGATE();
		return retval;
	}

	static Volume LUA_NATIVE_VOLUME__CREATE_VOLUME_BY_HASH_WITH_CUSTOM_NAME(Hash volumeType, float x, float y, float z, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ, sol::stack_object name)
	{
		auto retval = VOLUME::_CREATE_VOLUME_BY_HASH_WITH_CUSTOM_NAME(volumeType, x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ, name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static Volume LUA_NATIVE_VOLUME__CREATE_ANTI_GRIEF_VOLUME(Hash volumeType, float x, float y, float z, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ)
	{
		auto retval = VOLUME::_CREATE_ANTI_GRIEF_VOLUME(volumeType, x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ);
		return retval;
	}

	static void LUA_NATIVE_VOLUME__SET_ANTI_GRIEF_VOLUME_BLOCKS_HORSE(Volume volume, bool toggle)
	{
		VOLUME::_SET_ANTI_GRIEF_VOLUME_BLOCKS_HORSE(volume, toggle);
	}

	static void LUA_NATIVE_VOLUME__SET_ANTI_GRIEF_VOLUME_BLOCKS_PLAYER(Volume volume, bool toggle)
	{
		VOLUME::_SET_ANTI_GRIEF_VOLUME_BLOCKS_PLAYER(volume, toggle);
	}

	static Volume LUA_NATIVE_VOLUME__CREATE_WALK_AND_TALK_VOLUME(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11, Any p12)
	{
		auto retval = VOLUME::_CREATE_WALK_AND_TALK_VOLUME(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
		return retval;
	}

	static Volume LUA_NATIVE_VOLUME__CREATE_SPEED_VOLUME(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11, Any p12, Any p13, Any p14)
	{
		auto retval = VOLUME::_CREATE_SPEED_VOLUME(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
		return retval;
	}

	static Volume LUA_NATIVE_VOLUME__CREATE_VOLUME_BOX_WITH_CUSTOM_NAME(float x, float y, float z, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ, sol::stack_object name)
	{
		auto retval = VOLUME::_CREATE_VOLUME_BOX_WITH_CUSTOM_NAME(x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ, name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static Volume LUA_NATIVE_VOLUME__CREATE_VOLUME_CYLINDER_WITH_CUSTOM_NAME(float x, float y, float z, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ, sol::stack_object name)
	{
		auto retval = VOLUME::_CREATE_VOLUME_CYLINDER_WITH_CUSTOM_NAME(x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ, name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static Volume LUA_NATIVE_VOLUME__CREATE_VOLUME_SPHERE_WITH_CUSTOM_NAME(float x, float y, float z, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ, sol::stack_object name)
	{
		auto retval = VOLUME::_CREATE_VOLUME_SPHERE_WITH_CUSTOM_NAME(x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ, name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static Volume LUA_NATIVE_VOLUME__CREATE_VOLUME_AGGREGATE_WITH_CUSTOM_NAME(sol::stack_object name)
	{
		auto retval = VOLUME::_CREATE_VOLUME_AGGREGATE_WITH_CUSTOM_NAME(name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_VOLUME__ADD_BOUNDS_TO_AGGREGATE_VOLUME(Volume volume, Volume aggregate)
	{
		VOLUME::_ADD_BOUNDS_TO_AGGREGATE_VOLUME(volume, aggregate);
	}

	static void LUA_NATIVE_VOLUME__REMOVE_BOUNDS_FROM_AGGREGATE_VOLUME(Volume volume, Volume aggregate)
	{
		VOLUME::_REMOVE_BOUNDS_FROM_AGGREGATE_VOLUME(volume, aggregate);
	}

	static void LUA_NATIVE_VOLUME__ADD_VOLUME_TO_VOLUME_AGGREGATE(Volume aggregate, Hash typeHash, float x, float y, float z, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ)
	{
		VOLUME::_ADD_VOLUME_TO_VOLUME_AGGREGATE(aggregate, typeHash, x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ);
	}

	static void LUA_NATIVE_VOLUME__ADD_BOX_VOLUME_TO_VOLUME_AGGREGATE(Volume aggregate, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, float p9)
	{
		VOLUME::_ADD_BOX_VOLUME_TO_VOLUME_AGGREGATE(aggregate, p1, p2, p3, p4, p5, p6, p7, p8, p9);
	}

	static void LUA_NATIVE_VOLUME__ADD_CYLINDER_VOLUME_TO_VOLUME_AGGREGATE(Volume aggregate, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, float p9)
	{
		VOLUME::_ADD_CYLINDER_VOLUME_TO_VOLUME_AGGREGATE(aggregate, p1, p2, p3, p4, p5, p6, p7, p8, p9);
	}

	static void LUA_NATIVE_VOLUME__ADD_SPHERE_VOLUME_TO_VOLUME_AGGREGATE(Volume aggregate, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, float p9)
	{
		VOLUME::_ADD_SPHERE_VOLUME_TO_VOLUME_AGGREGATE(aggregate, p1, p2, p3, p4, p5, p6, p7, p8, p9);
	}

	static void LUA_NATIVE_VOLUME_DELETE_VOLUME(Volume volume)
	{
		VOLUME::DELETE_VOLUME(volume);
	}

	static bool LUA_NATIVE_VOLUME_DOES_VOLUME_EXIST(Volume volume)
	{
		auto retval = (bool)VOLUME::DOES_VOLUME_EXIST(volume);
		return retval;
	}

	static bool LUA_NATIVE_VOLUME_IS_POINT_IN_VOLUME(Volume volume, float x, float y, float z)
	{
		auto retval = (bool)VOLUME::IS_POINT_IN_VOLUME(volume, x, y, z);
		return retval;
	}

	static Vector3 LUA_NATIVE_VOLUME_GET_VOLUME_COORDS(Volume volume)
	{
		auto retval = VOLUME::GET_VOLUME_COORDS(volume);
		return retval;
	}

	static bool LUA_NATIVE_VOLUME_SET_VOLUME_COORDS(Volume volume, float posX, float posY, float posZ)
	{
		auto retval = (bool)VOLUME::SET_VOLUME_COORDS(volume, posX, posY, posZ);
		return retval;
	}

	static Vector3 LUA_NATIVE_VOLUME_GET_VOLUME_ROTATION(Volume volume)
	{
		auto retval = VOLUME::GET_VOLUME_ROTATION(volume);
		return retval;
	}

	static bool LUA_NATIVE_VOLUME_SET_VOLUME_ROTATION(Volume volume, float rotX, float rotY, float rotZ)
	{
		auto retval = (bool)VOLUME::SET_VOLUME_ROTATION(volume, rotX, rotY, rotZ);
		return retval;
	}

	static Vector3 LUA_NATIVE_VOLUME_GET_VOLUME_SCALE(Volume volume)
	{
		auto retval = VOLUME::GET_VOLUME_SCALE(volume);
		return retval;
	}

	static bool LUA_NATIVE_VOLUME_SET_VOLUME_SCALE(Volume volume, float scaleX, float scaleY, float scaleZ)
	{
		auto retval = (bool)VOLUME::SET_VOLUME_SCALE(volume, scaleX, scaleY, scaleZ);
		return retval;
	}

	static std::tuple<Vector3, Vector3> LUA_NATIVE_VOLUME__GET_VOLUME_BOUNDS(Volume volume, Vector3 min, Vector3 max)
	{
		std::tuple<Vector3, Vector3> return_values;
		VOLUME::_GET_VOLUME_BOUNDS(volume, &min, &max);
		std::get<0>(return_values) = min;
		std::get<1>(return_values) = max;

		return return_values;
	}

	static void LUA_NATIVE_VOLUME__0x748C5F51A18CB8F0(bool p0)
	{
		VOLUME::_0x748C5F51A18CB8F0(p0);
	}

	static Any LUA_NATIVE_VOLUME__0x2B32B11520626229(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		auto retval = VOLUME::_0x2B32B11520626229(p0, p1, p2, p3, p4);
		return retval;
	}

	static Any LUA_NATIVE_VOLUME__0x40F769D31A00D5A0(Any p0, Any p1)
	{
		auto retval = VOLUME::_0x40F769D31A00D5A0(p0, p1);
		return retval;
	}

	static Vector3 LUA_NATIVE_VOLUME__0xD882C5B3991575B7(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		auto retval = VOLUME::_0xD882C5B3991575B7(p0, p1, p2, p3, p4);
		return retval;
	}

	static void LUA_NATIVE_VOLUME__0xB469CFD9E065EB99(Any p0, Any p1)
	{
		VOLUME::_0xB469CFD9E065EB99(p0, p1);
	}

	static Any LUA_NATIVE_VOLUME__0x7FD78DFD0C5D7B9B(Any p0)
	{
		auto retval = VOLUME::_0x7FD78DFD0C5D7B9B(p0);
		return retval;
	}

	static Any LUA_NATIVE_VOLUME__0xEE1D6FF54CAF7714(Any p0, Any p1)
	{
		auto retval = VOLUME::_0xEE1D6FF54CAF7714(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_VOLUME__0xD52DF30355EA7C8E(Any p0, Any p1, Any p2)
	{
		VOLUME::_0xD52DF30355EA7C8E(p0, p1, p2);
	}

	static void LUA_NATIVE_VOLUME_SET_VOLUME_OWNER_PERSISTENT_CHARACTER(Volume volume, PersChar persChar, bool p2)
	{
		VOLUME::SET_VOLUME_OWNER_PERSISTENT_CHARACTER(volume, persChar, p2);
	}

	static void LUA_NATIVE_VOLUME__0x6D5F9E69BA1BE783(Any p0)
	{
		VOLUME::_0x6D5F9E69BA1BE783(p0);
	}

	static void LUA_NATIVE_VOLUME__0x998202B206872672(Any p0)
	{
		VOLUME::_0x998202B206872672(p0);
	}

	static void LUA_NATIVE_VOLUME__0x4A8FEFC43FD8AC9B(Any p0, Any p1, Any p2)
	{
		VOLUME::_0x4A8FEFC43FD8AC9B(p0, p1, p2);
	}

	static void LUA_NATIVE_VOLUME__0xF3A2FBA5985C8CD5(Any p0, Any p1, Any p2, Any p3)
	{
		VOLUME::_0xF3A2FBA5985C8CD5(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_VOLUME__0x53D05D60E5F5B40C(Any p0, Any p1, Any p2, Any p3)
	{
		VOLUME::_0x53D05D60E5F5B40C(p0, p1, p2, p3);
	}

	static Any LUA_NATIVE_VOLUME__0xCA5C90D40665D5CE(Any p0, Any p1)
	{
		auto retval = VOLUME::_0xCA5C90D40665D5CE(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_VOLUME__0x3EFABB21E14A6BD1(Any p0, Any p1, Any p2)
	{
		VOLUME::_0x3EFABB21E14A6BD1(p0, p1, p2);
	}

	static bool LUA_NATIVE_VOLUME__IS_AGGREGATE_VOLUME(Volume volume)
	{
		auto retval = (bool)VOLUME::_IS_AGGREGATE_VOLUME(volume);
		return retval;
	}

	static Volume LUA_NATIVE_VOLUME__CREATE_VOLUME_LOCK(float x, float y, float z, float radius, int flag, Any p5)
	{
		auto retval = VOLUME::_CREATE_VOLUME_LOCK(x, y, z, radius, flag, p5);
		return retval;
	}

	static Volume LUA_NATIVE_VOLUME__CREATE_VOLUME_LOCK_ATTACHED_TO_ENTITY(Entity entity, float radius, int flag, Any p3)
	{
		auto retval = VOLUME::_CREATE_VOLUME_LOCK_ATTACHED_TO_ENTITY(entity, radius, flag, p3);
		return retval;
	}

	static bool LUA_NATIVE_VOLUME__IS_VOLUME_LOCK_REQUEST_VALID_2(int volLockRequestId)
	{
		auto retval = (bool)VOLUME::_IS_VOLUME_LOCK_REQUEST_VALID_2(volLockRequestId);
		return retval;
	}

	static Vector3 LUA_NATIVE_VOLUME__0xC4019CF9AE8E931A(int volLockRequestId)
	{
		auto retval = VOLUME::_0xC4019CF9AE8E931A(volLockRequestId);
		return retval;
	}

	static Any LUA_NATIVE_VOLUME__0xF6CE6F9C3897804E(Any p0)
	{
		auto retval = VOLUME::_0xF6CE6F9C3897804E(p0);
		return retval;
	}

	static Any LUA_NATIVE_VOLUME__0xF6F5447D418DAA82(Any p0)
	{
		auto retval = VOLUME::_0xF6F5447D418DAA82(p0);
		return retval;
	}

	static void LUA_NATIVE_VOLUME__0xD4FA73FE628FEC63(Any p0, Any p1)
	{
		VOLUME::_0xD4FA73FE628FEC63(p0, p1);
	}

	static void LUA_NATIVE_VOLUME__0xB440F4E35393FC39(Volume volume, Any p1)
	{
		VOLUME::_0xB440F4E35393FC39(volume, p1);
	}

	static void LUA_NATIVE_VOLUME__0xD460135C98940274(Volume volume, Any p1)
	{
		VOLUME::_0xD460135C98940274(volume, p1);
	}

	static void LUA_NATIVE_VOLUME__0xEBA87B9273835CF3(Any p0, Any p1)
	{
		VOLUME::_0xEBA87B9273835CF3(p0, p1);
	}

	static Any LUA_NATIVE_VOLUME__0xAA9EE2AAFC717623(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5)
	{
		auto retval = VOLUME::_0xAA9EE2AAFC717623(p0, p1, p2, p3, p4, p5);
		return retval;
	}

	static Any LUA_NATIVE_VOLUME__0x870E9981ED27C815(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5)
	{
		auto retval = VOLUME::_0x870E9981ED27C815(p0, p1, p2, p3, p4, p5);
		return retval;
	}

	static bool LUA_NATIVE_VOLUME_DOES_VOLUME_COLLIDE_WITH_ANY_VOLUME_LOCK(float x, float y, float z, float radius, bool p4, int p5, int p6)
	{
		auto retval = (bool)VOLUME::DOES_VOLUME_COLLIDE_WITH_ANY_VOLUME_LOCK(x, y, z, radius, p4, p5, p6);
		return retval;
	}

	static bool LUA_NATIVE_VOLUME__IS_POINT_NEAR_VOLUME_LOCK_CENTER(float x, float y, float z, float radius, int p4, int p5, int flags)
	{
		auto retval = (bool)VOLUME::_IS_POINT_NEAR_VOLUME_LOCK_CENTER(x, y, z, radius, p4, p5, flags);
		return retval;
	}

	static Any LUA_NATIVE_VOLUME__0x51E52C9687FCDEEC(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6)
	{
		auto retval = VOLUME::_0x51E52C9687FCDEEC(p0, p1, p2, p3, p4, p5, p6);
		return retval;
	}

	static int LUA_NATIVE_VOLUME__FIND_VOLUME_LOCK_REQUEST_ID_WITH_ARGS(uintptr_t args)
	{
		auto retval = VOLUME::_FIND_VOLUME_LOCK_REQUEST_ID_WITH_ARGS((Any*)args);
		return retval;
	}

	static void LUA_NATIVE_VOLUME__MODIFY_VOLUME_LOCK_LOCATION(int volLock, float x, float y, float z)
	{
		VOLUME::_MODIFY_VOLUME_LOCK_LOCATION(volLock, x, y, z);
	}

	static void LUA_NATIVE_VOLUME__0x695DAC2DB928F308(Any p0, Any p1)
	{
		VOLUME::_0x695DAC2DB928F308(p0, p1);
	}

	static void LUA_NATIVE_VOLUME__RELEASE_LOCK_VOLUME(int volLockRequestId)
	{
		VOLUME::_RELEASE_LOCK_VOLUME(volLockRequestId);
	}

	static void LUA_NATIVE_VOLUME__0xAC355980681A7F89(Any p0)
	{
		VOLUME::_0xAC355980681A7F89(p0);
	}

	static bool LUA_NATIVE_VOLUME__ADD_ENTRY_VOLUME_LOCK(uintptr_t args)
	{
		auto retval = (bool)VOLUME::_ADD_ENTRY_VOLUME_LOCK((Any*)args);
		return retval;
	}

	static void LUA_NATIVE_VOLUME__0xC61E2FD926DBB406()
	{
		VOLUME::_0xC61E2FD926DBB406();
	}

	static int LUA_NATIVE_VOLUME_REQUEST_VOLUME_LOCK(float x, float y, float z, float radius, int p4, int p5)
	{
		auto retval = VOLUME::REQUEST_VOLUME_LOCK(x, y, z, radius, p4, p5);
		return retval;
	}

	static int LUA_NATIVE_VOLUME_REQUEST_VOLUME_LOCK_WITH_ARGS(uintptr_t args)
	{
		auto retval = VOLUME::REQUEST_VOLUME_LOCK_WITH_ARGS((Any*)args);
		return retval;
	}

	static bool LUA_NATIVE_VOLUME_IS_VOLUME_LOCK_REQUEST_VALID(int volLockRequestId)
	{
		auto retval = (bool)VOLUME::IS_VOLUME_LOCK_REQUEST_VALID(volLockRequestId);
		return retval;
	}

	static int LUA_NATIVE_VOLUME_GET_VOLUME_LOCK_REQUEST_STATUS(int volLockRequestId)
	{
		auto retval = VOLUME::GET_VOLUME_LOCK_REQUEST_STATUS(volLockRequestId);
		return retval;
	}

	static Any LUA_NATIVE_VOLUME__0x351D71B8B72B858B(Any p0)
	{
		auto retval = VOLUME::_0x351D71B8B72B858B(p0);
		return retval;
	}

	static void LUA_NATIVE_VOLUME__0xFA15C9A320E707B0()
	{
		VOLUME::_0xFA15C9A320E707B0();
	}

	static void LUA_NATIVE_VOLUME__0x52572B331E693AED(Any p0, Any p1, Any p2)
	{
		VOLUME::_0x52572B331E693AED(p0, p1, p2);
	}

	static void LUA_NATIVE_VOLUME__0x128FC3A893BF853A(Any p0)
	{
		VOLUME::_0x128FC3A893BF853A(p0);
	}

	static void LUA_NATIVE_VOLUME__SET_VOLUME_RELATIONSHIP(Volume volume, Hash relationshipGroup)
	{
		VOLUME::_SET_VOLUME_RELATIONSHIP(volume, relationshipGroup);
	}

	static Hash LUA_NATIVE_VOLUME__GET_VOLUME_RELATIONSHIP(Volume volume)
	{
		auto retval = VOLUME::_GET_VOLUME_RELATIONSHIP(volume);
		return retval;
	}

	void RegisterNatives_VOLUME(sol::state& L)
	{
		auto VOLUME = L["VOLUME"].get_or_create<sol::table>();
		VOLUME.set_function("_CREATE_VOLUME_BY_HASH", LUA_NATIVE_VOLUME__CREATE_VOLUME_BY_HASH);
		VOLUME.set_function("CREATE_VOLUME_BOX", LUA_NATIVE_VOLUME_CREATE_VOLUME_BOX);
		VOLUME.set_function("CREATE_VOLUME_CYLINDER", LUA_NATIVE_VOLUME_CREATE_VOLUME_CYLINDER);
		VOLUME.set_function("CREATE_VOLUME_SPHERE", LUA_NATIVE_VOLUME_CREATE_VOLUME_SPHERE);
		VOLUME.set_function("CREATE_VOLUME_AGGREGATE", LUA_NATIVE_VOLUME_CREATE_VOLUME_AGGREGATE);
		VOLUME.set_function("_CREATE_VOLUME_BY_HASH_WITH_CUSTOM_NAME", LUA_NATIVE_VOLUME__CREATE_VOLUME_BY_HASH_WITH_CUSTOM_NAME);
		VOLUME.set_function("_CREATE_ANTI_GRIEF_VOLUME", LUA_NATIVE_VOLUME__CREATE_ANTI_GRIEF_VOLUME);
		VOLUME.set_function("_SET_ANTI_GRIEF_VOLUME_BLOCKS_HORSE", LUA_NATIVE_VOLUME__SET_ANTI_GRIEF_VOLUME_BLOCKS_HORSE);
		VOLUME.set_function("_SET_ANTI_GRIEF_VOLUME_BLOCKS_PLAYER", LUA_NATIVE_VOLUME__SET_ANTI_GRIEF_VOLUME_BLOCKS_PLAYER);
		VOLUME.set_function("_CREATE_WALK_AND_TALK_VOLUME", LUA_NATIVE_VOLUME__CREATE_WALK_AND_TALK_VOLUME);
		VOLUME.set_function("_CREATE_SPEED_VOLUME", LUA_NATIVE_VOLUME__CREATE_SPEED_VOLUME);
		VOLUME.set_function("_CREATE_VOLUME_BOX_WITH_CUSTOM_NAME", LUA_NATIVE_VOLUME__CREATE_VOLUME_BOX_WITH_CUSTOM_NAME);
		VOLUME.set_function("_CREATE_VOLUME_CYLINDER_WITH_CUSTOM_NAME", LUA_NATIVE_VOLUME__CREATE_VOLUME_CYLINDER_WITH_CUSTOM_NAME);
		VOLUME.set_function("_CREATE_VOLUME_SPHERE_WITH_CUSTOM_NAME", LUA_NATIVE_VOLUME__CREATE_VOLUME_SPHERE_WITH_CUSTOM_NAME);
		VOLUME.set_function("_CREATE_VOLUME_AGGREGATE_WITH_CUSTOM_NAME", LUA_NATIVE_VOLUME__CREATE_VOLUME_AGGREGATE_WITH_CUSTOM_NAME);
		VOLUME.set_function("_ADD_BOUNDS_TO_AGGREGATE_VOLUME", LUA_NATIVE_VOLUME__ADD_BOUNDS_TO_AGGREGATE_VOLUME);
		VOLUME.set_function("_REMOVE_BOUNDS_FROM_AGGREGATE_VOLUME", LUA_NATIVE_VOLUME__REMOVE_BOUNDS_FROM_AGGREGATE_VOLUME);
		VOLUME.set_function("_ADD_VOLUME_TO_VOLUME_AGGREGATE", LUA_NATIVE_VOLUME__ADD_VOLUME_TO_VOLUME_AGGREGATE);
		VOLUME.set_function("_ADD_BOX_VOLUME_TO_VOLUME_AGGREGATE", LUA_NATIVE_VOLUME__ADD_BOX_VOLUME_TO_VOLUME_AGGREGATE);
		VOLUME.set_function("_ADD_CYLINDER_VOLUME_TO_VOLUME_AGGREGATE", LUA_NATIVE_VOLUME__ADD_CYLINDER_VOLUME_TO_VOLUME_AGGREGATE);
		VOLUME.set_function("_ADD_SPHERE_VOLUME_TO_VOLUME_AGGREGATE", LUA_NATIVE_VOLUME__ADD_SPHERE_VOLUME_TO_VOLUME_AGGREGATE);
		VOLUME.set_function("DELETE_VOLUME", LUA_NATIVE_VOLUME_DELETE_VOLUME);
		VOLUME.set_function("DOES_VOLUME_EXIST", LUA_NATIVE_VOLUME_DOES_VOLUME_EXIST);
		VOLUME.set_function("IS_POINT_IN_VOLUME", LUA_NATIVE_VOLUME_IS_POINT_IN_VOLUME);
		VOLUME.set_function("GET_VOLUME_COORDS", LUA_NATIVE_VOLUME_GET_VOLUME_COORDS);
		VOLUME.set_function("SET_VOLUME_COORDS", LUA_NATIVE_VOLUME_SET_VOLUME_COORDS);
		VOLUME.set_function("GET_VOLUME_ROTATION", LUA_NATIVE_VOLUME_GET_VOLUME_ROTATION);
		VOLUME.set_function("SET_VOLUME_ROTATION", LUA_NATIVE_VOLUME_SET_VOLUME_ROTATION);
		VOLUME.set_function("GET_VOLUME_SCALE", LUA_NATIVE_VOLUME_GET_VOLUME_SCALE);
		VOLUME.set_function("SET_VOLUME_SCALE", LUA_NATIVE_VOLUME_SET_VOLUME_SCALE);
		VOLUME.set_function("_GET_VOLUME_BOUNDS", LUA_NATIVE_VOLUME__GET_VOLUME_BOUNDS);
		VOLUME.set_function("_0x748C5F51A18CB8F0", LUA_NATIVE_VOLUME__0x748C5F51A18CB8F0);
		VOLUME.set_function("_0x2B32B11520626229", LUA_NATIVE_VOLUME__0x2B32B11520626229);
		VOLUME.set_function("_0x40F769D31A00D5A0", LUA_NATIVE_VOLUME__0x40F769D31A00D5A0);
		VOLUME.set_function("_0xD882C5B3991575B7", LUA_NATIVE_VOLUME__0xD882C5B3991575B7);
		VOLUME.set_function("_0xB469CFD9E065EB99", LUA_NATIVE_VOLUME__0xB469CFD9E065EB99);
		VOLUME.set_function("_0x7FD78DFD0C5D7B9B", LUA_NATIVE_VOLUME__0x7FD78DFD0C5D7B9B);
		VOLUME.set_function("_0xEE1D6FF54CAF7714", LUA_NATIVE_VOLUME__0xEE1D6FF54CAF7714);
		VOLUME.set_function("_0xD52DF30355EA7C8E", LUA_NATIVE_VOLUME__0xD52DF30355EA7C8E);
		VOLUME.set_function("SET_VOLUME_OWNER_PERSISTENT_CHARACTER", LUA_NATIVE_VOLUME_SET_VOLUME_OWNER_PERSISTENT_CHARACTER);
		VOLUME.set_function("_0x6D5F9E69BA1BE783", LUA_NATIVE_VOLUME__0x6D5F9E69BA1BE783);
		VOLUME.set_function("_0x998202B206872672", LUA_NATIVE_VOLUME__0x998202B206872672);
		VOLUME.set_function("_0x4A8FEFC43FD8AC9B", LUA_NATIVE_VOLUME__0x4A8FEFC43FD8AC9B);
		VOLUME.set_function("_0xF3A2FBA5985C8CD5", LUA_NATIVE_VOLUME__0xF3A2FBA5985C8CD5);
		VOLUME.set_function("_0x53D05D60E5F5B40C", LUA_NATIVE_VOLUME__0x53D05D60E5F5B40C);
		VOLUME.set_function("_0xCA5C90D40665D5CE", LUA_NATIVE_VOLUME__0xCA5C90D40665D5CE);
		VOLUME.set_function("_0x3EFABB21E14A6BD1", LUA_NATIVE_VOLUME__0x3EFABB21E14A6BD1);
		VOLUME.set_function("_IS_AGGREGATE_VOLUME", LUA_NATIVE_VOLUME__IS_AGGREGATE_VOLUME);
		VOLUME.set_function("_CREATE_VOLUME_LOCK", LUA_NATIVE_VOLUME__CREATE_VOLUME_LOCK);
		VOLUME.set_function("_CREATE_VOLUME_LOCK_ATTACHED_TO_ENTITY", LUA_NATIVE_VOLUME__CREATE_VOLUME_LOCK_ATTACHED_TO_ENTITY);
		VOLUME.set_function("_IS_VOLUME_LOCK_REQUEST_VALID_2", LUA_NATIVE_VOLUME__IS_VOLUME_LOCK_REQUEST_VALID_2);
		VOLUME.set_function("_0xC4019CF9AE8E931A", LUA_NATIVE_VOLUME__0xC4019CF9AE8E931A);
		VOLUME.set_function("_0xF6CE6F9C3897804E", LUA_NATIVE_VOLUME__0xF6CE6F9C3897804E);
		VOLUME.set_function("_0xF6F5447D418DAA82", LUA_NATIVE_VOLUME__0xF6F5447D418DAA82);
		VOLUME.set_function("_0xD4FA73FE628FEC63", LUA_NATIVE_VOLUME__0xD4FA73FE628FEC63);
		VOLUME.set_function("_0xB440F4E35393FC39", LUA_NATIVE_VOLUME__0xB440F4E35393FC39);
		VOLUME.set_function("_0xD460135C98940274", LUA_NATIVE_VOLUME__0xD460135C98940274);
		VOLUME.set_function("_0xEBA87B9273835CF3", LUA_NATIVE_VOLUME__0xEBA87B9273835CF3);
		VOLUME.set_function("_0xAA9EE2AAFC717623", LUA_NATIVE_VOLUME__0xAA9EE2AAFC717623);
		VOLUME.set_function("_0x870E9981ED27C815", LUA_NATIVE_VOLUME__0x870E9981ED27C815);
		VOLUME.set_function("DOES_VOLUME_COLLIDE_WITH_ANY_VOLUME_LOCK", LUA_NATIVE_VOLUME_DOES_VOLUME_COLLIDE_WITH_ANY_VOLUME_LOCK);
		VOLUME.set_function("_IS_POINT_NEAR_VOLUME_LOCK_CENTER", LUA_NATIVE_VOLUME__IS_POINT_NEAR_VOLUME_LOCK_CENTER);
		VOLUME.set_function("_0x51E52C9687FCDEEC", LUA_NATIVE_VOLUME__0x51E52C9687FCDEEC);
		VOLUME.set_function("_FIND_VOLUME_LOCK_REQUEST_ID_WITH_ARGS", LUA_NATIVE_VOLUME__FIND_VOLUME_LOCK_REQUEST_ID_WITH_ARGS);
		VOLUME.set_function("_MODIFY_VOLUME_LOCK_LOCATION", LUA_NATIVE_VOLUME__MODIFY_VOLUME_LOCK_LOCATION);
		VOLUME.set_function("_0x695DAC2DB928F308", LUA_NATIVE_VOLUME__0x695DAC2DB928F308);
		VOLUME.set_function("_RELEASE_LOCK_VOLUME", LUA_NATIVE_VOLUME__RELEASE_LOCK_VOLUME);
		VOLUME.set_function("_0xAC355980681A7F89", LUA_NATIVE_VOLUME__0xAC355980681A7F89);
		VOLUME.set_function("_ADD_ENTRY_VOLUME_LOCK", LUA_NATIVE_VOLUME__ADD_ENTRY_VOLUME_LOCK);
		VOLUME.set_function("_0xC61E2FD926DBB406", LUA_NATIVE_VOLUME__0xC61E2FD926DBB406);
		VOLUME.set_function("REQUEST_VOLUME_LOCK", LUA_NATIVE_VOLUME_REQUEST_VOLUME_LOCK);
		VOLUME.set_function("REQUEST_VOLUME_LOCK_WITH_ARGS", LUA_NATIVE_VOLUME_REQUEST_VOLUME_LOCK_WITH_ARGS);
		VOLUME.set_function("IS_VOLUME_LOCK_REQUEST_VALID", LUA_NATIVE_VOLUME_IS_VOLUME_LOCK_REQUEST_VALID);
		VOLUME.set_function("GET_VOLUME_LOCK_REQUEST_STATUS", LUA_NATIVE_VOLUME_GET_VOLUME_LOCK_REQUEST_STATUS);
		VOLUME.set_function("_0x351D71B8B72B858B", LUA_NATIVE_VOLUME__0x351D71B8B72B858B);
		VOLUME.set_function("_0xFA15C9A320E707B0", LUA_NATIVE_VOLUME__0xFA15C9A320E707B0);
		VOLUME.set_function("_0x52572B331E693AED", LUA_NATIVE_VOLUME__0x52572B331E693AED);
		VOLUME.set_function("_0x128FC3A893BF853A", LUA_NATIVE_VOLUME__0x128FC3A893BF853A);
		VOLUME.set_function("_SET_VOLUME_RELATIONSHIP", LUA_NATIVE_VOLUME__SET_VOLUME_RELATIONSHIP);
		VOLUME.set_function("_GET_VOLUME_RELATIONSHIP", LUA_NATIVE_VOLUME__GET_VOLUME_RELATIONSHIP);
	}
}
