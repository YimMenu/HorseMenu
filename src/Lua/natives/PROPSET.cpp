#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static bool LUA_NATIVE_PROPSET__REQUEST_PROP_SET(Hash hash)
	{
		auto retval = (bool)PROPSET::_REQUEST_PROP_SET(hash);
		return retval;
	}

	static bool LUA_NATIVE_PROPSET__REQUEST_PROP_SET_2(Hash hash)
	{
		auto retval = (bool)PROPSET::_REQUEST_PROP_SET_2(hash);
		return retval;
	}

	static bool LUA_NATIVE_PROPSET__HAS_PROP_SET_LOADED(Hash hash)
	{
		auto retval = (bool)PROPSET::_HAS_PROP_SET_LOADED(hash);
		return retval;
	}

	static bool LUA_NATIVE_PROPSET__HAS_PROP_SET_LOADED_2(Hash hash)
	{
		auto retval = (bool)PROPSET::_HAS_PROP_SET_LOADED_2(hash);
		return retval;
	}

	static void LUA_NATIVE_PROPSET__SET_PROP_SET_AS_NO_LONGER_NEEDED(PropSet propSet)
	{
		PROPSET::_SET_PROP_SET_AS_NO_LONGER_NEEDED(propSet);
	}

	static void LUA_NATIVE_PROPSET__DELETE_PROP_SET(PropSet propSet, bool p1, bool p2)
	{
		PROPSET::_DELETE_PROP_SET(propSet, p1, p2);
	}

	static bool LUA_NATIVE_PROPSET__RELEASE_PROP_SET(Hash hash)
	{
		auto retval = (bool)PROPSET::_RELEASE_PROP_SET(hash);
		return retval;
	}

	static PropSet LUA_NATIVE_PROPSET__CREATE_PROP_SET(Hash propsetType, float x, float y, float z, int placementType, float heading, float zProbe, bool p7, bool useVegMod)
	{
		auto retval = PROPSET::_CREATE_PROP_SET(propsetType, x, y, z, placementType, heading, zProbe, p7, useVegMod);
		return retval;
	}

	static PropSet LUA_NATIVE_PROPSET__CREATE_PROP_SET_2(Hash propsetType, float x, float y, float z, int placementType, float heading, float zProbe, bool p7, bool useVegMod)
	{
		auto retval = PROPSET::_CREATE_PROP_SET_2(propsetType, x, y, z, placementType, heading, zProbe, p7, useVegMod);
		return retval;
	}

	static PropSet LUA_NATIVE_PROPSET_CREATE_PROP_SET_INSTANCE_ATTACHED_TO_ENTITY(Hash hash, float x, float y, float z, Entity entity, float p5, bool p6, int p7, bool p8)
	{
		auto retval = PROPSET::CREATE_PROP_SET_INSTANCE_ATTACHED_TO_ENTITY(hash, x, y, z, entity, p5, p6, p7, p8);
		return retval;
	}

	static PropSet LUA_NATIVE_PROPSET__CREATE_PROP_SET_INSTANCE_ATTACHED_TO_ENTITY_2(Hash hash, float x, float y, float z, Entity entity, float p5, bool p6, int p7, bool p8)
	{
		auto retval = PROPSET::_CREATE_PROP_SET_INSTANCE_ATTACHED_TO_ENTITY_2(hash, x, y, z, entity, p5, p6, p7, p8);
		return retval;
	}

	static bool LUA_NATIVE_PROPSET_DOES_PROP_SET_EXIST(PropSet propSet)
	{
		auto retval = (bool)PROPSET::DOES_PROP_SET_EXIST(propSet);
		return retval;
	}

	static bool LUA_NATIVE_PROPSET__DOES_PROP_SET_OF_TYPE_EXIST_NEAR_COORDS(Hash propsetHash, float x, float y, float z)
	{
		auto retval = (bool)PROPSET::_DOES_PROP_SET_OF_TYPE_EXIST_NEAR_COORDS(propsetHash, x, y, z);
		return retval;
	}

	static bool LUA_NATIVE_PROPSET_IS_PROP_SET_FULLY_LOADED(PropSet propSet)
	{
		auto retval = (bool)PROPSET::IS_PROP_SET_FULLY_LOADED(propSet);
		return retval;
	}

	static void LUA_NATIVE_PROPSET__SET_PROP_SET_VISIBLE(PropSet propSet, bool toggle)
	{
		PROPSET::_SET_PROP_SET_VISIBLE(propSet, toggle);
	}

	static bool LUA_NATIVE_PROPSET__IS_PROP_SET_VISIBLE(PropSet propSet)
	{
		auto retval = (bool)PROPSET::_IS_PROP_SET_VISIBLE(propSet);
		return retval;
	}

	static Hash LUA_NATIVE_PROPSET__GET_PROP_SET_MODEL(PropSet propSet)
	{
		auto retval = PROPSET::_GET_PROP_SET_MODEL(propSet);
		return retval;
	}

	static Hash LUA_NATIVE_PROPSET__GET_VEHICLE_PROP_SET_HASH(Vehicle vehicle)
	{
		auto retval = PROPSET::_GET_VEHICLE_PROP_SET_HASH(vehicle);
		return retval;
	}

	static int LUA_NATIVE_PROPSET__GET_ENTITIES_FROM_PROP_SET(PropSet propSet, ItemSet itemSet, Hash model, bool p3, bool p4)
	{
		auto retval = PROPSET::_GET_ENTITIES_FROM_PROP_SET(propSet, itemSet, model, p3, p4);
		return retval;
	}

	static void LUA_NATIVE_PROPSET__0xC4B67EF3FD65622D(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5)
	{
		PROPSET::_0xC4B67EF3FD65622D(p0, p1, p2, p3, p4, p5);
	}

	static void LUA_NATIVE_PROPSET__0x58E0B01D45CA7357(Any p0)
	{
		PROPSET::_0x58E0B01D45CA7357(p0);
	}

	static void LUA_NATIVE_PROPSET__SET_PROP_SET_FLAG(PropSet propSet, int flag)
	{
		PROPSET::_SET_PROP_SET_FLAG(propSet, flag);
	}

	static PropSet LUA_NATIVE_PROPSET__GET_VEHICLE_PROP_SET(Vehicle vehicle)
	{
		auto retval = PROPSET::_GET_VEHICLE_PROP_SET(vehicle);
		return retval;
	}

	static bool LUA_NATIVE_PROPSET__DOES_VEHICLE_HAVE_ANY_PROP_SET(Vehicle vehicle)
	{
		auto retval = (bool)PROPSET::_DOES_VEHICLE_HAVE_ANY_PROP_SET(vehicle);
		return retval;
	}

	static void LUA_NATIVE_PROPSET__ADD_PROP_SET_FOR_VEHICLE(Vehicle vehicle, Hash propset)
	{
		PROPSET::_ADD_PROP_SET_FOR_VEHICLE(vehicle, propset);
	}

	static void LUA_NATIVE_PROPSET__REMOVE_VEHICLE_PROP_SETS(Vehicle vehicle)
	{
		PROPSET::_REMOVE_VEHICLE_PROP_SETS(vehicle);
	}

	static bool LUA_NATIVE_PROPSET__IS_VEHICLE_PROP_SET_LOADED(Vehicle vehicle)
	{
		auto retval = (bool)PROPSET::_IS_VEHICLE_PROP_SET_LOADED(vehicle);
		return retval;
	}

	static void LUA_NATIVE_PROPSET__ADD_ADDITIONAL_PROP_SET_FOR_VEHICLE(Vehicle vehicle, Hash propset)
	{
		PROPSET::_ADD_ADDITIONAL_PROP_SET_FOR_VEHICLE(vehicle, propset);
	}

	static bool LUA_NATIVE_PROPSET__IS_VEHICLE_PROP_SET_LOADED_ADDITIONAL(Vehicle vehicle)
	{
		auto retval = (bool)PROPSET::_IS_VEHICLE_PROP_SET_LOADED_ADDITIONAL(vehicle);
		return retval;
	}

	static PropSet LUA_NATIVE_PROPSET__GET_VEHICLE_LIGHT_PROP_SET(Vehicle vehicle)
	{
		auto retval = PROPSET::_GET_VEHICLE_LIGHT_PROP_SET(vehicle);
		return retval;
	}

	static bool LUA_NATIVE_PROPSET__DOES_VEHICLE_HAVE_ANY_LIGHT_PROP_SET(Vehicle vehicle)
	{
		auto retval = (bool)PROPSET::_DOES_VEHICLE_HAVE_ANY_LIGHT_PROP_SET(vehicle);
		return retval;
	}

	static void LUA_NATIVE_PROPSET__ADD_LIGHT_PROP_SET_TO_VEHICLE(Vehicle vehicle, Hash lightPropset)
	{
		PROPSET::_ADD_LIGHT_PROP_SET_TO_VEHICLE(vehicle, lightPropset);
	}

	static void LUA_NATIVE_PROPSET__REMOVE_VEHICLE_LIGHT_PROP_SETS(Vehicle vehicle)
	{
		PROPSET::_REMOVE_VEHICLE_LIGHT_PROP_SETS(vehicle);
	}

	static bool LUA_NATIVE_PROPSET__IS_VEHICLE_LIGHT_PROP_SET_LOADED(Vehicle vehicle)
	{
		auto retval = (bool)PROPSET::_IS_VEHICLE_LIGHT_PROP_SET_LOADED(vehicle);
		return retval;
	}

	static PropSet LUA_NATIVE_PROPSET__GET_TRAIN_CARRIAGE_PROP_SET(Entity trainCarriage)
	{
		auto retval = PROPSET::_GET_TRAIN_CARRIAGE_PROP_SET(trainCarriage);
		return retval;
	}

	static bool LUA_NATIVE_PROPSET__HAS_VEHICLE_TRAILER_PROP_SET_LOADED(Vehicle vehicle, int wagonIndex)
	{
		auto retval = (bool)PROPSET::_HAS_VEHICLE_TRAILER_PROP_SET_LOADED(vehicle, wagonIndex);
		return retval;
	}

	static PropSet LUA_NATIVE_PROPSET__GET_PROP_SET_AT_COORDS(Hash propsetHash, float x, float y, float z)
	{
		auto retval = PROPSET::_GET_PROP_SET_AT_COORDS(propsetHash, x, y, z);
		return retval;
	}

	void RegisterNatives_PROPSET(sol::state& L)
	{
		auto PROPSET = L["PROPSET"].get_or_create<sol::table>();
		PROPSET.set_function("_REQUEST_PROP_SET", LUA_NATIVE_PROPSET__REQUEST_PROP_SET);
		PROPSET.set_function("_REQUEST_PROP_SET_2", LUA_NATIVE_PROPSET__REQUEST_PROP_SET_2);
		PROPSET.set_function("_HAS_PROP_SET_LOADED", LUA_NATIVE_PROPSET__HAS_PROP_SET_LOADED);
		PROPSET.set_function("_HAS_PROP_SET_LOADED_2", LUA_NATIVE_PROPSET__HAS_PROP_SET_LOADED_2);
		PROPSET.set_function("_SET_PROP_SET_AS_NO_LONGER_NEEDED", LUA_NATIVE_PROPSET__SET_PROP_SET_AS_NO_LONGER_NEEDED);
		PROPSET.set_function("_DELETE_PROP_SET", LUA_NATIVE_PROPSET__DELETE_PROP_SET);
		PROPSET.set_function("_RELEASE_PROP_SET", LUA_NATIVE_PROPSET__RELEASE_PROP_SET);
		PROPSET.set_function("_CREATE_PROP_SET", LUA_NATIVE_PROPSET__CREATE_PROP_SET);
		PROPSET.set_function("_CREATE_PROP_SET_2", LUA_NATIVE_PROPSET__CREATE_PROP_SET_2);
		PROPSET.set_function("CREATE_PROP_SET_INSTANCE_ATTACHED_TO_ENTITY", LUA_NATIVE_PROPSET_CREATE_PROP_SET_INSTANCE_ATTACHED_TO_ENTITY);
		PROPSET.set_function("_CREATE_PROP_SET_INSTANCE_ATTACHED_TO_ENTITY_2", LUA_NATIVE_PROPSET__CREATE_PROP_SET_INSTANCE_ATTACHED_TO_ENTITY_2);
		PROPSET.set_function("DOES_PROP_SET_EXIST", LUA_NATIVE_PROPSET_DOES_PROP_SET_EXIST);
		PROPSET.set_function("_DOES_PROP_SET_OF_TYPE_EXIST_NEAR_COORDS", LUA_NATIVE_PROPSET__DOES_PROP_SET_OF_TYPE_EXIST_NEAR_COORDS);
		PROPSET.set_function("IS_PROP_SET_FULLY_LOADED", LUA_NATIVE_PROPSET_IS_PROP_SET_FULLY_LOADED);
		PROPSET.set_function("_SET_PROP_SET_VISIBLE", LUA_NATIVE_PROPSET__SET_PROP_SET_VISIBLE);
		PROPSET.set_function("_IS_PROP_SET_VISIBLE", LUA_NATIVE_PROPSET__IS_PROP_SET_VISIBLE);
		PROPSET.set_function("_GET_PROP_SET_MODEL", LUA_NATIVE_PROPSET__GET_PROP_SET_MODEL);
		PROPSET.set_function("_GET_VEHICLE_PROP_SET_HASH", LUA_NATIVE_PROPSET__GET_VEHICLE_PROP_SET_HASH);
		PROPSET.set_function("_GET_ENTITIES_FROM_PROP_SET", LUA_NATIVE_PROPSET__GET_ENTITIES_FROM_PROP_SET);
		PROPSET.set_function("_0xC4B67EF3FD65622D", LUA_NATIVE_PROPSET__0xC4B67EF3FD65622D);
		PROPSET.set_function("_0x58E0B01D45CA7357", LUA_NATIVE_PROPSET__0x58E0B01D45CA7357);
		PROPSET.set_function("_SET_PROP_SET_FLAG", LUA_NATIVE_PROPSET__SET_PROP_SET_FLAG);
		PROPSET.set_function("_GET_VEHICLE_PROP_SET", LUA_NATIVE_PROPSET__GET_VEHICLE_PROP_SET);
		PROPSET.set_function("_DOES_VEHICLE_HAVE_ANY_PROP_SET", LUA_NATIVE_PROPSET__DOES_VEHICLE_HAVE_ANY_PROP_SET);
		PROPSET.set_function("_ADD_PROP_SET_FOR_VEHICLE", LUA_NATIVE_PROPSET__ADD_PROP_SET_FOR_VEHICLE);
		PROPSET.set_function("_REMOVE_VEHICLE_PROP_SETS", LUA_NATIVE_PROPSET__REMOVE_VEHICLE_PROP_SETS);
		PROPSET.set_function("_IS_VEHICLE_PROP_SET_LOADED", LUA_NATIVE_PROPSET__IS_VEHICLE_PROP_SET_LOADED);
		PROPSET.set_function("_ADD_ADDITIONAL_PROP_SET_FOR_VEHICLE", LUA_NATIVE_PROPSET__ADD_ADDITIONAL_PROP_SET_FOR_VEHICLE);
		PROPSET.set_function("_IS_VEHICLE_PROP_SET_LOADED_ADDITIONAL", LUA_NATIVE_PROPSET__IS_VEHICLE_PROP_SET_LOADED_ADDITIONAL);
		PROPSET.set_function("_GET_VEHICLE_LIGHT_PROP_SET", LUA_NATIVE_PROPSET__GET_VEHICLE_LIGHT_PROP_SET);
		PROPSET.set_function("_DOES_VEHICLE_HAVE_ANY_LIGHT_PROP_SET", LUA_NATIVE_PROPSET__DOES_VEHICLE_HAVE_ANY_LIGHT_PROP_SET);
		PROPSET.set_function("_ADD_LIGHT_PROP_SET_TO_VEHICLE", LUA_NATIVE_PROPSET__ADD_LIGHT_PROP_SET_TO_VEHICLE);
		PROPSET.set_function("_REMOVE_VEHICLE_LIGHT_PROP_SETS", LUA_NATIVE_PROPSET__REMOVE_VEHICLE_LIGHT_PROP_SETS);
		PROPSET.set_function("_IS_VEHICLE_LIGHT_PROP_SET_LOADED", LUA_NATIVE_PROPSET__IS_VEHICLE_LIGHT_PROP_SET_LOADED);
		PROPSET.set_function("_GET_TRAIN_CARRIAGE_PROP_SET", LUA_NATIVE_PROPSET__GET_TRAIN_CARRIAGE_PROP_SET);
		PROPSET.set_function("_HAS_VEHICLE_TRAILER_PROP_SET_LOADED", LUA_NATIVE_PROPSET__HAS_VEHICLE_TRAILER_PROP_SET_LOADED);
		PROPSET.set_function("_GET_PROP_SET_AT_COORDS", LUA_NATIVE_PROPSET__GET_PROP_SET_AT_COORDS);
	}
}
