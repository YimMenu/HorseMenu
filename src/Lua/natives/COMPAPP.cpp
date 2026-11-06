#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_COMPAPP__0xB6FD96420C0126A1(Hash p0, bool p1)
	{
		COMPAPP::_0xB6FD96420C0126A1(p0, p1);
	}

	static void LUA_NATIVE_COMPAPP__0x74BCCEB233AD95B2(Hash p0, Hash p1)
	{
		COMPAPP::_0x74BCCEB233AD95B2(p0, p1);
	}

	static void LUA_NATIVE_COMPAPP__0x29C733459A9011EB(Hash p0, sol::stack_object p1)
	{
		COMPAPP::_0x29C733459A9011EB(p0, p1.is<const char*>() ? p1.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_COMPAPP__0x7AF1BB4504EA5ED9()
	{
		auto retval = (bool)COMPAPP::_0x7AF1BB4504EA5ED9();
		return retval;
	}

	static void LUA_NATIVE_COMPAPP__0xCCB4635A071FB62D()
	{
		COMPAPP::_0xCCB4635A071FB62D();
	}

	void RegisterNatives_COMPAPP(sol::state& L)
	{
		auto COMPAPP = L["COMPAPP"].get_or_create<sol::table>();
		COMPAPP.set_function("_0xB6FD96420C0126A1", LUA_NATIVE_COMPAPP__0xB6FD96420C0126A1);
		COMPAPP.set_function("_0x74BCCEB233AD95B2", LUA_NATIVE_COMPAPP__0x74BCCEB233AD95B2);
		COMPAPP.set_function("_0x29C733459A9011EB", LUA_NATIVE_COMPAPP__0x29C733459A9011EB);
		COMPAPP.set_function("_0x7AF1BB4504EA5ED9", LUA_NATIVE_COMPAPP__0x7AF1BB4504EA5ED9);
		COMPAPP.set_function("_0xCCB4635A071FB62D", LUA_NATIVE_COMPAPP__0xCCB4635A071FB62D);
	}
}
