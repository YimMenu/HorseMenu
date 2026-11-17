#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static FireId LUA_NATIVE_FIRE_START_SCRIPT_FIRE(float VecPosX, float VecPosY, float VecPosZ, int GenerationsAllowed, float p4, bool p5, sol::stack_object soundsetName, float p7, int p8)
	{
		auto retval = FIRE::START_SCRIPT_FIRE(VecPosX, VecPosY, VecPosZ, GenerationsAllowed, p4, p5, soundsetName.is<const char*>() ? soundsetName.as<const char*>() : nullptr, p7, p8);
		return retval;
	}

	static void LUA_NATIVE_FIRE_REMOVE_SCRIPT_FIRE(FireId FireIndex)
	{
		FIRE::REMOVE_SCRIPT_FIRE(FireIndex);
	}

	static void LUA_NATIVE_FIRE_START_ENTITY_FIRE(Entity EntityIndex, Any p1, Any p2, Any p3)
	{
		FIRE::START_ENTITY_FIRE(EntityIndex, p1, p2, p3);
	}

	static void LUA_NATIVE_FIRE_STOP_ENTITY_FIRE(Entity EntityIndex, Any p1)
	{
		FIRE::STOP_ENTITY_FIRE(EntityIndex, p1);
	}

	static bool LUA_NATIVE_FIRE_IS_ENTITY_ON_FIRE(Entity EntityIndex)
	{
		auto retval = (bool)FIRE::IS_ENTITY_ON_FIRE(EntityIndex);
		return retval;
	}

	static void LUA_NATIVE_FIRE__0x754937C28271BC65(Any p0)
	{
		FIRE::_0x754937C28271BC65(p0);
	}

	static int LUA_NATIVE_FIRE_GET_NUMBER_OF_FIRES_IN_RANGE(float VecPosX, float VecPosY, float VecPosZ, float Radius)
	{
		auto retval = FIRE::GET_NUMBER_OF_FIRES_IN_RANGE(VecPosX, VecPosY, VecPosZ, Radius);
		return retval;
	}

	static void LUA_NATIVE_FIRE_STOP_FIRE_IN_RANGE(float VecPosX, float VecPosY, float VecPosZ, float fRadius)
	{
		FIRE::STOP_FIRE_IN_RANGE(VecPosX, VecPosY, VecPosZ, fRadius);
	}

	static void LUA_NATIVE_FIRE__STOP_FIRE_IN_BOX(float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ)
	{
		FIRE::_STOP_FIRE_IN_BOX(posX, posY, posZ, rotX, rotY, rotZ, scaleX, scaleY, scaleZ);
	}

	static std::tuple<bool, Vector3> LUA_NATIVE_FIRE_GET_CLOSEST_FIRE_POS(Vector3 VecClosestFirePos, float VecTestPosX, float VecTestPosY, float VecTestPosZ)
	{
		std::tuple<bool, Vector3> return_values;
		std::get<0>(return_values) = (bool)FIRE::GET_CLOSEST_FIRE_POS(&VecClosestFirePos, VecTestPosX, VecTestPosY, VecTestPosZ);
		std::get<1>(return_values) = VecClosestFirePos;

		return return_values;
	}

	static Any LUA_NATIVE_FIRE__0x559FC1D310813031(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9)
	{
		auto retval = FIRE::_0x559FC1D310813031(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
		return retval;
	}

	static Any LUA_NATIVE_FIRE__0x41B87A6495EE13DD(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9)
	{
		auto retval = FIRE::_0x41B87A6495EE13DD(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
		return retval;
	}

	static Any LUA_NATIVE_FIRE__0xA4454592DCF7C992(Any p0)
	{
		auto retval = FIRE::_0xA4454592DCF7C992(p0);
		return retval;
	}

	static bool LUA_NATIVE_FIRE__IS_ENTITY_CONSUMED_BY_FIRE(Entity entity)
	{
		auto retval = (bool)FIRE::_IS_ENTITY_CONSUMED_BY_FIRE(entity);
		return retval;
	}

	static void LUA_NATIVE_FIRE_ADD_EXPLOSION(float VecExplosionPosX, float VecExplosionPosY, float VecExplosionPosZ, int ExplosionTag, float SizeScale, bool bMakeSound, bool bNoFx, float CamShakeMultiplier)
	{
		FIRE::ADD_EXPLOSION(VecExplosionPosX, VecExplosionPosY, VecExplosionPosZ, ExplosionTag, SizeScale, bMakeSound, bNoFx, CamShakeMultiplier);
	}

	static void LUA_NATIVE_FIRE_ADD_OWNED_EXPLOSION(Entity ExplosionOwner, float VecExplosionPosX, float VecExplosionPosY, float VecExplosionPosZ, int ExplosionTag, float SizeScale, bool bMakeSound, bool bNoFx, float CamShakeMultiplier)
	{
		FIRE::ADD_OWNED_EXPLOSION(ExplosionOwner, VecExplosionPosX, VecExplosionPosY, VecExplosionPosZ, ExplosionTag, SizeScale, bMakeSound, bNoFx, CamShakeMultiplier);
	}

	static void LUA_NATIVE_FIRE__0xB7DF150605EEDC9B(Entity entity, int p1, float x, float y, float z, int explosionType, float damageScale, bool isAudible, bool isInvisible, float cameraShake)
	{
		FIRE::_0xB7DF150605EEDC9B(entity, p1, x, y, z, explosionType, damageScale, isAudible, isInvisible, cameraShake);
	}

	static void LUA_NATIVE_FIRE_ADD_EXPLOSION_WITH_USER_VFX(float VecExplosionPosX, float VecExplosionPosY, float VecExplosionPosZ, int ExplosionTag, Hash VfxTagHash, float SizeScale, bool bMakeSound, bool bNoFx, float CamShakeMultiplier)
	{
		FIRE::ADD_EXPLOSION_WITH_USER_VFX(VecExplosionPosX, VecExplosionPosY, VecExplosionPosZ, ExplosionTag, VfxTagHash, SizeScale, bMakeSound, bNoFx, CamShakeMultiplier);
	}

	static void LUA_NATIVE_FIRE__0x34AE85C7CA4857AA(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10)
	{
		FIRE::_0x34AE85C7CA4857AA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
	}

	static bool LUA_NATIVE_FIRE_IS_EXPLOSION_IN_AREA(int ExplosionTag, float VecPosMinX, float VecPosMinY, float VecPosMinZ, float VecPosMaxX, float VecPosMaxY, float VecPosMaxZ)
	{
		auto retval = (bool)FIRE::IS_EXPLOSION_IN_AREA(ExplosionTag, VecPosMinX, VecPosMinY, VecPosMinZ, VecPosMaxX, VecPosMaxY, VecPosMaxZ);
		return retval;
	}

	static bool LUA_NATIVE_FIRE_IS_EXPLOSION_ACTIVE_IN_AREA(int ExplosionTag, float VecPosMinX, float VecPosMinY, float VecPosMinZ, float VecPosMaxX, float VecPosMaxY, float VecPosMaxZ)
	{
		auto retval = (bool)FIRE::IS_EXPLOSION_ACTIVE_IN_AREA(ExplosionTag, VecPosMinX, VecPosMinY, VecPosMinZ, VecPosMaxX, VecPosMaxY, VecPosMaxZ);
		return retval;
	}

	static bool LUA_NATIVE_FIRE_IS_EXPLOSION_IN_SPHERE(int ExplosionTag, float VecCentrePosX, float VecCentrePosY, float VecCentrePosZ, float Radius)
	{
		auto retval = (bool)FIRE::IS_EXPLOSION_IN_SPHERE(ExplosionTag, VecCentrePosX, VecCentrePosY, VecCentrePosZ, Radius);
		return retval;
	}

	static bool LUA_NATIVE_FIRE_IS_EXPLOSION_IN_ANGLED_AREA(int ExplosionTag, float VecPos1X, float VecPos1Y, float VecPos1Z, float VecPos2X, float VecPos2Y, float VecPos2Z, float AreaWidth)
	{
		auto retval = (bool)FIRE::IS_EXPLOSION_IN_ANGLED_AREA(ExplosionTag, VecPos1X, VecPos1Y, VecPos1Z, VecPos2X, VecPos2Y, VecPos2Z, AreaWidth);
		return retval;
	}

	static bool LUA_NATIVE_FIRE__IS_EXPLOSION_IN_VOLUME(int explosionType, Volume volume)
	{
		auto retval = (bool)FIRE::_IS_EXPLOSION_IN_VOLUME(explosionType, volume);
		return retval;
	}

	static Entity LUA_NATIVE_FIRE_GET_OWNER_OF_EXPLOSION_IN_ANGLED_AREA(int ExplosionTag, float VecPos1X, float VecPos1Y, float VecPos1Z, float VecPos2X, float VecPos2Y, float VecPos2Z, float AreaWidth)
	{
		auto retval = FIRE::GET_OWNER_OF_EXPLOSION_IN_ANGLED_AREA(ExplosionTag, VecPos1X, VecPos1Y, VecPos1Z, VecPos2X, VecPos2Y, VecPos2Z, AreaWidth);
		return retval;
	}

	static void LUA_NATIVE_FIRE__0x68F6A75FDF5A70D6(float x, float y, float z, float p3)
	{
		FIRE::_0x68F6A75FDF5A70D6(x, y, z, p3);
	}

	static void LUA_NATIVE_FIRE__0x24DB6B9F2B719043(float p0)
	{
		FIRE::_0x24DB6B9F2B719043(p0);
	}

	static bool LUA_NATIVE_FIRE__IS_PED_SHOCKING_EVENT_ACTIVE(Ped ped, int p1)
	{
		auto retval = (bool)FIRE::_IS_PED_SHOCKING_EVENT_ACTIVE(ped, p1);
		return retval;
	}

	void RegisterNatives_FIRE(sol::state& L)
	{
		auto FIRE = L["FIRE"].get_or_create<sol::table>();
		FIRE.set_function("START_SCRIPT_FIRE", LUA_NATIVE_FIRE_START_SCRIPT_FIRE);
		FIRE.set_function("REMOVE_SCRIPT_FIRE", LUA_NATIVE_FIRE_REMOVE_SCRIPT_FIRE);
		FIRE.set_function("START_ENTITY_FIRE", LUA_NATIVE_FIRE_START_ENTITY_FIRE);
		FIRE.set_function("STOP_ENTITY_FIRE", LUA_NATIVE_FIRE_STOP_ENTITY_FIRE);
		FIRE.set_function("IS_ENTITY_ON_FIRE", LUA_NATIVE_FIRE_IS_ENTITY_ON_FIRE);
		FIRE.set_function("_0x754937C28271BC65", LUA_NATIVE_FIRE__0x754937C28271BC65);
		FIRE.set_function("GET_NUMBER_OF_FIRES_IN_RANGE", LUA_NATIVE_FIRE_GET_NUMBER_OF_FIRES_IN_RANGE);
		FIRE.set_function("STOP_FIRE_IN_RANGE", LUA_NATIVE_FIRE_STOP_FIRE_IN_RANGE);
		FIRE.set_function("_STOP_FIRE_IN_BOX", LUA_NATIVE_FIRE__STOP_FIRE_IN_BOX);
		FIRE.set_function("GET_CLOSEST_FIRE_POS", LUA_NATIVE_FIRE_GET_CLOSEST_FIRE_POS);
		FIRE.set_function("_0x559FC1D310813031", LUA_NATIVE_FIRE__0x559FC1D310813031);
		FIRE.set_function("_0x41B87A6495EE13DD", LUA_NATIVE_FIRE__0x41B87A6495EE13DD);
		FIRE.set_function("_0xA4454592DCF7C992", LUA_NATIVE_FIRE__0xA4454592DCF7C992);
		FIRE.set_function("_IS_ENTITY_CONSUMED_BY_FIRE", LUA_NATIVE_FIRE__IS_ENTITY_CONSUMED_BY_FIRE);
		FIRE.set_function("ADD_EXPLOSION", LUA_NATIVE_FIRE_ADD_EXPLOSION);
		FIRE.set_function("ADD_OWNED_EXPLOSION", LUA_NATIVE_FIRE_ADD_OWNED_EXPLOSION);
		FIRE.set_function("_0xB7DF150605EEDC9B", LUA_NATIVE_FIRE__0xB7DF150605EEDC9B);
		FIRE.set_function("ADD_EXPLOSION_WITH_USER_VFX", LUA_NATIVE_FIRE_ADD_EXPLOSION_WITH_USER_VFX);
		FIRE.set_function("_0x34AE85C7CA4857AA", LUA_NATIVE_FIRE__0x34AE85C7CA4857AA);
		FIRE.set_function("IS_EXPLOSION_IN_AREA", LUA_NATIVE_FIRE_IS_EXPLOSION_IN_AREA);
		FIRE.set_function("IS_EXPLOSION_ACTIVE_IN_AREA", LUA_NATIVE_FIRE_IS_EXPLOSION_ACTIVE_IN_AREA);
		FIRE.set_function("IS_EXPLOSION_IN_SPHERE", LUA_NATIVE_FIRE_IS_EXPLOSION_IN_SPHERE);
		FIRE.set_function("IS_EXPLOSION_IN_ANGLED_AREA", LUA_NATIVE_FIRE_IS_EXPLOSION_IN_ANGLED_AREA);
		FIRE.set_function("_IS_EXPLOSION_IN_VOLUME", LUA_NATIVE_FIRE__IS_EXPLOSION_IN_VOLUME);
		FIRE.set_function("GET_OWNER_OF_EXPLOSION_IN_ANGLED_AREA", LUA_NATIVE_FIRE_GET_OWNER_OF_EXPLOSION_IN_ANGLED_AREA);
		FIRE.set_function("_0x68F6A75FDF5A70D6", LUA_NATIVE_FIRE__0x68F6A75FDF5A70D6);
		FIRE.set_function("_0x24DB6B9F2B719043", LUA_NATIVE_FIRE__0x24DB6B9F2B719043);
		FIRE.set_function("_IS_PED_SHOCKING_EVENT_ACTIVE", LUA_NATIVE_FIRE__IS_PED_SHOCKING_EVENT_ACTIVE);
	}
}
