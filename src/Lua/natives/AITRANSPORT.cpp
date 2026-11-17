#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_AITRANSPORT_TASK_ENTER_TRANSPORT(uintptr_t args)
	{
		AITRANSPORT::TASK_ENTER_TRANSPORT((Any*)args);
	}

	static void LUA_NATIVE_AITRANSPORT_TASK_EXIT_TRANSPORT(uintptr_t args)
	{
		AITRANSPORT::TASK_EXIT_TRANSPORT((Any*)args);
	}

	static void LUA_NATIVE_AITRANSPORT_SET_PED_ON_TRANSPORT_SEAT(Ped ped, Entity transportEntity, int seat, int flags)
	{
		AITRANSPORT::SET_PED_ON_TRANSPORT_SEAT(ped, transportEntity, seat, flags);
	}

	static void LUA_NATIVE_AITRANSPORT_SET_PED_OFF_TRANSPORT_SEAT(Ped ped, int flags)
	{
		AITRANSPORT::SET_PED_OFF_TRANSPORT_SEAT(ped, flags);
	}

	static void LUA_NATIVE_AITRANSPORT_SET_TRANSPORT_CONFIG_FLAG(Entity transportEntity, int flagId, bool value)
	{
		AITRANSPORT::SET_TRANSPORT_CONFIG_FLAG(transportEntity, flagId, value);
	}

	static bool LUA_NATIVE_AITRANSPORT_GET_TRANSPORT_CONFIG_FLAG(Entity transportEntity, int flagId, bool p2)
	{
		auto retval = (bool)AITRANSPORT::GET_TRANSPORT_CONFIG_FLAG(transportEntity, flagId, p2);
		return retval;
	}

	static std::tuple<Any, int> LUA_NATIVE_AITRANSPORT__GET_TRANSPORT_USAGE_FLAGS(Entity transportEntity, int flags)
	{
		std::tuple<Any, int> return_values;
		std::get<0>(return_values) = AITRANSPORT::_GET_TRANSPORT_USAGE_FLAGS(transportEntity, &flags);
		std::get<1>(return_values) = flags;

		return return_values;
	}

	static void LUA_NATIVE_AITRANSPORT__SET_TRANSPORT_USAGE_FLAGS(Entity transportEntity, int flags)
	{
		AITRANSPORT::_SET_TRANSPORT_USAGE_FLAGS(transportEntity, flags);
	}

	static void LUA_NATIVE_AITRANSPORT_SET_TRANSPORT_ACCESSIBLE_SEAT_FLAGS(Entity transportEntity, int flags)
	{
		AITRANSPORT::SET_TRANSPORT_ACCESSIBLE_SEAT_FLAGS(transportEntity, flags);
	}

	static void LUA_NATIVE_AITRANSPORT__0x4B6C9A43F7D9109B(Any p0, Any p1)
	{
		AITRANSPORT::_0x4B6C9A43F7D9109B(p0, p1);
	}

	static bool LUA_NATIVE_AITRANSPORT__IS_PED_ON_TRANSPORT_ENTITY(Ped ped, Entity transportEntity)
	{
		auto retval = (bool)AITRANSPORT::_IS_PED_ON_TRANSPORT_ENTITY(ped, transportEntity);
		return retval;
	}

	static bool LUA_NATIVE_AITRANSPORT__IS_PED_ON_TRANSPORT_SEAT(Ped ped, bool p1)
	{
		auto retval = (bool)AITRANSPORT::_IS_PED_ON_TRANSPORT_SEAT(ped, p1);
		return retval;
	}

	static bool LUA_NATIVE_AITRANSPORT__IS_TRANSPORT_SEAT_OCCUPIED(Entity transportEntity, int seatIndex)
	{
		auto retval = (bool)AITRANSPORT::_IS_TRANSPORT_SEAT_OCCUPIED(transportEntity, seatIndex);
		return retval;
	}

	static bool LUA_NATIVE_AITRANSPORT__IS_TRANSPORT_SEAT_FREE(Entity transportEntity, int seatIndex)
	{
		auto retval = (bool)AITRANSPORT::_IS_TRANSPORT_SEAT_FREE(transportEntity, seatIndex);
		return retval;
	}

	static Ped LUA_NATIVE_AITRANSPORT__GET_PED_IN_TRANSPORT_SEAT(Entity transportEntity, int seatIndex)
	{
		auto retval = AITRANSPORT::_GET_PED_IN_TRANSPORT_SEAT(transportEntity, seatIndex);
		return retval;
	}

	static bool LUA_NATIVE_AITRANSPORT_IS_PED_ENTERING_TRANSPORT(Ped ped, Entity transportEntity, bool p2)
	{
		auto retval = (bool)AITRANSPORT::IS_PED_ENTERING_TRANSPORT(ped, transportEntity, p2);
		return retval;
	}

	static bool LUA_NATIVE_AITRANSPORT_IS_PED_EXITING_TRANSPORT(Ped ped, Entity transportEntity)
	{
		auto retval = (bool)AITRANSPORT::IS_PED_EXITING_TRANSPORT(ped, transportEntity);
		return retval;
	}

	static void LUA_NATIVE_AITRANSPORT__0x4248AB2EEB3C75AD(Entity transportEntity, Ped ped, bool p2)
	{
		AITRANSPORT::_0x4248AB2EEB3C75AD(transportEntity, ped, p2);
	}

	static void LUA_NATIVE_AITRANSPORT__SET_PED_USE_TRANSPORT_SEAT_PREFERENCE(Ped ped, Entity transportEntity, int preferenceSlot, int p3, int seatIndex)
	{
		AITRANSPORT::_SET_PED_USE_TRANSPORT_SEAT_PREFERENCE(ped, transportEntity, preferenceSlot, p3, seatIndex);
	}

	static void LUA_NATIVE_AITRANSPORT__0x5639FBEA922788DA(Entity transportEntity)
	{
		AITRANSPORT::_0x5639FBEA922788DA(transportEntity);
	}

	static void LUA_NATIVE_AITRANSPORT__SET_AI_CAN_USE_TRANSPORT(Entity transportEntity, bool state)
	{
		AITRANSPORT::_SET_AI_CAN_USE_TRANSPORT(transportEntity, state);
	}

	static void LUA_NATIVE_AITRANSPORT__0x8C8371EDFAF014A0(Ped ped, float p1)
	{
		AITRANSPORT::_0x8C8371EDFAF014A0(ped, p1);
	}

	static void LUA_NATIVE_AITRANSPORT__0xF8C20282B237E3F7(Ped ped)
	{
		AITRANSPORT::_0xF8C20282B237E3F7(ped);
	}

	static void LUA_NATIVE_AITRANSPORT__SET_TRANSPORT_PRIORITY_SEAT(Entity transportEntity, int seatIndex)
	{
		AITRANSPORT::_SET_TRANSPORT_PRIORITY_SEAT(transportEntity, seatIndex);
	}

	void RegisterNatives_AITRANSPORT(sol::state& L)
	{
		auto AITRANSPORT = L["AITRANSPORT"].get_or_create<sol::table>();
		AITRANSPORT.set_function("TASK_ENTER_TRANSPORT", LUA_NATIVE_AITRANSPORT_TASK_ENTER_TRANSPORT);
		AITRANSPORT.set_function("TASK_EXIT_TRANSPORT", LUA_NATIVE_AITRANSPORT_TASK_EXIT_TRANSPORT);
		AITRANSPORT.set_function("SET_PED_ON_TRANSPORT_SEAT", LUA_NATIVE_AITRANSPORT_SET_PED_ON_TRANSPORT_SEAT);
		AITRANSPORT.set_function("SET_PED_OFF_TRANSPORT_SEAT", LUA_NATIVE_AITRANSPORT_SET_PED_OFF_TRANSPORT_SEAT);
		AITRANSPORT.set_function("SET_TRANSPORT_CONFIG_FLAG", LUA_NATIVE_AITRANSPORT_SET_TRANSPORT_CONFIG_FLAG);
		AITRANSPORT.set_function("GET_TRANSPORT_CONFIG_FLAG", LUA_NATIVE_AITRANSPORT_GET_TRANSPORT_CONFIG_FLAG);
		AITRANSPORT.set_function("_GET_TRANSPORT_USAGE_FLAGS", LUA_NATIVE_AITRANSPORT__GET_TRANSPORT_USAGE_FLAGS);
		AITRANSPORT.set_function("_SET_TRANSPORT_USAGE_FLAGS", LUA_NATIVE_AITRANSPORT__SET_TRANSPORT_USAGE_FLAGS);
		AITRANSPORT.set_function("SET_TRANSPORT_ACCESSIBLE_SEAT_FLAGS", LUA_NATIVE_AITRANSPORT_SET_TRANSPORT_ACCESSIBLE_SEAT_FLAGS);
		AITRANSPORT.set_function("_0x4B6C9A43F7D9109B", LUA_NATIVE_AITRANSPORT__0x4B6C9A43F7D9109B);
		AITRANSPORT.set_function("_IS_PED_ON_TRANSPORT_ENTITY", LUA_NATIVE_AITRANSPORT__IS_PED_ON_TRANSPORT_ENTITY);
		AITRANSPORT.set_function("_IS_PED_ON_TRANSPORT_SEAT", LUA_NATIVE_AITRANSPORT__IS_PED_ON_TRANSPORT_SEAT);
		AITRANSPORT.set_function("_IS_TRANSPORT_SEAT_OCCUPIED", LUA_NATIVE_AITRANSPORT__IS_TRANSPORT_SEAT_OCCUPIED);
		AITRANSPORT.set_function("_IS_TRANSPORT_SEAT_FREE", LUA_NATIVE_AITRANSPORT__IS_TRANSPORT_SEAT_FREE);
		AITRANSPORT.set_function("_GET_PED_IN_TRANSPORT_SEAT", LUA_NATIVE_AITRANSPORT__GET_PED_IN_TRANSPORT_SEAT);
		AITRANSPORT.set_function("IS_PED_ENTERING_TRANSPORT", LUA_NATIVE_AITRANSPORT_IS_PED_ENTERING_TRANSPORT);
		AITRANSPORT.set_function("IS_PED_EXITING_TRANSPORT", LUA_NATIVE_AITRANSPORT_IS_PED_EXITING_TRANSPORT);
		AITRANSPORT.set_function("_0x4248AB2EEB3C75AD", LUA_NATIVE_AITRANSPORT__0x4248AB2EEB3C75AD);
		AITRANSPORT.set_function("_SET_PED_USE_TRANSPORT_SEAT_PREFERENCE", LUA_NATIVE_AITRANSPORT__SET_PED_USE_TRANSPORT_SEAT_PREFERENCE);
		AITRANSPORT.set_function("_0x5639FBEA922788DA", LUA_NATIVE_AITRANSPORT__0x5639FBEA922788DA);
		AITRANSPORT.set_function("_SET_AI_CAN_USE_TRANSPORT", LUA_NATIVE_AITRANSPORT__SET_AI_CAN_USE_TRANSPORT);
		AITRANSPORT.set_function("_0x8C8371EDFAF014A0", LUA_NATIVE_AITRANSPORT__0x8C8371EDFAF014A0);
		AITRANSPORT.set_function("_0xF8C20282B237E3F7", LUA_NATIVE_AITRANSPORT__0xF8C20282B237E3F7);
		AITRANSPORT.set_function("_SET_TRANSPORT_PRIORITY_SEAT", LUA_NATIVE_AITRANSPORT__SET_TRANSPORT_PRIORITY_SEAT);
	}
}
