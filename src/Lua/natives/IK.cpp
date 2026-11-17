#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_IK__INVERSE_KINEMATICS_REQUEST_LOOK_AT(Ped ped, uintptr_t args)
	{
		IK::_INVERSE_KINEMATICS_REQUEST_LOOK_AT(ped, (Any*)args);
	}

	static void LUA_NATIVE_IK__0x0B9F7A01EC50448D(Ped ped, uintptr_t args)
	{
		IK::_0x0B9F7A01EC50448D(ped, (Any*)args);
	}

	static void LUA_NATIVE_IK__INVERSE_KINEMATICS_SET_DISABLED_FOR_PED(Ped ped, int p1, bool p2)
	{
		IK::_INVERSE_KINEMATICS_SET_DISABLED_FOR_PED(ped, p1, p2);
	}

	static bool LUA_NATIVE_IK__0x6098139150DCC745(Ped ped, int p1)
	{
		auto retval = (bool)IK::_0x6098139150DCC745(ped, p1);
		return retval;
	}

	static void LUA_NATIVE_IK__0x873C792E07A32C8B(Ped ped1, Ped ped2)
	{
		IK::_0x873C792E07A32C8B(ped1, ped2);
	}

	void RegisterNatives_IK(sol::state& L)
	{
		auto IK = L["IK"].get_or_create<sol::table>();
		IK.set_function("_INVERSE_KINEMATICS_REQUEST_LOOK_AT", LUA_NATIVE_IK__INVERSE_KINEMATICS_REQUEST_LOOK_AT);
		IK.set_function("_0x0B9F7A01EC50448D", LUA_NATIVE_IK__0x0B9F7A01EC50448D);
		IK.set_function("_INVERSE_KINEMATICS_SET_DISABLED_FOR_PED", LUA_NATIVE_IK__INVERSE_KINEMATICS_SET_DISABLED_FOR_PED);
		IK.set_function("_0x6098139150DCC745", LUA_NATIVE_IK__0x6098139150DCC745);
		IK.set_function("_0x873C792E07A32C8B", LUA_NATIVE_IK__0x873C792E07A32C8B);
	}
}
