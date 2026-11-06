#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static int LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ID_FROM_PED(Ped ped)
	{
		auto retval = INVENTORY::_INVENTORY_GET_INVENTORY_ID_FROM_PED(ped);
		return retval;
	}

	static int LUA_NATIVE_INVENTORY__GET_ITEM_ROLE_MAX_LEVEL_COUNT(int inventoryId, Hash eRoleMaxLevel)
	{
		auto retval = INVENTORY::_GET_ITEM_ROLE_MAX_LEVEL_COUNT(inventoryId, eRoleMaxLevel);
		return retval;
	}

	static int LUA_NATIVE_INVENTORY__GET_ITEM_SLOT_MAX_COUNT(Hash provision, Hash slotId)
	{
		auto retval = INVENTORY::_GET_ITEM_SLOT_MAX_COUNT(provision, slotId);
		return retval;
	}

	static std::tuple<bool, int, int, int, int, int, int> LUA_NATIVE_INVENTORY__0x112BCA290D2EB53C(int inventoryId, Hash p1, int year, int month, int day, int hour, int minute, int second)
	{
		std::tuple<bool, int, int, int, int, int, int> return_values;
		std::get<0>(return_values) = (bool)INVENTORY::_0x112BCA290D2EB53C(inventoryId, p1, &year, &month, &day, &hour, &minute, &second);
		std::get<1>(return_values) = year;
		std::get<2>(return_values) = month;
		std::get<3>(return_values) = day;
		std::get<4>(return_values) = hour;
		std::get<5>(return_values) = minute;
		std::get<6>(return_values) = second;

		return return_values;
	}

	static void LUA_NATIVE_INVENTORY__0x46743BBFEDBC859E(int inventoryId, Hash eInventoryItem, bool p2)
	{
		INVENTORY::_0x46743BBFEDBC859E(inventoryId, eInventoryItem, p2);
	}

	static void LUA_NATIVE_INVENTORY__INVENTORY_SET_INVENTORY_ITEM_IN_USE(int inventoryId, uintptr_t guid, bool inUse)
	{
		INVENTORY::_INVENTORY_SET_INVENTORY_ITEM_IN_USE(inventoryId, (Any*)guid, inUse);
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_IN_USE(int inventoryId, uintptr_t guid)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_GET_INVENTORY_ITEM_IN_USE(inventoryId, (Any*)guid);
		return retval;
	}

	static void LUA_NATIVE_INVENTORY__INVENTORY_SET_INVENTORY_ITEM_HIDDEN(int inventoryId, uintptr_t guid, bool hidden)
	{
		INVENTORY::_INVENTORY_SET_INVENTORY_ITEM_HIDDEN(inventoryId, (Any*)guid, hidden);
	}

	static void LUA_NATIVE_INVENTORY__INVENTORY_SET_INVENTORY_ITEM_HIDDEN_2(int inventoryId, uintptr_t guid, bool hidden)
	{
		INVENTORY::_INVENTORY_SET_INVENTORY_ITEM_HIDDEN_2(inventoryId, (Any*)guid, hidden);
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_HIDDEN(int inventoryId, uintptr_t guid)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_GET_INVENTORY_ITEM_HIDDEN(inventoryId, (Any*)guid);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_IS_ANIMAL_PELT(Hash item)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_GET_INVENTORY_ITEM_IS_ANIMAL_PELT(item);
		return retval;
	}

	static Hash LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_DESCRIPTION_HASH(Hash item)
	{
		auto retval = INVENTORY::_INVENTORY_GET_INVENTORY_ITEM_DESCRIPTION_HASH(item);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_IS_INVENTORY_ITEM_FLAG_ENABLED(Hash item, int flag)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_IS_INVENTORY_ITEM_FLAG_ENABLED(item, flag);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_GET_IS_INVENTORY_ITEM_SOUND_VALID(Hash item, int soundType)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_GET_IS_INVENTORY_ITEM_SOUND_VALID(item, soundType);
		return retval;
	}

	static Hash LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_SOUND(Hash item, int soundType)
	{
		auto retval = INVENTORY::_INVENTORY_GET_INVENTORY_ITEM_SOUND(item, soundType);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_INSPECTION_INFO(Hash item, uintptr_t info)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_GET_INVENTORY_ITEM_INSPECTION_INFO(item, (Any*)info);
		return retval;
	}

	static int LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_WEAPON_COPY_ID(int inventoryId, uintptr_t guid)
	{
		auto retval = INVENTORY::_INVENTORY_GET_INVENTORY_ITEM_WEAPON_COPY_ID(inventoryId, (Any*)guid);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_ARE_LOCAL_CHANGES_ALLOWED(int inventoryId)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_ARE_LOCAL_CHANGES_ALLOWED(inventoryId);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_IS_GUID_VALID(uintptr_t guid)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_IS_GUID_VALID((Any*)guid);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_COMPARE_GUIDS(uintptr_t guid1, uintptr_t guid2)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_COMPARE_GUIDS((Any*)guid1, (Any*)guid2);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY_INVENTORY_GET_GUID_FROM_ITEMID(int inventoryId, uintptr_t guid, Hash p2, Hash slotId, uintptr_t outGuid)
	{
		auto retval = (bool)INVENTORY::INVENTORY_GET_GUID_FROM_ITEMID(inventoryId, (Any*)guid, p2, slotId, (Any*)outGuid);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__0x5D6182F3BCE1333B(int inventoryId, Hash removeReason)
	{
		auto retval = (bool)INVENTORY::_0x5D6182F3BCE1333B(inventoryId, removeReason);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY_INVENTORY_GET_INVENTORY_ITEM(int inventoryId, uintptr_t inData, uintptr_t outData, bool p3)
	{
		auto retval = (bool)INVENTORY::INVENTORY_GET_INVENTORY_ITEM(inventoryId, (Any*)inData, (Any*)outData, p3);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_GET_FULL_INVENTORY_ITEM_DATA(int inventoryId, uintptr_t guid, uintptr_t p2, int p3, int p4)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_GET_FULL_INVENTORY_ITEM_DATA(inventoryId, (Any*)guid, (Any*)p2, p3, p4);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_CHILD(int inventoryId, uintptr_t parentGuid, Any childIndex, uintptr_t outInventoryItem)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_GET_INVENTORY_ITEM_CHILD(inventoryId, (Any*)parentGuid, childIndex, (Any*)outInventoryItem);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_ADD_ITEM_WITH_GUID(int inventoryId, uintptr_t guid1, uintptr_t guid2, Hash item, Hash inventoryItemSlot, int p5, Hash addReason)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_ADD_ITEM_WITH_GUID(inventoryId, (Any*)guid1, (Any*)guid2, item, inventoryItemSlot, p5, addReason);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_UPDATE_INVENTORY_ITEM(int inventoryId, uintptr_t guid1, uintptr_t guid2, int p3)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_UPDATE_INVENTORY_ITEM(inventoryId, (Any*)guid1, (Any*)guid2, p3);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_REMOVE_INVENTORY_ITEM_WITH_GUID(int inventoryId, uintptr_t guid, int quantity, Hash removeReason)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_REMOVE_INVENTORY_ITEM_WITH_GUID(inventoryId, (Any*)guid, quantity, removeReason);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_REMOVE_INVENTORY_ITEM_WITH_ITEMID(int inventoryId, Hash item, int quantity, Hash removeReason)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_REMOVE_INVENTORY_ITEM_WITH_ITEMID(inventoryId, item, quantity, removeReason);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_MOVE_INVENTORY_ITEM(int inventoryId, uintptr_t guid1, uintptr_t guid2, Hash slotId, int quantity, uintptr_t outGuid)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_MOVE_INVENTORY_ITEM(inventoryId, (Any*)guid1, (Any*)guid2, slotId, quantity, (Any*)outGuid);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_SWAP_INVENTORY_ITEM(int inventoryId, uintptr_t guid1, uintptr_t guid2)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_SWAP_INVENTORY_ITEM(inventoryId, (Any*)guid1, (Any*)guid2);
		return retval;
	}

	static std::tuple<int, int> LUA_NATIVE_INVENTORY__INVENTORY_CREATE_ITEM_COLLECTION(int inventoryId, sol::stack_object filterName, Hash slotId, int size)
	{
		std::tuple<int, int> return_values;
		std::get<0>(return_values) = INVENTORY::_INVENTORY_CREATE_ITEM_COLLECTION(inventoryId, filterName.is<const char*>() ? filterName.as<const char*>() : nullptr, slotId, &size);
		std::get<1>(return_values) = size;

		return return_values;
	}

	static std::tuple<int, int> LUA_NATIVE_INVENTORY__INVENTORY_CREATE_ITEM_COLLECTION_WITH_FILTER(int inventoryId, uintptr_t filter, int numInCollection)
	{
		std::tuple<int, int> return_values;
		std::get<0>(return_values) = INVENTORY::_INVENTORY_CREATE_ITEM_COLLECTION_WITH_FILTER(inventoryId, (Any*)filter, &numInCollection);
		std::get<1>(return_values) = numInCollection;

		return return_values;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_GET_ITEM_FROM_COLLECTION_INDEX(int collectionId, int itemIndex, uintptr_t itemData)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_GET_ITEM_FROM_COLLECTION_INDEX(collectionId, itemIndex, (Any*)itemData);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_RELEASE_ITEM_COLLECTION(int collectionId)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_RELEASE_ITEM_COLLECTION(collectionId);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_EQUIP_ITEM_WITH_GUID(int inventoryId, uintptr_t guid, bool bEquipped)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_EQUIP_ITEM_WITH_GUID(inventoryId, (Any*)guid, bEquipped);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_EQUIPPED_IN_SLOT_BY_REF(int inventoryId, uintptr_t guid, Hash slotId, uintptr_t outGuid)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_GET_INVENTORY_ITEM_EQUIPPED_IN_SLOT_BY_REF(inventoryId, (Any*)guid, slotId, (Any*)outGuid);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_DOES_ITEM_OWN_EQUIPMENT(int inventoryId, uintptr_t guid, Hash item)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_DOES_ITEM_OWN_EQUIPMENT(inventoryId, (Any*)guid, item);
		return retval;
	}

	static std::tuple<bool, int, int> LUA_NATIVE_INVENTORY__0xD08685BA892DBFAB(int inventoryId, uintptr_t guid, int p2, int p3)
	{
		std::tuple<bool, int, int> return_values;
		std::get<0>(return_values) = (bool)INVENTORY::_0xD08685BA892DBFAB(inventoryId, (Any*)guid, &p2, &p3);
		std::get<1>(return_values) = p2;
		std::get<2>(return_values) = p3;

		return return_values;
	}

	static void LUA_NATIVE_INVENTORY__0x0349404A22736740(bool p0, int inventoryId, uintptr_t guid)
	{
		INVENTORY::_0x0349404A22736740(p0, inventoryId, (Any*)guid);
	}

	static void LUA_NATIVE_INVENTORY__INVENTORY_SET_INVENTORY_ITEM_WEATHER_EFFECTIVENESS(int inventoryId, uintptr_t guid, int weatherEffectiveness)
	{
		INVENTORY::_INVENTORY_SET_INVENTORY_ITEM_WEATHER_EFFECTIVENESS(inventoryId, (Any*)guid, weatherEffectiveness);
	}

	static void LUA_NATIVE_INVENTORY__INVENTORY_DISABLE_ITEM(int inventoryId, Hash item, Hash gtxReason)
	{
		INVENTORY::_INVENTORY_DISABLE_ITEM(inventoryId, item, gtxReason);
	}

	static void LUA_NATIVE_INVENTORY__INVENTORY_ENABLE_ITEM(int inventoryId, Hash item)
	{
		INVENTORY::_INVENTORY_ENABLE_ITEM(inventoryId, item);
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_IS_INVENTORY_ITEM_EQUIPPED(int inventoryId, Hash item, bool p2)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_IS_INVENTORY_ITEM_EQUIPPED(inventoryId, item, p2);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_SET_INVENTORY_ITEM_INSPECTION_ENABLED(int inventoryId, uintptr_t p1, bool enabled)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_SET_INVENTORY_ITEM_INSPECTION_ENABLED(inventoryId, (Any*)p1, enabled);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_IS_ITEM_EXPIRED(uintptr_t itemGUID)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_IS_ITEM_EXPIRED((Any*)itemGUID);
		return retval;
	}

	static int LUA_NATIVE_INVENTORY__INVENTORY_GET_ITEM_EXPIRY_TIME(uintptr_t itemGUID)
	{
		auto retval = INVENTORY::_INVENTORY_GET_ITEM_EXPIRY_TIME((Any*)itemGUID);
		return retval;
	}

	static int LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_COUNT_WITH_GUID(int inventoryId, uintptr_t guid, bool p2)
	{
		auto retval = INVENTORY::_INVENTORY_GET_INVENTORY_ITEM_COUNT_WITH_GUID(inventoryId, (Any*)guid, p2);
		return retval;
	}

	static int LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_COUNT_WITH_ITEMID(int inventoryId, Hash eInventoryItem, bool p2)
	{
		auto retval = INVENTORY::_INVENTORY_GET_INVENTORY_ITEM_COUNT_WITH_ITEMID(inventoryId, eInventoryItem, p2);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__0xB1DD74A1F5536622(int inventoryId, uintptr_t itemGUID)
	{
		auto retval = (bool)INVENTORY::_0xB1DD74A1F5536622(inventoryId, (Any*)itemGUID);
		return retval;
	}

	static int LUA_NATIVE_INVENTORY__INVENTORY_GET_CHILDREN_COUNT(int inventoryId, uintptr_t parentGuid)
	{
		auto retval = INVENTORY::_INVENTORY_GET_CHILDREN_COUNT(inventoryId, (Any*)parentGuid);
		return retval;
	}

	static int LUA_NATIVE_INVENTORY_INVENTORY_GET_CHILDREN_IN_SLOT_COUNT(int inventoryId, uintptr_t guid, Hash slotId)
	{
		auto retval = INVENTORY::INVENTORY_GET_CHILDREN_IN_SLOT_COUNT(inventoryId, (Any*)guid, slotId);
		return retval;
	}

	static int LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_EQUIPPED_IN_SLOT(int inventoryId, uintptr_t guid, Hash slotId, int p3, uintptr_t p4)
	{
		auto retval = INVENTORY::_INVENTORY_GET_INVENTORY_ITEM_EQUIPPED_IN_SLOT(inventoryId, (Any*)guid, slotId, p3, (Any*)p4);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_FITS_SLOT_ID(Hash item, Hash slotId)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_FITS_SLOT_ID(item, slotId);
		return retval;
	}

	static Hash LUA_NATIVE_INVENTORY__GET_DEFAULT_ITEM_SLOT_INFO(Hash item, Hash p1)
	{
		auto retval = INVENTORY::_GET_DEFAULT_ITEM_SLOT_INFO(item, p1);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_FIT_SLOT(Hash p0, uintptr_t p1, int p2)
	{
		auto retval = (bool)INVENTORY::_INVENTORY_GET_INVENTORY_ITEM_FIT_SLOT(p0, (Any*)p1, p2);
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__0x9AC53CB6907B4428(Hash item, uintptr_t p1, uintptr_t p2)
	{
		auto retval = (bool)INVENTORY::_0x9AC53CB6907B4428(item, (Any*)p1, (Any*)p2);
		return retval;
	}

	static Hash LUA_NATIVE_INVENTORY__0x9D21B185ABC2DBC4(Any data, sol::stack_object effects, bool p2, bool p3)
	{
		auto retval = INVENTORY::_0x9D21B185ABC2DBC4(data, effects.is<const char*>() ? effects.as<const char*>() : nullptr, p2, p3);
		return retval;
	}

	static void LUA_NATIVE_INVENTORY__0x75CFAC49301E134F(Hash databindingEntryId, bool p1, bool p2)
	{
		INVENTORY::_0x75CFAC49301E134F(databindingEntryId, p1, p2);
	}

	static Hash LUA_NATIVE_INVENTORY__0x9D21B185ABC2DBC5(Any data, sol::stack_object stats, int p2, int p3)
	{
		auto retval = INVENTORY::_0x9D21B185ABC2DBC5(data, stats.is<const char*>() ? stats.as<const char*>() : nullptr, p2, p3);
		return retval;
	}

	static void LUA_NATIVE_INVENTORY__0x75CFAC49301E134E(Any data, bool p1, Ped ped)
	{
		INVENTORY::_0x75CFAC49301E134E(data, p1, ped);
	}

	static Hash LUA_NATIVE_INVENTORY__0x46DB71883EE9D5AF(Any data, sol::stack_object stats, uintptr_t guid, Ped ped)
	{
		auto retval = INVENTORY::_0x46DB71883EE9D5AF(data, stats.is<const char*>() ? stats.as<const char*>() : nullptr, (Any*)guid, ped);
		return retval;
	}

	static void LUA_NATIVE_INVENTORY__0x951847CEF3D829FF(Any p0, uintptr_t outGuid, Ped ped)
	{
		INVENTORY::_0x951847CEF3D829FF(p0, (Any*)outGuid, ped);
	}

	static bool LUA_NATIVE_INVENTORY__0x6862E4D93F64CF01(int inventoryId, uintptr_t guid, Hash p2, uintptr_t p3)
	{
		auto retval = (bool)INVENTORY::_0x6862E4D93F64CF01(inventoryId, (Any*)guid, p2, (Any*)p3);
		return retval;
	}

	static void LUA_NATIVE_INVENTORY__SET_USE_MISSION_INVENTORY(bool toggle)
	{
		INVENTORY::_SET_USE_MISSION_INVENTORY(toggle);
	}

	static void LUA_NATIVE_INVENTORY_INVENTORY_DISABLE_MISSION_INVENTORY_PICKUPS()
	{
		INVENTORY::INVENTORY_DISABLE_MISSION_INVENTORY_PICKUPS();
	}

	static void LUA_NATIVE_INVENTORY__INVENTORY_USE_MISSION_INVENTORY(bool enable, bool mirrorTransactions)
	{
		INVENTORY::_INVENTORY_USE_MISSION_INVENTORY(enable, mirrorTransactions);
	}

	static void LUA_NATIVE_INVENTORY_INVENTORY_COPY_MP_INVENTORY_TO_MISSION_INVENTORY(bool p0, bool p1, bool bCopySatchelItems, bool bCopyEmotes, bool bCopyHorse, bool p5)
	{
		INVENTORY::INVENTORY_COPY_MP_INVENTORY_TO_MISSION_INVENTORY(p0, p1, bCopySatchelItems, bCopyEmotes, bCopyHorse, p5);
	}

	static void LUA_NATIVE_INVENTORY__INVENTORY_COPY_ITEM_TO_MISSION_INVENTORY(uintptr_t guid, bool p1)
	{
		INVENTORY::_INVENTORY_COPY_ITEM_TO_MISSION_INVENTORY((Any*)guid, p1);
	}

	static void LUA_NATIVE_INVENTORY__0xE36D4A38D28D9CFB(bool p0)
	{
		INVENTORY::_0xE36D4A38D28D9CFB(p0);
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_USE_SP_BACKUP()
	{
		auto retval = (bool)INVENTORY::_INVENTORY_USE_SP_BACKUP();
		return retval;
	}

	static bool LUA_NATIVE_INVENTORY__INVENTORY_IS_PLAYER_INVENTORY_MIRRORING_TRANSACTIONS()
	{
		auto retval = (bool)INVENTORY::_INVENTORY_IS_PLAYER_INVENTORY_MIRRORING_TRANSACTIONS();
		return retval;
	}

	static void LUA_NATIVE_INVENTORY__INVENTORY_COPY_ITEM_TO_INVENTORY(int inventoryId, int inventoryIdCloned, uintptr_t p2, Any p3)
	{
		INVENTORY::_INVENTORY_COPY_ITEM_TO_INVENTORY(inventoryId, inventoryIdCloned, (Any*)p2, p3);
	}

	static void LUA_NATIVE_INVENTORY__0x9E58207B194488AC(Ped ped, int p1)
	{
		INVENTORY::_0x9E58207B194488AC(ped, p1);
	}

	static void LUA_NATIVE_INVENTORY__SET_ITEM_PROMPT_INFO_REQUEST(uintptr_t p0)
	{
		INVENTORY::_SET_ITEM_PROMPT_INFO_REQUEST((Any*)p0);
	}

	static void LUA_NATIVE_INVENTORY__0x9B4E793B1CB6550A()
	{
		INVENTORY::_0x9B4E793B1CB6550A();
	}

	static void LUA_NATIVE_INVENTORY__SET_CARRIABLE_CARRY_ACTION_PROMPT_OVERRIDE(uintptr_t data)
	{
		INVENTORY::_SET_CARRIABLE_CARRY_ACTION_PROMPT_OVERRIDE((Any*)data);
	}

	static void LUA_NATIVE_INVENTORY__INVENTORY_ENABLE_WEAPONS(int inventoryId)
	{
		INVENTORY::_INVENTORY_ENABLE_WEAPONS(inventoryId);
	}

	static void LUA_NATIVE_INVENTORY__INVENTORY_DISABLE_WEAPONS(int inventoryId, Any p1)
	{
		INVENTORY::_INVENTORY_DISABLE_WEAPONS(inventoryId, p1);
	}

	static void LUA_NATIVE_INVENTORY__0xE1F45A67A9F0DCBC(int inventoryId)
	{
		INVENTORY::_0xE1F45A67A9F0DCBC(inventoryId);
	}

	static void LUA_NATIVE_INVENTORY__0x6968CE7AC32F6788(int inventoryId)
	{
		INVENTORY::_0x6968CE7AC32F6788(inventoryId);
	}

	static std::tuple<int, int> LUA_NATIVE_INVENTORY__INVENTORY_CREATE_ITEM_COLLECTION_2(int collectionSize)
	{
		std::tuple<int, int> return_values;
		std::get<0>(return_values) = INVENTORY::_INVENTORY_CREATE_ITEM_COLLECTION_2(&collectionSize);
		std::get<1>(return_values) = collectionSize;

		return return_values;
	}

	static std::tuple<int, int> LUA_NATIVE_INVENTORY__INVENTORY_CREATE_SORTED_COLLECTION(int inventoryId, int p1, int size)
	{
		std::tuple<int, int> return_values;
		std::get<0>(return_values) = INVENTORY::_INVENTORY_CREATE_SORTED_COLLECTION(inventoryId, p1, &size);
		std::get<1>(return_values) = size;

		return return_values;
	}

	void RegisterNatives_INVENTORY(sol::state& L)
	{
		auto INVENTORY = L["INVENTORY"].get_or_create<sol::table>();
		INVENTORY.set_function("_INVENTORY_GET_INVENTORY_ID_FROM_PED", LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ID_FROM_PED);
		INVENTORY.set_function("_GET_ITEM_ROLE_MAX_LEVEL_COUNT", LUA_NATIVE_INVENTORY__GET_ITEM_ROLE_MAX_LEVEL_COUNT);
		INVENTORY.set_function("_GET_ITEM_SLOT_MAX_COUNT", LUA_NATIVE_INVENTORY__GET_ITEM_SLOT_MAX_COUNT);
		INVENTORY.set_function("_0x112BCA290D2EB53C", LUA_NATIVE_INVENTORY__0x112BCA290D2EB53C);
		INVENTORY.set_function("_0x46743BBFEDBC859E", LUA_NATIVE_INVENTORY__0x46743BBFEDBC859E);
		INVENTORY.set_function("_INVENTORY_SET_INVENTORY_ITEM_IN_USE", LUA_NATIVE_INVENTORY__INVENTORY_SET_INVENTORY_ITEM_IN_USE);
		INVENTORY.set_function("_INVENTORY_GET_INVENTORY_ITEM_IN_USE", LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_IN_USE);
		INVENTORY.set_function("_INVENTORY_SET_INVENTORY_ITEM_HIDDEN", LUA_NATIVE_INVENTORY__INVENTORY_SET_INVENTORY_ITEM_HIDDEN);
		INVENTORY.set_function("_INVENTORY_SET_INVENTORY_ITEM_HIDDEN_2", LUA_NATIVE_INVENTORY__INVENTORY_SET_INVENTORY_ITEM_HIDDEN_2);
		INVENTORY.set_function("_INVENTORY_GET_INVENTORY_ITEM_HIDDEN", LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_HIDDEN);
		INVENTORY.set_function("_INVENTORY_GET_INVENTORY_ITEM_IS_ANIMAL_PELT", LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_IS_ANIMAL_PELT);
		INVENTORY.set_function("_INVENTORY_GET_INVENTORY_ITEM_DESCRIPTION_HASH", LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_DESCRIPTION_HASH);
		INVENTORY.set_function("_INVENTORY_IS_INVENTORY_ITEM_FLAG_ENABLED", LUA_NATIVE_INVENTORY__INVENTORY_IS_INVENTORY_ITEM_FLAG_ENABLED);
		INVENTORY.set_function("_INVENTORY_GET_IS_INVENTORY_ITEM_SOUND_VALID", LUA_NATIVE_INVENTORY__INVENTORY_GET_IS_INVENTORY_ITEM_SOUND_VALID);
		INVENTORY.set_function("_INVENTORY_GET_INVENTORY_ITEM_SOUND", LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_SOUND);
		INVENTORY.set_function("_INVENTORY_GET_INVENTORY_ITEM_INSPECTION_INFO", LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_INSPECTION_INFO);
		INVENTORY.set_function("_INVENTORY_GET_INVENTORY_ITEM_WEAPON_COPY_ID", LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_WEAPON_COPY_ID);
		INVENTORY.set_function("_INVENTORY_ARE_LOCAL_CHANGES_ALLOWED", LUA_NATIVE_INVENTORY__INVENTORY_ARE_LOCAL_CHANGES_ALLOWED);
		INVENTORY.set_function("_INVENTORY_IS_GUID_VALID", LUA_NATIVE_INVENTORY__INVENTORY_IS_GUID_VALID);
		INVENTORY.set_function("_INVENTORY_COMPARE_GUIDS", LUA_NATIVE_INVENTORY__INVENTORY_COMPARE_GUIDS);
		INVENTORY.set_function("INVENTORY_GET_GUID_FROM_ITEMID", LUA_NATIVE_INVENTORY_INVENTORY_GET_GUID_FROM_ITEMID);
		INVENTORY.set_function("_0x5D6182F3BCE1333B", LUA_NATIVE_INVENTORY__0x5D6182F3BCE1333B);
		INVENTORY.set_function("INVENTORY_GET_INVENTORY_ITEM", LUA_NATIVE_INVENTORY_INVENTORY_GET_INVENTORY_ITEM);
		INVENTORY.set_function("_INVENTORY_GET_FULL_INVENTORY_ITEM_DATA", LUA_NATIVE_INVENTORY__INVENTORY_GET_FULL_INVENTORY_ITEM_DATA);
		INVENTORY.set_function("_INVENTORY_GET_INVENTORY_ITEM_CHILD", LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_CHILD);
		INVENTORY.set_function("_INVENTORY_ADD_ITEM_WITH_GUID", LUA_NATIVE_INVENTORY__INVENTORY_ADD_ITEM_WITH_GUID);
		INVENTORY.set_function("_INVENTORY_UPDATE_INVENTORY_ITEM", LUA_NATIVE_INVENTORY__INVENTORY_UPDATE_INVENTORY_ITEM);
		INVENTORY.set_function("_INVENTORY_REMOVE_INVENTORY_ITEM_WITH_GUID", LUA_NATIVE_INVENTORY__INVENTORY_REMOVE_INVENTORY_ITEM_WITH_GUID);
		INVENTORY.set_function("_INVENTORY_REMOVE_INVENTORY_ITEM_WITH_ITEMID", LUA_NATIVE_INVENTORY__INVENTORY_REMOVE_INVENTORY_ITEM_WITH_ITEMID);
		INVENTORY.set_function("_INVENTORY_MOVE_INVENTORY_ITEM", LUA_NATIVE_INVENTORY__INVENTORY_MOVE_INVENTORY_ITEM);
		INVENTORY.set_function("_INVENTORY_SWAP_INVENTORY_ITEM", LUA_NATIVE_INVENTORY__INVENTORY_SWAP_INVENTORY_ITEM);
		INVENTORY.set_function("_INVENTORY_CREATE_ITEM_COLLECTION", LUA_NATIVE_INVENTORY__INVENTORY_CREATE_ITEM_COLLECTION);
		INVENTORY.set_function("_INVENTORY_CREATE_ITEM_COLLECTION_WITH_FILTER", LUA_NATIVE_INVENTORY__INVENTORY_CREATE_ITEM_COLLECTION_WITH_FILTER);
		INVENTORY.set_function("_INVENTORY_GET_ITEM_FROM_COLLECTION_INDEX", LUA_NATIVE_INVENTORY__INVENTORY_GET_ITEM_FROM_COLLECTION_INDEX);
		INVENTORY.set_function("_INVENTORY_RELEASE_ITEM_COLLECTION", LUA_NATIVE_INVENTORY__INVENTORY_RELEASE_ITEM_COLLECTION);
		INVENTORY.set_function("_INVENTORY_EQUIP_ITEM_WITH_GUID", LUA_NATIVE_INVENTORY__INVENTORY_EQUIP_ITEM_WITH_GUID);
		INVENTORY.set_function("_INVENTORY_GET_INVENTORY_ITEM_EQUIPPED_IN_SLOT_BY_REF", LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_EQUIPPED_IN_SLOT_BY_REF);
		INVENTORY.set_function("_INVENTORY_DOES_ITEM_OWN_EQUIPMENT", LUA_NATIVE_INVENTORY__INVENTORY_DOES_ITEM_OWN_EQUIPMENT);
		INVENTORY.set_function("_0xD08685BA892DBFAB", LUA_NATIVE_INVENTORY__0xD08685BA892DBFAB);
		INVENTORY.set_function("_0x0349404A22736740", LUA_NATIVE_INVENTORY__0x0349404A22736740);
		INVENTORY.set_function("_INVENTORY_SET_INVENTORY_ITEM_WEATHER_EFFECTIVENESS", LUA_NATIVE_INVENTORY__INVENTORY_SET_INVENTORY_ITEM_WEATHER_EFFECTIVENESS);
		INVENTORY.set_function("_INVENTORY_DISABLE_ITEM", LUA_NATIVE_INVENTORY__INVENTORY_DISABLE_ITEM);
		INVENTORY.set_function("_INVENTORY_ENABLE_ITEM", LUA_NATIVE_INVENTORY__INVENTORY_ENABLE_ITEM);
		INVENTORY.set_function("_INVENTORY_IS_INVENTORY_ITEM_EQUIPPED", LUA_NATIVE_INVENTORY__INVENTORY_IS_INVENTORY_ITEM_EQUIPPED);
		INVENTORY.set_function("_INVENTORY_SET_INVENTORY_ITEM_INSPECTION_ENABLED", LUA_NATIVE_INVENTORY__INVENTORY_SET_INVENTORY_ITEM_INSPECTION_ENABLED);
		INVENTORY.set_function("_INVENTORY_IS_ITEM_EXPIRED", LUA_NATIVE_INVENTORY__INVENTORY_IS_ITEM_EXPIRED);
		INVENTORY.set_function("_INVENTORY_GET_ITEM_EXPIRY_TIME", LUA_NATIVE_INVENTORY__INVENTORY_GET_ITEM_EXPIRY_TIME);
		INVENTORY.set_function("_INVENTORY_GET_INVENTORY_ITEM_COUNT_WITH_GUID", LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_COUNT_WITH_GUID);
		INVENTORY.set_function("_INVENTORY_GET_INVENTORY_ITEM_COUNT_WITH_ITEMID", LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_COUNT_WITH_ITEMID);
		INVENTORY.set_function("_0xB1DD74A1F5536622", LUA_NATIVE_INVENTORY__0xB1DD74A1F5536622);
		INVENTORY.set_function("_INVENTORY_GET_CHILDREN_COUNT", LUA_NATIVE_INVENTORY__INVENTORY_GET_CHILDREN_COUNT);
		INVENTORY.set_function("INVENTORY_GET_CHILDREN_IN_SLOT_COUNT", LUA_NATIVE_INVENTORY_INVENTORY_GET_CHILDREN_IN_SLOT_COUNT);
		INVENTORY.set_function("_INVENTORY_GET_INVENTORY_ITEM_EQUIPPED_IN_SLOT", LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_EQUIPPED_IN_SLOT);
		INVENTORY.set_function("_INVENTORY_FITS_SLOT_ID", LUA_NATIVE_INVENTORY__INVENTORY_FITS_SLOT_ID);
		INVENTORY.set_function("_GET_DEFAULT_ITEM_SLOT_INFO", LUA_NATIVE_INVENTORY__GET_DEFAULT_ITEM_SLOT_INFO);
		INVENTORY.set_function("_INVENTORY_GET_INVENTORY_ITEM_FIT_SLOT", LUA_NATIVE_INVENTORY__INVENTORY_GET_INVENTORY_ITEM_FIT_SLOT);
		INVENTORY.set_function("_0x9AC53CB6907B4428", LUA_NATIVE_INVENTORY__0x9AC53CB6907B4428);
		INVENTORY.set_function("_0x9D21B185ABC2DBC4", LUA_NATIVE_INVENTORY__0x9D21B185ABC2DBC4);
		INVENTORY.set_function("_0x75CFAC49301E134F", LUA_NATIVE_INVENTORY__0x75CFAC49301E134F);
		INVENTORY.set_function("_0x9D21B185ABC2DBC5", LUA_NATIVE_INVENTORY__0x9D21B185ABC2DBC5);
		INVENTORY.set_function("_0x75CFAC49301E134E", LUA_NATIVE_INVENTORY__0x75CFAC49301E134E);
		INVENTORY.set_function("_0x46DB71883EE9D5AF", LUA_NATIVE_INVENTORY__0x46DB71883EE9D5AF);
		INVENTORY.set_function("_0x951847CEF3D829FF", LUA_NATIVE_INVENTORY__0x951847CEF3D829FF);
		INVENTORY.set_function("_0x6862E4D93F64CF01", LUA_NATIVE_INVENTORY__0x6862E4D93F64CF01);
		INVENTORY.set_function("_SET_USE_MISSION_INVENTORY", LUA_NATIVE_INVENTORY__SET_USE_MISSION_INVENTORY);
		INVENTORY.set_function("INVENTORY_DISABLE_MISSION_INVENTORY_PICKUPS", LUA_NATIVE_INVENTORY_INVENTORY_DISABLE_MISSION_INVENTORY_PICKUPS);
		INVENTORY.set_function("_INVENTORY_USE_MISSION_INVENTORY", LUA_NATIVE_INVENTORY__INVENTORY_USE_MISSION_INVENTORY);
		INVENTORY.set_function("INVENTORY_COPY_MP_INVENTORY_TO_MISSION_INVENTORY", LUA_NATIVE_INVENTORY_INVENTORY_COPY_MP_INVENTORY_TO_MISSION_INVENTORY);
		INVENTORY.set_function("_INVENTORY_COPY_ITEM_TO_MISSION_INVENTORY", LUA_NATIVE_INVENTORY__INVENTORY_COPY_ITEM_TO_MISSION_INVENTORY);
		INVENTORY.set_function("_0xE36D4A38D28D9CFB", LUA_NATIVE_INVENTORY__0xE36D4A38D28D9CFB);
		INVENTORY.set_function("_INVENTORY_USE_SP_BACKUP", LUA_NATIVE_INVENTORY__INVENTORY_USE_SP_BACKUP);
		INVENTORY.set_function("_INVENTORY_IS_PLAYER_INVENTORY_MIRRORING_TRANSACTIONS", LUA_NATIVE_INVENTORY__INVENTORY_IS_PLAYER_INVENTORY_MIRRORING_TRANSACTIONS);
		INVENTORY.set_function("_INVENTORY_COPY_ITEM_TO_INVENTORY", LUA_NATIVE_INVENTORY__INVENTORY_COPY_ITEM_TO_INVENTORY);
		INVENTORY.set_function("_0x9E58207B194488AC", LUA_NATIVE_INVENTORY__0x9E58207B194488AC);
		INVENTORY.set_function("_SET_ITEM_PROMPT_INFO_REQUEST", LUA_NATIVE_INVENTORY__SET_ITEM_PROMPT_INFO_REQUEST);
		INVENTORY.set_function("_0x9B4E793B1CB6550A", LUA_NATIVE_INVENTORY__0x9B4E793B1CB6550A);
		INVENTORY.set_function("_SET_CARRIABLE_CARRY_ACTION_PROMPT_OVERRIDE", LUA_NATIVE_INVENTORY__SET_CARRIABLE_CARRY_ACTION_PROMPT_OVERRIDE);
		INVENTORY.set_function("_INVENTORY_ENABLE_WEAPONS", LUA_NATIVE_INVENTORY__INVENTORY_ENABLE_WEAPONS);
		INVENTORY.set_function("_INVENTORY_DISABLE_WEAPONS", LUA_NATIVE_INVENTORY__INVENTORY_DISABLE_WEAPONS);
		INVENTORY.set_function("_0xE1F45A67A9F0DCBC", LUA_NATIVE_INVENTORY__0xE1F45A67A9F0DCBC);
		INVENTORY.set_function("_0x6968CE7AC32F6788", LUA_NATIVE_INVENTORY__0x6968CE7AC32F6788);
		INVENTORY.set_function("_INVENTORY_CREATE_ITEM_COLLECTION_2", LUA_NATIVE_INVENTORY__INVENTORY_CREATE_ITEM_COLLECTION_2);
		INVENTORY.set_function("_INVENTORY_CREATE_SORTED_COLLECTION", LUA_NATIVE_INVENTORY__INVENTORY_CREATE_SORTED_COLLECTION);
	}
}
