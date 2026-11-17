#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_DATAFILE_DATAFILE_WATCH_REQUEST_ID(int nCloudRequestID)
	{
		DATAFILE::DATAFILE_WATCH_REQUEST_ID(nCloudRequestID);
	}

	static bool LUA_NATIVE_DATAFILE_DATAFILE_HAS_LOADED_FILE_DATA(int nCloudRequestID)
	{
		auto retval = (bool)DATAFILE::DATAFILE_HAS_LOADED_FILE_DATA(nCloudRequestID);
		return retval;
	}

	static bool LUA_NATIVE_DATAFILE_DATAFILE_HAS_VALID_FILE_DATA(int nCloudRequestID)
	{
		auto retval = (bool)DATAFILE::DATAFILE_HAS_VALID_FILE_DATA(nCloudRequestID);
		return retval;
	}

	static bool LUA_NATIVE_DATAFILE_DATAFILE_SELECT_ACTIVE_FILE(int nCloudRequestID, int datafileIndex)
	{
		auto retval = (bool)DATAFILE::DATAFILE_SELECT_ACTIVE_FILE(nCloudRequestID, datafileIndex);
		return retval;
	}

	static bool LUA_NATIVE_DATAFILE_DATAFILE_DELETE_REQUESTED_FILE(int nCloudRequestID)
	{
		auto retval = (bool)DATAFILE::DATAFILE_DELETE_REQUESTED_FILE(nCloudRequestID);
		return retval;
	}

	static Any LUA_NATIVE_DATAFILE_UGC2_SET_PLAYER_DATA(Any p0, Any p1, Any p2, Any p3)
	{
		auto retval = DATAFILE::UGC2_SET_PLAYER_DATA(p0, p1, p2, p3);
		return retval;
	}

	static Any LUA_NATIVE_DATAFILE_DATAFILE_UGC_SELECT_DATA(Any ugcRequestId, int index, Any p2)
	{
		auto retval = DATAFILE::DATAFILE_UGC_SELECT_DATA(ugcRequestId, index, p2);
		return retval;
	}

	static void LUA_NATIVE_DATAFILE_DATAFILE_CREATE(int datafileIndex)
	{
		DATAFILE::DATAFILE_CREATE(datafileIndex);
	}

	static void LUA_NATIVE_DATAFILE_DATAFILE_DELETE(int datafileIndex)
	{
		DATAFILE::DATAFILE_DELETE(datafileIndex);
	}

	static uintptr_t LUA_NATIVE_DATAFILE_DATAFILE_GET_FILE_DICT(int datafileIndex)
	{
		auto retval = DATAFILE::DATAFILE_GET_FILE_DICT(datafileIndex);
		return (uintptr_t)retval;
	}

	static bool LUA_NATIVE_DATAFILE_DATADICT_IS_DICT_VALID(uintptr_t fileDict)
	{
		auto retval = (bool)DATAFILE::DATADICT_IS_DICT_VALID((Any*)fileDict);
		return retval;
	}

	static bool LUA_NATIVE_DATAFILE_DATADICT_IS_ARRAY_VALID(uintptr_t fileDict)
	{
		auto retval = (bool)DATAFILE::DATADICT_IS_ARRAY_VALID((Any*)fileDict);
		return retval;
	}

	static void LUA_NATIVE_DATAFILE_DATADICT_SET_INT(uintptr_t dict, sol::stack_object name, int value)
	{
		DATAFILE::DATADICT_SET_INT((Any*)dict, name.is<const char*>() ? name.as<const char*>() : nullptr, value);
	}

	static bool LUA_NATIVE_DATAFILE_DATADICT_GET_BOOL(uintptr_t dict, sol::stack_object name)
	{
		auto retval = (bool)DATAFILE::DATADICT_GET_BOOL((Any*)dict, name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static int LUA_NATIVE_DATAFILE_DATADICT_GET_INT(uintptr_t dict, sol::stack_object name)
	{
		auto retval = DATAFILE::DATADICT_GET_INT((Any*)dict, name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static float LUA_NATIVE_DATAFILE_DATADICT_GET_FLOAT(uintptr_t dict, sol::stack_object name)
	{
		auto retval = DATAFILE::DATADICT_GET_FLOAT((Any*)dict, name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static const char* LUA_NATIVE_DATAFILE_DATADICT_GET_STRING(uintptr_t dict, sol::stack_object name)
	{
		auto retval = DATAFILE::DATADICT_GET_STRING((Any*)dict, name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static Vector3 LUA_NATIVE_DATAFILE_DATADICT_GET_VECTOR(uintptr_t dict, sol::stack_object name)
	{
		auto retval = DATAFILE::DATADICT_GET_VECTOR((Any*)dict, name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static uintptr_t LUA_NATIVE_DATAFILE_DATADICT_GET_DICT(uintptr_t parent, sol::stack_object name)
	{
		auto retval = DATAFILE::DATADICT_GET_DICT((Any*)parent, name.is<const char*>() ? name.as<const char*>() : nullptr);
		return (uintptr_t)retval;
	}

	static uintptr_t LUA_NATIVE_DATAFILE_DATADICT_GET_ARRAY(uintptr_t parent, sol::stack_object name)
	{
		auto retval = DATAFILE::DATADICT_GET_ARRAY((Any*)parent, name.is<const char*>() ? name.as<const char*>() : nullptr);
		return (uintptr_t)retval;
	}

	static int LUA_NATIVE_DATAFILE_DATADICT_GET_TYPE(uintptr_t dict, sol::stack_object name)
	{
		auto retval = DATAFILE::DATADICT_GET_TYPE((Any*)dict, name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_DATAFILE__0xBC0DF006A4952C68(Any p0, Any p1, Any p2)
	{
		DATAFILE::_0xBC0DF006A4952C68(p0, p1, p2);
	}

	static void LUA_NATIVE_DATAFILE__0x9F130129EBC31B34(Any p0, Any p1, Any p2)
	{
		DATAFILE::_0x9F130129EBC31B34(p0, p1, p2);
	}

	static void LUA_NATIVE_DATAFILE__0x277251C161B4C3F4(Any p0, Any p1, Any p2)
	{
		DATAFILE::_0x277251C161B4C3F4(p0, p1, p2);
	}

	static void LUA_NATIVE_DATAFILE__0x1C65CC931C0F946F(Any p0, Any p1, Any p2)
	{
		DATAFILE::_0x1C65CC931C0F946F(p0, p1, p2);
	}

	static void LUA_NATIVE_DATAFILE__0x7681B677400C7071(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		DATAFILE::_0x7681B677400C7071(p0, p1, p2, p3, p4);
	}

	static bool LUA_NATIVE_DATAFILE_DATAARRAY_GET_BOOL(uintptr_t arr, int index)
	{
		auto retval = (bool)DATAFILE::DATAARRAY_GET_BOOL((Any*)arr, index);
		return retval;
	}

	static int LUA_NATIVE_DATAFILE_DATAARRAY_GET_INT(uintptr_t arr, int index)
	{
		auto retval = DATAFILE::DATAARRAY_GET_INT((Any*)arr, index);
		return retval;
	}

	static float LUA_NATIVE_DATAFILE_DATAARRAY_GET_FLOAT(uintptr_t arr, int index)
	{
		auto retval = DATAFILE::DATAARRAY_GET_FLOAT((Any*)arr, index);
		return retval;
	}

	static const char* LUA_NATIVE_DATAFILE_DATAARRAY_GET_STRING(uintptr_t arr, int index)
	{
		auto retval = DATAFILE::DATAARRAY_GET_STRING((Any*)arr, index);
		return retval;
	}

	static Vector3 LUA_NATIVE_DATAFILE_DATAARRAY_GET_VECTOR(uintptr_t arr, int index)
	{
		auto retval = DATAFILE::DATAARRAY_GET_VECTOR((Any*)arr, index);
		return retval;
	}

	static uintptr_t LUA_NATIVE_DATAFILE_DATAARRAY_GET_DICT(uintptr_t parent, int index)
	{
		auto retval = DATAFILE::DATAARRAY_GET_DICT((Any*)parent, index);
		return (uintptr_t)retval;
	}

	static int LUA_NATIVE_DATAFILE_DATAARRAY_GET_COUNT(uintptr_t arr)
	{
		auto retval = DATAFILE::DATAARRAY_GET_COUNT((Any*)arr);
		return retval;
	}

	static int LUA_NATIVE_DATAFILE_DATAARRAY_GET_TYPE(uintptr_t arr, int index)
	{
		auto retval = DATAFILE::DATAARRAY_GET_TYPE((Any*)arr, index);
		return retval;
	}

	static Any LUA_NATIVE_DATAFILE__0x4F9E3ED7617123AC(Any p0)
	{
		auto retval = DATAFILE::_0x4F9E3ED7617123AC(p0);
		return retval;
	}

	static Any LUA_NATIVE_DATAFILE__0xCA56DD6AB7A39F64(Any p0)
	{
		auto retval = DATAFILE::_0xCA56DD6AB7A39F64(p0);
		return retval;
	}

	static int LUA_NATIVE_DATAFILE__PARSEDDATA_LOAD_FILE_HASH(Hash p0)
	{
		auto retval = DATAFILE::_PARSEDDATA_LOAD_FILE_HASH(p0);
		return retval;
	}

	static void LUA_NATIVE_DATAFILE__PARSEDDATA_UNLOAD_FILE(int fileHandle)
	{
		DATAFILE::_PARSEDDATA_UNLOAD_FILE(fileHandle);
	}

	static bool LUA_NATIVE_DATAFILE_PARSEDDATA_IS_FILE_VALID(int fileHandle)
	{
		auto retval = (bool)DATAFILE::PARSEDDATA_IS_FILE_VALID(fileHandle);
		return retval;
	}

	static bool LUA_NATIVE_DATAFILE_PARSEDDATA_IS_FILE_LOADED(int fileHandle)
	{
		auto retval = (bool)DATAFILE::PARSEDDATA_IS_FILE_LOADED(fileHandle);
		return retval;
	}

	static void LUA_NATIVE_DATAFILE__0x3168BA5D6DECE323()
	{
		DATAFILE::_0x3168BA5D6DECE323();
	}

	static Any LUA_NATIVE_DATAFILE__PARSEDDATA_REGISTER_QUERY(Any p0, Any p1, Any p2)
	{
		auto retval = DATAFILE::_PARSEDDATA_REGISTER_QUERY(p0, p1, p2);
		return retval;
	}

	static std::tuple<bool, int> LUA_NATIVE_DATAFILE_PARSEDDATA_RQ_FILLOUT_NODE(int p0, uintptr_t p1)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)DATAFILE::PARSEDDATA_RQ_FILLOUT_NODE(&p0, (Any*)p1);
		std::get<1>(return_values) = p0;

		return return_values;
	}

	static Any LUA_NATIVE_DATAFILE__PARSEDDATA_RQ_GET_NUM_NODES(Any p0)
	{
		auto retval = DATAFILE::_PARSEDDATA_RQ_GET_NUM_NODES(p0);
		return retval;
	}

	static int LUA_NATIVE_DATAFILE__0xE13634BB6BAF0734(int p0, int p1)
	{
		auto retval = DATAFILE::_0xE13634BB6BAF0734(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_DATAFILE__PARSEDDATA_GET_NUM_CHILDREN(Any p0, Any p1)
	{
		auto retval = DATAFILE::_PARSEDDATA_GET_NUM_CHILDREN(p0, p1);
		return retval;
	}

	static std::tuple<bool, Hash> LUA_NATIVE_DATAFILE_PARSEDDATA_RQ_FILLOUT_HASH(Hash p0, uintptr_t p1)
	{
		std::tuple<bool, Hash> return_values;
		std::get<0>(return_values) = (bool)DATAFILE::PARSEDDATA_RQ_FILLOUT_HASH(&p0, (Any*)p1);
		std::get<1>(return_values) = p0;

		return return_values;
	}

	static std::tuple<bool, char> LUA_NATIVE_DATAFILE__PARSEDDATA_RQ_FILLOUT_STRING_63(char p0, uintptr_t p1)
	{
		std::tuple<bool, char> return_values;
		std::get<0>(return_values) = (bool)DATAFILE::_PARSEDDATA_RQ_FILLOUT_STRING_63(&p0, (Any*)p1);
		std::get<1>(return_values) = p0;

		return return_values;
	}

	static std::tuple<bool, char> LUA_NATIVE_DATAFILE_PARSEDDATA_RQ_FILLOUT_STRING_127(char p0, uintptr_t p1)
	{
		std::tuple<bool, char> return_values;
		std::get<0>(return_values) = (bool)DATAFILE::PARSEDDATA_RQ_FILLOUT_STRING_127(&p0, (Any*)p1);
		std::get<1>(return_values) = p0;

		return return_values;
	}

	static std::tuple<bool, Vector3> LUA_NATIVE_DATAFILE__PARSEDDATA_RQ_FILLOUT_VECTOR(Vector3 p0, uintptr_t p1)
	{
		std::tuple<bool, Vector3> return_values;
		std::get<0>(return_values) = (bool)DATAFILE::_PARSEDDATA_RQ_FILLOUT_VECTOR(&p0, (Any*)p1);
		std::get<1>(return_values) = p0;

		return return_values;
	}

	static std::tuple<bool, float> LUA_NATIVE_DATAFILE__PARSEDDATA_RQ_FILLOUT_FLOAT(float p0, uintptr_t p1)
	{
		std::tuple<bool, float> return_values;
		std::get<0>(return_values) = (bool)DATAFILE::_PARSEDDATA_RQ_FILLOUT_FLOAT(&p0, (Any*)p1);
		std::get<1>(return_values) = p0;

		return return_values;
	}

	static std::tuple<bool, int> LUA_NATIVE_DATAFILE__PARSEDDATA_RQ_FILLOUT_INT(int p0, uintptr_t p1)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)DATAFILE::_PARSEDDATA_RQ_FILLOUT_INT(&p0, (Any*)p1);
		std::get<1>(return_values) = p0;

		return return_values;
	}

	static std::tuple<bool, bool> LUA_NATIVE_DATAFILE__PARSEDDATA_RQ_FILLOUT_BOOL(bool p0, uintptr_t p1)
	{
		std::tuple<bool, bool> return_values;
		std::get<0>(return_values) = (bool)DATAFILE::_PARSEDDATA_RQ_FILLOUT_BOOL((BOOL*)&p0, (Any*)p1);
		std::get<1>(return_values) = p0;

		return return_values;
	}

	static void LUA_NATIVE_DATAFILE__PARSEDDATA_GET_FILE(uintptr_t p0)
	{
		DATAFILE::_PARSEDDATA_GET_FILE((Any*)p0);
	}

	static bool LUA_NATIVE_DATAFILE__PARSEDDATA_GET_ENTRIES(uintptr_t p0)
	{
		auto retval = (bool)DATAFILE::_PARSEDDATA_GET_ENTRIES((Any*)p0);
		return retval;
	}

	static bool LUA_NATIVE_DATAFILE__PARSEDDATA_GET_FLOAT(uintptr_t p0, uintptr_t p1, Hash p2)
	{
		auto retval = (bool)DATAFILE::_PARSEDDATA_GET_FLOAT((Any*)p0, (Any*)p1, p2);
		return retval;
	}

	static bool LUA_NATIVE_DATAFILE__PARSEDDATA_GET_INT(uintptr_t p0, uintptr_t p1, Hash p2)
	{
		auto retval = (bool)DATAFILE::_PARSEDDATA_GET_INT((Any*)p0, (Any*)p1, p2);
		return retval;
	}

	static bool LUA_NATIVE_DATAFILE__PARSEDDATA_GET_SECTION(uintptr_t p0, uintptr_t p1, Hash section)
	{
		auto retval = (bool)DATAFILE::_PARSEDDATA_GET_SECTION((Any*)p0, (Any*)p1, section);
		return retval;
	}

	static std::tuple<bool, bool> LUA_NATIVE_DATAFILE__PARSEDDATA_GET_BOOL(bool p0, uintptr_t p1, Hash p2)
	{
		std::tuple<bool, bool> return_values;
		std::get<0>(return_values) = (bool)DATAFILE::_PARSEDDATA_GET_BOOL((BOOL*)&p0, (Any*)p1, p2);
		std::get<1>(return_values) = p0;

		return return_values;
	}

	void RegisterNatives_DATAFILE(sol::state& L)
	{
		auto DATAFILE = L["DATAFILE"].get_or_create<sol::table>();
		DATAFILE.set_function("DATAFILE_WATCH_REQUEST_ID", LUA_NATIVE_DATAFILE_DATAFILE_WATCH_REQUEST_ID);
		DATAFILE.set_function("DATAFILE_HAS_LOADED_FILE_DATA", LUA_NATIVE_DATAFILE_DATAFILE_HAS_LOADED_FILE_DATA);
		DATAFILE.set_function("DATAFILE_HAS_VALID_FILE_DATA", LUA_NATIVE_DATAFILE_DATAFILE_HAS_VALID_FILE_DATA);
		DATAFILE.set_function("DATAFILE_SELECT_ACTIVE_FILE", LUA_NATIVE_DATAFILE_DATAFILE_SELECT_ACTIVE_FILE);
		DATAFILE.set_function("DATAFILE_DELETE_REQUESTED_FILE", LUA_NATIVE_DATAFILE_DATAFILE_DELETE_REQUESTED_FILE);
		DATAFILE.set_function("UGC2_SET_PLAYER_DATA", LUA_NATIVE_DATAFILE_UGC2_SET_PLAYER_DATA);
		DATAFILE.set_function("DATAFILE_UGC_SELECT_DATA", LUA_NATIVE_DATAFILE_DATAFILE_UGC_SELECT_DATA);
		DATAFILE.set_function("DATAFILE_CREATE", LUA_NATIVE_DATAFILE_DATAFILE_CREATE);
		DATAFILE.set_function("DATAFILE_DELETE", LUA_NATIVE_DATAFILE_DATAFILE_DELETE);
		DATAFILE.set_function("DATAFILE_GET_FILE_DICT", LUA_NATIVE_DATAFILE_DATAFILE_GET_FILE_DICT);
		DATAFILE.set_function("DATADICT_IS_DICT_VALID", LUA_NATIVE_DATAFILE_DATADICT_IS_DICT_VALID);
		DATAFILE.set_function("DATADICT_IS_ARRAY_VALID", LUA_NATIVE_DATAFILE_DATADICT_IS_ARRAY_VALID);
		DATAFILE.set_function("DATADICT_SET_INT", LUA_NATIVE_DATAFILE_DATADICT_SET_INT);
		DATAFILE.set_function("DATADICT_GET_BOOL", LUA_NATIVE_DATAFILE_DATADICT_GET_BOOL);
		DATAFILE.set_function("DATADICT_GET_INT", LUA_NATIVE_DATAFILE_DATADICT_GET_INT);
		DATAFILE.set_function("DATADICT_GET_FLOAT", LUA_NATIVE_DATAFILE_DATADICT_GET_FLOAT);
		DATAFILE.set_function("DATADICT_GET_STRING", LUA_NATIVE_DATAFILE_DATADICT_GET_STRING);
		DATAFILE.set_function("DATADICT_GET_VECTOR", LUA_NATIVE_DATAFILE_DATADICT_GET_VECTOR);
		DATAFILE.set_function("DATADICT_GET_DICT", LUA_NATIVE_DATAFILE_DATADICT_GET_DICT);
		DATAFILE.set_function("DATADICT_GET_ARRAY", LUA_NATIVE_DATAFILE_DATADICT_GET_ARRAY);
		DATAFILE.set_function("DATADICT_GET_TYPE", LUA_NATIVE_DATAFILE_DATADICT_GET_TYPE);
		DATAFILE.set_function("_0xBC0DF006A4952C68", LUA_NATIVE_DATAFILE__0xBC0DF006A4952C68);
		DATAFILE.set_function("_0x9F130129EBC31B34", LUA_NATIVE_DATAFILE__0x9F130129EBC31B34);
		DATAFILE.set_function("_0x277251C161B4C3F4", LUA_NATIVE_DATAFILE__0x277251C161B4C3F4);
		DATAFILE.set_function("_0x1C65CC931C0F946F", LUA_NATIVE_DATAFILE__0x1C65CC931C0F946F);
		DATAFILE.set_function("_0x7681B677400C7071", LUA_NATIVE_DATAFILE__0x7681B677400C7071);
		DATAFILE.set_function("DATAARRAY_GET_BOOL", LUA_NATIVE_DATAFILE_DATAARRAY_GET_BOOL);
		DATAFILE.set_function("DATAARRAY_GET_INT", LUA_NATIVE_DATAFILE_DATAARRAY_GET_INT);
		DATAFILE.set_function("DATAARRAY_GET_FLOAT", LUA_NATIVE_DATAFILE_DATAARRAY_GET_FLOAT);
		DATAFILE.set_function("DATAARRAY_GET_STRING", LUA_NATIVE_DATAFILE_DATAARRAY_GET_STRING);
		DATAFILE.set_function("DATAARRAY_GET_VECTOR", LUA_NATIVE_DATAFILE_DATAARRAY_GET_VECTOR);
		DATAFILE.set_function("DATAARRAY_GET_DICT", LUA_NATIVE_DATAFILE_DATAARRAY_GET_DICT);
		DATAFILE.set_function("DATAARRAY_GET_COUNT", LUA_NATIVE_DATAFILE_DATAARRAY_GET_COUNT);
		DATAFILE.set_function("DATAARRAY_GET_TYPE", LUA_NATIVE_DATAFILE_DATAARRAY_GET_TYPE);
		DATAFILE.set_function("_0x4F9E3ED7617123AC", LUA_NATIVE_DATAFILE__0x4F9E3ED7617123AC);
		DATAFILE.set_function("_0xCA56DD6AB7A39F64", LUA_NATIVE_DATAFILE__0xCA56DD6AB7A39F64);
		DATAFILE.set_function("_PARSEDDATA_LOAD_FILE_HASH", LUA_NATIVE_DATAFILE__PARSEDDATA_LOAD_FILE_HASH);
		DATAFILE.set_function("_PARSEDDATA_UNLOAD_FILE", LUA_NATIVE_DATAFILE__PARSEDDATA_UNLOAD_FILE);
		DATAFILE.set_function("PARSEDDATA_IS_FILE_VALID", LUA_NATIVE_DATAFILE_PARSEDDATA_IS_FILE_VALID);
		DATAFILE.set_function("PARSEDDATA_IS_FILE_LOADED", LUA_NATIVE_DATAFILE_PARSEDDATA_IS_FILE_LOADED);
		DATAFILE.set_function("_0x3168BA5D6DECE323", LUA_NATIVE_DATAFILE__0x3168BA5D6DECE323);
		DATAFILE.set_function("_PARSEDDATA_REGISTER_QUERY", LUA_NATIVE_DATAFILE__PARSEDDATA_REGISTER_QUERY);
		DATAFILE.set_function("PARSEDDATA_RQ_FILLOUT_NODE", LUA_NATIVE_DATAFILE_PARSEDDATA_RQ_FILLOUT_NODE);
		DATAFILE.set_function("_PARSEDDATA_RQ_GET_NUM_NODES", LUA_NATIVE_DATAFILE__PARSEDDATA_RQ_GET_NUM_NODES);
		DATAFILE.set_function("_0xE13634BB6BAF0734", LUA_NATIVE_DATAFILE__0xE13634BB6BAF0734);
		DATAFILE.set_function("_PARSEDDATA_GET_NUM_CHILDREN", LUA_NATIVE_DATAFILE__PARSEDDATA_GET_NUM_CHILDREN);
		DATAFILE.set_function("PARSEDDATA_RQ_FILLOUT_HASH", LUA_NATIVE_DATAFILE_PARSEDDATA_RQ_FILLOUT_HASH);
		DATAFILE.set_function("_PARSEDDATA_RQ_FILLOUT_STRING_63", LUA_NATIVE_DATAFILE__PARSEDDATA_RQ_FILLOUT_STRING_63);
		DATAFILE.set_function("PARSEDDATA_RQ_FILLOUT_STRING_127", LUA_NATIVE_DATAFILE_PARSEDDATA_RQ_FILLOUT_STRING_127);
		DATAFILE.set_function("_PARSEDDATA_RQ_FILLOUT_VECTOR", LUA_NATIVE_DATAFILE__PARSEDDATA_RQ_FILLOUT_VECTOR);
		DATAFILE.set_function("_PARSEDDATA_RQ_FILLOUT_FLOAT", LUA_NATIVE_DATAFILE__PARSEDDATA_RQ_FILLOUT_FLOAT);
		DATAFILE.set_function("_PARSEDDATA_RQ_FILLOUT_INT", LUA_NATIVE_DATAFILE__PARSEDDATA_RQ_FILLOUT_INT);
		DATAFILE.set_function("_PARSEDDATA_RQ_FILLOUT_BOOL", LUA_NATIVE_DATAFILE__PARSEDDATA_RQ_FILLOUT_BOOL);
		DATAFILE.set_function("_PARSEDDATA_GET_FILE", LUA_NATIVE_DATAFILE__PARSEDDATA_GET_FILE);
		DATAFILE.set_function("_PARSEDDATA_GET_ENTRIES", LUA_NATIVE_DATAFILE__PARSEDDATA_GET_ENTRIES);
		DATAFILE.set_function("_PARSEDDATA_GET_FLOAT", LUA_NATIVE_DATAFILE__PARSEDDATA_GET_FLOAT);
		DATAFILE.set_function("_PARSEDDATA_GET_INT", LUA_NATIVE_DATAFILE__PARSEDDATA_GET_INT);
		DATAFILE.set_function("_PARSEDDATA_GET_SECTION", LUA_NATIVE_DATAFILE__PARSEDDATA_GET_SECTION);
		DATAFILE.set_function("_PARSEDDATA_GET_BOOL", LUA_NATIVE_DATAFILE__PARSEDDATA_GET_BOOL);
	}
}
