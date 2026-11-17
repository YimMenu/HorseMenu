#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static Hash LUA_NATIVE_WEAPON__GET_WEAPON_UNLOCK(Hash weaponHash)
	{
		auto retval = WEAPON::_GET_WEAPON_UNLOCK(weaponHash);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__ADD_AMMO_TO_PED(Ped ped, Hash weaponHash, int amount, Hash addReason)
	{
		WEAPON::_ADD_AMMO_TO_PED(ped, weaponHash, amount, addReason);
	}

	static void LUA_NATIVE_WEAPON__ADD_AMMO_TO_PED_BY_TYPE(Ped ped, Hash ammoType, int amount, Hash addReason)
	{
		WEAPON::_ADD_AMMO_TO_PED_BY_TYPE(ped, ammoType, amount, addReason);
	}

	static void LUA_NATIVE_WEAPON__REMOVE_AMMO_FROM_PED(Ped ped, Hash weaponHash, int amount, Hash removeReason)
	{
		WEAPON::_REMOVE_AMMO_FROM_PED(ped, weaponHash, amount, removeReason);
	}

	static void LUA_NATIVE_WEAPON__REMOVE_AMMO_FROM_PED_BY_TYPE(Ped ped, Hash ammoHash, int amount, Hash removeReason)
	{
		WEAPON::_REMOVE_AMMO_FROM_PED_BY_TYPE(ped, ammoHash, amount, removeReason);
	}

	static void LUA_NATIVE_WEAPON__REMOVE_ALL_PED_AMMO(Ped ped)
	{
		WEAPON::_REMOVE_ALL_PED_AMMO(ped);
	}

	static void LUA_NATIVE_WEAPON_SET_PED_AMMO(Ped PedIndex, Hash TypeOfWeapon, int AmountOfAmmo)
	{
		WEAPON::SET_PED_AMMO(PedIndex, TypeOfWeapon, AmountOfAmmo);
	}

	static void LUA_NATIVE_WEAPON__0x8A779706DA5CA3DD(Ped ped, bool p1, int p2)
	{
		WEAPON::_0x8A779706DA5CA3DD(ped, p1, p2);
	}

	static void LUA_NATIVE_WEAPON__0x9409C62504A8F9E9(Vehicle vehicle, bool p1)
	{
		WEAPON::_0x9409C62504A8F9E9(vehicle, p1);
	}

	static void LUA_NATIVE_WEAPON__SET_VEHICLE_WEAPON_HEADING_LIMITS(Vehicle vehicle, int p1, float minHeading, float maxHeading)
	{
		WEAPON::_SET_VEHICLE_WEAPON_HEADING_LIMITS(vehicle, p1, minHeading, maxHeading);
	}

	static Any LUA_NATIVE_WEAPON__SET_VEHICLE_WEAPON_HEADING_LIMITS_2(Vehicle vehicle, int p1, float minHeading, float maxHeading)
	{
		auto retval = WEAPON::_SET_VEHICLE_WEAPON_HEADING_LIMITS_2(vehicle, p1, minHeading, maxHeading);
		return retval;
	}

	static void LUA_NATIVE_WEAPON_SET_VEHICLE_WEAPON_HEADING(Vehicle vehicle, int seatIndex, float heading, bool p3)
	{
		WEAPON::SET_VEHICLE_WEAPON_HEADING(vehicle, seatIndex, heading, p3);
	}

	static void LUA_NATIVE_WEAPON_SET_PED_INFINITE_AMMO(Ped PedIndex, bool Infinite, Hash TypeOfWeapon)
	{
		WEAPON::SET_PED_INFINITE_AMMO(PedIndex, Infinite, TypeOfWeapon);
	}

	static void LUA_NATIVE_WEAPON__SET_PED_INFINITE_AMMO_CLIP(Ped ped, bool toggle)
	{
		WEAPON::_SET_PED_INFINITE_AMMO_CLIP(ped, toggle);
	}

	static int LUA_NATIVE_WEAPON_GET_AMMO_IN_PED_WEAPON(Ped PedIndex, Hash TypeOfWeapon)
	{
		auto retval = WEAPON::GET_AMMO_IN_PED_WEAPON(PedIndex, TypeOfWeapon);
		return retval;
	}

	static int LUA_NATIVE_WEAPON_GET_MAX_AMMO_IN_CLIP(Ped PedIndex, Hash WeaponType, bool DoDeadCheck)
	{
		auto retval = WEAPON::GET_MAX_AMMO_IN_CLIP(PedIndex, WeaponType, DoDeadCheck);
		return retval;
	}

	static std::tuple<bool, int> LUA_NATIVE_WEAPON_GET_AMMO_IN_CLIP(Ped PedIndex, int ReturnAmmoInClip, Hash WeaponType)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)WEAPON::GET_AMMO_IN_CLIP(PedIndex, &ReturnAmmoInClip, WeaponType);
		std::get<1>(return_values) = ReturnAmmoInClip;

		return return_values;
	}

	static std::tuple<bool, int> LUA_NATIVE_WEAPON__GET_AMMO_IN_CLIP_BY_INVENTORY_UID(Ped ped, int ammo, uintptr_t inventoryUid)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)WEAPON::_GET_AMMO_IN_CLIP_BY_INVENTORY_UID(ped, &ammo, (Any*)inventoryUid);
		std::get<1>(return_values) = ammo;

		return return_values;
	}

	static bool LUA_NATIVE_WEAPON_SET_AMMO_IN_CLIP(Ped PedIndex, Hash WeaponType, int AmmoInClip)
	{
		auto retval = (bool)WEAPON::SET_AMMO_IN_CLIP(PedIndex, WeaponType, AmmoInClip);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__REFILL_AMMO_IN_CLIP(Ped ped, uintptr_t clipInventoryUid, int p2)
	{
		auto retval = WEAPON::_REFILL_AMMO_IN_CLIP(ped, (Any*)clipInventoryUid, p2);
		return retval;
	}

	static std::tuple<bool, int> LUA_NATIVE_WEAPON_GET_MAX_AMMO(Ped PedIndex, int ReturnMaxAmmo, Hash WeaponType)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)WEAPON::GET_MAX_AMMO(PedIndex, &ReturnMaxAmmo, WeaponType);
		std::get<1>(return_values) = ReturnMaxAmmo;

		return return_values;
	}

	static void LUA_NATIVE_WEAPON_SET_PED_AMMO_BY_TYPE(Ped PedIndex, Hash AmmoType, int AmmoAmount)
	{
		WEAPON::SET_PED_AMMO_BY_TYPE(PedIndex, AmmoType, AmmoAmount);
	}

	static int LUA_NATIVE_WEAPON_GET_PED_AMMO_BY_TYPE(Ped PedIndex, Hash AmmoType)
	{
		auto retval = WEAPON::GET_PED_AMMO_BY_TYPE(PedIndex, AmmoType);
		return retval;
	}

	static void LUA_NATIVE_WEAPON_SET_PED_AMMO_TO_DROP(Ped PedIndex, int MinAmount, int MaxAmount)
	{
		WEAPON::SET_PED_AMMO_TO_DROP(PedIndex, MinAmount, MaxAmount);
	}

	static Hash LUA_NATIVE_WEAPON__GET_AMMO_TYPE_FOR_WEAPON(Hash weaponHash)
	{
		auto retval = WEAPON::_GET_AMMO_TYPE_FOR_WEAPON(weaponHash);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON_GET_PED_AMMO_TYPE_FROM_WEAPON(Ped PedIndex, Hash WeaponType)
	{
		auto retval = WEAPON::GET_PED_AMMO_TYPE_FROM_WEAPON(PedIndex, WeaponType);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON__GET_WEAPON_TYPE_FROM_AMMO_TYPE(Hash ammoType)
	{
		auto retval = WEAPON::_GET_WEAPON_TYPE_FROM_AMMO_TYPE(ammoType);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON__GET_WEAPON_COMPONENT_TYPE_MODEL(Hash componentHash)
	{
		auto retval = WEAPON::_GET_WEAPON_COMPONENT_TYPE_MODEL(componentHash);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON__GET_WEAPONTYPE_MODEL(Hash weaponHash)
	{
		auto retval = WEAPON::_GET_WEAPONTYPE_MODEL(weaponHash);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON__GET_WEAPONTYPE_SLOT(Hash weaponHash)
	{
		auto retval = WEAPON::_GET_WEAPONTYPE_SLOT(weaponHash);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON_GET_WEAPONTYPE_GROUP(Hash weapon)
	{
		auto retval = WEAPON::GET_WEAPONTYPE_GROUP(weapon);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON__0xF8204EF17410BF43(Hash weaponGroupHash, float p1, float p2, Any p3)
	{
		auto retval = WEAPON::_0xF8204EF17410BF43(weaponGroupHash, p1, p2, p3);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_WEAPON_KIT(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::_IS_WEAPON_KIT(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_WEAPON_KIT_2(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::_IS_WEAPON_KIT_2(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON_IS_WEAPON_BOW(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::IS_WEAPON_BOW(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_WEAPON_LANTERN(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::_IS_WEAPON_LANTERN(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_WEAPON_TORCH(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::_IS_WEAPON_TORCH(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON_GIVE_WEAPON_TO_PED_WITH_OPTIONS(Ped ped, uintptr_t data, uintptr_t outData)
	{
		auto retval = (bool)WEAPON::GIVE_WEAPON_TO_PED_WITH_OPTIONS(ped, (Any*)data, (Any*)outData);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON_GIVE_WEAPON_TO_PED(Ped ped, Hash weaponHash, int ammoCount, bool bForceInHand, bool bForceInHolster, int attachPoint, bool bAllowMultipleCopies, float p7, float p8, Hash addReason, bool bIgnoreUnlocks, float permanentDegradation, bool p12)
	{
		auto retval = WEAPON::GIVE_WEAPON_TO_PED(ped, weaponHash, ammoCount, bForceInHand, bForceInHolster, attachPoint, bAllowMultipleCopies, p7, p8, addReason, bIgnoreUnlocks, permanentDegradation, p12);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__SET_FORCE_CURRENT_WEAPON_INTO_COCKED_STATE(Ped ped, int attachPoint)
	{
		WEAPON::_SET_FORCE_CURRENT_WEAPON_INTO_COCKED_STATE(ped, attachPoint);
	}

	static Any LUA_NATIVE_WEAPON__0x9F0E1892C7F228A8(bool p0)
	{
		auto retval = WEAPON::_0x9F0E1892C7F228A8(p0);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__HOLSTER_PED_WEAPONS(Ped ped, bool p1, bool p2, bool p3, bool immediately)
	{
		WEAPON::_HOLSTER_PED_WEAPONS(ped, p1, p2, p3, immediately);
	}

	static void LUA_NATIVE_WEAPON__HIDE_PED_WEAPONS(Ped ped, int p0, bool immediately)
	{
		WEAPON::_HIDE_PED_WEAPONS(ped, p0, immediately);
	}

	static void LUA_NATIVE_WEAPON__0x4820A6939D7CEF28(Any p0, Any p1)
	{
		WEAPON::_0x4820A6939D7CEF28(p0, p1);
	}

	static void LUA_NATIVE_WEAPON_SET_CURRENT_PED_WEAPON(Ped PedIndex, Hash TypeOfWeapon, bool bForceInHand, int attachPoint, bool p4, bool p5)
	{
		WEAPON::SET_CURRENT_PED_WEAPON(PedIndex, TypeOfWeapon, bForceInHand, attachPoint, p4, p5);
	}

	static std::tuple<bool, Hash> LUA_NATIVE_WEAPON_GET_CURRENT_PED_WEAPON(Ped PedIndex, Hash ReturnWeaponType, bool DoDeadCheck, int attachPoint, bool p4)
	{
		std::tuple<bool, Hash> return_values;
		std::get<0>(return_values) = (bool)WEAPON::GET_CURRENT_PED_WEAPON(PedIndex, &ReturnWeaponType, DoDeadCheck, attachPoint, p4);
		std::get<1>(return_values) = ReturnWeaponType;

		return return_values;
	}

	static Entity LUA_NATIVE_WEAPON_GET_CURRENT_PED_WEAPON_ENTITY_INDEX(Ped PedIndex, int attachPoint)
	{
		auto retval = WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PedIndex, attachPoint);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__ENABLE_WEAPON_RESTORE(Ped ped)
	{
		auto retval = (bool)WEAPON::_ENABLE_WEAPON_RESTORE(ped);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON_GET_PED_BACKUP_WEAPON(Ped ped, bool p1)
	{
		auto retval = WEAPON::GET_PED_BACKUP_WEAPON(ped, p1);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__0x486C96A0DCD2BC92(Any p0, Any p1)
	{
		auto retval = WEAPON::_0x486C96A0DCD2BC92(p0, p1);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON__GET_PED_WORST_WEAPON(Ped ped, bool p1, bool p2, bool p3)
	{
		auto retval = WEAPON::_GET_PED_WORST_WEAPON(ped, p1, p2, p3);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON_GET_BEST_PED_WEAPON(Ped PedIndex, bool p1, bool p2)
	{
		auto retval = WEAPON::GET_BEST_PED_WEAPON(PedIndex, p1, p2);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__GET_BEST_PED_WEAPON_IN_INVENTORY(Ped ped, Any p1, uintptr_t guidPrimary)
	{
		auto retval = WEAPON::_GET_BEST_PED_WEAPON_IN_INVENTORY(ped, p1, (Any*)guidPrimary);
		return retval;
	}

	static void LUA_NATIVE_WEAPON_GET_BEST_PED_SHORTARM_GUID(Ped ped, uintptr_t outGUID, bool p2, bool p3)
	{
		WEAPON::GET_BEST_PED_SHORTARM_GUID(ped, (Any*)outGUID, p2, p3);
	}

	static bool LUA_NATIVE_WEAPON_GET_PED_WEAPON_GUID_AT_ATTACH_POINT(Ped ped, int attachPoint, uintptr_t weaponGuid)
	{
		auto retval = (bool)WEAPON::GET_PED_WEAPON_GUID_AT_ATTACH_POINT(ped, attachPoint, (Any*)weaponGuid);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON__GET_BEST_PED_WEAPON_IN_GROUP(Ped ped, Hash weaponGroup, bool p2, bool p3)
	{
		auto retval = WEAPON::_GET_BEST_PED_WEAPON_IN_GROUP(ped, weaponGroup, p2, p3);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON__GET_DEFAULT_UNARMED_WEAPON_HASH(Ped ped)
	{
		auto retval = WEAPON::_GET_DEFAULT_UNARMED_WEAPON_HASH(ped);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__SET_AMMO_IN_TURRET(Vehicle vehicle, Hash turretHash, int ammo)
	{
		WEAPON::_SET_AMMO_IN_TURRET(vehicle, turretHash, ammo);
	}

	static bool LUA_NATIVE_WEAPON_SET_CURRENT_PED_VEHICLE_WEAPON(Ped PedIndex, Hash TypeOfWeapon)
	{
		auto retval = (bool)WEAPON::SET_CURRENT_PED_VEHICLE_WEAPON(PedIndex, TypeOfWeapon);
		return retval;
	}

	static std::tuple<bool, Hash> LUA_NATIVE_WEAPON_GET_CURRENT_PED_VEHICLE_WEAPON(Ped PedIndex, Hash ReturnWeaponType)
	{
		std::tuple<bool, Hash> return_values;
		std::get<0>(return_values) = (bool)WEAPON::GET_CURRENT_PED_VEHICLE_WEAPON(PedIndex, &ReturnWeaponType);
		std::get<1>(return_values) = ReturnWeaponType;

		return return_values;
	}

	static bool LUA_NATIVE_WEAPON_IS_PED_ARMED(Ped ped, int flags)
	{
		auto retval = (bool)WEAPON::IS_PED_ARMED(ped, flags);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__0xA2091482ED42EF85(Any p0, Any p1)
	{
		auto retval = WEAPON::_0xA2091482ED42EF85(p0, p1);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_WEAPON_HOLSTER_STATE_CHANGING(Ped ped)
	{
		auto retval = (bool)WEAPON::_IS_WEAPON_HOLSTER_STATE_CHANGING(ped);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON_IS_WEAPON_VALID(Hash TypeOfWeapon)
	{
		auto retval = (bool)WEAPON::IS_WEAPON_VALID(TypeOfWeapon);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_AMMO_VALID(Hash ammoHash)
	{
		auto retval = (bool)WEAPON::_IS_AMMO_VALID(ammoHash);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__0x23BF601A42F329A0(Any p0)
	{
		auto retval = WEAPON::_0x23BF601A42F329A0(p0);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON_IS_PED_CARRYING_WEAPON(Ped ped, Hash weaponHash)
	{
		auto retval = (bool)WEAPON::IS_PED_CARRYING_WEAPON(ped, weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON_HAS_PED_GOT_WEAPON(Ped PedIndex, Hash TypeOfWeapon, int GeneralWeaponType, bool p3)
	{
		auto retval = (bool)WEAPON::HAS_PED_GOT_WEAPON(PedIndex, TypeOfWeapon, GeneralWeaponType, p3);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__0x07E1C35F0078C3F9(Ped ped, Hash weapon)
	{
		auto retval = (bool)WEAPON::_0x07E1C35F0078C3F9(ped, weapon);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON_IS_PED_WEAPON_READY_TO_SHOOT(Ped PedIndex)
	{
		auto retval = (bool)WEAPON::IS_PED_WEAPON_READY_TO_SHOOT(PedIndex);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON__GET_PED_WEAPON_IN_SLOT(Ped ped, Hash slotHash)
	{
		auto retval = WEAPON::_GET_PED_WEAPON_IN_SLOT(ped, slotHash);
		return retval;
	}

	static void LUA_NATIVE_WEAPON_GIVE_DELAYED_WEAPON_TO_PED(Ped PedIndex, Hash TypeOfWeapon, int AmountOfAmmo, bool bSetAsCurrentWeapon, Hash addReason)
	{
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PedIndex, TypeOfWeapon, AmountOfAmmo, bSetAsCurrentWeapon, addReason);
	}

	static void LUA_NATIVE_WEAPON_REMOVE_ALL_PED_WEAPONS(Ped PedIndex, bool p1, bool p2)
	{
		WEAPON::REMOVE_ALL_PED_WEAPONS(PedIndex, p1, p2);
	}

	static void LUA_NATIVE_WEAPON_REMOVE_WEAPON_FROM_PED(Ped PedIndex, Hash TypeOfWeapon, bool p2, Hash removeReason)
	{
		WEAPON::REMOVE_WEAPON_FROM_PED(PedIndex, TypeOfWeapon, p2, removeReason);
	}

	static void LUA_NATIVE_WEAPON__REMOVE_WEAPON_FROM_PED_BY_GUID(Ped ped, uintptr_t weaponGuid, Hash removeReason)
	{
		WEAPON::_REMOVE_WEAPON_FROM_PED_BY_GUID(ped, (Any*)weaponGuid, removeReason);
	}

	static void LUA_NATIVE_WEAPON_HIDE_PED_WEAPON_FOR_SCRIPTED_CUTSCENE(Ped PedIndex, bool HideWeaponFlag)
	{
		WEAPON::HIDE_PED_WEAPON_FOR_SCRIPTED_CUTSCENE(PedIndex, HideWeaponFlag);
	}

	static void LUA_NATIVE_WEAPON_SET_PED_CURRENT_WEAPON_VISIBLE(Ped PedIndex, bool VisibleFlag, bool DestroyObject, bool DeadCheck, bool StoreDestroyedWeaponClipValue)
	{
		WEAPON::SET_PED_CURRENT_WEAPON_VISIBLE(PedIndex, VisibleFlag, DestroyObject, DeadCheck, StoreDestroyedWeaponClipValue);
	}

	static void LUA_NATIVE_WEAPON__SET_PED_WEAPON_ATTACH_POINT_VISIBILITY(Ped ped, int attachPoint, bool visible)
	{
		WEAPON::_SET_PED_WEAPON_ATTACH_POINT_VISIBILITY(ped, attachPoint, visible);
	}

	static void LUA_NATIVE_WEAPON__SET_PED_ALL_WEAPONS_VISIBILITY(Ped ped, bool visible)
	{
		WEAPON::_SET_PED_ALL_WEAPONS_VISIBILITY(ped, visible);
	}

	static void LUA_NATIVE_WEAPON_SET_PED_DROPS_WEAPONS_WHEN_DEAD(Ped PedIndex, bool DropsWeaponsFlag)
	{
		WEAPON::SET_PED_DROPS_WEAPONS_WHEN_DEAD(PedIndex, DropsWeaponsFlag);
	}

	static void LUA_NATIVE_WEAPON__0x431240A58484D5D0(Ped ped, bool toggle)
	{
		WEAPON::_0x431240A58484D5D0(ped, toggle);
	}

	static void LUA_NATIVE_WEAPON__0x45E57FDD531C9477(Ped ped, bool toggle)
	{
		WEAPON::_0x45E57FDD531C9477(ped, toggle);
	}

	static void LUA_NATIVE_WEAPON__0xF08D8FEB455F2C8C(Ped ped, bool toggle)
	{
		WEAPON::_0xF08D8FEB455F2C8C(ped, toggle);
	}

	static void LUA_NATIVE_WEAPON__0x16D9841A85FA627E(Ped ped, bool toggle)
	{
		WEAPON::_0x16D9841A85FA627E(ped, toggle);
	}

	static std::tuple<bool, Vector3> LUA_NATIVE_WEAPON_GET_PED_LAST_WEAPON_IMPACT_COORD(Ped PedIndex, Vector3 ImpactCoord)
	{
		std::tuple<bool, Vector3> return_values;
		std::get<0>(return_values) = (bool)WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PedIndex, &ImpactCoord);
		std::get<1>(return_values) = ImpactCoord;

		return return_values;
	}

	static void LUA_NATIVE_WEAPON__CLEAR_PED_LAST_WEAPON_DAMAGE(Ped ped)
	{
		WEAPON::_CLEAR_PED_LAST_WEAPON_DAMAGE(ped);
	}

	static bool LUA_NATIVE_WEAPON__HAS_ENTITY_BEEN_DAMAGED_BY_WEAPON(Entity entity, Hash weaponName, int weaponType)
	{
		auto retval = (bool)WEAPON::_HAS_ENTITY_BEEN_DAMAGED_BY_WEAPON(entity, weaponName, weaponType);
		return retval;
	}

	static void LUA_NATIVE_WEAPON_SET_PED_DROPS_INVENTORY_WEAPON(Ped PedIndex, Hash WeaponType, float offsetX, float offsetY, float offsetZ, int ammoAmount)
	{
		WEAPON::SET_PED_DROPS_INVENTORY_WEAPON(PedIndex, WeaponType, offsetX, offsetY, offsetZ, ammoAmount);
	}

	static void LUA_NATIVE_WEAPON__0xB0FB9B196A3D13F0(Any p0, Any p1, Any p2)
	{
		WEAPON::_0xB0FB9B196A3D13F0(p0, p1, p2);
	}

	static void LUA_NATIVE_WEAPON__0x2EBF70E1D8C06683(Ped ped, Hash p1)
	{
		WEAPON::_0x2EBF70E1D8C06683(ped, p1);
	}

	static void LUA_NATIVE_WEAPON__0x63B83A526329AFBC(Any p0)
	{
		WEAPON::_0x63B83A526329AFBC(p0);
	}

	static Any LUA_NATIVE_WEAPON__MAKE_PED_RELOAD(Ped ped)
	{
		auto retval = WEAPON::_MAKE_PED_RELOAD(ped);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__REFILL_AMMO_IN_CURRENT_PED_WEAPON(Ped ped)
	{
		auto retval = WEAPON::_REFILL_AMMO_IN_CURRENT_PED_WEAPON(ped);
		return retval;
	}

	static Entity LUA_NATIVE_WEAPON_MAKE_PED_DROP_WEAPON(Ped ped, bool p1, int attachPoint, bool p3, bool p4)
	{
		auto retval = WEAPON::MAKE_PED_DROP_WEAPON(ped, p1, attachPoint, p3, p4);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON__GET_PED_CURRENT_HELD_WEAPON(Ped ped)
	{
		auto retval = WEAPON::_GET_PED_CURRENT_HELD_WEAPON(ped);
		return retval;
	}

	static void LUA_NATIVE_WEAPON_SET_ALLOW_ANY_WEAPON_DROP(Ped ped, bool toggle)
	{
		WEAPON::SET_ALLOW_ANY_WEAPON_DROP(ped, toggle);
	}

	static void LUA_NATIVE_WEAPON__0xA3716A77DCF17424(Any p0, Any p1, Any p2)
	{
		WEAPON::_0xA3716A77DCF17424(p0, p1, p2);
	}

	static void LUA_NATIVE_WEAPON__0x457B16951AD77C1B(Any p0)
	{
		WEAPON::_0x457B16951AD77C1B(p0);
	}

	static Any LUA_NATIVE_WEAPON__0x3799EFCC3C8CD5E1(Any p0)
	{
		auto retval = WEAPON::_0x3799EFCC3C8CD5E1(p0);
		return retval;
	}

	static float LUA_NATIVE_WEAPON__GET_MAX_LOCKON_DISTANCE_OF_CURRENT_PED_WEAPON(Ped ped)
	{
		auto retval = WEAPON::_GET_MAX_LOCKON_DISTANCE_OF_CURRENT_PED_WEAPON(ped);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__REMOVE_WEAPON_COMPONENT_FROM_PED(Ped ped, Hash componentHash, Hash weaponHash)
	{
		WEAPON::_REMOVE_WEAPON_COMPONENT_FROM_PED(ped, componentHash, weaponHash);
	}

	static bool LUA_NATIVE_WEAPON__HAS_PED_GOT_WEAPON_COMPONENT(Ped ped, Hash componentHash, Hash weaponHash)
	{
		auto retval = (bool)WEAPON::_HAS_PED_GOT_WEAPON_COMPONENT(ped, componentHash, weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_PED_CURRENT_WEAPON_HOLSTERED(Ped ped)
	{
		auto retval = (bool)WEAPON::_IS_PED_CURRENT_WEAPON_HOLSTERED(ped);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__0xD2209866B0CB72EA(Any p0, Any p1)
	{
		auto retval = WEAPON::_0xD2209866B0CB72EA(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__REQUEST_WEAPON_ASSET(Hash weaponHash, int p1, bool p2)
	{
		WEAPON::_REQUEST_WEAPON_ASSET(weaponHash, p1, p2);
	}

	static bool LUA_NATIVE_WEAPON__HAS_WEAPON_ASSET_LOADED(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::_HAS_WEAPON_ASSET_LOADED(weaponHash);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__REMOVE_WEAPON_ASSET(Hash weaponHash)
	{
		WEAPON::_REMOVE_WEAPON_ASSET(weaponHash);
	}

	static void LUA_NATIVE_WEAPON__0xE9B3FEC825668291(Any p0, Any p1, Any p2)
	{
		WEAPON::_0xE9B3FEC825668291(p0, p1, p2);
	}

	static Any LUA_NATIVE_WEAPON__0x9CCA3131E6B53C68(Any p0, Any p1, Any p2)
	{
		auto retval = WEAPON::_0x9CCA3131E6B53C68(p0, p1, p2);
		return retval;
	}

	static const char* LUA_NATIVE_WEAPON__GET_WEAPON_NAME_2(Hash weaponHash)
	{
		auto retval = WEAPON::_GET_WEAPON_NAME_2(weaponHash);
		return retval;
	}

	static const char* LUA_NATIVE_WEAPON__GET_WEAPON_NAME(Hash weaponHash)
	{
		auto retval = WEAPON::_GET_WEAPON_NAME(weaponHash);
		return retval;
	}

	static const char* LUA_NATIVE_WEAPON__GET_WEAPON_NAME_WITH_PERMANENT_DEGRADATION(Hash weaponHash, float permanentDegradationLevel)
	{
		auto retval = WEAPON::_GET_WEAPON_NAME_WITH_PERMANENT_DEGRADATION(weaponHash, permanentDegradationLevel);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__0xB832F1A686B9B810(Any p0, Any p1, Any p2)
	{
		WEAPON::_0xB832F1A686B9B810(p0, p1, p2);
	}

	static Any LUA_NATIVE_WEAPON__0x5A695BD328586B44(Any p0, Any p1)
	{
		auto retval = WEAPON::_0x5A695BD328586B44(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__0x641351E9AD103890(Any p0, Any p1)
	{
		WEAPON::_0x641351E9AD103890(p0, p1);
	}

	static void LUA_NATIVE_WEAPON_SET_INSTANTLY_EQUIP_WEAPON_PICKUPS(Ped ped, bool toggle)
	{
		WEAPON::SET_INSTANTLY_EQUIP_WEAPON_PICKUPS(ped, toggle);
	}

	static void LUA_NATIVE_WEAPON__SET_FORCE_AUTO_EQUIP(Ped ped, bool toggle)
	{
		WEAPON::_SET_FORCE_AUTO_EQUIP(ped, toggle);
	}

	static void LUA_NATIVE_WEAPON__SEND_WEAPON_TO_INVENTORY(Ped ped, Hash weaponHash)
	{
		WEAPON::_SEND_WEAPON_TO_INVENTORY(ped, weaponHash);
	}

	static void LUA_NATIVE_WEAPON__0x14FF0C2545527F9B(Ped horse, Hash weaponHash, Ped ped)
	{
		WEAPON::_0x14FF0C2545527F9B(horse, weaponHash, ped);
	}

	static void LUA_NATIVE_WEAPON__0xD4C6E24D955FF061(Any p0)
	{
		WEAPON::_0xD4C6E24D955FF061(p0);
	}

	static Any LUA_NATIVE_WEAPON__0xAFFD0CCF31F469B8(Any p0)
	{
		auto retval = WEAPON::_0xAFFD0CCF31F469B8(p0);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON__GET_WEAPON_STAT_ID(Hash weaponHash)
	{
		auto retval = WEAPON::_GET_WEAPON_STAT_ID(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__HAS_ENTITY_BEEN_DAMAGED_BY_WEAPON_RECENTLY(Entity entity, Hash weaponHash, int ms)
	{
		auto retval = (bool)WEAPON::_HAS_ENTITY_BEEN_DAMAGED_BY_WEAPON_RECENTLY(entity, weaponHash, ms);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON__GET_PED_HOGTIE_WEAPON(Ped ped)
	{
		auto retval = WEAPON::_GET_PED_HOGTIE_WEAPON(ped);
		return retval;
	}

	static Object LUA_NATIVE_WEAPON__CREATE_WEAPON_OBJECT(Hash weaponHash, int ammoCount, float x, float y, float z, bool showWorldModel, float scale)
	{
		auto retval = WEAPON::_CREATE_WEAPON_OBJECT(weaponHash, ammoCount, x, y, z, showWorldModel, scale);
		return retval;
	}

	static void LUA_NATIVE_WEAPON_REMOVE_WEAPON_COMPONENT_FROM_WEAPON_OBJECT(Object WeaponObjectIndex, Hash WeaponComponent)
	{
		WEAPON::REMOVE_WEAPON_COMPONENT_FROM_WEAPON_OBJECT(WeaponObjectIndex, WeaponComponent);
	}

	static bool LUA_NATIVE_WEAPON_HAS_WEAPON_GOT_WEAPON_COMPONENT(Object WeaponObjectIndex, Hash WeaponComponent)
	{
		auto retval = (bool)WEAPON::HAS_WEAPON_GOT_WEAPON_COMPONENT(WeaponObjectIndex, WeaponComponent);
		return retval;
	}

	static Object LUA_NATIVE_WEAPON__GIVE_WEAPON_COMPONENT_TO_WEAPON_OBJECT(Object weaponObject, Ped ped, Hash componentHash, bool p3)
	{
		WEAPON::_GIVE_WEAPON_COMPONENT_TO_WEAPON_OBJECT(&weaponObject, ped, componentHash, p3);
		return weaponObject;
	}

	static Object LUA_NATIVE_WEAPON__GET_WEAPON_OBJECT_FROM_PED(Ped ped, bool p1)
	{
		auto retval = WEAPON::_GET_WEAPON_OBJECT_FROM_PED(ped, p1);
		return retval;
	}

	static Object LUA_NATIVE_WEAPON__GET_PED_WEAPON_OBJECT(Ped ped, bool p1)
	{
		auto retval = WEAPON::_GET_PED_WEAPON_OBJECT(ped, p1);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__GIVE_WEAPON_COMPONENT_TO_ENTITY(Entity entity, Hash componentHash, Hash weaponHash, bool p3)
	{
		WEAPON::_GIVE_WEAPON_COMPONENT_TO_ENTITY(entity, componentHash, weaponHash, p3);
	}

	static void LUA_NATIVE_WEAPON__0x74C9080FDD1BB48E(Any p0, Any p1)
	{
		WEAPON::_0x74C9080FDD1BB48E(p0, p1);
	}

	static void LUA_NATIVE_WEAPON__0x74C9080FDD1BB48F(Any p0, Any p1)
	{
		WEAPON::_0x74C9080FDD1BB48F(p0, p1);
	}

	static void LUA_NATIVE_WEAPON__0x74C2365FDD1BB48F(Any p0, Any p1)
	{
		WEAPON::_0x74C2365FDD1BB48F(p0, p1);
	}

	static void LUA_NATIVE_WEAPON__0x74C90AAACC1DD48F(Any p0)
	{
		WEAPON::_0x74C90AAACC1DD48F(p0);
	}

	static Any LUA_NATIVE_WEAPON__0x74C8000FDD1BB111(Any p0, Any p1)
	{
		auto retval = WEAPON::_0x74C8000FDD1BB111(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__0x74C8000FDD1BB222(Any p0, Any p1)
	{
		auto retval = WEAPON::_0x74C8000FDD1BB222(p0, p1);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON__GET_WEAPON_GUN_SPINNING_WEAPON_EMOTE_TRICK_TYPE_HASH(Hash emote, int weaponEmoteTrickType)
	{
		auto retval = WEAPON::_GET_WEAPON_GUN_SPINNING_WEAPON_EMOTE_TRICK_TYPE_HASH(emote, weaponEmoteTrickType);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__SET_ACTIVE_GUN_SPINNING_EQUIP_KIT_EMOTE_TWIRL(Ped ped, Hash emote)
	{
		WEAPON::_SET_ACTIVE_GUN_SPINNING_EQUIP_KIT_EMOTE_TWIRL(ped, emote);
	}

	static Hash LUA_NATIVE_WEAPON__GET_PED_GUN_SPINNING_EQUIPPED_KIT_EMOTE_TWIRL(Ped ped)
	{
		auto retval = WEAPON::_GET_PED_GUN_SPINNING_EQUIPPED_KIT_EMOTE_TWIRL(ped);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__SET_ACTIVE_GUN_SPINNING_KIT_EMOTE_TWIRL(Ped ped, int weaponEmoteTrickType, Hash spin)
	{
		WEAPON::_SET_ACTIVE_GUN_SPINNING_KIT_EMOTE_TWIRL(ped, weaponEmoteTrickType, spin);
	}

	static Hash LUA_NATIVE_WEAPON__GET_PED_GUN_SPINNING_HASH_FROM_WEAPON_EMOTE_VARIATION(Ped ped, int weaponEmoteVariation)
	{
		auto retval = WEAPON::_GET_PED_GUN_SPINNING_HASH_FROM_WEAPON_EMOTE_VARIATION(ped, weaponEmoteVariation);
		return retval;
	}

	static int LUA_NATIVE_WEAPON__GET_WEAPON_EMOTE_VARIATION(Ped ped, int variation)
	{
		auto retval = WEAPON::_GET_WEAPON_EMOTE_VARIATION(ped, variation);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__SET_GUN_SPINNING_INVENTORY_SLOT_ID_ACTIVATE(Ped ped, int emoteType)
	{
		WEAPON::_SET_GUN_SPINNING_INVENTORY_SLOT_ID_ACTIVATE(ped, emoteType);
	}

	static bool LUA_NATIVE_WEAPON__GET_CAN_TWIRL_WEAPON(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::_GET_CAN_TWIRL_WEAPON(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__GET_CORRECT_KIT_EMOTE_TWIRL_GUN(Ped ped, uintptr_t weaponGuid)
	{
		auto retval = (bool)WEAPON::_GET_CORRECT_KIT_EMOTE_TWIRL_GUN(ped, (Any*)weaponGuid);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__0xBC9444F2FF94A9C0(Any p0)
	{
		auto retval = WEAPON::_0xBC9444F2FF94A9C0(p0);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON__GET_DEFAULT_PED_WEAPON_COLLECTION(Hash pedModel)
	{
		auto retval = WEAPON::_GET_DEFAULT_PED_WEAPON_COLLECTION(pedModel);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__GIVE_WEAPON_COLLECTION_TO_PED(Ped ped, Hash weaponCollection)
	{
		WEAPON::_GIVE_WEAPON_COLLECTION_TO_PED(ped, weaponCollection);
	}

	static bool LUA_NATIVE_WEAPON__0xF252A85B8F3F8C58(Hash weaponCollection, Hash dualwieldVariant)
	{
		auto retval = (bool)WEAPON::_0xF252A85B8F3F8C58(weaponCollection, dualwieldVariant);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON__0x9EEFD670F10656D7(Hash weaponCollection, Hash weaponGroup)
	{
		auto retval = WEAPON::_0x9EEFD670F10656D7(weaponCollection, weaponGroup);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__0xF2F585411E748B9C(Any p0, Any p1)
	{
		auto retval = WEAPON::_0xF2F585411E748B9C(p0, p1);
		return retval;
	}

	static int LUA_NATIVE_WEAPON_GET_WEAPON_CLIP_SIZE(Hash weaponHash)
	{
		auto retval = WEAPON::GET_WEAPON_CLIP_SIZE(weaponHash);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__0xA769D753922B031B(Any p0, Any p1, Any p2)
	{
		WEAPON::_0xA769D753922B031B(p0, p1, p2);
	}

	static void LUA_NATIVE_WEAPON__0xC5899C4CD2E2495D(Any p0)
	{
		WEAPON::_0xC5899C4CD2E2495D(p0);
	}

	static bool LUA_NATIVE_WEAPON_GET_ALLOW_DUAL_WIELD(Ped ped)
	{
		auto retval = (bool)WEAPON::GET_ALLOW_DUAL_WIELD(ped);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__SET_ALLOW_DUAL_WIELD(Ped ped, bool allow)
	{
		WEAPON::_SET_ALLOW_DUAL_WIELD(ped, allow);
	}

	static bool LUA_NATIVE_WEAPON__0x44C8F4908F1B2622(Ped ped, Hash ammoHash)
	{
		auto retval = (bool)WEAPON::_0x44C8F4908F1B2622(ped, ammoHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_WEAPON_KNIFE(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::_IS_WEAPON_KNIFE(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON_IS_WEAPON_REVOLVER(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::IS_WEAPON_REVOLVER(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON_IS_WEAPON_PISTOL(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::IS_WEAPON_PISTOL(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON_IS_WEAPON_REPEATER(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::IS_WEAPON_REPEATER(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON_IS_WEAPON_RIFLE(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::IS_WEAPON_RIFLE(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON_IS_WEAPON_SHOTGUN(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::IS_WEAPON_SHOTGUN(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_WEAPON_SNIPER(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::_IS_WEAPON_SNIPER(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON_IS_WEAPON_MELEE_WEAPON(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::IS_WEAPON_MELEE_WEAPON(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_WEAPON_THROWABLE(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::_IS_WEAPON_THROWABLE(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_WEAPON_LASSO(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::_IS_WEAPON_LASSO(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_WEAPON_BINOCULARS(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::_IS_WEAPON_BINOCULARS(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON_IS_WEAPON_A_GUN(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::IS_WEAPON_A_GUN(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_WEAPON_TWO_HANDED(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::_IS_WEAPON_TWO_HANDED(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_WEAPON_ONE_HANDED(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::_IS_WEAPON_ONE_HANDED(weaponHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_WEAPON_SILENT(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::_IS_WEAPON_SILENT(weaponHash);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__0xEA522F991E120D45(Any p0)
	{
		auto retval = WEAPON::_0xEA522F991E120D45(p0);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_AMMO_SILENT(Hash ammoHash)
	{
		auto retval = (bool)WEAPON::_IS_AMMO_SILENT(ammoHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_AMMO_SILENT_2(Hash ammoHash)
	{
		auto retval = (bool)WEAPON::_IS_AMMO_SILENT_2(ammoHash);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON_SHOULD_WEAPON_BE_DISCARDED_WHEN_SWAPPED(Hash weaponHash)
	{
		auto retval = (bool)WEAPON::SHOULD_WEAPON_BE_DISCARDED_WHEN_SWAPPED(weaponHash);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__0x5B235F24472F2C3B(Any p0, Any p1)
	{
		auto retval = WEAPON::_0x5B235F24472F2C3B(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__0xBFCA7AFABF9D7967(Any p0, Any p1)
	{
		auto retval = WEAPON::_0xBFCA7AFABF9D7967(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__0x495A04CAEC263AF8(Any p0, Any p1)
	{
		auto retval = WEAPON::_0x495A04CAEC263AF8(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__0x95CA12E2C68043E5(Any p0, Any p1)
	{
		auto retval = WEAPON::_0x95CA12E2C68043E5(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__0xABC18A28BAD4B46F(Any p0, Any p1)
	{
		auto retval = WEAPON::_0xABC18A28BAD4B46F(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__0x80BB243789008A82(Any p0, Any p1)
	{
		auto retval = WEAPON::_0x80BB243789008A82(p0, p1);
		return retval;
	}

	static float LUA_NATIVE_WEAPON__GET_WEAPON_DAMAGE(Object weaponObject)
	{
		auto retval = WEAPON::_GET_WEAPON_DAMAGE(weaponObject);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__SET_WEAPON_DAMAGE(Object weaponObject, float level, bool p2)
	{
		WEAPON::_SET_WEAPON_DAMAGE(weaponObject, level, p2);
	}

	static float LUA_NATIVE_WEAPON__GET_WEAPON_DIRT(Object weaponObject)
	{
		auto retval = WEAPON::_GET_WEAPON_DIRT(weaponObject);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__SET_WEAPON_DIRT(Object weaponObject, float level, bool p2)
	{
		WEAPON::_SET_WEAPON_DIRT(weaponObject, level, p2);
	}

	static float LUA_NATIVE_WEAPON__GET_WEAPON_SOOT(Object weaponObject)
	{
		auto retval = WEAPON::_GET_WEAPON_SOOT(weaponObject);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__SET_WEAPON_SOOT(Object weaponObject, float level, bool p2)
	{
		WEAPON::_SET_WEAPON_SOOT(weaponObject, level, p2);
	}

	static void LUA_NATIVE_WEAPON__SET_WEAPON_LEVEL_THRESHOLD(Object weaponObject, float threshold)
	{
		WEAPON::_SET_WEAPON_LEVEL_THRESHOLD(weaponObject, threshold);
	}

	static float LUA_NATIVE_WEAPON_GET_WEAPON_DEGRADATION(Object weaponObject)
	{
		auto retval = WEAPON::GET_WEAPON_DEGRADATION(weaponObject);
		return retval;
	}

	static float LUA_NATIVE_WEAPON_GET_WEAPON_PERMANENT_DEGRADATION(Object weaponObject)
	{
		auto retval = WEAPON::GET_WEAPON_PERMANENT_DEGRADATION(weaponObject);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__SET_WEAPON_DEGRADATION(Object weaponObject, float level)
	{
		WEAPON::_SET_WEAPON_DEGRADATION(weaponObject, level);
	}

	static void LUA_NATIVE_WEAPON__LISTEN_PROJECTILE_HIT_EVENTS(bool listen)
	{
		WEAPON::_LISTEN_PROJECTILE_HIT_EVENTS(listen);
	}

	static float LUA_NATIVE_WEAPON__GET_WEAPON_SCALE(Object weaponObject)
	{
		auto retval = WEAPON::_GET_WEAPON_SCALE(weaponObject);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__SET_WEAPON_SCALE(Object weaponObject, float scale)
	{
		WEAPON::_SET_WEAPON_SCALE(weaponObject, scale);
	}

	static Any LUA_NATIVE_WEAPON__0x58425FCA3D3A2D15(Any p0)
	{
		auto retval = WEAPON::_0x58425FCA3D3A2D15(p0);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__0xEC97101A8F311282(Any p0)
	{
		auto retval = WEAPON::_0xEC97101A8F311282(p0);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON__GET_CURRENT_PED_WEAPON_AMMO_TYPE(Ped ped, Object weaponObject)
	{
		auto retval = WEAPON::_GET_CURRENT_PED_WEAPON_AMMO_TYPE(ped, weaponObject);
		return retval;
	}

	static Hash LUA_NATIVE_WEAPON__GET_CURRENT_AMMO_TYPE_FROM_GUID(Ped ped, uintptr_t weaponGuid)
	{
		auto retval = WEAPON::_GET_CURRENT_AMMO_TYPE_FROM_GUID(ped, (Any*)weaponGuid);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_AMMO_TYPE_VALID_FOR_WEAPON(Hash weaponHash, Hash ammoHash)
	{
		auto retval = (bool)WEAPON::_IS_AMMO_TYPE_VALID_FOR_WEAPON(weaponHash, ammoHash);
		return retval;
	}

	static void LUA_NATIVE_WEAPON__SET_AMMO_TYPE_FOR_PED_WEAPON(Ped ped, Hash weaponHash, Hash ammoHash)
	{
		WEAPON::_SET_AMMO_TYPE_FOR_PED_WEAPON(ped, weaponHash, ammoHash);
	}

	static void LUA_NATIVE_WEAPON__0x183CE355115B6E75(Any p0, Any p1)
	{
		WEAPON::_0x183CE355115B6E75(p0, p1);
	}

	static void LUA_NATIVE_WEAPON__SET_AMMO_TYPE_FOR_PED_WEAPON_INVENTORY(Ped ped, uintptr_t weaponInventoryUid, Hash ammoHash)
	{
		WEAPON::_SET_AMMO_TYPE_FOR_PED_WEAPON_INVENTORY(ped, (Any*)weaponInventoryUid, ammoHash);
	}

	static void LUA_NATIVE_WEAPON__DISABLE_AMMO_TYPE_FOR_PED_WEAPON(Ped ped, Hash weaponHash, Hash ammoHash)
	{
		WEAPON::_DISABLE_AMMO_TYPE_FOR_PED_WEAPON(ped, weaponHash, ammoHash);
	}

	static void LUA_NATIVE_WEAPON__DISABLE_AMMO_TYPE_FOR_PED(Ped ped, Hash ammoHash)
	{
		WEAPON::_DISABLE_AMMO_TYPE_FOR_PED(ped, ammoHash);
	}

	static void LUA_NATIVE_WEAPON__0xD63B4BA3A02A99E0(Any p0, Any p1)
	{
		WEAPON::_0xD63B4BA3A02A99E0(p0, p1);
	}

	static void LUA_NATIVE_WEAPON__ENABLE_AMMO_TYPE_FOR_PED_WEAPON(Ped ped, Hash weaponHash, Hash ammoHash)
	{
		WEAPON::_ENABLE_AMMO_TYPE_FOR_PED_WEAPON(ped, weaponHash, ammoHash);
	}

	static void LUA_NATIVE_WEAPON__ENABLE_AMMO_TYPE_FOR_PED(Ped ped, Hash weaponHash)
	{
		WEAPON::_ENABLE_AMMO_TYPE_FOR_PED(ped, weaponHash);
	}

	static void LUA_NATIVE_WEAPON__0x404514D231DB27A0(Any p0, Any p1)
	{
		WEAPON::_0x404514D231DB27A0(p0, p1);
	}

	static void LUA_NATIVE_WEAPON__0xD53846B9C931C181(Any p0, Any p1, Any p2)
	{
		WEAPON::_0xD53846B9C931C181(p0, p1, p2);
	}

	static void LUA_NATIVE_WEAPON__0x000FA7A4A8443AF7(Any p0)
	{
		WEAPON::_0x000FA7A4A8443AF7(p0);
	}

	static void LUA_NATIVE_WEAPON__0xECBB26529A737EF6(Any p0)
	{
		WEAPON::_0xECBB26529A737EF6(p0);
	}

	static int LUA_NATIVE_WEAPON__GET_WEAPON_ATTACH_POINT(Ped ped, int attachPoint)
	{
		auto retval = WEAPON::_GET_WEAPON_ATTACH_POINT(ped, attachPoint);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__0x4823F13A21F51964(Any p0, Any p1)
	{
		auto retval = WEAPON::_0x4823F13A21F51964(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_WEAPON_SET_CURRENT_PED_WEAPON_BY_GUID(Ped ped, uintptr_t weaponUid, bool p2, bool p3, bool p4, bool p5)
	{
		WEAPON::SET_CURRENT_PED_WEAPON_BY_GUID(ped, (Any*)weaponUid, p2, p3, p4, p5);
	}

	static void LUA_NATIVE_WEAPON_SET_PLAYER_PED_QUICK_SWAP_WEAPON_BY_GUID(Ped ped, uintptr_t guidPrimary, uintptr_t guidSecondary)
	{
		WEAPON::SET_PLAYER_PED_QUICK_SWAP_WEAPON_BY_GUID(ped, (Any*)guidPrimary, (Any*)guidSecondary);
	}

	static void LUA_NATIVE_WEAPON__GET_PLAYER_PED_QUICK_SWAP_WEAPON_BY_GUID(Ped ped, uintptr_t guidPrimary, uintptr_t guidSecondary)
	{
		WEAPON::_GET_PLAYER_PED_QUICK_SWAP_WEAPON_BY_GUID(ped, (Any*)guidPrimary, (Any*)guidSecondary);
	}

	static bool LUA_NATIVE_WEAPON__0x0DE0944ECCB3DF5D(Ped ped)
	{
		auto retval = (bool)WEAPON::_0x0DE0944ECCB3DF5D(ped);
		return retval;
	}

	static Any LUA_NATIVE_WEAPON__0x46D42883E873C1D7(Ped ped)
	{
		auto retval = WEAPON::_0x46D42883E873C1D7(ped);
		return retval;
	}

	static bool LUA_NATIVE_WEAPON__IS_TARGET_PED_CONSTRAINED_BY_PED_USING_BOLAS(Ped ped, Ped targetPed)
	{
		auto retval = (bool)WEAPON::_IS_TARGET_PED_CONSTRAINED_BY_PED_USING_BOLAS(ped, targetPed);
		return retval;
	}

	static int LUA_NATIVE_WEAPON__0x65DC4AC5B96614CB(Hash weaponHash)
	{
		auto retval = WEAPON::_0x65DC4AC5B96614CB(weaponHash);
		return retval;
	}

	void RegisterNatives_WEAPON(sol::state& L)
	{
		auto WEAPON = L["WEAPON"].get_or_create<sol::table>();
		WEAPON.set_function("_GET_WEAPON_UNLOCK", LUA_NATIVE_WEAPON__GET_WEAPON_UNLOCK);
		WEAPON.set_function("_ADD_AMMO_TO_PED", LUA_NATIVE_WEAPON__ADD_AMMO_TO_PED);
		WEAPON.set_function("_ADD_AMMO_TO_PED_BY_TYPE", LUA_NATIVE_WEAPON__ADD_AMMO_TO_PED_BY_TYPE);
		WEAPON.set_function("_REMOVE_AMMO_FROM_PED", LUA_NATIVE_WEAPON__REMOVE_AMMO_FROM_PED);
		WEAPON.set_function("_REMOVE_AMMO_FROM_PED_BY_TYPE", LUA_NATIVE_WEAPON__REMOVE_AMMO_FROM_PED_BY_TYPE);
		WEAPON.set_function("_REMOVE_ALL_PED_AMMO", LUA_NATIVE_WEAPON__REMOVE_ALL_PED_AMMO);
		WEAPON.set_function("SET_PED_AMMO", LUA_NATIVE_WEAPON_SET_PED_AMMO);
		WEAPON.set_function("_0x8A779706DA5CA3DD", LUA_NATIVE_WEAPON__0x8A779706DA5CA3DD);
		WEAPON.set_function("_0x9409C62504A8F9E9", LUA_NATIVE_WEAPON__0x9409C62504A8F9E9);
		WEAPON.set_function("_SET_VEHICLE_WEAPON_HEADING_LIMITS", LUA_NATIVE_WEAPON__SET_VEHICLE_WEAPON_HEADING_LIMITS);
		WEAPON.set_function("_SET_VEHICLE_WEAPON_HEADING_LIMITS_2", LUA_NATIVE_WEAPON__SET_VEHICLE_WEAPON_HEADING_LIMITS_2);
		WEAPON.set_function("SET_VEHICLE_WEAPON_HEADING", LUA_NATIVE_WEAPON_SET_VEHICLE_WEAPON_HEADING);
		WEAPON.set_function("SET_PED_INFINITE_AMMO", LUA_NATIVE_WEAPON_SET_PED_INFINITE_AMMO);
		WEAPON.set_function("_SET_PED_INFINITE_AMMO_CLIP", LUA_NATIVE_WEAPON__SET_PED_INFINITE_AMMO_CLIP);
		WEAPON.set_function("GET_AMMO_IN_PED_WEAPON", LUA_NATIVE_WEAPON_GET_AMMO_IN_PED_WEAPON);
		WEAPON.set_function("GET_MAX_AMMO_IN_CLIP", LUA_NATIVE_WEAPON_GET_MAX_AMMO_IN_CLIP);
		WEAPON.set_function("GET_AMMO_IN_CLIP", LUA_NATIVE_WEAPON_GET_AMMO_IN_CLIP);
		WEAPON.set_function("_GET_AMMO_IN_CLIP_BY_INVENTORY_UID", LUA_NATIVE_WEAPON__GET_AMMO_IN_CLIP_BY_INVENTORY_UID);
		WEAPON.set_function("SET_AMMO_IN_CLIP", LUA_NATIVE_WEAPON_SET_AMMO_IN_CLIP);
		WEAPON.set_function("_REFILL_AMMO_IN_CLIP", LUA_NATIVE_WEAPON__REFILL_AMMO_IN_CLIP);
		WEAPON.set_function("GET_MAX_AMMO", LUA_NATIVE_WEAPON_GET_MAX_AMMO);
		WEAPON.set_function("SET_PED_AMMO_BY_TYPE", LUA_NATIVE_WEAPON_SET_PED_AMMO_BY_TYPE);
		WEAPON.set_function("GET_PED_AMMO_BY_TYPE", LUA_NATIVE_WEAPON_GET_PED_AMMO_BY_TYPE);
		WEAPON.set_function("SET_PED_AMMO_TO_DROP", LUA_NATIVE_WEAPON_SET_PED_AMMO_TO_DROP);
		WEAPON.set_function("_GET_AMMO_TYPE_FOR_WEAPON", LUA_NATIVE_WEAPON__GET_AMMO_TYPE_FOR_WEAPON);
		WEAPON.set_function("GET_PED_AMMO_TYPE_FROM_WEAPON", LUA_NATIVE_WEAPON_GET_PED_AMMO_TYPE_FROM_WEAPON);
		WEAPON.set_function("_GET_WEAPON_TYPE_FROM_AMMO_TYPE", LUA_NATIVE_WEAPON__GET_WEAPON_TYPE_FROM_AMMO_TYPE);
		WEAPON.set_function("_GET_WEAPON_COMPONENT_TYPE_MODEL", LUA_NATIVE_WEAPON__GET_WEAPON_COMPONENT_TYPE_MODEL);
		WEAPON.set_function("_GET_WEAPONTYPE_MODEL", LUA_NATIVE_WEAPON__GET_WEAPONTYPE_MODEL);
		WEAPON.set_function("_GET_WEAPONTYPE_SLOT", LUA_NATIVE_WEAPON__GET_WEAPONTYPE_SLOT);
		WEAPON.set_function("GET_WEAPONTYPE_GROUP", LUA_NATIVE_WEAPON_GET_WEAPONTYPE_GROUP);
		WEAPON.set_function("_0xF8204EF17410BF43", LUA_NATIVE_WEAPON__0xF8204EF17410BF43);
		WEAPON.set_function("_IS_WEAPON_KIT", LUA_NATIVE_WEAPON__IS_WEAPON_KIT);
		WEAPON.set_function("_IS_WEAPON_KIT_2", LUA_NATIVE_WEAPON__IS_WEAPON_KIT_2);
		WEAPON.set_function("IS_WEAPON_BOW", LUA_NATIVE_WEAPON_IS_WEAPON_BOW);
		WEAPON.set_function("_IS_WEAPON_LANTERN", LUA_NATIVE_WEAPON__IS_WEAPON_LANTERN);
		WEAPON.set_function("_IS_WEAPON_TORCH", LUA_NATIVE_WEAPON__IS_WEAPON_TORCH);
		WEAPON.set_function("GIVE_WEAPON_TO_PED_WITH_OPTIONS", LUA_NATIVE_WEAPON_GIVE_WEAPON_TO_PED_WITH_OPTIONS);
		WEAPON.set_function("GIVE_WEAPON_TO_PED", LUA_NATIVE_WEAPON_GIVE_WEAPON_TO_PED);
		WEAPON.set_function("_SET_FORCE_CURRENT_WEAPON_INTO_COCKED_STATE", LUA_NATIVE_WEAPON__SET_FORCE_CURRENT_WEAPON_INTO_COCKED_STATE);
		WEAPON.set_function("_0x9F0E1892C7F228A8", LUA_NATIVE_WEAPON__0x9F0E1892C7F228A8);
		WEAPON.set_function("_HOLSTER_PED_WEAPONS", LUA_NATIVE_WEAPON__HOLSTER_PED_WEAPONS);
		WEAPON.set_function("_HIDE_PED_WEAPONS", LUA_NATIVE_WEAPON__HIDE_PED_WEAPONS);
		WEAPON.set_function("_0x4820A6939D7CEF28", LUA_NATIVE_WEAPON__0x4820A6939D7CEF28);
		WEAPON.set_function("SET_CURRENT_PED_WEAPON", LUA_NATIVE_WEAPON_SET_CURRENT_PED_WEAPON);
		WEAPON.set_function("GET_CURRENT_PED_WEAPON", LUA_NATIVE_WEAPON_GET_CURRENT_PED_WEAPON);
		WEAPON.set_function("GET_CURRENT_PED_WEAPON_ENTITY_INDEX", LUA_NATIVE_WEAPON_GET_CURRENT_PED_WEAPON_ENTITY_INDEX);
		WEAPON.set_function("_ENABLE_WEAPON_RESTORE", LUA_NATIVE_WEAPON__ENABLE_WEAPON_RESTORE);
		WEAPON.set_function("GET_PED_BACKUP_WEAPON", LUA_NATIVE_WEAPON_GET_PED_BACKUP_WEAPON);
		WEAPON.set_function("_0x486C96A0DCD2BC92", LUA_NATIVE_WEAPON__0x486C96A0DCD2BC92);
		WEAPON.set_function("_GET_PED_WORST_WEAPON", LUA_NATIVE_WEAPON__GET_PED_WORST_WEAPON);
		WEAPON.set_function("GET_BEST_PED_WEAPON", LUA_NATIVE_WEAPON_GET_BEST_PED_WEAPON);
		WEAPON.set_function("_GET_BEST_PED_WEAPON_IN_INVENTORY", LUA_NATIVE_WEAPON__GET_BEST_PED_WEAPON_IN_INVENTORY);
		WEAPON.set_function("GET_BEST_PED_SHORTARM_GUID", LUA_NATIVE_WEAPON_GET_BEST_PED_SHORTARM_GUID);
		WEAPON.set_function("GET_PED_WEAPON_GUID_AT_ATTACH_POINT", LUA_NATIVE_WEAPON_GET_PED_WEAPON_GUID_AT_ATTACH_POINT);
		WEAPON.set_function("_GET_BEST_PED_WEAPON_IN_GROUP", LUA_NATIVE_WEAPON__GET_BEST_PED_WEAPON_IN_GROUP);
		WEAPON.set_function("_GET_DEFAULT_UNARMED_WEAPON_HASH", LUA_NATIVE_WEAPON__GET_DEFAULT_UNARMED_WEAPON_HASH);
		WEAPON.set_function("_SET_AMMO_IN_TURRET", LUA_NATIVE_WEAPON__SET_AMMO_IN_TURRET);
		WEAPON.set_function("SET_CURRENT_PED_VEHICLE_WEAPON", LUA_NATIVE_WEAPON_SET_CURRENT_PED_VEHICLE_WEAPON);
		WEAPON.set_function("GET_CURRENT_PED_VEHICLE_WEAPON", LUA_NATIVE_WEAPON_GET_CURRENT_PED_VEHICLE_WEAPON);
		WEAPON.set_function("IS_PED_ARMED", LUA_NATIVE_WEAPON_IS_PED_ARMED);
		WEAPON.set_function("_0xA2091482ED42EF85", LUA_NATIVE_WEAPON__0xA2091482ED42EF85);
		WEAPON.set_function("_IS_WEAPON_HOLSTER_STATE_CHANGING", LUA_NATIVE_WEAPON__IS_WEAPON_HOLSTER_STATE_CHANGING);
		WEAPON.set_function("IS_WEAPON_VALID", LUA_NATIVE_WEAPON_IS_WEAPON_VALID);
		WEAPON.set_function("_IS_AMMO_VALID", LUA_NATIVE_WEAPON__IS_AMMO_VALID);
		WEAPON.set_function("_0x23BF601A42F329A0", LUA_NATIVE_WEAPON__0x23BF601A42F329A0);
		WEAPON.set_function("IS_PED_CARRYING_WEAPON", LUA_NATIVE_WEAPON_IS_PED_CARRYING_WEAPON);
		WEAPON.set_function("HAS_PED_GOT_WEAPON", LUA_NATIVE_WEAPON_HAS_PED_GOT_WEAPON);
		WEAPON.set_function("_0x07E1C35F0078C3F9", LUA_NATIVE_WEAPON__0x07E1C35F0078C3F9);
		WEAPON.set_function("IS_PED_WEAPON_READY_TO_SHOOT", LUA_NATIVE_WEAPON_IS_PED_WEAPON_READY_TO_SHOOT);
		WEAPON.set_function("_GET_PED_WEAPON_IN_SLOT", LUA_NATIVE_WEAPON__GET_PED_WEAPON_IN_SLOT);
		WEAPON.set_function("GIVE_DELAYED_WEAPON_TO_PED", LUA_NATIVE_WEAPON_GIVE_DELAYED_WEAPON_TO_PED);
		WEAPON.set_function("REMOVE_ALL_PED_WEAPONS", LUA_NATIVE_WEAPON_REMOVE_ALL_PED_WEAPONS);
		WEAPON.set_function("REMOVE_WEAPON_FROM_PED", LUA_NATIVE_WEAPON_REMOVE_WEAPON_FROM_PED);
		WEAPON.set_function("_REMOVE_WEAPON_FROM_PED_BY_GUID", LUA_NATIVE_WEAPON__REMOVE_WEAPON_FROM_PED_BY_GUID);
		WEAPON.set_function("HIDE_PED_WEAPON_FOR_SCRIPTED_CUTSCENE", LUA_NATIVE_WEAPON_HIDE_PED_WEAPON_FOR_SCRIPTED_CUTSCENE);
		WEAPON.set_function("SET_PED_CURRENT_WEAPON_VISIBLE", LUA_NATIVE_WEAPON_SET_PED_CURRENT_WEAPON_VISIBLE);
		WEAPON.set_function("_SET_PED_WEAPON_ATTACH_POINT_VISIBILITY", LUA_NATIVE_WEAPON__SET_PED_WEAPON_ATTACH_POINT_VISIBILITY);
		WEAPON.set_function("_SET_PED_ALL_WEAPONS_VISIBILITY", LUA_NATIVE_WEAPON__SET_PED_ALL_WEAPONS_VISIBILITY);
		WEAPON.set_function("SET_PED_DROPS_WEAPONS_WHEN_DEAD", LUA_NATIVE_WEAPON_SET_PED_DROPS_WEAPONS_WHEN_DEAD);
		WEAPON.set_function("_0x431240A58484D5D0", LUA_NATIVE_WEAPON__0x431240A58484D5D0);
		WEAPON.set_function("_0x45E57FDD531C9477", LUA_NATIVE_WEAPON__0x45E57FDD531C9477);
		WEAPON.set_function("_0xF08D8FEB455F2C8C", LUA_NATIVE_WEAPON__0xF08D8FEB455F2C8C);
		WEAPON.set_function("_0x16D9841A85FA627E", LUA_NATIVE_WEAPON__0x16D9841A85FA627E);
		WEAPON.set_function("GET_PED_LAST_WEAPON_IMPACT_COORD", LUA_NATIVE_WEAPON_GET_PED_LAST_WEAPON_IMPACT_COORD);
		WEAPON.set_function("_CLEAR_PED_LAST_WEAPON_DAMAGE", LUA_NATIVE_WEAPON__CLEAR_PED_LAST_WEAPON_DAMAGE);
		WEAPON.set_function("_HAS_ENTITY_BEEN_DAMAGED_BY_WEAPON", LUA_NATIVE_WEAPON__HAS_ENTITY_BEEN_DAMAGED_BY_WEAPON);
		WEAPON.set_function("SET_PED_DROPS_INVENTORY_WEAPON", LUA_NATIVE_WEAPON_SET_PED_DROPS_INVENTORY_WEAPON);
		WEAPON.set_function("_0xB0FB9B196A3D13F0", LUA_NATIVE_WEAPON__0xB0FB9B196A3D13F0);
		WEAPON.set_function("_0x2EBF70E1D8C06683", LUA_NATIVE_WEAPON__0x2EBF70E1D8C06683);
		WEAPON.set_function("_0x63B83A526329AFBC", LUA_NATIVE_WEAPON__0x63B83A526329AFBC);
		WEAPON.set_function("_MAKE_PED_RELOAD", LUA_NATIVE_WEAPON__MAKE_PED_RELOAD);
		WEAPON.set_function("_REFILL_AMMO_IN_CURRENT_PED_WEAPON", LUA_NATIVE_WEAPON__REFILL_AMMO_IN_CURRENT_PED_WEAPON);
		WEAPON.set_function("MAKE_PED_DROP_WEAPON", LUA_NATIVE_WEAPON_MAKE_PED_DROP_WEAPON);
		WEAPON.set_function("_GET_PED_CURRENT_HELD_WEAPON", LUA_NATIVE_WEAPON__GET_PED_CURRENT_HELD_WEAPON);
		WEAPON.set_function("SET_ALLOW_ANY_WEAPON_DROP", LUA_NATIVE_WEAPON_SET_ALLOW_ANY_WEAPON_DROP);
		WEAPON.set_function("_0xA3716A77DCF17424", LUA_NATIVE_WEAPON__0xA3716A77DCF17424);
		WEAPON.set_function("_0x457B16951AD77C1B", LUA_NATIVE_WEAPON__0x457B16951AD77C1B);
		WEAPON.set_function("_0x3799EFCC3C8CD5E1", LUA_NATIVE_WEAPON__0x3799EFCC3C8CD5E1);
		WEAPON.set_function("_GET_MAX_LOCKON_DISTANCE_OF_CURRENT_PED_WEAPON", LUA_NATIVE_WEAPON__GET_MAX_LOCKON_DISTANCE_OF_CURRENT_PED_WEAPON);
		WEAPON.set_function("_REMOVE_WEAPON_COMPONENT_FROM_PED", LUA_NATIVE_WEAPON__REMOVE_WEAPON_COMPONENT_FROM_PED);
		WEAPON.set_function("_HAS_PED_GOT_WEAPON_COMPONENT", LUA_NATIVE_WEAPON__HAS_PED_GOT_WEAPON_COMPONENT);
		WEAPON.set_function("_IS_PED_CURRENT_WEAPON_HOLSTERED", LUA_NATIVE_WEAPON__IS_PED_CURRENT_WEAPON_HOLSTERED);
		WEAPON.set_function("_0xD2209866B0CB72EA", LUA_NATIVE_WEAPON__0xD2209866B0CB72EA);
		WEAPON.set_function("_REQUEST_WEAPON_ASSET", LUA_NATIVE_WEAPON__REQUEST_WEAPON_ASSET);
		WEAPON.set_function("_HAS_WEAPON_ASSET_LOADED", LUA_NATIVE_WEAPON__HAS_WEAPON_ASSET_LOADED);
		WEAPON.set_function("_REMOVE_WEAPON_ASSET", LUA_NATIVE_WEAPON__REMOVE_WEAPON_ASSET);
		WEAPON.set_function("_0xE9B3FEC825668291", LUA_NATIVE_WEAPON__0xE9B3FEC825668291);
		WEAPON.set_function("_0x9CCA3131E6B53C68", LUA_NATIVE_WEAPON__0x9CCA3131E6B53C68);
		WEAPON.set_function("_GET_WEAPON_NAME_2", LUA_NATIVE_WEAPON__GET_WEAPON_NAME_2);
		WEAPON.set_function("_GET_WEAPON_NAME", LUA_NATIVE_WEAPON__GET_WEAPON_NAME);
		WEAPON.set_function("_GET_WEAPON_NAME_WITH_PERMANENT_DEGRADATION", LUA_NATIVE_WEAPON__GET_WEAPON_NAME_WITH_PERMANENT_DEGRADATION);
		WEAPON.set_function("_0xB832F1A686B9B810", LUA_NATIVE_WEAPON__0xB832F1A686B9B810);
		WEAPON.set_function("_0x5A695BD328586B44", LUA_NATIVE_WEAPON__0x5A695BD328586B44);
		WEAPON.set_function("_0x641351E9AD103890", LUA_NATIVE_WEAPON__0x641351E9AD103890);
		WEAPON.set_function("SET_INSTANTLY_EQUIP_WEAPON_PICKUPS", LUA_NATIVE_WEAPON_SET_INSTANTLY_EQUIP_WEAPON_PICKUPS);
		WEAPON.set_function("_SET_FORCE_AUTO_EQUIP", LUA_NATIVE_WEAPON__SET_FORCE_AUTO_EQUIP);
		WEAPON.set_function("_SEND_WEAPON_TO_INVENTORY", LUA_NATIVE_WEAPON__SEND_WEAPON_TO_INVENTORY);
		WEAPON.set_function("_0x14FF0C2545527F9B", LUA_NATIVE_WEAPON__0x14FF0C2545527F9B);
		WEAPON.set_function("_0xD4C6E24D955FF061", LUA_NATIVE_WEAPON__0xD4C6E24D955FF061);
		WEAPON.set_function("_0xAFFD0CCF31F469B8", LUA_NATIVE_WEAPON__0xAFFD0CCF31F469B8);
		WEAPON.set_function("_GET_WEAPON_STAT_ID", LUA_NATIVE_WEAPON__GET_WEAPON_STAT_ID);
		WEAPON.set_function("_HAS_ENTITY_BEEN_DAMAGED_BY_WEAPON_RECENTLY", LUA_NATIVE_WEAPON__HAS_ENTITY_BEEN_DAMAGED_BY_WEAPON_RECENTLY);
		WEAPON.set_function("_GET_PED_HOGTIE_WEAPON", LUA_NATIVE_WEAPON__GET_PED_HOGTIE_WEAPON);
		WEAPON.set_function("_CREATE_WEAPON_OBJECT", LUA_NATIVE_WEAPON__CREATE_WEAPON_OBJECT);
		WEAPON.set_function("REMOVE_WEAPON_COMPONENT_FROM_WEAPON_OBJECT", LUA_NATIVE_WEAPON_REMOVE_WEAPON_COMPONENT_FROM_WEAPON_OBJECT);
		WEAPON.set_function("HAS_WEAPON_GOT_WEAPON_COMPONENT", LUA_NATIVE_WEAPON_HAS_WEAPON_GOT_WEAPON_COMPONENT);
		WEAPON.set_function("_GIVE_WEAPON_COMPONENT_TO_WEAPON_OBJECT", LUA_NATIVE_WEAPON__GIVE_WEAPON_COMPONENT_TO_WEAPON_OBJECT);
		WEAPON.set_function("_GET_WEAPON_OBJECT_FROM_PED", LUA_NATIVE_WEAPON__GET_WEAPON_OBJECT_FROM_PED);
		WEAPON.set_function("_GET_PED_WEAPON_OBJECT", LUA_NATIVE_WEAPON__GET_PED_WEAPON_OBJECT);
		WEAPON.set_function("_GIVE_WEAPON_COMPONENT_TO_ENTITY", LUA_NATIVE_WEAPON__GIVE_WEAPON_COMPONENT_TO_ENTITY);
		WEAPON.set_function("_0x74C9080FDD1BB48E", LUA_NATIVE_WEAPON__0x74C9080FDD1BB48E);
		WEAPON.set_function("_0x74C9080FDD1BB48F", LUA_NATIVE_WEAPON__0x74C9080FDD1BB48F);
		WEAPON.set_function("_0x74C2365FDD1BB48F", LUA_NATIVE_WEAPON__0x74C2365FDD1BB48F);
		WEAPON.set_function("_0x74C90AAACC1DD48F", LUA_NATIVE_WEAPON__0x74C90AAACC1DD48F);
		WEAPON.set_function("_0x74C8000FDD1BB111", LUA_NATIVE_WEAPON__0x74C8000FDD1BB111);
		WEAPON.set_function("_0x74C8000FDD1BB222", LUA_NATIVE_WEAPON__0x74C8000FDD1BB222);
		WEAPON.set_function("_GET_WEAPON_GUN_SPINNING_WEAPON_EMOTE_TRICK_TYPE_HASH", LUA_NATIVE_WEAPON__GET_WEAPON_GUN_SPINNING_WEAPON_EMOTE_TRICK_TYPE_HASH);
		WEAPON.set_function("_SET_ACTIVE_GUN_SPINNING_EQUIP_KIT_EMOTE_TWIRL", LUA_NATIVE_WEAPON__SET_ACTIVE_GUN_SPINNING_EQUIP_KIT_EMOTE_TWIRL);
		WEAPON.set_function("_GET_PED_GUN_SPINNING_EQUIPPED_KIT_EMOTE_TWIRL", LUA_NATIVE_WEAPON__GET_PED_GUN_SPINNING_EQUIPPED_KIT_EMOTE_TWIRL);
		WEAPON.set_function("_SET_ACTIVE_GUN_SPINNING_KIT_EMOTE_TWIRL", LUA_NATIVE_WEAPON__SET_ACTIVE_GUN_SPINNING_KIT_EMOTE_TWIRL);
		WEAPON.set_function("_GET_PED_GUN_SPINNING_HASH_FROM_WEAPON_EMOTE_VARIATION", LUA_NATIVE_WEAPON__GET_PED_GUN_SPINNING_HASH_FROM_WEAPON_EMOTE_VARIATION);
		WEAPON.set_function("_GET_WEAPON_EMOTE_VARIATION", LUA_NATIVE_WEAPON__GET_WEAPON_EMOTE_VARIATION);
		WEAPON.set_function("_SET_GUN_SPINNING_INVENTORY_SLOT_ID_ACTIVATE", LUA_NATIVE_WEAPON__SET_GUN_SPINNING_INVENTORY_SLOT_ID_ACTIVATE);
		WEAPON.set_function("_GET_CAN_TWIRL_WEAPON", LUA_NATIVE_WEAPON__GET_CAN_TWIRL_WEAPON);
		WEAPON.set_function("_GET_CORRECT_KIT_EMOTE_TWIRL_GUN", LUA_NATIVE_WEAPON__GET_CORRECT_KIT_EMOTE_TWIRL_GUN);
		WEAPON.set_function("_0xBC9444F2FF94A9C0", LUA_NATIVE_WEAPON__0xBC9444F2FF94A9C0);
		WEAPON.set_function("_GET_DEFAULT_PED_WEAPON_COLLECTION", LUA_NATIVE_WEAPON__GET_DEFAULT_PED_WEAPON_COLLECTION);
		WEAPON.set_function("_GIVE_WEAPON_COLLECTION_TO_PED", LUA_NATIVE_WEAPON__GIVE_WEAPON_COLLECTION_TO_PED);
		WEAPON.set_function("_0xF252A85B8F3F8C58", LUA_NATIVE_WEAPON__0xF252A85B8F3F8C58);
		WEAPON.set_function("_0x9EEFD670F10656D7", LUA_NATIVE_WEAPON__0x9EEFD670F10656D7);
		WEAPON.set_function("_0xF2F585411E748B9C", LUA_NATIVE_WEAPON__0xF2F585411E748B9C);
		WEAPON.set_function("GET_WEAPON_CLIP_SIZE", LUA_NATIVE_WEAPON_GET_WEAPON_CLIP_SIZE);
		WEAPON.set_function("_0xA769D753922B031B", LUA_NATIVE_WEAPON__0xA769D753922B031B);
		WEAPON.set_function("_0xC5899C4CD2E2495D", LUA_NATIVE_WEAPON__0xC5899C4CD2E2495D);
		WEAPON.set_function("GET_ALLOW_DUAL_WIELD", LUA_NATIVE_WEAPON_GET_ALLOW_DUAL_WIELD);
		WEAPON.set_function("_SET_ALLOW_DUAL_WIELD", LUA_NATIVE_WEAPON__SET_ALLOW_DUAL_WIELD);
		WEAPON.set_function("_0x44C8F4908F1B2622", LUA_NATIVE_WEAPON__0x44C8F4908F1B2622);
		WEAPON.set_function("_IS_WEAPON_KNIFE", LUA_NATIVE_WEAPON__IS_WEAPON_KNIFE);
		WEAPON.set_function("IS_WEAPON_REVOLVER", LUA_NATIVE_WEAPON_IS_WEAPON_REVOLVER);
		WEAPON.set_function("IS_WEAPON_PISTOL", LUA_NATIVE_WEAPON_IS_WEAPON_PISTOL);
		WEAPON.set_function("IS_WEAPON_REPEATER", LUA_NATIVE_WEAPON_IS_WEAPON_REPEATER);
		WEAPON.set_function("IS_WEAPON_RIFLE", LUA_NATIVE_WEAPON_IS_WEAPON_RIFLE);
		WEAPON.set_function("IS_WEAPON_SHOTGUN", LUA_NATIVE_WEAPON_IS_WEAPON_SHOTGUN);
		WEAPON.set_function("_IS_WEAPON_SNIPER", LUA_NATIVE_WEAPON__IS_WEAPON_SNIPER);
		WEAPON.set_function("IS_WEAPON_MELEE_WEAPON", LUA_NATIVE_WEAPON_IS_WEAPON_MELEE_WEAPON);
		WEAPON.set_function("_IS_WEAPON_THROWABLE", LUA_NATIVE_WEAPON__IS_WEAPON_THROWABLE);
		WEAPON.set_function("_IS_WEAPON_LASSO", LUA_NATIVE_WEAPON__IS_WEAPON_LASSO);
		WEAPON.set_function("_IS_WEAPON_BINOCULARS", LUA_NATIVE_WEAPON__IS_WEAPON_BINOCULARS);
		WEAPON.set_function("IS_WEAPON_A_GUN", LUA_NATIVE_WEAPON_IS_WEAPON_A_GUN);
		WEAPON.set_function("_IS_WEAPON_TWO_HANDED", LUA_NATIVE_WEAPON__IS_WEAPON_TWO_HANDED);
		WEAPON.set_function("_IS_WEAPON_ONE_HANDED", LUA_NATIVE_WEAPON__IS_WEAPON_ONE_HANDED);
		WEAPON.set_function("_IS_WEAPON_SILENT", LUA_NATIVE_WEAPON__IS_WEAPON_SILENT);
		WEAPON.set_function("_0xEA522F991E120D45", LUA_NATIVE_WEAPON__0xEA522F991E120D45);
		WEAPON.set_function("_IS_AMMO_SILENT", LUA_NATIVE_WEAPON__IS_AMMO_SILENT);
		WEAPON.set_function("_IS_AMMO_SILENT_2", LUA_NATIVE_WEAPON__IS_AMMO_SILENT_2);
		WEAPON.set_function("SHOULD_WEAPON_BE_DISCARDED_WHEN_SWAPPED", LUA_NATIVE_WEAPON_SHOULD_WEAPON_BE_DISCARDED_WHEN_SWAPPED);
		WEAPON.set_function("_0x5B235F24472F2C3B", LUA_NATIVE_WEAPON__0x5B235F24472F2C3B);
		WEAPON.set_function("_0xBFCA7AFABF9D7967", LUA_NATIVE_WEAPON__0xBFCA7AFABF9D7967);
		WEAPON.set_function("_0x495A04CAEC263AF8", LUA_NATIVE_WEAPON__0x495A04CAEC263AF8);
		WEAPON.set_function("_0x95CA12E2C68043E5", LUA_NATIVE_WEAPON__0x95CA12E2C68043E5);
		WEAPON.set_function("_0xABC18A28BAD4B46F", LUA_NATIVE_WEAPON__0xABC18A28BAD4B46F);
		WEAPON.set_function("_0x80BB243789008A82", LUA_NATIVE_WEAPON__0x80BB243789008A82);
		WEAPON.set_function("_GET_WEAPON_DAMAGE", LUA_NATIVE_WEAPON__GET_WEAPON_DAMAGE);
		WEAPON.set_function("_SET_WEAPON_DAMAGE", LUA_NATIVE_WEAPON__SET_WEAPON_DAMAGE);
		WEAPON.set_function("_GET_WEAPON_DIRT", LUA_NATIVE_WEAPON__GET_WEAPON_DIRT);
		WEAPON.set_function("_SET_WEAPON_DIRT", LUA_NATIVE_WEAPON__SET_WEAPON_DIRT);
		WEAPON.set_function("_GET_WEAPON_SOOT", LUA_NATIVE_WEAPON__GET_WEAPON_SOOT);
		WEAPON.set_function("_SET_WEAPON_SOOT", LUA_NATIVE_WEAPON__SET_WEAPON_SOOT);
		WEAPON.set_function("_SET_WEAPON_LEVEL_THRESHOLD", LUA_NATIVE_WEAPON__SET_WEAPON_LEVEL_THRESHOLD);
		WEAPON.set_function("GET_WEAPON_DEGRADATION", LUA_NATIVE_WEAPON_GET_WEAPON_DEGRADATION);
		WEAPON.set_function("GET_WEAPON_PERMANENT_DEGRADATION", LUA_NATIVE_WEAPON_GET_WEAPON_PERMANENT_DEGRADATION);
		WEAPON.set_function("_SET_WEAPON_DEGRADATION", LUA_NATIVE_WEAPON__SET_WEAPON_DEGRADATION);
		WEAPON.set_function("_LISTEN_PROJECTILE_HIT_EVENTS", LUA_NATIVE_WEAPON__LISTEN_PROJECTILE_HIT_EVENTS);
		WEAPON.set_function("_GET_WEAPON_SCALE", LUA_NATIVE_WEAPON__GET_WEAPON_SCALE);
		WEAPON.set_function("_SET_WEAPON_SCALE", LUA_NATIVE_WEAPON__SET_WEAPON_SCALE);
		WEAPON.set_function("_0x58425FCA3D3A2D15", LUA_NATIVE_WEAPON__0x58425FCA3D3A2D15);
		WEAPON.set_function("_0xEC97101A8F311282", LUA_NATIVE_WEAPON__0xEC97101A8F311282);
		WEAPON.set_function("_GET_CURRENT_PED_WEAPON_AMMO_TYPE", LUA_NATIVE_WEAPON__GET_CURRENT_PED_WEAPON_AMMO_TYPE);
		WEAPON.set_function("_GET_CURRENT_AMMO_TYPE_FROM_GUID", LUA_NATIVE_WEAPON__GET_CURRENT_AMMO_TYPE_FROM_GUID);
		WEAPON.set_function("_IS_AMMO_TYPE_VALID_FOR_WEAPON", LUA_NATIVE_WEAPON__IS_AMMO_TYPE_VALID_FOR_WEAPON);
		WEAPON.set_function("_SET_AMMO_TYPE_FOR_PED_WEAPON", LUA_NATIVE_WEAPON__SET_AMMO_TYPE_FOR_PED_WEAPON);
		WEAPON.set_function("_0x183CE355115B6E75", LUA_NATIVE_WEAPON__0x183CE355115B6E75);
		WEAPON.set_function("_SET_AMMO_TYPE_FOR_PED_WEAPON_INVENTORY", LUA_NATIVE_WEAPON__SET_AMMO_TYPE_FOR_PED_WEAPON_INVENTORY);
		WEAPON.set_function("_DISABLE_AMMO_TYPE_FOR_PED_WEAPON", LUA_NATIVE_WEAPON__DISABLE_AMMO_TYPE_FOR_PED_WEAPON);
		WEAPON.set_function("_DISABLE_AMMO_TYPE_FOR_PED", LUA_NATIVE_WEAPON__DISABLE_AMMO_TYPE_FOR_PED);
		WEAPON.set_function("_0xD63B4BA3A02A99E0", LUA_NATIVE_WEAPON__0xD63B4BA3A02A99E0);
		WEAPON.set_function("_ENABLE_AMMO_TYPE_FOR_PED_WEAPON", LUA_NATIVE_WEAPON__ENABLE_AMMO_TYPE_FOR_PED_WEAPON);
		WEAPON.set_function("_ENABLE_AMMO_TYPE_FOR_PED", LUA_NATIVE_WEAPON__ENABLE_AMMO_TYPE_FOR_PED);
		WEAPON.set_function("_0x404514D231DB27A0", LUA_NATIVE_WEAPON__0x404514D231DB27A0);
		WEAPON.set_function("_0xD53846B9C931C181", LUA_NATIVE_WEAPON__0xD53846B9C931C181);
		WEAPON.set_function("_0x000FA7A4A8443AF7", LUA_NATIVE_WEAPON__0x000FA7A4A8443AF7);
		WEAPON.set_function("_0xECBB26529A737EF6", LUA_NATIVE_WEAPON__0xECBB26529A737EF6);
		WEAPON.set_function("_GET_WEAPON_ATTACH_POINT", LUA_NATIVE_WEAPON__GET_WEAPON_ATTACH_POINT);
		WEAPON.set_function("_0x4823F13A21F51964", LUA_NATIVE_WEAPON__0x4823F13A21F51964);
		WEAPON.set_function("SET_CURRENT_PED_WEAPON_BY_GUID", LUA_NATIVE_WEAPON_SET_CURRENT_PED_WEAPON_BY_GUID);
		WEAPON.set_function("SET_PLAYER_PED_QUICK_SWAP_WEAPON_BY_GUID", LUA_NATIVE_WEAPON_SET_PLAYER_PED_QUICK_SWAP_WEAPON_BY_GUID);
		WEAPON.set_function("_GET_PLAYER_PED_QUICK_SWAP_WEAPON_BY_GUID", LUA_NATIVE_WEAPON__GET_PLAYER_PED_QUICK_SWAP_WEAPON_BY_GUID);
		WEAPON.set_function("_0x0DE0944ECCB3DF5D", LUA_NATIVE_WEAPON__0x0DE0944ECCB3DF5D);
		WEAPON.set_function("_0x46D42883E873C1D7", LUA_NATIVE_WEAPON__0x46D42883E873C1D7);
		WEAPON.set_function("_IS_TARGET_PED_CONSTRAINED_BY_PED_USING_BOLAS", LUA_NATIVE_WEAPON__IS_TARGET_PED_CONSTRAINED_BY_PED_USING_BOLAS);
		WEAPON.set_function("_0x65DC4AC5B96614CB", LUA_NATIVE_WEAPON__0x65DC4AC5B96614CB);
	}
}
