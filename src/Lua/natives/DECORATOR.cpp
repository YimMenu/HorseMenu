#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static bool LUA_NATIVE_DECORATOR_DECOR_SET_BOOL(ScrHandle guid, sol::stack_object decoratorName, bool value)
	{
		auto retval = (bool)DECORATOR::DECOR_SET_BOOL(guid, decoratorName.is<const char*>() ? decoratorName.as<const char*>() : nullptr, value);
		return retval;
	}

	static bool LUA_NATIVE_DECORATOR_DECOR_SET_FLOAT(ScrHandle guid, sol::stack_object decoratorName, float value)
	{
		auto retval = (bool)DECORATOR::DECOR_SET_FLOAT(guid, decoratorName.is<const char*>() ? decoratorName.as<const char*>() : nullptr, value);
		return retval;
	}

	static bool LUA_NATIVE_DECORATOR_DECOR_SET_INT(ScrHandle guid, sol::stack_object decoratorName, int value)
	{
		auto retval = (bool)DECORATOR::DECOR_SET_INT(guid, decoratorName.is<const char*>() ? decoratorName.as<const char*>() : nullptr, value);
		return retval;
	}

	static bool LUA_NATIVE_DECORATOR__DECOR_SET_UINT8(Entity entity, sol::stack_object propertyName, int value)
	{
		auto retval = (bool)DECORATOR::_DECOR_SET_UINT8(entity, propertyName.is<const char*>() ? propertyName.as<const char*>() : nullptr, value);
		return retval;
	}

	static bool LUA_NATIVE_DECORATOR_DECOR_SET_STRING(Entity entity, sol::stack_object propertyName, sol::stack_object value)
	{
		auto retval = (bool)DECORATOR::DECOR_SET_STRING(entity, propertyName.is<const char*>() ? propertyName.as<const char*>() : nullptr, value.is<const char*>() ? value.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_DECORATOR_DECOR_GET_BOOL(ScrHandle guid, sol::stack_object decoratorName)
	{
		auto retval = (bool)DECORATOR::DECOR_GET_BOOL(guid, decoratorName.is<const char*>() ? decoratorName.as<const char*>() : nullptr);
		return retval;
	}

	static float LUA_NATIVE_DECORATOR_DECOR_GET_FLOAT(ScrHandle guid, sol::stack_object decoratorName)
	{
		auto retval = DECORATOR::DECOR_GET_FLOAT(guid, decoratorName.is<const char*>() ? decoratorName.as<const char*>() : nullptr);
		return retval;
	}

	static int LUA_NATIVE_DECORATOR_DECOR_GET_INT(ScrHandle guid, sol::stack_object decoratorName)
	{
		auto retval = DECORATOR::DECOR_GET_INT(guid, decoratorName.is<const char*>() ? decoratorName.as<const char*>() : nullptr);
		return retval;
	}

	static int LUA_NATIVE_DECORATOR__DECOR_GET_UINT8(Entity entity, sol::stack_object propertyName)
	{
		auto retval = DECORATOR::_DECOR_GET_UINT8(entity, propertyName.is<const char*>() ? propertyName.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_DECORATOR_DECOR_EXIST_ON(ScrHandle guid, sol::stack_object decoratorName)
	{
		auto retval = (bool)DECORATOR::DECOR_EXIST_ON(guid, decoratorName.is<const char*>() ? decoratorName.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_DECORATOR_DECOR_REMOVE(ScrHandle guid, sol::stack_object decoratorName)
	{
		auto retval = (bool)DECORATOR::DECOR_REMOVE(guid, decoratorName.is<const char*>() ? decoratorName.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_DECORATOR_DECOR_REMOVE_ALL(Entity entity)
	{
		auto retval = (bool)DECORATOR::DECOR_REMOVE_ALL(entity);
		return retval;
	}

	static void LUA_NATIVE_DECORATOR_DECOR_REGISTER(sol::stack_object decoratorName, int type)
	{
		DECORATOR::DECOR_REGISTER(decoratorName.is<const char*>() ? decoratorName.as<const char*>() : nullptr, type);
	}

	static void LUA_NATIVE_DECORATOR__DECOR_REGISTER_2(sol::stack_object propertyName, int type, bool p2)
	{
		DECORATOR::_DECOR_REGISTER_2(propertyName.is<const char*>() ? propertyName.as<const char*>() : nullptr, type, p2);
	}

	static bool LUA_NATIVE_DECORATOR_DECOR_IS_REGISTERED_AS_TYPE(sol::stack_object decoratorName, int type)
	{
		auto retval = (bool)DECORATOR::DECOR_IS_REGISTERED_AS_TYPE(decoratorName.is<const char*>() ? decoratorName.as<const char*>() : nullptr, type);
		return retval;
	}

	void RegisterNatives_DECORATOR(sol::state& L)
	{
		auto DECORATOR = L["DECORATOR"].get_or_create<sol::table>();
		DECORATOR.set_function("DECOR_SET_BOOL", LUA_NATIVE_DECORATOR_DECOR_SET_BOOL);
		DECORATOR.set_function("DECOR_SET_FLOAT", LUA_NATIVE_DECORATOR_DECOR_SET_FLOAT);
		DECORATOR.set_function("DECOR_SET_INT", LUA_NATIVE_DECORATOR_DECOR_SET_INT);
		DECORATOR.set_function("_DECOR_SET_UINT8", LUA_NATIVE_DECORATOR__DECOR_SET_UINT8);
		DECORATOR.set_function("DECOR_SET_STRING", LUA_NATIVE_DECORATOR_DECOR_SET_STRING);
		DECORATOR.set_function("DECOR_GET_BOOL", LUA_NATIVE_DECORATOR_DECOR_GET_BOOL);
		DECORATOR.set_function("DECOR_GET_FLOAT", LUA_NATIVE_DECORATOR_DECOR_GET_FLOAT);
		DECORATOR.set_function("DECOR_GET_INT", LUA_NATIVE_DECORATOR_DECOR_GET_INT);
		DECORATOR.set_function("_DECOR_GET_UINT8", LUA_NATIVE_DECORATOR__DECOR_GET_UINT8);
		DECORATOR.set_function("DECOR_EXIST_ON", LUA_NATIVE_DECORATOR_DECOR_EXIST_ON);
		DECORATOR.set_function("DECOR_REMOVE", LUA_NATIVE_DECORATOR_DECOR_REMOVE);
		DECORATOR.set_function("DECOR_REMOVE_ALL", LUA_NATIVE_DECORATOR_DECOR_REMOVE_ALL);
		DECORATOR.set_function("DECOR_REGISTER", LUA_NATIVE_DECORATOR_DECOR_REGISTER);
		DECORATOR.set_function("_DECOR_REGISTER_2", LUA_NATIVE_DECORATOR__DECOR_REGISTER_2);
		DECORATOR.set_function("DECOR_IS_REGISTERED_AS_TYPE", LUA_NATIVE_DECORATOR_DECOR_IS_REGISTERED_AS_TYPE);
	}
}
