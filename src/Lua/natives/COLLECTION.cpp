#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static Hash LUA_NATIVE_COLLECTION__COLLECTABLE_GET_CATEGORY(Hash collectableItem)
	{
		auto retval = COLLECTION::_COLLECTABLE_GET_CATEGORY(collectableItem);
		return retval;
	}

	static Hash LUA_NATIVE_COLLECTION__COLLECTABLE_GET_SUBCATEGORY(Hash collectableItem)
	{
		auto retval = COLLECTION::_COLLECTABLE_GET_SUBCATEGORY(collectableItem);
		return retval;
	}

	static Hash LUA_NATIVE_COLLECTION__COLLECTABLE_GET_IPL(Hash collectableItem)
	{
		auto retval = COLLECTION::_COLLECTABLE_GET_IPL(collectableItem);
		return retval;
	}

	static Vector3 LUA_NATIVE_COLLECTION__COLLECTABLE_GET_PLACEMENT_LOCATION(Hash collectableItem)
	{
		auto retval = COLLECTION::_COLLECTABLE_GET_PLACEMENT_LOCATION(collectableItem);
		return retval;
	}

	static int LUA_NATIVE_COLLECTION__COLLECTABLE_GET_NUM_FOUND(Hash collectableItem)
	{
		auto retval = COLLECTION::_COLLECTABLE_GET_NUM_FOUND(collectableItem);
		return retval;
	}

	static int LUA_NATIVE_COLLECTION__COLLECTABLE_GET_NUM_TURNED_IN(Hash collectableItem)
	{
		auto retval = COLLECTION::_COLLECTABLE_GET_NUM_TURNED_IN(collectableItem);
		return retval;
	}

	static void LUA_NATIVE_COLLECTION__COLLECTABLE_INCREMENT_NUM_FOUND(Hash collectableItem, int amount)
	{
		COLLECTION::_COLLECTABLE_INCREMENT_NUM_FOUND(collectableItem, amount);
	}

	static void LUA_NATIVE_COLLECTION__COLLECTABLE_INCREMENT_NUM_TURNED_IN(Hash collectableItem, int amount)
	{
		COLLECTION::_COLLECTABLE_INCREMENT_NUM_TURNED_IN(collectableItem, amount);
	}

	static int LUA_NATIVE_COLLECTION__COLLECTABLE_CATEGORY_GET_NUM_COLLECTABLES(Hash collectableCategory, Hash collectableSubcategory)
	{
		auto retval = COLLECTION::_COLLECTABLE_CATEGORY_GET_NUM_COLLECTABLES(collectableCategory, collectableSubcategory);
		return retval;
	}

	static Hash LUA_NATIVE_COLLECTION__COLLECTABLE_GET_COLLECTABLE_ITEM_HASH(int index, Hash collectableCategory, Hash collectableSubcategory)
	{
		auto retval = COLLECTION::_COLLECTABLE_GET_COLLECTABLE_ITEM_HASH(index, collectableCategory, collectableSubcategory);
		return retval;
	}

	static int LUA_NATIVE_COLLECTION__COLLECTABLE_CATEGORY_GET_NUM_FOUND(Hash collectableCategory, Hash collectableSubcategory)
	{
		auto retval = COLLECTION::_COLLECTABLE_CATEGORY_GET_NUM_FOUND(collectableCategory, collectableSubcategory);
		return retval;
	}

	static int LUA_NATIVE_COLLECTION__COLLECTABLE_CATEGORY_GET_NUM_TURNED_IN(Hash collectableCategory, Hash collectableSubcategory)
	{
		auto retval = COLLECTION::_COLLECTABLE_CATEGORY_GET_NUM_TURNED_IN(collectableCategory, collectableSubcategory);
		return retval;
	}

	static int LUA_NATIVE_COLLECTION__0x33825A7388A6B9F6(Hash collectableCategory, int p1)
	{
		auto retval = COLLECTION::_0x33825A7388A6B9F6(collectableCategory, p1);
		return retval;
	}

	static int LUA_NATIVE_COLLECTION__0x755901C7598B97BC(Hash collectableCategory, int p1)
	{
		auto retval = COLLECTION::_0x755901C7598B97BC(collectableCategory, p1);
		return retval;
	}

	static Any LUA_NATIVE_COLLECTION__0xB9020EC89C07DF04(Hash collectableCategory, int p1, int index)
	{
		auto retval = COLLECTION::_0xB9020EC89C07DF04(collectableCategory, p1, index);
		return retval;
	}

	static bool LUA_NATIVE_COLLECTION__0xFC832B06127D8E99(Hash collectableCategory, int p1)
	{
		auto retval = (bool)COLLECTION::_0xFC832B06127D8E99(collectableCategory, p1);
		return retval;
	}

	static void LUA_NATIVE_COLLECTION_COLLECTABLE_CATEGORY_SET_HAS_RECEIVED_LIST(Any p0, Any p1, Any p2)
	{
		COLLECTION::COLLECTABLE_CATEGORY_SET_HAS_RECEIVED_LIST(p0, p1, p2);
	}

	static bool LUA_NATIVE_COLLECTION__0x6BAB7ACED1017204(Hash collectableCategory, int p1)
	{
		auto retval = (bool)COLLECTION::_0x6BAB7ACED1017204(collectableCategory, p1);
		return retval;
	}

	static bool LUA_NATIVE_COLLECTION__0x61BEFBA3CE7A3BC8(Hash collectableCategory, int p1)
	{
		auto retval = (bool)COLLECTION::_0x61BEFBA3CE7A3BC8(collectableCategory, p1);
		return retval;
	}

	static Any LUA_NATIVE_COLLECTION__0xC4AC39719C1BB559(Hash collectableCategory, Any p1)
	{
		auto retval = COLLECTION::_0xC4AC39719C1BB559(collectableCategory, p1);
		return retval;
	}

	static Any LUA_NATIVE_COLLECTION__0x93F2E7B5DB85657B(Any p0, Any p1)
	{
		auto retval = COLLECTION::_0x93F2E7B5DB85657B(p0, p1);
		return retval;
	}

	static Hash LUA_NATIVE_COLLECTION_COLLECTABLE_GET_CATEGORY_ITEM_SET_BUY_AWARD(Hash collectableCategory, Hash p1)
	{
		auto retval = COLLECTION::COLLECTABLE_GET_CATEGORY_ITEM_SET_BUY_AWARD(collectableCategory, p1);
		return retval;
	}

	static Hash LUA_NATIVE_COLLECTION__0x9ADEE485726025D4(Hash collectableCategory)
	{
		auto retval = COLLECTION::_0x9ADEE485726025D4(collectableCategory);
		return retval;
	}

	static Any LUA_NATIVE_COLLECTION__0xD1806FB3EDED6D11(Hash collectableCategory, int p1)
	{
		auto retval = COLLECTION::_0xD1806FB3EDED6D11(collectableCategory, p1);
		return retval;
	}

	static Any LUA_NATIVE_COLLECTION__0x3FD91F1A148A0468(Hash collectableCategory, int p1)
	{
		auto retval = COLLECTION::_0x3FD91F1A148A0468(collectableCategory, p1);
		return retval;
	}

	static Any LUA_NATIVE_COLLECTION__0xC3CA424E1F12ED0C(Hash collectableCategory, int p1)
	{
		auto retval = COLLECTION::_0xC3CA424E1F12ED0C(collectableCategory, p1);
		return retval;
	}

	static Hash LUA_NATIVE_COLLECTION__COLLECTABLE_CATEGORY_GET_TOAST_TEXTURE_NAME(Hash collectableCategory, Hash collectableSubcategory)
	{
		auto retval = COLLECTION::_COLLECTABLE_CATEGORY_GET_TOAST_TEXTURE_NAME(collectableCategory, collectableSubcategory);
		return retval;
	}

	static Hash LUA_NATIVE_COLLECTION__COLLECTABLE_CATEGORY_GET_TOAST_TEXTURE_DICTIONARY(Hash collectableCategory, Hash collectableSubcategory)
	{
		auto retval = COLLECTION::_COLLECTABLE_CATEGORY_GET_TOAST_TEXTURE_DICTIONARY(collectableCategory, collectableSubcategory);
		return retval;
	}

	static Any LUA_NATIVE_COLLECTION__0xD297F68928A58130(Hash collectableCategory, int p1)
	{
		auto retval = COLLECTION::_0xD297F68928A58130(collectableCategory, p1);
		return retval;
	}

	static Any LUA_NATIVE_COLLECTION__0x775FA1FC87666847(Hash collectableCategory, int p1)
	{
		auto retval = COLLECTION::_0x775FA1FC87666847(collectableCategory, p1);
		return retval;
	}

	static Any LUA_NATIVE_COLLECTION__0xEC3959E9950BF56B(int p0)
	{
		auto retval = COLLECTION::_0xEC3959E9950BF56B(p0);
		return retval;
	}

	void RegisterNatives_COLLECTION(sol::state& L)
	{
		auto COLLECTION = L["COLLECTION"].get_or_create<sol::table>();
		COLLECTION.set_function("_COLLECTABLE_GET_CATEGORY", LUA_NATIVE_COLLECTION__COLLECTABLE_GET_CATEGORY);
		COLLECTION.set_function("_COLLECTABLE_GET_SUBCATEGORY", LUA_NATIVE_COLLECTION__COLLECTABLE_GET_SUBCATEGORY);
		COLLECTION.set_function("_COLLECTABLE_GET_IPL", LUA_NATIVE_COLLECTION__COLLECTABLE_GET_IPL);
		COLLECTION.set_function("_COLLECTABLE_GET_PLACEMENT_LOCATION", LUA_NATIVE_COLLECTION__COLLECTABLE_GET_PLACEMENT_LOCATION);
		COLLECTION.set_function("_COLLECTABLE_GET_NUM_FOUND", LUA_NATIVE_COLLECTION__COLLECTABLE_GET_NUM_FOUND);
		COLLECTION.set_function("_COLLECTABLE_GET_NUM_TURNED_IN", LUA_NATIVE_COLLECTION__COLLECTABLE_GET_NUM_TURNED_IN);
		COLLECTION.set_function("_COLLECTABLE_INCREMENT_NUM_FOUND", LUA_NATIVE_COLLECTION__COLLECTABLE_INCREMENT_NUM_FOUND);
		COLLECTION.set_function("_COLLECTABLE_INCREMENT_NUM_TURNED_IN", LUA_NATIVE_COLLECTION__COLLECTABLE_INCREMENT_NUM_TURNED_IN);
		COLLECTION.set_function("_COLLECTABLE_CATEGORY_GET_NUM_COLLECTABLES", LUA_NATIVE_COLLECTION__COLLECTABLE_CATEGORY_GET_NUM_COLLECTABLES);
		COLLECTION.set_function("_COLLECTABLE_GET_COLLECTABLE_ITEM_HASH", LUA_NATIVE_COLLECTION__COLLECTABLE_GET_COLLECTABLE_ITEM_HASH);
		COLLECTION.set_function("_COLLECTABLE_CATEGORY_GET_NUM_FOUND", LUA_NATIVE_COLLECTION__COLLECTABLE_CATEGORY_GET_NUM_FOUND);
		COLLECTION.set_function("_COLLECTABLE_CATEGORY_GET_NUM_TURNED_IN", LUA_NATIVE_COLLECTION__COLLECTABLE_CATEGORY_GET_NUM_TURNED_IN);
		COLLECTION.set_function("_0x33825A7388A6B9F6", LUA_NATIVE_COLLECTION__0x33825A7388A6B9F6);
		COLLECTION.set_function("_0x755901C7598B97BC", LUA_NATIVE_COLLECTION__0x755901C7598B97BC);
		COLLECTION.set_function("_0xB9020EC89C07DF04", LUA_NATIVE_COLLECTION__0xB9020EC89C07DF04);
		COLLECTION.set_function("_0xFC832B06127D8E99", LUA_NATIVE_COLLECTION__0xFC832B06127D8E99);
		COLLECTION.set_function("COLLECTABLE_CATEGORY_SET_HAS_RECEIVED_LIST", LUA_NATIVE_COLLECTION_COLLECTABLE_CATEGORY_SET_HAS_RECEIVED_LIST);
		COLLECTION.set_function("_0x6BAB7ACED1017204", LUA_NATIVE_COLLECTION__0x6BAB7ACED1017204);
		COLLECTION.set_function("_0x61BEFBA3CE7A3BC8", LUA_NATIVE_COLLECTION__0x61BEFBA3CE7A3BC8);
		COLLECTION.set_function("_0xC4AC39719C1BB559", LUA_NATIVE_COLLECTION__0xC4AC39719C1BB559);
		COLLECTION.set_function("_0x93F2E7B5DB85657B", LUA_NATIVE_COLLECTION__0x93F2E7B5DB85657B);
		COLLECTION.set_function("COLLECTABLE_GET_CATEGORY_ITEM_SET_BUY_AWARD", LUA_NATIVE_COLLECTION_COLLECTABLE_GET_CATEGORY_ITEM_SET_BUY_AWARD);
		COLLECTION.set_function("_0x9ADEE485726025D4", LUA_NATIVE_COLLECTION__0x9ADEE485726025D4);
		COLLECTION.set_function("_0xD1806FB3EDED6D11", LUA_NATIVE_COLLECTION__0xD1806FB3EDED6D11);
		COLLECTION.set_function("_0x3FD91F1A148A0468", LUA_NATIVE_COLLECTION__0x3FD91F1A148A0468);
		COLLECTION.set_function("_0xC3CA424E1F12ED0C", LUA_NATIVE_COLLECTION__0xC3CA424E1F12ED0C);
		COLLECTION.set_function("_COLLECTABLE_CATEGORY_GET_TOAST_TEXTURE_NAME", LUA_NATIVE_COLLECTION__COLLECTABLE_CATEGORY_GET_TOAST_TEXTURE_NAME);
		COLLECTION.set_function("_COLLECTABLE_CATEGORY_GET_TOAST_TEXTURE_DICTIONARY", LUA_NATIVE_COLLECTION__COLLECTABLE_CATEGORY_GET_TOAST_TEXTURE_DICTIONARY);
		COLLECTION.set_function("_0xD297F68928A58130", LUA_NATIVE_COLLECTION__0xD297F68928A58130);
		COLLECTION.set_function("_0x775FA1FC87666847", LUA_NATIVE_COLLECTION__0x775FA1FC87666847);
		COLLECTION.set_function("_0xEC3959E9950BF56B", LUA_NATIVE_COLLECTION__0xEC3959E9950BF56B);
	}
}
