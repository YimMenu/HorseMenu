#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static Object LUA_NATIVE_OBJECT_CREATE_OBJECT(Hash ModelIndex, float VecNewCoorsX, float VecNewCoorsY, float VecNewCoorsZ, bool RegisterAsNetworkObject, bool ScriptHostObject, bool ForceToBeObject, bool p7, bool p8)
	{
		auto retval = OBJECT::CREATE_OBJECT(ModelIndex, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ, RegisterAsNetworkObject, ScriptHostObject, ForceToBeObject, p7, p8);
		return retval;
	}

	static Object LUA_NATIVE_OBJECT_CREATE_OBJECT_NO_OFFSET(Hash ModelIndex, float VecNewCoorsX, float VecNewCoorsY, float VecNewCoorsZ, bool RegisterAsNetworkObject, bool ScriptHostObject, bool ForceToBeObject, bool p7)
	{
		auto retval = OBJECT::CREATE_OBJECT_NO_OFFSET(ModelIndex, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ, RegisterAsNetworkObject, ScriptHostObject, ForceToBeObject, p7);
		return retval;
	}

	static Object LUA_NATIVE_OBJECT_DELETE_OBJECT(Object ObjectIndex)
	{
		OBJECT::DELETE_OBJECT(&ObjectIndex);
		return ObjectIndex;
	}

	static bool LUA_NATIVE_OBJECT_PLACE_OBJECT_ON_GROUND_PROPERLY(Object ObjectIndex, bool p1)
	{
		auto retval = (bool)OBJECT::PLACE_OBJECT_ON_GROUND_PROPERLY(ObjectIndex, p1);
		return retval;
	}

	static bool LUA_NATIVE_OBJECT_SLIDE_OBJECT(Object ObjectID, float VecDestCoorstX, float VecDestCoorstY, float VecDestCoorstZ, float VecIncrementX, float VecIncrementY, float VecIncrementZ, bool StopOnCollision)
	{
		auto retval = (bool)OBJECT::SLIDE_OBJECT(ObjectID, VecDestCoorstX, VecDestCoorstY, VecDestCoorstZ, VecIncrementX, VecIncrementY, VecIncrementZ, StopOnCollision);
		return retval;
	}

	static void LUA_NATIVE_OBJECT_SET_OBJECT_TARGETTABLE(Object ObjectID, bool Targettable)
	{
		OBJECT::SET_OBJECT_TARGETTABLE(ObjectID, Targettable);
	}

	static void LUA_NATIVE_OBJECT__SET_OBJECT_TARGETTABLE_2(Object object, bool targettable)
	{
		OBJECT::_SET_OBJECT_TARGETTABLE_2(object, targettable);
	}

	static void LUA_NATIVE_OBJECT__SET_OBJECT_TARGETTABLE_FOCUS(Object object, bool p1, bool p2)
	{
		OBJECT::_SET_OBJECT_TARGETTABLE_FOCUS(object, p1, p2);
	}

	static void LUA_NATIVE_OBJECT__0xF6E88489B4E6EBE5(Any p0, Any p1)
	{
		OBJECT::_0xF6E88489B4E6EBE5(p0, p1);
	}

	static void LUA_NATIVE_OBJECT__0xE157A8A336C7F04A(Any p0, Any p1)
	{
		OBJECT::_0xE157A8A336C7F04A(p0, p1);
	}

	static void LUA_NATIVE_OBJECT__0x46CBCF0E98A4E156(Any p0, Any p1)
	{
		OBJECT::_0x46CBCF0E98A4E156(p0, p1);
	}

	static Object LUA_NATIVE_OBJECT_GET_CLOSEST_OBJECT_OF_TYPE(float scrVecCentreCoorsX, float scrVecCentreCoorsY, float scrVecCentreCoorsZ, float Radius, Hash ObjectModelHashKey, bool RegisterAsScriptObject, bool ScriptHostObject, bool RegisterAsNetworkObject)
	{
		auto retval = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(scrVecCentreCoorsX, scrVecCentreCoorsY, scrVecCentreCoorsZ, Radius, ObjectModelHashKey, RegisterAsScriptObject, ScriptHostObject, RegisterAsNetworkObject);
		return retval;
	}

	static bool LUA_NATIVE_OBJECT_HAS_OBJECT_BEEN_BROKEN(Object ObjectID)
	{
		auto retval = (bool)OBJECT::HAS_OBJECT_BEEN_BROKEN(ObjectID);
		return retval;
	}

	static bool LUA_NATIVE_OBJECT_HAS_CLOSEST_OBJECT_OF_TYPE_BEEN_BROKEN(float scrVecCoorsX, float scrVecCoorsY, float scrVecCoorsZ, float Radius, Hash model, int SearchFlags)
	{
		auto retval = (bool)OBJECT::HAS_CLOSEST_OBJECT_OF_TYPE_BEEN_BROKEN(scrVecCoorsX, scrVecCoorsY, scrVecCoorsZ, Radius, model, SearchFlags);
		return retval;
	}

	static Vector3 LUA_NATIVE_OBJECT_GET_OFFSET_FROM_COORD_AND_HEADING_IN_WORLD_COORDS(float vPosX, float vPosY, float vPosZ, float fHeading, float vOffsetX, float vOffsetY, float vOffsetZ)
	{
		auto retval = OBJECT::GET_OFFSET_FROM_COORD_AND_HEADING_IN_WORLD_COORDS(vPosX, vPosY, vPosZ, fHeading, vOffsetX, vOffsetY, vOffsetZ);
		return retval;
	}

	static void LUA_NATIVE_OBJECT__ADD_DOOR_TO_SYSTEM_NEW(Hash doorHash, bool p1, bool p2, bool p3, int threadId, int p5, bool p6)
	{
		OBJECT::_ADD_DOOR_TO_SYSTEM_NEW(doorHash, p1, p2, p3, threadId, p5, p6);
	}

	static bool LUA_NATIVE_OBJECT__IS_DOOR_REGISTERED_WITH_NETWORK(Hash doorHash)
	{
		auto retval = (bool)OBJECT::_IS_DOOR_REGISTERED_WITH_NETWORK(doorHash);
		return retval;
	}

	static void LUA_NATIVE_OBJECT_REMOVE_DOOR_FROM_SYSTEM(Hash doorEnumHash)
	{
		OBJECT::REMOVE_DOOR_FROM_SYSTEM(doorEnumHash);
	}

	static void LUA_NATIVE_OBJECT_DOOR_SYSTEM_SET_DOOR_STATE(Hash doorEnumHash, int state)
	{
		OBJECT::DOOR_SYSTEM_SET_DOOR_STATE(doorEnumHash, state);
	}

	static int LUA_NATIVE_OBJECT_DOOR_SYSTEM_GET_DOOR_STATE(Hash doorEnumHash)
	{
		auto retval = OBJECT::DOOR_SYSTEM_GET_DOOR_STATE(doorEnumHash);
		return retval;
	}

	static void LUA_NATIVE_OBJECT_DOOR_SYSTEM_SET_AUTOMATIC_RATE(Hash doorEnumHash, float fAutomaticRate)
	{
		OBJECT::DOOR_SYSTEM_SET_AUTOMATIC_RATE(doorEnumHash, fAutomaticRate);
	}

	static void LUA_NATIVE_OBJECT_DOOR_SYSTEM_SET_AUTOMATIC_DISTANCE(Hash doorEnumHash, float fAutomaticDistance)
	{
		OBJECT::DOOR_SYSTEM_SET_AUTOMATIC_DISTANCE(doorEnumHash, fAutomaticDistance);
	}

	static void LUA_NATIVE_OBJECT__0xB3B1546D23DF8DE1(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		OBJECT::_0xB3B1546D23DF8DE1(p0, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_OBJECT_DOOR_SYSTEM_SET_OPEN_RATIO(Hash doorEnumHash, float fOpenRatio, bool forceUpdate)
	{
		OBJECT::DOOR_SYSTEM_SET_OPEN_RATIO(doorEnumHash, fOpenRatio, forceUpdate);
	}

	static void LUA_NATIVE_OBJECT__0x3A77DAE8B4FD7586(Any p0, Any p1)
	{
		OBJECT::_0x3A77DAE8B4FD7586(p0, p1);
	}

	static void LUA_NATIVE_OBJECT__DOOR_SYSTEM_SET_ABLE_TO_CHANGE_OPEN_RATIO_WHILE_LOCKED(Hash doorHash, bool p1)
	{
		OBJECT::_DOOR_SYSTEM_SET_ABLE_TO_CHANGE_OPEN_RATIO_WHILE_LOCKED(doorHash, p1);
	}

	static bool LUA_NATIVE_OBJECT__IS_DOOR_REGISTERED_WITH_OWNER(Hash doorHash)
	{
		auto retval = (bool)OBJECT::_IS_DOOR_REGISTERED_WITH_OWNER(doorHash);
		return retval;
	}

	static void LUA_NATIVE_OBJECT__DOOR_SYSTEM_CHANGE_SCRIPT_OWNER(Hash doorHash)
	{
		OBJECT::_DOOR_SYSTEM_CHANGE_SCRIPT_OWNER(doorHash);
	}

	static float LUA_NATIVE_OBJECT__DOOR_SYSTEM_GET_AUTOMATIC_RATE(Hash doorHash)
	{
		auto retval = OBJECT::_DOOR_SYSTEM_GET_AUTOMATIC_RATE(doorHash);
		return retval;
	}

	static Any LUA_NATIVE_OBJECT__0x6E2AA80BB0C03728(Any p0, Any p1)
	{
		auto retval = OBJECT::_0x6E2AA80BB0C03728(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_OBJECT__DOOR_SYSTEM_SET_AUTOMATIC_STATE(Hash doorHash, bool disable)
	{
		OBJECT::_DOOR_SYSTEM_SET_AUTOMATIC_STATE(doorHash, disable);
	}

	static float LUA_NATIVE_OBJECT_DOOR_SYSTEM_GET_OPEN_RATIO(Hash doorEnumHash)
	{
		auto retval = OBJECT::DOOR_SYSTEM_GET_OPEN_RATIO(doorEnumHash);
		return retval;
	}

	static void LUA_NATIVE_OBJECT__0x7F458B543006C8FE(Any p0, Any p1)
	{
		OBJECT::_0x7F458B543006C8FE(p0, p1);
	}

	static Any LUA_NATIVE_OBJECT__0xACD4F9831DFAD7F5(Any p0)
	{
		auto retval = OBJECT::_0xACD4F9831DFAD7F5(p0);
		return retval;
	}

	static void LUA_NATIVE_OBJECT__0x0C0A373D181BF900(Any p0)
	{
		OBJECT::_0x0C0A373D181BF900(p0);
	}

	static void LUA_NATIVE_OBJECT__0xA93F925F1942E434(Any p0, Any p1)
	{
		OBJECT::_0xA93F925F1942E434(p0, p1);
	}

	static Any LUA_NATIVE_OBJECT__0x4D8611DFE1126478(Any p0)
	{
		auto retval = OBJECT::_0x4D8611DFE1126478(p0);
		return retval;
	}

	static void LUA_NATIVE_OBJECT__0x57C242543B7B8FB9(Any p0, Any p1)
	{
		OBJECT::_0x57C242543B7B8FB9(p0, p1);
	}

	static void LUA_NATIVE_OBJECT__0x4AE07EBA3462C5D5(Any p0, Any p1)
	{
		OBJECT::_0x4AE07EBA3462C5D5(p0, p1);
	}

	static void LUA_NATIVE_OBJECT__0x22031584496CFB70(Any p0, Any p1)
	{
		OBJECT::_0x22031584496CFB70(p0, p1);
	}

	static void LUA_NATIVE_OBJECT__0xC07B91B996C1DE89(Any p0, Any p1)
	{
		OBJECT::_0xC07B91B996C1DE89(p0, p1);
	}

	static bool LUA_NATIVE_OBJECT_IS_DOOR_REGISTERED_WITH_SYSTEM(Hash doorEnumHash)
	{
		auto retval = (bool)OBJECT::IS_DOOR_REGISTERED_WITH_SYSTEM(doorEnumHash);
		return retval;
	}

	static bool LUA_NATIVE_OBJECT_IS_DOOR_CLOSED(Hash doorEnumHash)
	{
		auto retval = (bool)OBJECT::IS_DOOR_CLOSED(doorEnumHash);
		return retval;
	}

	static Any LUA_NATIVE_OBJECT__0x0943113E02322164(Object object, int p1)
	{
		auto retval = OBJECT::_0x0943113E02322164(object, p1);
		return retval;
	}

	static Any LUA_NATIVE_OBJECT__0x614D0B4533F842D3(Any p0)
	{
		auto retval = OBJECT::_0x614D0B4533F842D3(p0);
		return retval;
	}

	static void LUA_NATIVE_OBJECT__DOOR_SYSTEM_FORCE_SHUT(Hash doorHash, bool p1)
	{
		OBJECT::_DOOR_SYSTEM_FORCE_SHUT(doorHash, p1);
	}

	static Any LUA_NATIVE_OBJECT__0xEBA314768FB35D58(Any p0)
	{
		auto retval = OBJECT::_0xEBA314768FB35D58(p0);
		return retval;
	}

	static void LUA_NATIVE_OBJECT__0x5230BF34EB0EC645(Any p0)
	{
		OBJECT::_0x5230BF34EB0EC645(p0);
	}

	static bool LUA_NATIVE_OBJECT_DOES_OBJECT_OF_TYPE_EXIST_AT_COORDS(float VecCoorsX, float VecCoorsY, float VecCoorsZ, float Radius, Hash ModelIndex, bool checkPhysicsExists)
	{
		auto retval = (bool)OBJECT::DOES_OBJECT_OF_TYPE_EXIST_AT_COORDS(VecCoorsX, VecCoorsY, VecCoorsZ, Radius, ModelIndex, checkPhysicsExists);
		return retval;
	}

	static bool LUA_NATIVE_OBJECT_IS_POINT_IN_ANGLED_AREA(float VecPointX, float VecPointY, float VecPointZ, float VecCoors1X, float VecCoors1Y, float VecCoors1Z, float VecCoors2X, float VecCoors2Y, float VecCoors2Z, float DistanceP1toP4, bool HighlightArea, bool bCheck3D)
	{
		auto retval = (bool)OBJECT::IS_POINT_IN_ANGLED_AREA(VecPointX, VecPointY, VecPointZ, VecCoors1X, VecCoors1Y, VecCoors1Z, VecCoors2X, VecCoors2Y, VecCoors2Z, DistanceP1toP4, HighlightArea, bCheck3D);
		return retval;
	}

	static void LUA_NATIVE_OBJECT_SET_OBJECT_ALLOW_LOW_LOD_BUOYANCY(Object ObjectID, bool AllowFlag)
	{
		OBJECT::SET_OBJECT_ALLOW_LOW_LOD_BUOYANCY(ObjectID, AllowFlag);
	}

	static void LUA_NATIVE_OBJECT_SET_OBJECT_PHYSICS_PARAMS(Object ObjectIndex, float fMass, float fGravityFactor, float TranslationalDampingX, float TranslationalDampingY, float TranslationalDampingZ, float RotationalDampingX, float RotationalDampingY, float RotationalDampingZ, float fCollisionMargin, float fMaxAngularSpeed, float fBuoyancyFactor)
	{
		OBJECT::SET_OBJECT_PHYSICS_PARAMS(ObjectIndex, fMass, fGravityFactor, TranslationalDampingX, TranslationalDampingY, TranslationalDampingZ, RotationalDampingX, RotationalDampingY, RotationalDampingZ, fCollisionMargin, fMaxAngularSpeed, fBuoyancyFactor);
	}

	static float LUA_NATIVE_OBJECT_GET_OBJECT_FRAGMENT_DAMAGE_HEALTH(Object ObjectIndex, bool HealthPercentageByMass)
	{
		auto retval = OBJECT::GET_OBJECT_FRAGMENT_DAMAGE_HEALTH(ObjectIndex, HealthPercentageByMass);
		return retval;
	}

	static Any LUA_NATIVE_OBJECT__0x235C863DA77BD88D(Any p0, Any p1, Any p2)
	{
		auto retval = OBJECT::_0x235C863DA77BD88D(p0, p1, p2);
		return retval;
	}

	static void LUA_NATIVE_OBJECT_SET_ACTIVATE_OBJECT_PHYSICS_AS_SOON_AS_IT_IS_UNFROZEN(Object ObjectIndex, bool bActivatePhysicsWhenUnfrozen)
	{
		OBJECT::SET_ACTIVATE_OBJECT_PHYSICS_AS_SOON_AS_IT_IS_UNFROZEN(ObjectIndex, bActivatePhysicsWhenUnfrozen);
	}

	static void LUA_NATIVE_OBJECT_BREAK_OBJECT_FRAGMENT_CHILD(Object ObjectIndex, int Component, bool Disappear)
	{
		OBJECT::BREAK_OBJECT_FRAGMENT_CHILD(ObjectIndex, Component, Disappear);
	}

	static void LUA_NATIVE_OBJECT_BREAK_ALL_OBJECT_FRAGMENT_BONES(Object object)
	{
		OBJECT::BREAK_ALL_OBJECT_FRAGMENT_BONES(object);
	}

	static void LUA_NATIVE_OBJECT__0xAAACF33CBF9B990A(Any p0, Any p1)
	{
		OBJECT::_0xAAACF33CBF9B990A(p0, p1);
	}

	static void LUA_NATIVE_OBJECT__DAMAGE_BONE_ON_PROP(Object object, int bone)
	{
		OBJECT::_DAMAGE_BONE_ON_PROP(object, bone);
	}

	static void LUA_NATIVE_OBJECT_FIX_OBJECT_FRAGMENT(Object ObjectIndex)
	{
		OBJECT::FIX_OBJECT_FRAGMENT(ObjectIndex);
	}

	static Any LUA_NATIVE_OBJECT__0x58DE624FA7FB0E7F(Any p0)
	{
		auto retval = OBJECT::_0x58DE624FA7FB0E7F(p0);
		return retval;
	}

	static void LUA_NATIVE_OBJECT__0x491439AEF410A2FC(Any p0)
	{
		OBJECT::_0x491439AEF410A2FC(p0);
	}

	static void LUA_NATIVE_OBJECT__SET_OBJECT_BREAK_SCALE(Object object, float scale)
	{
		OBJECT::_SET_OBJECT_BREAK_SCALE(object, scale);
	}

	static void LUA_NATIVE_OBJECT__0xCEAB54F4632C6EF6(Any p0, Any p1)
	{
		OBJECT::_0xCEAB54F4632C6EF6(p0, p1);
	}

	static void LUA_NATIVE_OBJECT_TRACK_OBJECT_VISIBILITY(Object ObjectID)
	{
		OBJECT::TRACK_OBJECT_VISIBILITY(ObjectID);
	}

	static bool LUA_NATIVE_OBJECT_IS_OBJECT_VISIBLE(Object ObjectID)
	{
		auto retval = (bool)OBJECT::IS_OBJECT_VISIBLE(ObjectID);
		return retval;
	}

	static void LUA_NATIVE_OBJECT_SET_OBJECT_TAKES_DAMAGE_FROM_COLLIDING_WITH_BUILDINGS(Object ObjectIndex, bool bTakesDamage)
	{
		OBJECT::SET_OBJECT_TAKES_DAMAGE_FROM_COLLIDING_WITH_BUILDINGS(ObjectIndex, bTakesDamage);
	}

	static void LUA_NATIVE_OBJECT_ALLOW_DAMAGE_EVENTS_FOR_NON_NETWORKED_OBJECTS(bool enabled)
	{
		OBJECT::ALLOW_DAMAGE_EVENTS_FOR_NON_NETWORKED_OBJECTS(enabled);
	}

	static void LUA_NATIVE_OBJECT__0x6579860A5558524A(Any p0, Any p1)
	{
		OBJECT::_0x6579860A5558524A(p0, p1);
	}

	static void LUA_NATIVE_OBJECT__0xDFA1237F5228263F(Any p0, Any p1)
	{
		OBJECT::_0xDFA1237F5228263F(p0, p1);
	}

	static float LUA_NATIVE_OBJECT__GET_LIGHT_INTENSITY_FROM_OBJECT(Object object)
	{
		auto retval = OBJECT::_GET_LIGHT_INTENSITY_FROM_OBJECT(object);
		return retval;
	}

	static void LUA_NATIVE_OBJECT__SET_LIGHT_INTENSITY_FOR_OBJECT(Object object, float lightIntensity)
	{
		OBJECT::_SET_LIGHT_INTENSITY_FOR_OBJECT(object, lightIntensity);
	}

	static void LUA_NATIVE_OBJECT__SET_LIGHT_TRANSLUCENCY_FOR_OBJECT(Object object, float value)
	{
		OBJECT::_SET_LIGHT_TRANSLUCENCY_FOR_OBJECT(object, value);
	}

	static void LUA_NATIVE_OBJECT__SET_LIGHT_SCATTERING_DISABLED_FOR_OBJECT(Object object, bool disable)
	{
		OBJECT::_SET_LIGHT_SCATTERING_DISABLED_FOR_OBJECT(object, disable);
	}

	static void LUA_NATIVE_OBJECT__0x7FCD49388BC9B775(Any p0, Any p1)
	{
		OBJECT::_0x7FCD49388BC9B775(p0, p1);
	}

	static Any LUA_NATIVE_OBJECT__0xFA99E8E575F2FEF8(Any p0)
	{
		auto retval = OBJECT::_0xFA99E8E575F2FEF8(p0);
		return retval;
	}

	static Object LUA_NATIVE_OBJECT_GET_RAYFIRE_MAP_OBJECT(float PosX, float PosY, float PosZ, float fRadius, sol::stack_object RayfireName)
	{
		auto retval = OBJECT::GET_RAYFIRE_MAP_OBJECT(PosX, PosY, PosZ, fRadius, RayfireName.is<const char*>() ? RayfireName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_OBJECT_SET_STATE_OF_RAYFIRE_MAP_OBJECT(Object RayFireObject, int state)
	{
		OBJECT::SET_STATE_OF_RAYFIRE_MAP_OBJECT(RayFireObject, state);
	}

	static int LUA_NATIVE_OBJECT_GET_STATE_OF_RAYFIRE_MAP_OBJECT(Object RayFireObject)
	{
		auto retval = OBJECT::GET_STATE_OF_RAYFIRE_MAP_OBJECT(RayFireObject);
		return retval;
	}

	static bool LUA_NATIVE_OBJECT_DOES_RAYFIRE_MAP_OBJECT_EXIST(Object RayFireObject)
	{
		auto retval = (bool)OBJECT::DOES_RAYFIRE_MAP_OBJECT_EXIST(RayFireObject);
		return retval;
	}

	static float LUA_NATIVE_OBJECT_GET_RAYFIRE_MAP_OBJECT_ANIM_PHASE(Object RayFireObject)
	{
		auto retval = OBJECT::GET_RAYFIRE_MAP_OBJECT_ANIM_PHASE(RayFireObject);
		return retval;
	}

	static Pickup LUA_NATIVE_OBJECT_CREATE_PICKUP(Hash Type, float VecNewCoorsX, float VecNewCoorsY, float VecNewCoorsZ, int PlacementFlags, int Amount, bool ScriptHostObject, Hash CustomModel, int p8, float p9, Any p10)
	{
		auto retval = OBJECT::CREATE_PICKUP(Type, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ, PlacementFlags, Amount, ScriptHostObject, CustomModel, p8, p9, p10);
		return retval;
	}

	static Pickup LUA_NATIVE_OBJECT_CREATE_PICKUP_ROTATE(Hash Type, float CoorsX, float CoorsY, float CoorsZ, float OrientationX, float OrientationY, float OrientationZ, int PlacementFlags, int Amount, int RotOrder, bool ScriptHostObject, Hash CustomModel, int p12, float p13, Any p14)
	{
		auto retval = OBJECT::CREATE_PICKUP_ROTATE(Type, CoorsX, CoorsY, CoorsZ, OrientationX, OrientationY, OrientationZ, PlacementFlags, Amount, RotOrder, ScriptHostObject, CustomModel, p12, p13, p14);
		return retval;
	}

	static Object LUA_NATIVE_OBJECT_CREATE_AMBIENT_PICKUP(Hash Type, float VecNewCoorsX, float VecNewCoorsY, float VecNewCoorsZ, int PlacementFlags, int Amount, Hash CustomModel, bool bCreateAsScriptObject, bool ScriptHostObject, int p9, float p10)
	{
		auto retval = OBJECT::CREATE_AMBIENT_PICKUP(Type, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ, PlacementFlags, Amount, CustomModel, bCreateAsScriptObject, ScriptHostObject, p9, p10);
		return retval;
	}

	static Object LUA_NATIVE_OBJECT_CREATE_PORTABLE_PICKUP(Hash Type, float VecNewCoorsX, float VecNewCoorsY, float VecNewCoorsZ, bool SnapToGround, Hash CustomModel)
	{
		auto retval = OBJECT::CREATE_PORTABLE_PICKUP(Type, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ, SnapToGround, CustomModel);
		return retval;
	}

	static void LUA_NATIVE_OBJECT_ATTACH_PORTABLE_PICKUP_TO_PED(Object PickupID, Ped PedID)
	{
		OBJECT::ATTACH_PORTABLE_PICKUP_TO_PED(PickupID, PedID);
	}

	static void LUA_NATIVE_OBJECT_DETACH_PORTABLE_PICKUP_FROM_PED(Object PickupID)
	{
		OBJECT::DETACH_PORTABLE_PICKUP_FROM_PED(PickupID);
	}

	static void LUA_NATIVE_OBJECT__HIDE_PICKUP_OBJECT(Object pickupObject, bool toggle)
	{
		OBJECT::_HIDE_PICKUP_OBJECT(pickupObject, toggle);
	}

	static void LUA_NATIVE_OBJECT_SET_MAX_NUM_PORTABLE_PICKUPS_CARRIED_BY_PLAYER(Hash modelName, int MaxPickups)
	{
		OBJECT::SET_MAX_NUM_PORTABLE_PICKUPS_CARRIED_BY_PLAYER(modelName, MaxPickups);
	}

	static Any LUA_NATIVE_OBJECT__0x3E2616E7EA539480(Any p0)
	{
		auto retval = OBJECT::_0x3E2616E7EA539480(p0);
		return retval;
	}

	static void LUA_NATIVE_OBJECT_SET_LOCAL_PLAYER_CAN_COLLECT_PORTABLE_PICKUPS(bool CanCollect)
	{
		OBJECT::SET_LOCAL_PLAYER_CAN_COLLECT_PORTABLE_PICKUPS(CanCollect);
	}

	static Vector3 LUA_NATIVE_OBJECT_GET_SAFE_PICKUP_COORDS(float VecInCoorsX, float VecInCoorsY, float VecInCoorsZ, float minDist, float maxDist, Any p5)
	{
		auto retval = OBJECT::GET_SAFE_PICKUP_COORDS(VecInCoorsX, VecInCoorsY, VecInCoorsZ, minDist, maxDist, p5);
		return retval;
	}

	static Vector3 LUA_NATIVE_OBJECT_GET_PICKUP_COORDS(Pickup PickupID)
	{
		auto retval = OBJECT::GET_PICKUP_COORDS(PickupID);
		return retval;
	}

	static void LUA_NATIVE_OBJECT_REMOVE_ALL_PICKUPS_OF_TYPE(Hash Type)
	{
		OBJECT::REMOVE_ALL_PICKUPS_OF_TYPE(Type);
	}

	static bool LUA_NATIVE_OBJECT_HAS_PICKUP_BEEN_COLLECTED(Pickup PickupID)
	{
		auto retval = (bool)OBJECT::HAS_PICKUP_BEEN_COLLECTED(PickupID);
		return retval;
	}

	static void LUA_NATIVE_OBJECT_REMOVE_PICKUP(Pickup PickupID)
	{
		OBJECT::REMOVE_PICKUP(PickupID);
	}

	static void LUA_NATIVE_OBJECT_SET_PICKUP_DO_NOT_AUTO_PLACE_ON_GROUND(Object pickupObject)
	{
		OBJECT::SET_PICKUP_DO_NOT_AUTO_PLACE_ON_GROUND(pickupObject);
	}

	static bool LUA_NATIVE_OBJECT_DOES_PICKUP_EXIST(Pickup PickupID)
	{
		auto retval = (bool)OBJECT::DOES_PICKUP_EXIST(PickupID);
		return retval;
	}

	static bool LUA_NATIVE_OBJECT_DOES_PICKUP_OBJECT_EXIST(Pickup PickupID)
	{
		auto retval = (bool)OBJECT::DOES_PICKUP_OBJECT_EXIST(PickupID);
		return retval;
	}

	static Object LUA_NATIVE_OBJECT_GET_PICKUP_OBJECT(Pickup PickupID)
	{
		auto retval = OBJECT::GET_PICKUP_OBJECT(PickupID);
		return retval;
	}

	static bool LUA_NATIVE_OBJECT_IS_OBJECT_A_PORTABLE_PICKUP(Object ObjectID)
	{
		auto retval = (bool)OBJECT::IS_OBJECT_A_PORTABLE_PICKUP(ObjectID);
		return retval;
	}

	static bool LUA_NATIVE_OBJECT__IS_PICKUP_TYPE_VALID(Hash pickupHash)
	{
		auto retval = (bool)OBJECT::_IS_PICKUP_TYPE_VALID(pickupHash);
		return retval;
	}

	static bool LUA_NATIVE_OBJECT_DOES_PICKUP_OF_TYPE_EXIST_IN_AREA(Hash PickupType, float VecCoordsX, float VecCoordsY, float VecCoordsZ, float Radius)
	{
		auto retval = (bool)OBJECT::DOES_PICKUP_OF_TYPE_EXIST_IN_AREA(PickupType, VecCoordsX, VecCoordsY, VecCoordsZ, Radius);
		return retval;
	}

	static void LUA_NATIVE_OBJECT_SET_PICKUP_REGENERATION_TIME(Pickup PickupID, int RegenTime)
	{
		OBJECT::SET_PICKUP_REGENERATION_TIME(PickupID, RegenTime);
	}

	static void LUA_NATIVE_OBJECT_FORCE_PICKUP_REGENERATE(Pickup PickupID)
	{
		OBJECT::FORCE_PICKUP_REGENERATE(PickupID);
	}

	static void LUA_NATIVE_OBJECT__SET_NETWORK_PICKUP_USABLE_FOR_PLAYER(Player player, Hash pickupHash, bool isUsable)
	{
		OBJECT::_SET_NETWORK_PICKUP_USABLE_FOR_PLAYER(player, pickupHash, isUsable);
	}

	static void LUA_NATIVE_OBJECT_SET_LOCAL_PLAYER_PERMITTED_TO_COLLECT_PICKUPS_WITH_MODEL(Hash CustomModel, bool Allow)
	{
		OBJECT::SET_LOCAL_PLAYER_PERMITTED_TO_COLLECT_PICKUPS_WITH_MODEL(CustomModel, Allow);
	}

	static void LUA_NATIVE_OBJECT_BLOCK_PICKUP_FROM_PLAYER_COLLECTION(Any p0, Any p1)
	{
		OBJECT::BLOCK_PICKUP_FROM_PLAYER_COLLECTION(p0, p1);
	}

	static void LUA_NATIVE_OBJECT_SET_PICKUP_NOT_LOOTABLE(Any p0, Any p1)
	{
		OBJECT::SET_PICKUP_NOT_LOOTABLE(p0, p1);
	}

	static void LUA_NATIVE_OBJECT__0x1F5E07E14A86FAFC(bool p0)
	{
		OBJECT::_0x1F5E07E14A86FAFC(p0);
	}

	static void LUA_NATIVE_OBJECT_SET_TEAM_PICKUP_OBJECT(Object PickupID, int Team, bool bSet)
	{
		OBJECT::SET_TEAM_PICKUP_OBJECT(PickupID, Team, bSet);
	}

	static Any LUA_NATIVE_OBJECT__0x9F52AD67D1A91BAD(Any p0, Any p1)
	{
		auto retval = OBJECT::_0x9F52AD67D1A91BAD(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_OBJECT_PREVENT_COLLECTION_OF_PORTABLE_PICKUP(Object PickupID, bool bPrevent, bool bLocalOnly)
	{
		OBJECT::PREVENT_COLLECTION_OF_PORTABLE_PICKUP(PickupID, bPrevent, bLocalOnly);
	}

	static void LUA_NATIVE_OBJECT_SET_PICKUP_GENERATION_RANGE_MULTIPLIER(float multiplier)
	{
		OBJECT::SET_PICKUP_GENERATION_RANGE_MULTIPLIER(multiplier);
	}

	static void LUA_NATIVE_OBJECT_SET_PICKUP_UNCOLLECTABLE(Pickup PickupID, bool bSet)
	{
		OBJECT::SET_PICKUP_UNCOLLECTABLE(PickupID, bSet);
	}

	static void LUA_NATIVE_OBJECT_SET_PICKUP_HIDDEN_WHEN_UNCOLLECTABLE(Pickup PickupID, bool bSet)
	{
		OBJECT::SET_PICKUP_HIDDEN_WHEN_UNCOLLECTABLE(PickupID, bSet);
	}

	static void LUA_NATIVE_OBJECT__SET_AMBIENT_PICKUP_LIFETIME(int lifetime)
	{
		OBJECT::_SET_AMBIENT_PICKUP_LIFETIME(lifetime);
	}

	static void LUA_NATIVE_OBJECT_SET_PICKUP_PARTICLE_FX_SPAWN(Any p0, Any p1)
	{
		OBJECT::SET_PICKUP_PARTICLE_FX_SPAWN(p0, p1);
	}

	static void LUA_NATIVE_OBJECT_SET_PICKUP_PARTICLE_FX_HIGHLIGHT(Any p0, Any p1)
	{
		OBJECT::SET_PICKUP_PARTICLE_FX_HIGHLIGHT(p0, p1);
	}

	static void LUA_NATIVE_OBJECT_SUPPRESS_PICKUP_REWARD_TYPE(int pickupFlag, bool bClearPreviousFlags)
	{
		OBJECT::SUPPRESS_PICKUP_REWARD_TYPE(pickupFlag, bClearPreviousFlags);
	}

	static Any LUA_NATIVE_OBJECT__0x20135AF9C10D2A3D(Any p0)
	{
		auto retval = OBJECT::_0x20135AF9C10D2A3D(p0);
		return retval;
	}

	static void LUA_NATIVE_OBJECT__SET_PICKUP_COLLECTABLE_ON_MOUNT(Object object)
	{
		OBJECT::_SET_PICKUP_COLLECTABLE_ON_MOUNT(object);
	}

	static void LUA_NATIVE_OBJECT__0xDE116ECFFDD4B997(Any p0, Any p1)
	{
		OBJECT::_0xDE116ECFFDD4B997(p0, p1);
	}

	static Hash LUA_NATIVE_OBJECT_GET_WEAPON_TYPE_FROM_PICKUP_TYPE(Hash ePickupType)
	{
		auto retval = OBJECT::GET_WEAPON_TYPE_FROM_PICKUP_TYPE(ePickupType);
		return retval;
	}

	static Hash LUA_NATIVE_OBJECT__GET_AMMO_TYPE_FROM_PICKUP_TYPE(Hash pickupHash)
	{
		auto retval = OBJECT::_GET_AMMO_TYPE_FROM_PICKUP_TYPE(pickupHash);
		return retval;
	}

	static void LUA_NATIVE_OBJECT_SET_OBJECT_TINT_INDEX(Object ObjectIndex, int TintIndex)
	{
		OBJECT::SET_OBJECT_TINT_INDEX(ObjectIndex, TintIndex);
	}

	static float LUA_NATIVE_OBJECT__GET_OBJECT_LIGHT_INTENSITY(Object object)
	{
		auto retval = OBJECT::_GET_OBJECT_LIGHT_INTENSITY(object);
		return retval;
	}

	static void LUA_NATIVE_OBJECT__SET_OBJECT_BURN_OPACITY(Object object, float opacity)
	{
		OBJECT::_SET_OBJECT_BURN_OPACITY(object, opacity);
	}

	static void LUA_NATIVE_OBJECT__SET_OBJECT_BURN_INTENSITY(Object object, float intensity)
	{
		OBJECT::_SET_OBJECT_BURN_INTENSITY(object, intensity);
	}

	static void LUA_NATIVE_OBJECT__SET_OBJECT_BURN_LEVEL(Object object, float burnLevel, bool affectAsh)
	{
		OBJECT::_SET_OBJECT_BURN_LEVEL(object, burnLevel, affectAsh);
	}

	static void LUA_NATIVE_OBJECT__0x9A74A9CADFA8A598(Any p0)
	{
		OBJECT::_0x9A74A9CADFA8A598(p0);
	}

	static void LUA_NATIVE_OBJECT__RESET_OBJECT_VELOCITY(Object object)
	{
		OBJECT::_RESET_OBJECT_VELOCITY(object);
	}

	static void LUA_NATIVE_OBJECT__SET_OBJECT_BURN_SPEED(Object object, float speed, float p2)
	{
		OBJECT::_SET_OBJECT_BURN_SPEED(object, speed, p2);
	}

	static void LUA_NATIVE_OBJECT__0xCBFBD38F2E0A263B(Any p0, Any p1)
	{
		OBJECT::_0xCBFBD38F2E0A263B(p0, p1);
	}

	static Hash LUA_NATIVE_OBJECT_CONVERT_OLD_PICKUP_TYPE_TO_NEW(Hash OldPickupType)
	{
		auto retval = OBJECT::CONVERT_OLD_PICKUP_TYPE_TO_NEW(OldPickupType);
		return retval;
	}

	static void LUA_NATIVE_OBJECT_SET_FORCE_OBJECT_THIS_FRAME(float posX, float posY, float posZ, float radius)
	{
		OBJECT::SET_FORCE_OBJECT_THIS_FRAME(posX, posY, posZ, radius);
	}

	static Any LUA_NATIVE_OBJECT__0xD91E55B6C005EB09(Any p0, Any p1)
	{
		auto retval = OBJECT::_0xD91E55B6C005EB09(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_OBJECT_ONLY_CLEAN_UP_OBJECT_WHEN_OUT_OF_RANGE(Object ObjectIndex)
	{
		OBJECT::ONLY_CLEAN_UP_OBJECT_WHEN_OUT_OF_RANGE(ObjectIndex);
	}

	static void LUA_NATIVE_OBJECT__0xCAAF2BCCFEF37F77(Object object, Any p1)
	{
		OBJECT::_0xCAAF2BCCFEF37F77(object, p1);
	}

	static Any LUA_NATIVE_OBJECT__0x08C5825A2932EA7B(Any p0)
	{
		auto retval = OBJECT::_0x08C5825A2932EA7B(p0);
		return retval;
	}

	static Any LUA_NATIVE_OBJECT__0x7D4411D6736CD295(Any p0, Any p1)
	{
		auto retval = OBJECT::_0x7D4411D6736CD295(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_OBJECT__0x250EBB11E81A10BE(Any p0)
	{
		auto retval = OBJECT::_0x250EBB11E81A10BE(p0);
		return retval;
	}

	static Any LUA_NATIVE_OBJECT__0x2BF1953C0C21AC88(Any p0)
	{
		auto retval = OBJECT::_0x2BF1953C0C21AC88(p0);
		return retval;
	}

	static bool LUA_NATIVE_OBJECT_CREATE_OBJECT_SKELETON(Object object)
	{
		auto retval = (bool)OBJECT::CREATE_OBJECT_SKELETON(object);
		return retval;
	}

	static void LUA_NATIVE_OBJECT__MAKE_ITEM_CARRIABLE(Object object)
	{
		OBJECT::_MAKE_ITEM_CARRIABLE(object);
	}

	static void LUA_NATIVE_OBJECT__0xF65EDE5D02A7A760(Any p0, Any p1)
	{
		OBJECT::_0xF65EDE5D02A7A760(p0, p1);
	}

	static void LUA_NATIVE_OBJECT__SET_AUTO_JUMPABLE_BY_HORSE(Object object, bool p1)
	{
		OBJECT::_SET_AUTO_JUMPABLE_BY_HORSE(object, p1);
	}

	static void LUA_NATIVE_OBJECT__SET_NOT_JUMPABLE_BY_HORSE(Object object, bool p1)
	{
		OBJECT::_SET_NOT_JUMPABLE_BY_HORSE(object, p1);
	}

	static void LUA_NATIVE_OBJECT__SET_OBJECT_KICKABLE(Object object, bool kickable)
	{
		OBJECT::_SET_OBJECT_KICKABLE(object, kickable);
	}

	static void LUA_NATIVE_OBJECT_SET_CUSTOM_TEXTURES_ON_OBJECT(Object object, Hash txdHash, Any p2, Any p3)
	{
		OBJECT::SET_CUSTOM_TEXTURES_ON_OBJECT(object, txdHash, p2, p3);
	}

	static void LUA_NATIVE_OBJECT__0xD503D6F0986D58BC(Any p0, Any p1)
	{
		OBJECT::_0xD503D6F0986D58BC(p0, p1);
	}

	static void LUA_NATIVE_OBJECT__0xAEE6C800E124CFE1(Any p0, Any p1)
	{
		OBJECT::_0xAEE6C800E124CFE1(p0, p1);
	}

	static void LUA_NATIVE_OBJECT__0x3DF1A0A58498E209(Object object, Any p1)
	{
		OBJECT::_0x3DF1A0A58498E209(object, p1);
	}

	void RegisterNatives_OBJECT(sol::state& L)
	{
		auto OBJECT = L["OBJECT"].get_or_create<sol::table>();
		OBJECT.set_function("CREATE_OBJECT", LUA_NATIVE_OBJECT_CREATE_OBJECT);
		OBJECT.set_function("CREATE_OBJECT_NO_OFFSET", LUA_NATIVE_OBJECT_CREATE_OBJECT_NO_OFFSET);
		OBJECT.set_function("DELETE_OBJECT", LUA_NATIVE_OBJECT_DELETE_OBJECT);
		OBJECT.set_function("PLACE_OBJECT_ON_GROUND_PROPERLY", LUA_NATIVE_OBJECT_PLACE_OBJECT_ON_GROUND_PROPERLY);
		OBJECT.set_function("SLIDE_OBJECT", LUA_NATIVE_OBJECT_SLIDE_OBJECT);
		OBJECT.set_function("SET_OBJECT_TARGETTABLE", LUA_NATIVE_OBJECT_SET_OBJECT_TARGETTABLE);
		OBJECT.set_function("_SET_OBJECT_TARGETTABLE_2", LUA_NATIVE_OBJECT__SET_OBJECT_TARGETTABLE_2);
		OBJECT.set_function("_SET_OBJECT_TARGETTABLE_FOCUS", LUA_NATIVE_OBJECT__SET_OBJECT_TARGETTABLE_FOCUS);
		OBJECT.set_function("_0xF6E88489B4E6EBE5", LUA_NATIVE_OBJECT__0xF6E88489B4E6EBE5);
		OBJECT.set_function("_0xE157A8A336C7F04A", LUA_NATIVE_OBJECT__0xE157A8A336C7F04A);
		OBJECT.set_function("_0x46CBCF0E98A4E156", LUA_NATIVE_OBJECT__0x46CBCF0E98A4E156);
		OBJECT.set_function("GET_CLOSEST_OBJECT_OF_TYPE", LUA_NATIVE_OBJECT_GET_CLOSEST_OBJECT_OF_TYPE);
		OBJECT.set_function("HAS_OBJECT_BEEN_BROKEN", LUA_NATIVE_OBJECT_HAS_OBJECT_BEEN_BROKEN);
		OBJECT.set_function("HAS_CLOSEST_OBJECT_OF_TYPE_BEEN_BROKEN", LUA_NATIVE_OBJECT_HAS_CLOSEST_OBJECT_OF_TYPE_BEEN_BROKEN);
		OBJECT.set_function("GET_OFFSET_FROM_COORD_AND_HEADING_IN_WORLD_COORDS", LUA_NATIVE_OBJECT_GET_OFFSET_FROM_COORD_AND_HEADING_IN_WORLD_COORDS);
		OBJECT.set_function("_ADD_DOOR_TO_SYSTEM_NEW", LUA_NATIVE_OBJECT__ADD_DOOR_TO_SYSTEM_NEW);
		OBJECT.set_function("_IS_DOOR_REGISTERED_WITH_NETWORK", LUA_NATIVE_OBJECT__IS_DOOR_REGISTERED_WITH_NETWORK);
		OBJECT.set_function("REMOVE_DOOR_FROM_SYSTEM", LUA_NATIVE_OBJECT_REMOVE_DOOR_FROM_SYSTEM);
		OBJECT.set_function("DOOR_SYSTEM_SET_DOOR_STATE", LUA_NATIVE_OBJECT_DOOR_SYSTEM_SET_DOOR_STATE);
		OBJECT.set_function("DOOR_SYSTEM_GET_DOOR_STATE", LUA_NATIVE_OBJECT_DOOR_SYSTEM_GET_DOOR_STATE);
		OBJECT.set_function("DOOR_SYSTEM_SET_AUTOMATIC_RATE", LUA_NATIVE_OBJECT_DOOR_SYSTEM_SET_AUTOMATIC_RATE);
		OBJECT.set_function("DOOR_SYSTEM_SET_AUTOMATIC_DISTANCE", LUA_NATIVE_OBJECT_DOOR_SYSTEM_SET_AUTOMATIC_DISTANCE);
		OBJECT.set_function("_0xB3B1546D23DF8DE1", LUA_NATIVE_OBJECT__0xB3B1546D23DF8DE1);
		OBJECT.set_function("DOOR_SYSTEM_SET_OPEN_RATIO", LUA_NATIVE_OBJECT_DOOR_SYSTEM_SET_OPEN_RATIO);
		OBJECT.set_function("_0x3A77DAE8B4FD7586", LUA_NATIVE_OBJECT__0x3A77DAE8B4FD7586);
		OBJECT.set_function("_DOOR_SYSTEM_SET_ABLE_TO_CHANGE_OPEN_RATIO_WHILE_LOCKED", LUA_NATIVE_OBJECT__DOOR_SYSTEM_SET_ABLE_TO_CHANGE_OPEN_RATIO_WHILE_LOCKED);
		OBJECT.set_function("_IS_DOOR_REGISTERED_WITH_OWNER", LUA_NATIVE_OBJECT__IS_DOOR_REGISTERED_WITH_OWNER);
		OBJECT.set_function("_DOOR_SYSTEM_CHANGE_SCRIPT_OWNER", LUA_NATIVE_OBJECT__DOOR_SYSTEM_CHANGE_SCRIPT_OWNER);
		OBJECT.set_function("_DOOR_SYSTEM_GET_AUTOMATIC_RATE", LUA_NATIVE_OBJECT__DOOR_SYSTEM_GET_AUTOMATIC_RATE);
		OBJECT.set_function("_0x6E2AA80BB0C03728", LUA_NATIVE_OBJECT__0x6E2AA80BB0C03728);
		OBJECT.set_function("_DOOR_SYSTEM_SET_AUTOMATIC_STATE", LUA_NATIVE_OBJECT__DOOR_SYSTEM_SET_AUTOMATIC_STATE);
		OBJECT.set_function("DOOR_SYSTEM_GET_OPEN_RATIO", LUA_NATIVE_OBJECT_DOOR_SYSTEM_GET_OPEN_RATIO);
		OBJECT.set_function("_0x7F458B543006C8FE", LUA_NATIVE_OBJECT__0x7F458B543006C8FE);
		OBJECT.set_function("_0xACD4F9831DFAD7F5", LUA_NATIVE_OBJECT__0xACD4F9831DFAD7F5);
		OBJECT.set_function("_0x0C0A373D181BF900", LUA_NATIVE_OBJECT__0x0C0A373D181BF900);
		OBJECT.set_function("_0xA93F925F1942E434", LUA_NATIVE_OBJECT__0xA93F925F1942E434);
		OBJECT.set_function("_0x4D8611DFE1126478", LUA_NATIVE_OBJECT__0x4D8611DFE1126478);
		OBJECT.set_function("_0x57C242543B7B8FB9", LUA_NATIVE_OBJECT__0x57C242543B7B8FB9);
		OBJECT.set_function("_0x4AE07EBA3462C5D5", LUA_NATIVE_OBJECT__0x4AE07EBA3462C5D5);
		OBJECT.set_function("_0x22031584496CFB70", LUA_NATIVE_OBJECT__0x22031584496CFB70);
		OBJECT.set_function("_0xC07B91B996C1DE89", LUA_NATIVE_OBJECT__0xC07B91B996C1DE89);
		OBJECT.set_function("IS_DOOR_REGISTERED_WITH_SYSTEM", LUA_NATIVE_OBJECT_IS_DOOR_REGISTERED_WITH_SYSTEM);
		OBJECT.set_function("IS_DOOR_CLOSED", LUA_NATIVE_OBJECT_IS_DOOR_CLOSED);
		OBJECT.set_function("_0x0943113E02322164", LUA_NATIVE_OBJECT__0x0943113E02322164);
		OBJECT.set_function("_0x614D0B4533F842D3", LUA_NATIVE_OBJECT__0x614D0B4533F842D3);
		OBJECT.set_function("_DOOR_SYSTEM_FORCE_SHUT", LUA_NATIVE_OBJECT__DOOR_SYSTEM_FORCE_SHUT);
		OBJECT.set_function("_0xEBA314768FB35D58", LUA_NATIVE_OBJECT__0xEBA314768FB35D58);
		OBJECT.set_function("_0x5230BF34EB0EC645", LUA_NATIVE_OBJECT__0x5230BF34EB0EC645);
		OBJECT.set_function("DOES_OBJECT_OF_TYPE_EXIST_AT_COORDS", LUA_NATIVE_OBJECT_DOES_OBJECT_OF_TYPE_EXIST_AT_COORDS);
		OBJECT.set_function("IS_POINT_IN_ANGLED_AREA", LUA_NATIVE_OBJECT_IS_POINT_IN_ANGLED_AREA);
		OBJECT.set_function("SET_OBJECT_ALLOW_LOW_LOD_BUOYANCY", LUA_NATIVE_OBJECT_SET_OBJECT_ALLOW_LOW_LOD_BUOYANCY);
		OBJECT.set_function("SET_OBJECT_PHYSICS_PARAMS", LUA_NATIVE_OBJECT_SET_OBJECT_PHYSICS_PARAMS);
		OBJECT.set_function("GET_OBJECT_FRAGMENT_DAMAGE_HEALTH", LUA_NATIVE_OBJECT_GET_OBJECT_FRAGMENT_DAMAGE_HEALTH);
		OBJECT.set_function("_0x235C863DA77BD88D", LUA_NATIVE_OBJECT__0x235C863DA77BD88D);
		OBJECT.set_function("SET_ACTIVATE_OBJECT_PHYSICS_AS_SOON_AS_IT_IS_UNFROZEN", LUA_NATIVE_OBJECT_SET_ACTIVATE_OBJECT_PHYSICS_AS_SOON_AS_IT_IS_UNFROZEN);
		OBJECT.set_function("BREAK_OBJECT_FRAGMENT_CHILD", LUA_NATIVE_OBJECT_BREAK_OBJECT_FRAGMENT_CHILD);
		OBJECT.set_function("BREAK_ALL_OBJECT_FRAGMENT_BONES", LUA_NATIVE_OBJECT_BREAK_ALL_OBJECT_FRAGMENT_BONES);
		OBJECT.set_function("_0xAAACF33CBF9B990A", LUA_NATIVE_OBJECT__0xAAACF33CBF9B990A);
		OBJECT.set_function("_DAMAGE_BONE_ON_PROP", LUA_NATIVE_OBJECT__DAMAGE_BONE_ON_PROP);
		OBJECT.set_function("FIX_OBJECT_FRAGMENT", LUA_NATIVE_OBJECT_FIX_OBJECT_FRAGMENT);
		OBJECT.set_function("_0x58DE624FA7FB0E7F", LUA_NATIVE_OBJECT__0x58DE624FA7FB0E7F);
		OBJECT.set_function("_0x491439AEF410A2FC", LUA_NATIVE_OBJECT__0x491439AEF410A2FC);
		OBJECT.set_function("_SET_OBJECT_BREAK_SCALE", LUA_NATIVE_OBJECT__SET_OBJECT_BREAK_SCALE);
		OBJECT.set_function("_0xCEAB54F4632C6EF6", LUA_NATIVE_OBJECT__0xCEAB54F4632C6EF6);
		OBJECT.set_function("TRACK_OBJECT_VISIBILITY", LUA_NATIVE_OBJECT_TRACK_OBJECT_VISIBILITY);
		OBJECT.set_function("IS_OBJECT_VISIBLE", LUA_NATIVE_OBJECT_IS_OBJECT_VISIBLE);
		OBJECT.set_function("SET_OBJECT_TAKES_DAMAGE_FROM_COLLIDING_WITH_BUILDINGS", LUA_NATIVE_OBJECT_SET_OBJECT_TAKES_DAMAGE_FROM_COLLIDING_WITH_BUILDINGS);
		OBJECT.set_function("ALLOW_DAMAGE_EVENTS_FOR_NON_NETWORKED_OBJECTS", LUA_NATIVE_OBJECT_ALLOW_DAMAGE_EVENTS_FOR_NON_NETWORKED_OBJECTS);
		OBJECT.set_function("_0x6579860A5558524A", LUA_NATIVE_OBJECT__0x6579860A5558524A);
		OBJECT.set_function("_0xDFA1237F5228263F", LUA_NATIVE_OBJECT__0xDFA1237F5228263F);
		OBJECT.set_function("_GET_LIGHT_INTENSITY_FROM_OBJECT", LUA_NATIVE_OBJECT__GET_LIGHT_INTENSITY_FROM_OBJECT);
		OBJECT.set_function("_SET_LIGHT_INTENSITY_FOR_OBJECT", LUA_NATIVE_OBJECT__SET_LIGHT_INTENSITY_FOR_OBJECT);
		OBJECT.set_function("_SET_LIGHT_TRANSLUCENCY_FOR_OBJECT", LUA_NATIVE_OBJECT__SET_LIGHT_TRANSLUCENCY_FOR_OBJECT);
		OBJECT.set_function("_SET_LIGHT_SCATTERING_DISABLED_FOR_OBJECT", LUA_NATIVE_OBJECT__SET_LIGHT_SCATTERING_DISABLED_FOR_OBJECT);
		OBJECT.set_function("_0x7FCD49388BC9B775", LUA_NATIVE_OBJECT__0x7FCD49388BC9B775);
		OBJECT.set_function("_0xFA99E8E575F2FEF8", LUA_NATIVE_OBJECT__0xFA99E8E575F2FEF8);
		OBJECT.set_function("GET_RAYFIRE_MAP_OBJECT", LUA_NATIVE_OBJECT_GET_RAYFIRE_MAP_OBJECT);
		OBJECT.set_function("SET_STATE_OF_RAYFIRE_MAP_OBJECT", LUA_NATIVE_OBJECT_SET_STATE_OF_RAYFIRE_MAP_OBJECT);
		OBJECT.set_function("GET_STATE_OF_RAYFIRE_MAP_OBJECT", LUA_NATIVE_OBJECT_GET_STATE_OF_RAYFIRE_MAP_OBJECT);
		OBJECT.set_function("DOES_RAYFIRE_MAP_OBJECT_EXIST", LUA_NATIVE_OBJECT_DOES_RAYFIRE_MAP_OBJECT_EXIST);
		OBJECT.set_function("GET_RAYFIRE_MAP_OBJECT_ANIM_PHASE", LUA_NATIVE_OBJECT_GET_RAYFIRE_MAP_OBJECT_ANIM_PHASE);
		OBJECT.set_function("CREATE_PICKUP", LUA_NATIVE_OBJECT_CREATE_PICKUP);
		OBJECT.set_function("CREATE_PICKUP_ROTATE", LUA_NATIVE_OBJECT_CREATE_PICKUP_ROTATE);
		OBJECT.set_function("CREATE_AMBIENT_PICKUP", LUA_NATIVE_OBJECT_CREATE_AMBIENT_PICKUP);
		OBJECT.set_function("CREATE_PORTABLE_PICKUP", LUA_NATIVE_OBJECT_CREATE_PORTABLE_PICKUP);
		OBJECT.set_function("ATTACH_PORTABLE_PICKUP_TO_PED", LUA_NATIVE_OBJECT_ATTACH_PORTABLE_PICKUP_TO_PED);
		OBJECT.set_function("DETACH_PORTABLE_PICKUP_FROM_PED", LUA_NATIVE_OBJECT_DETACH_PORTABLE_PICKUP_FROM_PED);
		OBJECT.set_function("_HIDE_PICKUP_OBJECT", LUA_NATIVE_OBJECT__HIDE_PICKUP_OBJECT);
		OBJECT.set_function("SET_MAX_NUM_PORTABLE_PICKUPS_CARRIED_BY_PLAYER", LUA_NATIVE_OBJECT_SET_MAX_NUM_PORTABLE_PICKUPS_CARRIED_BY_PLAYER);
		OBJECT.set_function("_0x3E2616E7EA539480", LUA_NATIVE_OBJECT__0x3E2616E7EA539480);
		OBJECT.set_function("SET_LOCAL_PLAYER_CAN_COLLECT_PORTABLE_PICKUPS", LUA_NATIVE_OBJECT_SET_LOCAL_PLAYER_CAN_COLLECT_PORTABLE_PICKUPS);
		OBJECT.set_function("GET_SAFE_PICKUP_COORDS", LUA_NATIVE_OBJECT_GET_SAFE_PICKUP_COORDS);
		OBJECT.set_function("GET_PICKUP_COORDS", LUA_NATIVE_OBJECT_GET_PICKUP_COORDS);
		OBJECT.set_function("REMOVE_ALL_PICKUPS_OF_TYPE", LUA_NATIVE_OBJECT_REMOVE_ALL_PICKUPS_OF_TYPE);
		OBJECT.set_function("HAS_PICKUP_BEEN_COLLECTED", LUA_NATIVE_OBJECT_HAS_PICKUP_BEEN_COLLECTED);
		OBJECT.set_function("REMOVE_PICKUP", LUA_NATIVE_OBJECT_REMOVE_PICKUP);
		OBJECT.set_function("SET_PICKUP_DO_NOT_AUTO_PLACE_ON_GROUND", LUA_NATIVE_OBJECT_SET_PICKUP_DO_NOT_AUTO_PLACE_ON_GROUND);
		OBJECT.set_function("DOES_PICKUP_EXIST", LUA_NATIVE_OBJECT_DOES_PICKUP_EXIST);
		OBJECT.set_function("DOES_PICKUP_OBJECT_EXIST", LUA_NATIVE_OBJECT_DOES_PICKUP_OBJECT_EXIST);
		OBJECT.set_function("GET_PICKUP_OBJECT", LUA_NATIVE_OBJECT_GET_PICKUP_OBJECT);
		OBJECT.set_function("IS_OBJECT_A_PORTABLE_PICKUP", LUA_NATIVE_OBJECT_IS_OBJECT_A_PORTABLE_PICKUP);
		OBJECT.set_function("_IS_PICKUP_TYPE_VALID", LUA_NATIVE_OBJECT__IS_PICKUP_TYPE_VALID);
		OBJECT.set_function("DOES_PICKUP_OF_TYPE_EXIST_IN_AREA", LUA_NATIVE_OBJECT_DOES_PICKUP_OF_TYPE_EXIST_IN_AREA);
		OBJECT.set_function("SET_PICKUP_REGENERATION_TIME", LUA_NATIVE_OBJECT_SET_PICKUP_REGENERATION_TIME);
		OBJECT.set_function("FORCE_PICKUP_REGENERATE", LUA_NATIVE_OBJECT_FORCE_PICKUP_REGENERATE);
		OBJECT.set_function("_SET_NETWORK_PICKUP_USABLE_FOR_PLAYER", LUA_NATIVE_OBJECT__SET_NETWORK_PICKUP_USABLE_FOR_PLAYER);
		OBJECT.set_function("SET_LOCAL_PLAYER_PERMITTED_TO_COLLECT_PICKUPS_WITH_MODEL", LUA_NATIVE_OBJECT_SET_LOCAL_PLAYER_PERMITTED_TO_COLLECT_PICKUPS_WITH_MODEL);
		OBJECT.set_function("BLOCK_PICKUP_FROM_PLAYER_COLLECTION", LUA_NATIVE_OBJECT_BLOCK_PICKUP_FROM_PLAYER_COLLECTION);
		OBJECT.set_function("SET_PICKUP_NOT_LOOTABLE", LUA_NATIVE_OBJECT_SET_PICKUP_NOT_LOOTABLE);
		OBJECT.set_function("_0x1F5E07E14A86FAFC", LUA_NATIVE_OBJECT__0x1F5E07E14A86FAFC);
		OBJECT.set_function("SET_TEAM_PICKUP_OBJECT", LUA_NATIVE_OBJECT_SET_TEAM_PICKUP_OBJECT);
		OBJECT.set_function("_0x9F52AD67D1A91BAD", LUA_NATIVE_OBJECT__0x9F52AD67D1A91BAD);
		OBJECT.set_function("PREVENT_COLLECTION_OF_PORTABLE_PICKUP", LUA_NATIVE_OBJECT_PREVENT_COLLECTION_OF_PORTABLE_PICKUP);
		OBJECT.set_function("SET_PICKUP_GENERATION_RANGE_MULTIPLIER", LUA_NATIVE_OBJECT_SET_PICKUP_GENERATION_RANGE_MULTIPLIER);
		OBJECT.set_function("SET_PICKUP_UNCOLLECTABLE", LUA_NATIVE_OBJECT_SET_PICKUP_UNCOLLECTABLE);
		OBJECT.set_function("SET_PICKUP_HIDDEN_WHEN_UNCOLLECTABLE", LUA_NATIVE_OBJECT_SET_PICKUP_HIDDEN_WHEN_UNCOLLECTABLE);
		OBJECT.set_function("_SET_AMBIENT_PICKUP_LIFETIME", LUA_NATIVE_OBJECT__SET_AMBIENT_PICKUP_LIFETIME);
		OBJECT.set_function("SET_PICKUP_PARTICLE_FX_SPAWN", LUA_NATIVE_OBJECT_SET_PICKUP_PARTICLE_FX_SPAWN);
		OBJECT.set_function("SET_PICKUP_PARTICLE_FX_HIGHLIGHT", LUA_NATIVE_OBJECT_SET_PICKUP_PARTICLE_FX_HIGHLIGHT);
		OBJECT.set_function("SUPPRESS_PICKUP_REWARD_TYPE", LUA_NATIVE_OBJECT_SUPPRESS_PICKUP_REWARD_TYPE);
		OBJECT.set_function("_0x20135AF9C10D2A3D", LUA_NATIVE_OBJECT__0x20135AF9C10D2A3D);
		OBJECT.set_function("_SET_PICKUP_COLLECTABLE_ON_MOUNT", LUA_NATIVE_OBJECT__SET_PICKUP_COLLECTABLE_ON_MOUNT);
		OBJECT.set_function("_0xDE116ECFFDD4B997", LUA_NATIVE_OBJECT__0xDE116ECFFDD4B997);
		OBJECT.set_function("GET_WEAPON_TYPE_FROM_PICKUP_TYPE", LUA_NATIVE_OBJECT_GET_WEAPON_TYPE_FROM_PICKUP_TYPE);
		OBJECT.set_function("_GET_AMMO_TYPE_FROM_PICKUP_TYPE", LUA_NATIVE_OBJECT__GET_AMMO_TYPE_FROM_PICKUP_TYPE);
		OBJECT.set_function("SET_OBJECT_TINT_INDEX", LUA_NATIVE_OBJECT_SET_OBJECT_TINT_INDEX);
		OBJECT.set_function("_GET_OBJECT_LIGHT_INTENSITY", LUA_NATIVE_OBJECT__GET_OBJECT_LIGHT_INTENSITY);
		OBJECT.set_function("_SET_OBJECT_BURN_OPACITY", LUA_NATIVE_OBJECT__SET_OBJECT_BURN_OPACITY);
		OBJECT.set_function("_SET_OBJECT_BURN_INTENSITY", LUA_NATIVE_OBJECT__SET_OBJECT_BURN_INTENSITY);
		OBJECT.set_function("_SET_OBJECT_BURN_LEVEL", LUA_NATIVE_OBJECT__SET_OBJECT_BURN_LEVEL);
		OBJECT.set_function("_0x9A74A9CADFA8A598", LUA_NATIVE_OBJECT__0x9A74A9CADFA8A598);
		OBJECT.set_function("_RESET_OBJECT_VELOCITY", LUA_NATIVE_OBJECT__RESET_OBJECT_VELOCITY);
		OBJECT.set_function("_SET_OBJECT_BURN_SPEED", LUA_NATIVE_OBJECT__SET_OBJECT_BURN_SPEED);
		OBJECT.set_function("_0xCBFBD38F2E0A263B", LUA_NATIVE_OBJECT__0xCBFBD38F2E0A263B);
		OBJECT.set_function("CONVERT_OLD_PICKUP_TYPE_TO_NEW", LUA_NATIVE_OBJECT_CONVERT_OLD_PICKUP_TYPE_TO_NEW);
		OBJECT.set_function("SET_FORCE_OBJECT_THIS_FRAME", LUA_NATIVE_OBJECT_SET_FORCE_OBJECT_THIS_FRAME);
		OBJECT.set_function("_0xD91E55B6C005EB09", LUA_NATIVE_OBJECT__0xD91E55B6C005EB09);
		OBJECT.set_function("ONLY_CLEAN_UP_OBJECT_WHEN_OUT_OF_RANGE", LUA_NATIVE_OBJECT_ONLY_CLEAN_UP_OBJECT_WHEN_OUT_OF_RANGE);
		OBJECT.set_function("_0xCAAF2BCCFEF37F77", LUA_NATIVE_OBJECT__0xCAAF2BCCFEF37F77);
		OBJECT.set_function("_0x08C5825A2932EA7B", LUA_NATIVE_OBJECT__0x08C5825A2932EA7B);
		OBJECT.set_function("_0x7D4411D6736CD295", LUA_NATIVE_OBJECT__0x7D4411D6736CD295);
		OBJECT.set_function("_0x250EBB11E81A10BE", LUA_NATIVE_OBJECT__0x250EBB11E81A10BE);
		OBJECT.set_function("_0x2BF1953C0C21AC88", LUA_NATIVE_OBJECT__0x2BF1953C0C21AC88);
		OBJECT.set_function("CREATE_OBJECT_SKELETON", LUA_NATIVE_OBJECT_CREATE_OBJECT_SKELETON);
		OBJECT.set_function("_MAKE_ITEM_CARRIABLE", LUA_NATIVE_OBJECT__MAKE_ITEM_CARRIABLE);
		OBJECT.set_function("_0xF65EDE5D02A7A760", LUA_NATIVE_OBJECT__0xF65EDE5D02A7A760);
		OBJECT.set_function("_SET_AUTO_JUMPABLE_BY_HORSE", LUA_NATIVE_OBJECT__SET_AUTO_JUMPABLE_BY_HORSE);
		OBJECT.set_function("_SET_NOT_JUMPABLE_BY_HORSE", LUA_NATIVE_OBJECT__SET_NOT_JUMPABLE_BY_HORSE);
		OBJECT.set_function("_SET_OBJECT_KICKABLE", LUA_NATIVE_OBJECT__SET_OBJECT_KICKABLE);
		OBJECT.set_function("SET_CUSTOM_TEXTURES_ON_OBJECT", LUA_NATIVE_OBJECT_SET_CUSTOM_TEXTURES_ON_OBJECT);
		OBJECT.set_function("_0xD503D6F0986D58BC", LUA_NATIVE_OBJECT__0xD503D6F0986D58BC);
		OBJECT.set_function("_0xAEE6C800E124CFE1", LUA_NATIVE_OBJECT__0xAEE6C800E124CFE1);
		OBJECT.set_function("_0x3DF1A0A58498E209", LUA_NATIVE_OBJECT__0x3DF1A0A58498E209);
	}
}
