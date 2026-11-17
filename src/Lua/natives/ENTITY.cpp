#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static bool LUA_NATIVE_ENTITY_DOES_ENTITY_EXIST(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::DOES_ENTITY_EXIST(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_DOES_ENTITY_BELONG_TO_THIS_SCRIPT(Entity EntityIndex, bool bDeadCheck)
	{
		auto retval = (bool)ENTITY::DOES_ENTITY_BELONG_TO_THIS_SCRIPT(EntityIndex, bDeadCheck);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_DOES_ENTITY_HAVE_DRAWABLE(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::DOES_ENTITY_HAVE_DRAWABLE(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_DOES_ENTITY_HAVE_PHYSICS(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::DOES_ENTITY_HAVE_PHYSICS(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_HAS_ENTITY_BEEN_DAMAGED_BY_ANY_OBJECT(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ANY_OBJECT(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_HAS_ENTITY_BEEN_DAMAGED_BY_ANY_PED(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ANY_PED(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_HAS_ENTITY_BEEN_DAMAGED_BY_ANY_VEHICLE(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ANY_VEHICLE(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_HAS_ENTITY_BEEN_DAMAGED_BY_ENTITY(Entity EntityIndex, Entity DamagerIndex, bool p2, bool p3)
	{
		auto retval = (bool)ENTITY::HAS_ENTITY_BEEN_DAMAGED_BY_ENTITY(EntityIndex, DamagerIndex, p2, p3);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY__0x3EC28DA1FFAC9DDD(Entity entity1, Entity entity2, Any p2, Any p3)
	{
		auto retval = (bool)ENTITY::_0x3EC28DA1FFAC9DDD(entity1, entity2, p2, p3);
		return retval;
	}

	static Entity LUA_NATIVE_ENTITY__0xAF72EC7E1B54539B(Entity entity)
	{
		auto retval = ENTITY::_0xAF72EC7E1B54539B(entity);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_HAS_ENTITY_CLEAR_LOS_TO_ENTITY(Entity FirstEntityIndex, Entity SecondEntityIndex, int LOSFlags)
	{
		auto retval = (bool)ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(FirstEntityIndex, SecondEntityIndex, LOSFlags);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_HAS_ENTITY_CLEAR_LOS_TO_COORD(Entity entity, float x, float y, float z, int flags)
	{
		auto retval = (bool)ENTITY::HAS_ENTITY_CLEAR_LOS_TO_COORD(entity, x, y, z, flags);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_HAS_ENTITY_CLEAR_LOS_TO_ENTITY_IN_FRONT(Entity FirstEntityIndex, Entity SecondEntityIndex, int traceType)
	{
		auto retval = (bool)ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY_IN_FRONT(FirstEntityIndex, SecondEntityIndex, traceType);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_HAS_ENTITY_COLLIDED_WITH_ANYTHING(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::HAS_ENTITY_COLLIDED_WITH_ANYTHING(EntityIndex);
		return retval;
	}

	static float LUA_NATIVE_ENTITY__0x6D58167F62238284(Vehicle vehicle)
	{
		auto retval = ENTITY::_0x6D58167F62238284(vehicle);
		return retval;
	}

	static float LUA_NATIVE_ENTITY__0xDFC2B226D56D85F6(Any p0, Any p1)
	{
		auto retval = ENTITY::_0xDFC2B226D56D85F6(p0, p1);
		return retval;
	}

	static float LUA_NATIVE_ENTITY_GET_ANIM_DURATION(sol::stack_object pAnimDictName, sol::stack_object pAnimName)
	{
		auto retval = ENTITY::GET_ANIM_DURATION(pAnimDictName.is<const char*>() ? pAnimDictName.as<const char*>() : nullptr, pAnimName.is<const char*>() ? pAnimName.as<const char*>() : nullptr);
		return retval;
	}

	static Entity LUA_NATIVE_ENTITY_GET_ENTITY_ATTACHED_TO(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_ENTITY_ATTACHED_TO(EntityIndex);
		return retval;
	}

	static Vector3 LUA_NATIVE_ENTITY_GET_ENTITY_COORDS(Entity EntityIndex, bool DoDeadCheck, bool realCoords)
	{
		auto retval = ENTITY::GET_ENTITY_COORDS(EntityIndex, DoDeadCheck, realCoords);
		return retval;
	}

	static Vector3 LUA_NATIVE_ENTITY_GET_ENTITY_FORWARD_VECTOR(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_ENTITY_FORWARD_VECTOR(EntityIndex);
		return retval;
	}

	static float LUA_NATIVE_ENTITY_GET_ENTITY_FORWARD_X(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_ENTITY_FORWARD_X(EntityIndex);
		return retval;
	}

	static float LUA_NATIVE_ENTITY_GET_ENTITY_FORWARD_Y(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_ENTITY_FORWARD_Y(EntityIndex);
		return retval;
	}

	static Vector3 LUA_NATIVE_ENTITY__GET_ENTITY_FORWARD_VECTOR_YX(Entity entity)
	{
		auto retval = ENTITY::_GET_ENTITY_FORWARD_VECTOR_YX(entity);
		return retval;
	}

	static float LUA_NATIVE_ENTITY_GET_ENTITY_HEADING(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_ENTITY_HEADING(EntityIndex);
		return retval;
	}

	static int LUA_NATIVE_ENTITY_GET_ENTITY_HEALTH(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_ENTITY_HEALTH(EntityIndex);
		return retval;
	}

	static float LUA_NATIVE_ENTITY__GET_ENTITY_HEALTH_FLOAT(Entity entity)
	{
		auto retval = ENTITY::_GET_ENTITY_HEALTH_FLOAT(entity);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY__CHANGE_ENTITY_HEALTH(Entity entity, float amount, Entity entity2, Hash weaponHash)
	{
		auto retval = (bool)ENTITY::_CHANGE_ENTITY_HEALTH(entity, amount, entity2, weaponHash);
		return retval;
	}

	static int LUA_NATIVE_ENTITY_GET_ENTITY_MAX_HEALTH(Entity EntityIndex, bool p1)
	{
		auto retval = ENTITY::GET_ENTITY_MAX_HEALTH(EntityIndex, p1);
		return retval;
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_MAX_HEALTH(Entity EntityIndex, int Health)
	{
		ENTITY::SET_ENTITY_MAX_HEALTH(EntityIndex, Health);
	}

	static float LUA_NATIVE_ENTITY_GET_ENTITY_HEIGHT(Entity EntityIndex, float PositionX, float PositionY, float PositionZ, bool IsWorldPos, bool WantWorldResult)
	{
		auto retval = ENTITY::GET_ENTITY_HEIGHT(EntityIndex, PositionX, PositionY, PositionZ, IsWorldPos, WantWorldResult);
		return retval;
	}

	static float LUA_NATIVE_ENTITY_GET_ENTITY_HEIGHT_ABOVE_GROUND(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_ENTITY_HEIGHT_ABOVE_GROUND(EntityIndex);
		return retval;
	}

	static std::tuple<Vector3, Vector3> LUA_NATIVE_ENTITY__GET_ENTITY_WORLD_POSITION_OF_DIMENSIONS(Entity entity, Vector3 minimum, Vector3 maximum)
	{
		std::tuple<Vector3, Vector3> return_values;
		ENTITY::_GET_ENTITY_WORLD_POSITION_OF_DIMENSIONS(entity, &minimum, &maximum);
		std::get<0>(return_values) = minimum;
		std::get<1>(return_values) = maximum;

		return return_values;
	}

	static std::tuple<Vector3, Vector3, Vector3, Vector3> LUA_NATIVE_ENTITY_GET_ENTITY_MATRIX(Entity EntityIndex, Vector3 vFront, Vector3 vSide, Vector3 vUp, Vector3 vPos)
	{
		std::tuple<Vector3, Vector3, Vector3, Vector3> return_values;
		ENTITY::GET_ENTITY_MATRIX(EntityIndex, &vFront, &vSide, &vUp, &vPos);
		std::get<0>(return_values) = vFront;
		std::get<1>(return_values) = vSide;
		std::get<2>(return_values) = vUp;
		std::get<3>(return_values) = vPos;

		return return_values;
	}

	static Hash LUA_NATIVE_ENTITY_GET_ENTITY_MODEL(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_ENTITY_MODEL(EntityIndex);
		return retval;
	}

	static Hash LUA_NATIVE_ENTITY__GET_PED_ANIMAL_TYPE(Ped ped)
	{
		auto retval = ENTITY::_GET_PED_ANIMAL_TYPE(ped);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_GET_IS_ANIMAL(Entity entity)
	{
		auto retval = (bool)ENTITY::GET_IS_ANIMAL(entity);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY__GET_IS_BIRD(Entity entity)
	{
		auto retval = (bool)ENTITY::_GET_IS_BIRD(entity);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY__GET_IS_PREDATOR(Entity entity)
	{
		auto retval = (bool)ENTITY::_GET_IS_PREDATOR(entity);
		return retval;
	}

	static Vector3 LUA_NATIVE_ENTITY_GET_OFFSET_FROM_ENTITY_GIVEN_WORLD_COORDS(Entity EntityIndex, float VecWorldCoorsX, float VecWorldCoorsY, float VecWorldCoorsZ)
	{
		auto retval = ENTITY::GET_OFFSET_FROM_ENTITY_GIVEN_WORLD_COORDS(EntityIndex, VecWorldCoorsX, VecWorldCoorsY, VecWorldCoorsZ);
		return retval;
	}

	static Vector3 LUA_NATIVE_ENTITY_GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Entity EntityIndex, float VecNewCoorsX, float VecNewCoorsY, float VecNewCoorsZ)
	{
		auto retval = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(EntityIndex, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ);
		return retval;
	}

	static float LUA_NATIVE_ENTITY_GET_ENTITY_PITCH(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_ENTITY_PITCH(EntityIndex);
		return retval;
	}

	static float LUA_NATIVE_ENTITY_GET_ENTITY_ROLL(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_ENTITY_ROLL(EntityIndex);
		return retval;
	}

	static Vector3 LUA_NATIVE_ENTITY_GET_ENTITY_ROTATION(Entity EntityIndex, int RotOrder)
	{
		auto retval = ENTITY::GET_ENTITY_ROTATION(EntityIndex, RotOrder);
		return retval;
	}

	static Hash LUA_NATIVE_ENTITY__GET_ENTITY_SCRIPT(Entity entity, uintptr_t argStruct)
	{
		auto retval = ENTITY::_GET_ENTITY_SCRIPT(entity, (Any*)argStruct);
		return retval;
	}

	static float LUA_NATIVE_ENTITY_GET_ENTITY_SPEED(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_ENTITY_SPEED(EntityIndex);
		return retval;
	}

	static Vector3 LUA_NATIVE_ENTITY_GET_ENTITY_SPEED_VECTOR(Entity EntityIndex, bool bLocalResult)
	{
		auto retval = ENTITY::GET_ENTITY_SPEED_VECTOR(EntityIndex, bLocalResult);
		return retval;
	}

	static float LUA_NATIVE_ENTITY_GET_ENTITY_UPRIGHT_VALUE(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_ENTITY_UPRIGHT_VALUE(EntityIndex);
		return retval;
	}

	static Vector3 LUA_NATIVE_ENTITY_GET_ENTITY_VELOCITY(Entity EntityIndex, int p1)
	{
		auto retval = ENTITY::GET_ENTITY_VELOCITY(EntityIndex, p1);
		return retval;
	}

	static Object LUA_NATIVE_ENTITY_GET_OBJECT_INDEX_FROM_ENTITY_INDEX(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_OBJECT_INDEX_FROM_ENTITY_INDEX(EntityIndex);
		return retval;
	}

	static Ped LUA_NATIVE_ENTITY_GET_PED_INDEX_FROM_ENTITY_INDEX(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_PED_INDEX_FROM_ENTITY_INDEX(EntityIndex);
		return retval;
	}

	static Vehicle LUA_NATIVE_ENTITY_GET_VEHICLE_INDEX_FROM_ENTITY_INDEX(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_VEHICLE_INDEX_FROM_ENTITY_INDEX(EntityIndex);
		return retval;
	}

	static Vector3 LUA_NATIVE_ENTITY_GET_WORLD_POSITION_OF_ENTITY_BONE(Entity EntityIndex, int iBoneIdx)
	{
		auto retval = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(EntityIndex, iBoneIdx);
		return retval;
	}

	static Vector3 LUA_NATIVE_ENTITY__0x5E214112806591EA(Entity entity, int boneIndex)
	{
		auto retval = ENTITY::_0x5E214112806591EA(entity, boneIndex);
		return retval;
	}

	static Vector3 LUA_NATIVE_ENTITY__0x3AB3A77672F6473F(Any p0, Any p1, Any p2, Any p3)
	{
		auto retval = ENTITY::_0x3AB3A77672F6473F(p0, p1, p2, p3);
		return retval;
	}

	static int LUA_NATIVE_ENTITY_GET_NEAREST_PLAYER_TO_ENTITY(Entity entityIndex, Ped playerPedToIgnore, int flags)
	{
		auto retval = ENTITY::GET_NEAREST_PLAYER_TO_ENTITY(entityIndex, playerPedToIgnore, flags);
		return retval;
	}

	static int LUA_NATIVE_ENTITY_GET_NEAREST_PLAYER_TO_ENTITY_ON_TEAM(Entity entityIndex, int team, Ped playerPedToIgnore, int flags)
	{
		auto retval = ENTITY::GET_NEAREST_PLAYER_TO_ENTITY_ON_TEAM(entityIndex, team, playerPedToIgnore, flags);
		return retval;
	}

	static Player LUA_NATIVE_ENTITY_GET_NEAREST_PARTICIPANT_TO_ENTITY(Entity entity)
	{
		auto retval = ENTITY::GET_NEAREST_PARTICIPANT_TO_ENTITY(entity);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_PLACE_ENTITY_ON_GROUND_PROPERLY(Entity entity, bool p1)
	{
		auto retval = (bool)ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(entity, p1);
		return retval;
	}

	static int LUA_NATIVE_ENTITY_GET_ENTITY_TYPE(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_ENTITY_TYPE(EntityIndex);
		return retval;
	}

	static int LUA_NATIVE_ENTITY_GET_ENTITY_POPULATION_TYPE(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_ENTITY_POPULATION_TYPE(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_AN_ENTITY(ScrHandle obj)
	{
		auto retval = (bool)ENTITY::IS_AN_ENTITY(obj);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_A_PED(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_A_PED(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_A_MISSION_ENTITY(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_A_MISSION_ENTITY(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_A_VEHICLE(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_A_VEHICLE(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_AN_OBJECT(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_AN_OBJECT(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_AT_COORD(Entity EntityIndex, float VecCoorsX, float VecCoorsY, float VecCoorsZ, float VecLocDimensionsX, float VecLocDimensionsY, float VecLocDimensionsZ, bool HighlightArea, bool Do3dCheck, int TM_MODE)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_AT_COORD(EntityIndex, VecCoorsX, VecCoorsY, VecCoorsZ, VecLocDimensionsX, VecLocDimensionsY, VecLocDimensionsZ, HighlightArea, Do3dCheck, TM_MODE);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_AT_ENTITY(Entity EntityIndex, Entity TargetEntityIndex, float VecLocDimensionsX, float VecLocDimensionsY, float VecLocDimensionsZ, bool HighlightArea, bool Do3dCheck, int TM_MODE)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_AT_ENTITY(EntityIndex, TargetEntityIndex, VecLocDimensionsX, VecLocDimensionsY, VecLocDimensionsZ, HighlightArea, Do3dCheck, TM_MODE);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_ATTACHED(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_ATTACHED(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_ATTACHED_TO_ANY_OBJECT(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_ATTACHED_TO_ANY_OBJECT(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_ATTACHED_TO_ANY_PED(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_ATTACHED_TO_ANY_PED(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_ATTACHED_TO_ANY_VEHICLE(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_ATTACHED_TO_ANY_VEHICLE(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_ATTACHED_TO_ENTITY(Entity EntityIndex1, Entity EntityIndex2)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(EntityIndex1, EntityIndex2);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY__IS_ENTITY_OWNED_BY_PERSISTENCE_SYSTEM(Entity entity)
	{
		auto retval = (bool)ENTITY::_IS_ENTITY_OWNED_BY_PERSISTENCE_SYSTEM(entity);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_DEAD(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_DEAD(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_IN_AIR(Entity EntityIndex, Any p1)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_IN_AIR(EntityIndex, p1);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_IN_ANGLED_AREA(Entity EntityIndex, float VecCoors1X, float VecCoors1Y, float VecCoors1Z, float VecCoors2X, float VecCoors2Y, float VecCoors2Z, float AreaWidth, bool HighlightArea, bool Do3dCheck, int TM_MODE)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_IN_ANGLED_AREA(EntityIndex, VecCoors1X, VecCoors1Y, VecCoors1Z, VecCoors2X, VecCoors2Y, VecCoors2Z, AreaWidth, HighlightArea, Do3dCheck, TM_MODE);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_IN_AREA(Entity EntityIndex, float VecCoors1X, float VecCoors1Y, float VecCoors1Z, float VecCoors2X, float VecCoors2Y, float VecCoors2Z, bool HighlightArea, bool Do3dCheck, int TM_MODE)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_IN_AREA(EntityIndex, VecCoors1X, VecCoors1Y, VecCoors1Z, VecCoors2X, VecCoors2Y, VecCoors2Z, HighlightArea, Do3dCheck, TM_MODE);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_IN_VOLUME(Entity entity, ScrHandle volume, bool p2, int p3)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_IN_VOLUME(entity, volume, p2, p3);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_IN_WATER(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_IN_WATER(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY__IS_ENTITY_UNDERWATER(Entity entity, bool p1)
	{
		auto retval = (bool)ENTITY::_IS_ENTITY_UNDERWATER(entity, p1);
		return retval;
	}

	static float LUA_NATIVE_ENTITY_GET_ENTITY_SUBMERGED_LEVEL(Entity EntityIndex)
	{
		auto retval = ENTITY::GET_ENTITY_SUBMERGED_LEVEL(EntityIndex);
		return retval;
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_REQUIRES_MORE_EXPENSIVE_RIVER_CHECK(Entity EntityIndex, bool FlagValue)
	{
		ENTITY::SET_ENTITY_REQUIRES_MORE_EXPENSIVE_RIVER_CHECK(EntityIndex, FlagValue);
	}

	static void LUA_NATIVE_ENTITY__0x7A49D40DE437BC8D(Any p0, Any p1)
	{
		ENTITY::_0x7A49D40DE437BC8D(p0, p1);
	}

	static void LUA_NATIVE_ENTITY__0x978AA2323ED32209(Any p0, Any p1)
	{
		ENTITY::_0x978AA2323ED32209(p0, p1);
	}

	static void LUA_NATIVE_ENTITY__0x002AAC783ED323ED(Any p0, Any p1)
	{
		ENTITY::_0x002AAC783ED323ED(p0, p1);
	}

	static void LUA_NATIVE_ENTITY__0x007AAC783ED323ED(Any p0, Any p1, Any p2)
	{
		ENTITY::_0x007AAC783ED323ED(p0, p1, p2);
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_ON_SCREEN(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_ON_SCREEN(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_PLAYING_ANIM(Entity EntityIndex, sol::stack_object AnimDictName, sol::stack_object AnimName, int type)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_PLAYING_ANIM(EntityIndex, AnimDictName.is<const char*>() ? AnimDictName.as<const char*>() : nullptr, AnimName.is<const char*>() ? AnimName.as<const char*>() : nullptr, type);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY__IS_ENTITY_PLAYING_ANY_ANIM(Entity entity, int p1)
	{
		auto retval = (bool)ENTITY::_IS_ENTITY_PLAYING_ANY_ANIM(entity, p1);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_STATIC(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_STATIC(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_TOUCHING_ENTITY(Entity FirstEntityIndex, Entity SecondEntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_TOUCHING_ENTITY(FirstEntityIndex, SecondEntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_TOUCHING_MODEL(Entity EntityIndex, Hash ModelHashKey)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_TOUCHING_MODEL(EntityIndex, ModelHashKey);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_UPRIGHT(Entity EntityIndex, float fAngleToVerticalLimit)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_UPRIGHT(EntityIndex, fAngleToVerticalLimit);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_UPSIDEDOWN(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_UPSIDEDOWN(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_VISIBLE(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_VISIBLE(EntityIndex);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__0xFF9965C47FA404DA(Entity entity, bool toggle)
	{
		ENTITY::_0xFF9965C47FA404DA(entity, toggle);
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_VISIBLE_TO_SCRIPT(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_VISIBLE_TO_SCRIPT(EntityIndex);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__0x3F08C6163A4AB1D6(Any p0)
	{
		ENTITY::_0x3F08C6163A4AB1D6(p0);
	}

	static void LUA_NATIVE_ENTITY__0x0DB41D59E0F1502B(Any p0)
	{
		ENTITY::_0x0DB41D59E0F1502B(p0);
	}

	static bool LUA_NATIVE_ENTITY__IS_TRACKED_ENTITY_VISIBLE(Entity entity)
	{
		auto retval = (bool)ENTITY::_IS_TRACKED_ENTITY_VISIBLE(entity);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_OCCLUDED(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_OCCLUDED(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_WOULD_ENTITY_BE_OCCLUDED(Hash ModelHashKey, float CoordsX, float CoordsY, float CoordsZ, bool bAssertIfModelIsntLoaded)
	{
		auto retval = (bool)ENTITY::WOULD_ENTITY_BE_OCCLUDED(ModelHashKey, CoordsX, CoordsY, CoordsZ, bAssertIfModelIsntLoaded);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_IS_ENTITY_WAITING_FOR_WORLD_COLLISION(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::IS_ENTITY_WAITING_FOR_WORLD_COLLISION(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY__IS_ENTITY_ON_TRAIN_TRACK(Entity entity)
	{
		auto retval = (bool)ENTITY::_IS_ENTITY_ON_TRAIN_TRACK(entity);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__0xCDB682BB47C02F0A(Entity entity, Hash p1)
	{
		ENTITY::_0xCDB682BB47C02F0A(entity, p1);
	}

	static void LUA_NATIVE_ENTITY__0xE19035EB65AB2932(Any p0, Any p1)
	{
		ENTITY::_0xE19035EB65AB2932(p0, p1);
	}

	static bool LUA_NATIVE_ENTITY_SCRIPT_OVERRIDE_ENTITY_LOOT_TABLE_PERMANENT(Entity entity, Hash lootTable)
	{
		auto retval = (bool)ENTITY::SCRIPT_OVERRIDE_ENTITY_LOOT_TABLE_PERMANENT(entity, lootTable);
		return retval;
	}

	static std::tuple<bool, Hash> LUA_NATIVE_ENTITY__GET_SCRIPT_OVERRIDE_ENTITY_LOOT_TABLE_PERMANENT(Entity entity, Hash lootTable)
	{
		std::tuple<bool, Hash> return_values;
		std::get<0>(return_values) = (bool)ENTITY::_GET_SCRIPT_OVERRIDE_ENTITY_LOOT_TABLE_PERMANENT(entity, &lootTable);
		std::get<1>(return_values) = lootTable;

		return return_values;
	}

	static bool LUA_NATIVE_ENTITY__REQUEST_ENTITY_LOOT_LIST(Ped mount, uintptr_t argStruct, Hash visiblelootslotrequestType, int flag, int p4, bool p5)
	{
		auto retval = (bool)ENTITY::_REQUEST_ENTITY_LOOT_LIST(mount, (Any*)argStruct, visiblelootslotrequestType, flag, p4, p5);
		return retval;
	}

	static Any LUA_NATIVE_ENTITY__0xE31FC20319874CB3(Any p0, Any p1, Any p2)
	{
		auto retval = ENTITY::_0xE31FC20319874CB3(p0, p1, p2);
		return retval;
	}

	static Any LUA_NATIVE_ENTITY__0x582F73ACFE969571(Any p0, Any p1, Any p2)
	{
		auto retval = ENTITY::_0x582F73ACFE969571(p0, p1, p2);
		return retval;
	}

	static Any LUA_NATIVE_ENTITY__0xBA2A089E60ED1163(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		auto retval = ENTITY::_0xBA2A089E60ED1163(p0, p1, p2, p3, p4);
		return retval;
	}

	static int LUA_NATIVE_ENTITY_GET_CARRIABLE_ENTITY_STATE(Entity entity)
	{
		auto retval = ENTITY::GET_CARRIABLE_ENTITY_STATE(entity);
		return retval;
	}

	static Any LUA_NATIVE_ENTITY__0xD46BF94C4C66FAB0(Any p0, Any p1, Any p2, Any p3)
	{
		auto retval = ENTITY::_0xD46BF94C4C66FAB0(p0, p1, p2, p3);
		return retval;
	}

	static Hash LUA_NATIVE_ENTITY__GET_OPTIMAL_CARRY_CONFIG(Entity entity, int index)
	{
		auto retval = ENTITY::_GET_OPTIMAL_CARRY_CONFIG(entity, index);
		return retval;
	}

	static Any LUA_NATIVE_ENTITY__0xD21C7418C590BB40(Any p0)
	{
		auto retval = ENTITY::_0xD21C7418C590BB40(p0);
		return retval;
	}

	static Hash LUA_NATIVE_ENTITY__GET_ENTITY_CARRY_CONFIG(Entity entity)
	{
		auto retval = ENTITY::_GET_ENTITY_CARRY_CONFIG(entity);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY__IS_CARRIABLE_MODEL(Hash model)
	{
		auto retval = (bool)ENTITY::_IS_CARRIABLE_MODEL(model);
		return retval;
	}

	static Hash LUA_NATIVE_ENTITY__GET_CARRIABLE_FROM_ENTITY(Entity entity)
	{
		auto retval = ENTITY::_GET_CARRIABLE_FROM_ENTITY(entity);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__SET_ENTITY_CARCASS_TYPE(Entity entity, Hash type)
	{
		ENTITY::_SET_ENTITY_CARCASS_TYPE(entity, type);
	}

	static Any LUA_NATIVE_ENTITY__0x2A77EF9BEC8518F4(Any p0)
	{
		auto retval = ENTITY::_0x2A77EF9BEC8518F4(p0);
		return retval;
	}

	static Entity LUA_NATIVE_ENTITY__DELETE_CARRIABLE(Entity entity)
	{
		ENTITY::_DELETE_CARRIABLE(&entity);
		return entity;
	}

	static bool LUA_NATIVE_ENTITY__IS_ENTITY_FULLY_LOOTED(Entity entity)
	{
		auto retval = (bool)ENTITY::_IS_ENTITY_FULLY_LOOTED(entity);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__SET_ENTITY_FULLY_LOOTED(Entity entity, bool looted)
	{
		ENTITY::_SET_ENTITY_FULLY_LOOTED(entity, looted);
	}

	static Ped LUA_NATIVE_ENTITY__0xEF2D9ED7CE684F08(Ped ped)
	{
		auto retval = ENTITY::_0xEF2D9ED7CE684F08(ped);
		return retval;
	}

	static Any LUA_NATIVE_ENTITY__0x0CCEFC6C2C95DA2A(Any p0, Any p1, Any p2, Any p3)
	{
		auto retval = ENTITY::_0x0CCEFC6C2C95DA2A(p0, p1, p2, p3);
		return retval;
	}

	static std::tuple<bool, int> LUA_NATIVE_ENTITY__0x383F64263F946E45(int p0, Entity entity, int p2, Ped ped, Any p4, int p5)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)ENTITY::_0x383F64263F946E45(&p0, entity, p2, ped, p4, p5);
		std::get<1>(return_values) = p0;

		return return_values;
	}

	static Any LUA_NATIVE_ENTITY__0x8E10DF0FFA63FB65(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		auto retval = ENTITY::_0x8E10DF0FFA63FB65(p0, p1, p2, p3, p4);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY__GET_ENTITY_CARRYING_FLAG(Entity entity, int flagId)
	{
		auto retval = (bool)ENTITY::_GET_ENTITY_CARRYING_FLAG(entity, flagId);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__SET_ENTITY_CARRYING_FLAG(Entity entity, int flagId, bool value)
	{
		ENTITY::_SET_ENTITY_CARRYING_FLAG(entity, flagId, value);
	}

	static void LUA_NATIVE_ENTITY__0xC3ABCFBC7D74AFA5(Ped ped, int p1, bool p2)
	{
		ENTITY::_0xC3ABCFBC7D74AFA5(ped, p1, p2);
	}

	static void LUA_NATIVE_ENTITY__0x371D179701D9C082(Entity entity)
	{
		ENTITY::_0x371D179701D9C082(entity);
	}

	static void LUA_NATIVE_ENTITY__0xA48E4801DEBDF7E4(Entity entity, bool p1)
	{
		ENTITY::_0xA48E4801DEBDF7E4(entity, p1);
	}

	static bool LUA_NATIVE_ENTITY__GET_IS_CARRIABLE_PELT(Entity entity)
	{
		auto retval = (bool)ENTITY::_GET_IS_CARRIABLE_PELT(entity);
		return retval;
	}

	static Any LUA_NATIVE_ENTITY__0xF59FDE7B4D31A630(Any p0)
	{
		auto retval = ENTITY::_0xF59FDE7B4D31A630(p0);
		return retval;
	}

	static Any LUA_NATIVE_ENTITY__0x120376C23F019C6C(Any p0, Any p1)
	{
		auto retval = ENTITY::_0x120376C23F019C6C(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_ENTITY__0x5744562E973E33CD(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		auto retval = ENTITY::_0x5744562E973E33CD(p0, p1, p2, p3, p4);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__0xDD03FC2089AD093C(Any p0, Any p1, Any p2, Any p3)
	{
		ENTITY::_0xDD03FC2089AD093C(p0, p1, p2, p3);
	}

	static Any LUA_NATIVE_ENTITY__0xB16C780C51E51E2B(Any p0)
	{
		auto retval = ENTITY::_0xB16C780C51E51E2B(p0);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__0xEF259AA1E097E0AD(Entity entity, Any p1)
	{
		ENTITY::_0xEF259AA1E097E0AD(entity, p1);
	}

	static void LUA_NATIVE_ENTITY__0xBD94CECFB2D65119(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5)
	{
		ENTITY::_0xBD94CECFB2D65119(p0, p1, p2, p3, p4, p5);
	}

	static void LUA_NATIVE_ENTITY__SET_ENTITY_CUSTOM_PICKUP_RADIUS(Entity entity, float radius)
	{
		ENTITY::_SET_ENTITY_CUSTOM_PICKUP_RADIUS(entity, radius);
	}

	static void LUA_NATIVE_ENTITY__0xE75EEA8DB59A9F39(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5)
	{
		ENTITY::_0xE75EEA8DB59A9F39(p0, p1, p2, p3, p4, p5);
	}

	static Any LUA_NATIVE_ENTITY__0x188736456D1DEDE6(Any p0, Any p1)
	{
		auto retval = ENTITY::_0x188736456D1DEDE6(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__0xC6A1A3D63F122DE7(Any p0, Any p1)
	{
		ENTITY::_0xC6A1A3D63F122DE7(p0, p1);
	}

	static void LUA_NATIVE_ENTITY_APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(Entity EntityIndex, int ApplyType, float vForceX, float vForceY, float vForceZ, int Component, bool LocalForce, bool ScaleByMass, bool applyToChildren)
	{
		ENTITY::APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(EntityIndex, ApplyType, vForceX, vForceY, vForceZ, Component, LocalForce, ScaleByMass, applyToChildren);
	}

	static void LUA_NATIVE_ENTITY_APPLY_FORCE_TO_ENTITY(Entity EntityIndex, int ApplyType, float vForceX, float vForceY, float vForceZ, float vOffsetX, float vOffsetY, float vOffsetZ, int Component, bool LocalForce, bool LocalOffset, bool ScaleByMass, bool triggerAudio, bool ScaleByTimeWarp)
	{
		ENTITY::APPLY_FORCE_TO_ENTITY(EntityIndex, ApplyType, vForceX, vForceY, vForceZ, vOffsetX, vOffsetY, vOffsetZ, Component, LocalForce, LocalOffset, ScaleByMass, triggerAudio, ScaleByTimeWarp);
	}

	static void LUA_NATIVE_ENTITY_ATTACH_ENTITY_TO_ENTITY(Entity FirstEntityIndex, Entity SecondEntityIndex, int SecondEntityBoneIndex, float vecOffsetX, float vecOffsetY, float vecOffsetZ, float vecRotationX, float vecRotationY, float vecRotationZ, bool p9, bool useSoftPinning, bool collision, bool isPed, int RotOrder, bool bAttachOffsetIsRelative, bool p15, bool p16)
	{
		ENTITY::ATTACH_ENTITY_TO_ENTITY(FirstEntityIndex, SecondEntityIndex, SecondEntityBoneIndex, vecOffsetX, vecOffsetY, vecOffsetZ, vecRotationX, vecRotationY, vecRotationZ, p9, useSoftPinning, collision, isPed, RotOrder, bAttachOffsetIsRelative, p15, p16);
	}

	static void LUA_NATIVE_ENTITY_ATTACH_ENTITY_TO_ENTITY_PHYSICALLY(Entity FirstEntityIndex, Entity SecondEntityIndex, int FirstEntityBoneIndex, int SecondEntityBoneIndex, float SecondEntityOffsetX, float SecondEntityOffsetY, float SecondEntityOffsetZ, float FirstEntityOffsetX, float FirstEntityOffsetY, float FirstEntityOffsetZ, float vecRotationX, float vecRotationY, float vecRotationZ, float PhysicalStrength, bool p14, bool p15, bool p16, bool p17, int RotOrder, bool p19, float p20, float p21)
	{
		ENTITY::ATTACH_ENTITY_TO_ENTITY_PHYSICALLY(FirstEntityIndex, SecondEntityIndex, FirstEntityBoneIndex, SecondEntityBoneIndex, SecondEntityOffsetX, SecondEntityOffsetY, SecondEntityOffsetZ, FirstEntityOffsetX, FirstEntityOffsetY, FirstEntityOffsetZ, vecRotationX, vecRotationY, vecRotationZ, PhysicalStrength, p14, p15, p16, p17, RotOrder, p19, p20, p21);
	}

	static void LUA_NATIVE_ENTITY__ATTACH_ENTITY_TO_COORDS_PHYSICALLY(Entity entity, float x, float y, float z, float offsetx, float offsety, float offsetz, float timer, bool p8, int p9, int p10, int p11, int p12, int p13, int p14)
	{
		ENTITY::_ATTACH_ENTITY_TO_COORDS_PHYSICALLY(entity, x, y, z, offsetx, offsety, offsetz, timer, p8, p9, p10, p11, p12, p13, p14);
	}

	static void LUA_NATIVE_ENTITY__0x445D7D8EA66E373E(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11, Any p12, Any p13, Any p14, Any p15)
	{
		ENTITY::_0x445D7D8EA66E373E(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
	}

	static void LUA_NATIVE_ENTITY__0x16908E859C3AB698(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		ENTITY::_0x16908E859C3AB698(p0, p1, p2, p3, p4);
	}

	static int LUA_NATIVE_ENTITY_GET_ENTITY_BONE_INDEX_BY_NAME(Entity EntityIndex, sol::stack_object BoneName)
	{
		auto retval = ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(EntityIndex, BoneName.is<const char*>() ? BoneName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_ENTITY_CLEAR_ENTITY_LAST_DAMAGE_ENTITY(Entity EntityIndex)
	{
		ENTITY::CLEAR_ENTITY_LAST_DAMAGE_ENTITY(EntityIndex);
	}

	static Entity LUA_NATIVE_ENTITY_DELETE_ENTITY(Entity EntityIndex)
	{
		ENTITY::DELETE_ENTITY(&EntityIndex);
		return EntityIndex;
	}

	static Entity LUA_NATIVE_ENTITY__DELETE_ENTITY_2(Entity entity)
	{
		ENTITY::_DELETE_ENTITY_2(&entity);
		return entity;
	}

	static void LUA_NATIVE_ENTITY_DETACH_ENTITY(Entity EntityIndex, bool ApplyVelocity, bool bNoCollisionUntilClear)
	{
		ENTITY::DETACH_ENTITY(EntityIndex, ApplyVelocity, bNoCollisionUntilClear);
	}

	static bool LUA_NATIVE_ENTITY__IS_ENTITY_FROZEN(Entity entity)
	{
		auto retval = (bool)ENTITY::_IS_ENTITY_FROZEN(entity);
		return retval;
	}

	static void LUA_NATIVE_ENTITY_FREEZE_ENTITY_POSITION(Entity EntityIndex, bool FrozenByScriptFlag)
	{
		ENTITY::FREEZE_ENTITY_POSITION(EntityIndex, FrozenByScriptFlag);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_SHOULD_FREEZE_WAITING_ON_COLLISION(Entity EntityIndex, bool ShouldFreeze)
	{
		ENTITY::SET_ENTITY_SHOULD_FREEZE_WAITING_ON_COLLISION(EntityIndex, ShouldFreeze);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_AS_MISSION_ENTITY(Entity EntityIndex, bool ScriptHostObject, bool GrabFromOtherScript)
	{
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(EntityIndex, ScriptHostObject, GrabFromOtherScript);
	}

	static Entity LUA_NATIVE_ENTITY_SET_ENTITY_AS_NO_LONGER_NEEDED(Entity EntityIndex)
	{
		ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&EntityIndex);
		return EntityIndex;
	}

	static Ped LUA_NATIVE_ENTITY_SET_PED_AS_NO_LONGER_NEEDED(Ped PedIndex)
	{
		ENTITY::SET_PED_AS_NO_LONGER_NEEDED(&PedIndex);
		return PedIndex;
	}

	static Vehicle LUA_NATIVE_ENTITY_SET_VEHICLE_AS_NO_LONGER_NEEDED(Vehicle VehicleIndex)
	{
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&VehicleIndex);
		return VehicleIndex;
	}

	static Object LUA_NATIVE_ENTITY_SET_OBJECT_AS_NO_LONGER_NEEDED(Object ObjectIndex)
	{
		ENTITY::SET_OBJECT_AS_NO_LONGER_NEEDED(&ObjectIndex);
		return ObjectIndex;
	}

	static void LUA_NATIVE_ENTITY__0x20FAEE47427A4497()
	{
		ENTITY::_0x20FAEE47427A4497();
	}

	static bool LUA_NATIVE_ENTITY__DOES_THREAD_OWN_THIS_ENTITY(Entity entity)
	{
		auto retval = (bool)ENTITY::_DOES_THREAD_OWN_THIS_ENTITY(entity);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__0x56E0735D6273B227(Any p0, Any p1)
	{
		ENTITY::_0x56E0735D6273B227(p0, p1);
	}

	static void LUA_NATIVE_ENTITY__0xC0EDEF16D90661EE(Entity entity, float p1)
	{
		ENTITY::_0xC0EDEF16D90661EE(entity, p1);
	}

	static void LUA_NATIVE_ENTITY__0x0FD7D7C232876E72(Any p0)
	{
		ENTITY::_0x0FD7D7C232876E72(p0);
	}

	static void LUA_NATIVE_ENTITY__0x0939E773925C4719()
	{
		ENTITY::_0x0939E773925C4719();
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_CAN_BE_DAMAGED(Entity EntityIndex, bool CanBeDamagedFlag)
	{
		ENTITY::SET_ENTITY_CAN_BE_DAMAGED(EntityIndex, CanBeDamagedFlag);
	}

	static bool LUA_NATIVE_ENTITY__GET_ENTITY_CAN_BE_DAMAGED(Entity entity)
	{
		auto retval = (bool)ENTITY::_GET_ENTITY_CAN_BE_DAMAGED(entity);
		return retval;
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_CAN_BE_DAMAGED_BY_RELATIONSHIP_GROUP(Entity EntityIndex, bool AllowDamagedByRelGroup, Hash relGroup)
	{
		ENTITY::SET_ENTITY_CAN_BE_DAMAGED_BY_RELATIONSHIP_GROUP(EntityIndex, AllowDamagedByRelGroup, relGroup);
	}

	static void LUA_NATIVE_ENTITY__0xFF83AF534156B399(Any p0, Any p1)
	{
		ENTITY::_0xFF83AF534156B399(p0, p1);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_CAN_BE_TARGETED_WITHOUT_LOS(Entity EntityIndex, bool TargettableWithNoLos)
	{
		ENTITY::SET_ENTITY_CAN_BE_TARGETED_WITHOUT_LOS(EntityIndex, TargettableWithNoLos);
	}

	static bool LUA_NATIVE_ENTITY_GET_ENTITY_COLLISION_DISABLED(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::GET_ENTITY_COLLISION_DISABLED(EntityIndex);
		return retval;
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_COLLISION(Entity EntityIndex, bool UsesCollisionsFlag, bool KeepDisabledSimulatingFlag)
	{
		ENTITY::SET_ENTITY_COLLISION(EntityIndex, UsesCollisionsFlag, KeepDisabledSimulatingFlag);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_COMPLETELY_DISABLE_COLLISION(Entity EntityIndex, bool UsesCollisionsFlag, bool KeepDisabledSimulatingFlag)
	{
		ENTITY::SET_ENTITY_COMPLETELY_DISABLE_COLLISION(EntityIndex, UsesCollisionsFlag, KeepDisabledSimulatingFlag);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_COORDS(Entity EntityIndex, float VecNewCoorsX, float VecNewCoorsY, float VecNewCoorsZ, bool DoDeadCheck, bool KeepTasks, bool KeepIK, bool DoWarp)
	{
		ENTITY::SET_ENTITY_COORDS(EntityIndex, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ, DoDeadCheck, KeepTasks, KeepIK, DoWarp);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_COORDS_NO_OFFSET(Entity EntityIndex, float VecNewCoorsX, float VecNewCoorsY, float VecNewCoorsZ, bool KeepTasks, bool KeepIK, bool DoWarp)
	{
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(EntityIndex, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ, KeepTasks, KeepIK, DoWarp);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_DYNAMIC(Entity EntityIndex, bool IsDynamic)
	{
		ENTITY::SET_ENTITY_DYNAMIC(EntityIndex, IsDynamic);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_HEADING(Entity EntityIndex, float NewHeading)
	{
		ENTITY::SET_ENTITY_HEADING(EntityIndex, NewHeading);
	}

	static void LUA_NATIVE_ENTITY__SET_ENTITY_COORDS_AND_HEADING(Entity entity, float xPos, float yPos, float zPos, float heading, bool xAxis, bool yAxis, bool zAxis)
	{
		ENTITY::_SET_ENTITY_COORDS_AND_HEADING(entity, xPos, yPos, zPos, heading, xAxis, yAxis, zAxis);
	}

	static void LUA_NATIVE_ENTITY__SET_ENTITY_COORDS_AND_HEADING_NO_OFFSET(Entity entity, float xPos, float yPos, float zPos, float heading, bool p5, bool p6)
	{
		ENTITY::_SET_ENTITY_COORDS_AND_HEADING_NO_OFFSET(entity, xPos, yPos, zPos, heading, p5, p6);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_HEALTH(Entity entity, int healthAmount, Entity entityKilledBy)
	{
		ENTITY::SET_ENTITY_HEALTH(entity, healthAmount, entityKilledBy);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_INVINCIBLE(Entity EntityIndex, bool bInvincible)
	{
		ENTITY::SET_ENTITY_INVINCIBLE(EntityIndex, bInvincible);
	}

	static void LUA_NATIVE_ENTITY__0xAF7F3099B9FEB535(Entity entity, float p1, float p2, float p3)
	{
		ENTITY::_0xAF7F3099B9FEB535(entity, p1, p2, p3);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_IS_TARGET_PRIORITY(Entity EntityIndex, bool bHighPriority, float fTargetableDistance)
	{
		ENTITY::SET_ENTITY_IS_TARGET_PRIORITY(EntityIndex, bHighPriority, fTargetableDistance);
	}

	static void LUA_NATIVE_ENTITY__0xB38A29CCD5447783(Any p0, Any p1, Any p2)
	{
		ENTITY::_0xB38A29CCD5447783(p0, p1, p2);
	}

	static void LUA_NATIVE_ENTITY__SET_ENTITY_THREAT_TIER(Entity entity, int tier, bool p2)
	{
		ENTITY::_SET_ENTITY_THREAT_TIER(entity, tier, p2);
	}

	static int LUA_NATIVE_ENTITY__GET_ENTITY_THREAT_TIER(Entity entity)
	{
		auto retval = ENTITY::_GET_ENTITY_THREAT_TIER(entity);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__0x2D40BCBFE9305DEA(Any p0, Any p1)
	{
		ENTITY::_0x2D40BCBFE9305DEA(p0, p1);
	}

	static void LUA_NATIVE_ENTITY__SET_ENTITY_LIGHTS_ENABLED(Entity entity, bool enabled)
	{
		ENTITY::_SET_ENTITY_LIGHTS_ENABLED(entity, enabled);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_LOAD_COLLISION_FLAG(Entity EntityIndex, bool LoadCollisionFlag)
	{
		ENTITY::SET_ENTITY_LOAD_COLLISION_FLAG(EntityIndex, LoadCollisionFlag);
	}

	static bool LUA_NATIVE_ENTITY_HAS_COLLISION_LOADED_AROUND_ENTITY(Entity EntityIndex)
	{
		auto retval = (bool)ENTITY::HAS_COLLISION_LOADED_AROUND_ENTITY(EntityIndex);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_HAS_COLLISION_LOADED_AROUND_POSITION(float xPos, float yPos, float zPos)
	{
		auto retval = (bool)ENTITY::HAS_COLLISION_LOADED_AROUND_POSITION(xPos, yPos, zPos);
		return retval;
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_ONLY_DAMAGED_BY_PLAYER(Entity EntityIndex, bool OnlyDamagedByPlayer)
	{
		ENTITY::SET_ENTITY_ONLY_DAMAGED_BY_PLAYER(EntityIndex, OnlyDamagedByPlayer);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_ONLY_DAMAGED_BY_RELATIONSHIP_GROUP(Entity EntityIndex, bool OnlyDamagedByRelGroup, Hash relGroup)
	{
		ENTITY::SET_ENTITY_ONLY_DAMAGED_BY_RELATIONSHIP_GROUP(EntityIndex, OnlyDamagedByRelGroup, relGroup);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_PROOFS(Entity EntityIndex, int proofsBitset, bool specialFlag)
	{
		ENTITY::SET_ENTITY_PROOFS(EntityIndex, proofsBitset, specialFlag);
	}

	static int LUA_NATIVE_ENTITY__GET_ENTITY_PROOFS(Entity entity)
	{
		auto retval = ENTITY::_GET_ENTITY_PROOFS(entity);
		return retval;
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_QUATERNION(Entity EntityIndex, float NewX, float NewY, float NewZ, float NewW)
	{
		ENTITY::SET_ENTITY_QUATERNION(EntityIndex, NewX, NewY, NewZ, NewW);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_ROTATION(Entity EntityIndex, float VecNewRotationX, float VecNewRotationY, float VecNewRotationZ, int RotOrder, bool DoDeadCheck)
	{
		ENTITY::SET_ENTITY_ROTATION(EntityIndex, VecNewRotationX, VecNewRotationY, VecNewRotationZ, RotOrder, DoDeadCheck);
	}

	static void LUA_NATIVE_ENTITY__0xD45BB89B53FC0CFD(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7)
	{
		ENTITY::_0xD45BB89B53FC0CFD(p0, p1, p2, p3, p4, p5, p6, p7);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_VISIBLE(Entity EntityIndex, bool VisibleFlag)
	{
		ENTITY::SET_ENTITY_VISIBLE(EntityIndex, VisibleFlag);
	}

	static void LUA_NATIVE_ENTITY__0x80FDEB3A9E9AA578(Entity entity, bool p1)
	{
		ENTITY::_0x80FDEB3A9E9AA578(entity, p1);
	}

	static void LUA_NATIVE_ENTITY__0x9C6906EF8CB20C5F(Entity entity)
	{
		ENTITY::_0x9C6906EF8CB20C5F(entity);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_VELOCITY(Entity EntityIndex, float VecVelocityComponenttX, float VecVelocityComponenttY, float VecVelocityComponenttZ)
	{
		ENTITY::SET_ENTITY_VELOCITY(EntityIndex, VecVelocityComponenttX, VecVelocityComponenttY, VecVelocityComponenttZ);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_HAS_GRAVITY(Entity EntityIndex, bool bHasGravity)
	{
		ENTITY::SET_ENTITY_HAS_GRAVITY(EntityIndex, bHasGravity);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_LOD_DIST(Entity entityIndex, int lodDist)
	{
		ENTITY::SET_ENTITY_LOD_DIST(entityIndex, lodDist);
	}

	static int LUA_NATIVE_ENTITY_GET_ENTITY_LOD_DIST(Entity entityIndex)
	{
		auto retval = ENTITY::GET_ENTITY_LOD_DIST(entityIndex);
		return retval;
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_ALPHA(Entity entityIndex, int alpha_param, bool bUseSmoothAlpha)
	{
		ENTITY::SET_ENTITY_ALPHA(entityIndex, alpha_param, bUseSmoothAlpha);
	}

	static int LUA_NATIVE_ENTITY_GET_ENTITY_ALPHA(Entity entityIndex)
	{
		auto retval = ENTITY::GET_ENTITY_ALPHA(entityIndex);
		return retval;
	}

	static void LUA_NATIVE_ENTITY_RESET_ENTITY_ALPHA(Entity entityIndex)
	{
		ENTITY::RESET_ENTITY_ALPHA(entityIndex);
	}

	static void LUA_NATIVE_ENTITY__SET_ENTITY_FADE_IN(Entity entity)
	{
		ENTITY::_SET_ENTITY_FADE_IN(entity);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_ALWAYS_PRERENDER(Entity entityIndex, bool bAlwaysPreRender)
	{
		ENTITY::SET_ENTITY_ALWAYS_PRERENDER(entityIndex, bAlwaysPreRender);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_RENDER_SCORCHED(Entity entityIndex, bool bRenderScorched)
	{
		ENTITY::SET_ENTITY_RENDER_SCORCHED(entityIndex, bRenderScorched);
	}

	static Any LUA_NATIVE_ENTITY__0x37B01666BAE8F7EF(Entity entity)
	{
		auto retval = ENTITY::_0x37B01666BAE8F7EF(entity);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__0xA9E6D8F2DDFC4DB9(Any p0, Any p1)
	{
		ENTITY::_0xA9E6D8F2DDFC4DB9(p0, p1);
	}

	static void LUA_NATIVE_ENTITY_CREATE_MODEL_SWAP(float posX, float posY, float posZ, float radius, Hash oldModelHash, Hash newModelHash, bool bSurviveMapReload)
	{
		ENTITY::CREATE_MODEL_SWAP(posX, posY, posZ, radius, oldModelHash, newModelHash, bSurviveMapReload);
	}

	static void LUA_NATIVE_ENTITY_REMOVE_MODEL_SWAP(float posX, float posY, float posZ, float radius, Hash oldModelHash, Hash newModelHash, bool bLazy)
	{
		ENTITY::REMOVE_MODEL_SWAP(posX, posY, posZ, radius, oldModelHash, newModelHash, bLazy);
	}

	static void LUA_NATIVE_ENTITY_CREATE_MODEL_HIDE(float posX, float posY, float posZ, float radius, Hash modelHash, bool bSurviveMapReload)
	{
		ENTITY::CREATE_MODEL_HIDE(posX, posY, posZ, radius, modelHash, bSurviveMapReload);
	}

	static void LUA_NATIVE_ENTITY_CREATE_MODEL_HIDE_EXCLUDING_SCRIPT_OBJECTS(float posX, float posY, float posZ, float radius, Hash modelHash, bool bSurviveMapReload)
	{
		ENTITY::CREATE_MODEL_HIDE_EXCLUDING_SCRIPT_OBJECTS(posX, posY, posZ, radius, modelHash, bSurviveMapReload);
	}

	static void LUA_NATIVE_ENTITY_REMOVE_MODEL_HIDE(float posX, float posY, float posZ, float radius, Hash modelHash, bool bLazy)
	{
		ENTITY::REMOVE_MODEL_HIDE(posX, posY, posZ, radius, modelHash, bLazy);
	}

	static Any LUA_NATIVE_ENTITY__0xD4636C2EDB0DEA8A(Any p0)
	{
		auto retval = ENTITY::_0xD4636C2EDB0DEA8A(p0);
		return retval;
	}

	static void LUA_NATIVE_ENTITY_CREATE_FORCED_OBJECT(float posX, float posY, float posZ, float radius, Hash modelHash, bool bSurviveMapReload)
	{
		ENTITY::CREATE_FORCED_OBJECT(posX, posY, posZ, radius, modelHash, bSurviveMapReload);
	}

	static void LUA_NATIVE_ENTITY_REMOVE_FORCED_OBJECT(float posX, float posY, float posZ, float radius, Hash modelHash)
	{
		ENTITY::REMOVE_FORCED_OBJECT(posX, posY, posZ, radius, modelHash);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_NO_COLLISION_ENTITY(Entity entityIndex, Entity secondEntityIndex, bool bReactivateWhenNoCollision)
	{
		ENTITY::SET_ENTITY_NO_COLLISION_ENTITY(entityIndex, secondEntityIndex, bReactivateWhenNoCollision);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_MOTION_BLUR(Entity entityIndex, bool bEnableMotionBlur)
	{
		ENTITY::SET_ENTITY_MOTION_BLUR(entityIndex, bEnableMotionBlur);
	}

	static void LUA_NATIVE_ENTITY_SET_CAN_AUTO_VAULT_ON_ENTITY(Entity entityIndex, bool bCanAutoVault)
	{
		ENTITY::SET_CAN_AUTO_VAULT_ON_ENTITY(entityIndex, bCanAutoVault);
	}

	static void LUA_NATIVE_ENTITY_SET_CAN_CLIMB_ON_ENTITY(Entity entityIndex, bool bCanClimb)
	{
		ENTITY::SET_CAN_CLIMB_ON_ENTITY(entityIndex, bCanClimb);
	}

	static void LUA_NATIVE_ENTITY_SET_ENTITY_NOWEAPONDECALS(Entity entityIndex, bool bNoWeaponDecals)
	{
		ENTITY::SET_ENTITY_NOWEAPONDECALS(entityIndex, bNoWeaponDecals);
	}

	static int LUA_NATIVE_ENTITY__GET_ENTITIES_NEAR_POINT(float x, float y, float z, float radius, ItemSet itemSet, int p5)
	{
		auto retval = ENTITY::_GET_ENTITIES_NEAR_POINT(x, y, z, radius, itemSet, p5);
		return retval;
	}

	static int LUA_NATIVE_ENTITY_GET_MATCHING_ENTITIES(Volume volume, ItemSet itemSet, int entityType, Any p3, Hash p4, sol::stack_object p5)
	{
		auto retval = ENTITY::GET_MATCHING_ENTITIES(volume, itemSet, entityType, p3, p4, p5.is<const char*>() ? p5.as<const char*>() : nullptr);
		return retval;
	}

	static int LUA_NATIVE_ENTITY__GET_ENTITIES_IN_VOLUME(Volume volume, ItemSet itemSet, int entityType)
	{
		auto retval = ENTITY::_GET_ENTITIES_IN_VOLUME(volume, itemSet, entityType);
		return retval;
	}

	static Entity LUA_NATIVE_ENTITY__SEARCH_BUILDING_POOL_FOR_ENTITY_WITH_THIS_MODEL(Hash modelHash)
	{
		auto retval = ENTITY::_SEARCH_BUILDING_POOL_FOR_ENTITY_WITH_THIS_MODEL(modelHash);
		return retval;
	}

	static Any LUA_NATIVE_ENTITY__0xC2E71D7E0A7B4C89(Any p0)
	{
		auto retval = ENTITY::_0xC2E71D7E0A7B4C89(p0);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__0x6C31B06E91518269(Any p0, Any p1)
	{
		ENTITY::_0x6C31B06E91518269(p0, p1);
	}

	static void LUA_NATIVE_ENTITY__0x119A5714578F4E05(Any p0, Any p1)
	{
		ENTITY::_0x119A5714578F4E05(p0, p1);
	}

	static Entity LUA_NATIVE_ENTITY__GET_ENTITY_BY_DOORHASH(Hash doorHash, int p1)
	{
		auto retval = ENTITY::_GET_ENTITY_BY_DOORHASH(doorHash, p1);
		return retval;
	}

	static std::tuple<bool, float, float> LUA_NATIVE_ENTITY_FIND_ANIM_EVENT_PHASE(sol::stack_object pAnimDictName, sol::stack_object pAnimName, sol::stack_object pEventName, float ReturnStartPhase, float ReturnEndPhase)
	{
		std::tuple<bool, float, float> return_values;
		std::get<0>(return_values) = (bool)ENTITY::FIND_ANIM_EVENT_PHASE(pAnimDictName.is<const char*>() ? pAnimDictName.as<const char*>() : nullptr, pAnimName.is<const char*>() ? pAnimName.as<const char*>() : nullptr, pEventName.is<const char*>() ? pEventName.as<const char*>() : nullptr, &ReturnStartPhase, &ReturnEndPhase);
		std::get<1>(return_values) = ReturnStartPhase;
		std::get<2>(return_values) = ReturnEndPhase;

		return return_values;
	}

	static void LUA_NATIVE_ENTITY_FORCE_ENTITY_AI_AND_ANIMATION_UPDATE(Entity EntityIndex, bool p1)
	{
		ENTITY::FORCE_ENTITY_AI_AND_ANIMATION_UPDATE(EntityIndex, p1);
	}

	static float LUA_NATIVE_ENTITY__GET_ENTITY_ANIM_CURRENT_TIME(Entity entity, sol::stack_object animDict, sol::stack_object animName)
	{
		auto retval = ENTITY::_GET_ENTITY_ANIM_CURRENT_TIME(entity, animDict.is<const char*>() ? animDict.as<const char*>() : nullptr, animName.is<const char*>() ? animName.as<const char*>() : nullptr);
		return retval;
	}

	static float LUA_NATIVE_ENTITY__0x8E46E18AA828334F(Entity entity, sol::stack_object animDict, sol::stack_object animClip)
	{
		auto retval = ENTITY::_0x8E46E18AA828334F(entity, animDict.is<const char*>() ? animDict.as<const char*>() : nullptr, animClip.is<const char*>() ? animClip.as<const char*>() : nullptr);
		return retval;
	}

	static Any LUA_NATIVE_ENTITY__0xDF8E49EA89A01DB1(Any p0, Any p1, Any p2)
	{
		auto retval = ENTITY::_0xDF8E49EA89A01DB1(p0, p1, p2);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_HAS_ANIM_EVENT_FIRED(Entity EntityIndex, Hash EventHash)
	{
		auto retval = (bool)ENTITY::HAS_ANIM_EVENT_FIRED(EntityIndex, EventHash);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_HAS_ENTITY_ANIM_FINISHED(Entity EntityIndex, sol::stack_object pAnimDictName, sol::stack_object pAnimName, int animType)
	{
		auto retval = (bool)ENTITY::HAS_ENTITY_ANIM_FINISHED(EntityIndex, pAnimDictName.is<const char*>() ? pAnimDictName.as<const char*>() : nullptr, pAnimName.is<const char*>() ? pAnimName.as<const char*>() : nullptr, animType);
		return retval;
	}

	static bool LUA_NATIVE_ENTITY_PLAY_ENTITY_ANIM(Entity EntityIndex, sol::stack_object AnimName, sol::stack_object AnimDictName, float BlendDelta, bool Loop, bool HoldLastFrame, bool DriveToPose, float StartPhase, int AnimFlags)
	{
		auto retval = (bool)ENTITY::PLAY_ENTITY_ANIM(EntityIndex, AnimName.is<const char*>() ? AnimName.as<const char*>() : nullptr, AnimDictName.is<const char*>() ? AnimDictName.as<const char*>() : nullptr, BlendDelta, Loop, HoldLastFrame, DriveToPose, StartPhase, AnimFlags);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__SET_ENTITY_ANIM_CURRENT_TIME(Entity entity, sol::stack_object animDict, sol::stack_object animName, float time)
	{
		ENTITY::_SET_ENTITY_ANIM_CURRENT_TIME(entity, animDict.is<const char*>() ? animDict.as<const char*>() : nullptr, animName.is<const char*>() ? animName.as<const char*>() : nullptr, time);
	}

	static void LUA_NATIVE_ENTITY__SET_ENTITY_ANIM_SPEED(Entity entity, sol::stack_object animDict, sol::stack_object animName, float speedMultiplier)
	{
		ENTITY::_SET_ENTITY_ANIM_SPEED(entity, animDict.is<const char*>() ? animDict.as<const char*>() : nullptr, animName.is<const char*>() ? animName.as<const char*>() : nullptr, speedMultiplier);
	}

	static bool LUA_NATIVE_ENTITY_STOP_ENTITY_ANIM(Entity EntityIndex, sol::stack_object AnimName, sol::stack_object AnimDictName, float BlendDelta)
	{
		auto retval = (bool)ENTITY::STOP_ENTITY_ANIM(EntityIndex, AnimName.is<const char*>() ? AnimName.as<const char*>() : nullptr, AnimDictName.is<const char*>() ? AnimDictName.as<const char*>() : nullptr, BlendDelta);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__0x669655FFB29EF1A9(Any p0, Any p1, Any p2, Any p3)
	{
		ENTITY::_0x669655FFB29EF1A9(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_ENTITY__ADD_ENTITY_TRACKING_TRAILS(Entity entity)
	{
		ENTITY::_ADD_ENTITY_TRACKING_TRAILS(entity);
	}

	static void LUA_NATIVE_ENTITY__0x5826EFD6D73C4DE5(Entity entity)
	{
		ENTITY::_0x5826EFD6D73C4DE5(entity);
	}

	static void LUA_NATIVE_ENTITY__PAUSE_ENTITY_TRACKING(Entity entity, bool pause)
	{
		ENTITY::_PAUSE_ENTITY_TRACKING(entity, pause);
	}

	static Any LUA_NATIVE_ENTITY__CREATE_FOOTPATH_TRAIL(Any p0, sol::stack_object waypointRecord, bool bUseSnowOffset, float p3, float p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, bool bInit)
	{
		auto retval = ENTITY::_CREATE_FOOTPATH_TRAIL(p0, waypointRecord.is<const char*>() ? waypointRecord.as<const char*>() : nullptr, bUseSnowOffset, p3, p4, p5, p6, p7, p8, p9, p10, bInit);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__0xC76E94A78127412B(Any p0, Any p1, Any p2)
	{
		ENTITY::_0xC76E94A78127412B(p0, p1, p2);
	}

	static void LUA_NATIVE_ENTITY__0x7F20092547B4DDEA(Any p0)
	{
		ENTITY::_0x7F20092547B4DDEA(p0);
	}

	static void LUA_NATIVE_ENTITY__0xF41E2979D5BC5370(Any p0)
	{
		ENTITY::_0xF41E2979D5BC5370(p0);
	}

	static Any LUA_NATIVE_ENTITY__0xAAACB74442C1BED3(Any p0)
	{
		auto retval = ENTITY::_0xAAACB74442C1BED3(p0);
		return retval;
	}

	static Any LUA_NATIVE_ENTITY_PIN_CLOSEST_MAP_ENTITY(Hash modelHash, float x, float y, float z, int flags)
	{
		auto retval = ENTITY::PIN_CLOSEST_MAP_ENTITY(modelHash, x, y, z, flags);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__UNPIN_MAP_ENTITY(Entity entity)
	{
		ENTITY::_UNPIN_MAP_ENTITY(entity);
	}

	static bool LUA_NATIVE_ENTITY_IS_MAP_ENTITY_PINNED(Any p0)
	{
		auto retval = (bool)ENTITY::IS_MAP_ENTITY_PINNED(p0);
		return retval;
	}

	static Entity LUA_NATIVE_ENTITY__GET_PINNED_MAP_ENTITY(Any p0)
	{
		auto retval = ENTITY::_GET_PINNED_MAP_ENTITY(p0);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__0xEAB3D91D30A344F1(Any p0)
	{
		ENTITY::_0xEAB3D91D30A344F1(p0);
	}

	static void LUA_NATIVE_ENTITY__0x37CEB637BA3B1A47(Any p0)
	{
		ENTITY::_0x37CEB637BA3B1A47(p0);
	}

	static Any LUA_NATIVE_ENTITY__0x350E9211074955AF(Any p0, Any p1)
	{
		auto retval = ENTITY::_0x350E9211074955AF(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_ENTITY__0x898586729DB5221D(Ped ped)
	{
		ENTITY::_0x898586729DB5221D(ped);
	}

	static void LUA_NATIVE_ENTITY__0xE9E7A0BAC7F57746(Any p0, Any p1)
	{
		ENTITY::_0xE9E7A0BAC7F57746(p0, p1);
	}

	void RegisterNatives_ENTITY(sol::state& L)
	{
		auto ENTITY = L["ENTITY"].get_or_create<sol::table>();
		ENTITY.set_function("DOES_ENTITY_EXIST", LUA_NATIVE_ENTITY_DOES_ENTITY_EXIST);
		ENTITY.set_function("DOES_ENTITY_BELONG_TO_THIS_SCRIPT", LUA_NATIVE_ENTITY_DOES_ENTITY_BELONG_TO_THIS_SCRIPT);
		ENTITY.set_function("DOES_ENTITY_HAVE_DRAWABLE", LUA_NATIVE_ENTITY_DOES_ENTITY_HAVE_DRAWABLE);
		ENTITY.set_function("DOES_ENTITY_HAVE_PHYSICS", LUA_NATIVE_ENTITY_DOES_ENTITY_HAVE_PHYSICS);
		ENTITY.set_function("HAS_ENTITY_BEEN_DAMAGED_BY_ANY_OBJECT", LUA_NATIVE_ENTITY_HAS_ENTITY_BEEN_DAMAGED_BY_ANY_OBJECT);
		ENTITY.set_function("HAS_ENTITY_BEEN_DAMAGED_BY_ANY_PED", LUA_NATIVE_ENTITY_HAS_ENTITY_BEEN_DAMAGED_BY_ANY_PED);
		ENTITY.set_function("HAS_ENTITY_BEEN_DAMAGED_BY_ANY_VEHICLE", LUA_NATIVE_ENTITY_HAS_ENTITY_BEEN_DAMAGED_BY_ANY_VEHICLE);
		ENTITY.set_function("HAS_ENTITY_BEEN_DAMAGED_BY_ENTITY", LUA_NATIVE_ENTITY_HAS_ENTITY_BEEN_DAMAGED_BY_ENTITY);
		ENTITY.set_function("_0x3EC28DA1FFAC9DDD", LUA_NATIVE_ENTITY__0x3EC28DA1FFAC9DDD);
		ENTITY.set_function("_0xAF72EC7E1B54539B", LUA_NATIVE_ENTITY__0xAF72EC7E1B54539B);
		ENTITY.set_function("HAS_ENTITY_CLEAR_LOS_TO_ENTITY", LUA_NATIVE_ENTITY_HAS_ENTITY_CLEAR_LOS_TO_ENTITY);
		ENTITY.set_function("HAS_ENTITY_CLEAR_LOS_TO_COORD", LUA_NATIVE_ENTITY_HAS_ENTITY_CLEAR_LOS_TO_COORD);
		ENTITY.set_function("HAS_ENTITY_CLEAR_LOS_TO_ENTITY_IN_FRONT", LUA_NATIVE_ENTITY_HAS_ENTITY_CLEAR_LOS_TO_ENTITY_IN_FRONT);
		ENTITY.set_function("HAS_ENTITY_COLLIDED_WITH_ANYTHING", LUA_NATIVE_ENTITY_HAS_ENTITY_COLLIDED_WITH_ANYTHING);
		ENTITY.set_function("_0x6D58167F62238284", LUA_NATIVE_ENTITY__0x6D58167F62238284);
		ENTITY.set_function("_0xDFC2B226D56D85F6", LUA_NATIVE_ENTITY__0xDFC2B226D56D85F6);
		ENTITY.set_function("GET_ANIM_DURATION", LUA_NATIVE_ENTITY_GET_ANIM_DURATION);
		ENTITY.set_function("GET_ENTITY_ATTACHED_TO", LUA_NATIVE_ENTITY_GET_ENTITY_ATTACHED_TO);
		ENTITY.set_function("GET_ENTITY_COORDS", LUA_NATIVE_ENTITY_GET_ENTITY_COORDS);
		ENTITY.set_function("GET_ENTITY_FORWARD_VECTOR", LUA_NATIVE_ENTITY_GET_ENTITY_FORWARD_VECTOR);
		ENTITY.set_function("GET_ENTITY_FORWARD_X", LUA_NATIVE_ENTITY_GET_ENTITY_FORWARD_X);
		ENTITY.set_function("GET_ENTITY_FORWARD_Y", LUA_NATIVE_ENTITY_GET_ENTITY_FORWARD_Y);
		ENTITY.set_function("_GET_ENTITY_FORWARD_VECTOR_YX", LUA_NATIVE_ENTITY__GET_ENTITY_FORWARD_VECTOR_YX);
		ENTITY.set_function("GET_ENTITY_HEADING", LUA_NATIVE_ENTITY_GET_ENTITY_HEADING);
		ENTITY.set_function("GET_ENTITY_HEALTH", LUA_NATIVE_ENTITY_GET_ENTITY_HEALTH);
		ENTITY.set_function("_GET_ENTITY_HEALTH_FLOAT", LUA_NATIVE_ENTITY__GET_ENTITY_HEALTH_FLOAT);
		ENTITY.set_function("_CHANGE_ENTITY_HEALTH", LUA_NATIVE_ENTITY__CHANGE_ENTITY_HEALTH);
		ENTITY.set_function("GET_ENTITY_MAX_HEALTH", LUA_NATIVE_ENTITY_GET_ENTITY_MAX_HEALTH);
		ENTITY.set_function("SET_ENTITY_MAX_HEALTH", LUA_NATIVE_ENTITY_SET_ENTITY_MAX_HEALTH);
		ENTITY.set_function("GET_ENTITY_HEIGHT", LUA_NATIVE_ENTITY_GET_ENTITY_HEIGHT);
		ENTITY.set_function("GET_ENTITY_HEIGHT_ABOVE_GROUND", LUA_NATIVE_ENTITY_GET_ENTITY_HEIGHT_ABOVE_GROUND);
		ENTITY.set_function("_GET_ENTITY_WORLD_POSITION_OF_DIMENSIONS", LUA_NATIVE_ENTITY__GET_ENTITY_WORLD_POSITION_OF_DIMENSIONS);
		ENTITY.set_function("GET_ENTITY_MATRIX", LUA_NATIVE_ENTITY_GET_ENTITY_MATRIX);
		ENTITY.set_function("GET_ENTITY_MODEL", LUA_NATIVE_ENTITY_GET_ENTITY_MODEL);
		ENTITY.set_function("_GET_PED_ANIMAL_TYPE", LUA_NATIVE_ENTITY__GET_PED_ANIMAL_TYPE);
		ENTITY.set_function("GET_IS_ANIMAL", LUA_NATIVE_ENTITY_GET_IS_ANIMAL);
		ENTITY.set_function("_GET_IS_BIRD", LUA_NATIVE_ENTITY__GET_IS_BIRD);
		ENTITY.set_function("_GET_IS_PREDATOR", LUA_NATIVE_ENTITY__GET_IS_PREDATOR);
		ENTITY.set_function("GET_OFFSET_FROM_ENTITY_GIVEN_WORLD_COORDS", LUA_NATIVE_ENTITY_GET_OFFSET_FROM_ENTITY_GIVEN_WORLD_COORDS);
		ENTITY.set_function("GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS", LUA_NATIVE_ENTITY_GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS);
		ENTITY.set_function("GET_ENTITY_PITCH", LUA_NATIVE_ENTITY_GET_ENTITY_PITCH);
		ENTITY.set_function("GET_ENTITY_ROLL", LUA_NATIVE_ENTITY_GET_ENTITY_ROLL);
		ENTITY.set_function("GET_ENTITY_ROTATION", LUA_NATIVE_ENTITY_GET_ENTITY_ROTATION);
		ENTITY.set_function("_GET_ENTITY_SCRIPT", LUA_NATIVE_ENTITY__GET_ENTITY_SCRIPT);
		ENTITY.set_function("GET_ENTITY_SPEED", LUA_NATIVE_ENTITY_GET_ENTITY_SPEED);
		ENTITY.set_function("GET_ENTITY_SPEED_VECTOR", LUA_NATIVE_ENTITY_GET_ENTITY_SPEED_VECTOR);
		ENTITY.set_function("GET_ENTITY_UPRIGHT_VALUE", LUA_NATIVE_ENTITY_GET_ENTITY_UPRIGHT_VALUE);
		ENTITY.set_function("GET_ENTITY_VELOCITY", LUA_NATIVE_ENTITY_GET_ENTITY_VELOCITY);
		ENTITY.set_function("GET_OBJECT_INDEX_FROM_ENTITY_INDEX", LUA_NATIVE_ENTITY_GET_OBJECT_INDEX_FROM_ENTITY_INDEX);
		ENTITY.set_function("GET_PED_INDEX_FROM_ENTITY_INDEX", LUA_NATIVE_ENTITY_GET_PED_INDEX_FROM_ENTITY_INDEX);
		ENTITY.set_function("GET_VEHICLE_INDEX_FROM_ENTITY_INDEX", LUA_NATIVE_ENTITY_GET_VEHICLE_INDEX_FROM_ENTITY_INDEX);
		ENTITY.set_function("GET_WORLD_POSITION_OF_ENTITY_BONE", LUA_NATIVE_ENTITY_GET_WORLD_POSITION_OF_ENTITY_BONE);
		ENTITY.set_function("_0x5E214112806591EA", LUA_NATIVE_ENTITY__0x5E214112806591EA);
		ENTITY.set_function("_0x3AB3A77672F6473F", LUA_NATIVE_ENTITY__0x3AB3A77672F6473F);
		ENTITY.set_function("GET_NEAREST_PLAYER_TO_ENTITY", LUA_NATIVE_ENTITY_GET_NEAREST_PLAYER_TO_ENTITY);
		ENTITY.set_function("GET_NEAREST_PLAYER_TO_ENTITY_ON_TEAM", LUA_NATIVE_ENTITY_GET_NEAREST_PLAYER_TO_ENTITY_ON_TEAM);
		ENTITY.set_function("GET_NEAREST_PARTICIPANT_TO_ENTITY", LUA_NATIVE_ENTITY_GET_NEAREST_PARTICIPANT_TO_ENTITY);
		ENTITY.set_function("PLACE_ENTITY_ON_GROUND_PROPERLY", LUA_NATIVE_ENTITY_PLACE_ENTITY_ON_GROUND_PROPERLY);
		ENTITY.set_function("GET_ENTITY_TYPE", LUA_NATIVE_ENTITY_GET_ENTITY_TYPE);
		ENTITY.set_function("GET_ENTITY_POPULATION_TYPE", LUA_NATIVE_ENTITY_GET_ENTITY_POPULATION_TYPE);
		ENTITY.set_function("IS_AN_ENTITY", LUA_NATIVE_ENTITY_IS_AN_ENTITY);
		ENTITY.set_function("IS_ENTITY_A_PED", LUA_NATIVE_ENTITY_IS_ENTITY_A_PED);
		ENTITY.set_function("IS_ENTITY_A_MISSION_ENTITY", LUA_NATIVE_ENTITY_IS_ENTITY_A_MISSION_ENTITY);
		ENTITY.set_function("IS_ENTITY_A_VEHICLE", LUA_NATIVE_ENTITY_IS_ENTITY_A_VEHICLE);
		ENTITY.set_function("IS_ENTITY_AN_OBJECT", LUA_NATIVE_ENTITY_IS_ENTITY_AN_OBJECT);
		ENTITY.set_function("IS_ENTITY_AT_COORD", LUA_NATIVE_ENTITY_IS_ENTITY_AT_COORD);
		ENTITY.set_function("IS_ENTITY_AT_ENTITY", LUA_NATIVE_ENTITY_IS_ENTITY_AT_ENTITY);
		ENTITY.set_function("IS_ENTITY_ATTACHED", LUA_NATIVE_ENTITY_IS_ENTITY_ATTACHED);
		ENTITY.set_function("IS_ENTITY_ATTACHED_TO_ANY_OBJECT", LUA_NATIVE_ENTITY_IS_ENTITY_ATTACHED_TO_ANY_OBJECT);
		ENTITY.set_function("IS_ENTITY_ATTACHED_TO_ANY_PED", LUA_NATIVE_ENTITY_IS_ENTITY_ATTACHED_TO_ANY_PED);
		ENTITY.set_function("IS_ENTITY_ATTACHED_TO_ANY_VEHICLE", LUA_NATIVE_ENTITY_IS_ENTITY_ATTACHED_TO_ANY_VEHICLE);
		ENTITY.set_function("IS_ENTITY_ATTACHED_TO_ENTITY", LUA_NATIVE_ENTITY_IS_ENTITY_ATTACHED_TO_ENTITY);
		ENTITY.set_function("_IS_ENTITY_OWNED_BY_PERSISTENCE_SYSTEM", LUA_NATIVE_ENTITY__IS_ENTITY_OWNED_BY_PERSISTENCE_SYSTEM);
		ENTITY.set_function("IS_ENTITY_DEAD", LUA_NATIVE_ENTITY_IS_ENTITY_DEAD);
		ENTITY.set_function("IS_ENTITY_IN_AIR", LUA_NATIVE_ENTITY_IS_ENTITY_IN_AIR);
		ENTITY.set_function("IS_ENTITY_IN_ANGLED_AREA", LUA_NATIVE_ENTITY_IS_ENTITY_IN_ANGLED_AREA);
		ENTITY.set_function("IS_ENTITY_IN_AREA", LUA_NATIVE_ENTITY_IS_ENTITY_IN_AREA);
		ENTITY.set_function("IS_ENTITY_IN_VOLUME", LUA_NATIVE_ENTITY_IS_ENTITY_IN_VOLUME);
		ENTITY.set_function("IS_ENTITY_IN_WATER", LUA_NATIVE_ENTITY_IS_ENTITY_IN_WATER);
		ENTITY.set_function("_IS_ENTITY_UNDERWATER", LUA_NATIVE_ENTITY__IS_ENTITY_UNDERWATER);
		ENTITY.set_function("GET_ENTITY_SUBMERGED_LEVEL", LUA_NATIVE_ENTITY_GET_ENTITY_SUBMERGED_LEVEL);
		ENTITY.set_function("SET_ENTITY_REQUIRES_MORE_EXPENSIVE_RIVER_CHECK", LUA_NATIVE_ENTITY_SET_ENTITY_REQUIRES_MORE_EXPENSIVE_RIVER_CHECK);
		ENTITY.set_function("_0x7A49D40DE437BC8D", LUA_NATIVE_ENTITY__0x7A49D40DE437BC8D);
		ENTITY.set_function("_0x978AA2323ED32209", LUA_NATIVE_ENTITY__0x978AA2323ED32209);
		ENTITY.set_function("_0x002AAC783ED323ED", LUA_NATIVE_ENTITY__0x002AAC783ED323ED);
		ENTITY.set_function("_0x007AAC783ED323ED", LUA_NATIVE_ENTITY__0x007AAC783ED323ED);
		ENTITY.set_function("IS_ENTITY_ON_SCREEN", LUA_NATIVE_ENTITY_IS_ENTITY_ON_SCREEN);
		ENTITY.set_function("IS_ENTITY_PLAYING_ANIM", LUA_NATIVE_ENTITY_IS_ENTITY_PLAYING_ANIM);
		ENTITY.set_function("_IS_ENTITY_PLAYING_ANY_ANIM", LUA_NATIVE_ENTITY__IS_ENTITY_PLAYING_ANY_ANIM);
		ENTITY.set_function("IS_ENTITY_STATIC", LUA_NATIVE_ENTITY_IS_ENTITY_STATIC);
		ENTITY.set_function("IS_ENTITY_TOUCHING_ENTITY", LUA_NATIVE_ENTITY_IS_ENTITY_TOUCHING_ENTITY);
		ENTITY.set_function("IS_ENTITY_TOUCHING_MODEL", LUA_NATIVE_ENTITY_IS_ENTITY_TOUCHING_MODEL);
		ENTITY.set_function("IS_ENTITY_UPRIGHT", LUA_NATIVE_ENTITY_IS_ENTITY_UPRIGHT);
		ENTITY.set_function("IS_ENTITY_UPSIDEDOWN", LUA_NATIVE_ENTITY_IS_ENTITY_UPSIDEDOWN);
		ENTITY.set_function("IS_ENTITY_VISIBLE", LUA_NATIVE_ENTITY_IS_ENTITY_VISIBLE);
		ENTITY.set_function("_0xFF9965C47FA404DA", LUA_NATIVE_ENTITY__0xFF9965C47FA404DA);
		ENTITY.set_function("IS_ENTITY_VISIBLE_TO_SCRIPT", LUA_NATIVE_ENTITY_IS_ENTITY_VISIBLE_TO_SCRIPT);
		ENTITY.set_function("_0x3F08C6163A4AB1D6", LUA_NATIVE_ENTITY__0x3F08C6163A4AB1D6);
		ENTITY.set_function("_0x0DB41D59E0F1502B", LUA_NATIVE_ENTITY__0x0DB41D59E0F1502B);
		ENTITY.set_function("_IS_TRACKED_ENTITY_VISIBLE", LUA_NATIVE_ENTITY__IS_TRACKED_ENTITY_VISIBLE);
		ENTITY.set_function("IS_ENTITY_OCCLUDED", LUA_NATIVE_ENTITY_IS_ENTITY_OCCLUDED);
		ENTITY.set_function("WOULD_ENTITY_BE_OCCLUDED", LUA_NATIVE_ENTITY_WOULD_ENTITY_BE_OCCLUDED);
		ENTITY.set_function("IS_ENTITY_WAITING_FOR_WORLD_COLLISION", LUA_NATIVE_ENTITY_IS_ENTITY_WAITING_FOR_WORLD_COLLISION);
		ENTITY.set_function("_IS_ENTITY_ON_TRAIN_TRACK", LUA_NATIVE_ENTITY__IS_ENTITY_ON_TRAIN_TRACK);
		ENTITY.set_function("_0xCDB682BB47C02F0A", LUA_NATIVE_ENTITY__0xCDB682BB47C02F0A);
		ENTITY.set_function("_0xE19035EB65AB2932", LUA_NATIVE_ENTITY__0xE19035EB65AB2932);
		ENTITY.set_function("SCRIPT_OVERRIDE_ENTITY_LOOT_TABLE_PERMANENT", LUA_NATIVE_ENTITY_SCRIPT_OVERRIDE_ENTITY_LOOT_TABLE_PERMANENT);
		ENTITY.set_function("_GET_SCRIPT_OVERRIDE_ENTITY_LOOT_TABLE_PERMANENT", LUA_NATIVE_ENTITY__GET_SCRIPT_OVERRIDE_ENTITY_LOOT_TABLE_PERMANENT);
		ENTITY.set_function("_REQUEST_ENTITY_LOOT_LIST", LUA_NATIVE_ENTITY__REQUEST_ENTITY_LOOT_LIST);
		ENTITY.set_function("_0xE31FC20319874CB3", LUA_NATIVE_ENTITY__0xE31FC20319874CB3);
		ENTITY.set_function("_0x582F73ACFE969571", LUA_NATIVE_ENTITY__0x582F73ACFE969571);
		ENTITY.set_function("_0xBA2A089E60ED1163", LUA_NATIVE_ENTITY__0xBA2A089E60ED1163);
		ENTITY.set_function("GET_CARRIABLE_ENTITY_STATE", LUA_NATIVE_ENTITY_GET_CARRIABLE_ENTITY_STATE);
		ENTITY.set_function("_0xD46BF94C4C66FAB0", LUA_NATIVE_ENTITY__0xD46BF94C4C66FAB0);
		ENTITY.set_function("_GET_OPTIMAL_CARRY_CONFIG", LUA_NATIVE_ENTITY__GET_OPTIMAL_CARRY_CONFIG);
		ENTITY.set_function("_0xD21C7418C590BB40", LUA_NATIVE_ENTITY__0xD21C7418C590BB40);
		ENTITY.set_function("_GET_ENTITY_CARRY_CONFIG", LUA_NATIVE_ENTITY__GET_ENTITY_CARRY_CONFIG);
		ENTITY.set_function("_IS_CARRIABLE_MODEL", LUA_NATIVE_ENTITY__IS_CARRIABLE_MODEL);
		ENTITY.set_function("_GET_CARRIABLE_FROM_ENTITY", LUA_NATIVE_ENTITY__GET_CARRIABLE_FROM_ENTITY);
		ENTITY.set_function("_SET_ENTITY_CARCASS_TYPE", LUA_NATIVE_ENTITY__SET_ENTITY_CARCASS_TYPE);
		ENTITY.set_function("_0x2A77EF9BEC8518F4", LUA_NATIVE_ENTITY__0x2A77EF9BEC8518F4);
		ENTITY.set_function("_DELETE_CARRIABLE", LUA_NATIVE_ENTITY__DELETE_CARRIABLE);
		ENTITY.set_function("_IS_ENTITY_FULLY_LOOTED", LUA_NATIVE_ENTITY__IS_ENTITY_FULLY_LOOTED);
		ENTITY.set_function("_SET_ENTITY_FULLY_LOOTED", LUA_NATIVE_ENTITY__SET_ENTITY_FULLY_LOOTED);
		ENTITY.set_function("_0xEF2D9ED7CE684F08", LUA_NATIVE_ENTITY__0xEF2D9ED7CE684F08);
		ENTITY.set_function("_0x0CCEFC6C2C95DA2A", LUA_NATIVE_ENTITY__0x0CCEFC6C2C95DA2A);
		ENTITY.set_function("_0x383F64263F946E45", LUA_NATIVE_ENTITY__0x383F64263F946E45);
		ENTITY.set_function("_0x8E10DF0FFA63FB65", LUA_NATIVE_ENTITY__0x8E10DF0FFA63FB65);
		ENTITY.set_function("_GET_ENTITY_CARRYING_FLAG", LUA_NATIVE_ENTITY__GET_ENTITY_CARRYING_FLAG);
		ENTITY.set_function("_SET_ENTITY_CARRYING_FLAG", LUA_NATIVE_ENTITY__SET_ENTITY_CARRYING_FLAG);
		ENTITY.set_function("_0xC3ABCFBC7D74AFA5", LUA_NATIVE_ENTITY__0xC3ABCFBC7D74AFA5);
		ENTITY.set_function("_0x371D179701D9C082", LUA_NATIVE_ENTITY__0x371D179701D9C082);
		ENTITY.set_function("_0xA48E4801DEBDF7E4", LUA_NATIVE_ENTITY__0xA48E4801DEBDF7E4);
		ENTITY.set_function("_GET_IS_CARRIABLE_PELT", LUA_NATIVE_ENTITY__GET_IS_CARRIABLE_PELT);
		ENTITY.set_function("_0xF59FDE7B4D31A630", LUA_NATIVE_ENTITY__0xF59FDE7B4D31A630);
		ENTITY.set_function("_0x120376C23F019C6C", LUA_NATIVE_ENTITY__0x120376C23F019C6C);
		ENTITY.set_function("_0x5744562E973E33CD", LUA_NATIVE_ENTITY__0x5744562E973E33CD);
		ENTITY.set_function("_0xDD03FC2089AD093C", LUA_NATIVE_ENTITY__0xDD03FC2089AD093C);
		ENTITY.set_function("_0xB16C780C51E51E2B", LUA_NATIVE_ENTITY__0xB16C780C51E51E2B);
		ENTITY.set_function("_0xEF259AA1E097E0AD", LUA_NATIVE_ENTITY__0xEF259AA1E097E0AD);
		ENTITY.set_function("_0xBD94CECFB2D65119", LUA_NATIVE_ENTITY__0xBD94CECFB2D65119);
		ENTITY.set_function("_SET_ENTITY_CUSTOM_PICKUP_RADIUS", LUA_NATIVE_ENTITY__SET_ENTITY_CUSTOM_PICKUP_RADIUS);
		ENTITY.set_function("_0xE75EEA8DB59A9F39", LUA_NATIVE_ENTITY__0xE75EEA8DB59A9F39);
		ENTITY.set_function("_0x188736456D1DEDE6", LUA_NATIVE_ENTITY__0x188736456D1DEDE6);
		ENTITY.set_function("_0xC6A1A3D63F122DE7", LUA_NATIVE_ENTITY__0xC6A1A3D63F122DE7);
		ENTITY.set_function("APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS", LUA_NATIVE_ENTITY_APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS);
		ENTITY.set_function("APPLY_FORCE_TO_ENTITY", LUA_NATIVE_ENTITY_APPLY_FORCE_TO_ENTITY);
		ENTITY.set_function("ATTACH_ENTITY_TO_ENTITY", LUA_NATIVE_ENTITY_ATTACH_ENTITY_TO_ENTITY);
		ENTITY.set_function("ATTACH_ENTITY_TO_ENTITY_PHYSICALLY", LUA_NATIVE_ENTITY_ATTACH_ENTITY_TO_ENTITY_PHYSICALLY);
		ENTITY.set_function("_ATTACH_ENTITY_TO_COORDS_PHYSICALLY", LUA_NATIVE_ENTITY__ATTACH_ENTITY_TO_COORDS_PHYSICALLY);
		ENTITY.set_function("_0x445D7D8EA66E373E", LUA_NATIVE_ENTITY__0x445D7D8EA66E373E);
		ENTITY.set_function("_0x16908E859C3AB698", LUA_NATIVE_ENTITY__0x16908E859C3AB698);
		ENTITY.set_function("GET_ENTITY_BONE_INDEX_BY_NAME", LUA_NATIVE_ENTITY_GET_ENTITY_BONE_INDEX_BY_NAME);
		ENTITY.set_function("CLEAR_ENTITY_LAST_DAMAGE_ENTITY", LUA_NATIVE_ENTITY_CLEAR_ENTITY_LAST_DAMAGE_ENTITY);
		ENTITY.set_function("DELETE_ENTITY", LUA_NATIVE_ENTITY_DELETE_ENTITY);
		ENTITY.set_function("_DELETE_ENTITY_2", LUA_NATIVE_ENTITY__DELETE_ENTITY_2);
		ENTITY.set_function("DETACH_ENTITY", LUA_NATIVE_ENTITY_DETACH_ENTITY);
		ENTITY.set_function("_IS_ENTITY_FROZEN", LUA_NATIVE_ENTITY__IS_ENTITY_FROZEN);
		ENTITY.set_function("FREEZE_ENTITY_POSITION", LUA_NATIVE_ENTITY_FREEZE_ENTITY_POSITION);
		ENTITY.set_function("SET_ENTITY_SHOULD_FREEZE_WAITING_ON_COLLISION", LUA_NATIVE_ENTITY_SET_ENTITY_SHOULD_FREEZE_WAITING_ON_COLLISION);
		ENTITY.set_function("SET_ENTITY_AS_MISSION_ENTITY", LUA_NATIVE_ENTITY_SET_ENTITY_AS_MISSION_ENTITY);
		ENTITY.set_function("SET_ENTITY_AS_NO_LONGER_NEEDED", LUA_NATIVE_ENTITY_SET_ENTITY_AS_NO_LONGER_NEEDED);
		ENTITY.set_function("SET_PED_AS_NO_LONGER_NEEDED", LUA_NATIVE_ENTITY_SET_PED_AS_NO_LONGER_NEEDED);
		ENTITY.set_function("SET_VEHICLE_AS_NO_LONGER_NEEDED", LUA_NATIVE_ENTITY_SET_VEHICLE_AS_NO_LONGER_NEEDED);
		ENTITY.set_function("SET_OBJECT_AS_NO_LONGER_NEEDED", LUA_NATIVE_ENTITY_SET_OBJECT_AS_NO_LONGER_NEEDED);
		ENTITY.set_function("_0x20FAEE47427A4497", LUA_NATIVE_ENTITY__0x20FAEE47427A4497);
		ENTITY.set_function("_DOES_THREAD_OWN_THIS_ENTITY", LUA_NATIVE_ENTITY__DOES_THREAD_OWN_THIS_ENTITY);
		ENTITY.set_function("_0x56E0735D6273B227", LUA_NATIVE_ENTITY__0x56E0735D6273B227);
		ENTITY.set_function("_0xC0EDEF16D90661EE", LUA_NATIVE_ENTITY__0xC0EDEF16D90661EE);
		ENTITY.set_function("_0x0FD7D7C232876E72", LUA_NATIVE_ENTITY__0x0FD7D7C232876E72);
		ENTITY.set_function("_0x0939E773925C4719", LUA_NATIVE_ENTITY__0x0939E773925C4719);
		ENTITY.set_function("SET_ENTITY_CAN_BE_DAMAGED", LUA_NATIVE_ENTITY_SET_ENTITY_CAN_BE_DAMAGED);
		ENTITY.set_function("_GET_ENTITY_CAN_BE_DAMAGED", LUA_NATIVE_ENTITY__GET_ENTITY_CAN_BE_DAMAGED);
		ENTITY.set_function("SET_ENTITY_CAN_BE_DAMAGED_BY_RELATIONSHIP_GROUP", LUA_NATIVE_ENTITY_SET_ENTITY_CAN_BE_DAMAGED_BY_RELATIONSHIP_GROUP);
		ENTITY.set_function("_0xFF83AF534156B399", LUA_NATIVE_ENTITY__0xFF83AF534156B399);
		ENTITY.set_function("SET_ENTITY_CAN_BE_TARGETED_WITHOUT_LOS", LUA_NATIVE_ENTITY_SET_ENTITY_CAN_BE_TARGETED_WITHOUT_LOS);
		ENTITY.set_function("GET_ENTITY_COLLISION_DISABLED", LUA_NATIVE_ENTITY_GET_ENTITY_COLLISION_DISABLED);
		ENTITY.set_function("SET_ENTITY_COLLISION", LUA_NATIVE_ENTITY_SET_ENTITY_COLLISION);
		ENTITY.set_function("SET_ENTITY_COMPLETELY_DISABLE_COLLISION", LUA_NATIVE_ENTITY_SET_ENTITY_COMPLETELY_DISABLE_COLLISION);
		ENTITY.set_function("SET_ENTITY_COORDS", LUA_NATIVE_ENTITY_SET_ENTITY_COORDS);
		ENTITY.set_function("SET_ENTITY_COORDS_NO_OFFSET", LUA_NATIVE_ENTITY_SET_ENTITY_COORDS_NO_OFFSET);
		ENTITY.set_function("SET_ENTITY_DYNAMIC", LUA_NATIVE_ENTITY_SET_ENTITY_DYNAMIC);
		ENTITY.set_function("SET_ENTITY_HEADING", LUA_NATIVE_ENTITY_SET_ENTITY_HEADING);
		ENTITY.set_function("_SET_ENTITY_COORDS_AND_HEADING", LUA_NATIVE_ENTITY__SET_ENTITY_COORDS_AND_HEADING);
		ENTITY.set_function("_SET_ENTITY_COORDS_AND_HEADING_NO_OFFSET", LUA_NATIVE_ENTITY__SET_ENTITY_COORDS_AND_HEADING_NO_OFFSET);
		ENTITY.set_function("SET_ENTITY_HEALTH", LUA_NATIVE_ENTITY_SET_ENTITY_HEALTH);
		ENTITY.set_function("SET_ENTITY_INVINCIBLE", LUA_NATIVE_ENTITY_SET_ENTITY_INVINCIBLE);
		ENTITY.set_function("_0xAF7F3099B9FEB535", LUA_NATIVE_ENTITY__0xAF7F3099B9FEB535);
		ENTITY.set_function("SET_ENTITY_IS_TARGET_PRIORITY", LUA_NATIVE_ENTITY_SET_ENTITY_IS_TARGET_PRIORITY);
		ENTITY.set_function("_0xB38A29CCD5447783", LUA_NATIVE_ENTITY__0xB38A29CCD5447783);
		ENTITY.set_function("_SET_ENTITY_THREAT_TIER", LUA_NATIVE_ENTITY__SET_ENTITY_THREAT_TIER);
		ENTITY.set_function("_GET_ENTITY_THREAT_TIER", LUA_NATIVE_ENTITY__GET_ENTITY_THREAT_TIER);
		ENTITY.set_function("_0x2D40BCBFE9305DEA", LUA_NATIVE_ENTITY__0x2D40BCBFE9305DEA);
		ENTITY.set_function("_SET_ENTITY_LIGHTS_ENABLED", LUA_NATIVE_ENTITY__SET_ENTITY_LIGHTS_ENABLED);
		ENTITY.set_function("SET_ENTITY_LOAD_COLLISION_FLAG", LUA_NATIVE_ENTITY_SET_ENTITY_LOAD_COLLISION_FLAG);
		ENTITY.set_function("HAS_COLLISION_LOADED_AROUND_ENTITY", LUA_NATIVE_ENTITY_HAS_COLLISION_LOADED_AROUND_ENTITY);
		ENTITY.set_function("HAS_COLLISION_LOADED_AROUND_POSITION", LUA_NATIVE_ENTITY_HAS_COLLISION_LOADED_AROUND_POSITION);
		ENTITY.set_function("SET_ENTITY_ONLY_DAMAGED_BY_PLAYER", LUA_NATIVE_ENTITY_SET_ENTITY_ONLY_DAMAGED_BY_PLAYER);
		ENTITY.set_function("SET_ENTITY_ONLY_DAMAGED_BY_RELATIONSHIP_GROUP", LUA_NATIVE_ENTITY_SET_ENTITY_ONLY_DAMAGED_BY_RELATIONSHIP_GROUP);
		ENTITY.set_function("SET_ENTITY_PROOFS", LUA_NATIVE_ENTITY_SET_ENTITY_PROOFS);
		ENTITY.set_function("_GET_ENTITY_PROOFS", LUA_NATIVE_ENTITY__GET_ENTITY_PROOFS);
		ENTITY.set_function("SET_ENTITY_QUATERNION", LUA_NATIVE_ENTITY_SET_ENTITY_QUATERNION);
		ENTITY.set_function("SET_ENTITY_ROTATION", LUA_NATIVE_ENTITY_SET_ENTITY_ROTATION);
		ENTITY.set_function("_0xD45BB89B53FC0CFD", LUA_NATIVE_ENTITY__0xD45BB89B53FC0CFD);
		ENTITY.set_function("SET_ENTITY_VISIBLE", LUA_NATIVE_ENTITY_SET_ENTITY_VISIBLE);
		ENTITY.set_function("_0x80FDEB3A9E9AA578", LUA_NATIVE_ENTITY__0x80FDEB3A9E9AA578);
		ENTITY.set_function("_0x9C6906EF8CB20C5F", LUA_NATIVE_ENTITY__0x9C6906EF8CB20C5F);
		ENTITY.set_function("SET_ENTITY_VELOCITY", LUA_NATIVE_ENTITY_SET_ENTITY_VELOCITY);
		ENTITY.set_function("SET_ENTITY_HAS_GRAVITY", LUA_NATIVE_ENTITY_SET_ENTITY_HAS_GRAVITY);
		ENTITY.set_function("SET_ENTITY_LOD_DIST", LUA_NATIVE_ENTITY_SET_ENTITY_LOD_DIST);
		ENTITY.set_function("GET_ENTITY_LOD_DIST", LUA_NATIVE_ENTITY_GET_ENTITY_LOD_DIST);
		ENTITY.set_function("SET_ENTITY_ALPHA", LUA_NATIVE_ENTITY_SET_ENTITY_ALPHA);
		ENTITY.set_function("GET_ENTITY_ALPHA", LUA_NATIVE_ENTITY_GET_ENTITY_ALPHA);
		ENTITY.set_function("RESET_ENTITY_ALPHA", LUA_NATIVE_ENTITY_RESET_ENTITY_ALPHA);
		ENTITY.set_function("_SET_ENTITY_FADE_IN", LUA_NATIVE_ENTITY__SET_ENTITY_FADE_IN);
		ENTITY.set_function("SET_ENTITY_ALWAYS_PRERENDER", LUA_NATIVE_ENTITY_SET_ENTITY_ALWAYS_PRERENDER);
		ENTITY.set_function("SET_ENTITY_RENDER_SCORCHED", LUA_NATIVE_ENTITY_SET_ENTITY_RENDER_SCORCHED);
		ENTITY.set_function("_0x37B01666BAE8F7EF", LUA_NATIVE_ENTITY__0x37B01666BAE8F7EF);
		ENTITY.set_function("_0xA9E6D8F2DDFC4DB9", LUA_NATIVE_ENTITY__0xA9E6D8F2DDFC4DB9);
		ENTITY.set_function("CREATE_MODEL_SWAP", LUA_NATIVE_ENTITY_CREATE_MODEL_SWAP);
		ENTITY.set_function("REMOVE_MODEL_SWAP", LUA_NATIVE_ENTITY_REMOVE_MODEL_SWAP);
		ENTITY.set_function("CREATE_MODEL_HIDE", LUA_NATIVE_ENTITY_CREATE_MODEL_HIDE);
		ENTITY.set_function("CREATE_MODEL_HIDE_EXCLUDING_SCRIPT_OBJECTS", LUA_NATIVE_ENTITY_CREATE_MODEL_HIDE_EXCLUDING_SCRIPT_OBJECTS);
		ENTITY.set_function("REMOVE_MODEL_HIDE", LUA_NATIVE_ENTITY_REMOVE_MODEL_HIDE);
		ENTITY.set_function("_0xD4636C2EDB0DEA8A", LUA_NATIVE_ENTITY__0xD4636C2EDB0DEA8A);
		ENTITY.set_function("CREATE_FORCED_OBJECT", LUA_NATIVE_ENTITY_CREATE_FORCED_OBJECT);
		ENTITY.set_function("REMOVE_FORCED_OBJECT", LUA_NATIVE_ENTITY_REMOVE_FORCED_OBJECT);
		ENTITY.set_function("SET_ENTITY_NO_COLLISION_ENTITY", LUA_NATIVE_ENTITY_SET_ENTITY_NO_COLLISION_ENTITY);
		ENTITY.set_function("SET_ENTITY_MOTION_BLUR", LUA_NATIVE_ENTITY_SET_ENTITY_MOTION_BLUR);
		ENTITY.set_function("SET_CAN_AUTO_VAULT_ON_ENTITY", LUA_NATIVE_ENTITY_SET_CAN_AUTO_VAULT_ON_ENTITY);
		ENTITY.set_function("SET_CAN_CLIMB_ON_ENTITY", LUA_NATIVE_ENTITY_SET_CAN_CLIMB_ON_ENTITY);
		ENTITY.set_function("SET_ENTITY_NOWEAPONDECALS", LUA_NATIVE_ENTITY_SET_ENTITY_NOWEAPONDECALS);
		ENTITY.set_function("_GET_ENTITIES_NEAR_POINT", LUA_NATIVE_ENTITY__GET_ENTITIES_NEAR_POINT);
		ENTITY.set_function("GET_MATCHING_ENTITIES", LUA_NATIVE_ENTITY_GET_MATCHING_ENTITIES);
		ENTITY.set_function("_GET_ENTITIES_IN_VOLUME", LUA_NATIVE_ENTITY__GET_ENTITIES_IN_VOLUME);
		ENTITY.set_function("_SEARCH_BUILDING_POOL_FOR_ENTITY_WITH_THIS_MODEL", LUA_NATIVE_ENTITY__SEARCH_BUILDING_POOL_FOR_ENTITY_WITH_THIS_MODEL);
		ENTITY.set_function("_0xC2E71D7E0A7B4C89", LUA_NATIVE_ENTITY__0xC2E71D7E0A7B4C89);
		ENTITY.set_function("_0x6C31B06E91518269", LUA_NATIVE_ENTITY__0x6C31B06E91518269);
		ENTITY.set_function("_0x119A5714578F4E05", LUA_NATIVE_ENTITY__0x119A5714578F4E05);
		ENTITY.set_function("_GET_ENTITY_BY_DOORHASH", LUA_NATIVE_ENTITY__GET_ENTITY_BY_DOORHASH);
		ENTITY.set_function("FIND_ANIM_EVENT_PHASE", LUA_NATIVE_ENTITY_FIND_ANIM_EVENT_PHASE);
		ENTITY.set_function("FORCE_ENTITY_AI_AND_ANIMATION_UPDATE", LUA_NATIVE_ENTITY_FORCE_ENTITY_AI_AND_ANIMATION_UPDATE);
		ENTITY.set_function("_GET_ENTITY_ANIM_CURRENT_TIME", LUA_NATIVE_ENTITY__GET_ENTITY_ANIM_CURRENT_TIME);
		ENTITY.set_function("_0x8E46E18AA828334F", LUA_NATIVE_ENTITY__0x8E46E18AA828334F);
		ENTITY.set_function("_0xDF8E49EA89A01DB1", LUA_NATIVE_ENTITY__0xDF8E49EA89A01DB1);
		ENTITY.set_function("HAS_ANIM_EVENT_FIRED", LUA_NATIVE_ENTITY_HAS_ANIM_EVENT_FIRED);
		ENTITY.set_function("HAS_ENTITY_ANIM_FINISHED", LUA_NATIVE_ENTITY_HAS_ENTITY_ANIM_FINISHED);
		ENTITY.set_function("PLAY_ENTITY_ANIM", LUA_NATIVE_ENTITY_PLAY_ENTITY_ANIM);
		ENTITY.set_function("_SET_ENTITY_ANIM_CURRENT_TIME", LUA_NATIVE_ENTITY__SET_ENTITY_ANIM_CURRENT_TIME);
		ENTITY.set_function("_SET_ENTITY_ANIM_SPEED", LUA_NATIVE_ENTITY__SET_ENTITY_ANIM_SPEED);
		ENTITY.set_function("STOP_ENTITY_ANIM", LUA_NATIVE_ENTITY_STOP_ENTITY_ANIM);
		ENTITY.set_function("_0x669655FFB29EF1A9", LUA_NATIVE_ENTITY__0x669655FFB29EF1A9);
		ENTITY.set_function("_ADD_ENTITY_TRACKING_TRAILS", LUA_NATIVE_ENTITY__ADD_ENTITY_TRACKING_TRAILS);
		ENTITY.set_function("_0x5826EFD6D73C4DE5", LUA_NATIVE_ENTITY__0x5826EFD6D73C4DE5);
		ENTITY.set_function("_PAUSE_ENTITY_TRACKING", LUA_NATIVE_ENTITY__PAUSE_ENTITY_TRACKING);
		ENTITY.set_function("_CREATE_FOOTPATH_TRAIL", LUA_NATIVE_ENTITY__CREATE_FOOTPATH_TRAIL);
		ENTITY.set_function("_0xC76E94A78127412B", LUA_NATIVE_ENTITY__0xC76E94A78127412B);
		ENTITY.set_function("_0x7F20092547B4DDEA", LUA_NATIVE_ENTITY__0x7F20092547B4DDEA);
		ENTITY.set_function("_0xF41E2979D5BC5370", LUA_NATIVE_ENTITY__0xF41E2979D5BC5370);
		ENTITY.set_function("_0xAAACB74442C1BED3", LUA_NATIVE_ENTITY__0xAAACB74442C1BED3);
		ENTITY.set_function("PIN_CLOSEST_MAP_ENTITY", LUA_NATIVE_ENTITY_PIN_CLOSEST_MAP_ENTITY);
		ENTITY.set_function("_UNPIN_MAP_ENTITY", LUA_NATIVE_ENTITY__UNPIN_MAP_ENTITY);
		ENTITY.set_function("IS_MAP_ENTITY_PINNED", LUA_NATIVE_ENTITY_IS_MAP_ENTITY_PINNED);
		ENTITY.set_function("_GET_PINNED_MAP_ENTITY", LUA_NATIVE_ENTITY__GET_PINNED_MAP_ENTITY);
		ENTITY.set_function("_0xEAB3D91D30A344F1", LUA_NATIVE_ENTITY__0xEAB3D91D30A344F1);
		ENTITY.set_function("_0x37CEB637BA3B1A47", LUA_NATIVE_ENTITY__0x37CEB637BA3B1A47);
		ENTITY.set_function("_0x350E9211074955AF", LUA_NATIVE_ENTITY__0x350E9211074955AF);
		ENTITY.set_function("_0x898586729DB5221D", LUA_NATIVE_ENTITY__0x898586729DB5221D);
		ENTITY.set_function("_0xE9E7A0BAC7F57746", LUA_NATIVE_ENTITY__0xE9E7A0BAC7F57746);
	}
}
