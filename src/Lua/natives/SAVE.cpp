#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_SAVE__0x4FB5869E2B37FC00()
	{
		SAVE::_0x4FB5869E2B37FC00();
	}

	static bool LUA_NATIVE_SAVE_SAVEGAME_SAVE_SP(Hash savegameType)
	{
		auto retval = (bool)SAVE::SAVEGAME_SAVE_SP(savegameType);
		return retval;
	}

	static bool LUA_NATIVE_SAVE_SAVEGAME_SAVE_MP(Hash savegameType)
	{
		auto retval = (bool)SAVE::SAVEGAME_SAVE_MP(savegameType);
		return retval;
	}

	static bool LUA_NATIVE_SAVE_SAVEGAME_IS_SAVE_PENDING()
	{
		auto retval = (bool)SAVE::SAVEGAME_IS_SAVE_PENDING();
		return retval;
	}

	static Any LUA_NATIVE_SAVE__0x1431540BCA1A1BD2()
	{
		auto retval = SAVE::_0x1431540BCA1A1BD2();
		return retval;
	}

	static Any LUA_NATIVE_SAVE__0xA7ECEBAFBAF997A5(Hash savegameType)
	{
		auto retval = SAVE::_0xA7ECEBAFBAF997A5(savegameType);
		return retval;
	}

	static void LUA_NATIVE_SAVE__0xED4B0C1057892B2E(Any p0, Any p1, Any p2, Any p3)
	{
		SAVE::_0xED4B0C1057892B2E(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_SAVE__0x9BB83C4DD7BE0802(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		SAVE::_0x9BB83C4DD7BE0802(p0, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_SAVE__0xE8346E62FD7FB962()
	{
		SAVE::_0xE8346E62FD7FB962();
	}

	static void LUA_NATIVE_SAVE__0xC0ABF784590798A9(Any p0)
	{
		SAVE::_0xC0ABF784590798A9(p0);
	}

	static Any LUA_NATIVE_SAVE__0xB00CE33465B5406D(Any p0, Any p1)
	{
		auto retval = SAVE::_0xB00CE33465B5406D(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_SAVE__SAVEGAME_GET_INT_2(uintptr_t p0, sol::stack_object variableName)
	{
		SAVE::_SAVEGAME_GET_INT_2((Any*)p0, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_SAVE__SAVEGAME_GET_INT(uintptr_t p0, sol::stack_object variableName)
	{
		SAVE::_SAVEGAME_GET_INT((Any*)p0, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_SAVE__SAVEGAME_GET_INT_3(uintptr_t p0, sol::stack_object variableName)
	{
		SAVE::_SAVEGAME_GET_INT_3((Any*)p0, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_SAVE__SAVEGAME_GET_FLOAT(uintptr_t p0, sol::stack_object variableName)
	{
		SAVE::_SAVEGAME_GET_FLOAT((Any*)p0, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_SAVE__SAVEGAME_GET_BOOL(uintptr_t p0, sol::stack_object variableName)
	{
		SAVE::_SAVEGAME_GET_BOOL((Any*)p0, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_SAVE__SAVEGAME_GET_TEXT_LABEL_23(uintptr_t p0, sol::stack_object variableName)
	{
		SAVE::_SAVEGAME_GET_TEXT_LABEL_23((Any*)p0, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_SAVE__SAVEGAME_GET_TEXT_LABEL_31(uintptr_t p0, sol::stack_object variableName)
	{
		SAVE::_SAVEGAME_GET_TEXT_LABEL_31((Any*)p0, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_SAVE__SAVEGAME_GET_TEXT_LABEL_63(uintptr_t p0, sol::stack_object variableName)
	{
		SAVE::_SAVEGAME_GET_TEXT_LABEL_63((Any*)p0, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_SAVE__0x443174C20B8B9E7F(Any p0, Any p1, Any p2)
	{
		SAVE::_0x443174C20B8B9E7F(p0, p1, p2);
	}

	static void LUA_NATIVE_SAVE__0x8E8FFB9E4AD051D2(Any p0, Any p1, Any p2, Any p3)
	{
		SAVE::_0x8E8FFB9E4AD051D2(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_SAVE__0xE0B45E983BFC0768()
	{
		SAVE::_0xE0B45E983BFC0768();
	}

	static void LUA_NATIVE_SAVE__0x81F4E92BE3958364(Any p0, Any p1, Any p2)
	{
		SAVE::_0x81F4E92BE3958364(p0, p1, p2);
	}

	static void LUA_NATIVE_SAVE__0xA844FEB5C22C2C74()
	{
		SAVE::_0xA844FEB5C22C2C74();
	}

	void RegisterNatives_SAVE(sol::state& L)
	{
		auto SAVE = L["SAVE"].get_or_create<sol::table>();
		SAVE.set_function("_0x4FB5869E2B37FC00", LUA_NATIVE_SAVE__0x4FB5869E2B37FC00);
		SAVE.set_function("SAVEGAME_SAVE_SP", LUA_NATIVE_SAVE_SAVEGAME_SAVE_SP);
		SAVE.set_function("SAVEGAME_SAVE_MP", LUA_NATIVE_SAVE_SAVEGAME_SAVE_MP);
		SAVE.set_function("SAVEGAME_IS_SAVE_PENDING", LUA_NATIVE_SAVE_SAVEGAME_IS_SAVE_PENDING);
		SAVE.set_function("_0x1431540BCA1A1BD2", LUA_NATIVE_SAVE__0x1431540BCA1A1BD2);
		SAVE.set_function("_0xA7ECEBAFBAF997A5", LUA_NATIVE_SAVE__0xA7ECEBAFBAF997A5);
		SAVE.set_function("_0xED4B0C1057892B2E", LUA_NATIVE_SAVE__0xED4B0C1057892B2E);
		SAVE.set_function("_0x9BB83C4DD7BE0802", LUA_NATIVE_SAVE__0x9BB83C4DD7BE0802);
		SAVE.set_function("_0xE8346E62FD7FB962", LUA_NATIVE_SAVE__0xE8346E62FD7FB962);
		SAVE.set_function("_0xC0ABF784590798A9", LUA_NATIVE_SAVE__0xC0ABF784590798A9);
		SAVE.set_function("_0xB00CE33465B5406D", LUA_NATIVE_SAVE__0xB00CE33465B5406D);
		SAVE.set_function("_SAVEGAME_GET_INT_2", LUA_NATIVE_SAVE__SAVEGAME_GET_INT_2);
		SAVE.set_function("_SAVEGAME_GET_INT", LUA_NATIVE_SAVE__SAVEGAME_GET_INT);
		SAVE.set_function("_SAVEGAME_GET_INT_3", LUA_NATIVE_SAVE__SAVEGAME_GET_INT_3);
		SAVE.set_function("_SAVEGAME_GET_FLOAT", LUA_NATIVE_SAVE__SAVEGAME_GET_FLOAT);
		SAVE.set_function("_SAVEGAME_GET_BOOL", LUA_NATIVE_SAVE__SAVEGAME_GET_BOOL);
		SAVE.set_function("_SAVEGAME_GET_TEXT_LABEL_23", LUA_NATIVE_SAVE__SAVEGAME_GET_TEXT_LABEL_23);
		SAVE.set_function("_SAVEGAME_GET_TEXT_LABEL_31", LUA_NATIVE_SAVE__SAVEGAME_GET_TEXT_LABEL_31);
		SAVE.set_function("_SAVEGAME_GET_TEXT_LABEL_63", LUA_NATIVE_SAVE__SAVEGAME_GET_TEXT_LABEL_63);
		SAVE.set_function("_0x443174C20B8B9E7F", LUA_NATIVE_SAVE__0x443174C20B8B9E7F);
		SAVE.set_function("_0x8E8FFB9E4AD051D2", LUA_NATIVE_SAVE__0x8E8FFB9E4AD051D2);
		SAVE.set_function("_0xE0B45E983BFC0768", LUA_NATIVE_SAVE__0xE0B45E983BFC0768);
		SAVE.set_function("_0x81F4E92BE3958364", LUA_NATIVE_SAVE__0x81F4E92BE3958364);
		SAVE.set_function("_0xA844FEB5C22C2C74", LUA_NATIVE_SAVE__0xA844FEB5C22C2C74);
	}
}
