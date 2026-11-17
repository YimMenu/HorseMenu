#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static bool LUA_NATIVE_TXD_DOES_STREAMED_TXD_EXIST(Hash txdHash)
	{
		auto retval = (bool)TXD::DOES_STREAMED_TXD_EXIST(txdHash);
		return retval;
	}

	static void LUA_NATIVE_TXD_REQUEST_STREAMED_TXD(Hash txdHash, bool p1)
	{
		TXD::REQUEST_STREAMED_TXD(txdHash, p1);
	}

	static bool LUA_NATIVE_TXD_HAS_STREAMED_TXD_LOADED(Hash txdHash)
	{
		auto retval = (bool)TXD::HAS_STREAMED_TXD_LOADED(txdHash);
		return retval;
	}

	static void LUA_NATIVE_TXD_SET_STREAMED_TXD_AS_NO_LONGER_NEEDED(Hash txdHash)
	{
		TXD::SET_STREAMED_TXD_AS_NO_LONGER_NEEDED(txdHash);
	}

	static bool LUA_NATIVE_TXD_DOES_STREAMED_TEXTURE_DICT_EXIST(sol::stack_object textureDict)
	{
		auto retval = (bool)TXD::DOES_STREAMED_TEXTURE_DICT_EXIST(textureDict.is<const char*>() ? textureDict.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_TXD_REQUEST_STREAMED_TEXTURE_DICT(sol::stack_object TxdName, bool bPriority)
	{
		TXD::REQUEST_STREAMED_TEXTURE_DICT(TxdName.is<const char*>() ? TxdName.as<const char*>() : nullptr, bPriority);
	}

	static bool LUA_NATIVE_TXD_HAS_STREAMED_TEXTURE_DICT_LOADED(sol::stack_object TxdName)
	{
		auto retval = (bool)TXD::HAS_STREAMED_TEXTURE_DICT_LOADED(TxdName.is<const char*>() ? TxdName.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_TXD_SET_STREAMED_TEXTURE_DICT_AS_NO_LONGER_NEEDED(sol::stack_object TxdName)
	{
		TXD::SET_STREAMED_TEXTURE_DICT_AS_NO_LONGER_NEEDED(TxdName.is<const char*>() ? TxdName.as<const char*>() : nullptr);
	}

	void RegisterNatives_TXD(sol::state& L)
	{
		auto TXD = L["TXD"].get_or_create<sol::table>();
		TXD.set_function("DOES_STREAMED_TXD_EXIST", LUA_NATIVE_TXD_DOES_STREAMED_TXD_EXIST);
		TXD.set_function("REQUEST_STREAMED_TXD", LUA_NATIVE_TXD_REQUEST_STREAMED_TXD);
		TXD.set_function("HAS_STREAMED_TXD_LOADED", LUA_NATIVE_TXD_HAS_STREAMED_TXD_LOADED);
		TXD.set_function("SET_STREAMED_TXD_AS_NO_LONGER_NEEDED", LUA_NATIVE_TXD_SET_STREAMED_TXD_AS_NO_LONGER_NEEDED);
		TXD.set_function("DOES_STREAMED_TEXTURE_DICT_EXIST", LUA_NATIVE_TXD_DOES_STREAMED_TEXTURE_DICT_EXIST);
		TXD.set_function("REQUEST_STREAMED_TEXTURE_DICT", LUA_NATIVE_TXD_REQUEST_STREAMED_TEXTURE_DICT);
		TXD.set_function("HAS_STREAMED_TEXTURE_DICT_LOADED", LUA_NATIVE_TXD_HAS_STREAMED_TEXTURE_DICT_LOADED);
		TXD.set_function("SET_STREAMED_TEXTURE_DICT_AS_NO_LONGER_NEEDED", LUA_NATIVE_TXD_SET_STREAMED_TEXTURE_DICT_AS_NO_LONGER_NEEDED);
	}
}
