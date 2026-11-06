#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static bool LUA_NATIVE_INTERIOR_IS_VALID_INTERIOR(Interior InteriorInstanceIndex)
	{
		auto retval = (bool)INTERIOR::IS_VALID_INTERIOR(InteriorInstanceIndex);
		return retval;
	}

	static std::tuple<Vector3, Hash> LUA_NATIVE_INTERIOR_GET_INTERIOR_LOCATION_AND_NAMEHASH(Interior interior, Vector3 position, Hash nameHash)
	{
		std::tuple<Vector3, Hash> return_values;
		INTERIOR::GET_INTERIOR_LOCATION_AND_NAMEHASH(interior, &position, &nameHash);
		std::get<0>(return_values) = position;
		std::get<1>(return_values) = nameHash;

		return return_values;
	}

	static Hash LUA_NATIVE_INTERIOR__GET_INTERIOR_MINIMAP_HASH(Interior interior)
	{
		auto retval = INTERIOR::_GET_INTERIOR_MINIMAP_HASH(interior);
		return retval;
	}

	static Vector3 LUA_NATIVE_INTERIOR__GET_INTERIOR_POSITION(Interior interior)
	{
		auto retval = INTERIOR::_GET_INTERIOR_POSITION(interior);
		return retval;
	}

	static bool LUA_NATIVE_INTERIOR_IS_INTERIOR_SCENE()
	{
		auto retval = (bool)INTERIOR::IS_INTERIOR_SCENE();
		return retval;
	}

	static void LUA_NATIVE_INTERIOR_CLEAR_ROOM_FOR_ENTITY(Entity EntityIndex)
	{
		INTERIOR::CLEAR_ROOM_FOR_ENTITY(EntityIndex);
	}

	static void LUA_NATIVE_INTERIOR_FORCE_ROOM_FOR_ENTITY(Entity EntityIndex, Interior InteriorInstanceIndex, Hash RoomKey)
	{
		INTERIOR::FORCE_ROOM_FOR_ENTITY(EntityIndex, InteriorInstanceIndex, RoomKey);
	}

	static Hash LUA_NATIVE_INTERIOR_GET_ROOM_KEY_FROM_ENTITY(Entity EntityIndex)
	{
		auto retval = INTERIOR::GET_ROOM_KEY_FROM_ENTITY(EntityIndex);
		return retval;
	}

	static Hash LUA_NATIVE_INTERIOR_GET_KEY_FOR_ENTITY_IN_ROOM(Entity EntityIndex)
	{
		auto retval = INTERIOR::GET_KEY_FOR_ENTITY_IN_ROOM(EntityIndex);
		return retval;
	}

	static Interior LUA_NATIVE_INTERIOR_GET_INTERIOR_FROM_ENTITY(Entity EntityIndex)
	{
		auto retval = INTERIOR::GET_INTERIOR_FROM_ENTITY(EntityIndex);
		return retval;
	}

	static void LUA_NATIVE_INTERIOR_RETAIN_ENTITY_IN_INTERIOR(Entity EntityIndex, Interior InteriorInstanceIndex)
	{
		INTERIOR::RETAIN_ENTITY_IN_INTERIOR(EntityIndex, InteriorInstanceIndex);
	}

	static void LUA_NATIVE_INTERIOR_FORCE_ROOM_FOR_GAME_VIEWPORT(Interior InteriorInstanceIndex, Hash RoomKey)
	{
		INTERIOR::FORCE_ROOM_FOR_GAME_VIEWPORT(InteriorInstanceIndex, RoomKey);
	}

	static void LUA_NATIVE_INTERIOR_CLEAR_ROOM_FOR_GAME_VIEWPORT()
	{
		INTERIOR::CLEAR_ROOM_FOR_GAME_VIEWPORT();
	}

	static Interior LUA_NATIVE_INTERIOR_GET_INTERIOR_FROM_PRIMARY_VIEW()
	{
		auto retval = INTERIOR::GET_INTERIOR_FROM_PRIMARY_VIEW();
		return retval;
	}

	static Interior LUA_NATIVE_INTERIOR_GET_INTERIOR_AT_COORDS(float VecInCoorsX, float VecInCoorsY, float VecInCoorsZ)
	{
		auto retval = INTERIOR::GET_INTERIOR_AT_COORDS(VecInCoorsX, VecInCoorsY, VecInCoorsZ);
		return retval;
	}

	static void LUA_NATIVE_INTERIOR_PIN_INTERIOR_IN_MEMORY(Interior InteriorInstanceIndex)
	{
		INTERIOR::PIN_INTERIOR_IN_MEMORY(InteriorInstanceIndex);
	}

	static void LUA_NATIVE_INTERIOR_UNPIN_INTERIOR(Interior InteriorInstanceIndex)
	{
		INTERIOR::UNPIN_INTERIOR(InteriorInstanceIndex);
	}

	static bool LUA_NATIVE_INTERIOR_IS_INTERIOR_READY(Interior InteriorInstanceIndex)
	{
		auto retval = (bool)INTERIOR::IS_INTERIOR_READY(InteriorInstanceIndex);
		return retval;
	}

	static bool LUA_NATIVE_INTERIOR_SET_INTERIOR_IN_USE(Interior InteriorInstanceIndex)
	{
		auto retval = (bool)INTERIOR::SET_INTERIOR_IN_USE(InteriorInstanceIndex);
		return retval;
	}

	static Interior LUA_NATIVE_INTERIOR_GET_INTERIOR_AT_COORDS_WITH_TYPE(float VecInCoorsX, float VecInCoorsY, float VecInCoorsZ, sol::stack_object Name)
	{
		auto retval = INTERIOR::GET_INTERIOR_AT_COORDS_WITH_TYPE(VecInCoorsX, VecInCoorsY, VecInCoorsZ, Name.is<const char*>() ? Name.as<const char*>() : nullptr);
		return retval;
	}

	static Interior LUA_NATIVE_INTERIOR_GET_INTERIOR_AT_COORDS_WITH_TYPEHASH(float VecInCoorsX, float VecInCoorsY, float VecInCoorsZ, Hash NameHash)
	{
		auto retval = INTERIOR::GET_INTERIOR_AT_COORDS_WITH_TYPEHASH(VecInCoorsX, VecInCoorsY, VecInCoorsZ, NameHash);
		return retval;
	}

	static bool LUA_NATIVE_INTERIOR_IS_COLLISION_MARKED_OUTSIDE(float VecInCoorsX, float VecInCoorsY, float VecInCoorsZ)
	{
		auto retval = (bool)INTERIOR::IS_COLLISION_MARKED_OUTSIDE(VecInCoorsX, VecInCoorsY, VecInCoorsZ);
		return retval;
	}

	static Interior LUA_NATIVE_INTERIOR_GET_INTERIOR_FROM_COLLISION(float VecInCoorsX, float VecInCoorsY, float VecInCoorsZ)
	{
		auto retval = INTERIOR::GET_INTERIOR_FROM_COLLISION(VecInCoorsX, VecInCoorsY, VecInCoorsZ);
		return retval;
	}

	static void LUA_NATIVE_INTERIOR_ACTIVATE_INTERIOR_ENTITY_SET(Interior InteriorInstanceIndex, sol::stack_object entitySetName, int p2)
	{
		INTERIOR::ACTIVATE_INTERIOR_ENTITY_SET(InteriorInstanceIndex, entitySetName.is<const char*>() ? entitySetName.as<const char*>() : nullptr, p2);
	}

	static void LUA_NATIVE_INTERIOR_DEACTIVATE_INTERIOR_ENTITY_SET(Interior InteriorInstanceIndex, sol::stack_object entitySetName, bool p2)
	{
		INTERIOR::DEACTIVATE_INTERIOR_ENTITY_SET(InteriorInstanceIndex, entitySetName.is<const char*>() ? entitySetName.as<const char*>() : nullptr, p2);
	}

	static bool LUA_NATIVE_INTERIOR_IS_INTERIOR_ENTITY_SET_ACTIVE(Interior InteriorInstanceIndex, sol::stack_object entitySetName)
	{
		auto retval = (bool)INTERIOR::IS_INTERIOR_ENTITY_SET_ACTIVE(InteriorInstanceIndex, entitySetName.is<const char*>() ? entitySetName.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_INTERIOR__IS_INTERIOR_ENTITY_SET_VALID(Interior interior, sol::stack_object entitySetName)
	{
		auto retval = (bool)INTERIOR::_IS_INTERIOR_ENTITY_SET_VALID(interior, entitySetName.is<const char*>() ? entitySetName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_INTERIOR_DISABLE_INTERIOR(Interior InteriorInstanceIndex, bool bDisable)
	{
		INTERIOR::DISABLE_INTERIOR(InteriorInstanceIndex, bDisable);
	}

	static void LUA_NATIVE_INTERIOR__0x2533F2AB0EB9C6F9(Any p0, Any p1)
	{
		INTERIOR::_0x2533F2AB0EB9C6F9(p0, p1);
	}

	static void LUA_NATIVE_INTERIOR__0xFE2B3D5500B1B2E4(Any p0, Any p1)
	{
		INTERIOR::_0xFE2B3D5500B1B2E4(p0, p1);
	}

	void RegisterNatives_INTERIOR(sol::state& L)
	{
		auto INTERIOR = L["INTERIOR"].get_or_create<sol::table>();
		INTERIOR.set_function("IS_VALID_INTERIOR", LUA_NATIVE_INTERIOR_IS_VALID_INTERIOR);
		INTERIOR.set_function("GET_INTERIOR_LOCATION_AND_NAMEHASH", LUA_NATIVE_INTERIOR_GET_INTERIOR_LOCATION_AND_NAMEHASH);
		INTERIOR.set_function("_GET_INTERIOR_MINIMAP_HASH", LUA_NATIVE_INTERIOR__GET_INTERIOR_MINIMAP_HASH);
		INTERIOR.set_function("_GET_INTERIOR_POSITION", LUA_NATIVE_INTERIOR__GET_INTERIOR_POSITION);
		INTERIOR.set_function("IS_INTERIOR_SCENE", LUA_NATIVE_INTERIOR_IS_INTERIOR_SCENE);
		INTERIOR.set_function("CLEAR_ROOM_FOR_ENTITY", LUA_NATIVE_INTERIOR_CLEAR_ROOM_FOR_ENTITY);
		INTERIOR.set_function("FORCE_ROOM_FOR_ENTITY", LUA_NATIVE_INTERIOR_FORCE_ROOM_FOR_ENTITY);
		INTERIOR.set_function("GET_ROOM_KEY_FROM_ENTITY", LUA_NATIVE_INTERIOR_GET_ROOM_KEY_FROM_ENTITY);
		INTERIOR.set_function("GET_KEY_FOR_ENTITY_IN_ROOM", LUA_NATIVE_INTERIOR_GET_KEY_FOR_ENTITY_IN_ROOM);
		INTERIOR.set_function("GET_INTERIOR_FROM_ENTITY", LUA_NATIVE_INTERIOR_GET_INTERIOR_FROM_ENTITY);
		INTERIOR.set_function("RETAIN_ENTITY_IN_INTERIOR", LUA_NATIVE_INTERIOR_RETAIN_ENTITY_IN_INTERIOR);
		INTERIOR.set_function("FORCE_ROOM_FOR_GAME_VIEWPORT", LUA_NATIVE_INTERIOR_FORCE_ROOM_FOR_GAME_VIEWPORT);
		INTERIOR.set_function("CLEAR_ROOM_FOR_GAME_VIEWPORT", LUA_NATIVE_INTERIOR_CLEAR_ROOM_FOR_GAME_VIEWPORT);
		INTERIOR.set_function("GET_INTERIOR_FROM_PRIMARY_VIEW", LUA_NATIVE_INTERIOR_GET_INTERIOR_FROM_PRIMARY_VIEW);
		INTERIOR.set_function("GET_INTERIOR_AT_COORDS", LUA_NATIVE_INTERIOR_GET_INTERIOR_AT_COORDS);
		INTERIOR.set_function("PIN_INTERIOR_IN_MEMORY", LUA_NATIVE_INTERIOR_PIN_INTERIOR_IN_MEMORY);
		INTERIOR.set_function("UNPIN_INTERIOR", LUA_NATIVE_INTERIOR_UNPIN_INTERIOR);
		INTERIOR.set_function("IS_INTERIOR_READY", LUA_NATIVE_INTERIOR_IS_INTERIOR_READY);
		INTERIOR.set_function("SET_INTERIOR_IN_USE", LUA_NATIVE_INTERIOR_SET_INTERIOR_IN_USE);
		INTERIOR.set_function("GET_INTERIOR_AT_COORDS_WITH_TYPE", LUA_NATIVE_INTERIOR_GET_INTERIOR_AT_COORDS_WITH_TYPE);
		INTERIOR.set_function("GET_INTERIOR_AT_COORDS_WITH_TYPEHASH", LUA_NATIVE_INTERIOR_GET_INTERIOR_AT_COORDS_WITH_TYPEHASH);
		INTERIOR.set_function("IS_COLLISION_MARKED_OUTSIDE", LUA_NATIVE_INTERIOR_IS_COLLISION_MARKED_OUTSIDE);
		INTERIOR.set_function("GET_INTERIOR_FROM_COLLISION", LUA_NATIVE_INTERIOR_GET_INTERIOR_FROM_COLLISION);
		INTERIOR.set_function("ACTIVATE_INTERIOR_ENTITY_SET", LUA_NATIVE_INTERIOR_ACTIVATE_INTERIOR_ENTITY_SET);
		INTERIOR.set_function("DEACTIVATE_INTERIOR_ENTITY_SET", LUA_NATIVE_INTERIOR_DEACTIVATE_INTERIOR_ENTITY_SET);
		INTERIOR.set_function("IS_INTERIOR_ENTITY_SET_ACTIVE", LUA_NATIVE_INTERIOR_IS_INTERIOR_ENTITY_SET_ACTIVE);
		INTERIOR.set_function("_IS_INTERIOR_ENTITY_SET_VALID", LUA_NATIVE_INTERIOR__IS_INTERIOR_ENTITY_SET_VALID);
		INTERIOR.set_function("DISABLE_INTERIOR", LUA_NATIVE_INTERIOR_DISABLE_INTERIOR);
		INTERIOR.set_function("_0x2533F2AB0EB9C6F9", LUA_NATIVE_INTERIOR__0x2533F2AB0EB9C6F9);
		INTERIOR.set_function("_0xFE2B3D5500B1B2E4", LUA_NATIVE_INTERIOR__0xFE2B3D5500B1B2E4);
	}
}
