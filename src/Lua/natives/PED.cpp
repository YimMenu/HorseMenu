#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static Ped LUA_NATIVE_PED_CREATE_PED(Hash PedModelHashKey, float VecNewCoorsX, float VecNewCoorsY, float VecNewCoorsZ, float fPedHeading, bool RegisterAsNetworkObject, bool ScriptHostObject, bool p7, bool p8)
	{
		auto retval = PED::CREATE_PED(PedModelHashKey, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ, fPedHeading, RegisterAsNetworkObject, ScriptHostObject, p7, p8);
		return retval;
	}

	static Ped LUA_NATIVE_PED_DELETE_PED(Ped PedIndex)
	{
		PED::DELETE_PED(&PedIndex);
		return PedIndex;
	}

	static void LUA_NATIVE_PED__SET_REMOVE_PED_NETWORKED(Ped ped, int p1)
	{
		PED::_SET_REMOVE_PED_NETWORKED(ped, p1);
	}

	static void LUA_NATIVE_PED__0x7C08E7CB8D951B70(Ped ped, float p1)
	{
		PED::_0x7C08E7CB8D951B70(ped, p1);
	}

	static void LUA_NATIVE_PED__SET_PED_TO_BE_REMOVED(Ped ped, float p1, float p2, int p3, Any p4)
	{
		PED::_SET_PED_TO_BE_REMOVED(ped, p1, p2, p3, p4);
	}

	static Ped LUA_NATIVE_PED_CLONE_PED(Ped PedIndex, bool bRegisterAsNetworkObject, bool bScriptHostObject, bool bLinkBlends)
	{
		auto retval = PED::CLONE_PED(PedIndex, bRegisterAsNetworkObject, bScriptHostObject, bLinkBlends);
		return retval;
	}

	static void LUA_NATIVE_PED_CLONE_PED_TO_TARGET(Ped PedIndexSource, Ped PedIndexTarget)
	{
		PED::CLONE_PED_TO_TARGET(PedIndexSource, PedIndexTarget);
	}

	static bool LUA_NATIVE_PED_IS_PED_IN_VEHICLE(Ped PedIndex, Vehicle VehicleIndex, bool ConsiderEnteringAsInVehicle)
	{
		auto retval = (bool)PED::IS_PED_IN_VEHICLE(PedIndex, VehicleIndex, ConsiderEnteringAsInVehicle);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_IN_MODEL(Ped PedIndex, Hash VehicleModelHashKey)
	{
		auto retval = (bool)PED::IS_PED_IN_MODEL(PedIndex, VehicleModelHashKey);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_IN_ANY_VEHICLE(Ped PedIndex, bool ConsiderEnteringAsInVehicle)
	{
		auto retval = (bool)PED::IS_PED_IN_ANY_VEHICLE(PedIndex, ConsiderEnteringAsInVehicle);
		return retval;
	}

	static void LUA_NATIVE_PED__0x9851DE7AEC10B4E1(float x, float y, float z, float p3, int p4, Any p5)
	{
		PED::_0x9851DE7AEC10B4E1(x, y, z, p3, p4, p5);
	}

	static bool LUA_NATIVE_PED_IS_PED_INJURED(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_INJURED(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_FATALLY_INJURED(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_FATALLY_INJURED(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_DEAD_OR_DYING(Ped PedIndex, bool CheckMeleeDeathFlags)
	{
		auto retval = (bool)PED::IS_PED_DEAD_OR_DYING(PedIndex, CheckMeleeDeathFlags);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_BLEEDOUT_PROFILE(Ped ped, Hash bleedoutProfile)
	{
		PED::_SET_PED_BLEEDOUT_PROFILE(ped, bleedoutProfile);
	}

	static bool LUA_NATIVE_PED_IS_PED_AIMING_FROM_COVER(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_AIMING_FROM_COVER(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_RELOADING(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_RELOADING(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_A_PLAYER(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_A_PLAYER(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_ANIMAL_CONTROLLED_BY_A_PLAYER(Ped ped)
	{
		auto retval = (bool)PED::_IS_ANIMAL_CONTROLLED_BY_A_PLAYER(ped);
		return retval;
	}

	static Ped LUA_NATIVE_PED_CREATE_PED_INSIDE_VEHICLE(Vehicle VehicleIndex, Hash PedModelHashKey, int Seat, bool RegisterAsNetworkObject, bool ScriptHostObject, bool p5)
	{
		auto retval = PED::CREATE_PED_INSIDE_VEHICLE(VehicleIndex, PedModelHashKey, Seat, RegisterAsNetworkObject, ScriptHostObject, p5);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_DESIRED_HEADING(Ped PedIndex, float DesiredHeading)
	{
		PED::SET_PED_DESIRED_HEADING(PedIndex, DesiredHeading);
	}

	static void LUA_NATIVE_PED_FORCE_ALL_HEADING_VALUES_TO_ALIGN(Ped PedIndex)
	{
		PED::FORCE_ALL_HEADING_VALUES_TO_ALIGN(PedIndex);
	}

	static bool LUA_NATIVE_PED_IS_PED_FACING_PED(Ped PedIndex1, Ped PedIndex2, float Degrees)
	{
		auto retval = (bool)PED::IS_PED_FACING_PED(PedIndex1, PedIndex2, Degrees);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_IN_MELEE_COMBAT(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_IN_MELEE_COMBAT(PedIndex);
		return retval;
	}

	static Any LUA_NATIVE_PED__0x6DB875AFC584FA32(Ped ped, int p1)
	{
		auto retval = PED::_0x6DB875AFC584FA32(ped, p1);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_STOPPED(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_STOPPED(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_SITTING(Ped ped)
	{
		auto retval = (bool)PED::IS_PED_SITTING(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x09D7AFD3716DA8E1(Ped ped, int p1)
	{
		auto retval = (bool)PED::_0x09D7AFD3716DA8E1(ped, p1);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x9C81338B2E62CE0A(Player player, Ped ped, int shotNearRecentlyTime)
	{
		auto retval = (bool)PED::_0x9C81338B2E62CE0A(player, ped, shotNearRecentlyTime);
		return retval;
	}

	static bool LUA_NATIVE_PED__0xB7DBB2986B87E230(Ped ped, float p1)
	{
		auto retval = (bool)PED::_0xB7DBB2986B87E230(ped, p1);
		return retval;
	}

	static bool LUA_NATIVE_PED__0xD355E2F1BB41087E(Ped ped, float p1)
	{
		auto retval = (bool)PED::_0xD355E2F1BB41087E(ped, p1);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_ANY_PED_SHOOTING_IN_AREA(float vMinX, float vMinY, float vMinZ, float vMaxX, float vMaxY, float vMaxZ, bool HighlightArea, bool bDo3DCheck)
	{
		auto retval = (bool)PED::IS_ANY_PED_SHOOTING_IN_AREA(vMinX, vMinY, vMinZ, vMaxX, vMaxY, vMaxZ, HighlightArea, bDo3DCheck);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_SHOOTING(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_SHOOTING(PedIndex);
		return retval;
	}

	static float LUA_NATIVE_PED_TIME_SINCE_PED_LAST_SHOT(Ped ped)
	{
		auto retval = PED::TIME_SINCE_PED_LAST_SHOT(ped);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_ACCURACY(Ped PedIndex, int NewAccuracy)
	{
		PED::SET_PED_ACCURACY(PedIndex, NewAccuracy);
	}

	static int LUA_NATIVE_PED_GET_PED_ACCURACY(Ped PedIndex)
	{
		auto retval = PED::GET_PED_ACCURACY(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_MODEL(Ped PedIndex, Hash PedModelHashKey)
	{
		auto retval = (bool)PED::IS_PED_MODEL(PedIndex, PedModelHashKey);
		return retval;
	}

	static void LUA_NATIVE_PED_EXPLODE_PED_HEAD(Ped PedIndex, Hash wtWeapon)
	{
		PED::EXPLODE_PED_HEAD(PedIndex, wtWeapon);
	}

	static void LUA_NATIVE_PED_ADD_ARMOUR_TO_PED(Ped PedIndex, int ArmourToAdd)
	{
		PED::ADD_ARMOUR_TO_PED(PedIndex, ArmourToAdd);
	}

	static void LUA_NATIVE_PED__0x5CA20FBE49891BBD(Ped ped, int p1)
	{
		PED::_0x5CA20FBE49891BBD(ped, p1);
	}

	static void LUA_NATIVE_PED_SET_PED_INTO_VEHICLE(Ped PedIndex, Vehicle VehicleIndex, int seat)
	{
		PED::SET_PED_INTO_VEHICLE(PedIndex, VehicleIndex, seat);
	}

	static void LUA_NATIVE_PED_SET_PED_MOVE_ANIMS_BLEND_OUT(Ped PedIndex)
	{
		PED::SET_PED_MOVE_ANIMS_BLEND_OUT(PedIndex);
	}

	static void LUA_NATIVE_PED__0x606D529DADA3C940(Ped ped, Any p1)
	{
		PED::_0x606D529DADA3C940(ped, p1);
	}

	static bool LUA_NATIVE_PED_IS_PED_MALE(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_MALE(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_HUMAN(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_HUMAN(PedIndex);
		return retval;
	}

	static Vehicle LUA_NATIVE_PED_GET_VEHICLE_PED_IS_IN(Ped PedIndex, bool ConsiderEnteringAsInVehicle)
	{
		auto retval = PED::GET_VEHICLE_PED_IS_IN(PedIndex, ConsiderEnteringAsInVehicle);
		return retval;
	}

	static void LUA_NATIVE_PED_RESET_PED_LAST_VEHICLE(Ped PedIndex)
	{
		PED::RESET_PED_LAST_VEHICLE(PedIndex);
	}

	static void LUA_NATIVE_PED__0xC6136B40FFFB778B(bool p0)
	{
		PED::_0xC6136B40FFFB778B(p0);
	}

	static void LUA_NATIVE_PED__0x6E8B87139854022D(Ped ped, sol::stack_object clipset)
	{
		PED::_0x6E8B87139854022D(ped, clipset.is<const char*>() ? clipset.as<const char*>() : nullptr);
	}

	static int LUA_NATIVE_PED__GET_NUM_FREE_SLOTS_IN_PED_POOL()
	{
		auto retval = PED::_GET_NUM_FREE_SLOTS_IN_PED_POOL();
		return retval;
	}

	static void LUA_NATIVE_PED__RESERVE_AMBIENT_PEDS(int numPeds)
	{
		PED::_RESERVE_AMBIENT_PEDS(numPeds);
	}

	static void LUA_NATIVE_PED__RESERVE_AMBIENT_PEDS_TOTAL(int numPeds)
	{
		PED::_RESERVE_AMBIENT_PEDS_TOTAL(numPeds);
	}

	static void LUA_NATIVE_PED__UNRESERVE_AMBIENT_PEDS(int numPeds)
	{
		PED::_UNRESERVE_AMBIENT_PEDS(numPeds);
	}

	static int LUA_NATIVE_PED__GET_NUM_RESERVED_AMBIENT_PEDS_DESIRED()
	{
		auto retval = PED::_GET_NUM_RESERVED_AMBIENT_PEDS_DESIRED();
		return retval;
	}

	static int LUA_NATIVE_PED__GET_NUM_RESERVED_AMBIENT_PEDS_READY()
	{
		auto retval = PED::_GET_NUM_RESERVED_AMBIENT_PEDS_READY();
		return retval;
	}

	static bool LUA_NATIVE_PED__ARE_ALL_AMBIENT_PED_RESERVATIONS_READY()
	{
		auto retval = (bool)PED::_ARE_ALL_AMBIENT_PED_RESERVATIONS_READY();
		return retval;
	}

	static void LUA_NATIVE_PED__SET_SCENARIO_PED_RANGE_MULTIPLIER_THIS_FRAME(float multiplier)
	{
		PED::_SET_SCENARIO_PED_RANGE_MULTIPLIER_THIS_FRAME(multiplier);
	}

	static void LUA_NATIVE_PED__0x9E3842E5DAD69F80(Volume volume)
	{
		PED::_0x9E3842E5DAD69F80(volume);
	}

	static void LUA_NATIVE_PED__SET_AMBIENT_PED_DENSITY_MULTIPLIER_THIS_FRAME(float multiplier)
	{
		PED::_SET_AMBIENT_PED_DENSITY_MULTIPLIER_THIS_FRAME(multiplier);
	}

	static void LUA_NATIVE_PED_SET_SCENARIO_PED_DENSITY_MULTIPLIER_THIS_FRAME(float multiplier)
	{
		PED::SET_SCENARIO_PED_DENSITY_MULTIPLIER_THIS_FRAME(multiplier);
	}

	static void LUA_NATIVE_PED__SET_AMBIENT_ANIMAL_DENSITY_MULTIPLIER_THIS_FRAME(float multiplier)
	{
		PED::_SET_AMBIENT_ANIMAL_DENSITY_MULTIPLIER_THIS_FRAME(multiplier);
	}

	static void LUA_NATIVE_PED__SET_AMBIENT_HUMAN_DENSITY_MULTIPLIER_THIS_FRAME(float multiplier)
	{
		PED::_SET_AMBIENT_HUMAN_DENSITY_MULTIPLIER_THIS_FRAME(multiplier);
	}

	static void LUA_NATIVE_PED__SET_SCENARIO_ANIMAL_DENSITY_MULTIPLIER_THIS_FRAME(float multiplier)
	{
		PED::_SET_SCENARIO_ANIMAL_DENSITY_MULTIPLIER_THIS_FRAME(multiplier);
	}

	static void LUA_NATIVE_PED__SET_SCENARIO_HUMAN_DENSITY_MULTIPLIER_THIS_FRAME(float multiplier)
	{
		PED::_SET_SCENARIO_HUMAN_DENSITY_MULTIPLIER_THIS_FRAME(multiplier);
	}

	static void LUA_NATIVE_PED__SET_SCENARIO_PED_DENSITY_THIS_FRAME(Hash configHash)
	{
		PED::_SET_SCENARIO_PED_DENSITY_THIS_FRAME(configHash);
	}

	static void LUA_NATIVE_PED_INSTANTLY_FILL_PED_POPULATION()
	{
		PED::INSTANTLY_FILL_PED_POPULATION();
	}

	static void LUA_NATIVE_PED__0xBFA6B7731C3BAF02()
	{
		PED::_0xBFA6B7731C3BAF02();
	}

	static bool LUA_NATIVE_PED_IS_INSTANTLY_FILL_PED_POPULATION_FINISHED()
	{
		auto retval = (bool)PED::IS_INSTANTLY_FILL_PED_POPULATION_FINISHED();
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_NON_CREATION_AREA(float MinX, float MinY, float MinZ, float MaxX, float MaxY, float MaxZ)
	{
		PED::SET_PED_NON_CREATION_AREA(MinX, MinY, MinZ, MaxX, MaxY, MaxZ);
	}

	static void LUA_NATIVE_PED_CLEAR_PED_NON_CREATION_AREA()
	{
		PED::CLEAR_PED_NON_CREATION_AREA();
	}

	static void LUA_NATIVE_PED__ATTACH_VOLUME_TO_ENTITY(Volume volume, Entity entity, float offsetX, float offsetY, float offsetZ, float rotX, float rotY, float rotZ, int p8, bool p9)
	{
		PED::_ATTACH_VOLUME_TO_ENTITY(volume, entity, offsetX, offsetY, offsetZ, rotX, rotY, rotZ, p8, p9);
	}

	static void LUA_NATIVE_PED__DETACH_VOLUME_FROM_ENTITY(Volume volume, Entity entity)
	{
		PED::_DETACH_VOLUME_FROM_ENTITY(volume, entity);
	}

	static void LUA_NATIVE_PED_SET_PED_ONTO_MOUNT(Ped ped, Ped mount, int seatIndex, bool p3)
	{
		PED::SET_PED_ONTO_MOUNT(ped, mount, seatIndex, p3);
	}

	static void LUA_NATIVE_PED__REMOVE_PED_FROM_MOUNT(Ped ped, bool p1, bool p2)
	{
		PED::_REMOVE_PED_FROM_MOUNT(ped, p1, p2);
	}

	static Ped LUA_NATIVE_PED_CREATE_PED_ON_MOUNT(Ped mount, Hash modelHash, int index, bool p3, bool p4, bool p5, bool p6)
	{
		auto retval = PED::CREATE_PED_ON_MOUNT(mount, modelHash, index, p3, p4, p5, p6);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_MOUNT_SEAT_FREE(Ped mount, int seat)
	{
		auto retval = (bool)PED::_IS_MOUNT_SEAT_FREE(mount, seat);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_ON_MOUNT(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_ON_MOUNT(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_FULLY_ON_MOUNT(Ped ped, bool p1)
	{
		auto retval = (bool)PED::IS_PED_FULLY_ON_MOUNT(ped, p1);
		return retval;
	}

	static Ped LUA_NATIVE_PED_GET_MOUNT(Ped PedIndex)
	{
		auto retval = PED::GET_MOUNT(PedIndex);
		return retval;
	}

	static Ped LUA_NATIVE_PED__GET_LAST_LED_MOUNT(Ped ped)
	{
		auto retval = PED::_GET_LAST_LED_MOUNT(ped);
		return retval;
	}

	static Ped LUA_NATIVE_PED__GET_LAST_MOUNT(Ped ped)
	{
		auto retval = PED::_GET_LAST_MOUNT(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0xED1C764997A86D5A(Ped ped1, Ped ped2)
	{
		PED::_0xED1C764997A86D5A(ped1, ped2);
	}

	static void LUA_NATIVE_PED__0xB8AB265426CFE6DD(Ped ped, bool p1)
	{
		PED::_0xB8AB265426CFE6DD(ped, p1);
	}

	static int LUA_NATIVE_PED__0xE8D1CCB9375C101B(Ped mount, Player player)
	{
		auto retval = PED::_0xE8D1CCB9375C101B(mount, player);
		return retval;
	}

	static void LUA_NATIVE_PED__0xA691C10054275290(Ped mount, Player player, int dismountedTimestamp)
	{
		PED::_0xA691C10054275290(mount, player, dismountedTimestamp);
	}

	static void LUA_NATIVE_PED__0x6734F0A6A52C371C(Player player, int horseSlot)
	{
		PED::_0x6734F0A6A52C371C(player, horseSlot);
	}

	static void LUA_NATIVE_PED__0x024EC9B649111915(Ped ped, bool p1)
	{
		PED::_0x024EC9B649111915(ped, p1);
	}

	static void LUA_NATIVE_PED_SET_PED_OWNS_ANIMAL(Ped ped, Ped animal, bool p2)
	{
		PED::SET_PED_OWNS_ANIMAL(ped, animal, p2);
	}

	static Ped LUA_NATIVE_PED__GET_ACTIVE_ANIMAL_OWNER(Ped animal)
	{
		auto retval = PED::_GET_ACTIVE_ANIMAL_OWNER(animal);
		return retval;
	}

	static void LUA_NATIVE_PED__CLEAR_ACTIVE_ANIMAL_OWNER(Ped horse, bool clear)
	{
		PED::_CLEAR_ACTIVE_ANIMAL_OWNER(horse, clear);
	}

	static int LUA_NATIVE_PED__GET_HORSE_TAMING_STATE(Ped horse)
	{
		auto retval = PED::_GET_HORSE_TAMING_STATE(horse);
		return retval;
	}

	static void LUA_NATIVE_PED__0x54D3CD482742C482(Ped animal, float p2)
	{
		PED::_0x54D3CD482742C482(animal, p2);
	}

	static void LUA_NATIVE_PED__0x5CB2EBB467BE3ED6(Ped animal, float p2)
	{
		PED::_0x5CB2EBB467BE3ED6(animal, p2);
	}

	static void LUA_NATIVE_PED__0x9F0F28B42C4EE80A(Ped animal, float p2)
	{
		PED::_0x9F0F28B42C4EE80A(animal, p2);
	}

	static void LUA_NATIVE_PED__SET_MOUNT_BONDING_LEVEL(Ped ped, int bondingLevel)
	{
		PED::_SET_MOUNT_BONDING_LEVEL(ped, bondingLevel);
	}

	static void LUA_NATIVE_PED__SET_MOUNT_SECURITY_ENABLED(Ped ped, bool toggle)
	{
		PED::_SET_MOUNT_SECURITY_ENABLED(ped, toggle);
	}

	static void LUA_NATIVE_PED__0x9B65444C07B782BF(Ped ped, sol::stack_object p1)
	{
		PED::_0x9B65444C07B782BF(ped, p1.is<const char*>() ? p1.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_PED_IS_ANIMAL_INTERACTION_POSSIBLE(Ped ped, Ped animal)
	{
		auto retval = (bool)PED::IS_ANIMAL_INTERACTION_POSSIBLE(ped, animal);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_ANIMAL_INTERACTION_RUNNING(Ped ped)
	{
		auto retval = (bool)PED::_IS_ANIMAL_INTERACTION_RUNNING(ped);
		return retval;
	}

	static Ped LUA_NATIVE_PED__0x8BE24D74D74C6E9B(Ped ped)
	{
		auto retval = PED::_0x8BE24D74D74C6E9B(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x77243ED4F7CAAA55(Ped ped)
	{
		auto retval = (bool)PED::_0x77243ED4F7CAAA55(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_ON_VEHICLE(Ped PedIndex, bool p1)
	{
		auto retval = (bool)PED::IS_PED_ON_VEHICLE(PedIndex, p1);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_ON_SPECIFIC_VEHICLE(Ped PedIndex, Vehicle VehicleIndex)
	{
		auto retval = (bool)PED::IS_PED_ON_SPECIFIC_VEHICLE(PedIndex, VehicleIndex);
		return retval;
	}

	static void LUA_NATIVE_PED__WARP_PED_OUT_OF_VEHICLE(Ped ped)
	{
		PED::_WARP_PED_OUT_OF_VEHICLE(ped);
	}

	static void LUA_NATIVE_PED_SET_PED_MONEY(Ped PedIndex, int MoneyToSet)
	{
		PED::SET_PED_MONEY(PedIndex, MoneyToSet);
	}

	static int LUA_NATIVE_PED_GET_PED_MONEY(Ped PedIndex)
	{
		auto retval = PED::GET_PED_MONEY(PedIndex);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_BLOCKING_OF_NON_TEMPORARY_EVENTS_FOR_AMBIENT_PEDS_THIS_FRAME(bool Block)
	{
		PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS_FOR_AMBIENT_PEDS_THIS_FRAME(Block);
	}

	static void LUA_NATIVE_PED__0x34EDDD59364AD74A(Ped ped, uintptr_t p1)
	{
		PED::_0x34EDDD59364AD74A(ped, (Any*)p1);
	}

	static void LUA_NATIVE_PED__0x2D976DBDC731DF80(Ped ped)
	{
		PED::_0x2D976DBDC731DF80(ped);
	}

	static bool LUA_NATIVE_PED_IS_PED_SITTING_IN_VEHICLE(Ped PedIndex, Vehicle VehicleIndex)
	{
		auto retval = (bool)PED::IS_PED_SITTING_IN_VEHICLE(PedIndex, VehicleIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_SITTING_IN_ANY_VEHICLE(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_SITTING_IN_ANY_VEHICLE(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_ON_FOOT(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_ON_FOOT(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_PLANTING_BOMB(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_PLANTING_BOMB(PedIndex);
		return retval;
	}

	static Vector3 LUA_NATIVE_PED_GET_DEAD_PED_PICKUP_COORDS(Ped PedIndex, float minDist, float maxDist)
	{
		auto retval = PED::GET_DEAD_PED_PICKUP_COORDS(PedIndex, minDist, maxDist);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_IN_ANY_BOAT(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_IN_ANY_BOAT(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_IN_ANY_HELI(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_IN_ANY_HELI(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_IN_ANY_PLANE(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_IN_ANY_PLANE(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_IN_FLYING_VEHICLE(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_IN_FLYING_VEHICLE(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x256EDD55C6BE1482(Ped ped)
	{
		auto retval = (bool)PED::_0x256EDD55C6BE1482(ped);
		return retval;
	}

	static std::tuple<bool, int> LUA_NATIVE_PED_GET_PED_LAST_DAMAGE_BONE(Ped PedIndex, int ReturnBoneTag)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)PED::GET_PED_LAST_DAMAGE_BONE(PedIndex, &ReturnBoneTag);
		std::get<1>(return_values) = ReturnBoneTag;

		return return_values;
	}

	static void LUA_NATIVE_PED_CLEAR_PED_LAST_DAMAGE_BONE(Ped PedIndex)
	{
		PED::CLEAR_PED_LAST_DAMAGE_BONE(PedIndex);
	}

	static int LUA_NATIVE_PED__GET_PED_DAMAGE_CLEANLINESS(Ped ped)
	{
		auto retval = PED::_GET_PED_DAMAGE_CLEANLINESS(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_DAMAGE_CLEANLINESS(Ped ped, int damageCleanliness)
	{
		PED::_SET_PED_DAMAGE_CLEANLINESS(ped, damageCleanliness);
	}

	static bool LUA_NATIVE_PED__GET_PED_DAMAGED(Ped ped)
	{
		auto retval = (bool)PED::_GET_PED_DAMAGED(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_DAMAGED(Ped ped, bool damaged)
	{
		PED::_SET_PED_DAMAGED(ped, damaged);
	}

	static Any LUA_NATIVE_PED__SET_PLAYER_CURRENT_ANIMAL_DAMAGE_MODIFIER(Player player, float modifier, int p2, int p3)
	{
		auto retval = PED::_SET_PLAYER_CURRENT_ANIMAL_DAMAGE_MODIFIER(player, modifier, p2, p3);
		return retval;
	}

	static void LUA_NATIVE_PED__UPDATE_ANIMAL_DAMAGE_MODIFIER(Player player)
	{
		PED::_UPDATE_ANIMAL_DAMAGE_MODIFIER(player);
	}

	static float LUA_NATIVE_PED__GET_PLAYER_CURRENT_ANIMAL_DAMAGE_MODIFIER(Player player)
	{
		auto retval = PED::_GET_PLAYER_CURRENT_ANIMAL_DAMAGE_MODIFIER(player);
		return retval;
	}

	static Any LUA_NATIVE_PED__0xB29C553BA582D09E(uintptr_t p0, Hash model, int damageCleanliness, int p3)
	{
		auto retval = PED::_0xB29C553BA582D09E((Any*)p0, model, damageCleanliness, p3);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x101B45C5F56D970F(uintptr_t p0, Ped ped, int damageCleanliness, int p3)
	{
		auto retval = (bool)PED::_0x101B45C5F56D970F((Any*)p0, ped, damageCleanliness, p3);
		return retval;
	}

	static int LUA_NATIVE_PED__COMPUTE_SATCHEL_ITEM_FOR_PED_CARCASS(uintptr_t outInventoryItemArray, Ped ped, int damageCleanliness, int skinningQuality)
	{
		auto retval = PED::_COMPUTE_SATCHEL_ITEM_FOR_PED_CARCASS((Any*)outInventoryItemArray, ped, damageCleanliness, skinningQuality);
		return retval;
	}

	static bool LUA_NATIVE_PED_COMPUTE_SATCHEL_ITEM_FOR_PED_DAMAGE(Any p0, Ped pedAttached, int damageCleanliness)
	{
		auto retval = (bool)PED::COMPUTE_SATCHEL_ITEM_FOR_PED_DAMAGE(p0, pedAttached, damageCleanliness);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_AI_WEAPON_DAMAGE_MODIFIER(float Modifier)
	{
		PED::SET_AI_WEAPON_DAMAGE_MODIFIER(Modifier);
	}

	static void LUA_NATIVE_PED_RESET_AI_WEAPON_DAMAGE_MODIFIER()
	{
		PED::RESET_AI_WEAPON_DAMAGE_MODIFIER();
	}

	static void LUA_NATIVE_PED__SET_TOTAL_PED_DAMAGE_FROM_AI(Ped ped, float totalDamage)
	{
		PED::_SET_TOTAL_PED_DAMAGE_FROM_AI(ped, totalDamage);
	}

	static void LUA_NATIVE_PED__0xA6D6F03095C88F59(Ped ped)
	{
		PED::_0xA6D6F03095C88F59(ped);
	}

	static float LUA_NATIVE_PED__GET_TOTAL_PED_DAMAGE_FROM_AI(Ped ped)
	{
		auto retval = PED::_GET_TOTAL_PED_DAMAGE_FROM_AI(ped);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_TO_PLAYER_WEAPON_DAMAGE_MODIFIER(Ped ped, float damageModifier)
	{
		PED::SET_PED_TO_PLAYER_WEAPON_DAMAGE_MODIFIER(ped, damageModifier);
	}

	static float LUA_NATIVE_PED_GET_PED_TO_PLAYER_WEAPON_DAMAGE_MODIFIER(Ped ped)
	{
		auto retval = PED::GET_PED_TO_PLAYER_WEAPON_DAMAGE_MODIFIER(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_CURRENT_DEFENSE_AGAINST_PLAYERS_MODIFIER(Ped horse, float modifier)
	{
		PED::_SET_CURRENT_DEFENSE_AGAINST_PLAYERS_MODIFIER(horse, modifier);
	}

	static float LUA_NATIVE_PED__0x763FA8A9D76EE3A7(Ped ped)
	{
		auto retval = PED::_0x763FA8A9D76EE3A7(ped);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_AI_MELEE_WEAPON_DAMAGE_MODIFIER(float Modifier)
	{
		PED::SET_AI_MELEE_WEAPON_DAMAGE_MODIFIER(Modifier);
	}

	static void LUA_NATIVE_PED__SET_ACCURACY_AGAINST_LOCAL_PLAYER_MODIFIER(Ped ped, float modifier)
	{
		PED::_SET_ACCURACY_AGAINST_LOCAL_PLAYER_MODIFIER(ped, modifier);
	}

	static float LUA_NATIVE_PED__GET_ACCURACY_AGAINST_LOCAL_PLAYER_MODIFIER(Ped ped)
	{
		auto retval = PED::_GET_ACCURACY_AGAINST_LOCAL_PLAYER_MODIFIER(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_HEADSHOT_DAMAGE_MULTIPLIER(Ped ped, float multiplier)
	{
		PED::_SET_PED_HEADSHOT_DAMAGE_MULTIPLIER(ped, multiplier);
	}

	static void LUA_NATIVE_PED__0xDEE8D30AA5C2E28D(Ped ped, Hash p1, bool p2)
	{
		PED::_0xDEE8D30AA5C2E28D(ped, p1, p2);
	}

	static void LUA_NATIVE_PED__0xE1B3BE07D3AADDED(Ped ped, int p1, bool p2)
	{
		PED::_0xE1B3BE07D3AADDED(ped, p1, p2);
	}

	static void LUA_NATIVE_PED__0x32CEDA9A0AB4CEF7(Ped ped, Hash p1, bool p2)
	{
		PED::_0x32CEDA9A0AB4CEF7(ped, p1, p2);
	}

	static void LUA_NATIVE_PED__0x52A24D8A1DA89658(Ped ped, int p1, bool p2)
	{
		PED::_0x52A24D8A1DA89658(ped, p1, p2);
	}

	static void LUA_NATIVE_PED__0x34B5CEAC180A5D6E(Ped ped, Hash p1, bool p2)
	{
		PED::_0x34B5CEAC180A5D6E(ped, p1, p2);
	}

	static void LUA_NATIVE_PED__0x4F27603E44A8E4C0(Ped ped, int p1, bool p2)
	{
		PED::_0x4F27603E44A8E4C0(ped, p1, p2);
	}

	static void LUA_NATIVE_PED__0x3FDCC1F8C17E303E(Ped ped, int p1, float p2)
	{
		PED::_0x3FDCC1F8C17E303E(ped, p1, p2);
	}

	static void LUA_NATIVE_PED__0xE50C9816B3F22D8B(Ped ped, Hash p1, float p2)
	{
		PED::_0xE50C9816B3F22D8B(ped, p1, p2);
	}

	static void LUA_NATIVE_PED__SET_DEFENSE_MODIFIER_FOR_PED(Ped ped, float modifier)
	{
		PED::_SET_DEFENSE_MODIFIER_FOR_PED(ped, modifier);
	}

	static void LUA_NATIVE_PED__SET_MIN_PED_HEALTH_THRESHOLD(Ped ped, float healthAmount)
	{
		PED::_SET_MIN_PED_HEALTH_THRESHOLD(ped, healthAmount);
	}

	static void LUA_NATIVE_PED__0xC5B78E41DCF8227C(Ped ped, bool p1)
	{
		PED::_0xC5B78E41DCF8227C(ped, p1);
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_BE_TARGETTED(Ped PedIndex, bool bAllowTargetted)
	{
		PED::SET_PED_CAN_BE_TARGETTED(PedIndex, bAllowTargetted);
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_BE_TARGETTED_BY_TEAM(Ped PedIndex, int team, bool bAllowTargetted)
	{
		PED::SET_PED_CAN_BE_TARGETTED_BY_TEAM(PedIndex, team, bAllowTargetted);
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_BE_TARGETTED_BY_PLAYER(Ped PedIndex, Player PlayerIndex, bool bAllowTargetted)
	{
		PED::SET_PED_CAN_BE_TARGETTED_BY_PLAYER(PedIndex, PlayerIndex, bAllowTargetted);
	}

	static void LUA_NATIVE_PED__SET_INTERACTION_LOCKON_FLAG(Ped ped, Player player, int flag, bool enable)
	{
		PED::_SET_INTERACTION_LOCKON_FLAG(ped, player, flag, enable);
	}

	static bool LUA_NATIVE_PED_IS_PED_FALLING(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_FALLING(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_PED_SLIDING(Ped ped)
	{
		auto retval = (bool)PED::_IS_PED_SLIDING(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_JUMPING(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_JUMPING(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_CLIMBING(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_CLIMBING(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_PED_CLIMBING_LADDER(Ped ped)
	{
		auto retval = (bool)PED::_IS_PED_CLIMBING_LADDER(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x577C60BA06D0EA64(Ped ped)
	{
		auto retval = (bool)PED::_0x577C60BA06D0EA64(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_VAULTING(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_VAULTING(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_DIVING(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_DIVING(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_OPENING_DOOR(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_OPENING_DOOR(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x5C6C7C70CA302801(Ped ped)
	{
		auto retval = (bool)PED::_0x5C6C7C70CA302801(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__0xB91AB3BE7F655D49(Ped ped)
	{
		auto retval = (bool)PED::_0xB91AB3BE7F655D49(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_IN_ANY_TAXI(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_IN_ANY_TAXI(PedIndex);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_ID_RANGE(Ped PedIndex, float IdRange)
	{
		PED::SET_PED_ID_RANGE(PedIndex, IdRange);
	}

	static float LUA_NATIVE_PED__GET_PED_ID_RANGE(Ped ped)
	{
		auto retval = PED::_GET_PED_ID_RANGE(ped);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_HIGHLY_PERCEPTIVE(Ped PedIndex, bool bHighlyPerceptive)
	{
		PED::SET_PED_HIGHLY_PERCEPTIVE(PedIndex, bHighlyPerceptive);
	}

	static void LUA_NATIVE_PED_SET_PED_INJURED_ON_GROUND_BEHAVIOUR(Ped PedIndex, float duration)
	{
		PED::SET_PED_INJURED_ON_GROUND_BEHAVIOUR(PedIndex, duration);
	}

	static void LUA_NATIVE_PED_DISABLE_PED_INJURED_ON_GROUND_BEHAVIOUR(Ped PedIndex)
	{
		PED::DISABLE_PED_INJURED_ON_GROUND_BEHAVIOUR(PedIndex);
	}

	static void LUA_NATIVE_PED__0x028E7B3BBA0BD2FC(Ped ped)
	{
		PED::_0x028E7B3BBA0BD2FC(ped);
	}

	static bool LUA_NATIVE_PED__0xFA8C10DCE0706D43(Ped ped)
	{
		auto retval = (bool)PED::_0xFA8C10DCE0706D43(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_ANIMAL_DETECTION_MODIFIER(Ped ped, float modifier)
	{
		PED::_SET_PED_ANIMAL_DETECTION_MODIFIER(ped, modifier);
	}

	static float LUA_NATIVE_PED__0x2BA9D7BF629F920C(Ped ped)
	{
		auto retval = PED::_0x2BA9D7BF629F920C(ped);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_SEEING_RANGE(Ped PedIndex, float SeeingRange)
	{
		PED::SET_PED_SEEING_RANGE(PedIndex, SeeingRange);
	}

	static float LUA_NATIVE_PED__0x900CA00CE703E1E2(Ped ped)
	{
		auto retval = PED::_0x900CA00CE703E1E2(ped);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_HEARING_RANGE(Ped PedIndex, float HearingRange)
	{
		PED::SET_PED_HEARING_RANGE(PedIndex, HearingRange);
	}

	static void LUA_NATIVE_PED_SET_PED_VISUAL_FIELD_MIN_ANGLE(Ped PedIndex, float fAngle)
	{
		PED::SET_PED_VISUAL_FIELD_MIN_ANGLE(PedIndex, fAngle);
	}

	static void LUA_NATIVE_PED_SET_PED_VISUAL_FIELD_MAX_ANGLE(Ped PedIndex, float fAngle)
	{
		PED::SET_PED_VISUAL_FIELD_MAX_ANGLE(PedIndex, fAngle);
	}

	static void LUA_NATIVE_PED_SET_PED_VISUAL_FIELD_PERIPHERAL_RANGE(Ped PedIndex, float fDistance)
	{
		PED::SET_PED_VISUAL_FIELD_PERIPHERAL_RANGE(PedIndex, fDistance);
	}

	static void LUA_NATIVE_PED_SET_PED_VISUAL_FIELD_CENTER_ANGLE(Ped PedIndex, float fAngle)
	{
		PED::SET_PED_VISUAL_FIELD_CENTER_ANGLE(PedIndex, fAngle);
	}

	static void LUA_NATIVE_PED__0x9AB33CB5834885B3(Ped ped, float p1, float p2, float p3, float p4)
	{
		PED::_0x9AB33CB5834885B3(ped, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_PED__0x899DFA0009AC93DE(Ped ped, float p1)
	{
		PED::_0x899DFA0009AC93DE(ped, p1);
	}

	static void LUA_NATIVE_PED__0x3A5697B80FED5EBE(Ped ped, float p1, float p2, float p3, float p4)
	{
		PED::_0x3A5697B80FED5EBE(ped, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_PED_SET_PED_STEALTH_MOVEMENT(Ped PedIndex, bool bStealth, Any p2, Any p3)
	{
		PED::SET_PED_STEALTH_MOVEMENT(PedIndex, bStealth, p2, p3);
	}

	static bool LUA_NATIVE_PED_GET_PED_STEALTH_MOVEMENT(Ped PedIndex)
	{
		auto retval = (bool)PED::GET_PED_STEALTH_MOVEMENT(PedIndex);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_CROUCH_MOVEMENT(Ped ped, bool state, int p2, bool immediately)
	{
		PED::_SET_PED_CROUCH_MOVEMENT(ped, state, p2, immediately);
	}

	static bool LUA_NATIVE_PED_GET_PED_CROUCH_MOVEMENT(Ped ped)
	{
		auto retval = (bool)PED::GET_PED_CROUCH_MOVEMENT(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_GET_PED_IS_DOING_COMBAT_ROLL(Ped ped)
	{
		auto retval = (bool)PED::GET_PED_IS_DOING_COMBAT_ROLL(ped);
		return retval;
	}

	static int LUA_NATIVE_PED_CREATE_GROUP(int DefaultTaskType)
	{
		auto retval = PED::CREATE_GROUP(DefaultTaskType);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_AS_GROUP_LEADER(Ped PedIndex, int GroupUniqueID, bool p2)
	{
		PED::SET_PED_AS_GROUP_LEADER(PedIndex, GroupUniqueID, p2);
	}

	static void LUA_NATIVE_PED_SET_PED_AS_GROUP_MEMBER(Ped PedIndex, int GroupUniqueID)
	{
		PED::SET_PED_AS_GROUP_MEMBER(PedIndex, GroupUniqueID);
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_TELEPORT_TO_GROUP_LEADER(Ped PedIndex, int GroupUniqueID, bool bEnabled)
	{
		PED::SET_PED_CAN_TELEPORT_TO_GROUP_LEADER(PedIndex, GroupUniqueID, bEnabled);
	}

	static void LUA_NATIVE_PED_REMOVE_GROUP(int UniqueGroupID)
	{
		PED::REMOVE_GROUP(UniqueGroupID);
	}

	static void LUA_NATIVE_PED_REMOVE_PED_FROM_GROUP(Ped PedIndex)
	{
		PED::REMOVE_PED_FROM_GROUP(PedIndex);
	}

	static bool LUA_NATIVE_PED_IS_PED_GROUP_MEMBER(Ped PedIndex, int UniqueGroupID, bool p2)
	{
		auto retval = (bool)PED::IS_PED_GROUP_MEMBER(PedIndex, UniqueGroupID, p2);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_PED_GROUP_LEADER(Ped ped, int groupId)
	{
		auto retval = (bool)PED::_IS_PED_GROUP_LEADER(ped, groupId);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_HANGING_ON_TO_VEHICLE(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_HANGING_ON_TO_VEHICLE(PedIndex);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_GROUP_SEPARATION_RANGE(int UniqueGroupID, float SeparationRange)
	{
		PED::SET_GROUP_SEPARATION_RANGE(UniqueGroupID, SeparationRange);
	}

	static void LUA_NATIVE_PED__0x89E59DBD15E21177(int groupId, int p1)
	{
		PED::_0x89E59DBD15E21177(groupId, p1);
	}

	static bool LUA_NATIVE_PED_IS_PED_PRONE(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_PRONE(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_PED_INVESTIGATING(Ped ped)
	{
		auto retval = (bool)PED::_IS_PED_INVESTIGATING(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_IN_COMBAT(Ped PedIndex, Ped TargetPedIndex)
	{
		auto retval = (bool)PED::IS_PED_IN_COMBAT(PedIndex, TargetPedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_CAN_PED_IN_COMBAT_SEE_TARGET(Ped PedIndex, Ped TargetPedIndex)
	{
		auto retval = (bool)PED::CAN_PED_IN_COMBAT_SEE_TARGET(PedIndex, TargetPedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_JACKING(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_JACKING(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_BEING_JACKED(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_BEING_JACKED(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_BEING_STUNNED(Ped PedIndex, Hash WeaponType)
	{
		auto retval = (bool)PED::IS_PED_BEING_STUNNED(PedIndex, WeaponType);
		return retval;
	}

	static Ped LUA_NATIVE_PED_GET_PEDS_JACKER(Ped PedIndex)
	{
		auto retval = PED::GET_PEDS_JACKER(PedIndex);
		return retval;
	}

	static Ped LUA_NATIVE_PED_GET_JACK_TARGET(Ped PedIndex)
	{
		auto retval = PED::GET_JACK_TARGET(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_FLEEING(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_FLEEING(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_IN_COVER(Ped PedIndex, bool p1, bool p2)
	{
		auto retval = (bool)PED::IS_PED_IN_COVER(PedIndex, p1, p2);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x2DD4E0E26DFAD97D(Ped ped1, Ped ped2, float p2)
	{
		auto retval = (bool)PED::_0x2DD4E0E26DFAD97D(ped1, ped2, p2);
		return retval;
	}

	static bool LUA_NATIVE_PED__PED_WAS_KILLED_BY_HEADSHOT(Ped ped)
	{
		auto retval = (bool)PED::_PED_WAS_KILLED_BY_HEADSHOT(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__PED_DUELING_DID_PLAYER_HEADSHOT_OPPONENT(Ped ped)
	{
		auto retval = (bool)PED::_PED_DUELING_DID_PLAYER_HEADSHOT_OPPONENT(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_IN_COVER_FACING_LEFT(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_IN_COVER_FACING_LEFT(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_GOING_INTO_COVER(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_GOING_INTO_COVER(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_RESPONDING_TO_THREAT(Ped ped)
	{
		auto retval = (bool)PED::IS_PED_RESPONDING_TO_THREAT(ped);
		return retval;
	}

	static Hash LUA_NATIVE_PED__GET_ACTIVE_DYNAMIC_SCENARIO_2(Ped ped)
	{
		auto retval = PED::_GET_ACTIVE_DYNAMIC_SCENARIO_2(ped);
		return retval;
	}

	static Hash LUA_NATIVE_PED__GET_ACTIVE_DYNAMIC_SCENARIO(Ped ped)
	{
		auto retval = PED::_GET_ACTIVE_DYNAMIC_SCENARIO(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__GIVE_PED_SCENARIO_PROP(Ped ped, Object object, sol::stack_object conditionalAnim, sol::stack_object p3, sol::stack_object p4, bool p5)
	{
		auto retval = (bool)PED::_GIVE_PED_SCENARIO_PROP(ped, object, conditionalAnim.is<const char*>() ? conditionalAnim.as<const char*>() : nullptr, p3.is<const char*>() ? p3.as<const char*>() : nullptr, p4.is<const char*>() ? p4.as<const char*>() : nullptr, p5);
		return retval;
	}

	static bool LUA_NATIVE_PED_GIVE_PED_HASH_SCENARIO_PROP(Ped ped, Object object, sol::stack_object conditionalAnim, Hash scenarioType, Hash p4, bool p5)
	{
		auto retval = (bool)PED::GIVE_PED_HASH_SCENARIO_PROP(ped, object, conditionalAnim.is<const char*>() ? conditionalAnim.as<const char*>() : nullptr, scenarioType, p4, p5);
		return retval;
	}

	static bool LUA_NATIVE_PED__GIVE_PED_SCENARIO_PROP_DYNAMIC(Ped ped, Object object, sol::stack_object p2, sol::stack_object p3, bool p4)
	{
		auto retval = (bool)PED::_GIVE_PED_SCENARIO_PROP_DYNAMIC(ped, object, p2.is<const char*>() ? p2.as<const char*>() : nullptr, p3.is<const char*>() ? p3.as<const char*>() : nullptr, p4);
		return retval;
	}

	static Any LUA_NATIVE_PED__REQUEST_PROP_SCENARIO_PED(Ped ped, Object object, sol::stack_object p2, sol::stack_object p3, sol::stack_object p4, bool p5)
	{
		auto retval = PED::_REQUEST_PROP_SCENARIO_PED(ped, object, p2.is<const char*>() ? p2.as<const char*>() : nullptr, p3.is<const char*>() ? p3.as<const char*>() : nullptr, p4.is<const char*>() ? p4.as<const char*>() : nullptr, p5);
		return retval;
	}

	static Any LUA_NATIVE_PED__REQUEST_PED_FOR_SCENARIO_TYPE(Ped ped, Object object, sol::stack_object p2, Hash scenarioType, sol::stack_object p4, bool p5)
	{
		auto retval = PED::_REQUEST_PED_FOR_SCENARIO_TYPE(ped, object, p2.is<const char*>() ? p2.as<const char*>() : nullptr, scenarioType, p4.is<const char*>() ? p4.as<const char*>() : nullptr, p5);
		return retval;
	}

	static Entity LUA_NATIVE_PED__GET_PED_REGISTER_PROP(Ped ped, sol::stack_object propName, bool detachProp)
	{
		auto retval = PED::_GET_PED_REGISTER_PROP(ped, propName.is<const char*>() ? propName.as<const char*>() : nullptr, detachProp);
		return retval;
	}

	static int LUA_NATIVE_PED_GET_SEAT_PED_IS_TRYING_TO_ENTER(Ped PedIndex)
	{
		auto retval = PED::GET_SEAT_PED_IS_TRYING_TO_ENTER(PedIndex);
		return retval;
	}

	static Entity LUA_NATIVE_PED_GET_PED_SOURCE_OF_DEATH(Ped PedIndex)
	{
		auto retval = PED::GET_PED_SOURCE_OF_DEATH(PedIndex);
		return retval;
	}

	static Hash LUA_NATIVE_PED_GET_PED_CAUSE_OF_DEATH(Ped PedIndex)
	{
		auto retval = PED::GET_PED_CAUSE_OF_DEATH(PedIndex);
		return retval;
	}

	static int LUA_NATIVE_PED_GET_PED_TIME_OF_DEATH(Ped PedIndex)
	{
		auto retval = PED::GET_PED_TIME_OF_DEATH(PedIndex);
		return retval;
	}

	static int LUA_NATIVE_PED_COUNT_PEDS_IN_COMBAT_WITH_TARGET(Ped TargetIndex, int flag)
	{
		auto retval = PED::COUNT_PEDS_IN_COMBAT_WITH_TARGET(TargetIndex, flag);
		return retval;
	}

	static int LUA_NATIVE_PED__GET_PEDS_IN_COMBAT_WITH_TARGET(Ped ped, ItemSet itemset, int flag)
	{
		auto retval = PED::_GET_PEDS_IN_COMBAT_WITH_TARGET(ped, itemset, flag);
		return retval;
	}

	static int LUA_NATIVE_PED_COUNT_PEDS_IN_COMBAT_WITH_TARGET_WITHIN_RADIUS(Ped TargetIndex, float vecSearchCenterX, float vecSearchCenterY, float vecSearchCenterZ, float fSearchRadius, int flag)
	{
		auto retval = PED::COUNT_PEDS_IN_COMBAT_WITH_TARGET_WITHIN_RADIUS(TargetIndex, vecSearchCenterX, vecSearchCenterY, vecSearchCenterZ, fSearchRadius, flag);
		return retval;
	}

	static Entity LUA_NATIVE_PED_GET_CURRENT_TARGET_FOR_PED(Ped ped)
	{
		auto retval = PED::GET_CURRENT_TARGET_FOR_PED(ped);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_RELATIONSHIP_GROUP_DEFAULT_HASH(Ped PedIndex, Hash relGroup)
	{
		PED::SET_PED_RELATIONSHIP_GROUP_DEFAULT_HASH(PedIndex, relGroup);
	}

	static Hash LUA_NATIVE_PED__GET_DEFAULT_RELATIONSHIP_GROUP_HASH(Hash modelHash)
	{
		auto retval = PED::_GET_DEFAULT_RELATIONSHIP_GROUP_HASH(modelHash);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_RELATIONSHIP_GROUP_HASH(Ped PedIndex, Hash relGroup)
	{
		PED::SET_PED_RELATIONSHIP_GROUP_HASH(PedIndex, relGroup);
	}

	static void LUA_NATIVE_PED_SET_RELATIONSHIP_BETWEEN_GROUPS(int RelationshipType, Hash relGroup, Hash otherRelGroup)
	{
		PED::SET_RELATIONSHIP_BETWEEN_GROUPS(RelationshipType, relGroup, otherRelGroup);
	}

	static void LUA_NATIVE_PED_CLEAR_RELATIONSHIP_BETWEEN_GROUPS(int RelationshipType, Hash relGroup, Hash otherRelGroup)
	{
		PED::CLEAR_RELATIONSHIP_BETWEEN_GROUPS(RelationshipType, relGroup, otherRelGroup);
	}

	static std::tuple<bool, Hash> LUA_NATIVE_PED_ADD_RELATIONSHIP_GROUP(sol::stack_object sName, Hash group)
	{
		std::tuple<bool, Hash> return_values;
		std::get<0>(return_values) = (bool)PED::ADD_RELATIONSHIP_GROUP(sName.is<const char*>() ? sName.as<const char*>() : nullptr, &group);
		std::get<1>(return_values) = group;

		return return_values;
	}

	static void LUA_NATIVE_PED_REMOVE_RELATIONSHIP_GROUP(Hash group)
	{
		PED::REMOVE_RELATIONSHIP_GROUP(group);
	}

	static int LUA_NATIVE_PED_GET_RELATIONSHIP_BETWEEN_PEDS(Ped PedIndex, Ped SecondPedIndex)
	{
		auto retval = PED::GET_RELATIONSHIP_BETWEEN_PEDS(PedIndex, SecondPedIndex);
		return retval;
	}

	static Hash LUA_NATIVE_PED_GET_PED_RELATIONSHIP_GROUP_DEFAULT_HASH(Ped PedIndex)
	{
		auto retval = PED::GET_PED_RELATIONSHIP_GROUP_DEFAULT_HASH(PedIndex);
		return retval;
	}

	static Hash LUA_NATIVE_PED_GET_PED_RELATIONSHIP_GROUP_HASH(Ped PedIndex)
	{
		auto retval = PED::GET_PED_RELATIONSHIP_GROUP_HASH(PedIndex);
		return retval;
	}

	static int LUA_NATIVE_PED_GET_RELATIONSHIP_BETWEEN_GROUPS(Hash relGroupA, Hash relGroupB)
	{
		auto retval = PED::GET_RELATIONSHIP_BETWEEN_GROUPS(relGroupA, relGroupB);
		return retval;
	}

	static void LUA_NATIVE_PED__0xDC91F22F09BC6C2F(Hash group, bool p1)
	{
		PED::_0xDC91F22F09BC6C2F(group, p1);
	}

	static void LUA_NATIVE_PED__0x9629FAF6460D35CB(Hash group, bool p1)
	{
		PED::_0x9629FAF6460D35CB(group, p1);
	}

	static void LUA_NATIVE_PED__0x4E68C7EF706DF35D(Ped ped, float x, float y, float z, float p4, Hash relationshipGroup)
	{
		PED::_0x4E68C7EF706DF35D(ped, x, y, z, p4, relationshipGroup);
	}

	static int LUA_NATIVE_PED__0x3ACCE14DFA6BA8C2(Ped ped, int p1, float x, float y, float z, float p5, ItemSet itemset)
	{
		auto retval = PED::_0x3ACCE14DFA6BA8C2(ped, p1, x, y, z, p5, itemset);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_TO_INFORM_RESPECTED_FRIENDS(Ped PedIndex, float Distance, int MaximumNumber)
	{
		PED::SET_PED_TO_INFORM_RESPECTED_FRIENDS(PedIndex, Distance, MaximumNumber);
	}

	static bool LUA_NATIVE_PED__0x40C9155AF8BC13F3(Ped ped)
	{
		auto retval = (bool)PED::_0x40C9155AF8BC13F3(ped);
		return retval;
	}

	static std::tuple<int, int> LUA_NATIVE_PED__0xF4860514AD354226(ScrHandle shockingEvent, float x, float y, float z, float p4, int p5)
	{
		std::tuple<int, int> return_values;
		std::get<0>(return_values) = PED::_0xF4860514AD354226(shockingEvent, x, y, z, p4, &p5);
		std::get<1>(return_values) = p5;

		return return_values;
	}

	static bool LUA_NATIVE_PED_IS_PED_RESPONDING_TO_EVENT(Ped PedIndex, Hash EventType)
	{
		auto retval = (bool)PED::IS_PED_RESPONDING_TO_EVENT(PedIndex, EventType);
		return retval;
	}

	static Entity LUA_NATIVE_PED__0x5E9FAF6C513347B4(Ped ped, Hash eventType)
	{
		auto retval = PED::_0x5E9FAF6C513347B4(ped, eventType);
		return retval;
	}

	static Any LUA_NATIVE_PED__0x326F7951EF0D7F75(Ped ped, Hash eventType)
	{
		auto retval = PED::_0x326F7951EF0D7F75(ped, eventType);
		return retval;
	}

	static Entity LUA_NATIVE_PED__0xE76687023D8C8505(Hash perscharModel, int p1)
	{
		auto retval = PED::_0xE76687023D8C8505(perscharModel, p1);
		return retval;
	}

	static std::tuple<bool, Vector3> LUA_NATIVE_PED__0xCB8F4C9343EBE240(Ped ped, Hash eventType, Vector3 coords)
	{
		std::tuple<bool, Vector3> return_values;
		std::get<0>(return_values) = (bool)PED::_0xCB8F4C9343EBE240(ped, eventType, &coords);
		std::get<1>(return_values) = coords;

		return return_values;
	}

	static void LUA_NATIVE_PED_SET_PED_FIRING_PATTERN(Ped PedIndex, Hash FiringPatternHash)
	{
		PED::SET_PED_FIRING_PATTERN(PedIndex, FiringPatternHash);
	}

	static void LUA_NATIVE_PED__SET_PED_FIRING_PATTERN_2(Ped ped, Hash patternHash)
	{
		PED::_SET_PED_FIRING_PATTERN_2(ped, patternHash);
	}

	static void LUA_NATIVE_PED__SET_PED_FIRING_PATTERN_3(Ped ped, Hash patternHash)
	{
		PED::_SET_PED_FIRING_PATTERN_3(ped, patternHash);
	}

	static void LUA_NATIVE_PED_SET_PED_SHOOT_RATE(Ped PedIndex, int ShootRate)
	{
		PED::SET_PED_SHOOT_RATE(PedIndex, ShootRate);
	}

	static void LUA_NATIVE_PED__0x3C529A827998F9B3(Ped ped, int p1, int p2)
	{
		PED::_0x3C529A827998F9B3(ped, p1, p2);
	}

	static void LUA_NATIVE_PED__0x1F44B7E283C09EDE(Ped ped, float p1, int p2)
	{
		PED::_0x1F44B7E283C09EDE(ped, p1, p2);
	}

	static void LUA_NATIVE_PED_SET_COMBAT_FLOAT(Ped PedIndex, int combatAttribute, float fNewValue)
	{
		PED::SET_COMBAT_FLOAT(PedIndex, combatAttribute, fNewValue);
	}

	static float LUA_NATIVE_PED_GET_COMBAT_FLOAT(Ped PedIndex, int combatAttribute)
	{
		auto retval = PED::GET_COMBAT_FLOAT(PedIndex, combatAttribute);
		return retval;
	}

	static std::tuple<int, int> LUA_NATIVE_PED_GET_GROUP_SIZE(int UniqueGroupID, int ReturnHasLeader, int ReturnNumberOfFollowers)
	{
		std::tuple<int, int> return_values;
		PED::GET_GROUP_SIZE(UniqueGroupID, &ReturnHasLeader, &ReturnNumberOfFollowers);
		std::get<0>(return_values) = ReturnHasLeader;
		std::get<1>(return_values) = ReturnNumberOfFollowers;

		return return_values;
	}

	static bool LUA_NATIVE_PED_DOES_GROUP_EXIST(int UniqueGroupID)
	{
		auto retval = (bool)PED::DOES_GROUP_EXIST(UniqueGroupID);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x0455546F23FF08E4(int groupId)
	{
		auto retval = (bool)PED::_0x0455546F23FF08E4(groupId);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_GROUP_LOCALLY_CONTROLLED(int groupId)
	{
		auto retval = (bool)PED::IS_GROUP_LOCALLY_CONTROLLED(groupId);
		return retval;
	}

	static int LUA_NATIVE_PED_GET_PED_GROUP_INDEX(Ped PedIndex)
	{
		auto retval = PED::GET_PED_GROUP_INDEX(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_IN_GROUP(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_IN_GROUP(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_PED_LEADING_ANY_GROUP(Ped ped)
	{
		auto retval = (bool)PED::_IS_PED_LEADING_ANY_GROUP(ped);
		return retval;
	}

	static Player LUA_NATIVE_PED_GET_PLAYER_PED_IS_FOLLOWING(Ped PedIndex)
	{
		auto retval = PED::GET_PLAYER_PED_IS_FOLLOWING(PedIndex);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_GROUP_FORMATION(int UniqueGroupID, int GroupFormation)
	{
		PED::SET_GROUP_FORMATION(UniqueGroupID, GroupFormation);
	}

	static int LUA_NATIVE_PED__GET_GROUP_FORMATION(int groupId)
	{
		auto retval = PED::_GET_GROUP_FORMATION(groupId);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_GROUP_FORMATION_SPACING(int UniqueGroupID, float Spacing, float AdjustSpeedMinDist, float AdjustSpeedMaxDist)
	{
		PED::SET_GROUP_FORMATION_SPACING(UniqueGroupID, Spacing, AdjustSpeedMinDist, AdjustSpeedMaxDist);
	}

	static void LUA_NATIVE_PED_RESET_GROUP_FORMATION_DEFAULT_SPACING(int UniqueGroupID)
	{
		PED::RESET_GROUP_FORMATION_DEFAULT_SPACING(UniqueGroupID);
	}

	static bool LUA_NATIVE_PED__0xB05CC690CDE8A4A9(int groupId, float p1)
	{
		auto retval = (bool)PED::_0xB05CC690CDE8A4A9(groupId, p1);
		return retval;
	}

	static void LUA_NATIVE_PED_ADD_CUSTOM_FORMATION_LOCATION(int groupId, float x, float y, float z, int position)
	{
		PED::ADD_CUSTOM_FORMATION_LOCATION(groupId, x, y, z, position);
	}

	static bool LUA_NATIVE_PED_ADD_FORMATION_LOCATION(int groupId, float p1, float p2, float p3)
	{
		auto retval = (bool)PED::ADD_FORMATION_LOCATION(groupId, p1, p2, p3);
		return retval;
	}

	static bool LUA_NATIVE_PED_SET_FORMATION_POSITIONS_TARGET_RADIUS(int groupId, float radius)
	{
		auto retval = (bool)PED::SET_FORMATION_POSITIONS_TARGET_RADIUS(groupId, radius);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_FORMATION_AUTO_ASSIGN_POSITION(int groupId, bool toggle)
	{
		PED::_SET_FORMATION_AUTO_ASSIGN_POSITION(groupId, toggle);
	}

	static void LUA_NATIVE_PED__SET_PED_FORMATION_POSITION(Ped ped, int position, bool toggle)
	{
		PED::_SET_PED_FORMATION_POSITION(ped, position, toggle);
	}

	static int LUA_NATIVE_PED__0x8AF8E647D6B2A649(int groupId, Ped ped)
	{
		auto retval = PED::_0x8AF8E647D6B2A649(groupId, ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0x87C2724A56F66020(Ped ped)
	{
		PED::_0x87C2724A56F66020(ped);
	}

	static void LUA_NATIVE_PED__0xD5BD1B5318A81994(int groupId, bool p1)
	{
		PED::_0xD5BD1B5318A81994(groupId, p1);
	}

	static void LUA_NATIVE_PED__0x9BBEAF8B0C007F1E(Ped ped, bool p1)
	{
		PED::_0x9BBEAF8B0C007F1E(ped, p1);
	}

	static void LUA_NATIVE_PED__0xC99F104BDF8C7F5A(Ped ped, bool p1)
	{
		PED::_0xC99F104BDF8C7F5A(ped, p1);
	}

	static void LUA_NATIVE_PED__0x02E741E19E39628C(Ped ped, float p1)
	{
		PED::_0x02E741E19E39628C(ped, p1);
	}

	static void LUA_NATIVE_PED__0x97C475212B327666(int groupId, bool p1)
	{
		PED::_0x97C475212B327666(groupId, p1);
	}

	static void LUA_NATIVE_PED__0x154B7E841AC7412F(int groupId, bool p1)
	{
		PED::_0x154B7E841AC7412F(groupId, p1);
	}

	static void LUA_NATIVE_PED__0x8AFCCC0F18D70018(int groupId, bool p1)
	{
		PED::_0x8AFCCC0F18D70018(groupId, p1);
	}

	static void LUA_NATIVE_PED__0xE1103300F3456DE7(int groupId, float p1, float p2)
	{
		PED::_0xE1103300F3456DE7(groupId, p1, p2);
	}

	static void LUA_NATIVE_PED__0xA8A95CECB1906EA2(int groupId, bool p1)
	{
		PED::_0xA8A95CECB1906EA2(groupId, p1);
	}

	static void LUA_NATIVE_PED__0xDDFAD4DEAA7FA362(int groupId, float p1, float p2, float p3, float p4)
	{
		PED::_0xDDFAD4DEAA7FA362(groupId, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_PED__0x966DE09688A1DE39(int groupId, float p1, float p2, float p3, float p4)
	{
		PED::_0x966DE09688A1DE39(groupId, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_PED__0x7E5185B979706210(int groupId, int p1)
	{
		PED::_0x7E5185B979706210(groupId, p1);
	}

	static void LUA_NATIVE_PED__0x40C3524D4ED83554(int groupId, bool p1)
	{
		PED::_0x40C3524D4ED83554(groupId, p1);
	}

	static void LUA_NATIVE_PED__0x86FAFC18E3D4380C(int groupId, bool p1)
	{
		PED::_0x86FAFC18E3D4380C(groupId, p1);
	}

	static void LUA_NATIVE_PED__0x07EA5B053FA60AC7(int groupId, bool p1)
	{
		PED::_0x07EA5B053FA60AC7(groupId, p1);
	}

	static void LUA_NATIVE_PED__0xF9CBD46433E36713(Ped ped, Entity targetEntity, float p2, float p3, float p4, float p5, float p6, float p7, float p8, sol::stack_object p9)
	{
		PED::_0xF9CBD46433E36713(ped, targetEntity, p2, p3, p4, p5, p6, p7, p8, p9.is<const char*>() ? p9.as<const char*>() : nullptr);
	}

	static Vehicle LUA_NATIVE_PED_GET_VEHICLE_PED_IS_USING(Ped PedIndex)
	{
		auto retval = PED::GET_VEHICLE_PED_IS_USING(PedIndex);
		return retval;
	}

	static Vehicle LUA_NATIVE_PED_GET_VEHICLE_PED_IS_ENTERING(Ped PedIndex)
	{
		auto retval = PED::GET_VEHICLE_PED_IS_ENTERING(PedIndex);
		return retval;
	}

	static Vehicle LUA_NATIVE_PED__GET_VEHICLE_DRAFT_HORSE_IS_ATTACHED_TO(Ped horse)
	{
		auto retval = PED::_GET_VEHICLE_DRAFT_HORSE_IS_ATTACHED_TO(horse);
		return retval;
	}

	static Vehicle LUA_NATIVE_PED__GET_LAST_VEHICLE_DRAFT_HORSE_WAS_ATTACHED_TO(Ped horse)
	{
		auto retval = PED::_GET_LAST_VEHICLE_DRAFT_HORSE_WAS_ATTACHED_TO(horse);
		return retval;
	}

	static int LUA_NATIVE_PED_GET_SEAT_PED_IS_USING(Ped ped)
	{
		auto retval = PED::GET_SEAT_PED_IS_USING(ped);
		return retval;
	}

	static Entity LUA_NATIVE_PED__GET_TRANSPORT_PED_IS_SEATED_ON(Ped ped)
	{
		auto retval = PED::_GET_TRANSPORT_PED_IS_SEATED_ON(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_ENTERING_ANY_TRANSPORT(Ped ped)
	{
		auto retval = (bool)PED::IS_PED_ENTERING_ANY_TRANSPORT(ped);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_GRAVITY(Ped PedIndex, bool isAffectedByGravity)
	{
		PED::SET_PED_GRAVITY(PedIndex, isAffectedByGravity);
	}

	static void LUA_NATIVE_PED__0x96595B36D6A2279B(Ped animal, bool toggle)
	{
		PED::_0x96595B36D6A2279B(animal, toggle);
	}

	static void LUA_NATIVE_PED__SET_PED_IMMERSION_FLAG(Ped ped, bool toggle)
	{
		PED::_SET_PED_IMMERSION_FLAG(ped, toggle);
	}

	static void LUA_NATIVE_PED__0xA90684ED185CCB4B(Ped animal, bool p1, float p2, float p3)
	{
		PED::_0xA90684ED185CCB4B(animal, p1, p2, p3);
	}

	static void LUA_NATIVE_PED__FAKE_SET_PED_LOCO_INJURED(Ped ped, bool enabled)
	{
		PED::_FAKE_SET_PED_LOCO_INJURED(ped, enabled);
	}

	static void LUA_NATIVE_PED__FORCE_PED_DEATH(Ped ped, Ped pedKiller, Hash weapon)
	{
		PED::_FORCE_PED_DEATH(ped, pedKiller, weapon);
	}

	static void LUA_NATIVE_PED_APPLY_DAMAGE_TO_PED(Ped PedIndex, int Damage, bool DamageArmourFlag, int boneId, Entity InstigatorIndex)
	{
		PED::APPLY_DAMAGE_TO_PED(PedIndex, Damage, DamageArmourFlag, boneId, InstigatorIndex);
	}

	static void LUA_NATIVE_PED__0xBAD2A311667A50D7(Ped ped, bool p1)
	{
		PED::_0xBAD2A311667A50D7(ped, p1);
	}

	static int LUA_NATIVE_PED_GET_PED_TYPE(Ped PedIndex)
	{
		auto retval = PED::GET_PED_TYPE(PedIndex);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_AS_COP(Ped PedIndex, bool bSetRelationshipGroup)
	{
		PED::SET_PED_AS_COP(PedIndex, bSetRelationshipGroup);
	}

	static void LUA_NATIVE_PED__0x405180B14DA5A935(Ped ped, bool p1)
	{
		PED::_0x405180B14DA5A935(ped, p1);
	}

	static void LUA_NATIVE_PED__SET_PED_INTERACTION_PERSONALITY(Ped ped, Hash personality)
	{
		PED::_SET_PED_INTERACTION_PERSONALITY(ped, personality);
	}

	static Hash LUA_NATIVE_PED__GET_PED_INTERACTION_PERSONALITY(Ped ped)
	{
		auto retval = PED::_GET_PED_INTERACTION_PERSONALITY(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_PERSONALITY(Ped ped, Hash personality)
	{
		PED::_SET_PED_PERSONALITY(ped, personality);
	}

	static void LUA_NATIVE_PED__0x329772C47DBB2FBC(Ped ped)
	{
		PED::_0x329772C47DBB2FBC(ped);
	}

	static bool LUA_NATIVE_PED__GET_IS_PED_IN_DISPUTE_WITH_PED(Ped ped, Ped pedInDisputeWith)
	{
		auto retval = (bool)PED::_GET_IS_PED_IN_DISPUTE_WITH_PED(ped, pedInDisputeWith);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x94132D7C8D3575C4(Ped ped)
	{
		auto retval = (bool)PED::_0x94132D7C8D3575C4(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0x8AF46E5159A5B620(Ped ped, Hash speechParams)
	{
		PED::_0x8AF46E5159A5B620(ped, speechParams);
	}

	static void LUA_NATIVE_PED__0x45FEA6D5539BD474(Ped ped, sol::stack_object p1)
	{
		PED::_0x45FEA6D5539BD474(ped, p1.is<const char*>() ? p1.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__SET_PED_INTERACTION_POSITIVE_RESPONSE(Ped ped, sol::stack_object speech)
	{
		PED::_SET_PED_INTERACTION_POSITIVE_RESPONSE(ped, speech.is<const char*>() ? speech.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__0xE37ACEE15AC50C7E(Ped ped, sol::stack_object p1)
	{
		PED::_0xE37ACEE15AC50C7E(ped, p1.is<const char*>() ? p1.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__SET_PED_INTERACTION_NEGATIVE_RESPONSE(Ped ped, sol::stack_object speech)
	{
		PED::_SET_PED_INTERACTION_NEGATIVE_RESPONSE(ped, speech.is<const char*>() ? speech.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__0x41C23A8E6B344867(Ped ped, sol::stack_object p1)
	{
		PED::_0x41C23A8E6B344867(ped, p1.is<const char*>() ? p1.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_PED_GET_IS_PED_RESPONDING_TO_POSITIVE_INTERACTION(Ped ped, Player player)
	{
		auto retval = (bool)PED::GET_IS_PED_RESPONDING_TO_POSITIVE_INTERACTION(ped, player);
		return retval;
	}

	static bool LUA_NATIVE_PED_GET_IS_PED_RESPONDING_TO_NEGATIVE_INTERACTION(Ped ped, Player player)
	{
		auto retval = (bool)PED::GET_IS_PED_RESPONDING_TO_NEGATIVE_INTERACTION(ped, player);
		return retval;
	}

	static void LUA_NATIVE_PED__0xA7DC9266ED6A4E51(Ped ped)
	{
		PED::_0xA7DC9266ED6A4E51(ped);
	}

	static Any LUA_NATIVE_PED__0x89816B58C3466262(Ped ped)
	{
		auto retval = PED::_0x89816B58C3466262(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0x97B06669AC569003(Ped ped1, Ped ped2)
	{
		PED::_0x97B06669AC569003(ped1, ped2);
	}

	static void LUA_NATIVE_PED__0x85F500F4E24CA43E(Ped ped, float p1)
	{
		PED::_0x85F500F4E24CA43E(ped, p1);
	}

	static void LUA_NATIVE_PED__0x9B9B9FA0EA283E3D(Ped ped, float p1)
	{
		PED::_0x9B9B9FA0EA283E3D(ped, p1);
	}

	static void LUA_NATIVE_PED__0xEC60D1D225BC50AA(Ped ped, float p1)
	{
		PED::_0xEC60D1D225BC50AA(ped, p1);
	}

	static void LUA_NATIVE_PED__0x12F2D161BF4031FC(Ped ped, float p1)
	{
		PED::_0x12F2D161BF4031FC(ped, p1);
	}

	static void LUA_NATIVE_PED__0x0ADA3EC589E1736E()
	{
		PED::_0x0ADA3EC589E1736E();
	}

	static bool LUA_NATIVE_PED__GET_IS_PED_BEING_ROBBED(Ped ped, Player player, bool trueUntilPlayerPocketsItem)
	{
		auto retval = (bool)PED::_GET_IS_PED_BEING_ROBBED(ped, player, trueUntilPlayerPocketsItem);
		return retval;
	}

	static bool LUA_NATIVE_PED__0xD55DB4466D00A258(Ped legendaryAnimal)
	{
		auto retval = (bool)PED::_0xD55DB4466D00A258(legendaryAnimal);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_MAX_HEALTH(Ped PedIndex, int MaxHealth)
	{
		PED::SET_PED_MAX_HEALTH(PedIndex, MaxHealth);
	}

	static int LUA_NATIVE_PED_GET_PED_MAX_HEALTH(Ped PedIndex)
	{
		auto retval = PED::GET_PED_MAX_HEALTH(PedIndex);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_HEALTH_CONFIG(Ped ped, Hash configHash)
	{
		PED::_SET_PED_HEALTH_CONFIG(ped, configHash);
	}

	static void LUA_NATIVE_PED_INIT_PED_DEFAULT_HEALTH(Ped ped)
	{
		PED::INIT_PED_DEFAULT_HEALTH(ped);
	}

	static void LUA_NATIVE_PED_SET_PED_MAX_TIME_IN_WATER(Ped PedIndex, float fMaxTime)
	{
		PED::SET_PED_MAX_TIME_IN_WATER(PedIndex, fMaxTime);
	}

	static void LUA_NATIVE_PED_SET_PED_MAX_TIME_UNDERWATER(Ped PedIndex, float fMaxTime)
	{
		PED::SET_PED_MAX_TIME_UNDERWATER(PedIndex, fMaxTime);
	}

	static void LUA_NATIVE_PED__0xAF041C10756C30FB(Ped ped, bool p1, bool p2, bool p3)
	{
		PED::_0xAF041C10756C30FB(ped, p1, p2, p3);
	}

	static void LUA_NATIVE_PED__0x5AF24CA9C974E51A(Ped ped1, Ped ped2)
	{
		PED::_0x5AF24CA9C974E51A(ped1, ped2);
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(Ped PedIndex, int CanBeKnockedOffFlag)
	{
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PedIndex, CanBeKnockedOffFlag);
	}

	static bool LUA_NATIVE_PED_CAN_KNOCK_PED_OFF_VEHICLE(Ped PedIndex)
	{
		auto retval = (bool)PED::CAN_KNOCK_PED_OFF_VEHICLE(PedIndex);
		return retval;
	}

	static void LUA_NATIVE_PED_KNOCK_PED_OFF_VEHICLE(Ped PedIndex)
	{
		PED::KNOCK_PED_OFF_VEHICLE(PedIndex);
	}

	static Ped LUA_NATIVE_PED_GET_PED_AS_GROUP_MEMBER(int UniqueGroupID, int MemberNumber)
	{
		auto retval = PED::GET_PED_AS_GROUP_MEMBER(UniqueGroupID, MemberNumber);
		return retval;
	}

	static Ped LUA_NATIVE_PED_GET_PED_AS_GROUP_LEADER(int UniqueGroupID)
	{
		auto retval = PED::GET_PED_AS_GROUP_LEADER(UniqueGroupID);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_KEEP_TASK(Ped PedIndex, bool KeepTasksFlag)
	{
		PED::SET_PED_KEEP_TASK(PedIndex, KeepTasksFlag);
	}

	static bool LUA_NATIVE_PED_IS_PED_SWIMMING(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_SWIMMING(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_SWIMMING_UNDER_WATER(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_SWIMMING_UNDER_WATER(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED__0xDC88D06719070C39(Ped ped)
	{
		auto retval = (bool)PED::_0xDC88D06719070C39(ped);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_CREATE_RANDOM_COPS(bool CreateRandomCopsFlag)
	{
		PED::SET_CREATE_RANDOM_COPS(CreateRandomCopsFlag);
	}

	static bool LUA_NATIVE_PED_IS_PED_IN_ANY_TRAIN(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_IN_ANY_TRAIN(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_GETTING_INTO_A_VEHICLE(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_GETTING_INTO_A_VEHICLE(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x550CB89DD7F4FA3D(Ped ped1, Ped ped2)
	{
		auto retval = (bool)PED::_0x550CB89DD7F4FA3D(ped1, ped2);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_ENABLE_HANDCUFFS(Ped PedIndex, bool bEnable, bool p2)
	{
		PED::SET_ENABLE_HANDCUFFS(PedIndex, bEnable, p2);
	}

	static void LUA_NATIVE_PED_SET_ENABLE_BOUND_ANKLES(Ped PedIndex, bool bEnable)
	{
		PED::SET_ENABLE_BOUND_ANKLES(PedIndex, bEnable);
	}

	static bool LUA_NATIVE_PED__0x8822F139408B8D0A(Ped ped)
	{
		auto retval = (bool)PED::_0x8822F139408B8D0A(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0x8822F124788B8D0A(Ped ped, bool p1)
	{
		PED::_0x8822F124788B8D0A(ped, p1);
	}

	static void LUA_NATIVE_PED_RESET_PED_WEAPON_MOVEMENT_CLIPSET(Ped PedIndex)
	{
		PED::RESET_PED_WEAPON_MOVEMENT_CLIPSET(PedIndex);
	}

	static void LUA_NATIVE_PED__SET_PED_GETUP_ANIMATION(Ped ped, sol::stack_object animName, bool p2)
	{
		PED::_SET_PED_GETUP_ANIMATION(ped, animName.is<const char*>() ? animName.as<const char*>() : nullptr, p2);
	}

	static void LUA_NATIVE_PED__0x88A95BB640FC186F(Ped ped)
	{
		PED::_0x88A95BB640FC186F(ped);
	}

	static void LUA_NATIVE_PED_RESET_PED_IN_VEHICLE_CONTEXT(Ped PedIndex)
	{
		PED::RESET_PED_IN_VEHICLE_CONTEXT(PedIndex);
	}

	static void LUA_NATIVE_PED__0x878E8104FA27CDAE(Vehicle vehicle, Hash p1)
	{
		PED::_0x878E8104FA27CDAE(vehicle, p1);
	}

	static void LUA_NATIVE_PED_SET_PED_GESTURE_GROUP(Ped PedIndex, sol::stack_object GestureGroup, int p2)
	{
		PED::SET_PED_GESTURE_GROUP(PedIndex, GestureGroup.is<const char*>() ? GestureGroup.as<const char*>() : nullptr, p2);
	}

	static void LUA_NATIVE_PED__SET_PED_DESIRED_LOCO_FOR_MODEL(Ped ped, sol::stack_object locomotionArchetype)
	{
		PED::_SET_PED_DESIRED_LOCO_FOR_MODEL(ped, locomotionArchetype.is<const char*>() ? locomotionArchetype.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__CLEAR_PED_DESIRED_LOCO_FOR_MODEL(Ped ped)
	{
		PED::_CLEAR_PED_DESIRED_LOCO_FOR_MODEL(ped);
	}

	static void LUA_NATIVE_PED__SET_PED_DESIRED_LOCO_MOTION_TYPE(Ped ped, sol::stack_object locoMotionType)
	{
		PED::_SET_PED_DESIRED_LOCO_MOTION_TYPE(ped, locoMotionType.is<const char*>() ? locoMotionType.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__CLEAR_PED_DESIRED_LOCO_MOTION_TYPE(Ped ped)
	{
		PED::_CLEAR_PED_DESIRED_LOCO_MOTION_TYPE(ped);
	}

	static void LUA_NATIVE_PED__0x2371C39D4F91C288(Ped ped)
	{
		PED::_0x2371C39D4F91C288(ped);
	}

	static void LUA_NATIVE_PED__REQUEST_PED_GETUP_ANIMATION(Ped ped, sol::stack_object getUpType)
	{
		PED::_REQUEST_PED_GETUP_ANIMATION(ped, getUpType.is<const char*>() ? getUpType.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED_PED_COWER_IN_PLACE(Ped ped, Ped ped2)
	{
		PED::PED_COWER_IN_PLACE(ped, ped2);
	}

	static void LUA_NATIVE_PED_PED_COWER_MOVE_TO_POINT(Ped ped, float p1, float p2, float p3, Ped ped2, float p5)
	{
		PED::PED_COWER_MOVE_TO_POINT(ped, p1, p2, p3, ped2, p5);
	}

	static void LUA_NATIVE_PED__0x16F798A05BB9E3B5(Ped ped)
	{
		PED::_0x16F798A05BB9E3B5(ped);
	}

	static void LUA_NATIVE_PED__PED_EMOTIONAL_PRESET_LOCO_MOTION(Ped ped, sol::stack_object presetName, Ped targetPed, int duration, int flag)
	{
		PED::_PED_EMOTIONAL_PRESET_LOCO_MOTION(ped, presetName.is<const char*>() ? presetName.as<const char*>() : nullptr, targetPed, duration, flag);
	}

	static void LUA_NATIVE_PED__PED_CLEAR_LOCO_MOTION(Ped ped)
	{
		PED::_PED_CLEAR_LOCO_MOTION(ped);
	}

	static void LUA_NATIVE_PED__0x32CCAD8A981B53D3(Ped ped)
	{
		PED::_0x32CCAD8A981B53D3(ped);
	}

	static void LUA_NATIVE_PED__SET_PED_DRUNKNESS(Ped ped, bool enabled, float drunknessLevel)
	{
		PED::_SET_PED_DRUNKNESS(ped, enabled, drunknessLevel);
	}

	static bool LUA_NATIVE_PED__IS_PED_DRUNK(Ped ped)
	{
		auto retval = (bool)PED::_IS_PED_DRUNK(ped);
		return retval;
	}

	static float LUA_NATIVE_PED__GET_PED_DRUNKNESS(Ped ped)
	{
		auto retval = PED::_GET_PED_DRUNKNESS(ped);
		return retval;
	}

	static Vector3 LUA_NATIVE_PED_GET_ANIM_INITIAL_OFFSET_POSITION(sol::stack_object pAnimDictName, sol::stack_object pAnimName, float scenePositionX, float scenePositionY, float scenePositionZ, float sceneOrientationX, float sceneOrientationY, float sceneOrientationZ, float phase, int RotOrder)
	{
		auto retval = PED::GET_ANIM_INITIAL_OFFSET_POSITION(pAnimDictName.is<const char*>() ? pAnimDictName.as<const char*>() : nullptr, pAnimName.is<const char*>() ? pAnimName.as<const char*>() : nullptr, scenePositionX, scenePositionY, scenePositionZ, sceneOrientationX, sceneOrientationY, sceneOrientationZ, phase, RotOrder);
		return retval;
	}

	static Vector3 LUA_NATIVE_PED_GET_ANIM_INITIAL_OFFSET_ROTATION(sol::stack_object pAnimDictName, sol::stack_object pAnimName, float scenePositionX, float scenePositionY, float scenePositionZ, float sceneOrientationX, float sceneOrientationY, float sceneOrientationZ, float phase, int RotOrder)
	{
		auto retval = PED::GET_ANIM_INITIAL_OFFSET_ROTATION(pAnimDictName.is<const char*>() ? pAnimDictName.as<const char*>() : nullptr, pAnimName.is<const char*>() ? pAnimName.as<const char*>() : nullptr, scenePositionX, scenePositionY, scenePositionZ, sceneOrientationX, sceneOrientationY, sceneOrientationZ, phase, RotOrder);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_RANDOM_COMPONENT_VARIATION(Ped PedIndex, int race)
	{
		PED::SET_PED_RANDOM_COMPONENT_VARIATION(PedIndex, race);
	}

	static void LUA_NATIVE_PED_KNOCK_OFF_PED_PROP(Ped PedIndex, bool bDamaged, bool bHats, bool bGlasses, bool bHelmets)
	{
		PED::KNOCK_OFF_PED_PROP(PedIndex, bDamaged, bHats, bGlasses, bHelmets);
	}

	static void LUA_NATIVE_PED_SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(Ped PedIndex, bool bBlockEvents)
	{
		PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(PedIndex, bBlockEvents);
	}

	static bool LUA_NATIVE_PED__GET_BLOCKING_OF_NON_TEMPORARY_EVENTS(Ped ped)
	{
		auto retval = (bool)PED::_GET_BLOCKING_OF_NON_TEMPORARY_EVENTS(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0xC17A94CC8FC3C61A(Entity entity, int boneId, float p2, float p3, float p4)
	{
		PED::_0xC17A94CC8FC3C61A(entity, boneId, p2, p3, p4);
	}

	static void LUA_NATIVE_PED__SET_PED_SCALE(Ped ped, float scale)
	{
		PED::_SET_PED_SCALE(ped, scale);
	}

	static float LUA_NATIVE_PED__0x134775B093AD5C38(Ped ped)
	{
		auto retval = PED::_0x134775B093AD5C38(ped);
		return retval;
	}

	static float LUA_NATIVE_PED__GET_PED_HEIGHT(Ped ped)
	{
		auto retval = PED::_GET_PED_HEIGHT(ped);
		return retval;
	}

	static int LUA_NATIVE_PED__GET_PED_MODEL_SIZE_FROM_HASH(Hash modelHash)
	{
		auto retval = PED::_GET_PED_MODEL_SIZE_FROM_HASH(modelHash);
		return retval;
	}

	static void LUA_NATIVE_PED_REGISTER_TARGET(Ped PedIndex, Ped TargetPedIndex, bool p2)
	{
		PED::REGISTER_TARGET(PedIndex, TargetPedIndex, p2);
	}

	static void LUA_NATIVE_PED__REGISTER_HATED_TARGETS_IN_AREA(Ped ped, float x, float y, float z, float radius)
	{
		PED::_REGISTER_HATED_TARGETS_IN_AREA(ped, x, y, z, radius);
	}

	static void LUA_NATIVE_PED_REGISTER_HATED_TARGETS_AROUND_PED(Ped PedIndex, float Radius)
	{
		PED::REGISTER_HATED_TARGETS_AROUND_PED(PedIndex, Radius);
	}

	static bool LUA_NATIVE_PED__IS_TARGET(Ped ped, Ped targetPed)
	{
		auto retval = (bool)PED::_IS_TARGET(ped, targetPed);
		return retval;
	}

	static void LUA_NATIVE_PED__REMOVE_TARGET(Ped ped, Ped targetPed)
	{
		PED::_REMOVE_TARGET(ped, targetPed);
	}

	static std::tuple<bool, Ped> LUA_NATIVE_PED_GET_CLOSEST_PED(float VecCentreCoorsX, float VecCentreCoorsY, float VecCentreCoorsZ, float Range, bool bScanRandomPeds, bool bScanMissionPeds, Ped ClosestPedIndex, bool p7, bool p8, bool p9, int ExclusionPedType)
	{
		std::tuple<bool, Ped> return_values;
		std::get<0>(return_values) = (bool)PED::GET_CLOSEST_PED(VecCentreCoorsX, VecCentreCoorsY, VecCentreCoorsZ, Range, bScanRandomPeds, bScanMissionPeds, &ClosestPedIndex, p7, p8, p9, ExclusionPedType);
		std::get<1>(return_values) = ClosestPedIndex;

		return return_values;
	}

	static bool LUA_NATIVE_PED_CAN_PED_RAGDOLL(Ped PedIndex)
	{
		auto retval = (bool)PED::CAN_PED_RAGDOLL(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_SET_PED_TO_RAGDOLL(Ped PedIndex, int MinTime, int MaxTime, int StartTask, bool bAbortIfInjured, bool bAbortIfDead, sol::stack_object nmTaskMessageParameterName)
	{
		auto retval = (bool)PED::SET_PED_TO_RAGDOLL(PedIndex, MinTime, MaxTime, StartTask, bAbortIfInjured, bAbortIfDead, nmTaskMessageParameterName.is<const char*>() ? nmTaskMessageParameterName.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_PED_SET_PED_TO_RAGDOLL_WITH_FALL(Ped PedIndex, int MinTime, int MaxTime, int nFallType, float vecDirectionX, float vecDirectionY, float vecDirectionZ, float fGroundHeight, float vecGrab1X, float vecGrab1Y, float vecGrab1Z, float vecGrab2X, float vecGrab2Y, float vecGrab2Z)
	{
		auto retval = (bool)PED::SET_PED_TO_RAGDOLL_WITH_FALL(PedIndex, MinTime, MaxTime, nFallType, vecDirectionX, vecDirectionY, vecDirectionZ, fGroundHeight, vecGrab1X, vecGrab1Y, vecGrab1Z, vecGrab2X, vecGrab2Y, vecGrab2Z);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_RAGDOLL_ON_COLLISION(Ped PedIndex, bool RagdollOnCollision, bool p2)
	{
		PED::SET_PED_RAGDOLL_ON_COLLISION(PedIndex, RagdollOnCollision, p2);
	}

	static void LUA_NATIVE_PED__SET_PED_TO_DISABLE_RAGDOLL(Ped ped, bool toggle)
	{
		PED::_SET_PED_TO_DISABLE_RAGDOLL(ped, toggle);
	}

	static bool LUA_NATIVE_PED_IS_PED_RAGDOLL(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_RAGDOLL(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_RUNNING_RAGDOLL_TASK(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_RUNNING_RAGDOLL_TASK(PedIndex);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_RAGDOLL_FORCE_FALL(Ped PedIndex)
	{
		PED::SET_PED_RAGDOLL_FORCE_FALL(PedIndex);
	}

	static void LUA_NATIVE_PED__0x8CB2553C559102C1(Ped ped, int p1, bool p2)
	{
		PED::_0x8CB2553C559102C1(ped, p1, p2);
	}

	static void LUA_NATIVE_PED__0xFD3C31A2E45671E7(Ped ped, int p1)
	{
		PED::_0xFD3C31A2E45671E7(ped, p1);
	}

	static void LUA_NATIVE_PED_RESET_PED_RAGDOLL_TIMER(Ped PedIndex)
	{
		PED::RESET_PED_RAGDOLL_TIMER(PedIndex);
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_RAGDOLL(Ped PedIndex, bool bUnlock)
	{
		PED::SET_PED_CAN_RAGDOLL(PedIndex, bUnlock);
	}

	static bool LUA_NATIVE_PED__0x3AEC4A410ECAF30D(Ped ped)
	{
		auto retval = (bool)PED::_0x3AEC4A410ECAF30D(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_RUNNING_MOBILE_PHONE_TASK(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_RUNNING_MOBILE_PHONE_TASK(PedIndex);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_RAGDOLL_BLOCKING_FLAGS(Ped PedIndex, int flags)
	{
		PED::SET_RAGDOLL_BLOCKING_FLAGS(PedIndex, flags);
	}

	static void LUA_NATIVE_PED_CLEAR_RAGDOLL_BLOCKING_FLAGS(Ped PedIndex, int flags)
	{
		PED::CLEAR_RAGDOLL_BLOCKING_FLAGS(PedIndex, flags);
	}

	static void LUA_NATIVE_PED__0x9F933E0985E12C51(Ped ped, float p1, float p2, float p3)
	{
		PED::_0x9F933E0985E12C51(ped, p1, p2, p3);
	}

	static void LUA_NATIVE_PED__0x88B2026A3B0BE33D(Ped ped, float p1)
	{
		PED::_0x88B2026A3B0BE33D(ped, p1);
	}

	static void LUA_NATIVE_PED_SET_PED_DEFENSIVE_AREA_VOLUME(Ped ped, Volume volume, bool p2, bool p3, bool p4)
	{
		PED::SET_PED_DEFENSIVE_AREA_VOLUME(ped, volume, p2, p3, p4);
	}

	static void LUA_NATIVE_PED_SET_PED_SPHERE_DEFENSIVE_AREA(Ped PedIndex, float vCentreX, float vCentreY, float vCentreZ, float fRadius, bool p5, bool p6, bool p7)
	{
		PED::SET_PED_SPHERE_DEFENSIVE_AREA(PedIndex, vCentreX, vCentreY, vCentreZ, fRadius, p5, p6, p7);
	}

	static void LUA_NATIVE_PED__SET_PED_DEFENSIVE_SPHERE_ATTACHED_TO_ENTITY(Ped ped, Entity entity, float x, float y, float z, float radius, int p6, bool p7)
	{
		PED::_SET_PED_DEFENSIVE_SPHERE_ATTACHED_TO_ENTITY(ped, entity, x, y, z, radius, p6, p7);
	}

	static void LUA_NATIVE_PED__SET_PED_DEFENSIVE_AREA_TO_ANGLED_AREA(Ped ped, float x1, float y1, float z1, float x2, float y2, float z2, Any p7, bool p8, bool p9, Entity entity, bool p11)
	{
		PED::_SET_PED_DEFENSIVE_AREA_TO_ANGLED_AREA(ped, x1, y1, z1, x2, y2, z2, p7, p8, p9, entity, p11);
	}

	static void LUA_NATIVE_PED_SET_PED_DEFENSIVE_AREA_DIRECTION(Ped PedIndex, float vDefendFromPosX, float vDefendFromPosY, float vDefendFromPosZ, bool bApplyToSecondaryDefensiveArea)
	{
		PED::SET_PED_DEFENSIVE_AREA_DIRECTION(PedIndex, vDefendFromPosX, vDefendFromPosY, vDefendFromPosZ, bApplyToSecondaryDefensiveArea);
	}

	static void LUA_NATIVE_PED_REMOVE_PED_DEFENSIVE_AREA(Ped PedIndex, bool bRemoveSecondaryDefensiveArea)
	{
		PED::REMOVE_PED_DEFENSIVE_AREA(PedIndex, bRemoveSecondaryDefensiveArea);
	}

	static Vector3 LUA_NATIVE_PED_GET_PED_DEFENSIVE_AREA_POSITION(Ped PedIndex, bool bApplyToSecondaryDefensiveArea)
	{
		auto retval = PED::GET_PED_DEFENSIVE_AREA_POSITION(PedIndex, bApplyToSecondaryDefensiveArea);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_DEFENSIVE_AREA_ACTIVE(Ped PedIndex, bool bCheckSecondaryDefensiveArea)
	{
		auto retval = (bool)PED::IS_PED_DEFENSIVE_AREA_ACTIVE(PedIndex, bCheckSecondaryDefensiveArea);
		return retval;
	}

	static Volume LUA_NATIVE_PED__GET_PED_DEFENSIVE_VOLUME(Ped ped, Any p1)
	{
		auto retval = PED::_GET_PED_DEFENSIVE_VOLUME(ped, p1);
		return retval;
	}

	static void LUA_NATIVE_PED__0x4EC4EA2F72B36358(Ped ped, bool p1)
	{
		PED::_0x4EC4EA2F72B36358(ped, p1);
	}

	static void LUA_NATIVE_PED__0xCF0B19806473D324(Ped ped, float x, float y, float z)
	{
		PED::_0xCF0B19806473D324(ped, x, y, z);
	}

	static void LUA_NATIVE_PED__0xB4B7C92FCE7347B7(Ped ped)
	{
		PED::_0xB4B7C92FCE7347B7(ped);
	}

	static void LUA_NATIVE_PED_REVIVE_INJURED_PED(Ped PedIndex)
	{
		PED::REVIVE_INJURED_PED(PedIndex);
	}

	static void LUA_NATIVE_PED_RESURRECT_PED(Ped PedIndex)
	{
		PED::RESURRECT_PED(PedIndex);
	}

	static void LUA_NATIVE_PED_SET_PED_NAME_DEBUG(Ped PedIndex, sol::stack_object debugName)
	{
		PED::SET_PED_NAME_DEBUG(PedIndex, debugName.is<const char*>() ? debugName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED_SPECIAL_FUNCTION_DO_NOT_USE(Ped PedIndex, bool bNoCollisionUntilClear)
	{
		PED::SPECIAL_FUNCTION_DO_NOT_USE(PedIndex, bNoCollisionUntilClear);
	}

	static bool LUA_NATIVE_PED__0x7020839C7302D8AC(Ped ped)
	{
		auto retval = (bool)PED::_0x7020839C7302D8AC(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0xE1AADD0055D76603(Ped ped, Entity entity, int boneIndex1, int boneIndex2, float x, float y, float z, float p7, bool p8, bool p9, int p10)
	{
		PED::_0xE1AADD0055D76603(ped, entity, boneIndex1, boneIndex2, x, y, z, p7, p8, p9, p10);
	}

	static void LUA_NATIVE_PED__0x5A1A929C8B729B4A(Ped ped)
	{
		PED::_0x5A1A929C8B729B4A(ped);
	}

	static void LUA_NATIVE_PED__0x97A38B65EBDA3D50(Ped ped, bool p1)
	{
		PED::_0x97A38B65EBDA3D50(ped, p1);
	}

	static bool LUA_NATIVE_PED__0x06A10B4D7F50B0C3(Ped ped)
	{
		auto retval = (bool)PED::_0x06A10B4D7F50B0C3(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x88A5564B19C15391(Ped ped)
	{
		auto retval = (bool)PED::_0x88A5564B19C15391(ped);
		return retval;
	}

	static int LUA_NATIVE_PED__0x354CA4DDDEEC397A(Ped ped)
	{
		auto retval = PED::_0x354CA4DDDEEC397A(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0xFEA6126C34DF2532(Ped ped, bool p1)
	{
		PED::_0xFEA6126C34DF2532(ped, p1);
	}

	static void LUA_NATIVE_PED__0xA967D6A8ED2D713B(Ped ped, bool p1)
	{
		PED::_0xA967D6A8ED2D713B(ped, p1);
	}

	static void LUA_NATIVE_PED_APPLY_PED_BLOOD_SPECIFIC(Ped pedIndex, int component, float u, float v, float rotation, float scale, int forcedFrame, float preAge, sol::stack_object bloodName)
	{
		PED::APPLY_PED_BLOOD_SPECIFIC(pedIndex, component, u, v, rotation, scale, forcedFrame, preAge, bloodName.is<const char*>() ? bloodName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__0x58D32261AE0F0843(Ped ped, int boneId, float p2, float p3, float p4, float p5, float p6, float p7, sol::stack_object p8)
	{
		PED::_0x58D32261AE0F0843(ped, boneId, p2, p3, p4, p5, p6, p7, p8.is<const char*>() ? p8.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__0x735662994E60A710(Ped ped, bool p1)
	{
		PED::_0x735662994E60A710(ped, p1);
	}

	static void LUA_NATIVE_PED__0x91BAB9E064F036CD(Any p0, Any p1)
	{
		PED::_0x91BAB9E064F036CD(p0, p1);
	}

	static void LUA_NATIVE_PED__0x897934E868EDDD6C(Ped ped, int p1, float p2, float p3, float p4)
	{
		PED::_0x897934E868EDDD6C(ped, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_PED__SET_PED_ACTIVATE_WOUND_EFFECT(Ped ped, int p1, int boneId, float moveWoundLeftRight, float bloodFountainPressure, float yaw, float bloodFountainDirection, float bloodFountainPulse, float p8, float p9)
	{
		PED::_SET_PED_ACTIVATE_WOUND_EFFECT(ped, p1, boneId, moveWoundLeftRight, bloodFountainPressure, yaw, bloodFountainDirection, bloodFountainPulse, p8, p9);
	}

	static void LUA_NATIVE_PED__UPDATE_PED_WOUND_EFFECT(Ped ped, float value)
	{
		PED::_UPDATE_PED_WOUND_EFFECT(ped, value);
	}

	static void LUA_NATIVE_PED_APPLY_PED_DAMAGE_PACK(Ped PedIndex, sol::stack_object packName, float preAge, float alpha_param)
	{
		PED::APPLY_PED_DAMAGE_PACK(PedIndex, packName.is<const char*>() ? packName.as<const char*>() : nullptr, preAge, alpha_param);
	}

	static void LUA_NATIVE_PED_CLEAR_PED_BLOOD_DAMAGE(Ped pedIndex)
	{
		PED::CLEAR_PED_BLOOD_DAMAGE(pedIndex);
	}

	static void LUA_NATIVE_PED_CLEAR_PED_BLOOD_DAMAGE_BY_ZONE(Ped PedIndex, int zone)
	{
		PED::CLEAR_PED_BLOOD_DAMAGE_BY_ZONE(PedIndex, zone);
	}

	static void LUA_NATIVE_PED_CLEAR_PED_DAMAGE_DECAL_BY_ZONE(Ped PedIndex, int zone, sol::stack_object damageDecalName)
	{
		PED::CLEAR_PED_DAMAGE_DECAL_BY_ZONE(PedIndex, zone, damageDecalName.is<const char*>() ? damageDecalName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__CLEAR_PED_BLOOD_DAMAGE_FACIAL(Ped ped, int p1)
	{
		PED::_CLEAR_PED_BLOOD_DAMAGE_FACIAL(ped, p1);
	}

	static void LUA_NATIVE_PED__0x34C11114887150FD(Any p0, Any p1)
	{
		PED::_0x34C11114887150FD(p0, p1);
	}

	static void LUA_NATIVE_PED__0xD8544F6260F5F01E(Ped ped, int p1)
	{
		PED::_0xD8544F6260F5F01E(ped, p1);
	}

	static void LUA_NATIVE_PED__0xEB8886E1065654CD(Ped ped, int p1, sol::stack_object p2, float p3)
	{
		PED::_0xEB8886E1065654CD(ped, p1, p2.is<const char*>() ? p2.as<const char*>() : nullptr, p3);
	}

	static Ped LUA_NATIVE_PED_FADE_AND_DESTROY_PED(Ped ped)
	{
		PED::FADE_AND_DESTROY_PED(&ped);
		return ped;
	}

	static bool LUA_NATIVE_PED__IS_PED_QUEUED_FOR_DELETION(Ped ped)
	{
		auto retval = (bool)PED::_IS_PED_QUEUED_FOR_DELETION(ped);
		return retval;
	}

	static void LUA_NATIVE_PED_CLEAR_PED_WETNESS(Ped pedIndex)
	{
		PED::CLEAR_PED_WETNESS(pedIndex);
	}

	static void LUA_NATIVE_PED_SET_PED_WETNESS_HEIGHT(Ped pedIndex, float height)
	{
		PED::SET_PED_WETNESS_HEIGHT(pedIndex, height);
	}

	static void LUA_NATIVE_PED__0xF9CFF5BB70E8A2CB(Ped ped, float p1)
	{
		PED::_0xF9CFF5BB70E8A2CB(ped, p1);
	}

	static void LUA_NATIVE_PED_SET_PED_WETNESS_ENABLED_THIS_FRAME(Ped pedIndex)
	{
		PED::SET_PED_WETNESS_ENABLED_THIS_FRAME(pedIndex);
	}

	static void LUA_NATIVE_PED__0xA7A806677F8DE138(Ped ped)
	{
		PED::_0xA7A806677F8DE138(ped);
	}

	static void LUA_NATIVE_PED__0xA064BBABB064446F(Any p0)
	{
		PED::_0xA064BBABB064446F(p0);
	}

	static void LUA_NATIVE_PED_CLEAR_PED_ENV_DIRT(Ped pedIndex)
	{
		PED::CLEAR_PED_ENV_DIRT(pedIndex);
	}

	static void LUA_NATIVE_PED_SET_PED_SWEAT(Ped pedIndex, float amount)
	{
		PED::SET_PED_SWEAT(pedIndex, amount);
	}

	static void LUA_NATIVE_PED_CLEAR_PED_DECORATIONS(Ped PedIndex)
	{
		PED::CLEAR_PED_DECORATIONS(PedIndex);
	}

	static bool LUA_NATIVE_PED_WAS_PED_SKELETON_UPDATED(Ped PedIndex)
	{
		auto retval = (bool)PED::WAS_PED_SKELETON_UPDATED(PedIndex);
		return retval;
	}

	static Vector3 LUA_NATIVE_PED_GET_PED_BONE_COORDS(Ped PedIndex, int bone, float vecOffsetX, float vecOffsetY, float vecOffsetZ)
	{
		auto retval = PED::GET_PED_BONE_COORDS(PedIndex, bone, vecOffsetX, vecOffsetY, vecOffsetZ);
		return retval;
	}

	static int LUA_NATIVE_PED_ADD_SCENARIO_BLOCKING_AREA(float vMinX, float vMinY, float vMinZ, float vMaxX, float vMaxY, float vMaxZ, bool bNetwork, int blockingFlags)
	{
		auto retval = PED::ADD_SCENARIO_BLOCKING_AREA(vMinX, vMinY, vMinZ, vMaxX, vMaxY, vMaxZ, bNetwork, blockingFlags);
		return retval;
	}

	static void LUA_NATIVE_PED_REMOVE_SCENARIO_BLOCKING_AREAS()
	{
		PED::REMOVE_SCENARIO_BLOCKING_AREAS();
	}

	static void LUA_NATIVE_PED_REMOVE_SCENARIO_BLOCKING_AREA(int ScenarioBlockingIndex, bool bNetwork)
	{
		PED::REMOVE_SCENARIO_BLOCKING_AREA(ScenarioBlockingIndex, bNetwork);
	}

	static Any LUA_NATIVE_PED__ADD_SCENARIO_BLOCKING_VOLUME(Volume volume, bool p1, int flag)
	{
		auto retval = PED::_ADD_SCENARIO_BLOCKING_VOLUME(volume, p1, flag);
		return retval;
	}

	static Any LUA_NATIVE_PED__0x6F46F8ACB44C4FC1(Any p0)
	{
		auto retval = PED::_0x6F46F8ACB44C4FC1(p0);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_SCENARIO_BLOCKING_AREA_VALID(Any p0)
	{
		auto retval = (bool)PED::_IS_SCENARIO_BLOCKING_AREA_VALID(p0);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_USING_SCENARIO_HASH(Ped ped, Hash scenarioHash)
	{
		auto retval = (bool)PED::IS_PED_USING_SCENARIO_HASH(ped, scenarioHash);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_USING_ANY_SCENARIO(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_USING_ANY_SCENARIO(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_USING_THIS_SCENARIO(Ped ped, int scenario)
	{
		auto retval = (bool)PED::IS_PED_USING_THIS_SCENARIO(ped, scenario);
		return retval;
	}

	static bool LUA_NATIVE_PED__CAN_PED_USE_SCENARIO_POINT(Ped ped, int scenario, Any p2, Any p3, Any p4)
	{
		auto retval = (bool)PED::_CAN_PED_USE_SCENARIO_POINT(ped, scenario, p2, p3, p4);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x1148F706CF4EBDDA(Ped ped, Hash p1, int p2)
	{
		auto retval = (bool)PED::_0x1148F706CF4EBDDA(ped, p1, p2);
		return retval;
	}

	static bool LUA_NATIVE_PED_SET_PED_PANIC_EXIT_SCENARIO(Ped PedIndex, float vDangerPositionX, float vDangerPositionY, float vDangerPositionZ)
	{
		auto retval = (bool)PED::SET_PED_PANIC_EXIT_SCENARIO(PedIndex, vDangerPositionX, vDangerPositionY, vDangerPositionZ);
		return retval;
	}

	static void LUA_NATIVE_PED_TOGGLE_SCENARIO_PED_COWER_IN_PLACE(Ped PedIndex, bool bStart)
	{
		PED::TOGGLE_SCENARIO_PED_COWER_IN_PLACE(PedIndex, bStart);
	}

	static void LUA_NATIVE_PED__0xD8CEEED54C672B5D(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6)
	{
		PED::_0xD8CEEED54C672B5D(p0, p1, p2, p3, p4, p5, p6);
	}

	static bool LUA_NATIVE_PED_SET_PED_SHOULD_PLAY_DIRECTED_NORMAL_SCENARIO_EXIT(Ped PedIndex, float vReactPositionX, float vReactPositionY, float vReactPositionZ)
	{
		auto retval = (bool)PED::SET_PED_SHOULD_PLAY_DIRECTED_NORMAL_SCENARIO_EXIT(PedIndex, vReactPositionX, vReactPositionY, vReactPositionZ);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_SHOULD_PLAY_NORMAL_SCENARIO_EXIT(Ped PedIndex)
	{
		PED::SET_PED_SHOULD_PLAY_NORMAL_SCENARIO_EXIT(PedIndex);
	}

	static void LUA_NATIVE_PED_SET_PED_SHOULD_PLAY_IMMEDIATE_SCENARIO_EXIT(Ped PedIndex)
	{
		PED::SET_PED_SHOULD_PLAY_IMMEDIATE_SCENARIO_EXIT(PedIndex);
	}

	static bool LUA_NATIVE_PED_SET_PED_SHOULD_PLAY_FLEE_SCENARIO_EXIT(Ped PedIndex, float vDangerPositionX, float vDangerPositionY, float vDangerPositionZ, int lookIntensity)
	{
		auto retval = (bool)PED::SET_PED_SHOULD_PLAY_FLEE_SCENARIO_EXIT(PedIndex, vDangerPositionX, vDangerPositionY, vDangerPositionZ, lookIntensity);
		return retval;
	}

	static bool LUA_NATIVE_PED_SET_PED_SHOULD_PLAY_COMBAT_SCENARIO_EXIT(Ped ped, float x, float y, float z, int lookIntensity)
	{
		auto retval = (bool)PED::SET_PED_SHOULD_PLAY_COMBAT_SCENARIO_EXIT(ped, x, y, z, lookIntensity);
		return retval;
	}

	static bool LUA_NATIVE_PED_SET_PED_SHOULD_PLAY_EMOTIONAL_SCENARIO_EXIT(Ped ped, float x, float y, float z, int lookIntensity, bool p5)
	{
		auto retval = (bool)PED::SET_PED_SHOULD_PLAY_EMOTIONAL_SCENARIO_EXIT(ped, x, y, z, lookIntensity, p5);
		return retval;
	}

	static bool LUA_NATIVE_PED_SET_PED_SHOULD_PLAY_QUICK_SCENARIO_EXIT(Ped ped, float x, float y, float z, int lookIntensity, bool p5)
	{
		auto retval = (bool)PED::SET_PED_SHOULD_PLAY_QUICK_SCENARIO_EXIT(ped, x, y, z, lookIntensity, p5);
		return retval;
	}

	static bool LUA_NATIVE_PED__0xF9331B3A314EB49D(Ped ped)
	{
		auto retval = (bool)PED::_0xF9331B3A314EB49D(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0xE735A7DA22E88359(Any p0)
	{
		PED::_0xE735A7DA22E88359(p0);
	}

	static Any LUA_NATIVE_PED__0x82CB0F3F0C7785E5(Any p0)
	{
		auto retval = PED::_0x82CB0F3F0C7785E5(p0);
		return retval;
	}

	static void LUA_NATIVE_PED__0xCA95C156C14B2054(Any p0, Any p1)
	{
		PED::_0xCA95C156C14B2054(p0, p1);
	}

	static void LUA_NATIVE_PED_SET_FACIAL_IDLE_ANIM_OVERRIDE(Ped PedIndex, sol::stack_object pOverrideIdleClipName, sol::stack_object pOverrideIdleClipDictName)
	{
		PED::SET_FACIAL_IDLE_ANIM_OVERRIDE(PedIndex, pOverrideIdleClipName.is<const char*>() ? pOverrideIdleClipName.as<const char*>() : nullptr, pOverrideIdleClipDictName.is<const char*>() ? pOverrideIdleClipDictName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED_CLEAR_FACIAL_IDLE_ANIM_OVERRIDE(Ped PedIndex)
	{
		PED::CLEAR_FACIAL_IDLE_ANIM_OVERRIDE(PedIndex);
	}

	static void LUA_NATIVE_PED__REQUEST_PED_FACIAL_MOOD_THIS_FRAME(Ped ped, Hash mood, int p2)
	{
		PED::_REQUEST_PED_FACIAL_MOOD_THIS_FRAME(ped, mood, p2);
	}

	static void LUA_NATIVE_PED__0xD2F0FE8805D91647(Any p0, Any p1)
	{
		PED::_0xD2F0FE8805D91647(p0, p1);
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_PLAY_GESTURE_ANIMS(Ped PedIndex, bool p1, Any p2)
	{
		PED::SET_PED_CAN_PLAY_GESTURE_ANIMS(PedIndex, p1, p2);
	}

	static void LUA_NATIVE_PED__0x7EDB3C766B0D073F(Ped ped)
	{
		PED::_0x7EDB3C766B0D073F(ped);
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_PLAY_AMBIENT_ANIMS(Ped PedIndex, bool bAlllowAmbientAnims)
	{
		PED::SET_PED_CAN_PLAY_AMBIENT_ANIMS(PedIndex, bAlllowAmbientAnims);
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_PLAY_AMBIENT_BASE_ANIMS(Ped PedIndex, bool bAlllowAmbientAnims)
	{
		PED::SET_PED_CAN_PLAY_AMBIENT_BASE_ANIMS(PedIndex, bAlllowAmbientAnims);
	}

	static void LUA_NATIVE_PED__0x4F63433CE3C08230(Ped ped, bool p1)
	{
		PED::_0x4F63433CE3C08230(ped, p1);
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_ARM_IK(Ped PedIndex, bool bEnableIK)
	{
		PED::SET_PED_CAN_ARM_IK(PedIndex, bEnableIK);
	}

	static void LUA_NATIVE_PED__SET_PED_CAN_UNK_BODYPART_IK(Ped ped, bool toggle)
	{
		PED::_SET_PED_CAN_UNK_BODYPART_IK(ped, toggle);
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_HEAD_IK(Ped PedIndex, bool bEnableIK)
	{
		PED::SET_PED_CAN_HEAD_IK(PedIndex, bEnableIK);
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_LEG_IK(Ped PedIndex, bool bEnableIK)
	{
		PED::SET_PED_CAN_LEG_IK(PedIndex, bEnableIK);
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_TORSO_IK(Ped PedIndex, bool bEnableIK)
	{
		PED::SET_PED_CAN_TORSO_IK(PedIndex, bEnableIK);
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_TORSO_REACT_IK(Ped PedIndex, bool bEnableIK)
	{
		PED::SET_PED_CAN_TORSO_REACT_IK(PedIndex, bEnableIK);
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_TORSO_VEHICLE_IK(Ped PedIndex, bool bEnableIK)
	{
		PED::SET_PED_CAN_TORSO_VEHICLE_IK(PedIndex, bEnableIK);
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_USE_AUTO_CONVERSATION_LOOKAT(Ped PedIndex, bool bAllowAutoConversationLookAts)
	{
		PED::SET_PED_CAN_USE_AUTO_CONVERSATION_LOOKAT(PedIndex, bAllowAutoConversationLookAts);
	}

	static bool LUA_NATIVE_PED_IS_PED_HEADTRACKING_PED(Ped FirstPedIndex, Ped SecondPedIndex)
	{
		auto retval = (bool)PED::IS_PED_HEADTRACKING_PED(FirstPedIndex, SecondPedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_HEADTRACKING_ENTITY(Ped PedIndex, Entity EntityIndex)
	{
		auto retval = (bool)PED::IS_PED_HEADTRACKING_ENTITY(PedIndex, EntityIndex);
		return retval;
	}

	static void LUA_NATIVE_PED__DISABLE_AMBIENT_LOOK_AT_REQUESTS(Any p0, Any p1)
	{
		PED::_DISABLE_AMBIENT_LOOK_AT_REQUESTS(p0, p1);
	}

	static void LUA_NATIVE_PED__DISABLE_ALL_LOOK_AT_REQUESTS(Ped ped, int p1)
	{
		PED::_DISABLE_ALL_LOOK_AT_REQUESTS(ped, p1);
	}

	static void LUA_NATIVE_PED__0xCD9E5F94A2F38683(Ped ped, bool p1)
	{
		PED::_0xCD9E5F94A2F38683(ped, p1);
	}

	static void LUA_NATIVE_PED_SET_PED_CLOTH_PIN_FRAMES(Ped PedIndex, int pinFrames)
	{
		PED::SET_PED_CLOTH_PIN_FRAMES(PedIndex, pinFrames);
	}

	static void LUA_NATIVE_PED__0x1D4636C90BBEFACB(Ped ped, int p1)
	{
		PED::_0x1D4636C90BBEFACB(ped, p1);
	}

	static void LUA_NATIVE_PED__0xEF371232BC6053E1(Ped ped)
	{
		PED::_0xEF371232BC6053E1(ped);
	}

	static void LUA_NATIVE_PED__0x86F0B6730C32AC14(Ped ped, bool p1)
	{
		PED::_0x86F0B6730C32AC14(ped, p1);
	}

	static void LUA_NATIVE_PED__0x8101BA1C0B462412(Ped ped, int ropeId)
	{
		PED::_0x8101BA1C0B462412(ped, ropeId);
	}

	static void LUA_NATIVE_PED_SET_PED_CONFIG_FLAG(Ped PedIndex, int ConfigFlag, bool bTrue)
	{
		PED::SET_PED_CONFIG_FLAG(PedIndex, ConfigFlag, bTrue);
	}

	static void LUA_NATIVE_PED_SET_PED_RESET_FLAG(Ped PedIndex, int ResetFlag, bool bTrue)
	{
		PED::SET_PED_RESET_FLAG(PedIndex, ResetFlag, bTrue);
	}

	static bool LUA_NATIVE_PED_GET_PED_CONFIG_FLAG(Ped PedIndex, int ConfigFlag, bool DoDeadCheck)
	{
		auto retval = (bool)PED::GET_PED_CONFIG_FLAG(PedIndex, ConfigFlag, DoDeadCheck);
		return retval;
	}

	static bool LUA_NATIVE_PED_GET_PED_RESET_FLAG(Ped PedIndex, int ResetFlag)
	{
		auto retval = (bool)PED::GET_PED_RESET_FLAG(PedIndex, ResetFlag);
		return retval;
	}

	static void LUA_NATIVE_PED__0xC6981AFF6D2A71C2(Any p0)
	{
		PED::_0xC6981AFF6D2A71C2(p0);
	}

	static void LUA_NATIVE_PED__0xE0FE107AB174D64A(Any p0, Any p1)
	{
		PED::_0xE0FE107AB174D64A(p0, p1);
	}

	static void LUA_NATIVE_PED_SET_PED_GROUP_MEMBER_PASSENGER_INDEX(Ped PedIndex, int seat)
	{
		PED::SET_PED_GROUP_MEMBER_PASSENGER_INDEX(PedIndex, seat);
	}

	static std::tuple<bool, Entity> LUA_NATIVE_PED_IS_PED_EVASIVE_DIVING(Ped PedIndex, Entity EntityDivingFromIndex)
	{
		std::tuple<bool, Entity> return_values;
		std::get<0>(return_values) = (bool)PED::IS_PED_EVASIVE_DIVING(PedIndex, &EntityDivingFromIndex);
		std::get<1>(return_values) = EntityDivingFromIndex;

		return return_values;
	}

	static Any LUA_NATIVE_PED__SHOOT_TRIGGER_AT_COORDS(Ped ped, float x, float y, float z, int p4, float p5, int p6, float p7)
	{
		auto retval = PED::_SHOOT_TRIGGER_AT_COORDS(ped, x, y, z, p4, p5, p6, p7);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_THIS_MODEL_A_HORSE(Hash model)
	{
		auto retval = (bool)PED::_IS_THIS_MODEL_A_HORSE(model);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_MODEL_IS_SUPPRESSED(Hash PedModelHashKey, bool bSurpressModel)
	{
		PED::SET_PED_MODEL_IS_SUPPRESSED(PedModelHashKey, bSurpressModel);
	}

	static bool LUA_NATIVE_PED__IS_PED_MODEL_SUPPRESSED(Hash model)
	{
		auto retval = (bool)PED::_IS_PED_MODEL_SUPPRESSED(model);
		return retval;
	}

	static void LUA_NATIVE_PED__0x7ABBD9E449E0DB00(Ped ped, bool p1)
	{
		PED::_0x7ABBD9E449E0DB00(ped, p1);
	}

	static void LUA_NATIVE_PED__SET_PED_DISABLE_KICK_MOVE(Ped ped, bool disable)
	{
		PED::_SET_PED_DISABLE_KICK_MOVE(ped, disable);
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(Ped PedIndex, bool bAllow)
	{
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PedIndex, bAllow);
	}

	static void LUA_NATIVE_PED__0xE6CB36F43A95D75F(Any p0)
	{
		PED::_0xE6CB36F43A95D75F(p0);
	}

	static void LUA_NATIVE_PED_SET_PED_LEG_IK_MODE(Ped PedIndex, int nLegIkMode)
	{
		PED::SET_PED_LEG_IK_MODE(PedIndex, nLegIkMode);
	}

	static bool LUA_NATIVE_PED__IS_PED_IN_POINT(Ped ped, float x, float y, float z, float radius, bool p5)
	{
		auto retval = (bool)PED::_IS_PED_IN_POINT(ped, x, y, z, radius, p5);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_CAN_BE_LASSOED(Ped ped, bool toggle)
	{
		PED::_SET_PED_CAN_BE_LASSOED(ped, toggle);
	}

	static void LUA_NATIVE_PED_SET_PED_COMBAT_MOVEMENT(Ped PedIndex, int PedCombatMoveType)
	{
		PED::SET_PED_COMBAT_MOVEMENT(PedIndex, PedCombatMoveType);
	}

	static int LUA_NATIVE_PED_GET_PED_COMBAT_MOVEMENT(Ped PedIndex)
	{
		auto retval = PED::GET_PED_COMBAT_MOVEMENT(PedIndex);
		return retval;
	}

	static void LUA_NATIVE_PED__0x815C0074A1BC0D93(Ped ped, int p1)
	{
		PED::_0x815C0074A1BC0D93(ped, p1);
	}

	static int LUA_NATIVE_PED__0xFFDE295662405B25(Ped ped)
	{
		auto retval = PED::_0xFFDE295662405B25(ped);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_COMBAT_ABILITY(Ped PedIndex, int PedCombatAbilityType)
	{
		PED::SET_PED_COMBAT_ABILITY(PedIndex, PedCombatAbilityType);
	}

	static void LUA_NATIVE_PED_SET_PED_COMBAT_RANGE(Ped PedIndex, int CombatRange)
	{
		PED::SET_PED_COMBAT_RANGE(PedIndex, CombatRange);
	}

	static void LUA_NATIVE_PED_SET_PED_COMBAT_ATTRIBUTES(Ped PedIndex, int CombatAttribute, bool bActiveSkill)
	{
		PED::SET_PED_COMBAT_ATTRIBUTES(PedIndex, CombatAttribute, bActiveSkill);
	}

	static bool LUA_NATIVE_PED__GET_PED_COMBAT_ATTRIBUTE(Ped ped, int attributeIndex)
	{
		auto retval = (bool)PED::_GET_PED_COMBAT_ATTRIBUTE(ped, attributeIndex);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_COMBAT_ATTRIBUTE_HASH(Ped ped, Hash p1)
	{
		PED::_SET_PED_COMBAT_ATTRIBUTE_HASH(ped, p1);
	}

	static void LUA_NATIVE_PED_SET_PED_TARGET_LOSS_RESPONSE(Ped PedIndex, int TargetLossResponse)
	{
		PED::SET_PED_TARGET_LOSS_RESPONSE(PedIndex, TargetLossResponse);
	}

	static void LUA_NATIVE_PED__0x0A4618FFD517E24D(Any p0, Any p1)
	{
		PED::_0x0A4618FFD517E24D(p0, p1);
	}

	static void LUA_NATIVE_PED__0x712B2C2B2471B493(Ped ped, Hash p1)
	{
		PED::_0x712B2C2B2471B493(ped, p1);
	}

	static void LUA_NATIVE_PED__0x00B380FF2DF6AB7A(Any p0, Any p1)
	{
		PED::_0x00B380FF2DF6AB7A(p0, p1);
	}

	static void LUA_NATIVE_PED__SET_PED_COMBAT_STYLE(Ped ped, Hash combatStyleHash, int p2, float duration)
	{
		PED::_SET_PED_COMBAT_STYLE(ped, combatStyleHash, p2, duration);
	}

	static void LUA_NATIVE_PED__CLEAR_PED_COMBAT_STYLE(Ped ped, int p1)
	{
		PED::_CLEAR_PED_COMBAT_STYLE(ped, p1);
	}

	static void LUA_NATIVE_PED__SET_PED_COMBAT_STYLE_MOD(Ped ped, Hash combatStyleModHash, float duration)
	{
		PED::_SET_PED_COMBAT_STYLE_MOD(ped, combatStyleModHash, duration);
	}

	static void LUA_NATIVE_PED__CLEAR_PED_COMBAT_STYLE_MOD(Ped ped, Hash combatStyleModHash)
	{
		PED::_CLEAR_PED_COMBAT_STYLE_MOD(ped, combatStyleModHash);
	}

	static bool LUA_NATIVE_PED__0x5BF0B9D9A8E227A0(Ped ped)
	{
		auto retval = (bool)PED::_0x5BF0B9D9A8E227A0(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0x642720D8D69328B6(Ped ped, Hash p1)
	{
		PED::_0x642720D8D69328B6(ped, p1);
	}

	static bool LUA_NATIVE_PED_IS_PED_PERFORMING_MELEE_ACTION(Ped PedIndex, int p1, Hash p2)
	{
		auto retval = (bool)PED::IS_PED_PERFORMING_MELEE_ACTION(PedIndex, p1, p2);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x99DF2639DA76C1DC(Ped ped1, Ped ped2, int p2)
	{
		auto retval = (bool)PED::_0x99DF2639DA76C1DC(ped1, ped2, p2);
		return retval;
	}

	static float LUA_NATIVE_PED__GET_PED_MELEE_ACTION_PHASE(Ped ped)
	{
		auto retval = PED::_GET_PED_MELEE_ACTION_PHASE(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_BEING_STEALTH_KILLED(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_BEING_STEALTH_KILLED(PedIndex);
		return retval;
	}

	static Ped LUA_NATIVE_PED_GET_MELEE_TARGET_FOR_PED(Ped PedIndex)
	{
		auto retval = PED::GET_MELEE_TARGET_FOR_PED(PedIndex);
		return retval;
	}

	static void LUA_NATIVE_PED__0xDEDBED3020DA49DC(Any p0)
	{
		PED::_0xDEDBED3020DA49DC(p0);
	}

	static void LUA_NATIVE_PED__0xA405BF9F01960C16(Any p0)
	{
		PED::_0xA405BF9F01960C16(p0);
	}

	static Hash LUA_NATIVE_PED__GET_PED_BRAWLING_STYLE(Ped ped)
	{
		auto retval = PED::_GET_PED_BRAWLING_STYLE(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_BRAWLING_STYLE(Ped ped, Hash brawlingStyle)
	{
		PED::_SET_PED_BRAWLING_STYLE(ped, brawlingStyle);
	}

	static void LUA_NATIVE_PED__0x9D8DFE2DE9CB4DFC(Ped ped)
	{
		PED::_0x9D8DFE2DE9CB4DFC(ped);
	}

	static Any LUA_NATIVE_PED__0xC48AF420371C7407(Ped ped, Hash grapple)
	{
		auto retval = PED::_0xC48AF420371C7407(ped, grapple);
		return retval;
	}

	static Any LUA_NATIVE_PED__0x5EFA8A3D8A60D662(Any p0, Any p1)
	{
		auto retval = PED::_0x5EFA8A3D8A60D662(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_PED__0x242EDF85D4E87B65(Any p0)
	{
		auto retval = PED::_0x242EDF85D4E87B65(p0);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_COMBAT_BEHAVIOUR(Ped ped, Hash behaviour)
	{
		PED::_SET_PED_COMBAT_BEHAVIOUR(ped, behaviour);
	}

	static void LUA_NATIVE_PED__0x9A4AC116CC1EEE14(Any p0)
	{
		PED::_0x9A4AC116CC1EEE14(p0);
	}

	static void LUA_NATIVE_PED__0xE20027B414BFE6C7(Any p0, Any p1)
	{
		PED::_0xE20027B414BFE6C7(p0, p1);
	}

	static void LUA_NATIVE_PED__SET_PED_BEAT_MULTIPLIER(Ped ped, float p1)
	{
		PED::_SET_PED_BEAT_MULTIPLIER(ped, p1);
	}

	static void LUA_NATIVE_PED__SET_PED_ACTION_DISABLE_FLAG(Ped ped, int actionDisableFlag)
	{
		PED::_SET_PED_ACTION_DISABLE_FLAG(ped, actionDisableFlag);
	}

	static void LUA_NATIVE_PED__CLEAR_PED_ACTION_DISABLE_FLAG(Ped ped, int actionDisableFlag)
	{
		PED::_CLEAR_PED_ACTION_DISABLE_FLAG(ped, actionDisableFlag);
	}

	static bool LUA_NATIVE_PED__IS_PED_ACTION_DISABLE_FLAG_ENABLED(Ped ped, int actionDisableFlag)
	{
		auto retval = (bool)PED::_IS_PED_ACTION_DISABLE_FLAG_ENABLED(ped, actionDisableFlag);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_TARGET_ACTION_DISABLE_FLAG(Ped ped, int actionDisableFlag)
	{
		PED::_SET_PED_TARGET_ACTION_DISABLE_FLAG(ped, actionDisableFlag);
	}

	static void LUA_NATIVE_PED__CLEAR_PED_TARGET_ACTION_DISABLE_FLAG(Ped ped, int actionDisableFlag)
	{
		PED::_CLEAR_PED_TARGET_ACTION_DISABLE_FLAG(ped, actionDisableFlag);
	}

	static bool LUA_NATIVE_PED__IS_PED_TARGET_ACTION_DISABLE_FLAG_ENABLED(Ped ped, int actionDisableFlag)
	{
		auto retval = (bool)PED::_IS_PED_TARGET_ACTION_DISABLE_FLAG_ENABLED(ped, actionDisableFlag);
		return retval;
	}

	static void LUA_NATIVE_PED__0x57F35552E771BE9D(Ped ped, int p1)
	{
		PED::_0x57F35552E771BE9D(ped, p1);
	}

	static void LUA_NATIVE_PED__0x7C10221CE718AA72(Ped ped, int p1)
	{
		PED::_0x7C10221CE718AA72(ped, p1);
	}

	static bool LUA_NATIVE_PED__0x0D3B1568917EBDA0(Ped ped, int p1)
	{
		auto retval = (bool)PED::_0x0D3B1568917EBDA0(ped, p1);
		return retval;
	}

	static void LUA_NATIVE_PED__0x29F3539189D3E277(Any p0, Any p1)
	{
		PED::_0x29F3539189D3E277(p0, p1);
	}

	static void LUA_NATIVE_PED__0xE9E06EA514A69061(Any p0, Any p1)
	{
		PED::_0xE9E06EA514A69061(p0, p1);
	}

	static void LUA_NATIVE_PED__SET_PED_WRITHING_DURATION(Ped ped, float writhingDuration1, float writhingDuration2, int p3)
	{
		PED::_SET_PED_WRITHING_DURATION(ped, writhingDuration1, writhingDuration2, p3);
	}

	static float LUA_NATIVE_PED__GET_PED_REMAINING_REVIVAL_TIME(Ped ped, bool normalized)
	{
		auto retval = PED::_GET_PED_REMAINING_REVIVAL_TIME(ped, normalized);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PAUSE_PED_WRITHE_BLEEDOUT(Ped ped, bool toggle)
	{
		PED::SET_PAUSE_PED_WRITHE_BLEEDOUT(ped, toggle);
	}

	static bool LUA_NATIVE_PED__0x12EB4E31F092C9B3(Ped ped)
	{
		auto retval = (bool)PED::_0x12EB4E31F092C9B3(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_GET_PED_IS_GRAPPLING(Ped ped)
	{
		auto retval = (bool)PED::GET_PED_IS_GRAPPLING(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_GET_PED_IS_BEING_GRAPPLED(Ped ped)
	{
		auto retval = (bool)PED::GET_PED_IS_BEING_GRAPPLED(ped);
		return retval;
	}

	static Ped LUA_NATIVE_PED__GET_PED_GRAPPLER(Ped ped)
	{
		auto retval = PED::_GET_PED_GRAPPLER(ped);
		return retval;
	}

	static int LUA_NATIVE_PED_GET_PED_GRAPPLE_STATE(Ped ped)
	{
		auto retval = PED::GET_PED_GRAPPLE_STATE(ped);
		return retval;
	}

	static Hash LUA_NATIVE_PED__GET_PED_GRAPPLE_STYLE(Ped ped)
	{
		auto retval = PED::_GET_PED_GRAPPLE_STYLE(ped);
		return retval;
	}

	static Any LUA_NATIVE_PED__SET_PED_GRAPPLE_STYLE(Ped ped, Hash style)
	{
		auto retval = PED::_SET_PED_GRAPPLE_STYLE(ped, style);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_GRAPPLE_SEQUENCE(Ped ped, sol::stack_object grappleSequence)
	{
		PED::_SET_PED_GRAPPLE_SEQUENCE(ped, grappleSequence.is<const char*>() ? grappleSequence.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__SET_PED_GRAPPLE_FLAG(Ped ped, int flag, bool enable)
	{
		PED::_SET_PED_GRAPPLE_FLAG(ped, flag, enable);
	}

	static void LUA_NATIVE_PED__CLEAR_PED_GRAPPLE_FLAG(Ped ped, int flag)
	{
		PED::_CLEAR_PED_GRAPPLE_FLAG(ped, flag);
	}

	static int LUA_NATIVE_PED__GET_PED_GRAPPLE_FLAG(Ped ped)
	{
		auto retval = PED::_GET_PED_GRAPPLE_FLAG(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_GRAPPLE_ACTION(Ped ped, Hash grappleAction)
	{
		PED::_SET_PED_GRAPPLE_ACTION(ped, grappleAction);
	}

	static Any LUA_NATIVE_PED__SET_PED_GRAPPLE_EFFECT_MULTIPLIER(Ped ped, float multiplier)
	{
		auto retval = PED::_SET_PED_GRAPPLE_EFFECT_MULTIPLIER(ped, multiplier);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_GRAPPLE_ANIMATION(Ped ped, Hash grappleAnim)
	{
		PED::_SET_PED_GRAPPLE_ANIMATION(ped, grappleAnim);
	}

	static void LUA_NATIVE_PED_SET_PED_FLEE_ATTRIBUTES(Ped PedIndex, int FleeAttribute, bool bActiveSkill)
	{
		PED::SET_PED_FLEE_ATTRIBUTES(PedIndex, FleeAttribute, bActiveSkill);
	}

	static bool LUA_NATIVE_PED__IS_PED_COWERING(Ped ped)
	{
		auto retval = (bool)PED::_IS_PED_COWERING(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_ANY_PED_NEAR_POINT(float pointX, float pointY, float pointZ, float radius)
	{
		auto retval = (bool)PED::IS_ANY_PED_NEAR_POINT(pointX, pointY, pointZ, radius);
		return retval;
	}

	static void LUA_NATIVE_PED_FORCE_PED_AI_AND_ANIMATION_UPDATE(Ped PedIndex, bool ForceAIPreCameraUpdate, bool ForceZeroTimestep)
	{
		PED::FORCE_PED_AI_AND_ANIMATION_UPDATE(PedIndex, ForceAIPreCameraUpdate, ForceZeroTimestep);
	}

	static void LUA_NATIVE_PED__0xC2722B252C79E641(Ped ped, Any p1, Any p2, bool p3)
	{
		PED::_0xC2722B252C79E641(ped, p1, p2, p3);
	}

	static bool LUA_NATIVE_PED__IS_PED_DOING_SCENARIO_TRANSITION(Ped ped)
	{
		auto retval = (bool)PED::_IS_PED_DOING_SCENARIO_TRANSITION(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x2DC0E8DCBD3546E9(Ped ped)
	{
		auto retval = (bool)PED::_0x2DC0E8DCBD3546E9(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__ADD_SCENARIO_TRANSITION(Ped ped)
	{
		PED::_ADD_SCENARIO_TRANSITION(ped);
	}

	static void LUA_NATIVE_PED__GIVE_PED_HASH_COMMAND(Ped ped, Hash commandHash, float activationDuration)
	{
		PED::_GIVE_PED_HASH_COMMAND(ped, commandHash, activationDuration);
	}

	static bool LUA_NATIVE_PED__GET_IS_PED_COMMAND_HASH_PRESENT(Ped ped, Hash commandHash)
	{
		auto retval = (bool)PED::_GET_IS_PED_COMMAND_HASH_PRESENT(ped, commandHash);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_HEADING_TOWARDS_POSITION(Ped iPedIndex, float vPointX, float vPointY, float vPointZ, float fDegreesDelta)
	{
		auto retval = (bool)PED::IS_PED_HEADING_TOWARDS_POSITION(iPedIndex, vPointX, vPointY, vPointZ, fDegreesDelta);
		return retval;
	}

	static void LUA_NATIVE_PED__0x600BBDD29820370C(Ped ped)
	{
		PED::_0x600BBDD29820370C(ped);
	}

	static void LUA_NATIVE_PED_REQUEST_PED_VISIBILITY_TRACKING(Ped ped)
	{
		PED::REQUEST_PED_VISIBILITY_TRACKING(ped);
	}

	static void LUA_NATIVE_PED_RELEASE_PED_VISIBILITY_TRACKING(Ped ped)
	{
		PED::RELEASE_PED_VISIBILITY_TRACKING(ped);
	}

	static void LUA_NATIVE_PED_REQUEST_PED_VEHICLE_VISIBILITY_TRACKING(Ped ped, bool trackvehicle)
	{
		PED::REQUEST_PED_VEHICLE_VISIBILITY_TRACKING(ped, trackvehicle);
	}

	static void LUA_NATIVE_PED_REQUEST_PED_USE_SMALL_BBOX_VISIBILITY_TRACKING(Ped ped, bool useSmallBox)
	{
		PED::REQUEST_PED_USE_SMALL_BBOX_VISIBILITY_TRACKING(ped, useSmallBox);
	}

	static int LUA_NATIVE_PED_GET_TRACKED_PED_PIXELCOUNT(Ped ped)
	{
		auto retval = PED::GET_TRACKED_PED_PIXELCOUNT(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_TRACKED_PED_VISIBLE(Ped ped)
	{
		auto retval = (bool)PED::IS_TRACKED_PED_VISIBLE(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_TRACKED_PED_VISIBILITY_PERCENTAGE_NOT_LESS_THAN(Ped ped, float percent)
	{
		auto retval = (bool)PED::_IS_TRACKED_PED_VISIBILITY_PERCENTAGE_NOT_LESS_THAN(ped, percent);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_PED_VISIBILITY_TRACKED(Ped ped)
	{
		auto retval = (bool)PED::_IS_PED_VISIBILITY_TRACKED(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_CAN_PED_BE_MOUNTED(Ped ped)
	{
		auto retval = (bool)PED::CAN_PED_BE_MOUNTED(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_META_PED_FISH(Ped ped)
	{
		auto retval = (bool)PED::_IS_META_PED_FISH(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_EVENT_IN_QUEUE(Ped ped, Hash eventType)
	{
		auto retval = (bool)PED::IS_EVENT_IN_QUEUE(ped, eventType);
		return retval;
	}

	static int LUA_NATIVE_PED_CAN_PED_SEE_ENTITY(Ped ped, Entity targetEntity, bool p2, bool p3)
	{
		auto retval = PED::CAN_PED_SEE_ENTITY(ped, targetEntity, p2, p3);
		return retval;
	}

	static int LUA_NATIVE_PED_CAN_PED_SEE_PED_CACHED(Ped ped, Ped targetPed, bool p2)
	{
		auto retval = PED::CAN_PED_SEE_PED_CACHED(ped, targetPed, p2);
		return retval;
	}

	static float LUA_NATIVE_PED__0x0EA9EACBA3B01601(Ped ped1, Ped ped2, bool p2)
	{
		auto retval = PED::_0x0EA9EACBA3B01601(ped1, ped2, p2);
		return retval;
	}

	static int LUA_NATIVE_PED_GET_PED_BONE_INDEX(Ped iPedIndex, int boneTag)
	{
		auto retval = PED::GET_PED_BONE_INDEX(iPedIndex, boneTag);
		return retval;
	}

	static int LUA_NATIVE_PED__0xC5303F460A40D21D(Ped ped, int p1)
	{
		auto retval = PED::_0xC5303F460A40D21D(ped, p1);
		return retval;
	}

	static void LUA_NATIVE_PED__0xE29D8CD66553DBAA(Ped horse)
	{
		PED::_0xE29D8CD66553DBAA(horse);
	}

	static void LUA_NATIVE_PED__0xB06F5F1DEF417216(Any p0, Any p1, Any p2, Any p3)
	{
		PED::_0xB06F5F1DEF417216(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_PED__0xFC23348F0F4E245F(Any p0, Any p1, Any p2, Any p3)
	{
		PED::_0xFC23348F0F4E245F(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_PED__0x9184788BFF1EDAD7(Any p0, Any p1)
	{
		PED::_0x9184788BFF1EDAD7(p0, p1);
	}

	static void LUA_NATIVE_PED__SET_PED_DIRT_CLEANED(Ped ped, float p1, int p2, bool p3, bool p4)
	{
		PED::_SET_PED_DIRT_CLEANED(ped, p1, p2, p3, p4);
	}

	static Any LUA_NATIVE_PED__0x0105FEE8F9091255(Any p0, Any p1)
	{
		auto retval = PED::_0x0105FEE8F9091255(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_PED__0xD049920CD29F6CC8(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		PED::_0xD049920CD29F6CC8(p0, p1, p2, p3, p4);
	}

	static Any LUA_NATIVE_PED__0xBB3E5370EBB6BE28(Any p0, Any p1)
	{
		auto retval = PED::_0xBB3E5370EBB6BE28(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_PED__0x2FA568BFA725F8D6(Any p0, Any p1, Any p2, Any p3)
	{
		PED::_0x2FA568BFA725F8D6(p0, p1, p2, p3);
	}

	static Any LUA_NATIVE_PED__0x56E4BAD93D33453C(Any p0, Any p1)
	{
		auto retval = PED::_0x56E4BAD93D33453C(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_PED__0x75A082563B4452E5(Any p0, Any p1, Any p2, Any p3)
	{
		PED::_0x75A082563B4452E5(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_PED__0x16802C32B2FCA06B(Any p0, Any p1, Any p2, Any p3)
	{
		PED::_0x16802C32B2FCA06B(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_PED__0x8BA0C65AC15A7D33(Any p0, Any p1, Any p2, Any p3)
	{
		PED::_0x8BA0C65AC15A7D33(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_PED__0x0FFDF937E5C11382(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5)
	{
		PED::_0x0FFDF937E5C11382(p0, p1, p2, p3, p4, p5);
	}

	static void LUA_NATIVE_PED__0x5FCF25D584065BFD(Any p0, Any p1, Any p2, Any p3)
	{
		PED::_0x5FCF25D584065BFD(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_PED__0xA2116C1E4ED85C24(Ped ped, bool inverted)
	{
		PED::_0xA2116C1E4ED85C24(ped, inverted);
	}

	static bool LUA_NATIVE_PED_FORCE_PED_MOTION_STATE(Ped PedIndex, Hash state, bool shouldRestart, int exitstate, bool ForceAIPreCameraUpdate)
	{
		auto retval = (bool)PED::FORCE_PED_MOTION_STATE(PedIndex, state, shouldRestart, exitstate, ForceAIPreCameraUpdate);
		return retval;
	}

	static void LUA_NATIVE_PED__0x75D3333409CD33CE(Any p0, Any p1, Any p2)
	{
		PED::_0x75D3333409CD33CE(p0, p1, p2);
	}

	static std::tuple<bool, float, float> LUA_NATIVE_PED_GET_PED_CURRENT_MOVE_BLEND_RATIO(Ped PedIndex, float MbrXOut, float MbrYOut)
	{
		std::tuple<bool, float, float> return_values;
		std::get<0>(return_values) = (bool)PED::GET_PED_CURRENT_MOVE_BLEND_RATIO(PedIndex, &MbrXOut, &MbrYOut);
		std::get<1>(return_values) = MbrXOut;
		std::get<2>(return_values) = MbrYOut;

		return return_values;
	}

	static void LUA_NATIVE_PED_SET_PED_MAX_MOVE_BLEND_RATIO(Ped PedIndex, float MoveBlendRatio)
	{
		PED::SET_PED_MAX_MOVE_BLEND_RATIO(PedIndex, MoveBlendRatio);
	}

	static void LUA_NATIVE_PED_SET_PED_MIN_MOVE_BLEND_RATIO(Ped PedIndex, float MoveBlendRatio)
	{
		PED::SET_PED_MIN_MOVE_BLEND_RATIO(PedIndex, MoveBlendRatio);
	}

	static void LUA_NATIVE_PED__0xBC1DC48270468444(Any p0)
	{
		PED::_0xBC1DC48270468444(p0);
	}

	static float LUA_NATIVE_PED__0x46BF2A810679D6E6(Ped ped, float maxMoveBlendRatio)
	{
		auto retval = PED::_0x46BF2A810679D6E6(ped, maxMoveBlendRatio);
		return retval;
	}

	static float LUA_NATIVE_PED__0xCA95924C893A0C91(Ped ped, float p1)
	{
		auto retval = PED::_0xCA95924C893A0C91(ped, p1);
		return retval;
	}

	static void LUA_NATIVE_PED__HORSE_AGITATE(Ped mount, bool kickOffRider)
	{
		PED::_HORSE_AGITATE(mount, kickOffRider);
	}

	static void LUA_NATIVE_PED__0x413697EC260AABBF(Any p0, Any p1, Any p2)
	{
		PED::_0x413697EC260AABBF(p0, p1, p2);
	}

	static void LUA_NATIVE_PED__0xCAC43D060099EA72(Ped ped)
	{
		PED::_0xCAC43D060099EA72(ped);
	}

	static void LUA_NATIVE_PED__0xC9151483CC06A414(Ped ped)
	{
		PED::_0xC9151483CC06A414(ped);
	}

	static void LUA_NATIVE_PED__0xAD3330E3C3E98007(Any p0, Any p1)
	{
		PED::_0xAD3330E3C3E98007(p0, p1);
	}

	static Any LUA_NATIVE_PED__0xB8E2D655E1D5BD39(Any p0)
	{
		auto retval = PED::_0xB8E2D655E1D5BD39(p0);
		return retval;
	}

	static Any LUA_NATIVE_PED__0x7BB810E8B343AC7B(Any p0)
	{
		auto retval = PED::_0x7BB810E8B343AC7B(p0);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_MOVE_RATE_OVERRIDE(Ped PedIndex, float DesiredRate)
	{
		PED::SET_PED_MOVE_RATE_OVERRIDE(PedIndex, DesiredRate);
	}

	static std::tuple<int, Vehicle> LUA_NATIVE_PED_GET_PED_NEARBY_VEHICLES(Ped PedIndex, Vehicle array)
	{
		std::tuple<int, Vehicle> return_values;
		std::get<0>(return_values) = PED::GET_PED_NEARBY_VEHICLES(PedIndex, &array);
		std::get<1>(return_values) = array;

		return return_values;
	}

	static int LUA_NATIVE_PED_GET_PED_NEARBY_PEDS(Ped PedIndex, uintptr_t array, int ExclusionPedType, int p3)
	{
		auto retval = PED::GET_PED_NEARBY_PEDS(PedIndex, (Any*)array, ExclusionPedType, p3);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_READY_TO_RENDER(Ped ped)
	{
		auto retval = (bool)PED::IS_PED_READY_TO_RENDER(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0x6A489892E813951A(Any p0)
	{
		PED::_0x6A489892E813951A(p0);
	}

	static bool LUA_NATIVE_PED_IS_PED_USING_ACTION_MODE(Ped PedIndex)
	{
		auto retval = (bool)PED::IS_PED_USING_ACTION_MODE(PedIndex);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_PED_USING_ACTION_MODE_2(Ped ped)
	{
		auto retval = (bool)PED::_IS_PED_USING_ACTION_MODE_2(ped);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_USING_ACTION_MODE(Ped PedIndex, bool UsingActionMode, int ActionModeTime, sol::stack_object ActionModeName)
	{
		PED::SET_PED_USING_ACTION_MODE(PedIndex, UsingActionMode, ActionModeTime, ActionModeName.is<const char*>() ? ActionModeName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED_SET_PED_CAPSULE(Ped PedIndex, float Radius)
	{
		PED::SET_PED_CAPSULE(PedIndex, Radius);
	}

	static Ped LUA_NATIVE_PED__GET_RIDER_OF_MOUNT(Ped mount, bool p1)
	{
		auto retval = PED::_GET_RIDER_OF_MOUNT(mount, p1);
		return retval;
	}

	static void LUA_NATIVE_PED_SPAWNPOINTS_START_SEARCH(float vSearchOriginX, float vSearchOriginY, float vSearchOriginZ, float fSearchRadius, float fMaxDistZ, int iFlags, float fMinimumSpacing, int iMaxSearchDurationMS, float p8)
	{
		PED::SPAWNPOINTS_START_SEARCH(vSearchOriginX, vSearchOriginY, vSearchOriginZ, fSearchRadius, fMaxDistZ, iFlags, fMinimumSpacing, iMaxSearchDurationMS, p8);
	}

	static void LUA_NATIVE_PED_SPAWNPOINTS_START_SEARCH_IN_ANGLED_AREA(float vPoint1X, float vPoint1Y, float vPoint1Z, float vPoint2X, float vPoint2Y, float vPoint2Z, float fWidth, int iFlags, float fMinimumSpacing, int iMaxSearchDurationMS, float p10)
	{
		PED::SPAWNPOINTS_START_SEARCH_IN_ANGLED_AREA(vPoint1X, vPoint1Y, vPoint1Z, vPoint2X, vPoint2Y, vPoint2Z, fWidth, iFlags, fMinimumSpacing, iMaxSearchDurationMS, p10);
	}

	static void LUA_NATIVE_PED__SPAWNPOINTS_START_SEARCH_WITH_VOLUME(Volume volume, int spawnpointsFlag, float p2, int duration, float p4)
	{
		PED::_SPAWNPOINTS_START_SEARCH_WITH_VOLUME(volume, spawnpointsFlag, p2, duration, p4);
	}

	static void LUA_NATIVE_PED_SPAWNPOINTS_CANCEL_SEARCH()
	{
		PED::SPAWNPOINTS_CANCEL_SEARCH();
	}

	static bool LUA_NATIVE_PED_SPAWNPOINTS_IS_SEARCH_ACTIVE()
	{
		auto retval = (bool)PED::SPAWNPOINTS_IS_SEARCH_ACTIVE();
		return retval;
	}

	static bool LUA_NATIVE_PED_SPAWNPOINTS_IS_SEARCH_COMPLETE()
	{
		auto retval = (bool)PED::SPAWNPOINTS_IS_SEARCH_COMPLETE();
		return retval;
	}

	static bool LUA_NATIVE_PED_SPAWNPOINTS_IS_SEARCH_FAILED()
	{
		auto retval = (bool)PED::SPAWNPOINTS_IS_SEARCH_FAILED();
		return retval;
	}

	static int LUA_NATIVE_PED_SPAWNPOINTS_GET_NUM_SEARCH_RESULTS()
	{
		auto retval = PED::SPAWNPOINTS_GET_NUM_SEARCH_RESULTS();
		return retval;
	}

	static std::tuple<float, float, float> LUA_NATIVE_PED_SPAWNPOINTS_GET_SEARCH_RESULT(int iResultIndex, float fOut_X, float fOut_Y, float fOut_Z)
	{
		std::tuple<float, float, float> return_values;
		PED::SPAWNPOINTS_GET_SEARCH_RESULT(iResultIndex, &fOut_X, &fOut_Y, &fOut_Z);
		std::get<0>(return_values) = fOut_X;
		std::get<1>(return_values) = fOut_Y;
		std::get<2>(return_values) = fOut_Z;

		return return_values;
	}

	static int LUA_NATIVE_PED_SPAWNPOINTS_GET_SEARCH_RESULT_FLAGS(int iResultIndex, int iOut_Flags)
	{
		PED::SPAWNPOINTS_GET_SEARCH_RESULT_FLAGS(iResultIndex, &iOut_Flags);
		return iOut_Flags;
	}

	static void LUA_NATIVE_PED_SET_IK_TARGET(Ped PedIndex, int IKPart, Entity TargetEntityIndex, int TargetBone, float TargetOffsetX, float TargetOffsetY, float TargetOffsetZ, int Flags, int BlendInTimeMS, int BlendOutTimeMS)
	{
		PED::SET_IK_TARGET(PedIndex, IKPart, TargetEntityIndex, TargetBone, TargetOffsetX, TargetOffsetY, TargetOffsetZ, Flags, BlendInTimeMS, BlendOutTimeMS);
	}

	static void LUA_NATIVE_PED__REQUEST_PED_EMOTIONAL_PRESET(Ped ped, sol::stack_object name)
	{
		PED::_REQUEST_PED_EMOTIONAL_PRESET(ped, name.is<const char*>() ? name.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_PED__HAS_PED_EMOTIONAL_PRESET_LOADED(Ped ped, sol::stack_object name)
	{
		auto retval = (bool)PED::_HAS_PED_EMOTIONAL_PRESET_LOADED(ped, name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_PED__REMOVE_PED_EMOTIONAL_PRESET(Ped ped, sol::stack_object name)
	{
		PED::_REMOVE_PED_EMOTIONAL_PRESET(ped, name.is<const char*>() ? name.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__REQUEST_MOTION_TYPE_ASSET(Hash nameHash, Ped ped)
	{
		PED::_REQUEST_MOTION_TYPE_ASSET(nameHash, ped);
	}

	static bool LUA_NATIVE_PED_HAS_MOTION_TYPE_ASSET_LOADED(Hash nameHash, Ped ped)
	{
		auto retval = (bool)PED::HAS_MOTION_TYPE_ASSET_LOADED(nameHash, ped);
		return retval;
	}

	static void LUA_NATIVE_PED__REMOVE_MOTION_TYPE_ASSET(Hash nameHash, Ped ped)
	{
		PED::_REMOVE_MOTION_TYPE_ASSET(nameHash, ped);
	}

	static bool LUA_NATIVE_PED__0x290B2E6CCDE532E1(Ped ped)
	{
		auto retval = (bool)PED::_0x290B2E6CCDE532E1(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x0EEF7A81C17679DB(Ped ped)
	{
		auto retval = (bool)PED::_0x0EEF7A81C17679DB(ped);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_LOD_MULTIPLIER(Ped PedIndex, float multiplier)
	{
		PED::SET_PED_LOD_MULTIPLIER(PedIndex, multiplier);
	}

	static float LUA_NATIVE_PED__GET_PED_LOD_MULTIPLIER(Ped ped)
	{
		auto retval = PED::_GET_PED_LOD_MULTIPLIER(ped);
		return retval;
	}

	static Any LUA_NATIVE_PED__0xA218D2BBCAA7388C(Any p0, Any p1)
	{
		auto retval = PED::_0xA218D2BBCAA7388C(p0, p1);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_ANY_HOSTILE_PED_NEAR_POINT(Ped iPedIndex, float pointX, float pointY, float pointZ, float radius)
	{
		auto retval = (bool)PED::IS_ANY_HOSTILE_PED_NEAR_POINT(iPedIndex, pointX, pointY, pointZ, radius);
		return retval;
	}

	static void LUA_NATIVE_PED__0xCBDE59C48F2B06F5(Any p0, Any p1, Any p2)
	{
		PED::_0xCBDE59C48F2B06F5(p0, p1, p2);
	}

	static void LUA_NATIVE_PED__0x6A190B94C2541A99(Any p0)
	{
		PED::_0x6A190B94C2541A99(p0);
	}

	static bool LUA_NATIVE_PED_IS_TARGET_PED_IN_PERCEPTION_AREA(Ped PedIndex, Ped TargetPedIndex, float fFocusAngle, float fFocusDistance, float fPeripheralAngle, float fPeripheralDistance)
	{
		auto retval = (bool)PED::IS_TARGET_PED_IN_PERCEPTION_AREA(PedIndex, TargetPedIndex, fFocusAngle, fFocusDistance, fPeripheralAngle, fPeripheralDistance);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_POP_CONTROL_SPHERE_THIS_FRAME(float centerX, float centerY, float centerZ, float pedRadius, float vehRadius)
	{
		PED::SET_POP_CONTROL_SPHERE_THIS_FRAME(centerX, centerY, centerZ, pedRadius, vehRadius);
	}

	static bool LUA_NATIVE_PED_IS_PED_HOGTIED(Ped ped)
	{
		auto retval = (bool)PED::IS_PED_HOGTIED(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_BEING_HOGTIED(Ped ped)
	{
		auto retval = (bool)PED::IS_PED_BEING_HOGTIED(ped);
		return retval;
	}

	static Ped LUA_NATIVE_PED__0x3D9F958834AB9C30(Ped ped)
	{
		auto retval = PED::_0x3D9F958834AB9C30(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x913D04A5176F84C9(Ped ped)
	{
		auto retval = (bool)PED::_0x913D04A5176F84C9(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_HOGTYING(Ped ped)
	{
		auto retval = (bool)PED::IS_PED_HOGTYING(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__GET_PED_LASSO_HOGTIE_FLAG(Ped ped, int flagId)
	{
		auto retval = (bool)PED::_GET_PED_LASSO_HOGTIE_FLAG(ped, flagId);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_LASSO_HOGTIE_FLAG(Ped ped, int flagId, bool value)
	{
		PED::SET_PED_LASSO_HOGTIE_FLAG(ped, flagId, value);
	}

	static int LUA_NATIVE_PED__0x4642182A298187D0(Ped ped, int p1, uintptr_t p2, int p3, int p4)
	{
		auto retval = PED::_0x4642182A298187D0(ped, p1, (Any*)p2, p3, p4);
		return retval;
	}

	static void LUA_NATIVE_PED__0x6B67320E0D57856A(Ped ped, uintptr_t p1, int p2, bool p3)
	{
		PED::_0x6B67320E0D57856A(ped, (Any*)p1, p2, p3);
	}

	static Entity LUA_NATIVE_PED__GET_FIRST_ENTITY_PED_IS_CARRYING(Ped ped)
	{
		auto retval = PED::_GET_FIRST_ENTITY_PED_IS_CARRYING(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0xAA6C49AE90A32299(Ped ped, Hash p1)
	{
		PED::_0xAA6C49AE90A32299(ped, p1);
	}

	static Ped LUA_NATIVE_PED__GET_CARRIER_AS_PED(Entity entity)
	{
		auto retval = PED::_GET_CARRIER_AS_PED(entity);
		return retval;
	}

	static Ped LUA_NATIVE_PED__GET_CARRIER_AS_MOUNT(Entity entity)
	{
		auto retval = PED::_GET_CARRIER_AS_MOUNT(entity);
		return retval;
	}

	static Ped LUA_NATIVE_PED__GET_CARRIER_AS_HUMAN(Entity entity)
	{
		auto retval = PED::_GET_CARRIER_AS_HUMAN(entity);
		return retval;
	}

	static Any LUA_NATIVE_PED_GET_CARRIED_ATTACHED_INFO_FOR_SLOT(Any p0, Any p1, Any p2, Any p3)
	{
		auto retval = PED::GET_CARRIED_ATTACHED_INFO_FOR_SLOT(p0, p1, p2, p3);
		return retval;
	}

	static void LUA_NATIVE_PED_DETACH_CARRIABLE_ENTITY(Entity entity, bool p1, bool p2)
	{
		PED::DETACH_CARRIABLE_ENTITY(entity, p1, p2);
	}

	static void LUA_NATIVE_PED_FIND_ALL_ATTACHED_CARRIABLE_ENTITIES(Ped ped, ItemSet itemset)
	{
		PED::FIND_ALL_ATTACHED_CARRIABLE_ENTITIES(ped, itemset);
	}

	static bool LUA_NATIVE_PED_IS_PED_CARRYING_SOMETHING(Ped ped)
	{
		auto retval = (bool)PED::IS_PED_CARRYING_SOMETHING(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__0xB65927F861E7AE39(Ped ped, int p1)
	{
		auto retval = (bool)PED::_0xB65927F861E7AE39(ped, p1);
		return retval;
	}

	static bool LUA_NATIVE_PED__0xA1FBAC56D38563E2(Volume volume)
	{
		auto retval = (bool)PED::_0xA1FBAC56D38563E2(volume);
		return retval;
	}

	static Any LUA_NATIVE_PED__0x6F43C351A5D51E2F(Ped ped, uintptr_t p1)
	{
		auto retval = PED::_0x6F43C351A5D51E2F(ped, (Any*)p1);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_LASSOED(Ped ped)
	{
		auto retval = (bool)PED::IS_PED_LASSOED(ped);
		return retval;
	}

	static Entity LUA_NATIVE_PED__GET_LASSOER_OF_PED(Ped ped)
	{
		auto retval = PED::_GET_LASSOER_OF_PED(ped);
		return retval;
	}

	static Entity LUA_NATIVE_PED__GET_LASSO_TARGET(Ped ped)
	{
		auto retval = PED::_GET_LASSO_TARGET(ped);
		return retval;
	}

	static Ped LUA_NATIVE_PED__GET_LASSOED_LASSOER(Ped ped)
	{
		auto retval = PED::_GET_LASSOED_LASSOER(ped);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_LOOTING_FLAG(Ped ped, int lootFlag, bool enabled)
	{
		PED::SET_LOOTING_FLAG(ped, lootFlag, enabled);
	}

	static bool LUA_NATIVE_PED__GET_LOOTING_FLAG(Ped ped, int lootFlag)
	{
		auto retval = (bool)PED::_GET_LOOTING_FLAG(ped, lootFlag);
		return retval;
	}

	static std::tuple<int, Ped> LUA_NATIVE_PED__REFRESH_LOOT_STATE_FOR_PED(Ped ped, int p1, Ped lootTarget, int p3, int p4)
	{
		std::tuple<int, Ped> return_values;
		std::get<0>(return_values) = PED::_REFRESH_LOOT_STATE_FOR_PED(ped, p1, &lootTarget, p3, p4);
		std::get<1>(return_values) = lootTarget;

		return return_values;
	}

	static int LUA_NATIVE_PED_GET_PED_LOOT_STATUS_MP(Ped ped)
	{
		auto retval = PED::GET_PED_LOOT_STATUS_MP(ped);
		return retval;
	}

	static Ped LUA_NATIVE_PED__0x4B19F171450E0D4F(Ped ped)
	{
		auto retval = PED::_0x4B19F171450E0D4F(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x758F081DB204DDDE(Ped ped)
	{
		auto retval = (bool)PED::_0x758F081DB204DDDE(ped);
		return retval;
	}

	static Entity LUA_NATIVE_PED_GET_LOOTING_PICKUP_TARGET_ENTITY(Ped ped)
	{
		auto retval = PED::GET_LOOTING_PICKUP_TARGET_ENTITY(ped);
		return retval;
	}

	static Any LUA_NATIVE_PED__0x7B5C293238EE4F20(Any p0)
	{
		auto retval = PED::_0x7B5C293238EE4F20(p0);
		return retval;
	}

	static void LUA_NATIVE_PED__0xAE6B68A83ABBE7C0(Any p0)
	{
		PED::_0xAE6B68A83ABBE7C0(p0);
	}

	static bool LUA_NATIVE_PED__0xA4B6432E3880F2F9(Ped ped)
	{
		auto retval = (bool)PED::_0xA4B6432E3880F2F9(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__ADD_PED_SUBSCRIBE_TO_LEGENDARY_BLIPS(Ped ped)
	{
		auto retval = (bool)PED::_ADD_PED_SUBSCRIBE_TO_LEGENDARY_BLIPS(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__REMOVE_PED_SUBSCRIBE_TO_LEGENDARY_BLIPS(Ped ped)
	{
		auto retval = (bool)PED::_REMOVE_PED_SUBSCRIBE_TO_LEGENDARY_BLIPS(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_INCAPACITATED(Ped ped)
	{
		auto retval = (bool)PED::IS_PED_INCAPACITATED(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_INCAPACITATION_MODIFIERS(Ped ped, bool canBeIncapacitated, int threshold, int bleedoutTime, int p4)
	{
		PED::_SET_PED_INCAPACITATION_MODIFIERS(ped, canBeIncapacitated, threshold, bleedoutTime, p4);
	}

	static bool LUA_NATIVE_PED__GET_PED_CAN_BE_INCAPACITATED_THIS_FRAME(Ped ped)
	{
		auto retval = (bool)PED::_GET_PED_CAN_BE_INCAPACITATED_THIS_FRAME(ped);
		return retval;
	}

	static void LUA_NATIVE_PED_SET_PED_CAN_BE_INCAPACITATED(Ped ped, bool toggle)
	{
		PED::SET_PED_CAN_BE_INCAPACITATED(ped, toggle);
	}

	static int LUA_NATIVE_PED__GET_PED_INCAPACITATION_HEALTH(Ped ped)
	{
		auto retval = PED::_GET_PED_INCAPACITATION_HEALTH(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_INCAPACITATION_TOTAL_BLEED_OUT_DURATION(Ped ped, float duration)
	{
		PED::_SET_PED_INCAPACITATION_TOTAL_BLEED_OUT_DURATION(ped, duration);
	}

	static void LUA_NATIVE_PED__RESET_PED_INCAPACITATION_BLEED_OUT_DURATION(Ped ped)
	{
		PED::_RESET_PED_INCAPACITATION_BLEED_OUT_DURATION(ped);
	}

	static void LUA_NATIVE_PED__SET_PED_INCAPACITATION_FLAGS(Ped ped, int flags)
	{
		PED::_SET_PED_INCAPACITATION_FLAGS(ped, flags);
	}

	static void LUA_NATIVE_PED__0x92A1B55A59720395(Any p0, Any p1)
	{
		PED::_0x92A1B55A59720395(p0, p1);
	}

	static void LUA_NATIVE_PED__INCAPACITATED_REVIVE(Ped ped, Ped ped2)
	{
		PED::_INCAPACITATED_REVIVE(ped, ped2);
	}

	static int LUA_NATIVE_PED__GET_INCAPACITATION_TIME_REMAINING(Ped ped)
	{
		auto retval = PED::_GET_INCAPACITATION_TIME_REMAINING(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_KNOCKED_BY_ONE_HIT(Ped ped, float p1)
	{
		PED::_SET_PED_KNOCKED_BY_ONE_HIT(ped, p1);
	}

	static void LUA_NATIVE_PED__0x2E5B5D1F1453E08E(Ped ped, int p1)
	{
		PED::_0x2E5B5D1F1453E08E(ped, p1);
	}

	static void LUA_NATIVE_PED__0x29924EB8EE9DB926(Ped ped, float p1)
	{
		PED::_0x29924EB8EE9DB926(ped, p1);
	}

	static void LUA_NATIVE_PED__SET_PED_ACTIVE_PLAYER_TYPE(Ped ped, Hash playerType)
	{
		PED::_SET_PED_ACTIVE_PLAYER_TYPE(ped, playerType);
	}

	static Any LUA_NATIVE_PED__0xCB86D3E3E3708901(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		auto retval = PED::_0xCB86D3E3E3708901(p0, p1, p2, p3, p4);
		return retval;
	}

	static void LUA_NATIVE_PED__0x633F83B301C87994(Any p0, Any p1)
	{
		PED::_0x633F83B301C87994(p0, p1);
	}

	static bool LUA_NATIVE_PED__0x5203038FF8BAE577(Ped ped, int p1, int p2)
	{
		auto retval = (bool)PED::_0x5203038FF8BAE577(ped, p1, p2);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x7F090958AE95B61B(Ped ped, int p1)
	{
		auto retval = (bool)PED::_0x7F090958AE95B61B(ped, p1);
		return retval;
	}

	static void LUA_NATIVE_PED__0xC494C76A34266E82(Ped ped, int p1)
	{
		PED::_0xC494C76A34266E82(ped, p1);
	}

	static bool LUA_NATIVE_PED__0xC3995D396F1D97B6(Ped ped, int p1, int p2)
	{
		auto retval = (bool)PED::_0xC3995D396F1D97B6(ped, p1, p2);
		return retval;
	}

	static void LUA_NATIVE_PED__0x15F4732C357B1D6D(Any p0, Any p1, Any p2)
	{
		PED::_0x15F4732C357B1D6D(p0, p1, p2);
	}

	static bool LUA_NATIVE_PED__0x947E43F544B6AB34(Ped ped, Player player, int flag, int ms)
	{
		auto retval = (bool)PED::_0x947E43F544B6AB34(ped, player, flag, ms);
		return retval;
	}

	static Any LUA_NATIVE_PED__0x32417CB860A3BDC4(Any p0, Any p1)
	{
		auto retval = PED::_0x32417CB860A3BDC4(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_PED__0xE737D5F14304A2EC(Ped ped, Player player, int p2)
	{
		PED::_0xE737D5F14304A2EC(ped, player, p2);
	}

	static void LUA_NATIVE_PED__0xEBD49472BCCF7642(Any p0, Any p1)
	{
		PED::_0xEBD49472BCCF7642(p0, p1);
	}

	static void LUA_NATIVE_PED__SET_PLAYER_GREET_DISABLED_FOR_PED(Ped ped, Player player, int duration)
	{
		PED::_SET_PLAYER_GREET_DISABLED_FOR_PED(ped, player, duration);
	}

	static void LUA_NATIVE_PED__SET_PLAYER_ANTAGONIZE_DISABLED_FOR_PED(Ped ped, Player player, int duration)
	{
		PED::_SET_PLAYER_ANTAGONIZE_DISABLED_FOR_PED(ped, player, duration);
	}

	static void LUA_NATIVE_PED__0xB9BDFAE609DFB7C5(Any p0, Any p1, Any p2)
	{
		PED::_0xB9BDFAE609DFB7C5(p0, p1, p2);
	}

	static Any LUA_NATIVE_PED__0xF7327ACC7A89AEF1(Any p0, Any p1, Any p2)
	{
		auto retval = PED::_0xF7327ACC7A89AEF1(p0, p1, p2);
		return retval;
	}

	static int LUA_NATIVE_PED__GET_PED_ATTITUDE(Ped ped, Player player)
	{
		auto retval = PED::_GET_PED_ATTITUDE(ped, player);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x1E017404784AA6A3(Ped ped, Hash p1)
	{
		auto retval = (bool)PED::_0x1E017404784AA6A3(ped, p1);
		return retval;
	}

	static void LUA_NATIVE_PED__0x2B4CE170DE09F346(Ped ped, Hash p1)
	{
		PED::_0x2B4CE170DE09F346(ped, p1);
	}

	static Any LUA_NATIVE_PED__0x7C8AA850617651D9(Any p0, Any p1)
	{
		auto retval = PED::_0x7C8AA850617651D9(p0, p1);
		return retval;
	}

	static float LUA_NATIVE_PED__GET_PED_MOTIVATION(Ped ped, int motivationState, Ped targetPed)
	{
		auto retval = PED::_GET_PED_MOTIVATION(ped, motivationState, targetPed);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_MOTIVATION(Ped ped, int motivationState, float threshold, Ped targetPed)
	{
		PED::_SET_PED_MOTIVATION(ped, motivationState, threshold, targetPed);
	}

	static void LUA_NATIVE_PED__0x23BDE06596A22CEC(Ped ped, int p1, float p2, Any p3)
	{
		PED::_0x23BDE06596A22CEC(ped, p1, p2, p3);
	}

	static void LUA_NATIVE_PED__0xCDFB8C04D4C95D9B(Any p0, Any p1, Any p2, Any p3)
	{
		PED::_0xCDFB8C04D4C95D9B(p0, p1, p2, p3);
	}

	static bool LUA_NATIVE_PED__GET_IS_PED_MOTIVATION_STATE_ENABLED(Ped ped, int motivationState)
	{
		auto retval = (bool)PED::_GET_IS_PED_MOTIVATION_STATE_ENABLED(ped, motivationState);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_MOTIVATION_STATE_OVERRIDE(Ped ped, int motivationState, bool enabled)
	{
		PED::_SET_PED_MOTIVATION_STATE_OVERRIDE(ped, motivationState, enabled);
	}

	static void LUA_NATIVE_PED__SET_PED_MOTIVATION_MODIFIER(Ped ped, int motivationState, float modifier)
	{
		PED::_SET_PED_MOTIVATION_MODIFIER(ped, motivationState, modifier);
	}

	static void LUA_NATIVE_PED__0xFD8E853F0BC2E942(Any p0, Any p1)
	{
		PED::_0xFD8E853F0BC2E942(p0, p1);
	}

	static void LUA_NATIVE_PED__SET_PED_SCENT(Ped ped, float scent)
	{
		PED::_SET_PED_SCENT(ped, scent);
	}

	static void LUA_NATIVE_PED__SET_PED_LADDER_MOVEMENT_SPEED_MODIFIER(Ped ped, float p1)
	{
		PED::_SET_PED_LADDER_MOVEMENT_SPEED_MODIFIER(ped, p1);
	}

	static void LUA_NATIVE_PED__RESET_PED_LADDER_MOVEMENT_SPEED_MODIFIER(Ped ped)
	{
		PED::_RESET_PED_LADDER_MOVEMENT_SPEED_MODIFIER(ped);
	}

	static void LUA_NATIVE_PED__0xC6C4E15CF7D52FEA(Any p0, Any p1)
	{
		PED::_0xC6C4E15CF7D52FEA(p0, p1);
	}

	static void LUA_NATIVE_PED__SET_PED_VOICE_VOLUME(Ped ped, float volume)
	{
		PED::_SET_PED_VOICE_VOLUME(ped, volume);
	}

	static void LUA_NATIVE_PED__0x0F967019CC853BCC(Any p0, Any p1)
	{
		PED::_0x0F967019CC853BCC(p0, p1);
	}

	static bool LUA_NATIVE_PED__IS_PED_DRAGGING(Ped ped)
	{
		auto retval = (bool)PED::_IS_PED_DRAGGING(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED_IS_PED_BEING_DRAGGED(Ped ped)
	{
		auto retval = (bool)PED::IS_PED_BEING_DRAGGED(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0x070A3841406C43D5(Any p0, Any p1)
	{
		PED::_0x070A3841406C43D5(p0, p1);
	}

	static bool LUA_NATIVE_PED__ADD_PED_STAY_OUT_VOLUME(Ped ped, Volume volume)
	{
		auto retval = (bool)PED::_ADD_PED_STAY_OUT_VOLUME(ped, volume);
		return retval;
	}

	static bool LUA_NATIVE_PED__REMOVE_PED_STAY_OUT_VOLUME(Ped ped, Volume volume)
	{
		auto retval = (bool)PED::_REMOVE_PED_STAY_OUT_VOLUME(ped, volume);
		return retval;
	}

	static void LUA_NATIVE_PED__0x9E66708B2B41F14A(Any p0, Any p1)
	{
		PED::_0x9E66708B2B41F14A(p0, p1);
	}

	static void LUA_NATIVE_PED__0xF634E2892220EF34(Ped ped, Any p1)
	{
		PED::_0xF634E2892220EF34(ped, p1);
	}

	static void LUA_NATIVE_PED__0xAAC0EE3B4999ABB5(Ped ped, Ped targetPed)
	{
		PED::_0xAAC0EE3B4999ABB5(ped, targetPed);
	}

	static Entity LUA_NATIVE_PED_GET_PED_MOTION_FOCUS_ENTITY(Ped ped)
	{
		auto retval = PED::GET_PED_MOTION_FOCUS_ENTITY(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_CHAR_EXPRESSION(Ped ped, int index, float value)
	{
		PED::_SET_CHAR_EXPRESSION(ped, index, value);
	}

	static float LUA_NATIVE_PED__GET_CHAR_EXPRESSION(Ped ped, int index)
	{
		auto retval = PED::_GET_CHAR_EXPRESSION(ped, index);
		return retval;
	}

	static void LUA_NATIVE_PED__0x5BB04BC74A474B47(Any p0, Any p1)
	{
		PED::_0x5BB04BC74A474B47(p0, p1);
	}

	static void LUA_NATIVE_PED__0x9078FB0557364099(Any p0)
	{
		PED::_0x9078FB0557364099(p0);
	}

	static bool LUA_NATIVE_PED_IS_PED_FALLING_OVER(Ped ped)
	{
		auto retval = (bool)PED::IS_PED_FALLING_OVER(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__HAS_PED_BEEN_SHOVED_RECENTLY(Ped ped, int ms)
	{
		auto retval = (bool)PED::_HAS_PED_BEEN_SHOVED_RECENTLY(ped, ms);
		return retval;
	}

	static Ped LUA_NATIVE_PED__GET_PED_TRANQUILIZER(Ped ped)
	{
		auto retval = PED::_GET_PED_TRANQUILIZER(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0x0D497AA69059FE40(Any p0, Any p1)
	{
		PED::_0x0D497AA69059FE40(p0, p1);
	}

	static void LUA_NATIVE_PED__0xD7D2F45C56A4F4DF(Any p0, Any p1, Any p2)
	{
		PED::_0xD7D2F45C56A4F4DF(p0, p1, p2);
	}

	static void LUA_NATIVE_PED__SET_PED_CULL_RANGE(Ped ped, float p1, float p2)
	{
		PED::_SET_PED_CULL_RANGE(ped, p1, p2);
	}

	static void LUA_NATIVE_PED__0x1D23D3F70606D788(Any p0, Any p1)
	{
		PED::_0x1D23D3F70606D788(p0, p1);
	}

	static int LUA_NATIVE_PED__GET_META_PED_TYPE(Ped ped)
	{
		auto retval = PED::_GET_META_PED_TYPE(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_META_PED_USING_COMPONENT(Ped ped, Hash component)
	{
		auto retval = (bool)PED::_IS_META_PED_USING_COMPONENT(ped, component);
		return retval;
	}

	static bool LUA_NATIVE_PED__0xBD0E4F52F6D95242(Ped ped)
	{
		auto retval = (bool)PED::_0xBD0E4F52F6D95242(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_PED_CHILD(Ped ped)
	{
		auto retval = (bool)PED::_IS_PED_CHILD(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0xFFA1594703ED27CA(Ped ped, int p1)
	{
		PED::_0xFFA1594703ED27CA(ped, p1);
	}

	static void LUA_NATIVE_PED__SET_META_PED_TAG(Ped ped, Hash drawable, Hash albedo, Hash normal, Hash material, Hash palette, int tint0, int tint1, int tint2)
	{
		PED::_SET_META_PED_TAG(ped, drawable, albedo, normal, material, palette, tint0, tint1, tint2);
	}

	static void LUA_NATIVE_PED_REMOVE_TAG_FROM_META_PED(Ped ped, Hash component, int p2)
	{
		PED::REMOVE_TAG_FROM_META_PED(ped, component, p2);
	}

	static void LUA_NATIVE_PED__0xA2B8E47442C76CEC(Any p0, Any p1)
	{
		PED::_0xA2B8E47442C76CEC(p0, p1);
	}

	static int LUA_NATIVE_PED__GET_NUM_COMPONENT_CATEGORIES_IN_PED(Ped ped)
	{
		auto retval = PED::_GET_NUM_COMPONENT_CATEGORIES_IN_PED(ped);
		return retval;
	}

	static Hash LUA_NATIVE_PED__GET_PED_COMPONENT_CATEGORY_BY_INDEX(Ped ped, int index)
	{
		auto retval = PED::_GET_PED_COMPONENT_CATEGORY_BY_INDEX(ped, index);
		return retval;
	}

	static int LUA_NATIVE_PED__GET_NUM_COMPONENTS_IN_PED(Ped ped)
	{
		auto retval = PED::_GET_NUM_COMPONENTS_IN_PED(ped);
		return retval;
	}

	static Any LUA_NATIVE_PED__0x9B90842304C938A7(Any p0, Any p1, Any p2)
	{
		auto retval = PED::_0x9B90842304C938A7(p0, p1, p2);
		return retval;
	}

	static void LUA_NATIVE_PED__UPDATE_PED_VARIATION(Ped ped, bool p1, bool p2, bool p3, bool p4, bool p5)
	{
		PED::_UPDATE_PED_VARIATION(ped, p1, p2, p3, p4, p5);
	}

	static void LUA_NATIVE_PED__0xCB1A3864C524F784(Any p0, Any p1)
	{
		PED::_0xCB1A3864C524F784(p0, p1);
	}

	static void LUA_NATIVE_PED__0xFA0D206B489A6846(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		PED::_0xFA0D206B489A6846(p0, p1, p2, p3, p4);
	}

	static Any LUA_NATIVE_PED__0xA4AC05B1A364EBC5(Any p0, Any p1, Any p2)
	{
		auto retval = PED::_0xA4AC05B1A364EBC5(p0, p1, p2);
		return retval;
	}

	static void LUA_NATIVE_PED__0x1298B3D8E4C2409F(Any p0)
	{
		PED::_0x1298B3D8E4C2409F(p0);
	}

	static Any LUA_NATIVE_PED__0xA274F51EF7E34B95(Any p0, Any p1)
	{
		auto retval = PED::_0xA274F51EF7E34B95(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_PED__0xC2EF407645BEECDC(Any p0)
	{
		auto retval = PED::_0xC2EF407645BEECDC(p0);
		return retval;
	}

	static void LUA_NATIVE_PED__EQUIP_META_PED_OUTFIT(Ped ped, Hash hash)
	{
		PED::_EQUIP_META_PED_OUTFIT(ped, hash);
	}

	static void LUA_NATIVE_PED__0xFA742B82D093D848(Any p0, Any p1, Any p2)
	{
		PED::_0xFA742B82D093D848(p0, p1, p2);
	}

	static Hash LUA_NATIVE_PED__GET_PED_META_OUTFIT_HASH(Ped ped)
	{
		auto retval = PED::_GET_PED_META_OUTFIT_HASH(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0xA2F8B3B5FEDFC100(Any p0, Any p1)
	{
		PED::_0xA2F8B3B5FEDFC100(p0, p1);
	}

	static void LUA_NATIVE_PED__EQUIP_META_PED_SUBOUTFIT(Ped ped, Hash suboutfit, int p2)
	{
		PED::_EQUIP_META_PED_SUBOUTFIT(ped, suboutfit, p2);
	}

	static bool LUA_NATIVE_PED__DOES_META_PED_OUTFIT_EXIST_FOR_PED_MODEL(Hash outfit, Hash model)
	{
		auto retval = (bool)PED::_DOES_META_PED_OUTFIT_EXIST_FOR_PED_MODEL(outfit, model);
		return retval;
	}

	static bool LUA_NATIVE_PED__DOES_META_PED_SUBOUTFIT_EXIST_FOR_PED_MODEL(Hash outfit, Hash suboutfit, Hash model)
	{
		auto retval = (bool)PED::_DOES_META_PED_SUBOUTFIT_EXIST_FOR_PED_MODEL(outfit, suboutfit, model);
		return retval;
	}

	static Any LUA_NATIVE_PED__0x62FDF4E678E40CC6(Entity entity, Any p1)
	{
		auto retval = PED::_0x62FDF4E678E40CC6(entity, p1);
		return retval;
	}

	static void LUA_NATIVE_PED__RESET_PED_COMPONENTS(Ped ped)
	{
		PED::_RESET_PED_COMPONENTS(ped);
	}

	static void LUA_NATIVE_PED__0x370A973252741AC4(Ped ped, bool p1)
	{
		PED::_0x370A973252741AC4(ped, p1);
	}

	static void LUA_NATIVE_PED__SET_RANDOM_OUTFIT_VARIATION(Ped ped, bool p1)
	{
		PED::_SET_RANDOM_OUTFIT_VARIATION(ped, p1);
	}

	static int LUA_NATIVE_PED_GET_NUM_META_PED_OUTFITS(Ped ped)
	{
		auto retval = PED::GET_NUM_META_PED_OUTFITS(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__EQUIP_META_PED_OUTFIT_PRESET(Ped ped, int presetId, bool p2)
	{
		PED::_EQUIP_META_PED_OUTFIT_PRESET(ped, presetId, p2);
	}

	static void LUA_NATIVE_PED__EQUIP_META_PED_OUTFIT_EXTRA(Ped ped, int component, Any p2, Any p3)
	{
		PED::_EQUIP_META_PED_OUTFIT_EXTRA(ped, component, p2, p3);
	}

	static bool LUA_NATIVE_PED__IS_META_PED_OUTFIT_EQUIPPED(Ped ped, Hash outfit)
	{
		auto retval = (bool)PED::_IS_META_PED_OUTFIT_EQUIPPED(ped, outfit);
		return retval;
	}

	static void LUA_NATIVE_PED__0x851966E1E35AF491(Any p0, Any p1)
	{
		PED::_0x851966E1E35AF491(p0, p1);
	}

	static void LUA_NATIVE_PED__SET_TEXTURE_OUTFIT_TINTS(Ped ped, Hash componentCategory, Hash palette, int tint0, int tint1, int tint2)
	{
		PED::_SET_TEXTURE_OUTFIT_TINTS(ped, componentCategory, palette, tint0, tint1, tint2);
	}

	static int LUA_NATIVE_PED__REQUEST_META_PED(Hash model, int p1)
	{
		auto retval = PED::_REQUEST_META_PED(model, p1);
		return retval;
	}

	static bool LUA_NATIVE_PED__HAS_META_PED_REQUEST_LOADED(int requestId)
	{
		auto retval = (bool)PED::_HAS_META_PED_REQUEST_LOADED(requestId);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_META_PED_REQUEST_VALID(int requestId)
	{
		auto retval = (bool)PED::_IS_META_PED_REQUEST_VALID(requestId);
		return retval;
	}

	static Ped LUA_NATIVE_PED__CREATE_META_PED(int requestId, float x, float y, float z, float heading, bool p5, bool p6, bool p7, bool p8, bool p9)
	{
		auto retval = PED::_CREATE_META_PED(requestId, x, y, z, heading, p5, p6, p7, p8, p9);
		return retval;
	}

	static void LUA_NATIVE_PED__RELEASE_META_PED_REQUEST(int requestId)
	{
		PED::_RELEASE_META_PED_REQUEST(requestId);
	}

	static int LUA_NATIVE_PED__REQUEST_META_PED_OUTFIT(Hash model, Hash outfit)
	{
		auto retval = PED::_REQUEST_META_PED_OUTFIT(model, outfit);
		return retval;
	}

	static Any LUA_NATIVE_PED__0x27E8A84C12B0B7D1(Any p0, Any p1, Any p2)
	{
		auto retval = PED::_0x27E8A84C12B0B7D1(p0, p1, p2);
		return retval;
	}

	static Any LUA_NATIVE_PED__0x273915CE30780986(Any p0, Any p1)
	{
		auto retval = PED::_0x273915CE30780986(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_PED__RELEASE_META_PED_OUTFIT_REQUEST(int requestId)
	{
		PED::_RELEASE_META_PED_OUTFIT_REQUEST(requestId);
	}

	static int LUA_NATIVE_PED__0x3FCBB5FCFD968698(Hash drawable, Hash albedo, Hash normal, Hash material, Any p4)
	{
		auto retval = PED::_0x3FCBB5FCFD968698(drawable, albedo, normal, material, p4);
		return retval;
	}

	static int LUA_NATIVE_PED__REQUEST_META_PED_ASSET_BUNDLE(Hash asset, int p1)
	{
		auto retval = PED::_REQUEST_META_PED_ASSET_BUNDLE(asset, p1);
		return retval;
	}

	static Any LUA_NATIVE_PED__REQUEST_META_PED_COMPONENT(int metaPedType, Any p1, int p2, int p3, int p4)
	{
		auto retval = PED::_REQUEST_META_PED_COMPONENT(metaPedType, p1, p2, p3, p4);
		return retval;
	}

	static void LUA_NATIVE_PED__RELEASE_META_PED_ASSET_REQUEST(int requestId)
	{
		PED::_RELEASE_META_PED_ASSET_REQUEST(requestId);
	}

	static bool LUA_NATIVE_PED__HAS_META_PED_ASSET_LOADED(int requestId)
	{
		auto retval = (bool)PED::_HAS_META_PED_ASSET_LOADED(requestId);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_META_PED_ASSET_VALID(int requestId)
	{
		auto retval = (bool)PED::_IS_META_PED_ASSET_VALID(requestId);
		return retval;
	}

	static Entity LUA_NATIVE_PED__CREATE_META_PED_ASSET(Hash asset, float posX, float posY, float posZ, float rotX, float rotY, float rotZ, bool p7, bool p8, bool p9)
	{
		auto retval = PED::_CREATE_META_PED_ASSET(asset, posX, posY, posZ, rotX, rotY, rotZ, p7, p8, p9);
		return retval;
	}

	static bool LUA_NATIVE_PED__HAS_META_PED_OUTFIT_LOADED(int requestId)
	{
		auto retval = (bool)PED::_HAS_META_PED_OUTFIT_LOADED(requestId);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_META_PED_OUTFIT_REQUEST_VALID(int requestId)
	{
		auto retval = (bool)PED::_IS_META_PED_OUTFIT_REQUEST_VALID(requestId);
		return retval;
	}

	static Ped LUA_NATIVE_PED__CREATE_META_PED_OUTFIT_PED(int requestId, float x, float y, float z, float heading, bool p5, bool p6, bool p7, bool p8)
	{
		auto retval = PED::_CREATE_META_PED_OUTFIT_PED(requestId, x, y, z, heading, p5, p6, p7, p8);
		return retval;
	}

	static bool LUA_NATIVE_PED__APPLY_PED_META_PED_OUTFIT(int requestId, Ped ped, bool p2, bool p3)
	{
		auto retval = (bool)PED::_APPLY_PED_META_PED_OUTFIT(requestId, ped, p2, p3);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_META_PED_WEARINESS(Ped ped, float weariness)
	{
		PED::_SET_META_PED_WEARINESS(ped, weariness);
	}

	static void LUA_NATIVE_PED__0xF47D54B986F0A346(Ped ped, int danceIntensity)
	{
		PED::_0xF47D54B986F0A346(ped, danceIntensity);
	}

	static void LUA_NATIVE_PED__0x3EFED081B4834BA1(Any p0)
	{
		PED::_0x3EFED081B4834BA1(p0);
	}

	static void LUA_NATIVE_PED__0x0FB1BA7FF73B41E1(Any p0, Any p1, Any p2)
	{
		PED::_0x0FB1BA7FF73B41E1(p0, p1, p2);
	}

	static Any LUA_NATIVE_PED__0xB292203008EBBAAC(Any p0)
	{
		auto retval = PED::_0xB292203008EBBAAC(p0);
		return retval;
	}

	static bool LUA_NATIVE_PED__0xD4D403EA031F351C(Ped ped)
	{
		auto retval = (bool)PED::_0xD4D403EA031F351C(ped);
		return retval;
	}

	static int LUA_NATIVE_PED__GET_PELT_FROM_HORSE(Ped horse, int index)
	{
		auto retval = PED::_GET_PELT_FROM_HORSE(horse, index);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PELT_FOR_HORSE(Ped horse, int peltId)
	{
		PED::_SET_PELT_FOR_HORSE(horse, peltId);
	}

	static void LUA_NATIVE_PED__0xC412AA1C73111FE0(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		PED::_0xC412AA1C73111FE0(p0, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_PED__CLEAR_PELT_FROM_HORSE(Ped horse, int peltId)
	{
		PED::_CLEAR_PELT_FROM_HORSE(horse, peltId);
	}

	static void LUA_NATIVE_PED__SET_PED_LIGHTS(Ped ped, bool toggle)
	{
		PED::_SET_PED_LIGHTS(ped, toggle);
	}

	static void LUA_NATIVE_PED__0xD049FDAF089FDDB0(Ped ped, Hash p1, float p2)
	{
		PED::_0xD049FDAF089FDDB0(ped, p1, p2);
	}

	static void LUA_NATIVE_PED__0xDD9540E7B1C9714F(Ped ped, Hash p1, float r, float g, float b)
	{
		PED::_0xDD9540E7B1C9714F(ped, p1, r, g, b);
	}

	static void LUA_NATIVE_PED__0x55546004A244302A(Any p0, Any p1)
	{
		PED::_0x55546004A244302A(p0, p1);
	}

	static void LUA_NATIVE_PED__SET_HEALTH_RECHARGE_MULTIPLIER(Ped ped, int multiplier)
	{
		PED::_SET_HEALTH_RECHARGE_MULTIPLIER(ped, multiplier);
	}

	static float LUA_NATIVE_PED__GET_HEALTH_RECHARGE_MULTIPLIER(Ped ped)
	{
		auto retval = PED::_GET_HEALTH_RECHARGE_MULTIPLIER(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_STAMINA_DEPLETION_MULTIPLIER(Ped ped, int multiplier)
	{
		PED::_SET_STAMINA_DEPLETION_MULTIPLIER(ped, multiplier);
	}

	static float LUA_NATIVE_PED__GET_STAMINA_DEPLETION_MULTIPLIER(Ped ped)
	{
		auto retval = PED::_GET_STAMINA_DEPLETION_MULTIPLIER(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_STAMINA_RECHARGE_MULTIPLIER(Ped ped, int multiplier)
	{
		PED::_SET_STAMINA_RECHARGE_MULTIPLIER(ped, multiplier);
	}

	static float LUA_NATIVE_PED__GET_STAMINA_RECHARGE_MULTIPLIER(Ped ped)
	{
		auto retval = PED::_GET_STAMINA_RECHARGE_MULTIPLIER(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__CHANGE_PED_STAMINA(Ped ped, float amount)
	{
		auto retval = (bool)PED::_CHANGE_PED_STAMINA(ped, amount);
		return retval;
	}

	static float LUA_NATIVE_PED__GET_PED_STAMINA(Ped ped)
	{
		auto retval = PED::_GET_PED_STAMINA(ped);
		return retval;
	}

	static float LUA_NATIVE_PED__GET_PED_STAMINA_NORMALIZED(Ped ped)
	{
		auto retval = PED::_GET_PED_STAMINA_NORMALIZED(ped);
		return retval;
	}

	static float LUA_NATIVE_PED__GET_PED_MAX_STAMINA(Ped ped)
	{
		auto retval = PED::_GET_PED_MAX_STAMINA(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0x36513AFFC703C60D(Any p0)
	{
		PED::_0x36513AFFC703C60D(p0);
	}

	static void LUA_NATIVE_PED__RESTORE_PED_STAMINA(Ped ped, float stamina)
	{
		PED::_RESTORE_PED_STAMINA(ped, stamina);
	}

	static int LUA_NATIVE_PED__0xFC3B580C4380B5B7(Ped ped)
	{
		auto retval = PED::_0xFC3B580C4380B5B7(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0xEA8763E505AFD49A(Any p0, Any p1, Any p2)
	{
		PED::_0xEA8763E505AFD49A(p0, p1, p2);
	}

	static void LUA_NATIVE_PED__0xE4EF4382E22C780C(Any p0)
	{
		PED::_0xE4EF4382E22C780C(p0);
	}

	static void LUA_NATIVE_PED__0xD61FCF9FCFD515B7(Any p0, Any p1, Any p2)
	{
		PED::_0xD61FCF9FCFD515B7(p0, p1, p2);
	}

	static void LUA_NATIVE_PED__0x8D9DB115FBA8E23D(Any p0)
	{
		PED::_0x8D9DB115FBA8E23D(p0);
	}

	static Any LUA_NATIVE_PED__GET_NUM_RESERVED_HEALTH(Ped ped)
	{
		auto retval = PED::_GET_NUM_RESERVED_HEALTH(ped);
		return retval;
	}

	static Any LUA_NATIVE_PED__0xD97BC27AC039F681(Any p0, Any p1, Any p2, Any p3)
	{
		auto retval = PED::_0xD97BC27AC039F681(p0, p1, p2, p3);
		return retval;
	}

	static Any LUA_NATIVE_PED__0xF6A8C4B4A11AE89C(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5)
	{
		auto retval = PED::_0xF6A8C4B4A11AE89C(p0, p1, p2, p3, p4, p5);
		return retval;
	}

	static void LUA_NATIVE_PED__0xE4C95E0AE31C6512(Ped ped, Any p1)
	{
		PED::_0xE4C95E0AE31C6512(ped, p1);
	}

	static Object LUA_NATIVE_PED__GET_PED_LAST_DROPPED_HAT(Ped ped)
	{
		auto retval = PED::_GET_PED_LAST_DROPPED_HAT(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0x5D4CD22A8C82A81A(Ped ped, bool p1)
	{
		PED::_0x5D4CD22A8C82A81A(ped, p1);
	}

	static void LUA_NATIVE_PED__0xBF567DF2BEF211A6(Any p0, Any p1)
	{
		PED::_0xBF567DF2BEF211A6(p0, p1);
	}

	static int LUA_NATIVE_PED__CREATE_GRAVITY_WELL(float xPos, float yPos, float zPos, float heading, float radius, float p5, float p6, float p7, bool stopAtDestination)
	{
		auto retval = PED::_CREATE_GRAVITY_WELL(xPos, yPos, zPos, heading, radius, p5, p6, p7, stopAtDestination);
		return retval;
	}

	static void LUA_NATIVE_PED__REMOVE_GRAVITY_WELL(int handle)
	{
		PED::_REMOVE_GRAVITY_WELL(handle);
	}

	static bool LUA_NATIVE_PED__IS_PED_INTIMIDATED(Ped ped)
	{
		auto retval = (bool)PED::_IS_PED_INTIMIDATED(ped);
		return retval;
	}

	static bool LUA_NATIVE_PED__0x7EE3A8660F38797E(Ped ped)
	{
		auto retval = (bool)PED::_0x7EE3A8660F38797E(ped);
		return retval;
	}

	static Any LUA_NATIVE_PED__0xA180FBD502A03125(Any p0, Any p1, Any p2)
	{
		auto retval = PED::_0xA180FBD502A03125(p0, p1, p2);
		return retval;
	}

	static int LUA_NATIVE_PED__REQUEST_TEXTURE(Hash albedoHash, Hash normalHash, Hash materialHash)
	{
		auto retval = PED::_REQUEST_TEXTURE(albedoHash, normalHash, materialHash);
		return retval;
	}

	static void LUA_NATIVE_PED__APPLY_TEXTURE_ON_PED(Ped ped, Hash componentHash, int textureId)
	{
		PED::_APPLY_TEXTURE_ON_PED(ped, componentHash, textureId);
	}

	static void LUA_NATIVE_PED__RELEASE_TEXTURE(int textureId)
	{
		PED::_RELEASE_TEXTURE(textureId);
	}

	static void LUA_NATIVE_PED__UPDATE_PED_TEXTURE(int textureId)
	{
		PED::_UPDATE_PED_TEXTURE(textureId);
	}

	static void LUA_NATIVE_PED__RESET_PED_TEXTURE(int textureId)
	{
		PED::_RESET_PED_TEXTURE(textureId);
	}

	static bool LUA_NATIVE_PED__IS_TEXTURE_VALID(int textureId)
	{
		auto retval = (bool)PED::_IS_TEXTURE_VALID(textureId);
		return retval;
	}

	static int LUA_NATIVE_PED__ADD_TEXTURE_LAYER(int textureId, Hash albedoHash, Hash normalHash, Hash materialHash, int blendType, float texAlpha, int sheetGridIndex)
	{
		auto retval = PED::_ADD_TEXTURE_LAYER(textureId, albedoHash, normalHash, materialHash, blendType, texAlpha, sheetGridIndex);
		return retval;
	}

	static void LUA_NATIVE_PED__REMOVE_PED_OVERLAY(int textureId, int overlayId)
	{
		PED::_REMOVE_PED_OVERLAY(textureId, overlayId);
	}

	static void LUA_NATIVE_PED__SET_TEXTURE_LAYER_SHEET_GRID_INDEX(int textureId, int layerId, int sheetGridIndex)
	{
		PED::_SET_TEXTURE_LAYER_SHEET_GRID_INDEX(textureId, layerId, sheetGridIndex);
	}

	static void LUA_NATIVE_PED__SET_TEXTURE_LAYER_ALPHA(int textureId, int layerId, float texAlpha)
	{
		PED::_SET_TEXTURE_LAYER_ALPHA(textureId, layerId, texAlpha);
	}

	static void LUA_NATIVE_PED__SET_TEXTURE_LAYER_ROUGHNESS(int textureId, int layerId, float texRough)
	{
		PED::_SET_TEXTURE_LAYER_ROUGHNESS(textureId, layerId, texRough);
	}

	static void LUA_NATIVE_PED__SET_TEXTURE_LAYER_PALLETE(int textureId, int layerId, Hash paletteHash)
	{
		PED::_SET_TEXTURE_LAYER_PALLETE(textureId, layerId, paletteHash);
	}

	static void LUA_NATIVE_PED__SET_TEXTURE_LAYER_TINT(int textureId, int layerId, int tint0, int tint1, int tint2)
	{
		PED::_SET_TEXTURE_LAYER_TINT(textureId, layerId, tint0, tint1, tint2);
	}

	static void LUA_NATIVE_PED__SET_TEXTURE_LAYER_MOD(int textureId, int layerId, Hash modTextureHash, float modAlpha, int modChannel)
	{
		PED::_SET_TEXTURE_LAYER_MOD(textureId, layerId, modTextureHash, modAlpha, modChannel);
	}

	static void LUA_NATIVE_PED__SET_TEXTURE_LAYER_TEXTURE_MAP(int textureId, int layerId, Hash albedoHash, Hash normalHash, Hash materialHash)
	{
		PED::_SET_TEXTURE_LAYER_TEXTURE_MAP(textureId, layerId, albedoHash, normalHash, materialHash);
	}

	static void LUA_NATIVE_PED__CLEAR_PED_TEXTURE(int textureId)
	{
		PED::_CLEAR_PED_TEXTURE(textureId);
	}

	static void LUA_NATIVE_PED__0xC991EF46FE323867(Ped ped, Any p1)
	{
		PED::_0xC991EF46FE323867(ped, p1);
	}

	static void LUA_NATIVE_PED__0x1F8215D0E446F593(Any p0, Any p1, Any p2)
	{
		PED::_0x1F8215D0E446F593(p0, p1, p2);
	}

	static bool LUA_NATIVE_PED_IS_LOCATION_SPAWN_SAFE(Ped ped, float p1)
	{
		auto retval = (bool)PED::IS_LOCATION_SPAWN_SAFE(ped, p1);
		return retval;
	}

	static void LUA_NATIVE_PED__0x53BA7D96B9A421D9(Any p0, Any p1)
	{
		PED::_0x53BA7D96B9A421D9(p0, p1);
	}

	static void LUA_NATIVE_PED__0x96C7B659854DE629(Any p0, Any p1)
	{
		PED::_0x96C7B659854DE629(p0, p1);
	}

	static void LUA_NATIVE_PED_SET_HORSE_AVOIDANCE_LEVEL(Ped horse, int avoidanceLevel)
	{
		PED::SET_HORSE_AVOIDANCE_LEVEL(horse, avoidanceLevel);
	}

	static void LUA_NATIVE_PED_RESET_HORSE_AVOIDANCE_LEVEL_TO_DEFAULT(Ped horse)
	{
		PED::RESET_HORSE_AVOIDANCE_LEVEL_TO_DEFAULT(horse);
	}

	static Any LUA_NATIVE_PED__SET_PED_USE_HORSE_MAP_COLLISION(Ped ped, bool toggle)
	{
		auto retval = PED::_SET_PED_USE_HORSE_MAP_COLLISION(ped, toggle);
		return retval;
	}

	static void LUA_NATIVE_PED__0x5B73975B4F12F7F3(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		PED::_0x5B73975B4F12F7F3(p0, p1, p2, p3, p4);
	}

	static std::tuple<bool, Hash, Hash, Hash, Hash> LUA_NATIVE_PED_GET_META_PED_ASSET_GUIDS(Ped ped, int index, Hash drawable, Hash albedo, Hash normal, Hash material)
	{
		std::tuple<bool, Hash, Hash, Hash, Hash> return_values;
		std::get<0>(return_values) = (bool)PED::GET_META_PED_ASSET_GUIDS(ped, index, &drawable, &albedo, &normal, &material);
		std::get<1>(return_values) = drawable;
		std::get<2>(return_values) = albedo;
		std::get<3>(return_values) = normal;
		std::get<4>(return_values) = material;

		return return_values;
	}

	static std::tuple<bool, Hash, int, int, int> LUA_NATIVE_PED_GET_META_PED_ASSET_TINT(Ped ped, int index, Hash pallete, int tint0, int tint1, int tint2)
	{
		std::tuple<bool, Hash, int, int, int> return_values;
		std::get<0>(return_values) = (bool)PED::GET_META_PED_ASSET_TINT(ped, index, &pallete, &tint0, &tint1, &tint2);
		std::get<1>(return_values) = pallete;
		std::get<2>(return_values) = tint0;
		std::get<3>(return_values) = tint1;
		std::get<4>(return_values) = tint2;

		return return_values;
	}

	static void LUA_NATIVE_PED__SET_PED_BLACKBOARD_INT(Ped ped, sol::stack_object variableName, int value, int removeTimer)
	{
		PED::_SET_PED_BLACKBOARD_INT(ped, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr, value, removeTimer);
	}

	static void LUA_NATIVE_PED__SET_PED_BLACKBOARD_BOOL(Ped ped, sol::stack_object variableName, bool value, int removeTimer)
	{
		PED::_SET_PED_BLACKBOARD_BOOL(ped, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr, value, removeTimer);
	}

	static void LUA_NATIVE_PED__SET_PED_BLACKBOARD_FLOAT(Ped ped, sol::stack_object variableName, float value, int removeTimer)
	{
		PED::_SET_PED_BLACKBOARD_FLOAT(ped, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr, value, removeTimer);
	}

	static void LUA_NATIVE_PED__SET_PED_BLACKBOARD_HASH(Ped ped, sol::stack_object variableName, sol::stack_object value, int removeTimer)
	{
		PED::_SET_PED_BLACKBOARD_HASH(ped, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr, value.is<const char*>() ? value.as<const char*>() : nullptr, removeTimer);
	}

	static void LUA_NATIVE_PED__REMOVE_PED_BLACKBOARD_INT(Ped ped, sol::stack_object variableName)
	{
		PED::_REMOVE_PED_BLACKBOARD_INT(ped, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__REMOVE_PED_BLACKBOARD_BOOL(Ped ped, sol::stack_object variableName)
	{
		PED::_REMOVE_PED_BLACKBOARD_BOOL(ped, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__REMOVE_PED_BLACKBOARD_FLOAT(Ped ped, sol::stack_object variableName)
	{
		PED::_REMOVE_PED_BLACKBOARD_FLOAT(ped, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__REMOVE_PED_BLACKBOARD_HASH(Ped ped, sol::stack_object variableName)
	{
		PED::_REMOVE_PED_BLACKBOARD_HASH(ped, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_PED__GET_PED_BLACKBOARD_BOOL(Ped ped, sol::stack_object variableName)
	{
		auto retval = (bool)PED::_GET_PED_BLACKBOARD_BOOL(ped, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
		return retval;
	}

	static float LUA_NATIVE_PED__GET_PED_BLACKBOARD_FLOAT(Ped ped, sol::stack_object variableName)
	{
		auto retval = PED::_GET_PED_BLACKBOARD_FLOAT(ped, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
		return retval;
	}

	static Hash LUA_NATIVE_PED__GET_PED_BLACKBOARD_HASH(Ped ped, sol::stack_object variableName)
	{
		auto retval = PED::_GET_PED_BLACKBOARD_HASH(ped, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
		return retval;
	}

	static int LUA_NATIVE_PED_GET_PED_BLACKBOARD_SCRIPT_INT(Ped ped, sol::stack_object variableName)
	{
		auto retval = PED::GET_PED_BLACKBOARD_SCRIPT_INT(ped, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_PED_GET_PED_BLACKBOARD_SCRIPT_BOOL(Ped ped, sol::stack_object variableName)
	{
		auto retval = (bool)PED::GET_PED_BLACKBOARD_SCRIPT_BOOL(ped, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
		return retval;
	}

	static float LUA_NATIVE_PED_GET_PED_BLACKBOARD_SCRIPT_FLOAT(Ped ped, sol::stack_object variableName)
	{
		auto retval = PED::GET_PED_BLACKBOARD_SCRIPT_FLOAT(ped, variableName.is<const char*>() ? variableName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_TANK_ATTRIBUTE_SIZE(Ped ped, int attributeIndex, float size)
	{
		PED::_SET_TANK_ATTRIBUTE_SIZE(ped, attributeIndex, size);
	}

	static Any LUA_NATIVE_PED__0xA31D350D66FA1855(Any p0)
	{
		auto retval = PED::_0xA31D350D66FA1855(p0);
		return retval;
	}

	static bool LUA_NATIVE_PED__IS_USING_SLIPSTREAM(Ped ped)
	{
		auto retval = (bool)PED::_IS_USING_SLIPSTREAM(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0xEEDC9B29314B2733(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9)
	{
		PED::_0xEEDC9B29314B2733(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
	}

	static void LUA_NATIVE_PED__0x5C90E20C25E6D83C(Any p0)
	{
		PED::_0x5C90E20C25E6D83C(p0);
	}

	static void LUA_NATIVE_PED__0x10F96086123B939F(Ped legendaryPed, Ped preyPed, float p2)
	{
		PED::_0x10F96086123B939F(legendaryPed, preyPed, p2);
	}

	static void LUA_NATIVE_PED__0x3FDBB99EFD8CE4AF(Any p0, Any p1, Any p2)
	{
		PED::_0x3FDBB99EFD8CE4AF(p0, p1, p2);
	}

	static void LUA_NATIVE_PED__0x7E8F9949B7AABBF0(Any p0, Any p1, Any p2)
	{
		PED::_0x7E8F9949B7AABBF0(p0, p1, p2);
	}

	static Any LUA_NATIVE_PED__0x5DA36CCCB63C0895(Any p0, Any p1, Any p2)
	{
		auto retval = PED::_0x5DA36CCCB63C0895(p0, p1, p2);
		return retval;
	}

	static void LUA_NATIVE_PED__0x56076667E7C2DCD6(Any p0, Any p1)
	{
		PED::_0x56076667E7C2DCD6(p0, p1);
	}

	static void LUA_NATIVE_PED__APPLY_SHOP_ITEM_TO_PED(Ped ped, Hash componentHash, bool immediately, bool isMp, bool p4)
	{
		PED::_APPLY_SHOP_ITEM_TO_PED(ped, componentHash, immediately, isMp, p4);
	}

	static void LUA_NATIVE_PED__REMOVE_SHOP_ITEM_FROM_PED(Ped ped, Hash componentHash, int p2, bool p3)
	{
		PED::_REMOVE_SHOP_ITEM_FROM_PED(ped, componentHash, p2, p3);
	}

	static void LUA_NATIVE_PED_REMOVE_SHOP_ITEM_FROM_PED_BY_CATEGORY(Ped ped, Hash componentCategory, int p2, bool p3)
	{
		PED::REMOVE_SHOP_ITEM_FROM_PED_BY_CATEGORY(ped, componentCategory, p2, p3);
	}

	static void LUA_NATIVE_PED__UPDATE_SHOP_ITEM_WEARABLE_STATE(Ped ped, Hash componentHash, Hash wearableState, int p3, bool p4, int p5)
	{
		PED::_UPDATE_SHOP_ITEM_WEARABLE_STATE(ped, componentHash, wearableState, p3, p4, p5);
	}

	static Hash LUA_NATIVE_PED__GET_SHOP_ITEM_COMPONENT_AT_INDEX(Ped ped, int index, bool p2, uintptr_t argStruct, uintptr_t argStruct2)
	{
		auto retval = PED::_GET_SHOP_ITEM_COMPONENT_AT_INDEX(ped, index, p2, (Any*)argStruct, (Any*)argStruct2);
		return retval;
	}

	static int LUA_NATIVE_PED__GET_SHOP_ITEM_NUM_WEARABLE_STATES(Hash componentHash, bool isMpFemale, bool p2)
	{
		auto retval = PED::_GET_SHOP_ITEM_NUM_WEARABLE_STATES(componentHash, isMpFemale, p2);
		return retval;
	}

	static Hash LUA_NATIVE_PED__GET_SHOP_ITEM_WEARABLE_STATE_BY_INDEX(Hash componentHash, int wearableStateIndex, bool isMpFemale, bool p3)
	{
		auto retval = PED::_GET_SHOP_ITEM_WEARABLE_STATE_BY_INDEX(componentHash, wearableStateIndex, isMpFemale, p3);
		return retval;
	}

	static Hash LUA_NATIVE_PED__GET_SHOP_ITEM_COMPONENT_CATEGORY(Hash componentHash, int metapedType, bool isMP)
	{
		auto retval = PED::_GET_SHOP_ITEM_COMPONENT_CATEGORY(componentHash, metapedType, isMP);
		return retval;
	}

	static Any LUA_NATIVE_PED__0x31B2E7F2E3C58B89(Any p0, Any p1, Any p2, Any p3)
	{
		auto retval = PED::_0x31B2E7F2E3C58B89(p0, p1, p2, p3);
		return retval;
	}

	static std::tuple<bool, Hash, Hash, Hash, Hash, Hash, Hash, Hash, Hash> LUA_NATIVE_PED__GET_SHOP_ITEM_BASE_LAYERS(Hash shopItem, Any p1, Ped ped, int metapedType, bool p4, Hash drawable, Hash albedo, Hash normal, Hash material, Hash p9, Hash p10, Hash p11, Hash p12)
	{
		std::tuple<bool, Hash, Hash, Hash, Hash, Hash, Hash, Hash, Hash> return_values;
		std::get<0>(return_values) = (bool)PED::_GET_SHOP_ITEM_BASE_LAYERS(shopItem, p1, ped, metapedType, p4, &drawable, &albedo, &normal, &material, &p9, &p10, &p11, &p12);
		std::get<1>(return_values) = drawable;
		std::get<2>(return_values) = albedo;
		std::get<3>(return_values) = normal;
		std::get<4>(return_values) = material;
		std::get<5>(return_values) = p9;
		std::get<6>(return_values) = p10;
		std::get<7>(return_values) = p11;
		std::get<8>(return_values) = p12;

		return return_values;
	}

	static Any LUA_NATIVE_PED__0xAAB86462966168CE(Ped ped, bool isMP)
	{
		auto retval = PED::_0xAAB86462966168CE(ped, isMP);
		return retval;
	}

	static Any LUA_NATIVE_PED__GET_SHOP_ITEM_HAT_COMPONENT(Ped ped, int metapedType, bool p2)
	{
		auto retval = PED::_GET_SHOP_ITEM_HAT_COMPONENT(ped, metapedType, p2);
		return retval;
	}

	static void LUA_NATIVE_PED__REFRESH_META_PED_SHOP_ITEMS(Ped ped, int p1)
	{
		PED::_REFRESH_META_PED_SHOP_ITEMS(ped, p1);
	}

	static void LUA_NATIVE_PED__0xD103F6DBB5442BE8(Ped ped, int p1)
	{
		PED::_0xD103F6DBB5442BE8(ped, p1);
	}

	static void LUA_NATIVE_PED__SET_PED_PROMPT_NAME_FROM_GXT_ENTRY(Ped ped, Hash gxtEntryHash)
	{
		PED::_SET_PED_PROMPT_NAME_FROM_GXT_ENTRY(ped, gxtEntryHash);
	}

	static void LUA_NATIVE_PED__SET_PED_PROMPT_NAME(Ped ped, sol::stack_object name)
	{
		PED::_SET_PED_PROMPT_NAME(ped, name.is<const char*>() ? name.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__SET_PED_PROMPT_NAME_FROM_GXT_ENTRY_2(Ped ped, Hash gxtEntryHash)
	{
		PED::_SET_PED_PROMPT_NAME_FROM_GXT_ENTRY_2(ped, gxtEntryHash);
	}

	static void LUA_NATIVE_PED__SET_PED_PROMPT_NAME_2(Ped ped, sol::stack_object name)
	{
		PED::_SET_PED_PROMPT_NAME_2(ped, name.is<const char*>() ? name.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__0xF917F92BF22ECBAB(Any p0)
	{
		PED::_0xF917F92BF22ECBAB(p0);
	}

	static void LUA_NATIVE_PED__0x49DADFC4CD808B0A(Any p0, Any p1, Any p2)
	{
		PED::_0x49DADFC4CD808B0A(p0, p1, p2);
	}

	static bool LUA_NATIVE_PED__HAS_PED_TAKEN_GORE_DAMAGE(Ped ped, int limb)
	{
		auto retval = (bool)PED::_HAS_PED_TAKEN_GORE_DAMAGE(ped, limb);
		return retval;
	}

	static void LUA_NATIVE_PED__0x704C908E9C405136(Ped ped)
	{
		PED::_0x704C908E9C405136(ped);
	}

	static void LUA_NATIVE_PED__0x7406C71F4AC2FFCC(Any p0)
	{
		PED::_0x7406C71F4AC2FFCC(p0);
	}

	static void LUA_NATIVE_PED__0x28508173C6A7CC18(Any p0)
	{
		PED::_0x28508173C6A7CC18(p0);
	}

	static Any LUA_NATIVE_PED__0x52250B92EA70BE3D(Any p0)
	{
		auto retval = PED::_0x52250B92EA70BE3D(p0);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_QUALITY(Ped ped, int quality)
	{
		PED::_SET_PED_QUALITY(ped, quality);
	}

	static int LUA_NATIVE_PED__GET_PED_QUALITY(Ped ped)
	{
		auto retval = PED::_GET_PED_QUALITY(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0xCE7A6C1D5CDE1F9D(Ped ped, Object object, sol::stack_object propName, sol::stack_object animName)
	{
		PED::_0xCE7A6C1D5CDE1F9D(ped, object, propName.is<const char*>() ? propName.as<const char*>() : nullptr, animName.is<const char*>() ? animName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__0x604E1010E3162E86(Any p0, Any p1, Any p2)
	{
		PED::_0x604E1010E3162E86(p0, p1, p2);
	}

	static void LUA_NATIVE_PED__0xE8ABE3B73FC7FE17(Any p0, Any p1, Any p2, Any p3)
	{
		PED::_0xE8ABE3B73FC7FE17(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_PED__REMOVE_PED_PROP(Ped ped, sol::stack_object propName)
	{
		PED::_REMOVE_PED_PROP(ped, propName.is<const char*>() ? propName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PED__SET_TOTAL_PED_DAMAGE_FALLOFF_BONUS(Ped ped, float bonus)
	{
		PED::_SET_TOTAL_PED_DAMAGE_FALLOFF_BONUS(ped, bonus);
	}

	static Any LUA_NATIVE_PED__0x095C2277FED731DB(Any p0)
	{
		auto retval = PED::_0x095C2277FED731DB(p0);
		return retval;
	}

	static void LUA_NATIVE_PED__0x09171A6F8FDE5DC1(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		PED::_0x09171A6F8FDE5DC1(p0, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_PED__0x09E378C52B1433B5(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		PED::_0x09E378C52B1433B5(p0, p1, p2, p3, p4);
	}

	static bool LUA_NATIVE_PED__0x6507AC3BD7C99009(float x, float y, float z, float p3)
	{
		auto retval = (bool)PED::_0x6507AC3BD7C99009(x, y, z, p3);
		return retval;
	}

	static float LUA_NATIVE_PED__GET_PLAYER_PED_WATER_DEPTH(Ped ped)
	{
		auto retval = PED::_GET_PLAYER_PED_WATER_DEPTH(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__SET_PED_TRAIL_EFFECT(Ped ped, bool p1, float duration)
	{
		PED::_SET_PED_TRAIL_EFFECT(ped, p1, duration);
	}

	static bool LUA_NATIVE_PED__0xEBAAC9A750E7563B(Ped ped)
	{
		auto retval = (bool)PED::_0xEBAAC9A750E7563B(ped);
		return retval;
	}

	static void LUA_NATIVE_PED__0x992187D975635DF5(Any p0, Any p1)
	{
		PED::_0x992187D975635DF5(p0, p1);
	}

	static void LUA_NATIVE_PED__0x0B787A37EEDD226F(Any p0, Any p1)
	{
		PED::_0x0B787A37EEDD226F(p0, p1);
	}

	void RegisterNatives_PED(sol::state& L)
	{
		auto PED = L["PED"].get_or_create<sol::table>();
		PED.set_function("CREATE_PED", LUA_NATIVE_PED_CREATE_PED);
		PED.set_function("DELETE_PED", LUA_NATIVE_PED_DELETE_PED);
		PED.set_function("_SET_REMOVE_PED_NETWORKED", LUA_NATIVE_PED__SET_REMOVE_PED_NETWORKED);
		PED.set_function("_0x7C08E7CB8D951B70", LUA_NATIVE_PED__0x7C08E7CB8D951B70);
		PED.set_function("_SET_PED_TO_BE_REMOVED", LUA_NATIVE_PED__SET_PED_TO_BE_REMOVED);
		PED.set_function("CLONE_PED", LUA_NATIVE_PED_CLONE_PED);
		PED.set_function("CLONE_PED_TO_TARGET", LUA_NATIVE_PED_CLONE_PED_TO_TARGET);
		PED.set_function("IS_PED_IN_VEHICLE", LUA_NATIVE_PED_IS_PED_IN_VEHICLE);
		PED.set_function("IS_PED_IN_MODEL", LUA_NATIVE_PED_IS_PED_IN_MODEL);
		PED.set_function("IS_PED_IN_ANY_VEHICLE", LUA_NATIVE_PED_IS_PED_IN_ANY_VEHICLE);
		PED.set_function("_0x9851DE7AEC10B4E1", LUA_NATIVE_PED__0x9851DE7AEC10B4E1);
		PED.set_function("IS_PED_INJURED", LUA_NATIVE_PED_IS_PED_INJURED);
		PED.set_function("IS_PED_FATALLY_INJURED", LUA_NATIVE_PED_IS_PED_FATALLY_INJURED);
		PED.set_function("IS_PED_DEAD_OR_DYING", LUA_NATIVE_PED_IS_PED_DEAD_OR_DYING);
		PED.set_function("_SET_PED_BLEEDOUT_PROFILE", LUA_NATIVE_PED__SET_PED_BLEEDOUT_PROFILE);
		PED.set_function("IS_PED_AIMING_FROM_COVER", LUA_NATIVE_PED_IS_PED_AIMING_FROM_COVER);
		PED.set_function("IS_PED_RELOADING", LUA_NATIVE_PED_IS_PED_RELOADING);
		PED.set_function("IS_PED_A_PLAYER", LUA_NATIVE_PED_IS_PED_A_PLAYER);
		PED.set_function("_IS_ANIMAL_CONTROLLED_BY_A_PLAYER", LUA_NATIVE_PED__IS_ANIMAL_CONTROLLED_BY_A_PLAYER);
		PED.set_function("CREATE_PED_INSIDE_VEHICLE", LUA_NATIVE_PED_CREATE_PED_INSIDE_VEHICLE);
		PED.set_function("SET_PED_DESIRED_HEADING", LUA_NATIVE_PED_SET_PED_DESIRED_HEADING);
		PED.set_function("FORCE_ALL_HEADING_VALUES_TO_ALIGN", LUA_NATIVE_PED_FORCE_ALL_HEADING_VALUES_TO_ALIGN);
		PED.set_function("IS_PED_FACING_PED", LUA_NATIVE_PED_IS_PED_FACING_PED);
		PED.set_function("IS_PED_IN_MELEE_COMBAT", LUA_NATIVE_PED_IS_PED_IN_MELEE_COMBAT);
		PED.set_function("_0x6DB875AFC584FA32", LUA_NATIVE_PED__0x6DB875AFC584FA32);
		PED.set_function("IS_PED_STOPPED", LUA_NATIVE_PED_IS_PED_STOPPED);
		PED.set_function("IS_PED_SITTING", LUA_NATIVE_PED_IS_PED_SITTING);
		PED.set_function("_0x09D7AFD3716DA8E1", LUA_NATIVE_PED__0x09D7AFD3716DA8E1);
		PED.set_function("_0x9C81338B2E62CE0A", LUA_NATIVE_PED__0x9C81338B2E62CE0A);
		PED.set_function("_0xB7DBB2986B87E230", LUA_NATIVE_PED__0xB7DBB2986B87E230);
		PED.set_function("_0xD355E2F1BB41087E", LUA_NATIVE_PED__0xD355E2F1BB41087E);
		PED.set_function("IS_ANY_PED_SHOOTING_IN_AREA", LUA_NATIVE_PED_IS_ANY_PED_SHOOTING_IN_AREA);
		PED.set_function("IS_PED_SHOOTING", LUA_NATIVE_PED_IS_PED_SHOOTING);
		PED.set_function("TIME_SINCE_PED_LAST_SHOT", LUA_NATIVE_PED_TIME_SINCE_PED_LAST_SHOT);
		PED.set_function("SET_PED_ACCURACY", LUA_NATIVE_PED_SET_PED_ACCURACY);
		PED.set_function("GET_PED_ACCURACY", LUA_NATIVE_PED_GET_PED_ACCURACY);
		PED.set_function("IS_PED_MODEL", LUA_NATIVE_PED_IS_PED_MODEL);
		PED.set_function("EXPLODE_PED_HEAD", LUA_NATIVE_PED_EXPLODE_PED_HEAD);
		PED.set_function("ADD_ARMOUR_TO_PED", LUA_NATIVE_PED_ADD_ARMOUR_TO_PED);
		PED.set_function("_0x5CA20FBE49891BBD", LUA_NATIVE_PED__0x5CA20FBE49891BBD);
		PED.set_function("SET_PED_INTO_VEHICLE", LUA_NATIVE_PED_SET_PED_INTO_VEHICLE);
		PED.set_function("SET_PED_MOVE_ANIMS_BLEND_OUT", LUA_NATIVE_PED_SET_PED_MOVE_ANIMS_BLEND_OUT);
		PED.set_function("_0x606D529DADA3C940", LUA_NATIVE_PED__0x606D529DADA3C940);
		PED.set_function("IS_PED_MALE", LUA_NATIVE_PED_IS_PED_MALE);
		PED.set_function("IS_PED_HUMAN", LUA_NATIVE_PED_IS_PED_HUMAN);
		PED.set_function("GET_VEHICLE_PED_IS_IN", LUA_NATIVE_PED_GET_VEHICLE_PED_IS_IN);
		PED.set_function("RESET_PED_LAST_VEHICLE", LUA_NATIVE_PED_RESET_PED_LAST_VEHICLE);
		PED.set_function("_0xC6136B40FFFB778B", LUA_NATIVE_PED__0xC6136B40FFFB778B);
		PED.set_function("_0x6E8B87139854022D", LUA_NATIVE_PED__0x6E8B87139854022D);
		PED.set_function("_GET_NUM_FREE_SLOTS_IN_PED_POOL", LUA_NATIVE_PED__GET_NUM_FREE_SLOTS_IN_PED_POOL);
		PED.set_function("_RESERVE_AMBIENT_PEDS", LUA_NATIVE_PED__RESERVE_AMBIENT_PEDS);
		PED.set_function("_RESERVE_AMBIENT_PEDS_TOTAL", LUA_NATIVE_PED__RESERVE_AMBIENT_PEDS_TOTAL);
		PED.set_function("_UNRESERVE_AMBIENT_PEDS", LUA_NATIVE_PED__UNRESERVE_AMBIENT_PEDS);
		PED.set_function("_GET_NUM_RESERVED_AMBIENT_PEDS_DESIRED", LUA_NATIVE_PED__GET_NUM_RESERVED_AMBIENT_PEDS_DESIRED);
		PED.set_function("_GET_NUM_RESERVED_AMBIENT_PEDS_READY", LUA_NATIVE_PED__GET_NUM_RESERVED_AMBIENT_PEDS_READY);
		PED.set_function("_ARE_ALL_AMBIENT_PED_RESERVATIONS_READY", LUA_NATIVE_PED__ARE_ALL_AMBIENT_PED_RESERVATIONS_READY);
		PED.set_function("_SET_SCENARIO_PED_RANGE_MULTIPLIER_THIS_FRAME", LUA_NATIVE_PED__SET_SCENARIO_PED_RANGE_MULTIPLIER_THIS_FRAME);
		PED.set_function("_0x9E3842E5DAD69F80", LUA_NATIVE_PED__0x9E3842E5DAD69F80);
		PED.set_function("_SET_AMBIENT_PED_DENSITY_MULTIPLIER_THIS_FRAME", LUA_NATIVE_PED__SET_AMBIENT_PED_DENSITY_MULTIPLIER_THIS_FRAME);
		PED.set_function("SET_SCENARIO_PED_DENSITY_MULTIPLIER_THIS_FRAME", LUA_NATIVE_PED_SET_SCENARIO_PED_DENSITY_MULTIPLIER_THIS_FRAME);
		PED.set_function("_SET_AMBIENT_ANIMAL_DENSITY_MULTIPLIER_THIS_FRAME", LUA_NATIVE_PED__SET_AMBIENT_ANIMAL_DENSITY_MULTIPLIER_THIS_FRAME);
		PED.set_function("_SET_AMBIENT_HUMAN_DENSITY_MULTIPLIER_THIS_FRAME", LUA_NATIVE_PED__SET_AMBIENT_HUMAN_DENSITY_MULTIPLIER_THIS_FRAME);
		PED.set_function("_SET_SCENARIO_ANIMAL_DENSITY_MULTIPLIER_THIS_FRAME", LUA_NATIVE_PED__SET_SCENARIO_ANIMAL_DENSITY_MULTIPLIER_THIS_FRAME);
		PED.set_function("_SET_SCENARIO_HUMAN_DENSITY_MULTIPLIER_THIS_FRAME", LUA_NATIVE_PED__SET_SCENARIO_HUMAN_DENSITY_MULTIPLIER_THIS_FRAME);
		PED.set_function("_SET_SCENARIO_PED_DENSITY_THIS_FRAME", LUA_NATIVE_PED__SET_SCENARIO_PED_DENSITY_THIS_FRAME);
		PED.set_function("INSTANTLY_FILL_PED_POPULATION", LUA_NATIVE_PED_INSTANTLY_FILL_PED_POPULATION);
		PED.set_function("_0xBFA6B7731C3BAF02", LUA_NATIVE_PED__0xBFA6B7731C3BAF02);
		PED.set_function("IS_INSTANTLY_FILL_PED_POPULATION_FINISHED", LUA_NATIVE_PED_IS_INSTANTLY_FILL_PED_POPULATION_FINISHED);
		PED.set_function("SET_PED_NON_CREATION_AREA", LUA_NATIVE_PED_SET_PED_NON_CREATION_AREA);
		PED.set_function("CLEAR_PED_NON_CREATION_AREA", LUA_NATIVE_PED_CLEAR_PED_NON_CREATION_AREA);
		PED.set_function("_ATTACH_VOLUME_TO_ENTITY", LUA_NATIVE_PED__ATTACH_VOLUME_TO_ENTITY);
		PED.set_function("_DETACH_VOLUME_FROM_ENTITY", LUA_NATIVE_PED__DETACH_VOLUME_FROM_ENTITY);
		PED.set_function("SET_PED_ONTO_MOUNT", LUA_NATIVE_PED_SET_PED_ONTO_MOUNT);
		PED.set_function("_REMOVE_PED_FROM_MOUNT", LUA_NATIVE_PED__REMOVE_PED_FROM_MOUNT);
		PED.set_function("CREATE_PED_ON_MOUNT", LUA_NATIVE_PED_CREATE_PED_ON_MOUNT);
		PED.set_function("_IS_MOUNT_SEAT_FREE", LUA_NATIVE_PED__IS_MOUNT_SEAT_FREE);
		PED.set_function("IS_PED_ON_MOUNT", LUA_NATIVE_PED_IS_PED_ON_MOUNT);
		PED.set_function("IS_PED_FULLY_ON_MOUNT", LUA_NATIVE_PED_IS_PED_FULLY_ON_MOUNT);
		PED.set_function("GET_MOUNT", LUA_NATIVE_PED_GET_MOUNT);
		PED.set_function("_GET_LAST_LED_MOUNT", LUA_NATIVE_PED__GET_LAST_LED_MOUNT);
		PED.set_function("_GET_LAST_MOUNT", LUA_NATIVE_PED__GET_LAST_MOUNT);
		PED.set_function("_0xED1C764997A86D5A", LUA_NATIVE_PED__0xED1C764997A86D5A);
		PED.set_function("_0xB8AB265426CFE6DD", LUA_NATIVE_PED__0xB8AB265426CFE6DD);
		PED.set_function("_0xE8D1CCB9375C101B", LUA_NATIVE_PED__0xE8D1CCB9375C101B);
		PED.set_function("_0xA691C10054275290", LUA_NATIVE_PED__0xA691C10054275290);
		PED.set_function("_0x6734F0A6A52C371C", LUA_NATIVE_PED__0x6734F0A6A52C371C);
		PED.set_function("_0x024EC9B649111915", LUA_NATIVE_PED__0x024EC9B649111915);
		PED.set_function("SET_PED_OWNS_ANIMAL", LUA_NATIVE_PED_SET_PED_OWNS_ANIMAL);
		PED.set_function("_GET_ACTIVE_ANIMAL_OWNER", LUA_NATIVE_PED__GET_ACTIVE_ANIMAL_OWNER);
		PED.set_function("_CLEAR_ACTIVE_ANIMAL_OWNER", LUA_NATIVE_PED__CLEAR_ACTIVE_ANIMAL_OWNER);
		PED.set_function("_GET_HORSE_TAMING_STATE", LUA_NATIVE_PED__GET_HORSE_TAMING_STATE);
		PED.set_function("_0x54D3CD482742C482", LUA_NATIVE_PED__0x54D3CD482742C482);
		PED.set_function("_0x5CB2EBB467BE3ED6", LUA_NATIVE_PED__0x5CB2EBB467BE3ED6);
		PED.set_function("_0x9F0F28B42C4EE80A", LUA_NATIVE_PED__0x9F0F28B42C4EE80A);
		PED.set_function("_SET_MOUNT_BONDING_LEVEL", LUA_NATIVE_PED__SET_MOUNT_BONDING_LEVEL);
		PED.set_function("_SET_MOUNT_SECURITY_ENABLED", LUA_NATIVE_PED__SET_MOUNT_SECURITY_ENABLED);
		PED.set_function("_0x9B65444C07B782BF", LUA_NATIVE_PED__0x9B65444C07B782BF);
		PED.set_function("IS_ANIMAL_INTERACTION_POSSIBLE", LUA_NATIVE_PED_IS_ANIMAL_INTERACTION_POSSIBLE);
		PED.set_function("_IS_ANIMAL_INTERACTION_RUNNING", LUA_NATIVE_PED__IS_ANIMAL_INTERACTION_RUNNING);
		PED.set_function("_0x8BE24D74D74C6E9B", LUA_NATIVE_PED__0x8BE24D74D74C6E9B);
		PED.set_function("_0x77243ED4F7CAAA55", LUA_NATIVE_PED__0x77243ED4F7CAAA55);
		PED.set_function("IS_PED_ON_VEHICLE", LUA_NATIVE_PED_IS_PED_ON_VEHICLE);
		PED.set_function("IS_PED_ON_SPECIFIC_VEHICLE", LUA_NATIVE_PED_IS_PED_ON_SPECIFIC_VEHICLE);
		PED.set_function("_WARP_PED_OUT_OF_VEHICLE", LUA_NATIVE_PED__WARP_PED_OUT_OF_VEHICLE);
		PED.set_function("SET_PED_MONEY", LUA_NATIVE_PED_SET_PED_MONEY);
		PED.set_function("GET_PED_MONEY", LUA_NATIVE_PED_GET_PED_MONEY);
		PED.set_function("SET_BLOCKING_OF_NON_TEMPORARY_EVENTS_FOR_AMBIENT_PEDS_THIS_FRAME", LUA_NATIVE_PED_SET_BLOCKING_OF_NON_TEMPORARY_EVENTS_FOR_AMBIENT_PEDS_THIS_FRAME);
		PED.set_function("_0x34EDDD59364AD74A", LUA_NATIVE_PED__0x34EDDD59364AD74A);
		PED.set_function("_0x2D976DBDC731DF80", LUA_NATIVE_PED__0x2D976DBDC731DF80);
		PED.set_function("IS_PED_SITTING_IN_VEHICLE", LUA_NATIVE_PED_IS_PED_SITTING_IN_VEHICLE);
		PED.set_function("IS_PED_SITTING_IN_ANY_VEHICLE", LUA_NATIVE_PED_IS_PED_SITTING_IN_ANY_VEHICLE);
		PED.set_function("IS_PED_ON_FOOT", LUA_NATIVE_PED_IS_PED_ON_FOOT);
		PED.set_function("IS_PED_PLANTING_BOMB", LUA_NATIVE_PED_IS_PED_PLANTING_BOMB);
		PED.set_function("GET_DEAD_PED_PICKUP_COORDS", LUA_NATIVE_PED_GET_DEAD_PED_PICKUP_COORDS);
		PED.set_function("IS_PED_IN_ANY_BOAT", LUA_NATIVE_PED_IS_PED_IN_ANY_BOAT);
		PED.set_function("IS_PED_IN_ANY_HELI", LUA_NATIVE_PED_IS_PED_IN_ANY_HELI);
		PED.set_function("IS_PED_IN_ANY_PLANE", LUA_NATIVE_PED_IS_PED_IN_ANY_PLANE);
		PED.set_function("IS_PED_IN_FLYING_VEHICLE", LUA_NATIVE_PED_IS_PED_IN_FLYING_VEHICLE);
		PED.set_function("_0x256EDD55C6BE1482", LUA_NATIVE_PED__0x256EDD55C6BE1482);
		PED.set_function("GET_PED_LAST_DAMAGE_BONE", LUA_NATIVE_PED_GET_PED_LAST_DAMAGE_BONE);
		PED.set_function("CLEAR_PED_LAST_DAMAGE_BONE", LUA_NATIVE_PED_CLEAR_PED_LAST_DAMAGE_BONE);
		PED.set_function("_GET_PED_DAMAGE_CLEANLINESS", LUA_NATIVE_PED__GET_PED_DAMAGE_CLEANLINESS);
		PED.set_function("_SET_PED_DAMAGE_CLEANLINESS", LUA_NATIVE_PED__SET_PED_DAMAGE_CLEANLINESS);
		PED.set_function("_GET_PED_DAMAGED", LUA_NATIVE_PED__GET_PED_DAMAGED);
		PED.set_function("_SET_PED_DAMAGED", LUA_NATIVE_PED__SET_PED_DAMAGED);
		PED.set_function("_SET_PLAYER_CURRENT_ANIMAL_DAMAGE_MODIFIER", LUA_NATIVE_PED__SET_PLAYER_CURRENT_ANIMAL_DAMAGE_MODIFIER);
		PED.set_function("_UPDATE_ANIMAL_DAMAGE_MODIFIER", LUA_NATIVE_PED__UPDATE_ANIMAL_DAMAGE_MODIFIER);
		PED.set_function("_GET_PLAYER_CURRENT_ANIMAL_DAMAGE_MODIFIER", LUA_NATIVE_PED__GET_PLAYER_CURRENT_ANIMAL_DAMAGE_MODIFIER);
		PED.set_function("_0xB29C553BA582D09E", LUA_NATIVE_PED__0xB29C553BA582D09E);
		PED.set_function("_0x101B45C5F56D970F", LUA_NATIVE_PED__0x101B45C5F56D970F);
		PED.set_function("_COMPUTE_SATCHEL_ITEM_FOR_PED_CARCASS", LUA_NATIVE_PED__COMPUTE_SATCHEL_ITEM_FOR_PED_CARCASS);
		PED.set_function("COMPUTE_SATCHEL_ITEM_FOR_PED_DAMAGE", LUA_NATIVE_PED_COMPUTE_SATCHEL_ITEM_FOR_PED_DAMAGE);
		PED.set_function("SET_AI_WEAPON_DAMAGE_MODIFIER", LUA_NATIVE_PED_SET_AI_WEAPON_DAMAGE_MODIFIER);
		PED.set_function("RESET_AI_WEAPON_DAMAGE_MODIFIER", LUA_NATIVE_PED_RESET_AI_WEAPON_DAMAGE_MODIFIER);
		PED.set_function("_SET_TOTAL_PED_DAMAGE_FROM_AI", LUA_NATIVE_PED__SET_TOTAL_PED_DAMAGE_FROM_AI);
		PED.set_function("_0xA6D6F03095C88F59", LUA_NATIVE_PED__0xA6D6F03095C88F59);
		PED.set_function("_GET_TOTAL_PED_DAMAGE_FROM_AI", LUA_NATIVE_PED__GET_TOTAL_PED_DAMAGE_FROM_AI);
		PED.set_function("SET_PED_TO_PLAYER_WEAPON_DAMAGE_MODIFIER", LUA_NATIVE_PED_SET_PED_TO_PLAYER_WEAPON_DAMAGE_MODIFIER);
		PED.set_function("GET_PED_TO_PLAYER_WEAPON_DAMAGE_MODIFIER", LUA_NATIVE_PED_GET_PED_TO_PLAYER_WEAPON_DAMAGE_MODIFIER);
		PED.set_function("_SET_CURRENT_DEFENSE_AGAINST_PLAYERS_MODIFIER", LUA_NATIVE_PED__SET_CURRENT_DEFENSE_AGAINST_PLAYERS_MODIFIER);
		PED.set_function("_0x763FA8A9D76EE3A7", LUA_NATIVE_PED__0x763FA8A9D76EE3A7);
		PED.set_function("SET_AI_MELEE_WEAPON_DAMAGE_MODIFIER", LUA_NATIVE_PED_SET_AI_MELEE_WEAPON_DAMAGE_MODIFIER);
		PED.set_function("_SET_ACCURACY_AGAINST_LOCAL_PLAYER_MODIFIER", LUA_NATIVE_PED__SET_ACCURACY_AGAINST_LOCAL_PLAYER_MODIFIER);
		PED.set_function("_GET_ACCURACY_AGAINST_LOCAL_PLAYER_MODIFIER", LUA_NATIVE_PED__GET_ACCURACY_AGAINST_LOCAL_PLAYER_MODIFIER);
		PED.set_function("_SET_PED_HEADSHOT_DAMAGE_MULTIPLIER", LUA_NATIVE_PED__SET_PED_HEADSHOT_DAMAGE_MULTIPLIER);
		PED.set_function("_0xDEE8D30AA5C2E28D", LUA_NATIVE_PED__0xDEE8D30AA5C2E28D);
		PED.set_function("_0xE1B3BE07D3AADDED", LUA_NATIVE_PED__0xE1B3BE07D3AADDED);
		PED.set_function("_0x32CEDA9A0AB4CEF7", LUA_NATIVE_PED__0x32CEDA9A0AB4CEF7);
		PED.set_function("_0x52A24D8A1DA89658", LUA_NATIVE_PED__0x52A24D8A1DA89658);
		PED.set_function("_0x34B5CEAC180A5D6E", LUA_NATIVE_PED__0x34B5CEAC180A5D6E);
		PED.set_function("_0x4F27603E44A8E4C0", LUA_NATIVE_PED__0x4F27603E44A8E4C0);
		PED.set_function("_0x3FDCC1F8C17E303E", LUA_NATIVE_PED__0x3FDCC1F8C17E303E);
		PED.set_function("_0xE50C9816B3F22D8B", LUA_NATIVE_PED__0xE50C9816B3F22D8B);
		PED.set_function("_SET_DEFENSE_MODIFIER_FOR_PED", LUA_NATIVE_PED__SET_DEFENSE_MODIFIER_FOR_PED);
		PED.set_function("_SET_MIN_PED_HEALTH_THRESHOLD", LUA_NATIVE_PED__SET_MIN_PED_HEALTH_THRESHOLD);
		PED.set_function("_0xC5B78E41DCF8227C", LUA_NATIVE_PED__0xC5B78E41DCF8227C);
		PED.set_function("SET_PED_CAN_BE_TARGETTED", LUA_NATIVE_PED_SET_PED_CAN_BE_TARGETTED);
		PED.set_function("SET_PED_CAN_BE_TARGETTED_BY_TEAM", LUA_NATIVE_PED_SET_PED_CAN_BE_TARGETTED_BY_TEAM);
		PED.set_function("SET_PED_CAN_BE_TARGETTED_BY_PLAYER", LUA_NATIVE_PED_SET_PED_CAN_BE_TARGETTED_BY_PLAYER);
		PED.set_function("_SET_INTERACTION_LOCKON_FLAG", LUA_NATIVE_PED__SET_INTERACTION_LOCKON_FLAG);
		PED.set_function("IS_PED_FALLING", LUA_NATIVE_PED_IS_PED_FALLING);
		PED.set_function("_IS_PED_SLIDING", LUA_NATIVE_PED__IS_PED_SLIDING);
		PED.set_function("IS_PED_JUMPING", LUA_NATIVE_PED_IS_PED_JUMPING);
		PED.set_function("IS_PED_CLIMBING", LUA_NATIVE_PED_IS_PED_CLIMBING);
		PED.set_function("_IS_PED_CLIMBING_LADDER", LUA_NATIVE_PED__IS_PED_CLIMBING_LADDER);
		PED.set_function("_0x577C60BA06D0EA64", LUA_NATIVE_PED__0x577C60BA06D0EA64);
		PED.set_function("IS_PED_VAULTING", LUA_NATIVE_PED_IS_PED_VAULTING);
		PED.set_function("IS_PED_DIVING", LUA_NATIVE_PED_IS_PED_DIVING);
		PED.set_function("IS_PED_OPENING_DOOR", LUA_NATIVE_PED_IS_PED_OPENING_DOOR);
		PED.set_function("_0x5C6C7C70CA302801", LUA_NATIVE_PED__0x5C6C7C70CA302801);
		PED.set_function("_0xB91AB3BE7F655D49", LUA_NATIVE_PED__0xB91AB3BE7F655D49);
		PED.set_function("IS_PED_IN_ANY_TAXI", LUA_NATIVE_PED_IS_PED_IN_ANY_TAXI);
		PED.set_function("SET_PED_ID_RANGE", LUA_NATIVE_PED_SET_PED_ID_RANGE);
		PED.set_function("_GET_PED_ID_RANGE", LUA_NATIVE_PED__GET_PED_ID_RANGE);
		PED.set_function("SET_PED_HIGHLY_PERCEPTIVE", LUA_NATIVE_PED_SET_PED_HIGHLY_PERCEPTIVE);
		PED.set_function("SET_PED_INJURED_ON_GROUND_BEHAVIOUR", LUA_NATIVE_PED_SET_PED_INJURED_ON_GROUND_BEHAVIOUR);
		PED.set_function("DISABLE_PED_INJURED_ON_GROUND_BEHAVIOUR", LUA_NATIVE_PED_DISABLE_PED_INJURED_ON_GROUND_BEHAVIOUR);
		PED.set_function("_0x028E7B3BBA0BD2FC", LUA_NATIVE_PED__0x028E7B3BBA0BD2FC);
		PED.set_function("_0xFA8C10DCE0706D43", LUA_NATIVE_PED__0xFA8C10DCE0706D43);
		PED.set_function("_SET_PED_ANIMAL_DETECTION_MODIFIER", LUA_NATIVE_PED__SET_PED_ANIMAL_DETECTION_MODIFIER);
		PED.set_function("_0x2BA9D7BF629F920C", LUA_NATIVE_PED__0x2BA9D7BF629F920C);
		PED.set_function("SET_PED_SEEING_RANGE", LUA_NATIVE_PED_SET_PED_SEEING_RANGE);
		PED.set_function("_0x900CA00CE703E1E2", LUA_NATIVE_PED__0x900CA00CE703E1E2);
		PED.set_function("SET_PED_HEARING_RANGE", LUA_NATIVE_PED_SET_PED_HEARING_RANGE);
		PED.set_function("SET_PED_VISUAL_FIELD_MIN_ANGLE", LUA_NATIVE_PED_SET_PED_VISUAL_FIELD_MIN_ANGLE);
		PED.set_function("SET_PED_VISUAL_FIELD_MAX_ANGLE", LUA_NATIVE_PED_SET_PED_VISUAL_FIELD_MAX_ANGLE);
		PED.set_function("SET_PED_VISUAL_FIELD_PERIPHERAL_RANGE", LUA_NATIVE_PED_SET_PED_VISUAL_FIELD_PERIPHERAL_RANGE);
		PED.set_function("SET_PED_VISUAL_FIELD_CENTER_ANGLE", LUA_NATIVE_PED_SET_PED_VISUAL_FIELD_CENTER_ANGLE);
		PED.set_function("_0x9AB33CB5834885B3", LUA_NATIVE_PED__0x9AB33CB5834885B3);
		PED.set_function("_0x899DFA0009AC93DE", LUA_NATIVE_PED__0x899DFA0009AC93DE);
		PED.set_function("_0x3A5697B80FED5EBE", LUA_NATIVE_PED__0x3A5697B80FED5EBE);
		PED.set_function("SET_PED_STEALTH_MOVEMENT", LUA_NATIVE_PED_SET_PED_STEALTH_MOVEMENT);
		PED.set_function("GET_PED_STEALTH_MOVEMENT", LUA_NATIVE_PED_GET_PED_STEALTH_MOVEMENT);
		PED.set_function("_SET_PED_CROUCH_MOVEMENT", LUA_NATIVE_PED__SET_PED_CROUCH_MOVEMENT);
		PED.set_function("GET_PED_CROUCH_MOVEMENT", LUA_NATIVE_PED_GET_PED_CROUCH_MOVEMENT);
		PED.set_function("GET_PED_IS_DOING_COMBAT_ROLL", LUA_NATIVE_PED_GET_PED_IS_DOING_COMBAT_ROLL);
		PED.set_function("CREATE_GROUP", LUA_NATIVE_PED_CREATE_GROUP);
		PED.set_function("SET_PED_AS_GROUP_LEADER", LUA_NATIVE_PED_SET_PED_AS_GROUP_LEADER);
		PED.set_function("SET_PED_AS_GROUP_MEMBER", LUA_NATIVE_PED_SET_PED_AS_GROUP_MEMBER);
		PED.set_function("SET_PED_CAN_TELEPORT_TO_GROUP_LEADER", LUA_NATIVE_PED_SET_PED_CAN_TELEPORT_TO_GROUP_LEADER);
		PED.set_function("REMOVE_GROUP", LUA_NATIVE_PED_REMOVE_GROUP);
		PED.set_function("REMOVE_PED_FROM_GROUP", LUA_NATIVE_PED_REMOVE_PED_FROM_GROUP);
		PED.set_function("IS_PED_GROUP_MEMBER", LUA_NATIVE_PED_IS_PED_GROUP_MEMBER);
		PED.set_function("_IS_PED_GROUP_LEADER", LUA_NATIVE_PED__IS_PED_GROUP_LEADER);
		PED.set_function("IS_PED_HANGING_ON_TO_VEHICLE", LUA_NATIVE_PED_IS_PED_HANGING_ON_TO_VEHICLE);
		PED.set_function("SET_GROUP_SEPARATION_RANGE", LUA_NATIVE_PED_SET_GROUP_SEPARATION_RANGE);
		PED.set_function("_0x89E59DBD15E21177", LUA_NATIVE_PED__0x89E59DBD15E21177);
		PED.set_function("IS_PED_PRONE", LUA_NATIVE_PED_IS_PED_PRONE);
		PED.set_function("_IS_PED_INVESTIGATING", LUA_NATIVE_PED__IS_PED_INVESTIGATING);
		PED.set_function("IS_PED_IN_COMBAT", LUA_NATIVE_PED_IS_PED_IN_COMBAT);
		PED.set_function("CAN_PED_IN_COMBAT_SEE_TARGET", LUA_NATIVE_PED_CAN_PED_IN_COMBAT_SEE_TARGET);
		PED.set_function("IS_PED_JACKING", LUA_NATIVE_PED_IS_PED_JACKING);
		PED.set_function("IS_PED_BEING_JACKED", LUA_NATIVE_PED_IS_PED_BEING_JACKED);
		PED.set_function("IS_PED_BEING_STUNNED", LUA_NATIVE_PED_IS_PED_BEING_STUNNED);
		PED.set_function("GET_PEDS_JACKER", LUA_NATIVE_PED_GET_PEDS_JACKER);
		PED.set_function("GET_JACK_TARGET", LUA_NATIVE_PED_GET_JACK_TARGET);
		PED.set_function("IS_PED_FLEEING", LUA_NATIVE_PED_IS_PED_FLEEING);
		PED.set_function("IS_PED_IN_COVER", LUA_NATIVE_PED_IS_PED_IN_COVER);
		PED.set_function("_0x2DD4E0E26DFAD97D", LUA_NATIVE_PED__0x2DD4E0E26DFAD97D);
		PED.set_function("_PED_WAS_KILLED_BY_HEADSHOT", LUA_NATIVE_PED__PED_WAS_KILLED_BY_HEADSHOT);
		PED.set_function("_PED_DUELING_DID_PLAYER_HEADSHOT_OPPONENT", LUA_NATIVE_PED__PED_DUELING_DID_PLAYER_HEADSHOT_OPPONENT);
		PED.set_function("IS_PED_IN_COVER_FACING_LEFT", LUA_NATIVE_PED_IS_PED_IN_COVER_FACING_LEFT);
		PED.set_function("IS_PED_GOING_INTO_COVER", LUA_NATIVE_PED_IS_PED_GOING_INTO_COVER);
		PED.set_function("IS_PED_RESPONDING_TO_THREAT", LUA_NATIVE_PED_IS_PED_RESPONDING_TO_THREAT);
		PED.set_function("_GET_ACTIVE_DYNAMIC_SCENARIO_2", LUA_NATIVE_PED__GET_ACTIVE_DYNAMIC_SCENARIO_2);
		PED.set_function("_GET_ACTIVE_DYNAMIC_SCENARIO", LUA_NATIVE_PED__GET_ACTIVE_DYNAMIC_SCENARIO);
		PED.set_function("_GIVE_PED_SCENARIO_PROP", LUA_NATIVE_PED__GIVE_PED_SCENARIO_PROP);
		PED.set_function("GIVE_PED_HASH_SCENARIO_PROP", LUA_NATIVE_PED_GIVE_PED_HASH_SCENARIO_PROP);
		PED.set_function("_GIVE_PED_SCENARIO_PROP_DYNAMIC", LUA_NATIVE_PED__GIVE_PED_SCENARIO_PROP_DYNAMIC);
		PED.set_function("_REQUEST_PROP_SCENARIO_PED", LUA_NATIVE_PED__REQUEST_PROP_SCENARIO_PED);
		PED.set_function("_REQUEST_PED_FOR_SCENARIO_TYPE", LUA_NATIVE_PED__REQUEST_PED_FOR_SCENARIO_TYPE);
		PED.set_function("_GET_PED_REGISTER_PROP", LUA_NATIVE_PED__GET_PED_REGISTER_PROP);
		PED.set_function("GET_SEAT_PED_IS_TRYING_TO_ENTER", LUA_NATIVE_PED_GET_SEAT_PED_IS_TRYING_TO_ENTER);
		PED.set_function("GET_PED_SOURCE_OF_DEATH", LUA_NATIVE_PED_GET_PED_SOURCE_OF_DEATH);
		PED.set_function("GET_PED_CAUSE_OF_DEATH", LUA_NATIVE_PED_GET_PED_CAUSE_OF_DEATH);
		PED.set_function("GET_PED_TIME_OF_DEATH", LUA_NATIVE_PED_GET_PED_TIME_OF_DEATH);
		PED.set_function("COUNT_PEDS_IN_COMBAT_WITH_TARGET", LUA_NATIVE_PED_COUNT_PEDS_IN_COMBAT_WITH_TARGET);
		PED.set_function("_GET_PEDS_IN_COMBAT_WITH_TARGET", LUA_NATIVE_PED__GET_PEDS_IN_COMBAT_WITH_TARGET);
		PED.set_function("COUNT_PEDS_IN_COMBAT_WITH_TARGET_WITHIN_RADIUS", LUA_NATIVE_PED_COUNT_PEDS_IN_COMBAT_WITH_TARGET_WITHIN_RADIUS);
		PED.set_function("GET_CURRENT_TARGET_FOR_PED", LUA_NATIVE_PED_GET_CURRENT_TARGET_FOR_PED);
		PED.set_function("SET_PED_RELATIONSHIP_GROUP_DEFAULT_HASH", LUA_NATIVE_PED_SET_PED_RELATIONSHIP_GROUP_DEFAULT_HASH);
		PED.set_function("_GET_DEFAULT_RELATIONSHIP_GROUP_HASH", LUA_NATIVE_PED__GET_DEFAULT_RELATIONSHIP_GROUP_HASH);
		PED.set_function("SET_PED_RELATIONSHIP_GROUP_HASH", LUA_NATIVE_PED_SET_PED_RELATIONSHIP_GROUP_HASH);
		PED.set_function("SET_RELATIONSHIP_BETWEEN_GROUPS", LUA_NATIVE_PED_SET_RELATIONSHIP_BETWEEN_GROUPS);
		PED.set_function("CLEAR_RELATIONSHIP_BETWEEN_GROUPS", LUA_NATIVE_PED_CLEAR_RELATIONSHIP_BETWEEN_GROUPS);
		PED.set_function("ADD_RELATIONSHIP_GROUP", LUA_NATIVE_PED_ADD_RELATIONSHIP_GROUP);
		PED.set_function("REMOVE_RELATIONSHIP_GROUP", LUA_NATIVE_PED_REMOVE_RELATIONSHIP_GROUP);
		PED.set_function("GET_RELATIONSHIP_BETWEEN_PEDS", LUA_NATIVE_PED_GET_RELATIONSHIP_BETWEEN_PEDS);
		PED.set_function("GET_PED_RELATIONSHIP_GROUP_DEFAULT_HASH", LUA_NATIVE_PED_GET_PED_RELATIONSHIP_GROUP_DEFAULT_HASH);
		PED.set_function("GET_PED_RELATIONSHIP_GROUP_HASH", LUA_NATIVE_PED_GET_PED_RELATIONSHIP_GROUP_HASH);
		PED.set_function("GET_RELATIONSHIP_BETWEEN_GROUPS", LUA_NATIVE_PED_GET_RELATIONSHIP_BETWEEN_GROUPS);
		PED.set_function("_0xDC91F22F09BC6C2F", LUA_NATIVE_PED__0xDC91F22F09BC6C2F);
		PED.set_function("_0x9629FAF6460D35CB", LUA_NATIVE_PED__0x9629FAF6460D35CB);
		PED.set_function("_0x4E68C7EF706DF35D", LUA_NATIVE_PED__0x4E68C7EF706DF35D);
		PED.set_function("_0x3ACCE14DFA6BA8C2", LUA_NATIVE_PED__0x3ACCE14DFA6BA8C2);
		PED.set_function("SET_PED_TO_INFORM_RESPECTED_FRIENDS", LUA_NATIVE_PED_SET_PED_TO_INFORM_RESPECTED_FRIENDS);
		PED.set_function("_0x40C9155AF8BC13F3", LUA_NATIVE_PED__0x40C9155AF8BC13F3);
		PED.set_function("_0xF4860514AD354226", LUA_NATIVE_PED__0xF4860514AD354226);
		PED.set_function("IS_PED_RESPONDING_TO_EVENT", LUA_NATIVE_PED_IS_PED_RESPONDING_TO_EVENT);
		PED.set_function("_0x5E9FAF6C513347B4", LUA_NATIVE_PED__0x5E9FAF6C513347B4);
		PED.set_function("_0x326F7951EF0D7F75", LUA_NATIVE_PED__0x326F7951EF0D7F75);
		PED.set_function("_0xE76687023D8C8505", LUA_NATIVE_PED__0xE76687023D8C8505);
		PED.set_function("_0xCB8F4C9343EBE240", LUA_NATIVE_PED__0xCB8F4C9343EBE240);
		PED.set_function("SET_PED_FIRING_PATTERN", LUA_NATIVE_PED_SET_PED_FIRING_PATTERN);
		PED.set_function("_SET_PED_FIRING_PATTERN_2", LUA_NATIVE_PED__SET_PED_FIRING_PATTERN_2);
		PED.set_function("_SET_PED_FIRING_PATTERN_3", LUA_NATIVE_PED__SET_PED_FIRING_PATTERN_3);
		PED.set_function("SET_PED_SHOOT_RATE", LUA_NATIVE_PED_SET_PED_SHOOT_RATE);
		PED.set_function("_0x3C529A827998F9B3", LUA_NATIVE_PED__0x3C529A827998F9B3);
		PED.set_function("_0x1F44B7E283C09EDE", LUA_NATIVE_PED__0x1F44B7E283C09EDE);
		PED.set_function("SET_COMBAT_FLOAT", LUA_NATIVE_PED_SET_COMBAT_FLOAT);
		PED.set_function("GET_COMBAT_FLOAT", LUA_NATIVE_PED_GET_COMBAT_FLOAT);
		PED.set_function("GET_GROUP_SIZE", LUA_NATIVE_PED_GET_GROUP_SIZE);
		PED.set_function("DOES_GROUP_EXIST", LUA_NATIVE_PED_DOES_GROUP_EXIST);
		PED.set_function("_0x0455546F23FF08E4", LUA_NATIVE_PED__0x0455546F23FF08E4);
		PED.set_function("IS_GROUP_LOCALLY_CONTROLLED", LUA_NATIVE_PED_IS_GROUP_LOCALLY_CONTROLLED);
		PED.set_function("GET_PED_GROUP_INDEX", LUA_NATIVE_PED_GET_PED_GROUP_INDEX);
		PED.set_function("IS_PED_IN_GROUP", LUA_NATIVE_PED_IS_PED_IN_GROUP);
		PED.set_function("_IS_PED_LEADING_ANY_GROUP", LUA_NATIVE_PED__IS_PED_LEADING_ANY_GROUP);
		PED.set_function("GET_PLAYER_PED_IS_FOLLOWING", LUA_NATIVE_PED_GET_PLAYER_PED_IS_FOLLOWING);
		PED.set_function("SET_GROUP_FORMATION", LUA_NATIVE_PED_SET_GROUP_FORMATION);
		PED.set_function("_GET_GROUP_FORMATION", LUA_NATIVE_PED__GET_GROUP_FORMATION);
		PED.set_function("SET_GROUP_FORMATION_SPACING", LUA_NATIVE_PED_SET_GROUP_FORMATION_SPACING);
		PED.set_function("RESET_GROUP_FORMATION_DEFAULT_SPACING", LUA_NATIVE_PED_RESET_GROUP_FORMATION_DEFAULT_SPACING);
		PED.set_function("_0xB05CC690CDE8A4A9", LUA_NATIVE_PED__0xB05CC690CDE8A4A9);
		PED.set_function("ADD_CUSTOM_FORMATION_LOCATION", LUA_NATIVE_PED_ADD_CUSTOM_FORMATION_LOCATION);
		PED.set_function("ADD_FORMATION_LOCATION", LUA_NATIVE_PED_ADD_FORMATION_LOCATION);
		PED.set_function("SET_FORMATION_POSITIONS_TARGET_RADIUS", LUA_NATIVE_PED_SET_FORMATION_POSITIONS_TARGET_RADIUS);
		PED.set_function("_SET_FORMATION_AUTO_ASSIGN_POSITION", LUA_NATIVE_PED__SET_FORMATION_AUTO_ASSIGN_POSITION);
		PED.set_function("_SET_PED_FORMATION_POSITION", LUA_NATIVE_PED__SET_PED_FORMATION_POSITION);
		PED.set_function("_0x8AF8E647D6B2A649", LUA_NATIVE_PED__0x8AF8E647D6B2A649);
		PED.set_function("_0x87C2724A56F66020", LUA_NATIVE_PED__0x87C2724A56F66020);
		PED.set_function("_0xD5BD1B5318A81994", LUA_NATIVE_PED__0xD5BD1B5318A81994);
		PED.set_function("_0x9BBEAF8B0C007F1E", LUA_NATIVE_PED__0x9BBEAF8B0C007F1E);
		PED.set_function("_0xC99F104BDF8C7F5A", LUA_NATIVE_PED__0xC99F104BDF8C7F5A);
		PED.set_function("_0x02E741E19E39628C", LUA_NATIVE_PED__0x02E741E19E39628C);
		PED.set_function("_0x97C475212B327666", LUA_NATIVE_PED__0x97C475212B327666);
		PED.set_function("_0x154B7E841AC7412F", LUA_NATIVE_PED__0x154B7E841AC7412F);
		PED.set_function("_0x8AFCCC0F18D70018", LUA_NATIVE_PED__0x8AFCCC0F18D70018);
		PED.set_function("_0xE1103300F3456DE7", LUA_NATIVE_PED__0xE1103300F3456DE7);
		PED.set_function("_0xA8A95CECB1906EA2", LUA_NATIVE_PED__0xA8A95CECB1906EA2);
		PED.set_function("_0xDDFAD4DEAA7FA362", LUA_NATIVE_PED__0xDDFAD4DEAA7FA362);
		PED.set_function("_0x966DE09688A1DE39", LUA_NATIVE_PED__0x966DE09688A1DE39);
		PED.set_function("_0x7E5185B979706210", LUA_NATIVE_PED__0x7E5185B979706210);
		PED.set_function("_0x40C3524D4ED83554", LUA_NATIVE_PED__0x40C3524D4ED83554);
		PED.set_function("_0x86FAFC18E3D4380C", LUA_NATIVE_PED__0x86FAFC18E3D4380C);
		PED.set_function("_0x07EA5B053FA60AC7", LUA_NATIVE_PED__0x07EA5B053FA60AC7);
		PED.set_function("_0xF9CBD46433E36713", LUA_NATIVE_PED__0xF9CBD46433E36713);
		PED.set_function("GET_VEHICLE_PED_IS_USING", LUA_NATIVE_PED_GET_VEHICLE_PED_IS_USING);
		PED.set_function("GET_VEHICLE_PED_IS_ENTERING", LUA_NATIVE_PED_GET_VEHICLE_PED_IS_ENTERING);
		PED.set_function("_GET_VEHICLE_DRAFT_HORSE_IS_ATTACHED_TO", LUA_NATIVE_PED__GET_VEHICLE_DRAFT_HORSE_IS_ATTACHED_TO);
		PED.set_function("_GET_LAST_VEHICLE_DRAFT_HORSE_WAS_ATTACHED_TO", LUA_NATIVE_PED__GET_LAST_VEHICLE_DRAFT_HORSE_WAS_ATTACHED_TO);
		PED.set_function("GET_SEAT_PED_IS_USING", LUA_NATIVE_PED_GET_SEAT_PED_IS_USING);
		PED.set_function("_GET_TRANSPORT_PED_IS_SEATED_ON", LUA_NATIVE_PED__GET_TRANSPORT_PED_IS_SEATED_ON);
		PED.set_function("IS_PED_ENTERING_ANY_TRANSPORT", LUA_NATIVE_PED_IS_PED_ENTERING_ANY_TRANSPORT);
		PED.set_function("SET_PED_GRAVITY", LUA_NATIVE_PED_SET_PED_GRAVITY);
		PED.set_function("_0x96595B36D6A2279B", LUA_NATIVE_PED__0x96595B36D6A2279B);
		PED.set_function("_SET_PED_IMMERSION_FLAG", LUA_NATIVE_PED__SET_PED_IMMERSION_FLAG);
		PED.set_function("_0xA90684ED185CCB4B", LUA_NATIVE_PED__0xA90684ED185CCB4B);
		PED.set_function("_FAKE_SET_PED_LOCO_INJURED", LUA_NATIVE_PED__FAKE_SET_PED_LOCO_INJURED);
		PED.set_function("_FORCE_PED_DEATH", LUA_NATIVE_PED__FORCE_PED_DEATH);
		PED.set_function("APPLY_DAMAGE_TO_PED", LUA_NATIVE_PED_APPLY_DAMAGE_TO_PED);
		PED.set_function("_0xBAD2A311667A50D7", LUA_NATIVE_PED__0xBAD2A311667A50D7);
		PED.set_function("GET_PED_TYPE", LUA_NATIVE_PED_GET_PED_TYPE);
		PED.set_function("SET_PED_AS_COP", LUA_NATIVE_PED_SET_PED_AS_COP);
		PED.set_function("_0x405180B14DA5A935", LUA_NATIVE_PED__0x405180B14DA5A935);
		PED.set_function("_SET_PED_INTERACTION_PERSONALITY", LUA_NATIVE_PED__SET_PED_INTERACTION_PERSONALITY);
		PED.set_function("_GET_PED_INTERACTION_PERSONALITY", LUA_NATIVE_PED__GET_PED_INTERACTION_PERSONALITY);
		PED.set_function("_SET_PED_PERSONALITY", LUA_NATIVE_PED__SET_PED_PERSONALITY);
		PED.set_function("_0x329772C47DBB2FBC", LUA_NATIVE_PED__0x329772C47DBB2FBC);
		PED.set_function("_GET_IS_PED_IN_DISPUTE_WITH_PED", LUA_NATIVE_PED__GET_IS_PED_IN_DISPUTE_WITH_PED);
		PED.set_function("_0x94132D7C8D3575C4", LUA_NATIVE_PED__0x94132D7C8D3575C4);
		PED.set_function("_0x8AF46E5159A5B620", LUA_NATIVE_PED__0x8AF46E5159A5B620);
		PED.set_function("_0x45FEA6D5539BD474", LUA_NATIVE_PED__0x45FEA6D5539BD474);
		PED.set_function("_SET_PED_INTERACTION_POSITIVE_RESPONSE", LUA_NATIVE_PED__SET_PED_INTERACTION_POSITIVE_RESPONSE);
		PED.set_function("_0xE37ACEE15AC50C7E", LUA_NATIVE_PED__0xE37ACEE15AC50C7E);
		PED.set_function("_SET_PED_INTERACTION_NEGATIVE_RESPONSE", LUA_NATIVE_PED__SET_PED_INTERACTION_NEGATIVE_RESPONSE);
		PED.set_function("_0x41C23A8E6B344867", LUA_NATIVE_PED__0x41C23A8E6B344867);
		PED.set_function("GET_IS_PED_RESPONDING_TO_POSITIVE_INTERACTION", LUA_NATIVE_PED_GET_IS_PED_RESPONDING_TO_POSITIVE_INTERACTION);
		PED.set_function("GET_IS_PED_RESPONDING_TO_NEGATIVE_INTERACTION", LUA_NATIVE_PED_GET_IS_PED_RESPONDING_TO_NEGATIVE_INTERACTION);
		PED.set_function("_0xA7DC9266ED6A4E51", LUA_NATIVE_PED__0xA7DC9266ED6A4E51);
		PED.set_function("_0x89816B58C3466262", LUA_NATIVE_PED__0x89816B58C3466262);
		PED.set_function("_0x97B06669AC569003", LUA_NATIVE_PED__0x97B06669AC569003);
		PED.set_function("_0x85F500F4E24CA43E", LUA_NATIVE_PED__0x85F500F4E24CA43E);
		PED.set_function("_0x9B9B9FA0EA283E3D", LUA_NATIVE_PED__0x9B9B9FA0EA283E3D);
		PED.set_function("_0xEC60D1D225BC50AA", LUA_NATIVE_PED__0xEC60D1D225BC50AA);
		PED.set_function("_0x12F2D161BF4031FC", LUA_NATIVE_PED__0x12F2D161BF4031FC);
		PED.set_function("_0x0ADA3EC589E1736E", LUA_NATIVE_PED__0x0ADA3EC589E1736E);
		PED.set_function("_GET_IS_PED_BEING_ROBBED", LUA_NATIVE_PED__GET_IS_PED_BEING_ROBBED);
		PED.set_function("_0xD55DB4466D00A258", LUA_NATIVE_PED__0xD55DB4466D00A258);
		PED.set_function("SET_PED_MAX_HEALTH", LUA_NATIVE_PED_SET_PED_MAX_HEALTH);
		PED.set_function("GET_PED_MAX_HEALTH", LUA_NATIVE_PED_GET_PED_MAX_HEALTH);
		PED.set_function("_SET_PED_HEALTH_CONFIG", LUA_NATIVE_PED__SET_PED_HEALTH_CONFIG);
		PED.set_function("INIT_PED_DEFAULT_HEALTH", LUA_NATIVE_PED_INIT_PED_DEFAULT_HEALTH);
		PED.set_function("SET_PED_MAX_TIME_IN_WATER", LUA_NATIVE_PED_SET_PED_MAX_TIME_IN_WATER);
		PED.set_function("SET_PED_MAX_TIME_UNDERWATER", LUA_NATIVE_PED_SET_PED_MAX_TIME_UNDERWATER);
		PED.set_function("_0xAF041C10756C30FB", LUA_NATIVE_PED__0xAF041C10756C30FB);
		PED.set_function("_0x5AF24CA9C974E51A", LUA_NATIVE_PED__0x5AF24CA9C974E51A);
		PED.set_function("SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE", LUA_NATIVE_PED_SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE);
		PED.set_function("CAN_KNOCK_PED_OFF_VEHICLE", LUA_NATIVE_PED_CAN_KNOCK_PED_OFF_VEHICLE);
		PED.set_function("KNOCK_PED_OFF_VEHICLE", LUA_NATIVE_PED_KNOCK_PED_OFF_VEHICLE);
		PED.set_function("GET_PED_AS_GROUP_MEMBER", LUA_NATIVE_PED_GET_PED_AS_GROUP_MEMBER);
		PED.set_function("GET_PED_AS_GROUP_LEADER", LUA_NATIVE_PED_GET_PED_AS_GROUP_LEADER);
		PED.set_function("SET_PED_KEEP_TASK", LUA_NATIVE_PED_SET_PED_KEEP_TASK);
		PED.set_function("IS_PED_SWIMMING", LUA_NATIVE_PED_IS_PED_SWIMMING);
		PED.set_function("IS_PED_SWIMMING_UNDER_WATER", LUA_NATIVE_PED_IS_PED_SWIMMING_UNDER_WATER);
		PED.set_function("_0xDC88D06719070C39", LUA_NATIVE_PED__0xDC88D06719070C39);
		PED.set_function("SET_CREATE_RANDOM_COPS", LUA_NATIVE_PED_SET_CREATE_RANDOM_COPS);
		PED.set_function("IS_PED_IN_ANY_TRAIN", LUA_NATIVE_PED_IS_PED_IN_ANY_TRAIN);
		PED.set_function("IS_PED_GETTING_INTO_A_VEHICLE", LUA_NATIVE_PED_IS_PED_GETTING_INTO_A_VEHICLE);
		PED.set_function("_0x550CB89DD7F4FA3D", LUA_NATIVE_PED__0x550CB89DD7F4FA3D);
		PED.set_function("SET_ENABLE_HANDCUFFS", LUA_NATIVE_PED_SET_ENABLE_HANDCUFFS);
		PED.set_function("SET_ENABLE_BOUND_ANKLES", LUA_NATIVE_PED_SET_ENABLE_BOUND_ANKLES);
		PED.set_function("_0x8822F139408B8D0A", LUA_NATIVE_PED__0x8822F139408B8D0A);
		PED.set_function("_0x8822F124788B8D0A", LUA_NATIVE_PED__0x8822F124788B8D0A);
		PED.set_function("RESET_PED_WEAPON_MOVEMENT_CLIPSET", LUA_NATIVE_PED_RESET_PED_WEAPON_MOVEMENT_CLIPSET);
		PED.set_function("_SET_PED_GETUP_ANIMATION", LUA_NATIVE_PED__SET_PED_GETUP_ANIMATION);
		PED.set_function("_0x88A95BB640FC186F", LUA_NATIVE_PED__0x88A95BB640FC186F);
		PED.set_function("RESET_PED_IN_VEHICLE_CONTEXT", LUA_NATIVE_PED_RESET_PED_IN_VEHICLE_CONTEXT);
		PED.set_function("_0x878E8104FA27CDAE", LUA_NATIVE_PED__0x878E8104FA27CDAE);
		PED.set_function("SET_PED_GESTURE_GROUP", LUA_NATIVE_PED_SET_PED_GESTURE_GROUP);
		PED.set_function("_SET_PED_DESIRED_LOCO_FOR_MODEL", LUA_NATIVE_PED__SET_PED_DESIRED_LOCO_FOR_MODEL);
		PED.set_function("_CLEAR_PED_DESIRED_LOCO_FOR_MODEL", LUA_NATIVE_PED__CLEAR_PED_DESIRED_LOCO_FOR_MODEL);
		PED.set_function("_SET_PED_DESIRED_LOCO_MOTION_TYPE", LUA_NATIVE_PED__SET_PED_DESIRED_LOCO_MOTION_TYPE);
		PED.set_function("_CLEAR_PED_DESIRED_LOCO_MOTION_TYPE", LUA_NATIVE_PED__CLEAR_PED_DESIRED_LOCO_MOTION_TYPE);
		PED.set_function("_0x2371C39D4F91C288", LUA_NATIVE_PED__0x2371C39D4F91C288);
		PED.set_function("_REQUEST_PED_GETUP_ANIMATION", LUA_NATIVE_PED__REQUEST_PED_GETUP_ANIMATION);
		PED.set_function("PED_COWER_IN_PLACE", LUA_NATIVE_PED_PED_COWER_IN_PLACE);
		PED.set_function("PED_COWER_MOVE_TO_POINT", LUA_NATIVE_PED_PED_COWER_MOVE_TO_POINT);
		PED.set_function("_0x16F798A05BB9E3B5", LUA_NATIVE_PED__0x16F798A05BB9E3B5);
		PED.set_function("_PED_EMOTIONAL_PRESET_LOCO_MOTION", LUA_NATIVE_PED__PED_EMOTIONAL_PRESET_LOCO_MOTION);
		PED.set_function("_PED_CLEAR_LOCO_MOTION", LUA_NATIVE_PED__PED_CLEAR_LOCO_MOTION);
		PED.set_function("_0x32CCAD8A981B53D3", LUA_NATIVE_PED__0x32CCAD8A981B53D3);
		PED.set_function("_SET_PED_DRUNKNESS", LUA_NATIVE_PED__SET_PED_DRUNKNESS);
		PED.set_function("_IS_PED_DRUNK", LUA_NATIVE_PED__IS_PED_DRUNK);
		PED.set_function("_GET_PED_DRUNKNESS", LUA_NATIVE_PED__GET_PED_DRUNKNESS);
		PED.set_function("GET_ANIM_INITIAL_OFFSET_POSITION", LUA_NATIVE_PED_GET_ANIM_INITIAL_OFFSET_POSITION);
		PED.set_function("GET_ANIM_INITIAL_OFFSET_ROTATION", LUA_NATIVE_PED_GET_ANIM_INITIAL_OFFSET_ROTATION);
		PED.set_function("SET_PED_RANDOM_COMPONENT_VARIATION", LUA_NATIVE_PED_SET_PED_RANDOM_COMPONENT_VARIATION);
		PED.set_function("KNOCK_OFF_PED_PROP", LUA_NATIVE_PED_KNOCK_OFF_PED_PROP);
		PED.set_function("SET_BLOCKING_OF_NON_TEMPORARY_EVENTS", LUA_NATIVE_PED_SET_BLOCKING_OF_NON_TEMPORARY_EVENTS);
		PED.set_function("_GET_BLOCKING_OF_NON_TEMPORARY_EVENTS", LUA_NATIVE_PED__GET_BLOCKING_OF_NON_TEMPORARY_EVENTS);
		PED.set_function("_0xC17A94CC8FC3C61A", LUA_NATIVE_PED__0xC17A94CC8FC3C61A);
		PED.set_function("_SET_PED_SCALE", LUA_NATIVE_PED__SET_PED_SCALE);
		PED.set_function("_0x134775B093AD5C38", LUA_NATIVE_PED__0x134775B093AD5C38);
		PED.set_function("_GET_PED_HEIGHT", LUA_NATIVE_PED__GET_PED_HEIGHT);
		PED.set_function("_GET_PED_MODEL_SIZE_FROM_HASH", LUA_NATIVE_PED__GET_PED_MODEL_SIZE_FROM_HASH);
		PED.set_function("REGISTER_TARGET", LUA_NATIVE_PED_REGISTER_TARGET);
		PED.set_function("_REGISTER_HATED_TARGETS_IN_AREA", LUA_NATIVE_PED__REGISTER_HATED_TARGETS_IN_AREA);
		PED.set_function("REGISTER_HATED_TARGETS_AROUND_PED", LUA_NATIVE_PED_REGISTER_HATED_TARGETS_AROUND_PED);
		PED.set_function("_IS_TARGET", LUA_NATIVE_PED__IS_TARGET);
		PED.set_function("_REMOVE_TARGET", LUA_NATIVE_PED__REMOVE_TARGET);
		PED.set_function("GET_CLOSEST_PED", LUA_NATIVE_PED_GET_CLOSEST_PED);
		PED.set_function("CAN_PED_RAGDOLL", LUA_NATIVE_PED_CAN_PED_RAGDOLL);
		PED.set_function("SET_PED_TO_RAGDOLL", LUA_NATIVE_PED_SET_PED_TO_RAGDOLL);
		PED.set_function("SET_PED_TO_RAGDOLL_WITH_FALL", LUA_NATIVE_PED_SET_PED_TO_RAGDOLL_WITH_FALL);
		PED.set_function("SET_PED_RAGDOLL_ON_COLLISION", LUA_NATIVE_PED_SET_PED_RAGDOLL_ON_COLLISION);
		PED.set_function("_SET_PED_TO_DISABLE_RAGDOLL", LUA_NATIVE_PED__SET_PED_TO_DISABLE_RAGDOLL);
		PED.set_function("IS_PED_RAGDOLL", LUA_NATIVE_PED_IS_PED_RAGDOLL);
		PED.set_function("IS_PED_RUNNING_RAGDOLL_TASK", LUA_NATIVE_PED_IS_PED_RUNNING_RAGDOLL_TASK);
		PED.set_function("SET_PED_RAGDOLL_FORCE_FALL", LUA_NATIVE_PED_SET_PED_RAGDOLL_FORCE_FALL);
		PED.set_function("_0x8CB2553C559102C1", LUA_NATIVE_PED__0x8CB2553C559102C1);
		PED.set_function("_0xFD3C31A2E45671E7", LUA_NATIVE_PED__0xFD3C31A2E45671E7);
		PED.set_function("RESET_PED_RAGDOLL_TIMER", LUA_NATIVE_PED_RESET_PED_RAGDOLL_TIMER);
		PED.set_function("SET_PED_CAN_RAGDOLL", LUA_NATIVE_PED_SET_PED_CAN_RAGDOLL);
		PED.set_function("_0x3AEC4A410ECAF30D", LUA_NATIVE_PED__0x3AEC4A410ECAF30D);
		PED.set_function("IS_PED_RUNNING_MOBILE_PHONE_TASK", LUA_NATIVE_PED_IS_PED_RUNNING_MOBILE_PHONE_TASK);
		PED.set_function("SET_RAGDOLL_BLOCKING_FLAGS", LUA_NATIVE_PED_SET_RAGDOLL_BLOCKING_FLAGS);
		PED.set_function("CLEAR_RAGDOLL_BLOCKING_FLAGS", LUA_NATIVE_PED_CLEAR_RAGDOLL_BLOCKING_FLAGS);
		PED.set_function("_0x9F933E0985E12C51", LUA_NATIVE_PED__0x9F933E0985E12C51);
		PED.set_function("_0x88B2026A3B0BE33D", LUA_NATIVE_PED__0x88B2026A3B0BE33D);
		PED.set_function("SET_PED_DEFENSIVE_AREA_VOLUME", LUA_NATIVE_PED_SET_PED_DEFENSIVE_AREA_VOLUME);
		PED.set_function("SET_PED_SPHERE_DEFENSIVE_AREA", LUA_NATIVE_PED_SET_PED_SPHERE_DEFENSIVE_AREA);
		PED.set_function("_SET_PED_DEFENSIVE_SPHERE_ATTACHED_TO_ENTITY", LUA_NATIVE_PED__SET_PED_DEFENSIVE_SPHERE_ATTACHED_TO_ENTITY);
		PED.set_function("_SET_PED_DEFENSIVE_AREA_TO_ANGLED_AREA", LUA_NATIVE_PED__SET_PED_DEFENSIVE_AREA_TO_ANGLED_AREA);
		PED.set_function("SET_PED_DEFENSIVE_AREA_DIRECTION", LUA_NATIVE_PED_SET_PED_DEFENSIVE_AREA_DIRECTION);
		PED.set_function("REMOVE_PED_DEFENSIVE_AREA", LUA_NATIVE_PED_REMOVE_PED_DEFENSIVE_AREA);
		PED.set_function("GET_PED_DEFENSIVE_AREA_POSITION", LUA_NATIVE_PED_GET_PED_DEFENSIVE_AREA_POSITION);
		PED.set_function("IS_PED_DEFENSIVE_AREA_ACTIVE", LUA_NATIVE_PED_IS_PED_DEFENSIVE_AREA_ACTIVE);
		PED.set_function("_GET_PED_DEFENSIVE_VOLUME", LUA_NATIVE_PED__GET_PED_DEFENSIVE_VOLUME);
		PED.set_function("_0x4EC4EA2F72B36358", LUA_NATIVE_PED__0x4EC4EA2F72B36358);
		PED.set_function("_0xCF0B19806473D324", LUA_NATIVE_PED__0xCF0B19806473D324);
		PED.set_function("_0xB4B7C92FCE7347B7", LUA_NATIVE_PED__0xB4B7C92FCE7347B7);
		PED.set_function("REVIVE_INJURED_PED", LUA_NATIVE_PED_REVIVE_INJURED_PED);
		PED.set_function("RESURRECT_PED", LUA_NATIVE_PED_RESURRECT_PED);
		PED.set_function("SET_PED_NAME_DEBUG", LUA_NATIVE_PED_SET_PED_NAME_DEBUG);
		PED.set_function("SPECIAL_FUNCTION_DO_NOT_USE", LUA_NATIVE_PED_SPECIAL_FUNCTION_DO_NOT_USE);
		PED.set_function("_0x7020839C7302D8AC", LUA_NATIVE_PED__0x7020839C7302D8AC);
		PED.set_function("_0xE1AADD0055D76603", LUA_NATIVE_PED__0xE1AADD0055D76603);
		PED.set_function("_0x5A1A929C8B729B4A", LUA_NATIVE_PED__0x5A1A929C8B729B4A);
		PED.set_function("_0x97A38B65EBDA3D50", LUA_NATIVE_PED__0x97A38B65EBDA3D50);
		PED.set_function("_0x06A10B4D7F50B0C3", LUA_NATIVE_PED__0x06A10B4D7F50B0C3);
		PED.set_function("_0x88A5564B19C15391", LUA_NATIVE_PED__0x88A5564B19C15391);
		PED.set_function("_0x354CA4DDDEEC397A", LUA_NATIVE_PED__0x354CA4DDDEEC397A);
		PED.set_function("_0xFEA6126C34DF2532", LUA_NATIVE_PED__0xFEA6126C34DF2532);
		PED.set_function("_0xA967D6A8ED2D713B", LUA_NATIVE_PED__0xA967D6A8ED2D713B);
		PED.set_function("APPLY_PED_BLOOD_SPECIFIC", LUA_NATIVE_PED_APPLY_PED_BLOOD_SPECIFIC);
		PED.set_function("_0x58D32261AE0F0843", LUA_NATIVE_PED__0x58D32261AE0F0843);
		PED.set_function("_0x735662994E60A710", LUA_NATIVE_PED__0x735662994E60A710);
		PED.set_function("_0x91BAB9E064F036CD", LUA_NATIVE_PED__0x91BAB9E064F036CD);
		PED.set_function("_0x897934E868EDDD6C", LUA_NATIVE_PED__0x897934E868EDDD6C);
		PED.set_function("_SET_PED_ACTIVATE_WOUND_EFFECT", LUA_NATIVE_PED__SET_PED_ACTIVATE_WOUND_EFFECT);
		PED.set_function("_UPDATE_PED_WOUND_EFFECT", LUA_NATIVE_PED__UPDATE_PED_WOUND_EFFECT);
		PED.set_function("APPLY_PED_DAMAGE_PACK", LUA_NATIVE_PED_APPLY_PED_DAMAGE_PACK);
		PED.set_function("CLEAR_PED_BLOOD_DAMAGE", LUA_NATIVE_PED_CLEAR_PED_BLOOD_DAMAGE);
		PED.set_function("CLEAR_PED_BLOOD_DAMAGE_BY_ZONE", LUA_NATIVE_PED_CLEAR_PED_BLOOD_DAMAGE_BY_ZONE);
		PED.set_function("CLEAR_PED_DAMAGE_DECAL_BY_ZONE", LUA_NATIVE_PED_CLEAR_PED_DAMAGE_DECAL_BY_ZONE);
		PED.set_function("_CLEAR_PED_BLOOD_DAMAGE_FACIAL", LUA_NATIVE_PED__CLEAR_PED_BLOOD_DAMAGE_FACIAL);
		PED.set_function("_0x34C11114887150FD", LUA_NATIVE_PED__0x34C11114887150FD);
		PED.set_function("_0xD8544F6260F5F01E", LUA_NATIVE_PED__0xD8544F6260F5F01E);
		PED.set_function("_0xEB8886E1065654CD", LUA_NATIVE_PED__0xEB8886E1065654CD);
		PED.set_function("FADE_AND_DESTROY_PED", LUA_NATIVE_PED_FADE_AND_DESTROY_PED);
		PED.set_function("_IS_PED_QUEUED_FOR_DELETION", LUA_NATIVE_PED__IS_PED_QUEUED_FOR_DELETION);
		PED.set_function("CLEAR_PED_WETNESS", LUA_NATIVE_PED_CLEAR_PED_WETNESS);
		PED.set_function("SET_PED_WETNESS_HEIGHT", LUA_NATIVE_PED_SET_PED_WETNESS_HEIGHT);
		PED.set_function("_0xF9CFF5BB70E8A2CB", LUA_NATIVE_PED__0xF9CFF5BB70E8A2CB);
		PED.set_function("SET_PED_WETNESS_ENABLED_THIS_FRAME", LUA_NATIVE_PED_SET_PED_WETNESS_ENABLED_THIS_FRAME);
		PED.set_function("_0xA7A806677F8DE138", LUA_NATIVE_PED__0xA7A806677F8DE138);
		PED.set_function("_0xA064BBABB064446F", LUA_NATIVE_PED__0xA064BBABB064446F);
		PED.set_function("CLEAR_PED_ENV_DIRT", LUA_NATIVE_PED_CLEAR_PED_ENV_DIRT);
		PED.set_function("SET_PED_SWEAT", LUA_NATIVE_PED_SET_PED_SWEAT);
		PED.set_function("CLEAR_PED_DECORATIONS", LUA_NATIVE_PED_CLEAR_PED_DECORATIONS);
		PED.set_function("WAS_PED_SKELETON_UPDATED", LUA_NATIVE_PED_WAS_PED_SKELETON_UPDATED);
		PED.set_function("GET_PED_BONE_COORDS", LUA_NATIVE_PED_GET_PED_BONE_COORDS);
		PED.set_function("ADD_SCENARIO_BLOCKING_AREA", LUA_NATIVE_PED_ADD_SCENARIO_BLOCKING_AREA);
		PED.set_function("REMOVE_SCENARIO_BLOCKING_AREAS", LUA_NATIVE_PED_REMOVE_SCENARIO_BLOCKING_AREAS);
		PED.set_function("REMOVE_SCENARIO_BLOCKING_AREA", LUA_NATIVE_PED_REMOVE_SCENARIO_BLOCKING_AREA);
		PED.set_function("_ADD_SCENARIO_BLOCKING_VOLUME", LUA_NATIVE_PED__ADD_SCENARIO_BLOCKING_VOLUME);
		PED.set_function("_0x6F46F8ACB44C4FC1", LUA_NATIVE_PED__0x6F46F8ACB44C4FC1);
		PED.set_function("_IS_SCENARIO_BLOCKING_AREA_VALID", LUA_NATIVE_PED__IS_SCENARIO_BLOCKING_AREA_VALID);
		PED.set_function("IS_PED_USING_SCENARIO_HASH", LUA_NATIVE_PED_IS_PED_USING_SCENARIO_HASH);
		PED.set_function("IS_PED_USING_ANY_SCENARIO", LUA_NATIVE_PED_IS_PED_USING_ANY_SCENARIO);
		PED.set_function("IS_PED_USING_THIS_SCENARIO", LUA_NATIVE_PED_IS_PED_USING_THIS_SCENARIO);
		PED.set_function("_CAN_PED_USE_SCENARIO_POINT", LUA_NATIVE_PED__CAN_PED_USE_SCENARIO_POINT);
		PED.set_function("_0x1148F706CF4EBDDA", LUA_NATIVE_PED__0x1148F706CF4EBDDA);
		PED.set_function("SET_PED_PANIC_EXIT_SCENARIO", LUA_NATIVE_PED_SET_PED_PANIC_EXIT_SCENARIO);
		PED.set_function("TOGGLE_SCENARIO_PED_COWER_IN_PLACE", LUA_NATIVE_PED_TOGGLE_SCENARIO_PED_COWER_IN_PLACE);
		PED.set_function("_0xD8CEEED54C672B5D", LUA_NATIVE_PED__0xD8CEEED54C672B5D);
		PED.set_function("SET_PED_SHOULD_PLAY_DIRECTED_NORMAL_SCENARIO_EXIT", LUA_NATIVE_PED_SET_PED_SHOULD_PLAY_DIRECTED_NORMAL_SCENARIO_EXIT);
		PED.set_function("SET_PED_SHOULD_PLAY_NORMAL_SCENARIO_EXIT", LUA_NATIVE_PED_SET_PED_SHOULD_PLAY_NORMAL_SCENARIO_EXIT);
		PED.set_function("SET_PED_SHOULD_PLAY_IMMEDIATE_SCENARIO_EXIT", LUA_NATIVE_PED_SET_PED_SHOULD_PLAY_IMMEDIATE_SCENARIO_EXIT);
		PED.set_function("SET_PED_SHOULD_PLAY_FLEE_SCENARIO_EXIT", LUA_NATIVE_PED_SET_PED_SHOULD_PLAY_FLEE_SCENARIO_EXIT);
		PED.set_function("SET_PED_SHOULD_PLAY_COMBAT_SCENARIO_EXIT", LUA_NATIVE_PED_SET_PED_SHOULD_PLAY_COMBAT_SCENARIO_EXIT);
		PED.set_function("SET_PED_SHOULD_PLAY_EMOTIONAL_SCENARIO_EXIT", LUA_NATIVE_PED_SET_PED_SHOULD_PLAY_EMOTIONAL_SCENARIO_EXIT);
		PED.set_function("SET_PED_SHOULD_PLAY_QUICK_SCENARIO_EXIT", LUA_NATIVE_PED_SET_PED_SHOULD_PLAY_QUICK_SCENARIO_EXIT);
		PED.set_function("_0xF9331B3A314EB49D", LUA_NATIVE_PED__0xF9331B3A314EB49D);
		PED.set_function("_0xE735A7DA22E88359", LUA_NATIVE_PED__0xE735A7DA22E88359);
		PED.set_function("_0x82CB0F3F0C7785E5", LUA_NATIVE_PED__0x82CB0F3F0C7785E5);
		PED.set_function("_0xCA95C156C14B2054", LUA_NATIVE_PED__0xCA95C156C14B2054);
		PED.set_function("SET_FACIAL_IDLE_ANIM_OVERRIDE", LUA_NATIVE_PED_SET_FACIAL_IDLE_ANIM_OVERRIDE);
		PED.set_function("CLEAR_FACIAL_IDLE_ANIM_OVERRIDE", LUA_NATIVE_PED_CLEAR_FACIAL_IDLE_ANIM_OVERRIDE);
		PED.set_function("_REQUEST_PED_FACIAL_MOOD_THIS_FRAME", LUA_NATIVE_PED__REQUEST_PED_FACIAL_MOOD_THIS_FRAME);
		PED.set_function("_0xD2F0FE8805D91647", LUA_NATIVE_PED__0xD2F0FE8805D91647);
		PED.set_function("SET_PED_CAN_PLAY_GESTURE_ANIMS", LUA_NATIVE_PED_SET_PED_CAN_PLAY_GESTURE_ANIMS);
		PED.set_function("_0x7EDB3C766B0D073F", LUA_NATIVE_PED__0x7EDB3C766B0D073F);
		PED.set_function("SET_PED_CAN_PLAY_AMBIENT_ANIMS", LUA_NATIVE_PED_SET_PED_CAN_PLAY_AMBIENT_ANIMS);
		PED.set_function("SET_PED_CAN_PLAY_AMBIENT_BASE_ANIMS", LUA_NATIVE_PED_SET_PED_CAN_PLAY_AMBIENT_BASE_ANIMS);
		PED.set_function("_0x4F63433CE3C08230", LUA_NATIVE_PED__0x4F63433CE3C08230);
		PED.set_function("SET_PED_CAN_ARM_IK", LUA_NATIVE_PED_SET_PED_CAN_ARM_IK);
		PED.set_function("_SET_PED_CAN_UNK_BODYPART_IK", LUA_NATIVE_PED__SET_PED_CAN_UNK_BODYPART_IK);
		PED.set_function("SET_PED_CAN_HEAD_IK", LUA_NATIVE_PED_SET_PED_CAN_HEAD_IK);
		PED.set_function("SET_PED_CAN_LEG_IK", LUA_NATIVE_PED_SET_PED_CAN_LEG_IK);
		PED.set_function("SET_PED_CAN_TORSO_IK", LUA_NATIVE_PED_SET_PED_CAN_TORSO_IK);
		PED.set_function("SET_PED_CAN_TORSO_REACT_IK", LUA_NATIVE_PED_SET_PED_CAN_TORSO_REACT_IK);
		PED.set_function("SET_PED_CAN_TORSO_VEHICLE_IK", LUA_NATIVE_PED_SET_PED_CAN_TORSO_VEHICLE_IK);
		PED.set_function("SET_PED_CAN_USE_AUTO_CONVERSATION_LOOKAT", LUA_NATIVE_PED_SET_PED_CAN_USE_AUTO_CONVERSATION_LOOKAT);
		PED.set_function("IS_PED_HEADTRACKING_PED", LUA_NATIVE_PED_IS_PED_HEADTRACKING_PED);
		PED.set_function("IS_PED_HEADTRACKING_ENTITY", LUA_NATIVE_PED_IS_PED_HEADTRACKING_ENTITY);
		PED.set_function("_DISABLE_AMBIENT_LOOK_AT_REQUESTS", LUA_NATIVE_PED__DISABLE_AMBIENT_LOOK_AT_REQUESTS);
		PED.set_function("_DISABLE_ALL_LOOK_AT_REQUESTS", LUA_NATIVE_PED__DISABLE_ALL_LOOK_AT_REQUESTS);
		PED.set_function("_0xCD9E5F94A2F38683", LUA_NATIVE_PED__0xCD9E5F94A2F38683);
		PED.set_function("SET_PED_CLOTH_PIN_FRAMES", LUA_NATIVE_PED_SET_PED_CLOTH_PIN_FRAMES);
		PED.set_function("_0x1D4636C90BBEFACB", LUA_NATIVE_PED__0x1D4636C90BBEFACB);
		PED.set_function("_0xEF371232BC6053E1", LUA_NATIVE_PED__0xEF371232BC6053E1);
		PED.set_function("_0x86F0B6730C32AC14", LUA_NATIVE_PED__0x86F0B6730C32AC14);
		PED.set_function("_0x8101BA1C0B462412", LUA_NATIVE_PED__0x8101BA1C0B462412);
		PED.set_function("SET_PED_CONFIG_FLAG", LUA_NATIVE_PED_SET_PED_CONFIG_FLAG);
		PED.set_function("SET_PED_RESET_FLAG", LUA_NATIVE_PED_SET_PED_RESET_FLAG);
		PED.set_function("GET_PED_CONFIG_FLAG", LUA_NATIVE_PED_GET_PED_CONFIG_FLAG);
		PED.set_function("GET_PED_RESET_FLAG", LUA_NATIVE_PED_GET_PED_RESET_FLAG);
		PED.set_function("_0xC6981AFF6D2A71C2", LUA_NATIVE_PED__0xC6981AFF6D2A71C2);
		PED.set_function("_0xE0FE107AB174D64A", LUA_NATIVE_PED__0xE0FE107AB174D64A);
		PED.set_function("SET_PED_GROUP_MEMBER_PASSENGER_INDEX", LUA_NATIVE_PED_SET_PED_GROUP_MEMBER_PASSENGER_INDEX);
		PED.set_function("IS_PED_EVASIVE_DIVING", LUA_NATIVE_PED_IS_PED_EVASIVE_DIVING);
		PED.set_function("_SHOOT_TRIGGER_AT_COORDS", LUA_NATIVE_PED__SHOOT_TRIGGER_AT_COORDS);
		PED.set_function("_IS_THIS_MODEL_A_HORSE", LUA_NATIVE_PED__IS_THIS_MODEL_A_HORSE);
		PED.set_function("SET_PED_MODEL_IS_SUPPRESSED", LUA_NATIVE_PED_SET_PED_MODEL_IS_SUPPRESSED);
		PED.set_function("_IS_PED_MODEL_SUPPRESSED", LUA_NATIVE_PED__IS_PED_MODEL_SUPPRESSED);
		PED.set_function("_0x7ABBD9E449E0DB00", LUA_NATIVE_PED__0x7ABBD9E449E0DB00);
		PED.set_function("_SET_PED_DISABLE_KICK_MOVE", LUA_NATIVE_PED__SET_PED_DISABLE_KICK_MOVE);
		PED.set_function("SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT", LUA_NATIVE_PED_SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT);
		PED.set_function("_0xE6CB36F43A95D75F", LUA_NATIVE_PED__0xE6CB36F43A95D75F);
		PED.set_function("SET_PED_LEG_IK_MODE", LUA_NATIVE_PED_SET_PED_LEG_IK_MODE);
		PED.set_function("_IS_PED_IN_POINT", LUA_NATIVE_PED__IS_PED_IN_POINT);
		PED.set_function("_SET_PED_CAN_BE_LASSOED", LUA_NATIVE_PED__SET_PED_CAN_BE_LASSOED);
		PED.set_function("SET_PED_COMBAT_MOVEMENT", LUA_NATIVE_PED_SET_PED_COMBAT_MOVEMENT);
		PED.set_function("GET_PED_COMBAT_MOVEMENT", LUA_NATIVE_PED_GET_PED_COMBAT_MOVEMENT);
		PED.set_function("_0x815C0074A1BC0D93", LUA_NATIVE_PED__0x815C0074A1BC0D93);
		PED.set_function("_0xFFDE295662405B25", LUA_NATIVE_PED__0xFFDE295662405B25);
		PED.set_function("SET_PED_COMBAT_ABILITY", LUA_NATIVE_PED_SET_PED_COMBAT_ABILITY);
		PED.set_function("SET_PED_COMBAT_RANGE", LUA_NATIVE_PED_SET_PED_COMBAT_RANGE);
		PED.set_function("SET_PED_COMBAT_ATTRIBUTES", LUA_NATIVE_PED_SET_PED_COMBAT_ATTRIBUTES);
		PED.set_function("_GET_PED_COMBAT_ATTRIBUTE", LUA_NATIVE_PED__GET_PED_COMBAT_ATTRIBUTE);
		PED.set_function("_SET_PED_COMBAT_ATTRIBUTE_HASH", LUA_NATIVE_PED__SET_PED_COMBAT_ATTRIBUTE_HASH);
		PED.set_function("SET_PED_TARGET_LOSS_RESPONSE", LUA_NATIVE_PED_SET_PED_TARGET_LOSS_RESPONSE);
		PED.set_function("_0x0A4618FFD517E24D", LUA_NATIVE_PED__0x0A4618FFD517E24D);
		PED.set_function("_0x712B2C2B2471B493", LUA_NATIVE_PED__0x712B2C2B2471B493);
		PED.set_function("_0x00B380FF2DF6AB7A", LUA_NATIVE_PED__0x00B380FF2DF6AB7A);
		PED.set_function("_SET_PED_COMBAT_STYLE", LUA_NATIVE_PED__SET_PED_COMBAT_STYLE);
		PED.set_function("_CLEAR_PED_COMBAT_STYLE", LUA_NATIVE_PED__CLEAR_PED_COMBAT_STYLE);
		PED.set_function("_SET_PED_COMBAT_STYLE_MOD", LUA_NATIVE_PED__SET_PED_COMBAT_STYLE_MOD);
		PED.set_function("_CLEAR_PED_COMBAT_STYLE_MOD", LUA_NATIVE_PED__CLEAR_PED_COMBAT_STYLE_MOD);
		PED.set_function("_0x5BF0B9D9A8E227A0", LUA_NATIVE_PED__0x5BF0B9D9A8E227A0);
		PED.set_function("_0x642720D8D69328B6", LUA_NATIVE_PED__0x642720D8D69328B6);
		PED.set_function("IS_PED_PERFORMING_MELEE_ACTION", LUA_NATIVE_PED_IS_PED_PERFORMING_MELEE_ACTION);
		PED.set_function("_0x99DF2639DA76C1DC", LUA_NATIVE_PED__0x99DF2639DA76C1DC);
		PED.set_function("_GET_PED_MELEE_ACTION_PHASE", LUA_NATIVE_PED__GET_PED_MELEE_ACTION_PHASE);
		PED.set_function("IS_PED_BEING_STEALTH_KILLED", LUA_NATIVE_PED_IS_PED_BEING_STEALTH_KILLED);
		PED.set_function("GET_MELEE_TARGET_FOR_PED", LUA_NATIVE_PED_GET_MELEE_TARGET_FOR_PED);
		PED.set_function("_0xDEDBED3020DA49DC", LUA_NATIVE_PED__0xDEDBED3020DA49DC);
		PED.set_function("_0xA405BF9F01960C16", LUA_NATIVE_PED__0xA405BF9F01960C16);
		PED.set_function("_GET_PED_BRAWLING_STYLE", LUA_NATIVE_PED__GET_PED_BRAWLING_STYLE);
		PED.set_function("_SET_PED_BRAWLING_STYLE", LUA_NATIVE_PED__SET_PED_BRAWLING_STYLE);
		PED.set_function("_0x9D8DFE2DE9CB4DFC", LUA_NATIVE_PED__0x9D8DFE2DE9CB4DFC);
		PED.set_function("_0xC48AF420371C7407", LUA_NATIVE_PED__0xC48AF420371C7407);
		PED.set_function("_0x5EFA8A3D8A60D662", LUA_NATIVE_PED__0x5EFA8A3D8A60D662);
		PED.set_function("_0x242EDF85D4E87B65", LUA_NATIVE_PED__0x242EDF85D4E87B65);
		PED.set_function("_SET_PED_COMBAT_BEHAVIOUR", LUA_NATIVE_PED__SET_PED_COMBAT_BEHAVIOUR);
		PED.set_function("_0x9A4AC116CC1EEE14", LUA_NATIVE_PED__0x9A4AC116CC1EEE14);
		PED.set_function("_0xE20027B414BFE6C7", LUA_NATIVE_PED__0xE20027B414BFE6C7);
		PED.set_function("_SET_PED_BEAT_MULTIPLIER", LUA_NATIVE_PED__SET_PED_BEAT_MULTIPLIER);
		PED.set_function("_SET_PED_ACTION_DISABLE_FLAG", LUA_NATIVE_PED__SET_PED_ACTION_DISABLE_FLAG);
		PED.set_function("_CLEAR_PED_ACTION_DISABLE_FLAG", LUA_NATIVE_PED__CLEAR_PED_ACTION_DISABLE_FLAG);
		PED.set_function("_IS_PED_ACTION_DISABLE_FLAG_ENABLED", LUA_NATIVE_PED__IS_PED_ACTION_DISABLE_FLAG_ENABLED);
		PED.set_function("_SET_PED_TARGET_ACTION_DISABLE_FLAG", LUA_NATIVE_PED__SET_PED_TARGET_ACTION_DISABLE_FLAG);
		PED.set_function("_CLEAR_PED_TARGET_ACTION_DISABLE_FLAG", LUA_NATIVE_PED__CLEAR_PED_TARGET_ACTION_DISABLE_FLAG);
		PED.set_function("_IS_PED_TARGET_ACTION_DISABLE_FLAG_ENABLED", LUA_NATIVE_PED__IS_PED_TARGET_ACTION_DISABLE_FLAG_ENABLED);
		PED.set_function("_0x57F35552E771BE9D", LUA_NATIVE_PED__0x57F35552E771BE9D);
		PED.set_function("_0x7C10221CE718AA72", LUA_NATIVE_PED__0x7C10221CE718AA72);
		PED.set_function("_0x0D3B1568917EBDA0", LUA_NATIVE_PED__0x0D3B1568917EBDA0);
		PED.set_function("_0x29F3539189D3E277", LUA_NATIVE_PED__0x29F3539189D3E277);
		PED.set_function("_0xE9E06EA514A69061", LUA_NATIVE_PED__0xE9E06EA514A69061);
		PED.set_function("_SET_PED_WRITHING_DURATION", LUA_NATIVE_PED__SET_PED_WRITHING_DURATION);
		PED.set_function("_GET_PED_REMAINING_REVIVAL_TIME", LUA_NATIVE_PED__GET_PED_REMAINING_REVIVAL_TIME);
		PED.set_function("SET_PAUSE_PED_WRITHE_BLEEDOUT", LUA_NATIVE_PED_SET_PAUSE_PED_WRITHE_BLEEDOUT);
		PED.set_function("_0x12EB4E31F092C9B3", LUA_NATIVE_PED__0x12EB4E31F092C9B3);
		PED.set_function("GET_PED_IS_GRAPPLING", LUA_NATIVE_PED_GET_PED_IS_GRAPPLING);
		PED.set_function("GET_PED_IS_BEING_GRAPPLED", LUA_NATIVE_PED_GET_PED_IS_BEING_GRAPPLED);
		PED.set_function("_GET_PED_GRAPPLER", LUA_NATIVE_PED__GET_PED_GRAPPLER);
		PED.set_function("GET_PED_GRAPPLE_STATE", LUA_NATIVE_PED_GET_PED_GRAPPLE_STATE);
		PED.set_function("_GET_PED_GRAPPLE_STYLE", LUA_NATIVE_PED__GET_PED_GRAPPLE_STYLE);
		PED.set_function("_SET_PED_GRAPPLE_STYLE", LUA_NATIVE_PED__SET_PED_GRAPPLE_STYLE);
		PED.set_function("_SET_PED_GRAPPLE_SEQUENCE", LUA_NATIVE_PED__SET_PED_GRAPPLE_SEQUENCE);
		PED.set_function("_SET_PED_GRAPPLE_FLAG", LUA_NATIVE_PED__SET_PED_GRAPPLE_FLAG);
		PED.set_function("_CLEAR_PED_GRAPPLE_FLAG", LUA_NATIVE_PED__CLEAR_PED_GRAPPLE_FLAG);
		PED.set_function("_GET_PED_GRAPPLE_FLAG", LUA_NATIVE_PED__GET_PED_GRAPPLE_FLAG);
		PED.set_function("_SET_PED_GRAPPLE_ACTION", LUA_NATIVE_PED__SET_PED_GRAPPLE_ACTION);
		PED.set_function("_SET_PED_GRAPPLE_EFFECT_MULTIPLIER", LUA_NATIVE_PED__SET_PED_GRAPPLE_EFFECT_MULTIPLIER);
		PED.set_function("_SET_PED_GRAPPLE_ANIMATION", LUA_NATIVE_PED__SET_PED_GRAPPLE_ANIMATION);
		PED.set_function("SET_PED_FLEE_ATTRIBUTES", LUA_NATIVE_PED_SET_PED_FLEE_ATTRIBUTES);
		PED.set_function("_IS_PED_COWERING", LUA_NATIVE_PED__IS_PED_COWERING);
		PED.set_function("IS_ANY_PED_NEAR_POINT", LUA_NATIVE_PED_IS_ANY_PED_NEAR_POINT);
		PED.set_function("FORCE_PED_AI_AND_ANIMATION_UPDATE", LUA_NATIVE_PED_FORCE_PED_AI_AND_ANIMATION_UPDATE);
		PED.set_function("_0xC2722B252C79E641", LUA_NATIVE_PED__0xC2722B252C79E641);
		PED.set_function("_IS_PED_DOING_SCENARIO_TRANSITION", LUA_NATIVE_PED__IS_PED_DOING_SCENARIO_TRANSITION);
		PED.set_function("_0x2DC0E8DCBD3546E9", LUA_NATIVE_PED__0x2DC0E8DCBD3546E9);
		PED.set_function("_ADD_SCENARIO_TRANSITION", LUA_NATIVE_PED__ADD_SCENARIO_TRANSITION);
		PED.set_function("_GIVE_PED_HASH_COMMAND", LUA_NATIVE_PED__GIVE_PED_HASH_COMMAND);
		PED.set_function("_GET_IS_PED_COMMAND_HASH_PRESENT", LUA_NATIVE_PED__GET_IS_PED_COMMAND_HASH_PRESENT);
		PED.set_function("IS_PED_HEADING_TOWARDS_POSITION", LUA_NATIVE_PED_IS_PED_HEADING_TOWARDS_POSITION);
		PED.set_function("_0x600BBDD29820370C", LUA_NATIVE_PED__0x600BBDD29820370C);
		PED.set_function("REQUEST_PED_VISIBILITY_TRACKING", LUA_NATIVE_PED_REQUEST_PED_VISIBILITY_TRACKING);
		PED.set_function("RELEASE_PED_VISIBILITY_TRACKING", LUA_NATIVE_PED_RELEASE_PED_VISIBILITY_TRACKING);
		PED.set_function("REQUEST_PED_VEHICLE_VISIBILITY_TRACKING", LUA_NATIVE_PED_REQUEST_PED_VEHICLE_VISIBILITY_TRACKING);
		PED.set_function("REQUEST_PED_USE_SMALL_BBOX_VISIBILITY_TRACKING", LUA_NATIVE_PED_REQUEST_PED_USE_SMALL_BBOX_VISIBILITY_TRACKING);
		PED.set_function("GET_TRACKED_PED_PIXELCOUNT", LUA_NATIVE_PED_GET_TRACKED_PED_PIXELCOUNT);
		PED.set_function("IS_TRACKED_PED_VISIBLE", LUA_NATIVE_PED_IS_TRACKED_PED_VISIBLE);
		PED.set_function("_IS_TRACKED_PED_VISIBILITY_PERCENTAGE_NOT_LESS_THAN", LUA_NATIVE_PED__IS_TRACKED_PED_VISIBILITY_PERCENTAGE_NOT_LESS_THAN);
		PED.set_function("_IS_PED_VISIBILITY_TRACKED", LUA_NATIVE_PED__IS_PED_VISIBILITY_TRACKED);
		PED.set_function("CAN_PED_BE_MOUNTED", LUA_NATIVE_PED_CAN_PED_BE_MOUNTED);
		PED.set_function("_IS_META_PED_FISH", LUA_NATIVE_PED__IS_META_PED_FISH);
		PED.set_function("IS_EVENT_IN_QUEUE", LUA_NATIVE_PED_IS_EVENT_IN_QUEUE);
		PED.set_function("CAN_PED_SEE_ENTITY", LUA_NATIVE_PED_CAN_PED_SEE_ENTITY);
		PED.set_function("CAN_PED_SEE_PED_CACHED", LUA_NATIVE_PED_CAN_PED_SEE_PED_CACHED);
		PED.set_function("_0x0EA9EACBA3B01601", LUA_NATIVE_PED__0x0EA9EACBA3B01601);
		PED.set_function("GET_PED_BONE_INDEX", LUA_NATIVE_PED_GET_PED_BONE_INDEX);
		PED.set_function("_0xC5303F460A40D21D", LUA_NATIVE_PED__0xC5303F460A40D21D);
		PED.set_function("_0xE29D8CD66553DBAA", LUA_NATIVE_PED__0xE29D8CD66553DBAA);
		PED.set_function("_0xB06F5F1DEF417216", LUA_NATIVE_PED__0xB06F5F1DEF417216);
		PED.set_function("_0xFC23348F0F4E245F", LUA_NATIVE_PED__0xFC23348F0F4E245F);
		PED.set_function("_0x9184788BFF1EDAD7", LUA_NATIVE_PED__0x9184788BFF1EDAD7);
		PED.set_function("_SET_PED_DIRT_CLEANED", LUA_NATIVE_PED__SET_PED_DIRT_CLEANED);
		PED.set_function("_0x0105FEE8F9091255", LUA_NATIVE_PED__0x0105FEE8F9091255);
		PED.set_function("_0xD049920CD29F6CC8", LUA_NATIVE_PED__0xD049920CD29F6CC8);
		PED.set_function("_0xBB3E5370EBB6BE28", LUA_NATIVE_PED__0xBB3E5370EBB6BE28);
		PED.set_function("_0x2FA568BFA725F8D6", LUA_NATIVE_PED__0x2FA568BFA725F8D6);
		PED.set_function("_0x56E4BAD93D33453C", LUA_NATIVE_PED__0x56E4BAD93D33453C);
		PED.set_function("_0x75A082563B4452E5", LUA_NATIVE_PED__0x75A082563B4452E5);
		PED.set_function("_0x16802C32B2FCA06B", LUA_NATIVE_PED__0x16802C32B2FCA06B);
		PED.set_function("_0x8BA0C65AC15A7D33", LUA_NATIVE_PED__0x8BA0C65AC15A7D33);
		PED.set_function("_0x0FFDF937E5C11382", LUA_NATIVE_PED__0x0FFDF937E5C11382);
		PED.set_function("_0x5FCF25D584065BFD", LUA_NATIVE_PED__0x5FCF25D584065BFD);
		PED.set_function("_0xA2116C1E4ED85C24", LUA_NATIVE_PED__0xA2116C1E4ED85C24);
		PED.set_function("FORCE_PED_MOTION_STATE", LUA_NATIVE_PED_FORCE_PED_MOTION_STATE);
		PED.set_function("_0x75D3333409CD33CE", LUA_NATIVE_PED__0x75D3333409CD33CE);
		PED.set_function("GET_PED_CURRENT_MOVE_BLEND_RATIO", LUA_NATIVE_PED_GET_PED_CURRENT_MOVE_BLEND_RATIO);
		PED.set_function("SET_PED_MAX_MOVE_BLEND_RATIO", LUA_NATIVE_PED_SET_PED_MAX_MOVE_BLEND_RATIO);
		PED.set_function("SET_PED_MIN_MOVE_BLEND_RATIO", LUA_NATIVE_PED_SET_PED_MIN_MOVE_BLEND_RATIO);
		PED.set_function("_0xBC1DC48270468444", LUA_NATIVE_PED__0xBC1DC48270468444);
		PED.set_function("_0x46BF2A810679D6E6", LUA_NATIVE_PED__0x46BF2A810679D6E6);
		PED.set_function("_0xCA95924C893A0C91", LUA_NATIVE_PED__0xCA95924C893A0C91);
		PED.set_function("_HORSE_AGITATE", LUA_NATIVE_PED__HORSE_AGITATE);
		PED.set_function("_0x413697EC260AABBF", LUA_NATIVE_PED__0x413697EC260AABBF);
		PED.set_function("_0xCAC43D060099EA72", LUA_NATIVE_PED__0xCAC43D060099EA72);
		PED.set_function("_0xC9151483CC06A414", LUA_NATIVE_PED__0xC9151483CC06A414);
		PED.set_function("_0xAD3330E3C3E98007", LUA_NATIVE_PED__0xAD3330E3C3E98007);
		PED.set_function("_0xB8E2D655E1D5BD39", LUA_NATIVE_PED__0xB8E2D655E1D5BD39);
		PED.set_function("_0x7BB810E8B343AC7B", LUA_NATIVE_PED__0x7BB810E8B343AC7B);
		PED.set_function("SET_PED_MOVE_RATE_OVERRIDE", LUA_NATIVE_PED_SET_PED_MOVE_RATE_OVERRIDE);
		PED.set_function("GET_PED_NEARBY_VEHICLES", LUA_NATIVE_PED_GET_PED_NEARBY_VEHICLES);
		PED.set_function("GET_PED_NEARBY_PEDS", LUA_NATIVE_PED_GET_PED_NEARBY_PEDS);
		PED.set_function("IS_PED_READY_TO_RENDER", LUA_NATIVE_PED_IS_PED_READY_TO_RENDER);
		PED.set_function("_0x6A489892E813951A", LUA_NATIVE_PED__0x6A489892E813951A);
		PED.set_function("IS_PED_USING_ACTION_MODE", LUA_NATIVE_PED_IS_PED_USING_ACTION_MODE);
		PED.set_function("_IS_PED_USING_ACTION_MODE_2", LUA_NATIVE_PED__IS_PED_USING_ACTION_MODE_2);
		PED.set_function("SET_PED_USING_ACTION_MODE", LUA_NATIVE_PED_SET_PED_USING_ACTION_MODE);
		PED.set_function("SET_PED_CAPSULE", LUA_NATIVE_PED_SET_PED_CAPSULE);
		PED.set_function("_GET_RIDER_OF_MOUNT", LUA_NATIVE_PED__GET_RIDER_OF_MOUNT);
		PED.set_function("SPAWNPOINTS_START_SEARCH", LUA_NATIVE_PED_SPAWNPOINTS_START_SEARCH);
		PED.set_function("SPAWNPOINTS_START_SEARCH_IN_ANGLED_AREA", LUA_NATIVE_PED_SPAWNPOINTS_START_SEARCH_IN_ANGLED_AREA);
		PED.set_function("_SPAWNPOINTS_START_SEARCH_WITH_VOLUME", LUA_NATIVE_PED__SPAWNPOINTS_START_SEARCH_WITH_VOLUME);
		PED.set_function("SPAWNPOINTS_CANCEL_SEARCH", LUA_NATIVE_PED_SPAWNPOINTS_CANCEL_SEARCH);
		PED.set_function("SPAWNPOINTS_IS_SEARCH_ACTIVE", LUA_NATIVE_PED_SPAWNPOINTS_IS_SEARCH_ACTIVE);
		PED.set_function("SPAWNPOINTS_IS_SEARCH_COMPLETE", LUA_NATIVE_PED_SPAWNPOINTS_IS_SEARCH_COMPLETE);
		PED.set_function("SPAWNPOINTS_IS_SEARCH_FAILED", LUA_NATIVE_PED_SPAWNPOINTS_IS_SEARCH_FAILED);
		PED.set_function("SPAWNPOINTS_GET_NUM_SEARCH_RESULTS", LUA_NATIVE_PED_SPAWNPOINTS_GET_NUM_SEARCH_RESULTS);
		PED.set_function("SPAWNPOINTS_GET_SEARCH_RESULT", LUA_NATIVE_PED_SPAWNPOINTS_GET_SEARCH_RESULT);
		PED.set_function("SPAWNPOINTS_GET_SEARCH_RESULT_FLAGS", LUA_NATIVE_PED_SPAWNPOINTS_GET_SEARCH_RESULT_FLAGS);
		PED.set_function("SET_IK_TARGET", LUA_NATIVE_PED_SET_IK_TARGET);
		PED.set_function("_REQUEST_PED_EMOTIONAL_PRESET", LUA_NATIVE_PED__REQUEST_PED_EMOTIONAL_PRESET);
		PED.set_function("_HAS_PED_EMOTIONAL_PRESET_LOADED", LUA_NATIVE_PED__HAS_PED_EMOTIONAL_PRESET_LOADED);
		PED.set_function("_REMOVE_PED_EMOTIONAL_PRESET", LUA_NATIVE_PED__REMOVE_PED_EMOTIONAL_PRESET);
		PED.set_function("_REQUEST_MOTION_TYPE_ASSET", LUA_NATIVE_PED__REQUEST_MOTION_TYPE_ASSET);
		PED.set_function("HAS_MOTION_TYPE_ASSET_LOADED", LUA_NATIVE_PED_HAS_MOTION_TYPE_ASSET_LOADED);
		PED.set_function("_REMOVE_MOTION_TYPE_ASSET", LUA_NATIVE_PED__REMOVE_MOTION_TYPE_ASSET);
		PED.set_function("_0x290B2E6CCDE532E1", LUA_NATIVE_PED__0x290B2E6CCDE532E1);
		PED.set_function("_0x0EEF7A81C17679DB", LUA_NATIVE_PED__0x0EEF7A81C17679DB);
		PED.set_function("SET_PED_LOD_MULTIPLIER", LUA_NATIVE_PED_SET_PED_LOD_MULTIPLIER);
		PED.set_function("_GET_PED_LOD_MULTIPLIER", LUA_NATIVE_PED__GET_PED_LOD_MULTIPLIER);
		PED.set_function("_0xA218D2BBCAA7388C", LUA_NATIVE_PED__0xA218D2BBCAA7388C);
		PED.set_function("IS_ANY_HOSTILE_PED_NEAR_POINT", LUA_NATIVE_PED_IS_ANY_HOSTILE_PED_NEAR_POINT);
		PED.set_function("_0xCBDE59C48F2B06F5", LUA_NATIVE_PED__0xCBDE59C48F2B06F5);
		PED.set_function("_0x6A190B94C2541A99", LUA_NATIVE_PED__0x6A190B94C2541A99);
		PED.set_function("IS_TARGET_PED_IN_PERCEPTION_AREA", LUA_NATIVE_PED_IS_TARGET_PED_IN_PERCEPTION_AREA);
		PED.set_function("SET_POP_CONTROL_SPHERE_THIS_FRAME", LUA_NATIVE_PED_SET_POP_CONTROL_SPHERE_THIS_FRAME);
		PED.set_function("IS_PED_HOGTIED", LUA_NATIVE_PED_IS_PED_HOGTIED);
		PED.set_function("IS_PED_BEING_HOGTIED", LUA_NATIVE_PED_IS_PED_BEING_HOGTIED);
		PED.set_function("_0x3D9F958834AB9C30", LUA_NATIVE_PED__0x3D9F958834AB9C30);
		PED.set_function("_0x913D04A5176F84C9", LUA_NATIVE_PED__0x913D04A5176F84C9);
		PED.set_function("IS_PED_HOGTYING", LUA_NATIVE_PED_IS_PED_HOGTYING);
		PED.set_function("_GET_PED_LASSO_HOGTIE_FLAG", LUA_NATIVE_PED__GET_PED_LASSO_HOGTIE_FLAG);
		PED.set_function("SET_PED_LASSO_HOGTIE_FLAG", LUA_NATIVE_PED_SET_PED_LASSO_HOGTIE_FLAG);
		PED.set_function("_0x4642182A298187D0", LUA_NATIVE_PED__0x4642182A298187D0);
		PED.set_function("_0x6B67320E0D57856A", LUA_NATIVE_PED__0x6B67320E0D57856A);
		PED.set_function("_GET_FIRST_ENTITY_PED_IS_CARRYING", LUA_NATIVE_PED__GET_FIRST_ENTITY_PED_IS_CARRYING);
		PED.set_function("_0xAA6C49AE90A32299", LUA_NATIVE_PED__0xAA6C49AE90A32299);
		PED.set_function("_GET_CARRIER_AS_PED", LUA_NATIVE_PED__GET_CARRIER_AS_PED);
		PED.set_function("_GET_CARRIER_AS_MOUNT", LUA_NATIVE_PED__GET_CARRIER_AS_MOUNT);
		PED.set_function("_GET_CARRIER_AS_HUMAN", LUA_NATIVE_PED__GET_CARRIER_AS_HUMAN);
		PED.set_function("GET_CARRIED_ATTACHED_INFO_FOR_SLOT", LUA_NATIVE_PED_GET_CARRIED_ATTACHED_INFO_FOR_SLOT);
		PED.set_function("DETACH_CARRIABLE_ENTITY", LUA_NATIVE_PED_DETACH_CARRIABLE_ENTITY);
		PED.set_function("FIND_ALL_ATTACHED_CARRIABLE_ENTITIES", LUA_NATIVE_PED_FIND_ALL_ATTACHED_CARRIABLE_ENTITIES);
		PED.set_function("IS_PED_CARRYING_SOMETHING", LUA_NATIVE_PED_IS_PED_CARRYING_SOMETHING);
		PED.set_function("_0xB65927F861E7AE39", LUA_NATIVE_PED__0xB65927F861E7AE39);
		PED.set_function("_0xA1FBAC56D38563E2", LUA_NATIVE_PED__0xA1FBAC56D38563E2);
		PED.set_function("_0x6F43C351A5D51E2F", LUA_NATIVE_PED__0x6F43C351A5D51E2F);
		PED.set_function("IS_PED_LASSOED", LUA_NATIVE_PED_IS_PED_LASSOED);
		PED.set_function("_GET_LASSOER_OF_PED", LUA_NATIVE_PED__GET_LASSOER_OF_PED);
		PED.set_function("_GET_LASSO_TARGET", LUA_NATIVE_PED__GET_LASSO_TARGET);
		PED.set_function("_GET_LASSOED_LASSOER", LUA_NATIVE_PED__GET_LASSOED_LASSOER);
		PED.set_function("SET_LOOTING_FLAG", LUA_NATIVE_PED_SET_LOOTING_FLAG);
		PED.set_function("_GET_LOOTING_FLAG", LUA_NATIVE_PED__GET_LOOTING_FLAG);
		PED.set_function("_REFRESH_LOOT_STATE_FOR_PED", LUA_NATIVE_PED__REFRESH_LOOT_STATE_FOR_PED);
		PED.set_function("GET_PED_LOOT_STATUS_MP", LUA_NATIVE_PED_GET_PED_LOOT_STATUS_MP);
		PED.set_function("_0x4B19F171450E0D4F", LUA_NATIVE_PED__0x4B19F171450E0D4F);
		PED.set_function("_0x758F081DB204DDDE", LUA_NATIVE_PED__0x758F081DB204DDDE);
		PED.set_function("GET_LOOTING_PICKUP_TARGET_ENTITY", LUA_NATIVE_PED_GET_LOOTING_PICKUP_TARGET_ENTITY);
		PED.set_function("_0x7B5C293238EE4F20", LUA_NATIVE_PED__0x7B5C293238EE4F20);
		PED.set_function("_0xAE6B68A83ABBE7C0", LUA_NATIVE_PED__0xAE6B68A83ABBE7C0);
		PED.set_function("_0xA4B6432E3880F2F9", LUA_NATIVE_PED__0xA4B6432E3880F2F9);
		PED.set_function("_ADD_PED_SUBSCRIBE_TO_LEGENDARY_BLIPS", LUA_NATIVE_PED__ADD_PED_SUBSCRIBE_TO_LEGENDARY_BLIPS);
		PED.set_function("_REMOVE_PED_SUBSCRIBE_TO_LEGENDARY_BLIPS", LUA_NATIVE_PED__REMOVE_PED_SUBSCRIBE_TO_LEGENDARY_BLIPS);
		PED.set_function("IS_PED_INCAPACITATED", LUA_NATIVE_PED_IS_PED_INCAPACITATED);
		PED.set_function("_SET_PED_INCAPACITATION_MODIFIERS", LUA_NATIVE_PED__SET_PED_INCAPACITATION_MODIFIERS);
		PED.set_function("_GET_PED_CAN_BE_INCAPACITATED_THIS_FRAME", LUA_NATIVE_PED__GET_PED_CAN_BE_INCAPACITATED_THIS_FRAME);
		PED.set_function("SET_PED_CAN_BE_INCAPACITATED", LUA_NATIVE_PED_SET_PED_CAN_BE_INCAPACITATED);
		PED.set_function("_GET_PED_INCAPACITATION_HEALTH", LUA_NATIVE_PED__GET_PED_INCAPACITATION_HEALTH);
		PED.set_function("_SET_PED_INCAPACITATION_TOTAL_BLEED_OUT_DURATION", LUA_NATIVE_PED__SET_PED_INCAPACITATION_TOTAL_BLEED_OUT_DURATION);
		PED.set_function("_RESET_PED_INCAPACITATION_BLEED_OUT_DURATION", LUA_NATIVE_PED__RESET_PED_INCAPACITATION_BLEED_OUT_DURATION);
		PED.set_function("_SET_PED_INCAPACITATION_FLAGS", LUA_NATIVE_PED__SET_PED_INCAPACITATION_FLAGS);
		PED.set_function("_0x92A1B55A59720395", LUA_NATIVE_PED__0x92A1B55A59720395);
		PED.set_function("_INCAPACITATED_REVIVE", LUA_NATIVE_PED__INCAPACITATED_REVIVE);
		PED.set_function("_GET_INCAPACITATION_TIME_REMAINING", LUA_NATIVE_PED__GET_INCAPACITATION_TIME_REMAINING);
		PED.set_function("_SET_PED_KNOCKED_BY_ONE_HIT", LUA_NATIVE_PED__SET_PED_KNOCKED_BY_ONE_HIT);
		PED.set_function("_0x2E5B5D1F1453E08E", LUA_NATIVE_PED__0x2E5B5D1F1453E08E);
		PED.set_function("_0x29924EB8EE9DB926", LUA_NATIVE_PED__0x29924EB8EE9DB926);
		PED.set_function("_SET_PED_ACTIVE_PLAYER_TYPE", LUA_NATIVE_PED__SET_PED_ACTIVE_PLAYER_TYPE);
		PED.set_function("_0xCB86D3E3E3708901", LUA_NATIVE_PED__0xCB86D3E3E3708901);
		PED.set_function("_0x633F83B301C87994", LUA_NATIVE_PED__0x633F83B301C87994);
		PED.set_function("_0x5203038FF8BAE577", LUA_NATIVE_PED__0x5203038FF8BAE577);
		PED.set_function("_0x7F090958AE95B61B", LUA_NATIVE_PED__0x7F090958AE95B61B);
		PED.set_function("_0xC494C76A34266E82", LUA_NATIVE_PED__0xC494C76A34266E82);
		PED.set_function("_0xC3995D396F1D97B6", LUA_NATIVE_PED__0xC3995D396F1D97B6);
		PED.set_function("_0x15F4732C357B1D6D", LUA_NATIVE_PED__0x15F4732C357B1D6D);
		PED.set_function("_0x947E43F544B6AB34", LUA_NATIVE_PED__0x947E43F544B6AB34);
		PED.set_function("_0x32417CB860A3BDC4", LUA_NATIVE_PED__0x32417CB860A3BDC4);
		PED.set_function("_0xE737D5F14304A2EC", LUA_NATIVE_PED__0xE737D5F14304A2EC);
		PED.set_function("_0xEBD49472BCCF7642", LUA_NATIVE_PED__0xEBD49472BCCF7642);
		PED.set_function("_SET_PLAYER_GREET_DISABLED_FOR_PED", LUA_NATIVE_PED__SET_PLAYER_GREET_DISABLED_FOR_PED);
		PED.set_function("_SET_PLAYER_ANTAGONIZE_DISABLED_FOR_PED", LUA_NATIVE_PED__SET_PLAYER_ANTAGONIZE_DISABLED_FOR_PED);
		PED.set_function("_0xB9BDFAE609DFB7C5", LUA_NATIVE_PED__0xB9BDFAE609DFB7C5);
		PED.set_function("_0xF7327ACC7A89AEF1", LUA_NATIVE_PED__0xF7327ACC7A89AEF1);
		PED.set_function("_GET_PED_ATTITUDE", LUA_NATIVE_PED__GET_PED_ATTITUDE);
		PED.set_function("_0x1E017404784AA6A3", LUA_NATIVE_PED__0x1E017404784AA6A3);
		PED.set_function("_0x2B4CE170DE09F346", LUA_NATIVE_PED__0x2B4CE170DE09F346);
		PED.set_function("_0x7C8AA850617651D9", LUA_NATIVE_PED__0x7C8AA850617651D9);
		PED.set_function("_GET_PED_MOTIVATION", LUA_NATIVE_PED__GET_PED_MOTIVATION);
		PED.set_function("_SET_PED_MOTIVATION", LUA_NATIVE_PED__SET_PED_MOTIVATION);
		PED.set_function("_0x23BDE06596A22CEC", LUA_NATIVE_PED__0x23BDE06596A22CEC);
		PED.set_function("_0xCDFB8C04D4C95D9B", LUA_NATIVE_PED__0xCDFB8C04D4C95D9B);
		PED.set_function("_GET_IS_PED_MOTIVATION_STATE_ENABLED", LUA_NATIVE_PED__GET_IS_PED_MOTIVATION_STATE_ENABLED);
		PED.set_function("_SET_PED_MOTIVATION_STATE_OVERRIDE", LUA_NATIVE_PED__SET_PED_MOTIVATION_STATE_OVERRIDE);
		PED.set_function("_SET_PED_MOTIVATION_MODIFIER", LUA_NATIVE_PED__SET_PED_MOTIVATION_MODIFIER);
		PED.set_function("_0xFD8E853F0BC2E942", LUA_NATIVE_PED__0xFD8E853F0BC2E942);
		PED.set_function("_SET_PED_SCENT", LUA_NATIVE_PED__SET_PED_SCENT);
		PED.set_function("_SET_PED_LADDER_MOVEMENT_SPEED_MODIFIER", LUA_NATIVE_PED__SET_PED_LADDER_MOVEMENT_SPEED_MODIFIER);
		PED.set_function("_RESET_PED_LADDER_MOVEMENT_SPEED_MODIFIER", LUA_NATIVE_PED__RESET_PED_LADDER_MOVEMENT_SPEED_MODIFIER);
		PED.set_function("_0xC6C4E15CF7D52FEA", LUA_NATIVE_PED__0xC6C4E15CF7D52FEA);
		PED.set_function("_SET_PED_VOICE_VOLUME", LUA_NATIVE_PED__SET_PED_VOICE_VOLUME);
		PED.set_function("_0x0F967019CC853BCC", LUA_NATIVE_PED__0x0F967019CC853BCC);
		PED.set_function("_IS_PED_DRAGGING", LUA_NATIVE_PED__IS_PED_DRAGGING);
		PED.set_function("IS_PED_BEING_DRAGGED", LUA_NATIVE_PED_IS_PED_BEING_DRAGGED);
		PED.set_function("_0x070A3841406C43D5", LUA_NATIVE_PED__0x070A3841406C43D5);
		PED.set_function("_ADD_PED_STAY_OUT_VOLUME", LUA_NATIVE_PED__ADD_PED_STAY_OUT_VOLUME);
		PED.set_function("_REMOVE_PED_STAY_OUT_VOLUME", LUA_NATIVE_PED__REMOVE_PED_STAY_OUT_VOLUME);
		PED.set_function("_0x9E66708B2B41F14A", LUA_NATIVE_PED__0x9E66708B2B41F14A);
		PED.set_function("_0xF634E2892220EF34", LUA_NATIVE_PED__0xF634E2892220EF34);
		PED.set_function("_0xAAC0EE3B4999ABB5", LUA_NATIVE_PED__0xAAC0EE3B4999ABB5);
		PED.set_function("GET_PED_MOTION_FOCUS_ENTITY", LUA_NATIVE_PED_GET_PED_MOTION_FOCUS_ENTITY);
		PED.set_function("_SET_CHAR_EXPRESSION", LUA_NATIVE_PED__SET_CHAR_EXPRESSION);
		PED.set_function("_GET_CHAR_EXPRESSION", LUA_NATIVE_PED__GET_CHAR_EXPRESSION);
		PED.set_function("_0x5BB04BC74A474B47", LUA_NATIVE_PED__0x5BB04BC74A474B47);
		PED.set_function("_0x9078FB0557364099", LUA_NATIVE_PED__0x9078FB0557364099);
		PED.set_function("IS_PED_FALLING_OVER", LUA_NATIVE_PED_IS_PED_FALLING_OVER);
		PED.set_function("_HAS_PED_BEEN_SHOVED_RECENTLY", LUA_NATIVE_PED__HAS_PED_BEEN_SHOVED_RECENTLY);
		PED.set_function("_GET_PED_TRANQUILIZER", LUA_NATIVE_PED__GET_PED_TRANQUILIZER);
		PED.set_function("_0x0D497AA69059FE40", LUA_NATIVE_PED__0x0D497AA69059FE40);
		PED.set_function("_0xD7D2F45C56A4F4DF", LUA_NATIVE_PED__0xD7D2F45C56A4F4DF);
		PED.set_function("_SET_PED_CULL_RANGE", LUA_NATIVE_PED__SET_PED_CULL_RANGE);
		PED.set_function("_0x1D23D3F70606D788", LUA_NATIVE_PED__0x1D23D3F70606D788);
		PED.set_function("_GET_META_PED_TYPE", LUA_NATIVE_PED__GET_META_PED_TYPE);
		PED.set_function("_IS_META_PED_USING_COMPONENT", LUA_NATIVE_PED__IS_META_PED_USING_COMPONENT);
		PED.set_function("_0xBD0E4F52F6D95242", LUA_NATIVE_PED__0xBD0E4F52F6D95242);
		PED.set_function("_IS_PED_CHILD", LUA_NATIVE_PED__IS_PED_CHILD);
		PED.set_function("_0xFFA1594703ED27CA", LUA_NATIVE_PED__0xFFA1594703ED27CA);
		PED.set_function("_SET_META_PED_TAG", LUA_NATIVE_PED__SET_META_PED_TAG);
		PED.set_function("REMOVE_TAG_FROM_META_PED", LUA_NATIVE_PED_REMOVE_TAG_FROM_META_PED);
		PED.set_function("_0xA2B8E47442C76CEC", LUA_NATIVE_PED__0xA2B8E47442C76CEC);
		PED.set_function("_GET_NUM_COMPONENT_CATEGORIES_IN_PED", LUA_NATIVE_PED__GET_NUM_COMPONENT_CATEGORIES_IN_PED);
		PED.set_function("_GET_PED_COMPONENT_CATEGORY_BY_INDEX", LUA_NATIVE_PED__GET_PED_COMPONENT_CATEGORY_BY_INDEX);
		PED.set_function("_GET_NUM_COMPONENTS_IN_PED", LUA_NATIVE_PED__GET_NUM_COMPONENTS_IN_PED);
		PED.set_function("_0x9B90842304C938A7", LUA_NATIVE_PED__0x9B90842304C938A7);
		PED.set_function("_UPDATE_PED_VARIATION", LUA_NATIVE_PED__UPDATE_PED_VARIATION);
		PED.set_function("_0xCB1A3864C524F784", LUA_NATIVE_PED__0xCB1A3864C524F784);
		PED.set_function("_0xFA0D206B489A6846", LUA_NATIVE_PED__0xFA0D206B489A6846);
		PED.set_function("_0xA4AC05B1A364EBC5", LUA_NATIVE_PED__0xA4AC05B1A364EBC5);
		PED.set_function("_0x1298B3D8E4C2409F", LUA_NATIVE_PED__0x1298B3D8E4C2409F);
		PED.set_function("_0xA274F51EF7E34B95", LUA_NATIVE_PED__0xA274F51EF7E34B95);
		PED.set_function("_0xC2EF407645BEECDC", LUA_NATIVE_PED__0xC2EF407645BEECDC);
		PED.set_function("_EQUIP_META_PED_OUTFIT", LUA_NATIVE_PED__EQUIP_META_PED_OUTFIT);
		PED.set_function("_0xFA742B82D093D848", LUA_NATIVE_PED__0xFA742B82D093D848);
		PED.set_function("_GET_PED_META_OUTFIT_HASH", LUA_NATIVE_PED__GET_PED_META_OUTFIT_HASH);
		PED.set_function("_0xA2F8B3B5FEDFC100", LUA_NATIVE_PED__0xA2F8B3B5FEDFC100);
		PED.set_function("_EQUIP_META_PED_SUBOUTFIT", LUA_NATIVE_PED__EQUIP_META_PED_SUBOUTFIT);
		PED.set_function("_DOES_META_PED_OUTFIT_EXIST_FOR_PED_MODEL", LUA_NATIVE_PED__DOES_META_PED_OUTFIT_EXIST_FOR_PED_MODEL);
		PED.set_function("_DOES_META_PED_SUBOUTFIT_EXIST_FOR_PED_MODEL", LUA_NATIVE_PED__DOES_META_PED_SUBOUTFIT_EXIST_FOR_PED_MODEL);
		PED.set_function("_0x62FDF4E678E40CC6", LUA_NATIVE_PED__0x62FDF4E678E40CC6);
		PED.set_function("_RESET_PED_COMPONENTS", LUA_NATIVE_PED__RESET_PED_COMPONENTS);
		PED.set_function("_0x370A973252741AC4", LUA_NATIVE_PED__0x370A973252741AC4);
		PED.set_function("_SET_RANDOM_OUTFIT_VARIATION", LUA_NATIVE_PED__SET_RANDOM_OUTFIT_VARIATION);
		PED.set_function("GET_NUM_META_PED_OUTFITS", LUA_NATIVE_PED_GET_NUM_META_PED_OUTFITS);
		PED.set_function("_EQUIP_META_PED_OUTFIT_PRESET", LUA_NATIVE_PED__EQUIP_META_PED_OUTFIT_PRESET);
		PED.set_function("_EQUIP_META_PED_OUTFIT_EXTRA", LUA_NATIVE_PED__EQUIP_META_PED_OUTFIT_EXTRA);
		PED.set_function("_IS_META_PED_OUTFIT_EQUIPPED", LUA_NATIVE_PED__IS_META_PED_OUTFIT_EQUIPPED);
		PED.set_function("_0x851966E1E35AF491", LUA_NATIVE_PED__0x851966E1E35AF491);
		PED.set_function("_SET_TEXTURE_OUTFIT_TINTS", LUA_NATIVE_PED__SET_TEXTURE_OUTFIT_TINTS);
		PED.set_function("_REQUEST_META_PED", LUA_NATIVE_PED__REQUEST_META_PED);
		PED.set_function("_HAS_META_PED_REQUEST_LOADED", LUA_NATIVE_PED__HAS_META_PED_REQUEST_LOADED);
		PED.set_function("_IS_META_PED_REQUEST_VALID", LUA_NATIVE_PED__IS_META_PED_REQUEST_VALID);
		PED.set_function("_CREATE_META_PED", LUA_NATIVE_PED__CREATE_META_PED);
		PED.set_function("_RELEASE_META_PED_REQUEST", LUA_NATIVE_PED__RELEASE_META_PED_REQUEST);
		PED.set_function("_REQUEST_META_PED_OUTFIT", LUA_NATIVE_PED__REQUEST_META_PED_OUTFIT);
		PED.set_function("_0x27E8A84C12B0B7D1", LUA_NATIVE_PED__0x27E8A84C12B0B7D1);
		PED.set_function("_0x273915CE30780986", LUA_NATIVE_PED__0x273915CE30780986);
		PED.set_function("_RELEASE_META_PED_OUTFIT_REQUEST", LUA_NATIVE_PED__RELEASE_META_PED_OUTFIT_REQUEST);
		PED.set_function("_0x3FCBB5FCFD968698", LUA_NATIVE_PED__0x3FCBB5FCFD968698);
		PED.set_function("_REQUEST_META_PED_ASSET_BUNDLE", LUA_NATIVE_PED__REQUEST_META_PED_ASSET_BUNDLE);
		PED.set_function("_REQUEST_META_PED_COMPONENT", LUA_NATIVE_PED__REQUEST_META_PED_COMPONENT);
		PED.set_function("_RELEASE_META_PED_ASSET_REQUEST", LUA_NATIVE_PED__RELEASE_META_PED_ASSET_REQUEST);
		PED.set_function("_HAS_META_PED_ASSET_LOADED", LUA_NATIVE_PED__HAS_META_PED_ASSET_LOADED);
		PED.set_function("_IS_META_PED_ASSET_VALID", LUA_NATIVE_PED__IS_META_PED_ASSET_VALID);
		PED.set_function("_CREATE_META_PED_ASSET", LUA_NATIVE_PED__CREATE_META_PED_ASSET);
		PED.set_function("_HAS_META_PED_OUTFIT_LOADED", LUA_NATIVE_PED__HAS_META_PED_OUTFIT_LOADED);
		PED.set_function("_IS_META_PED_OUTFIT_REQUEST_VALID", LUA_NATIVE_PED__IS_META_PED_OUTFIT_REQUEST_VALID);
		PED.set_function("_CREATE_META_PED_OUTFIT_PED", LUA_NATIVE_PED__CREATE_META_PED_OUTFIT_PED);
		PED.set_function("_APPLY_PED_META_PED_OUTFIT", LUA_NATIVE_PED__APPLY_PED_META_PED_OUTFIT);
		PED.set_function("_SET_META_PED_WEARINESS", LUA_NATIVE_PED__SET_META_PED_WEARINESS);
		PED.set_function("_0xF47D54B986F0A346", LUA_NATIVE_PED__0xF47D54B986F0A346);
		PED.set_function("_0x3EFED081B4834BA1", LUA_NATIVE_PED__0x3EFED081B4834BA1);
		PED.set_function("_0x0FB1BA7FF73B41E1", LUA_NATIVE_PED__0x0FB1BA7FF73B41E1);
		PED.set_function("_0xB292203008EBBAAC", LUA_NATIVE_PED__0xB292203008EBBAAC);
		PED.set_function("_0xD4D403EA031F351C", LUA_NATIVE_PED__0xD4D403EA031F351C);
		PED.set_function("_GET_PELT_FROM_HORSE", LUA_NATIVE_PED__GET_PELT_FROM_HORSE);
		PED.set_function("_SET_PELT_FOR_HORSE", LUA_NATIVE_PED__SET_PELT_FOR_HORSE);
		PED.set_function("_0xC412AA1C73111FE0", LUA_NATIVE_PED__0xC412AA1C73111FE0);
		PED.set_function("_CLEAR_PELT_FROM_HORSE", LUA_NATIVE_PED__CLEAR_PELT_FROM_HORSE);
		PED.set_function("_SET_PED_LIGHTS", LUA_NATIVE_PED__SET_PED_LIGHTS);
		PED.set_function("_0xD049FDAF089FDDB0", LUA_NATIVE_PED__0xD049FDAF089FDDB0);
		PED.set_function("_0xDD9540E7B1C9714F", LUA_NATIVE_PED__0xDD9540E7B1C9714F);
		PED.set_function("_0x55546004A244302A", LUA_NATIVE_PED__0x55546004A244302A);
		PED.set_function("_SET_HEALTH_RECHARGE_MULTIPLIER", LUA_NATIVE_PED__SET_HEALTH_RECHARGE_MULTIPLIER);
		PED.set_function("_GET_HEALTH_RECHARGE_MULTIPLIER", LUA_NATIVE_PED__GET_HEALTH_RECHARGE_MULTIPLIER);
		PED.set_function("_SET_STAMINA_DEPLETION_MULTIPLIER", LUA_NATIVE_PED__SET_STAMINA_DEPLETION_MULTIPLIER);
		PED.set_function("_GET_STAMINA_DEPLETION_MULTIPLIER", LUA_NATIVE_PED__GET_STAMINA_DEPLETION_MULTIPLIER);
		PED.set_function("_SET_STAMINA_RECHARGE_MULTIPLIER", LUA_NATIVE_PED__SET_STAMINA_RECHARGE_MULTIPLIER);
		PED.set_function("_GET_STAMINA_RECHARGE_MULTIPLIER", LUA_NATIVE_PED__GET_STAMINA_RECHARGE_MULTIPLIER);
		PED.set_function("_CHANGE_PED_STAMINA", LUA_NATIVE_PED__CHANGE_PED_STAMINA);
		PED.set_function("_GET_PED_STAMINA", LUA_NATIVE_PED__GET_PED_STAMINA);
		PED.set_function("_GET_PED_STAMINA_NORMALIZED", LUA_NATIVE_PED__GET_PED_STAMINA_NORMALIZED);
		PED.set_function("_GET_PED_MAX_STAMINA", LUA_NATIVE_PED__GET_PED_MAX_STAMINA);
		PED.set_function("_0x36513AFFC703C60D", LUA_NATIVE_PED__0x36513AFFC703C60D);
		PED.set_function("_RESTORE_PED_STAMINA", LUA_NATIVE_PED__RESTORE_PED_STAMINA);
		PED.set_function("_0xFC3B580C4380B5B7", LUA_NATIVE_PED__0xFC3B580C4380B5B7);
		PED.set_function("_0xEA8763E505AFD49A", LUA_NATIVE_PED__0xEA8763E505AFD49A);
		PED.set_function("_0xE4EF4382E22C780C", LUA_NATIVE_PED__0xE4EF4382E22C780C);
		PED.set_function("_0xD61FCF9FCFD515B7", LUA_NATIVE_PED__0xD61FCF9FCFD515B7);
		PED.set_function("_0x8D9DB115FBA8E23D", LUA_NATIVE_PED__0x8D9DB115FBA8E23D);
		PED.set_function("_GET_NUM_RESERVED_HEALTH", LUA_NATIVE_PED__GET_NUM_RESERVED_HEALTH);
		PED.set_function("_0xD97BC27AC039F681", LUA_NATIVE_PED__0xD97BC27AC039F681);
		PED.set_function("_0xF6A8C4B4A11AE89C", LUA_NATIVE_PED__0xF6A8C4B4A11AE89C);
		PED.set_function("_0xE4C95E0AE31C6512", LUA_NATIVE_PED__0xE4C95E0AE31C6512);
		PED.set_function("_GET_PED_LAST_DROPPED_HAT", LUA_NATIVE_PED__GET_PED_LAST_DROPPED_HAT);
		PED.set_function("_0x5D4CD22A8C82A81A", LUA_NATIVE_PED__0x5D4CD22A8C82A81A);
		PED.set_function("_0xBF567DF2BEF211A6", LUA_NATIVE_PED__0xBF567DF2BEF211A6);
		PED.set_function("_CREATE_GRAVITY_WELL", LUA_NATIVE_PED__CREATE_GRAVITY_WELL);
		PED.set_function("_REMOVE_GRAVITY_WELL", LUA_NATIVE_PED__REMOVE_GRAVITY_WELL);
		PED.set_function("_IS_PED_INTIMIDATED", LUA_NATIVE_PED__IS_PED_INTIMIDATED);
		PED.set_function("_0x7EE3A8660F38797E", LUA_NATIVE_PED__0x7EE3A8660F38797E);
		PED.set_function("_0xA180FBD502A03125", LUA_NATIVE_PED__0xA180FBD502A03125);
		PED.set_function("_REQUEST_TEXTURE", LUA_NATIVE_PED__REQUEST_TEXTURE);
		PED.set_function("_APPLY_TEXTURE_ON_PED", LUA_NATIVE_PED__APPLY_TEXTURE_ON_PED);
		PED.set_function("_RELEASE_TEXTURE", LUA_NATIVE_PED__RELEASE_TEXTURE);
		PED.set_function("_UPDATE_PED_TEXTURE", LUA_NATIVE_PED__UPDATE_PED_TEXTURE);
		PED.set_function("_RESET_PED_TEXTURE", LUA_NATIVE_PED__RESET_PED_TEXTURE);
		PED.set_function("_IS_TEXTURE_VALID", LUA_NATIVE_PED__IS_TEXTURE_VALID);
		PED.set_function("_ADD_TEXTURE_LAYER", LUA_NATIVE_PED__ADD_TEXTURE_LAYER);
		PED.set_function("_REMOVE_PED_OVERLAY", LUA_NATIVE_PED__REMOVE_PED_OVERLAY);
		PED.set_function("_SET_TEXTURE_LAYER_SHEET_GRID_INDEX", LUA_NATIVE_PED__SET_TEXTURE_LAYER_SHEET_GRID_INDEX);
		PED.set_function("_SET_TEXTURE_LAYER_ALPHA", LUA_NATIVE_PED__SET_TEXTURE_LAYER_ALPHA);
		PED.set_function("_SET_TEXTURE_LAYER_ROUGHNESS", LUA_NATIVE_PED__SET_TEXTURE_LAYER_ROUGHNESS);
		PED.set_function("_SET_TEXTURE_LAYER_PALLETE", LUA_NATIVE_PED__SET_TEXTURE_LAYER_PALLETE);
		PED.set_function("_SET_TEXTURE_LAYER_TINT", LUA_NATIVE_PED__SET_TEXTURE_LAYER_TINT);
		PED.set_function("_SET_TEXTURE_LAYER_MOD", LUA_NATIVE_PED__SET_TEXTURE_LAYER_MOD);
		PED.set_function("_SET_TEXTURE_LAYER_TEXTURE_MAP", LUA_NATIVE_PED__SET_TEXTURE_LAYER_TEXTURE_MAP);
		PED.set_function("_CLEAR_PED_TEXTURE", LUA_NATIVE_PED__CLEAR_PED_TEXTURE);
		PED.set_function("_0xC991EF46FE323867", LUA_NATIVE_PED__0xC991EF46FE323867);
		PED.set_function("_0x1F8215D0E446F593", LUA_NATIVE_PED__0x1F8215D0E446F593);
		PED.set_function("IS_LOCATION_SPAWN_SAFE", LUA_NATIVE_PED_IS_LOCATION_SPAWN_SAFE);
		PED.set_function("_0x53BA7D96B9A421D9", LUA_NATIVE_PED__0x53BA7D96B9A421D9);
		PED.set_function("_0x96C7B659854DE629", LUA_NATIVE_PED__0x96C7B659854DE629);
		PED.set_function("SET_HORSE_AVOIDANCE_LEVEL", LUA_NATIVE_PED_SET_HORSE_AVOIDANCE_LEVEL);
		PED.set_function("RESET_HORSE_AVOIDANCE_LEVEL_TO_DEFAULT", LUA_NATIVE_PED_RESET_HORSE_AVOIDANCE_LEVEL_TO_DEFAULT);
		PED.set_function("_SET_PED_USE_HORSE_MAP_COLLISION", LUA_NATIVE_PED__SET_PED_USE_HORSE_MAP_COLLISION);
		PED.set_function("_0x5B73975B4F12F7F3", LUA_NATIVE_PED__0x5B73975B4F12F7F3);
		PED.set_function("GET_META_PED_ASSET_GUIDS", LUA_NATIVE_PED_GET_META_PED_ASSET_GUIDS);
		PED.set_function("GET_META_PED_ASSET_TINT", LUA_NATIVE_PED_GET_META_PED_ASSET_TINT);
		PED.set_function("_SET_PED_BLACKBOARD_INT", LUA_NATIVE_PED__SET_PED_BLACKBOARD_INT);
		PED.set_function("_SET_PED_BLACKBOARD_BOOL", LUA_NATIVE_PED__SET_PED_BLACKBOARD_BOOL);
		PED.set_function("_SET_PED_BLACKBOARD_FLOAT", LUA_NATIVE_PED__SET_PED_BLACKBOARD_FLOAT);
		PED.set_function("_SET_PED_BLACKBOARD_HASH", LUA_NATIVE_PED__SET_PED_BLACKBOARD_HASH);
		PED.set_function("_REMOVE_PED_BLACKBOARD_INT", LUA_NATIVE_PED__REMOVE_PED_BLACKBOARD_INT);
		PED.set_function("_REMOVE_PED_BLACKBOARD_BOOL", LUA_NATIVE_PED__REMOVE_PED_BLACKBOARD_BOOL);
		PED.set_function("_REMOVE_PED_BLACKBOARD_FLOAT", LUA_NATIVE_PED__REMOVE_PED_BLACKBOARD_FLOAT);
		PED.set_function("_REMOVE_PED_BLACKBOARD_HASH", LUA_NATIVE_PED__REMOVE_PED_BLACKBOARD_HASH);
		PED.set_function("_GET_PED_BLACKBOARD_BOOL", LUA_NATIVE_PED__GET_PED_BLACKBOARD_BOOL);
		PED.set_function("_GET_PED_BLACKBOARD_FLOAT", LUA_NATIVE_PED__GET_PED_BLACKBOARD_FLOAT);
		PED.set_function("_GET_PED_BLACKBOARD_HASH", LUA_NATIVE_PED__GET_PED_BLACKBOARD_HASH);
		PED.set_function("GET_PED_BLACKBOARD_SCRIPT_INT", LUA_NATIVE_PED_GET_PED_BLACKBOARD_SCRIPT_INT);
		PED.set_function("GET_PED_BLACKBOARD_SCRIPT_BOOL", LUA_NATIVE_PED_GET_PED_BLACKBOARD_SCRIPT_BOOL);
		PED.set_function("GET_PED_BLACKBOARD_SCRIPT_FLOAT", LUA_NATIVE_PED_GET_PED_BLACKBOARD_SCRIPT_FLOAT);
		PED.set_function("_SET_TANK_ATTRIBUTE_SIZE", LUA_NATIVE_PED__SET_TANK_ATTRIBUTE_SIZE);
		PED.set_function("_0xA31D350D66FA1855", LUA_NATIVE_PED__0xA31D350D66FA1855);
		PED.set_function("_IS_USING_SLIPSTREAM", LUA_NATIVE_PED__IS_USING_SLIPSTREAM);
		PED.set_function("_0xEEDC9B29314B2733", LUA_NATIVE_PED__0xEEDC9B29314B2733);
		PED.set_function("_0x5C90E20C25E6D83C", LUA_NATIVE_PED__0x5C90E20C25E6D83C);
		PED.set_function("_0x10F96086123B939F", LUA_NATIVE_PED__0x10F96086123B939F);
		PED.set_function("_0x3FDBB99EFD8CE4AF", LUA_NATIVE_PED__0x3FDBB99EFD8CE4AF);
		PED.set_function("_0x7E8F9949B7AABBF0", LUA_NATIVE_PED__0x7E8F9949B7AABBF0);
		PED.set_function("_0x5DA36CCCB63C0895", LUA_NATIVE_PED__0x5DA36CCCB63C0895);
		PED.set_function("_0x56076667E7C2DCD6", LUA_NATIVE_PED__0x56076667E7C2DCD6);
		PED.set_function("_APPLY_SHOP_ITEM_TO_PED", LUA_NATIVE_PED__APPLY_SHOP_ITEM_TO_PED);
		PED.set_function("_REMOVE_SHOP_ITEM_FROM_PED", LUA_NATIVE_PED__REMOVE_SHOP_ITEM_FROM_PED);
		PED.set_function("REMOVE_SHOP_ITEM_FROM_PED_BY_CATEGORY", LUA_NATIVE_PED_REMOVE_SHOP_ITEM_FROM_PED_BY_CATEGORY);
		PED.set_function("_UPDATE_SHOP_ITEM_WEARABLE_STATE", LUA_NATIVE_PED__UPDATE_SHOP_ITEM_WEARABLE_STATE);
		PED.set_function("_GET_SHOP_ITEM_COMPONENT_AT_INDEX", LUA_NATIVE_PED__GET_SHOP_ITEM_COMPONENT_AT_INDEX);
		PED.set_function("_GET_SHOP_ITEM_NUM_WEARABLE_STATES", LUA_NATIVE_PED__GET_SHOP_ITEM_NUM_WEARABLE_STATES);
		PED.set_function("_GET_SHOP_ITEM_WEARABLE_STATE_BY_INDEX", LUA_NATIVE_PED__GET_SHOP_ITEM_WEARABLE_STATE_BY_INDEX);
		PED.set_function("_GET_SHOP_ITEM_COMPONENT_CATEGORY", LUA_NATIVE_PED__GET_SHOP_ITEM_COMPONENT_CATEGORY);
		PED.set_function("_0x31B2E7F2E3C58B89", LUA_NATIVE_PED__0x31B2E7F2E3C58B89);
		PED.set_function("_GET_SHOP_ITEM_BASE_LAYERS", LUA_NATIVE_PED__GET_SHOP_ITEM_BASE_LAYERS);
		PED.set_function("_0xAAB86462966168CE", LUA_NATIVE_PED__0xAAB86462966168CE);
		PED.set_function("_GET_SHOP_ITEM_HAT_COMPONENT", LUA_NATIVE_PED__GET_SHOP_ITEM_HAT_COMPONENT);
		PED.set_function("_REFRESH_META_PED_SHOP_ITEMS", LUA_NATIVE_PED__REFRESH_META_PED_SHOP_ITEMS);
		PED.set_function("_0xD103F6DBB5442BE8", LUA_NATIVE_PED__0xD103F6DBB5442BE8);
		PED.set_function("_SET_PED_PROMPT_NAME_FROM_GXT_ENTRY", LUA_NATIVE_PED__SET_PED_PROMPT_NAME_FROM_GXT_ENTRY);
		PED.set_function("_SET_PED_PROMPT_NAME", LUA_NATIVE_PED__SET_PED_PROMPT_NAME);
		PED.set_function("_SET_PED_PROMPT_NAME_FROM_GXT_ENTRY_2", LUA_NATIVE_PED__SET_PED_PROMPT_NAME_FROM_GXT_ENTRY_2);
		PED.set_function("_SET_PED_PROMPT_NAME_2", LUA_NATIVE_PED__SET_PED_PROMPT_NAME_2);
		PED.set_function("_0xF917F92BF22ECBAB", LUA_NATIVE_PED__0xF917F92BF22ECBAB);
		PED.set_function("_0x49DADFC4CD808B0A", LUA_NATIVE_PED__0x49DADFC4CD808B0A);
		PED.set_function("_HAS_PED_TAKEN_GORE_DAMAGE", LUA_NATIVE_PED__HAS_PED_TAKEN_GORE_DAMAGE);
		PED.set_function("_0x704C908E9C405136", LUA_NATIVE_PED__0x704C908E9C405136);
		PED.set_function("_0x7406C71F4AC2FFCC", LUA_NATIVE_PED__0x7406C71F4AC2FFCC);
		PED.set_function("_0x28508173C6A7CC18", LUA_NATIVE_PED__0x28508173C6A7CC18);
		PED.set_function("_0x52250B92EA70BE3D", LUA_NATIVE_PED__0x52250B92EA70BE3D);
		PED.set_function("_SET_PED_QUALITY", LUA_NATIVE_PED__SET_PED_QUALITY);
		PED.set_function("_GET_PED_QUALITY", LUA_NATIVE_PED__GET_PED_QUALITY);
		PED.set_function("_0xCE7A6C1D5CDE1F9D", LUA_NATIVE_PED__0xCE7A6C1D5CDE1F9D);
		PED.set_function("_0x604E1010E3162E86", LUA_NATIVE_PED__0x604E1010E3162E86);
		PED.set_function("_0xE8ABE3B73FC7FE17", LUA_NATIVE_PED__0xE8ABE3B73FC7FE17);
		PED.set_function("_REMOVE_PED_PROP", LUA_NATIVE_PED__REMOVE_PED_PROP);
		PED.set_function("_SET_TOTAL_PED_DAMAGE_FALLOFF_BONUS", LUA_NATIVE_PED__SET_TOTAL_PED_DAMAGE_FALLOFF_BONUS);
		PED.set_function("_0x095C2277FED731DB", LUA_NATIVE_PED__0x095C2277FED731DB);
		PED.set_function("_0x09171A6F8FDE5DC1", LUA_NATIVE_PED__0x09171A6F8FDE5DC1);
		PED.set_function("_0x09E378C52B1433B5", LUA_NATIVE_PED__0x09E378C52B1433B5);
		PED.set_function("_0x6507AC3BD7C99009", LUA_NATIVE_PED__0x6507AC3BD7C99009);
		PED.set_function("_GET_PLAYER_PED_WATER_DEPTH", LUA_NATIVE_PED__GET_PLAYER_PED_WATER_DEPTH);
		PED.set_function("_SET_PED_TRAIL_EFFECT", LUA_NATIVE_PED__SET_PED_TRAIL_EFFECT);
		PED.set_function("_0xEBAAC9A750E7563B", LUA_NATIVE_PED__0xEBAAC9A750E7563B);
		PED.set_function("_0x992187D975635DF5", LUA_NATIVE_PED__0x992187D975635DF5);
		PED.set_function("_0x0B787A37EEDD226F", LUA_NATIVE_PED__0x0B787A37EEDD226F);
	}
}
