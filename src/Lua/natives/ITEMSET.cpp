#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static ItemSet LUA_NATIVE_ITEMSET_CREATE_ITEMSET(bool autoClean)
	{
		auto retval = ITEMSET::CREATE_ITEMSET(autoClean);
		return retval;
	}

	static void LUA_NATIVE_ITEMSET_DESTROY_ITEMSET(ItemSet itemSet)
	{
		ITEMSET::DESTROY_ITEMSET(itemSet);
	}

	static bool LUA_NATIVE_ITEMSET_IS_ITEMSET_VALID(ItemSet itemSet)
	{
		auto retval = (bool)ITEMSET::IS_ITEMSET_VALID(itemSet);
		return retval;
	}

	static bool LUA_NATIVE_ITEMSET_ADD_TO_ITEMSET(ScrHandle itemToAdd, ItemSet itemSetToAddTo)
	{
		auto retval = (bool)ITEMSET::ADD_TO_ITEMSET(itemToAdd, itemSetToAddTo);
		return retval;
	}

	static void LUA_NATIVE_ITEMSET_REMOVE_FROM_ITEMSET(ScrHandle itemToRemove, ItemSet itemSetToRemoveFrom)
	{
		ITEMSET::REMOVE_FROM_ITEMSET(itemToRemove, itemSetToRemoveFrom);
	}

	static int LUA_NATIVE_ITEMSET_GET_ITEMSET_SIZE(ItemSet itemSet)
	{
		auto retval = ITEMSET::GET_ITEMSET_SIZE(itemSet);
		return retval;
	}

	static ScrHandle LUA_NATIVE_ITEMSET_GET_INDEXED_ITEM_IN_ITEMSET(int indexInSet, ItemSet itemSet)
	{
		auto retval = ITEMSET::GET_INDEXED_ITEM_IN_ITEMSET(indexInSet, itemSet);
		return retval;
	}

	static Any LUA_NATIVE_ITEMSET_GET_INDEXED_SCENARIO_POINT_INDEX_IN_ITEMSET(int index, ItemSet itemset)
	{
		auto retval = ITEMSET::GET_INDEXED_SCENARIO_POINT_INDEX_IN_ITEMSET(index, itemset);
		return retval;
	}

	static bool LUA_NATIVE_ITEMSET_IS_IN_ITEMSET(ScrHandle objToCheck, ItemSet itemSet)
	{
		auto retval = (bool)ITEMSET::IS_IN_ITEMSET(objToCheck, itemSet);
		return retval;
	}

	static void LUA_NATIVE_ITEMSET_CLEAN_ITEMSET(ItemSet itemSet)
	{
		ITEMSET::CLEAN_ITEMSET(itemSet);
	}

	static void LUA_NATIVE_ITEMSET__CLEAR_ITEMSET(ItemSet itemset)
	{
		ITEMSET::_CLEAR_ITEMSET(itemset);
	}

	void RegisterNatives_ITEMSET(sol::state& L)
	{
		auto ITEMSET = L["ITEMSET"].get_or_create<sol::table>();
		ITEMSET.set_function("CREATE_ITEMSET", LUA_NATIVE_ITEMSET_CREATE_ITEMSET);
		ITEMSET.set_function("DESTROY_ITEMSET", LUA_NATIVE_ITEMSET_DESTROY_ITEMSET);
		ITEMSET.set_function("IS_ITEMSET_VALID", LUA_NATIVE_ITEMSET_IS_ITEMSET_VALID);
		ITEMSET.set_function("ADD_TO_ITEMSET", LUA_NATIVE_ITEMSET_ADD_TO_ITEMSET);
		ITEMSET.set_function("REMOVE_FROM_ITEMSET", LUA_NATIVE_ITEMSET_REMOVE_FROM_ITEMSET);
		ITEMSET.set_function("GET_ITEMSET_SIZE", LUA_NATIVE_ITEMSET_GET_ITEMSET_SIZE);
		ITEMSET.set_function("GET_INDEXED_ITEM_IN_ITEMSET", LUA_NATIVE_ITEMSET_GET_INDEXED_ITEM_IN_ITEMSET);
		ITEMSET.set_function("GET_INDEXED_SCENARIO_POINT_INDEX_IN_ITEMSET", LUA_NATIVE_ITEMSET_GET_INDEXED_SCENARIO_POINT_INDEX_IN_ITEMSET);
		ITEMSET.set_function("IS_IN_ITEMSET", LUA_NATIVE_ITEMSET_IS_IN_ITEMSET);
		ITEMSET.set_function("CLEAN_ITEMSET", LUA_NATIVE_ITEMSET_CLEAN_ITEMSET);
		ITEMSET.set_function("_CLEAR_ITEMSET", LUA_NATIVE_ITEMSET__CLEAR_ITEMSET);
	}
}
