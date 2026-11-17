#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_CRASHLOG__0x0FD3ECF9D0C8655F(sol::stack_object p0)
	{
		CRASHLOG::_0x0FD3ECF9D0C8655F(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_CRASHLOG__0xCA0BAC376C541978(sol::stack_object p0)
	{
		CRASHLOG::_0xCA0BAC376C541978(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_CRASHLOG__0x3A66F1963B223F61(sol::stack_object p0)
	{
		auto retval = (bool)CRASHLOG::_0x3A66F1963B223F61(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_CRASHLOG__0x7C680FF55617F82F()
	{
		auto retval = (bool)CRASHLOG::_0x7C680FF55617F82F();
		return retval;
	}

	static bool LUA_NATIVE_CRASHLOG__0xD8E3D22AA4F0E0A5(sol::stack_object p0)
	{
		auto retval = (bool)CRASHLOG::_0xD8E3D22AA4F0E0A5(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_CRASHLOG__0xA67F0B039D9CD513(bool p0)
	{
		auto retval = (bool)CRASHLOG::_0xA67F0B039D9CD513(p0);
		return retval;
	}

	static bool LUA_NATIVE_CRASHLOG__0xE72E234B30DA7B7A(int p0)
	{
		auto retval = (bool)CRASHLOG::_0xE72E234B30DA7B7A(p0);
		return retval;
	}

	static bool LUA_NATIVE_CRASHLOG__0x87F005C969EF1563(float p0)
	{
		auto retval = (bool)CRASHLOG::_0x87F005C969EF1563(p0);
		return retval;
	}

	static bool LUA_NATIVE_CRASHLOG__0x23CCAB8F40B9CBEE(float x, float y, float z)
	{
		auto retval = (bool)CRASHLOG::_0x23CCAB8F40B9CBEE(x, y, z);
		return retval;
	}

	static bool LUA_NATIVE_CRASHLOG__0xF0D545C1EEAD614A()
	{
		auto retval = (bool)CRASHLOG::_0xF0D545C1EEAD614A();
		return retval;
	}

	static bool LUA_NATIVE_CRASHLOG__0x33C1D63E55FA4284(sol::stack_object p0)
	{
		auto retval = (bool)CRASHLOG::_0x33C1D63E55FA4284(p0.is<const char*>() ? p0.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_CRASHLOG__0x4E42CA5BCD45444A()
	{
		CRASHLOG::_0x4E42CA5BCD45444A();
	}

	static void LUA_NATIVE_CRASHLOG__0xDA05310EA94DC8C6(sol::stack_object p0, sol::stack_object p1)
	{
		CRASHLOG::_0xDA05310EA94DC8C6(p0.is<const char*>() ? p0.as<const char*>() : nullptr, p1.is<const char*>() ? p1.as<const char*>() : nullptr);
	}

	void RegisterNatives_CRASHLOG(sol::state& L)
	{
		auto CRASHLOG = L["CRASHLOG"].get_or_create<sol::table>();
		CRASHLOG.set_function("_0x0FD3ECF9D0C8655F", LUA_NATIVE_CRASHLOG__0x0FD3ECF9D0C8655F);
		CRASHLOG.set_function("_0xCA0BAC376C541978", LUA_NATIVE_CRASHLOG__0xCA0BAC376C541978);
		CRASHLOG.set_function("_0x3A66F1963B223F61", LUA_NATIVE_CRASHLOG__0x3A66F1963B223F61);
		CRASHLOG.set_function("_0x7C680FF55617F82F", LUA_NATIVE_CRASHLOG__0x7C680FF55617F82F);
		CRASHLOG.set_function("_0xD8E3D22AA4F0E0A5", LUA_NATIVE_CRASHLOG__0xD8E3D22AA4F0E0A5);
		CRASHLOG.set_function("_0xA67F0B039D9CD513", LUA_NATIVE_CRASHLOG__0xA67F0B039D9CD513);
		CRASHLOG.set_function("_0xE72E234B30DA7B7A", LUA_NATIVE_CRASHLOG__0xE72E234B30DA7B7A);
		CRASHLOG.set_function("_0x87F005C969EF1563", LUA_NATIVE_CRASHLOG__0x87F005C969EF1563);
		CRASHLOG.set_function("_0x23CCAB8F40B9CBEE", LUA_NATIVE_CRASHLOG__0x23CCAB8F40B9CBEE);
		CRASHLOG.set_function("_0xF0D545C1EEAD614A", LUA_NATIVE_CRASHLOG__0xF0D545C1EEAD614A);
		CRASHLOG.set_function("_0x33C1D63E55FA4284", LUA_NATIVE_CRASHLOG__0x33C1D63E55FA4284);
		CRASHLOG.set_function("_0x4E42CA5BCD45444A", LUA_NATIVE_CRASHLOG__0x4E42CA5BCD45444A);
		CRASHLOG.set_function("_0xDA05310EA94DC8C6", LUA_NATIVE_CRASHLOG__0xDA05310EA94DC8C6);
	}
}
