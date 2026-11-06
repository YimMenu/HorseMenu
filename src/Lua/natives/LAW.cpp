#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_LAW__REPORT_CRIME(Player player, Hash crimeType, int bounty, Entity entity, bool isKnownSuspect)
	{
		LAW::_REPORT_CRIME(player, crimeType, bounty, entity, isKnownSuspect);
	}

	static void LUA_NATIVE_LAW_SUPPRESS_CRIME_THIS_FRAME(Player player, Hash crimeType, int p2, int p3, int p4)
	{
		LAW::SUPPRESS_CRIME_THIS_FRAME(player, crimeType, p2, p3, p4);
	}

	static int LUA_NATIVE_LAW_NUM_CRIMES_SUPPRESSED(Player player, Hash crimeType)
	{
		auto retval = LAW::NUM_CRIMES_SUPPRESSED(player, crimeType);
		return retval;
	}

	static Any LUA_NATIVE_LAW__0xFFEBE5AA96BC2E4E(Ped ped, Hash crimeType, bool p2)
	{
		auto retval = LAW::_0xFFEBE5AA96BC2E4E(ped, crimeType, p2);
		return retval;
	}

	static void LUA_NATIVE_LAW__0x15ABD5004CAD2D99(int p0)
	{
		LAW::_0x15ABD5004CAD2D99(p0);
	}

	static void LUA_NATIVE_LAW__0xF611DE44AEB36A1D(Hash crimeType, bool p1)
	{
		LAW::_0xF611DE44AEB36A1D(crimeType, p1);
	}

	static bool LUA_NATIVE_LAW__0x3D2674828A4E6B3C()
	{
		auto retval = (bool)LAW::_0x3D2674828A4E6B3C();
		return retval;
	}

	static void LUA_NATIVE_LAW__0xC5EB2755FA25F1E9(bool p0)
	{
		LAW::_0xC5EB2755FA25F1E9(p0);
	}

	static int LUA_NATIVE_LAW_GET_BOUNTY(Player player)
	{
		auto retval = LAW::GET_BOUNTY(player);
		return retval;
	}

	static void LUA_NATIVE_LAW_ADD_BOUNTY(Player player, int itemValueAmount)
	{
		LAW::ADD_BOUNTY(player, itemValueAmount);
	}

	static void LUA_NATIVE_LAW_SET_BOUNTY(Player player, int amount)
	{
		LAW::SET_BOUNTY(player, amount);
	}

	static void LUA_NATIVE_LAW_CLEAR_BOUNTY(Player player)
	{
		LAW::CLEAR_BOUNTY(player);
	}

	static int LUA_NATIVE_LAW_GET_WANTED_SCORE(Player player)
	{
		auto retval = LAW::GET_WANTED_SCORE(player);
		return retval;
	}

	static void LUA_NATIVE_LAW_SET_WANTED_SCORE(Player player, int intensity)
	{
		LAW::SET_WANTED_SCORE(player, intensity);
	}

	static void LUA_NATIVE_LAW_CLEAR_WANTED_SCORE(Player player)
	{
		LAW::CLEAR_WANTED_SCORE(player);
	}

	static void LUA_NATIVE_LAW__0x331D349E0380B097(Any p0)
	{
		LAW::_0x331D349E0380B097(p0);
	}

	static void LUA_NATIVE_LAW__0x292AD61A33A7A485()
	{
		LAW::_0x292AD61A33A7A485();
	}

	static void LUA_NATIVE_LAW__0x07E8B8B20570271C(Player player)
	{
		LAW::_0x07E8B8B20570271C(player);
	}

	static void LUA_NATIVE_LAW__0x22741652985C84D0(Player player, Hash lawRegionHash)
	{
		LAW::_0x22741652985C84D0(player, lawRegionHash);
	}

	static void LUA_NATIVE_LAW__REPORT_PLAYER_LAW_DISPATCH_RESPONSE_OVERRIDE(Player player, Hash dispatchResponseHash)
	{
		LAW::_REPORT_PLAYER_LAW_DISPATCH_RESPONSE_OVERRIDE(player, dispatchResponseHash);
	}

	static bool LUA_NATIVE_LAW__0x9EF07CFBB19A9733()
	{
		auto retval = (bool)LAW::_0x9EF07CFBB19A9733();
		return retval;
	}

	static void LUA_NATIVE_LAW__SET_LAW_DISABLED(bool toggle)
	{
		LAW::_SET_LAW_DISABLED(toggle);
	}

	static void LUA_NATIVE_LAW__FORCE_LAW_ON_LOCAL_PLAYER_IMMEDIATELY()
	{
		LAW::_FORCE_LAW_ON_LOCAL_PLAYER_IMMEDIATELY();
	}

	static void LUA_NATIVE_LAW__SET_LAW_REGION(Player player, Hash lawRegionHash, Hash stateHash)
	{
		LAW::_SET_LAW_REGION(player, lawRegionHash, stateHash);
	}

	static void LUA_NATIVE_LAW__0x5E6F375CA101C108(Player player, bool p1)
	{
		LAW::_0x5E6F375CA101C108(player, p1);
	}

	static void LUA_NATIVE_LAW__SET_LAW_RBS_VOLUME(Player player, Hash p1)
	{
		LAW::_SET_LAW_RBS_VOLUME(player, p1);
	}

	static bool LUA_NATIVE_LAW_IS_LAW_INCIDENT_ACTIVE(Player player)
	{
		auto retval = (bool)LAW::IS_LAW_INCIDENT_ACTIVE(player);
		return retval;
	}

	static Hash LUA_NATIVE_LAW__0x148E7AC8141C9E64(Player player)
	{
		auto retval = LAW::_0x148E7AC8141C9E64(player);
		return retval;
	}

	static void LUA_NATIVE_LAW__0xEDFC6C1FD1C964F5(Player player, Hash crimeType, int bounty, float p3, float p4, bool p5, float p6, float p7, Any p8)
	{
		LAW::_0xEDFC6C1FD1C964F5(player, crimeType, bounty, p3, p4, p5, p6, p7, p8);
	}

	static bool LUA_NATIVE_LAW__LAW_WITNESS_RESPONSE_TASK(Ped pedGroup1, Ped ped, Ped pedGroup2, float x, float y, float z, Hash crimeType)
	{
		auto retval = (bool)LAW::_LAW_WITNESS_RESPONSE_TASK(pedGroup1, ped, pedGroup2, x, y, z, crimeType);
		return retval;
	}

	static Any LUA_NATIVE_LAW__0x018F30D762E62DF8(Ped ped, uintptr_t p1)
	{
		auto retval = LAW::_0x018F30D762E62DF8(ped, (Any*)p1);
		return retval;
	}

	static Any LUA_NATIVE_LAW__0x318F0F9A4426CFA2(Ped ped, uintptr_t p1)
	{
		auto retval = LAW::_0x318F0F9A4426CFA2(ped, (Any*)p1);
		return retval;
	}

	static Any LUA_NATIVE_LAW__0x95878B13E272EF1F(Entity entity, Ped ped, bool p2, float x, float y, float z, Hash crimeType)
	{
		auto retval = LAW::_0x95878B13E272EF1F(entity, ped, p2, x, y, z, crimeType);
		return retval;
	}

	static void LUA_NATIVE_LAW__ADD_WITNESS_RESPONSE(Player player, Hash crimeType, Ped pedGroup)
	{
		LAW::_ADD_WITNESS_RESPONSE(player, crimeType, pedGroup);
	}

	static void LUA_NATIVE_LAW__0xD7494DED50C6EF52(Player player, Hash crimeType, int p2)
	{
		LAW::_0xD7494DED50C6EF52(player, crimeType, p2);
	}

	static bool LUA_NATIVE_LAW_ARE_WITNESSES_ACTIVE(Player player)
	{
		auto retval = (bool)LAW::ARE_WITNESSES_ACTIVE(player);
		return retval;
	}

	static bool LUA_NATIVE_LAW__ARE_WITNESSES_PENDING(Player player)
	{
		auto retval = (bool)LAW::_ARE_WITNESSES_PENDING(player);
		return retval;
	}

	static bool LUA_NATIVE_LAW__ARE_INVESTIGATORS_ACTIVE(Player player, bool areInvestigatorsActive, Any p2)
	{
		auto retval = (bool)LAW::_ARE_INVESTIGATORS_ACTIVE(player, areInvestigatorsActive, p2);
		return retval;
	}

	static void LUA_NATIVE_LAW__0x522F74636DF10201(Player player, ItemSet itemSet)
	{
		LAW::_0x522F74636DF10201(player, itemSet);
	}

	static void LUA_NATIVE_LAW__0xDA1A9ADC4E3D4B16(ItemSet itemSet, bool p1, bool p2)
	{
		LAW::_0xDA1A9ADC4E3D4B16(itemSet, p1, p2);
	}

	static void LUA_NATIVE_LAW__ENABLE_DISPATCH_LAW(bool toggle)
	{
		LAW::_ENABLE_DISPATCH_LAW(toggle);
	}

	static void LUA_NATIVE_LAW__ENABLE_DISPATCH_LAW_2(bool toggle)
	{
		LAW::_ENABLE_DISPATCH_LAW_2(toggle);
	}

	static bool LUA_NATIVE_LAW__ARE_ANY_LAW_PEDS_INVESTIGATING()
	{
		auto retval = (bool)LAW::_ARE_ANY_LAW_PEDS_INVESTIGATING();
		return retval;
	}

	static bool LUA_NATIVE_LAW__ARE_LAW_PEDS_ENABLED_FOR_TRAIN()
	{
		auto retval = (bool)LAW::_ARE_LAW_PEDS_ENABLED_FOR_TRAIN();
		return retval;
	}

	static void LUA_NATIVE_LAW__0x82F11E1296996574(int p0)
	{
		LAW::_0x82F11E1296996574(p0);
	}

	static void LUA_NATIVE_LAW__0x3852237A3D9DF145(int p0)
	{
		LAW::_0x3852237A3D9DF145(p0);
	}

	static bool LUA_NATIVE_LAW__0x0EAF918F751F27BA(Ped ped)
	{
		auto retval = (bool)LAW::_0x0EAF918F751F27BA(ped);
		return retval;
	}

	static bool LUA_NATIVE_LAW__0xC0DF161950FB101E(Ped ped)
	{
		auto retval = (bool)LAW::_0xC0DF161950FB101E(ped);
		return retval;
	}

	static Any LUA_NATIVE_LAW__0xE4D6E45F491A66CB(Player player, int p1)
	{
		auto retval = LAW::_0xE4D6E45F491A66CB(player, p1);
		return retval;
	}

	static int LUA_NATIVE_LAW__0xE9EB79CBF9C0F58A(Player player)
	{
		auto retval = LAW::_0xE9EB79CBF9C0F58A(player);
		return retval;
	}

	static Vector3 LUA_NATIVE_LAW__0x21213B833EF4DAE7(Player player, Ped ped, Vector3 outCoords)
	{
		LAW::_0x21213B833EF4DAE7(player, ped, &outCoords);
		return outCoords;
	}

	static void LUA_NATIVE_LAW__0x61B98367D93F012F(Player player)
	{
		LAW::_0x61B98367D93F012F(player);
	}

	static Hash LUA_NATIVE_LAW__0x6ABC50979655BEE7(Player player, Hash crimeType, Any p2)
	{
		LAW::_0x6ABC50979655BEE7(player, &crimeType, p2);
		return crimeType;
	}

	static void LUA_NATIVE_LAW__0x390710D2DAFA6BFF(Player player, bool p1)
	{
		LAW::_0x390710D2DAFA6BFF(player, p1);
	}

	static int LUA_NATIVE_LAW__GET_CRIME_BOUNTY_AMOUNT_BY_TYPE(Hash crimeType)
	{
		auto retval = LAW::_GET_CRIME_BOUNTY_AMOUNT_BY_TYPE(crimeType);
		return retval;
	}

	static int LUA_NATIVE_LAW__0xDAEFDFDB2AEECE37(Hash crimeType, Any p1)
	{
		auto retval = LAW::_0xDAEFDFDB2AEECE37(crimeType, p1);
		return retval;
	}

	static Hash LUA_NATIVE_LAW__GET_HUD_PLAYER_CRIME_TYPE(Player player)
	{
		auto retval = LAW::_GET_HUD_PLAYER_CRIME_TYPE(player);
		return retval;
	}

	static int LUA_NATIVE_LAW__0xE083BEDA81709891(Player player)
	{
		auto retval = LAW::_0xE083BEDA81709891(player);
		return retval;
	}

	static bool LUA_NATIVE_LAW__0x89E005B1662F6E48(Player player, int p1, int p2)
	{
		auto retval = (bool)LAW::_0x89E005B1662F6E48(player, p1, p2);
		return retval;
	}

	static bool LUA_NATIVE_LAW__0x3738B784DDD35CC6(Player player, int p1, int p2)
	{
		auto retval = (bool)LAW::_0x3738B784DDD35CC6(player, p1, p2);
		return retval;
	}

	static int LUA_NATIVE_LAW__0x0BDFEBCF40A5F7E3(Hash crimeType)
	{
		auto retval = LAW::_0x0BDFEBCF40A5F7E3(crimeType);
		return retval;
	}

	static void LUA_NATIVE_LAW__SET_CUSTOM_LAW_DISPATCH_RESPONSE(Hash dispatchResponseHash)
	{
		LAW::_SET_CUSTOM_LAW_DISPATCH_RESPONSE(dispatchResponseHash);
	}

	static Any LUA_NATIVE_LAW__CREATE_LAW_DISPATCH_RESPONSE_FOR_COORDS(float x, float y, float z, Hash dispatchResponseHash)
	{
		auto retval = LAW::_CREATE_LAW_DISPATCH_RESPONSE_FOR_COORDS(x, y, z, dispatchResponseHash);
		return retval;
	}

	static void LUA_NATIVE_LAW__SET_BOUNTY_HUNTER_PURSUIT_CLEARED()
	{
		LAW::_SET_BOUNTY_HUNTER_PURSUIT_CLEARED();
	}

	static void LUA_NATIVE_LAW__0xBD944A3D36E992DE()
	{
		LAW::_0xBD944A3D36E992DE();
	}

	static void LUA_NATIVE_LAW__0x987BE590FB9D41E5(bool p0)
	{
		LAW::_0x987BE590FB9D41E5(p0);
	}

	static void LUA_NATIVE_LAW__0xDCF12B89624AAC96(bool p0)
	{
		LAW::_0xDCF12B89624AAC96(p0);
	}

	static void LUA_NATIVE_LAW__0xDDCE8E960D1DE240(bool p0)
	{
		LAW::_0xDDCE8E960D1DE240(p0);
	}

	static void LUA_NATIVE_LAW__0xDEA083C16BB91345()
	{
		LAW::_0xDEA083C16BB91345();
	}

	static void LUA_NATIVE_LAW__0x9C8A2BF37E966464(Player player, ItemSet itemSet)
	{
		LAW::_0x9C8A2BF37E966464(player, itemSet);
	}

	static bool LUA_NATIVE_LAW__0x9D5C9A5A3321B128(Player player)
	{
		auto retval = (bool)LAW::_0x9D5C9A5A3321B128(player);
		return retval;
	}

	static bool LUA_NATIVE_LAW__0x0F230DE0DDBE3649(Player player)
	{
		auto retval = (bool)LAW::_0x0F230DE0DDBE3649(player);
		return retval;
	}

	static bool LUA_NATIVE_LAW__0x9945A3E2528A02E8(Player player)
	{
		auto retval = (bool)LAW::_0x9945A3E2528A02E8(player);
		return retval;
	}

	static float LUA_NATIVE_LAW__GET_TIME_SINCE_LAST_SEEN_BY_LAW(Player player)
	{
		auto retval = LAW::_GET_TIME_SINCE_LAST_SEEN_BY_LAW(player);
		return retval;
	}

	static void LUA_NATIVE_LAW__0x9B4C564BFA7CFF37(float p0)
	{
		LAW::_0x9B4C564BFA7CFF37(p0);
	}

	static void LUA_NATIVE_LAW__SET_ALLOW_DISABLED_LAW_RESPONSES(bool toggle)
	{
		LAW::_SET_ALLOW_DISABLED_LAW_RESPONSES(toggle);
	}

	static void LUA_NATIVE_LAW_RESET_WANTED_FOR_NEW_INCIDENT(Player player)
	{
		LAW::RESET_WANTED_FOR_NEW_INCIDENT(player);
	}

	static bool LUA_NATIVE_LAW__0x856CE8FDE2416602(Ped ped)
	{
		auto retval = (bool)LAW::_0x856CE8FDE2416602(ped);
		return retval;
	}

	static bool LUA_NATIVE_LAW__0x7351DA734F989F4E(Entity entity)
	{
		auto retval = (bool)LAW::_0x7351DA734F989F4E(entity);
		return retval;
	}

	static int LUA_NATIVE_LAW__GET_BOUNTY_HUNTER_GLOBAL_COOLDOWN(Hash p0)
	{
		auto retval = LAW::_GET_BOUNTY_HUNTER_GLOBAL_COOLDOWN(p0);
		return retval;
	}

	static void LUA_NATIVE_LAW__SET_BOUNTY_HUNTER_GLOBAL_COOLDOWN(Hash p0, int p1)
	{
		LAW::_SET_BOUNTY_HUNTER_GLOBAL_COOLDOWN(p0, p1);
	}

	static void LUA_NATIVE_LAW__0x2001687F9562FD9D(Any p0)
	{
		LAW::_0x2001687F9562FD9D(p0);
	}

	static void LUA_NATIVE_LAW__PAUSE_BOUNTY_HUNTER_COOLDOWN(Hash p0, bool p1, Any p2)
	{
		LAW::_PAUSE_BOUNTY_HUNTER_COOLDOWN(p0, p1, p2);
	}

	static void LUA_NATIVE_LAW__0xE9AC8466ABE484BB(bool p0, Any p1)
	{
		LAW::_0xE9AC8466ABE484BB(p0, p1);
	}

	static bool LUA_NATIVE_LAW__0x40851BCC33ACD9AB(Ped ped)
	{
		auto retval = (bool)LAW::_0x40851BCC33ACD9AB(ped);
		return retval;
	}

	static bool LUA_NATIVE_LAW__0xF46108C50A22B029()
	{
		auto retval = (bool)LAW::_0xF46108C50A22B029();
		return retval;
	}

	static void LUA_NATIVE_LAW__0x7803436E68C32B26()
	{
		LAW::_0x7803436E68C32B26();
	}

	static void LUA_NATIVE_LAW__0xC310239ACCCF5579()
	{
		LAW::_0xC310239ACCCF5579();
	}

	static void LUA_NATIVE_LAW__0x29CD4896ECB66C12()
	{
		LAW::_0x29CD4896ECB66C12();
	}

	static void LUA_NATIVE_LAW__0xE94B5E938619712E()
	{
		LAW::_0xE94B5E938619712E();
	}

	static int LUA_NATIVE_LAW__0x7FC667F6DDFBCDCC(Player player)
	{
		auto retval = LAW::_0x7FC667F6DDFBCDCC(player);
		return retval;
	}

	static Hash LUA_NATIVE_LAW__0x9C5BD8C562565CE6(Hash crimeType)
	{
		LAW::_0x9C5BD8C562565CE6(&crimeType);
		return crimeType;
	}

	static void LUA_NATIVE_LAW__0xCBFB4951F2E3934C(Player player, uintptr_t data)
	{
		LAW::_0xCBFB4951F2E3934C(player, (Any*)data);
	}

	static void LUA_NATIVE_LAW__SET_PED_LAW_BEHAVIOUR(Ped ped, int behaviour)
	{
		LAW::_SET_PED_LAW_BEHAVIOUR(ped, behaviour);
	}

	static void LUA_NATIVE_LAW__0x00DB0BC05E3FAA4E(Ped ped, int bitset)
	{
		LAW::_0x00DB0BC05E3FAA4E(ped, bitset);
	}

	static void LUA_NATIVE_LAW__0x0C392DB374655176(float x, float y, float z, float p3, ItemSet itemSet)
	{
		LAW::_0x0C392DB374655176(x, y, z, p3, itemSet);
	}

	static Any LUA_NATIVE_LAW__0xC687A23E166DCF68(uintptr_t p0)
	{
		auto retval = LAW::_0xC687A23E166DCF68((Any*)p0);
		return retval;
	}

	static void LUA_NATIVE_LAW__SET_DISPATCH_MULTIPLIER_OVERRIDE(float multiplier)
	{
		LAW::_SET_DISPATCH_MULTIPLIER_OVERRIDE(multiplier);
	}

	static bool LUA_NATIVE_LAW__0x26934083D3F2579C(Player player)
	{
		auto retval = (bool)LAW::_0x26934083D3F2579C(player);
		return retval;
	}

	static std::tuple<bool, Hash> LUA_NATIVE_LAW_GET_PLAYER_REGISTERED_CRIME(Player player, int p1, Hash crimeType)
	{
		std::tuple<bool, Hash> return_values;
		std::get<0>(return_values) = (bool)LAW::GET_PLAYER_REGISTERED_CRIME(player, p1, &crimeType);
		std::get<1>(return_values) = crimeType;

		return return_values;
	}

	static std::tuple<bool, Hash> LUA_NATIVE_LAW__0xB527099D1E1EED49(Player player, int p1, Hash crimeType)
	{
		std::tuple<bool, Hash> return_values;
		std::get<0>(return_values) = (bool)LAW::_0xB527099D1E1EED49(player, p1, &crimeType);
		std::get<1>(return_values) = crimeType;

		return return_values;
	}

	static void LUA_NATIVE_LAW_CLEAR_PLAYER_PAST_CRIMES(Player player)
	{
		LAW::CLEAR_PLAYER_PAST_CRIMES(player);
	}

	static void LUA_NATIVE_LAW_SET_PLAYER_ARRESTED_IN_REGION(Player player, Hash lawRegionHash)
	{
		LAW::SET_PLAYER_ARRESTED_IN_REGION(player, lawRegionHash);
	}

	static void LUA_NATIVE_LAW_SET_PLAYER_TURNED_IN_BOUNTY_IN_REGION(Player player, Hash lawRegionHash)
	{
		LAW::SET_PLAYER_TURNED_IN_BOUNTY_IN_REGION(player, lawRegionHash);
	}

	static void LUA_NATIVE_LAW__0xD6C0A8C7C0B2F82C(Player player, bool p1)
	{
		LAW::_0xD6C0A8C7C0B2F82C(player, p1);
	}

	static void LUA_NATIVE_LAW_SET_LAW_SENSE_RANGE_MODIFIER(Player player, float range)
	{
		LAW::SET_LAW_SENSE_RANGE_MODIFIER(player, range);
	}

	static void LUA_NATIVE_LAW__0x7EF2A2FE38D74456(int flag, bool p1)
	{
		LAW::_0x7EF2A2FE38D74456(flag, p1);
	}

	static bool LUA_NATIVE_LAW__0xC7DC5A0A7DF608CB(int flag)
	{
		auto retval = (bool)LAW::_0xC7DC5A0A7DF608CB(flag);
		return retval;
	}

	static void LUA_NATIVE_LAW_SET_DISABLE_DISTURBANCE_CRIMES(Player player, bool p1)
	{
		LAW::SET_DISABLE_DISTURBANCE_CRIMES(player, p1);
	}

	static void LUA_NATIVE_LAW_SET_POSTPONE_DISTURBANCE_CRIMES_DURING_COMBAT(Player player, bool p1)
	{
		LAW::SET_POSTPONE_DISTURBANCE_CRIMES_DURING_COMBAT(player, p1);
	}

	static void LUA_NATIVE_LAW__CREATE_GUARD_ZONE(sol::stack_object name)
	{
		LAW::_CREATE_GUARD_ZONE(name.is<const char*>() ? name.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_LAW__REMOVE_GUARD_ZONE(sol::stack_object name)
	{
		LAW::_REMOVE_GUARD_ZONE(name.is<const char*>() ? name.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_LAW__0x9772395CC73E8D1F(Ped ped, sol::stack_object name)
	{
		LAW::_0x9772395CC73E8D1F(ped, name.is<const char*>() ? name.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_LAW__DISABLE_GUARD_ZONE(sol::stack_object name)
	{
		LAW::_DISABLE_GUARD_ZONE(name.is<const char*>() ? name.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_LAW__0x0DBACA9C38C9A686(sol::stack_object name)
	{
		auto retval = (bool)LAW::_0x0DBACA9C38C9A686(name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_LAW__IS_GUARD_PED_INVESTIGATING(Ped ped)
	{
		auto retval = (bool)LAW::_IS_GUARD_PED_INVESTIGATING(ped);
		return retval;
	}

	static bool LUA_NATIVE_LAW__CREATE_GUARD_ZONE_FOR_ENTITY(sol::stack_object guardZoneName, Entity entity, float x, float y, float z)
	{
		auto retval = (bool)LAW::_CREATE_GUARD_ZONE_FOR_ENTITY(guardZoneName.is<const char*>() ? guardZoneName.as<const char*>() : nullptr, entity, x, y, z);
		return retval;
	}

	static void LUA_NATIVE_LAW__SET_GUARD_ZONE_VOLUME_REGISTRATION_START(sol::stack_object name, Volume volume)
	{
		LAW::_SET_GUARD_ZONE_VOLUME_REGISTRATION_START(name.is<const char*>() ? name.as<const char*>() : nullptr, volume);
	}

	static void LUA_NATIVE_LAW__SET_GUARD_ZONE_VOLUME_RESTRICTED(sol::stack_object name, Volume volume)
	{
		LAW::_SET_GUARD_ZONE_VOLUME_RESTRICTED(name.is<const char*>() ? name.as<const char*>() : nullptr, volume);
	}

	static void LUA_NATIVE_LAW__SET_GUARD_ZONE_VOLUME_THREAT(sol::stack_object name, Volume volume)
	{
		LAW::_SET_GUARD_ZONE_VOLUME_THREAT(name.is<const char*>() ? name.as<const char*>() : nullptr, volume);
	}

	static void LUA_NATIVE_LAW__SET_GUARD_ZONE_VOLUME_WARNING(sol::stack_object name, Volume volume)
	{
		LAW::_SET_GUARD_ZONE_VOLUME_WARNING(name.is<const char*>() ? name.as<const char*>() : nullptr, volume);
	}

	static void LUA_NATIVE_LAW__SET_GUARD_ZONE_VOLUME_REGISTRATION_END(sol::stack_object name, Volume volume)
	{
		LAW::_SET_GUARD_ZONE_VOLUME_REGISTRATION_END(name.is<const char*>() ? name.as<const char*>() : nullptr, volume);
	}

	static void LUA_NATIVE_LAW__SET_GUARD_ZONE_POSITION(sol::stack_object name, float x, float y, float z)
	{
		LAW::_SET_GUARD_ZONE_POSITION(name.is<const char*>() ? name.as<const char*>() : nullptr, x, y, z);
	}

	static void LUA_NATIVE_LAW__SET_GUARD_ZONE_POSITION_2(sol::stack_object name, float x, float y, float z)
	{
		LAW::_SET_GUARD_ZONE_POSITION_2(name.is<const char*>() ? name.as<const char*>() : nullptr, x, y, z);
	}

	void RegisterNatives_LAW(sol::state& L)
	{
		auto LAW = L["LAW"].get_or_create<sol::table>();
		LAW.set_function("_REPORT_CRIME", LUA_NATIVE_LAW__REPORT_CRIME);
		LAW.set_function("SUPPRESS_CRIME_THIS_FRAME", LUA_NATIVE_LAW_SUPPRESS_CRIME_THIS_FRAME);
		LAW.set_function("NUM_CRIMES_SUPPRESSED", LUA_NATIVE_LAW_NUM_CRIMES_SUPPRESSED);
		LAW.set_function("_0xFFEBE5AA96BC2E4E", LUA_NATIVE_LAW__0xFFEBE5AA96BC2E4E);
		LAW.set_function("_0x15ABD5004CAD2D99", LUA_NATIVE_LAW__0x15ABD5004CAD2D99);
		LAW.set_function("_0xF611DE44AEB36A1D", LUA_NATIVE_LAW__0xF611DE44AEB36A1D);
		LAW.set_function("_0x3D2674828A4E6B3C", LUA_NATIVE_LAW__0x3D2674828A4E6B3C);
		LAW.set_function("_0xC5EB2755FA25F1E9", LUA_NATIVE_LAW__0xC5EB2755FA25F1E9);
		LAW.set_function("GET_BOUNTY", LUA_NATIVE_LAW_GET_BOUNTY);
		LAW.set_function("ADD_BOUNTY", LUA_NATIVE_LAW_ADD_BOUNTY);
		LAW.set_function("SET_BOUNTY", LUA_NATIVE_LAW_SET_BOUNTY);
		LAW.set_function("CLEAR_BOUNTY", LUA_NATIVE_LAW_CLEAR_BOUNTY);
		LAW.set_function("GET_WANTED_SCORE", LUA_NATIVE_LAW_GET_WANTED_SCORE);
		LAW.set_function("SET_WANTED_SCORE", LUA_NATIVE_LAW_SET_WANTED_SCORE);
		LAW.set_function("CLEAR_WANTED_SCORE", LUA_NATIVE_LAW_CLEAR_WANTED_SCORE);
		LAW.set_function("_0x331D349E0380B097", LUA_NATIVE_LAW__0x331D349E0380B097);
		LAW.set_function("_0x292AD61A33A7A485", LUA_NATIVE_LAW__0x292AD61A33A7A485);
		LAW.set_function("_0x07E8B8B20570271C", LUA_NATIVE_LAW__0x07E8B8B20570271C);
		LAW.set_function("_0x22741652985C84D0", LUA_NATIVE_LAW__0x22741652985C84D0);
		LAW.set_function("_REPORT_PLAYER_LAW_DISPATCH_RESPONSE_OVERRIDE", LUA_NATIVE_LAW__REPORT_PLAYER_LAW_DISPATCH_RESPONSE_OVERRIDE);
		LAW.set_function("_0x9EF07CFBB19A9733", LUA_NATIVE_LAW__0x9EF07CFBB19A9733);
		LAW.set_function("_SET_LAW_DISABLED", LUA_NATIVE_LAW__SET_LAW_DISABLED);
		LAW.set_function("_FORCE_LAW_ON_LOCAL_PLAYER_IMMEDIATELY", LUA_NATIVE_LAW__FORCE_LAW_ON_LOCAL_PLAYER_IMMEDIATELY);
		LAW.set_function("_SET_LAW_REGION", LUA_NATIVE_LAW__SET_LAW_REGION);
		LAW.set_function("_0x5E6F375CA101C108", LUA_NATIVE_LAW__0x5E6F375CA101C108);
		LAW.set_function("_SET_LAW_RBS_VOLUME", LUA_NATIVE_LAW__SET_LAW_RBS_VOLUME);
		LAW.set_function("IS_LAW_INCIDENT_ACTIVE", LUA_NATIVE_LAW_IS_LAW_INCIDENT_ACTIVE);
		LAW.set_function("_0x148E7AC8141C9E64", LUA_NATIVE_LAW__0x148E7AC8141C9E64);
		LAW.set_function("_0xEDFC6C1FD1C964F5", LUA_NATIVE_LAW__0xEDFC6C1FD1C964F5);
		LAW.set_function("_LAW_WITNESS_RESPONSE_TASK", LUA_NATIVE_LAW__LAW_WITNESS_RESPONSE_TASK);
		LAW.set_function("_0x018F30D762E62DF8", LUA_NATIVE_LAW__0x018F30D762E62DF8);
		LAW.set_function("_0x318F0F9A4426CFA2", LUA_NATIVE_LAW__0x318F0F9A4426CFA2);
		LAW.set_function("_0x95878B13E272EF1F", LUA_NATIVE_LAW__0x95878B13E272EF1F);
		LAW.set_function("_ADD_WITNESS_RESPONSE", LUA_NATIVE_LAW__ADD_WITNESS_RESPONSE);
		LAW.set_function("_0xD7494DED50C6EF52", LUA_NATIVE_LAW__0xD7494DED50C6EF52);
		LAW.set_function("ARE_WITNESSES_ACTIVE", LUA_NATIVE_LAW_ARE_WITNESSES_ACTIVE);
		LAW.set_function("_ARE_WITNESSES_PENDING", LUA_NATIVE_LAW__ARE_WITNESSES_PENDING);
		LAW.set_function("_ARE_INVESTIGATORS_ACTIVE", LUA_NATIVE_LAW__ARE_INVESTIGATORS_ACTIVE);
		LAW.set_function("_0x522F74636DF10201", LUA_NATIVE_LAW__0x522F74636DF10201);
		LAW.set_function("_0xDA1A9ADC4E3D4B16", LUA_NATIVE_LAW__0xDA1A9ADC4E3D4B16);
		LAW.set_function("_ENABLE_DISPATCH_LAW", LUA_NATIVE_LAW__ENABLE_DISPATCH_LAW);
		LAW.set_function("_ENABLE_DISPATCH_LAW_2", LUA_NATIVE_LAW__ENABLE_DISPATCH_LAW_2);
		LAW.set_function("_ARE_ANY_LAW_PEDS_INVESTIGATING", LUA_NATIVE_LAW__ARE_ANY_LAW_PEDS_INVESTIGATING);
		LAW.set_function("_ARE_LAW_PEDS_ENABLED_FOR_TRAIN", LUA_NATIVE_LAW__ARE_LAW_PEDS_ENABLED_FOR_TRAIN);
		LAW.set_function("_0x82F11E1296996574", LUA_NATIVE_LAW__0x82F11E1296996574);
		LAW.set_function("_0x3852237A3D9DF145", LUA_NATIVE_LAW__0x3852237A3D9DF145);
		LAW.set_function("_0x0EAF918F751F27BA", LUA_NATIVE_LAW__0x0EAF918F751F27BA);
		LAW.set_function("_0xC0DF161950FB101E", LUA_NATIVE_LAW__0xC0DF161950FB101E);
		LAW.set_function("_0xE4D6E45F491A66CB", LUA_NATIVE_LAW__0xE4D6E45F491A66CB);
		LAW.set_function("_0xE9EB79CBF9C0F58A", LUA_NATIVE_LAW__0xE9EB79CBF9C0F58A);
		LAW.set_function("_0x21213B833EF4DAE7", LUA_NATIVE_LAW__0x21213B833EF4DAE7);
		LAW.set_function("_0x61B98367D93F012F", LUA_NATIVE_LAW__0x61B98367D93F012F);
		LAW.set_function("_0x6ABC50979655BEE7", LUA_NATIVE_LAW__0x6ABC50979655BEE7);
		LAW.set_function("_0x390710D2DAFA6BFF", LUA_NATIVE_LAW__0x390710D2DAFA6BFF);
		LAW.set_function("_GET_CRIME_BOUNTY_AMOUNT_BY_TYPE", LUA_NATIVE_LAW__GET_CRIME_BOUNTY_AMOUNT_BY_TYPE);
		LAW.set_function("_0xDAEFDFDB2AEECE37", LUA_NATIVE_LAW__0xDAEFDFDB2AEECE37);
		LAW.set_function("_GET_HUD_PLAYER_CRIME_TYPE", LUA_NATIVE_LAW__GET_HUD_PLAYER_CRIME_TYPE);
		LAW.set_function("_0xE083BEDA81709891", LUA_NATIVE_LAW__0xE083BEDA81709891);
		LAW.set_function("_0x89E005B1662F6E48", LUA_NATIVE_LAW__0x89E005B1662F6E48);
		LAW.set_function("_0x3738B784DDD35CC6", LUA_NATIVE_LAW__0x3738B784DDD35CC6);
		LAW.set_function("_0x0BDFEBCF40A5F7E3", LUA_NATIVE_LAW__0x0BDFEBCF40A5F7E3);
		LAW.set_function("_SET_CUSTOM_LAW_DISPATCH_RESPONSE", LUA_NATIVE_LAW__SET_CUSTOM_LAW_DISPATCH_RESPONSE);
		LAW.set_function("_CREATE_LAW_DISPATCH_RESPONSE_FOR_COORDS", LUA_NATIVE_LAW__CREATE_LAW_DISPATCH_RESPONSE_FOR_COORDS);
		LAW.set_function("_SET_BOUNTY_HUNTER_PURSUIT_CLEARED", LUA_NATIVE_LAW__SET_BOUNTY_HUNTER_PURSUIT_CLEARED);
		LAW.set_function("_0xBD944A3D36E992DE", LUA_NATIVE_LAW__0xBD944A3D36E992DE);
		LAW.set_function("_0x987BE590FB9D41E5", LUA_NATIVE_LAW__0x987BE590FB9D41E5);
		LAW.set_function("_0xDCF12B89624AAC96", LUA_NATIVE_LAW__0xDCF12B89624AAC96);
		LAW.set_function("_0xDDCE8E960D1DE240", LUA_NATIVE_LAW__0xDDCE8E960D1DE240);
		LAW.set_function("_0xDEA083C16BB91345", LUA_NATIVE_LAW__0xDEA083C16BB91345);
		LAW.set_function("_0x9C8A2BF37E966464", LUA_NATIVE_LAW__0x9C8A2BF37E966464);
		LAW.set_function("_0x9D5C9A5A3321B128", LUA_NATIVE_LAW__0x9D5C9A5A3321B128);
		LAW.set_function("_0x0F230DE0DDBE3649", LUA_NATIVE_LAW__0x0F230DE0DDBE3649);
		LAW.set_function("_0x9945A3E2528A02E8", LUA_NATIVE_LAW__0x9945A3E2528A02E8);
		LAW.set_function("_GET_TIME_SINCE_LAST_SEEN_BY_LAW", LUA_NATIVE_LAW__GET_TIME_SINCE_LAST_SEEN_BY_LAW);
		LAW.set_function("_0x9B4C564BFA7CFF37", LUA_NATIVE_LAW__0x9B4C564BFA7CFF37);
		LAW.set_function("_SET_ALLOW_DISABLED_LAW_RESPONSES", LUA_NATIVE_LAW__SET_ALLOW_DISABLED_LAW_RESPONSES);
		LAW.set_function("RESET_WANTED_FOR_NEW_INCIDENT", LUA_NATIVE_LAW_RESET_WANTED_FOR_NEW_INCIDENT);
		LAW.set_function("_0x856CE8FDE2416602", LUA_NATIVE_LAW__0x856CE8FDE2416602);
		LAW.set_function("_0x7351DA734F989F4E", LUA_NATIVE_LAW__0x7351DA734F989F4E);
		LAW.set_function("_GET_BOUNTY_HUNTER_GLOBAL_COOLDOWN", LUA_NATIVE_LAW__GET_BOUNTY_HUNTER_GLOBAL_COOLDOWN);
		LAW.set_function("_SET_BOUNTY_HUNTER_GLOBAL_COOLDOWN", LUA_NATIVE_LAW__SET_BOUNTY_HUNTER_GLOBAL_COOLDOWN);
		LAW.set_function("_0x2001687F9562FD9D", LUA_NATIVE_LAW__0x2001687F9562FD9D);
		LAW.set_function("_PAUSE_BOUNTY_HUNTER_COOLDOWN", LUA_NATIVE_LAW__PAUSE_BOUNTY_HUNTER_COOLDOWN);
		LAW.set_function("_0xE9AC8466ABE484BB", LUA_NATIVE_LAW__0xE9AC8466ABE484BB);
		LAW.set_function("_0x40851BCC33ACD9AB", LUA_NATIVE_LAW__0x40851BCC33ACD9AB);
		LAW.set_function("_0xF46108C50A22B029", LUA_NATIVE_LAW__0xF46108C50A22B029);
		LAW.set_function("_0x7803436E68C32B26", LUA_NATIVE_LAW__0x7803436E68C32B26);
		LAW.set_function("_0xC310239ACCCF5579", LUA_NATIVE_LAW__0xC310239ACCCF5579);
		LAW.set_function("_0x29CD4896ECB66C12", LUA_NATIVE_LAW__0x29CD4896ECB66C12);
		LAW.set_function("_0xE94B5E938619712E", LUA_NATIVE_LAW__0xE94B5E938619712E);
		LAW.set_function("_0x7FC667F6DDFBCDCC", LUA_NATIVE_LAW__0x7FC667F6DDFBCDCC);
		LAW.set_function("_0x9C5BD8C562565CE6", LUA_NATIVE_LAW__0x9C5BD8C562565CE6);
		LAW.set_function("_0xCBFB4951F2E3934C", LUA_NATIVE_LAW__0xCBFB4951F2E3934C);
		LAW.set_function("_SET_PED_LAW_BEHAVIOUR", LUA_NATIVE_LAW__SET_PED_LAW_BEHAVIOUR);
		LAW.set_function("_0x00DB0BC05E3FAA4E", LUA_NATIVE_LAW__0x00DB0BC05E3FAA4E);
		LAW.set_function("_0x0C392DB374655176", LUA_NATIVE_LAW__0x0C392DB374655176);
		LAW.set_function("_0xC687A23E166DCF68", LUA_NATIVE_LAW__0xC687A23E166DCF68);
		LAW.set_function("_SET_DISPATCH_MULTIPLIER_OVERRIDE", LUA_NATIVE_LAW__SET_DISPATCH_MULTIPLIER_OVERRIDE);
		LAW.set_function("_0x26934083D3F2579C", LUA_NATIVE_LAW__0x26934083D3F2579C);
		LAW.set_function("GET_PLAYER_REGISTERED_CRIME", LUA_NATIVE_LAW_GET_PLAYER_REGISTERED_CRIME);
		LAW.set_function("_0xB527099D1E1EED49", LUA_NATIVE_LAW__0xB527099D1E1EED49);
		LAW.set_function("CLEAR_PLAYER_PAST_CRIMES", LUA_NATIVE_LAW_CLEAR_PLAYER_PAST_CRIMES);
		LAW.set_function("SET_PLAYER_ARRESTED_IN_REGION", LUA_NATIVE_LAW_SET_PLAYER_ARRESTED_IN_REGION);
		LAW.set_function("SET_PLAYER_TURNED_IN_BOUNTY_IN_REGION", LUA_NATIVE_LAW_SET_PLAYER_TURNED_IN_BOUNTY_IN_REGION);
		LAW.set_function("_0xD6C0A8C7C0B2F82C", LUA_NATIVE_LAW__0xD6C0A8C7C0B2F82C);
		LAW.set_function("SET_LAW_SENSE_RANGE_MODIFIER", LUA_NATIVE_LAW_SET_LAW_SENSE_RANGE_MODIFIER);
		LAW.set_function("_0x7EF2A2FE38D74456", LUA_NATIVE_LAW__0x7EF2A2FE38D74456);
		LAW.set_function("_0xC7DC5A0A7DF608CB", LUA_NATIVE_LAW__0xC7DC5A0A7DF608CB);
		LAW.set_function("SET_DISABLE_DISTURBANCE_CRIMES", LUA_NATIVE_LAW_SET_DISABLE_DISTURBANCE_CRIMES);
		LAW.set_function("SET_POSTPONE_DISTURBANCE_CRIMES_DURING_COMBAT", LUA_NATIVE_LAW_SET_POSTPONE_DISTURBANCE_CRIMES_DURING_COMBAT);
		LAW.set_function("_CREATE_GUARD_ZONE", LUA_NATIVE_LAW__CREATE_GUARD_ZONE);
		LAW.set_function("_REMOVE_GUARD_ZONE", LUA_NATIVE_LAW__REMOVE_GUARD_ZONE);
		LAW.set_function("_0x9772395CC73E8D1F", LUA_NATIVE_LAW__0x9772395CC73E8D1F);
		LAW.set_function("_DISABLE_GUARD_ZONE", LUA_NATIVE_LAW__DISABLE_GUARD_ZONE);
		LAW.set_function("_0x0DBACA9C38C9A686", LUA_NATIVE_LAW__0x0DBACA9C38C9A686);
		LAW.set_function("_IS_GUARD_PED_INVESTIGATING", LUA_NATIVE_LAW__IS_GUARD_PED_INVESTIGATING);
		LAW.set_function("_CREATE_GUARD_ZONE_FOR_ENTITY", LUA_NATIVE_LAW__CREATE_GUARD_ZONE_FOR_ENTITY);
		LAW.set_function("_SET_GUARD_ZONE_VOLUME_REGISTRATION_START", LUA_NATIVE_LAW__SET_GUARD_ZONE_VOLUME_REGISTRATION_START);
		LAW.set_function("_SET_GUARD_ZONE_VOLUME_RESTRICTED", LUA_NATIVE_LAW__SET_GUARD_ZONE_VOLUME_RESTRICTED);
		LAW.set_function("_SET_GUARD_ZONE_VOLUME_THREAT", LUA_NATIVE_LAW__SET_GUARD_ZONE_VOLUME_THREAT);
		LAW.set_function("_SET_GUARD_ZONE_VOLUME_WARNING", LUA_NATIVE_LAW__SET_GUARD_ZONE_VOLUME_WARNING);
		LAW.set_function("_SET_GUARD_ZONE_VOLUME_REGISTRATION_END", LUA_NATIVE_LAW__SET_GUARD_ZONE_VOLUME_REGISTRATION_END);
		LAW.set_function("_SET_GUARD_ZONE_POSITION", LUA_NATIVE_LAW__SET_GUARD_ZONE_POSITION);
		LAW.set_function("_SET_GUARD_ZONE_POSITION_2", LUA_NATIVE_LAW__SET_GUARD_ZONE_POSITION_2);
	}
}
