#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_SCRIPTS__SET_PLAYER_BIT_AT_INDEX(uintptr_t value, int bitIndex)
	{
		SCRIPTS::_SET_PLAYER_BIT_AT_INDEX((Any*)value, bitIndex);
	}

	static void LUA_NATIVE_SCRIPTS__CLEAR_PLAYER_BIT_AT_INDEX(uintptr_t value, int bitIndex)
	{
		SCRIPTS::_CLEAR_PLAYER_BIT_AT_INDEX((Any*)value, bitIndex);
	}

	static void LUA_NATIVE_SCRIPTS__0xE4ABE20DCE7C7CFE(Any p0, Any p1, Any p2)
	{
		SCRIPTS::_0xE4ABE20DCE7C7CFE(p0, p1, p2);
	}

	static void LUA_NATIVE_SCRIPTS__0xFFDDF802279BE128(Any p0, Any p1, Any p2)
	{
		SCRIPTS::_0xFFDDF802279BE128(p0, p1, p2);
	}

	static void LUA_NATIVE_SCRIPTS__0x64F765D9A1F8F02C(uintptr_t p0, uintptr_t p1, uintptr_t p2)
	{
		SCRIPTS::_0x64F765D9A1F8F02C((Any*)p0, (Any*)p1, (Any*)p2);
	}

	static void LUA_NATIVE_SCRIPTS__SET_ALL_PLAYER_BITS(uintptr_t value)
	{
		SCRIPTS::_SET_ALL_PLAYER_BITS((Any*)value);
	}

	static void LUA_NATIVE_SCRIPTS__CLEAR_ALL_PLAYER_BITS(uintptr_t value)
	{
		SCRIPTS::_CLEAR_ALL_PLAYER_BITS((Any*)value);
	}

	static bool LUA_NATIVE_SCRIPTS__IS_PLAYER_BIT_SET_AT_INDEX(uintptr_t value, int bitIndex)
	{
		auto retval = (bool)SCRIPTS::_IS_PLAYER_BIT_SET_AT_INDEX((Any*)value, bitIndex);
		return retval;
	}

	static std::tuple<bool, int> LUA_NATIVE_SCRIPTS__IS_ANY_PLAYER_BIT_SET(int playerBits)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)SCRIPTS::_IS_ANY_PLAYER_BIT_SET(&playerBits);
		std::get<1>(return_values) = playerBits;

		return return_values;
	}

	static int LUA_NATIVE_SCRIPTS_GET_BLOCK_OF_PLAYER_BITS(uintptr_t value, int p1)
	{
		auto retval = SCRIPTS::GET_BLOCK_OF_PLAYER_BITS((Any*)value, p1);
		return retval;
	}

	static void LUA_NATIVE_SCRIPTS_SET_BLOCK_OF_PLAYER_BITS(uintptr_t value, int p1, int p2)
	{
		SCRIPTS::SET_BLOCK_OF_PLAYER_BITS((Any*)value, p1, p2);
	}

	static int LUA_NATIVE_SCRIPTS_COUNT_PLAYER_BITS(uintptr_t value)
	{
		auto retval = SCRIPTS::COUNT_PLAYER_BITS((Any*)value);
		return retval;
	}

	static void LUA_NATIVE_SCRIPTS__0x1BDB5A07307F6929(Any p0, Any p1)
	{
		SCRIPTS::_0x1BDB5A07307F6929(p0, p1);
	}

	static void LUA_NATIVE_SCRIPTS__0x1C5EB3C27F7508CB(Any p0, Any p1)
	{
		SCRIPTS::_0x1C5EB3C27F7508CB(p0, p1);
	}

	static void LUA_NATIVE_SCRIPTS__0x42A429CDFED6D99D(Any p0, Any p1, Any p2)
	{
		SCRIPTS::_0x42A429CDFED6D99D(p0, p1, p2);
	}

	static void LUA_NATIVE_SCRIPTS__0x5827BE85A87B073D(Any p0)
	{
		SCRIPTS::_0x5827BE85A87B073D(p0);
	}

	static Any LUA_NATIVE_SCRIPTS__0x0A79C81C418F5D38(Any p0, Any p1)
	{
		auto retval = SCRIPTS::_0x0A79C81C418F5D38(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_SCRIPTS__0xA88E1D7FA1E20080(Any p0)
	{
		auto retval = SCRIPTS::_0xA88E1D7FA1E20080(p0);
		return retval;
	}

	static int LUA_NATIVE_SCRIPTS_COUNT_PARTICIPANT_BITS(uintptr_t value)
	{
		auto retval = SCRIPTS::COUNT_PARTICIPANT_BITS((Any*)value);
		return retval;
	}

	static void LUA_NATIVE_SCRIPTS_REQUEST_SCRIPT(sol::stack_object scriptname)
	{
		SCRIPTS::REQUEST_SCRIPT(scriptname.is<const char*>() ? scriptname.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_SCRIPTS_SET_SCRIPT_AS_NO_LONGER_NEEDED(sol::stack_object scriptname)
	{
		SCRIPTS::SET_SCRIPT_AS_NO_LONGER_NEEDED(scriptname.is<const char*>() ? scriptname.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_SCRIPTS_HAS_SCRIPT_LOADED(sol::stack_object scriptname)
	{
		auto retval = (bool)SCRIPTS::HAS_SCRIPT_LOADED(scriptname.is<const char*>() ? scriptname.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_SCRIPTS_DOES_SCRIPT_EXIST(sol::stack_object scriptname)
	{
		auto retval = (bool)SCRIPTS::DOES_SCRIPT_EXIST(scriptname.is<const char*>() ? scriptname.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_SCRIPTS_REQUEST_SCRIPT_WITH_NAME_HASH(Hash hashOfScriptName)
	{
		SCRIPTS::REQUEST_SCRIPT_WITH_NAME_HASH(hashOfScriptName);
	}

	static void LUA_NATIVE_SCRIPTS_SET_SCRIPT_WITH_NAME_HASH_AS_NO_LONGER_NEEDED(Hash hashOfScriptName)
	{
		SCRIPTS::SET_SCRIPT_WITH_NAME_HASH_AS_NO_LONGER_NEEDED(hashOfScriptName);
	}

	static bool LUA_NATIVE_SCRIPTS_HAS_SCRIPT_WITH_NAME_HASH_LOADED(Hash hashOfScriptName)
	{
		auto retval = (bool)SCRIPTS::HAS_SCRIPT_WITH_NAME_HASH_LOADED(hashOfScriptName);
		return retval;
	}

	static bool LUA_NATIVE_SCRIPTS_DOES_SCRIPT_WITH_NAME_HASH_EXIST(Hash hashOfScriptName)
	{
		auto retval = (bool)SCRIPTS::DOES_SCRIPT_WITH_NAME_HASH_EXIST(hashOfScriptName);
		return retval;
	}

	static void LUA_NATIVE_SCRIPTS_TERMINATE_THREAD(int thread)
	{
		SCRIPTS::TERMINATE_THREAD(thread);
	}

	static bool LUA_NATIVE_SCRIPTS_IS_THREAD_ACTIVE(int thread, bool ignoreKilledState)
	{
		auto retval = (bool)SCRIPTS::IS_THREAD_ACTIVE(thread, ignoreKilledState);
		return retval;
	}

	static bool LUA_NATIVE_SCRIPTS_DOES_THREAD_EXIST(int threadId)
	{
		auto retval = (bool)SCRIPTS::DOES_THREAD_EXIST(threadId);
		return retval;
	}

	static std::tuple<bool, bool> LUA_NATIVE_SCRIPTS_GET_THREAD_EXISTENCE_DETAILS(int threadId, bool threadExists, bool hasScriptHandler)
	{
		std::tuple<bool, bool> return_values;
		SCRIPTS::GET_THREAD_EXISTENCE_DETAILS(threadId, (BOOL*)&threadExists, (BOOL*)&hasScriptHandler);
		std::get<0>(return_values) = threadExists;
		std::get<1>(return_values) = hasScriptHandler;

		return return_values;
	}

	static Hash LUA_NATIVE_SCRIPTS__GET_HASH_OF_THREAD(int threadId)
	{
		auto retval = SCRIPTS::_GET_HASH_OF_THREAD(threadId);
		return retval;
	}

	static void LUA_NATIVE_SCRIPTS_SCRIPT_THREAD_ITERATOR_RESET()
	{
		SCRIPTS::SCRIPT_THREAD_ITERATOR_RESET();
	}

	static int LUA_NATIVE_SCRIPTS_SCRIPT_THREAD_ITERATOR_GET_NEXT_THREAD_ID()
	{
		auto retval = SCRIPTS::SCRIPT_THREAD_ITERATOR_GET_NEXT_THREAD_ID();
		return retval;
	}

	static bool LUA_NATIVE_SCRIPTS__IS_BACKGROUND_SCRIPT(int threadId)
	{
		auto retval = (bool)SCRIPTS::_IS_BACKGROUND_SCRIPT(threadId);
		return retval;
	}

	static int LUA_NATIVE_SCRIPTS_GET_ID_OF_THIS_THREAD()
	{
		auto retval = SCRIPTS::GET_ID_OF_THIS_THREAD();
		return retval;
	}

	static void LUA_NATIVE_SCRIPTS_TERMINATE_THIS_THREAD()
	{
		SCRIPTS::TERMINATE_THIS_THREAD();
	}

	static int LUA_NATIVE_SCRIPTS_GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH(Hash HashOfScriptName)
	{
		auto retval = SCRIPTS::GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH(HashOfScriptName);
		return retval;
	}

	static void LUA_NATIVE_SCRIPTS__REQUEST_THREAD_EXIT(int threadId)
	{
		SCRIPTS::_REQUEST_THREAD_EXIT(threadId);
	}

	static void LUA_NATIVE_SCRIPTS__REQUEST_THREAD_EXIT_FOR_ALL_THREADS_WITH_THIS_NAME(Hash nameHash)
	{
		SCRIPTS::_REQUEST_THREAD_EXIT_FOR_ALL_THREADS_WITH_THIS_NAME(nameHash);
	}

	static bool LUA_NATIVE_SCRIPTS_IS_THREAD_EXIT_REQUESTED()
	{
		auto retval = (bool)SCRIPTS::IS_THREAD_EXIT_REQUESTED();
		return retval;
	}

	static bool LUA_NATIVE_SCRIPTS__IS_THREAD_EXIT_REQUESTED_FOR_THREAD_WITH_THIS_ID(int threadId)
	{
		auto retval = (bool)SCRIPTS::_IS_THREAD_EXIT_REQUESTED_FOR_THREAD_WITH_THIS_ID(threadId);
		return retval;
	}

	static int LUA_NATIVE_SCRIPTS__GET_THREAD_EXIT_REASON()
	{
		auto retval = SCRIPTS::_GET_THREAD_EXIT_REASON();
		return retval;
	}

	static Hash LUA_NATIVE_SCRIPTS_GET_HASH_OF_THIS_SCRIPT_NAME()
	{
		auto retval = SCRIPTS::GET_HASH_OF_THIS_SCRIPT_NAME();
		return retval;
	}

	static int LUA_NATIVE_SCRIPTS_GET_NUMBER_OF_EVENTS(int eventQueue)
	{
		auto retval = SCRIPTS::GET_NUMBER_OF_EVENTS(eventQueue);
		return retval;
	}

	static bool LUA_NATIVE_SCRIPTS_GET_EVENT_EXISTS(int eventQueue, Hash eventType)
	{
		auto retval = (bool)SCRIPTS::GET_EVENT_EXISTS(eventQueue, eventType);
		return retval;
	}

	static Hash LUA_NATIVE_SCRIPTS_GET_EVENT_AT_INDEX(int eventQueue, int eventIndex)
	{
		auto retval = SCRIPTS::GET_EVENT_AT_INDEX(eventQueue, eventIndex);
		return retval;
	}

	static bool LUA_NATIVE_SCRIPTS_GET_EVENT_DATA(int eventQueue, int eventIndex, uintptr_t data, int dataSize)
	{
		auto retval = (bool)SCRIPTS::GET_EVENT_DATA(eventQueue, eventIndex, (Any*)data, dataSize);
		return retval;
	}

	static void LUA_NATIVE_SCRIPTS_SET_EVENT_FLAG_FOR_DELETION(int eventGroup, int eventIndex, bool p2)
	{
		SCRIPTS::SET_EVENT_FLAG_FOR_DELETION(eventGroup, eventIndex, p2);
	}

	static int LUA_NATIVE_SCRIPTS_TRIGGER_SCRIPT_EVENT(int eventQueue, uintptr_t data, int sizeOfData, int scriptMetadataIndex, int playerBits)
	{
		SCRIPTS::TRIGGER_SCRIPT_EVENT(eventQueue, (Any*)data, sizeOfData, scriptMetadataIndex, &playerBits);
		return playerBits;
	}

	static void LUA_NATIVE_SCRIPTS__TRIGGER_SCRIPT_EVENT_2(uintptr_t eventData, int eventDataSize, int scriptMetadataIndex, int threadId)
	{
		SCRIPTS::_TRIGGER_SCRIPT_EVENT_2((Any*)eventData, eventDataSize, scriptMetadataIndex, threadId);
	}

	static Any LUA_NATIVE_SCRIPTS__0xE7282390542F570D(Any p0)
	{
		auto retval = SCRIPTS::_0xE7282390542F570D(p0);
		return retval;
	}

	static void LUA_NATIVE_SCRIPTS__0x11B0A0B282FA9B10(bool p0)
	{
		SCRIPTS::_0x11B0A0B282FA9B10(p0);
	}

	static void LUA_NATIVE_SCRIPTS__0x6F700A4BF7C3331B(bool p0)
	{
		SCRIPTS::_0x6F700A4BF7C3331B(p0);
	}

	static void LUA_NATIVE_SCRIPTS__0xF9E951A1E5517C06()
	{
		SCRIPTS::_0xF9E951A1E5517C06();
	}

	static void LUA_NATIVE_SCRIPTS__0x76CBCD9EADC00955()
	{
		SCRIPTS::_0x76CBCD9EADC00955();
	}

	static void LUA_NATIVE_SCRIPTS_SHUTDOWN_LOADING_SCREEN()
	{
		SCRIPTS::SHUTDOWN_LOADING_SCREEN();
	}

	static void LUA_NATIVE_SCRIPTS_SET_NO_LOADING_SCREEN(bool state)
	{
		SCRIPTS::SET_NO_LOADING_SCREEN(state);
	}

	static bool LUA_NATIVE_SCRIPTS_GET_NO_LOADING_SCREEN()
	{
		auto retval = (bool)SCRIPTS::GET_NO_LOADING_SCREEN();
		return retval;
	}

	static void LUA_NATIVE_SCRIPTS__DISPLAY_LOADING_SCREENS(Hash p0, Hash p1, Hash p2, sol::stack_object gamemodeName, sol::stack_object title, sol::stack_object subtitle)
	{
		SCRIPTS::_DISPLAY_LOADING_SCREENS(p0, p1, p2, gamemodeName.is<const char*>() ? gamemodeName.as<const char*>() : nullptr, title.is<const char*>() ? title.as<const char*>() : nullptr, subtitle.is<const char*>() ? subtitle.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_SCRIPTS__0x29FB4CE89472C3CB(Any p0, Any p1, float p2, float p3, sol::stack_object p4, sol::stack_object p5, sol::stack_object p6, int p7)
	{
		SCRIPTS::_0x29FB4CE89472C3CB(p0, p1, p2, p3, p4.is<const char*>() ? p4.as<const char*>() : nullptr, p5.is<const char*>() ? p5.as<const char*>() : nullptr, p6.is<const char*>() ? p6.as<const char*>() : nullptr, p7);
	}

	static void LUA_NATIVE_SCRIPTS_STOP_DISPLAYING_MP_TRANSITION_LOADING_SCREENS(Any p0)
	{
		SCRIPTS::STOP_DISPLAYING_MP_TRANSITION_LOADING_SCREENS(p0);
	}

	static bool LUA_NATIVE_SCRIPTS_IS_LOADING_SCREEN_VISIBLE()
	{
		auto retval = (bool)SCRIPTS::IS_LOADING_SCREEN_VISIBLE();
		return retval;
	}

	static void LUA_NATIVE_SCRIPTS_BAIL_TO_LANDING_PAGE(int bailCode)
	{
		SCRIPTS::BAIL_TO_LANDING_PAGE(bailCode);
	}

	static void LUA_NATIVE_SCRIPTS_BAIL_WITH_PASS_THROUGH_PARAMS(sol::stack_object params)
	{
		SCRIPTS::BAIL_WITH_PASS_THROUGH_PARAMS(params.is<const char*>() ? params.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_SCRIPTS_BG_IS_EXITFLAG_SET()
	{
		auto retval = (bool)SCRIPTS::BG_IS_EXITFLAG_SET();
		return retval;
	}

	static void LUA_NATIVE_SCRIPTS_BG_SET_EXITFLAG_RESPONSE()
	{
		SCRIPTS::BG_SET_EXITFLAG_RESPONSE();
	}

	static void LUA_NATIVE_SCRIPTS_BG_START_CONTEXT_HASH(Hash context)
	{
		SCRIPTS::BG_START_CONTEXT_HASH(context);
	}

	static void LUA_NATIVE_SCRIPTS_BG_END_CONTEXT_HASH(Hash context)
	{
		SCRIPTS::BG_END_CONTEXT_HASH(context);
	}

	static void LUA_NATIVE_SCRIPTS_BG_START_CONTEXT(sol::stack_object context)
	{
		SCRIPTS::BG_START_CONTEXT(context.is<const char*>() ? context.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_SCRIPTS_BG_END_CONTEXT(sol::stack_object context)
	{
		SCRIPTS::BG_END_CONTEXT(context.is<const char*>() ? context.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_SCRIPTS_BG_DOES_LAUNCH_PARAM_EXIST(int bgScriptId, sol::stack_object paramName)
	{
		auto retval = (bool)SCRIPTS::BG_DOES_LAUNCH_PARAM_EXIST(bgScriptId, paramName.is<const char*>() ? paramName.as<const char*>() : nullptr);
		return retval;
	}

	static int LUA_NATIVE_SCRIPTS_BG_GET_LAUNCH_PARAM_VALUE(int bgScriptId, sol::stack_object paramName)
	{
		auto retval = SCRIPTS::BG_GET_LAUNCH_PARAM_VALUE(bgScriptId, paramName.is<const char*>() ? paramName.as<const char*>() : nullptr);
		return retval;
	}

	static int LUA_NATIVE_SCRIPTS_BG_GET_SCRIPT_ID_FROM_NAME_HASH(Hash scriptNameHash)
	{
		auto retval = SCRIPTS::BG_GET_SCRIPT_ID_FROM_NAME_HASH(scriptNameHash);
		return retval;
	}

	static void LUA_NATIVE_SCRIPTS__BG_RELOAD_ALL_BACKGROUND_SCRIPTS()
	{
		SCRIPTS::_BG_RELOAD_ALL_BACKGROUND_SCRIPTS();
	}

	static void LUA_NATIVE_SCRIPTS__ACTIVATE_GOAL_CONTEXT(Hash goalContext)
	{
		SCRIPTS::_ACTIVATE_GOAL_CONTEXT(goalContext);
	}

	static void LUA_NATIVE_SCRIPTS__DEACTIVATE_GOAL_CONTEXT(Hash goalContext)
	{
		SCRIPTS::_DEACTIVATE_GOAL_CONTEXT(goalContext);
	}

	static bool LUA_NATIVE_SCRIPTS__IS_GOAL_CONTEXT_ACTIVE(Hash goalContext)
	{
		auto retval = (bool)SCRIPTS::_IS_GOAL_CONTEXT_ACTIVE(goalContext);
		return retval;
	}

	static const char* LUA_NATIVE_SCRIPTS__NET_RPC_GUID_TO_STRING(uintptr_t netRpcGuid)
	{
		auto retval = SCRIPTS::_NET_RPC_GUID_TO_STRING((Any*)netRpcGuid);
		return retval;
	}

	static bool LUA_NATIVE_SCRIPTS_AWARDS_GET_RESULT_ITEM(uintptr_t rpcGuid, Hash awardHash, int itemIndex, uintptr_t outResultItem)
	{
		auto retval = (bool)SCRIPTS::AWARDS_GET_RESULT_ITEM((Any*)rpcGuid, awardHash, itemIndex, (Any*)outResultItem);
		return retval;
	}

	static bool LUA_NATIVE_SCRIPTS__AWARDS_GET_UNLOCK_CLAIM_DATA(uintptr_t rpcGuid, Hash awardHash, int dataIndex, uintptr_t outUnlockData)
	{
		auto retval = (bool)SCRIPTS::_AWARDS_GET_UNLOCK_CLAIM_DATA((Any*)rpcGuid, awardHash, dataIndex, (Any*)outUnlockData);
		return retval;
	}

	static bool LUA_NATIVE_SCRIPTS__LOOT_GET_RESULT_ITEM(uintptr_t rpcGuid, int itemIndex, uintptr_t outResultItem)
	{
		auto retval = (bool)SCRIPTS::_LOOT_GET_RESULT_ITEM((Any*)rpcGuid, itemIndex, (Any*)outResultItem);
		return retval;
	}

	static bool LUA_NATIVE_SCRIPTS__LOOT_GET_LOOT_CLAIM_DATA(uintptr_t rpcGuid, int dataIndex, uintptr_t outLootData)
	{
		auto retval = (bool)SCRIPTS::_LOOT_GET_LOOT_CLAIM_DATA((Any*)rpcGuid, dataIndex, (Any*)outLootData);
		return retval;
	}

	static bool LUA_NATIVE_SCRIPTS__STORE_GLOBAL_BLOCK(int index)
	{
		auto retval = (bool)SCRIPTS::_STORE_GLOBAL_BLOCK(index);
		return retval;
	}

	static bool LUA_NATIVE_SCRIPTS__RESTORE_GLOBAL_BLOCK(int index)
	{
		auto retval = (bool)SCRIPTS::_RESTORE_GLOBAL_BLOCK(index);
		return retval;
	}

	static bool LUA_NATIVE_SCRIPTS__DOES_COMPRESSED_GLOBAL_BLOCK_BUFFER_EXIST(int index)
	{
		auto retval = (bool)SCRIPTS::_DOES_COMPRESSED_GLOBAL_BLOCK_BUFFER_EXIST(index);
		return retval;
	}

	static void LUA_NATIVE_SCRIPTS__SET_GLOBAL_BLOCK_CAN_BE_ACCESSED(int index, bool toggle)
	{
		SCRIPTS::_SET_GLOBAL_BLOCK_CAN_BE_ACCESSED(index, toggle);
	}

	static bool LUA_NATIVE_SCRIPTS__GET_GLOBAL_BLOCK_CAN_BE_ACCESSED(int index)
	{
		auto retval = (bool)SCRIPTS::_GET_GLOBAL_BLOCK_CAN_BE_ACCESSED(index);
		return retval;
	}

	static void LUA_NATIVE_SCRIPTS__SET_ALL_GLOBAL_BLOCKS_HAVE_BEEN_LOADED(bool toggle)
	{
		SCRIPTS::_SET_ALL_GLOBAL_BLOCKS_HAVE_BEEN_LOADED(toggle);
	}

	static bool LUA_NATIVE_SCRIPTS_HAVE_ALL_CHILD_SCRIPTS_TERMINATED(int p0)
	{
		auto retval = (bool)SCRIPTS::HAVE_ALL_CHILD_SCRIPTS_TERMINATED(p0);
		return retval;
	}

	static int LUA_NATIVE_SCRIPTS_START_NEW_SCRIPT(sol::stack_object pScriptName, int stackSize)
	{
		auto retval = SCRIPTS::START_NEW_SCRIPT(pScriptName.is<const char*>() ? pScriptName.as<const char*>() : nullptr, stackSize);
		return retval;
	}

	static int LUA_NATIVE_SCRIPTS_START_NEW_SCRIPT_WITH_ARGS(sol::stack_object pScriptName, uintptr_t args, int argCount, int stackSize)
	{
		auto retval = SCRIPTS::START_NEW_SCRIPT_WITH_ARGS(pScriptName.is<const char*>() ? pScriptName.as<const char*>() : nullptr, (Any*)args, argCount, stackSize);
		return retval;
	}

	static int LUA_NATIVE_SCRIPTS_START_NEW_SCRIPT_WITH_NAME_HASH(Hash scriptHash, int stackSize)
	{
		auto retval = SCRIPTS::START_NEW_SCRIPT_WITH_NAME_HASH(scriptHash, stackSize);
		return retval;
	}

	static int LUA_NATIVE_SCRIPTS_START_NEW_SCRIPT_WITH_NAME_HASH_AND_ARGS(Hash scriptHash, uintptr_t args, int argCount, int stackSize)
	{
		auto retval = SCRIPTS::START_NEW_SCRIPT_WITH_NAME_HASH_AND_ARGS(scriptHash, (Any*)args, argCount, stackSize);
		return retval;
	}

	void RegisterNatives_SCRIPTS(sol::state& L)
	{
		auto SCRIPTS = L["SCRIPTS"].get_or_create<sol::table>();
		SCRIPTS.set_function("_SET_PLAYER_BIT_AT_INDEX", LUA_NATIVE_SCRIPTS__SET_PLAYER_BIT_AT_INDEX);
		SCRIPTS.set_function("_CLEAR_PLAYER_BIT_AT_INDEX", LUA_NATIVE_SCRIPTS__CLEAR_PLAYER_BIT_AT_INDEX);
		SCRIPTS.set_function("_0xE4ABE20DCE7C7CFE", LUA_NATIVE_SCRIPTS__0xE4ABE20DCE7C7CFE);
		SCRIPTS.set_function("_0xFFDDF802279BE128", LUA_NATIVE_SCRIPTS__0xFFDDF802279BE128);
		SCRIPTS.set_function("_0x64F765D9A1F8F02C", LUA_NATIVE_SCRIPTS__0x64F765D9A1F8F02C);
		SCRIPTS.set_function("_SET_ALL_PLAYER_BITS", LUA_NATIVE_SCRIPTS__SET_ALL_PLAYER_BITS);
		SCRIPTS.set_function("_CLEAR_ALL_PLAYER_BITS", LUA_NATIVE_SCRIPTS__CLEAR_ALL_PLAYER_BITS);
		SCRIPTS.set_function("_IS_PLAYER_BIT_SET_AT_INDEX", LUA_NATIVE_SCRIPTS__IS_PLAYER_BIT_SET_AT_INDEX);
		SCRIPTS.set_function("_IS_ANY_PLAYER_BIT_SET", LUA_NATIVE_SCRIPTS__IS_ANY_PLAYER_BIT_SET);
		SCRIPTS.set_function("GET_BLOCK_OF_PLAYER_BITS", LUA_NATIVE_SCRIPTS_GET_BLOCK_OF_PLAYER_BITS);
		SCRIPTS.set_function("SET_BLOCK_OF_PLAYER_BITS", LUA_NATIVE_SCRIPTS_SET_BLOCK_OF_PLAYER_BITS);
		SCRIPTS.set_function("COUNT_PLAYER_BITS", LUA_NATIVE_SCRIPTS_COUNT_PLAYER_BITS);
		SCRIPTS.set_function("_0x1BDB5A07307F6929", LUA_NATIVE_SCRIPTS__0x1BDB5A07307F6929);
		SCRIPTS.set_function("_0x1C5EB3C27F7508CB", LUA_NATIVE_SCRIPTS__0x1C5EB3C27F7508CB);
		SCRIPTS.set_function("_0x42A429CDFED6D99D", LUA_NATIVE_SCRIPTS__0x42A429CDFED6D99D);
		SCRIPTS.set_function("_0x5827BE85A87B073D", LUA_NATIVE_SCRIPTS__0x5827BE85A87B073D);
		SCRIPTS.set_function("_0x0A79C81C418F5D38", LUA_NATIVE_SCRIPTS__0x0A79C81C418F5D38);
		SCRIPTS.set_function("_0xA88E1D7FA1E20080", LUA_NATIVE_SCRIPTS__0xA88E1D7FA1E20080);
		SCRIPTS.set_function("COUNT_PARTICIPANT_BITS", LUA_NATIVE_SCRIPTS_COUNT_PARTICIPANT_BITS);
		SCRIPTS.set_function("REQUEST_SCRIPT", LUA_NATIVE_SCRIPTS_REQUEST_SCRIPT);
		SCRIPTS.set_function("SET_SCRIPT_AS_NO_LONGER_NEEDED", LUA_NATIVE_SCRIPTS_SET_SCRIPT_AS_NO_LONGER_NEEDED);
		SCRIPTS.set_function("HAS_SCRIPT_LOADED", LUA_NATIVE_SCRIPTS_HAS_SCRIPT_LOADED);
		SCRIPTS.set_function("DOES_SCRIPT_EXIST", LUA_NATIVE_SCRIPTS_DOES_SCRIPT_EXIST);
		SCRIPTS.set_function("REQUEST_SCRIPT_WITH_NAME_HASH", LUA_NATIVE_SCRIPTS_REQUEST_SCRIPT_WITH_NAME_HASH);
		SCRIPTS.set_function("SET_SCRIPT_WITH_NAME_HASH_AS_NO_LONGER_NEEDED", LUA_NATIVE_SCRIPTS_SET_SCRIPT_WITH_NAME_HASH_AS_NO_LONGER_NEEDED);
		SCRIPTS.set_function("HAS_SCRIPT_WITH_NAME_HASH_LOADED", LUA_NATIVE_SCRIPTS_HAS_SCRIPT_WITH_NAME_HASH_LOADED);
		SCRIPTS.set_function("DOES_SCRIPT_WITH_NAME_HASH_EXIST", LUA_NATIVE_SCRIPTS_DOES_SCRIPT_WITH_NAME_HASH_EXIST);
		SCRIPTS.set_function("TERMINATE_THREAD", LUA_NATIVE_SCRIPTS_TERMINATE_THREAD);
		SCRIPTS.set_function("IS_THREAD_ACTIVE", LUA_NATIVE_SCRIPTS_IS_THREAD_ACTIVE);
		SCRIPTS.set_function("DOES_THREAD_EXIST", LUA_NATIVE_SCRIPTS_DOES_THREAD_EXIST);
		SCRIPTS.set_function("GET_THREAD_EXISTENCE_DETAILS", LUA_NATIVE_SCRIPTS_GET_THREAD_EXISTENCE_DETAILS);
		SCRIPTS.set_function("_GET_HASH_OF_THREAD", LUA_NATIVE_SCRIPTS__GET_HASH_OF_THREAD);
		SCRIPTS.set_function("SCRIPT_THREAD_ITERATOR_RESET", LUA_NATIVE_SCRIPTS_SCRIPT_THREAD_ITERATOR_RESET);
		SCRIPTS.set_function("SCRIPT_THREAD_ITERATOR_GET_NEXT_THREAD_ID", LUA_NATIVE_SCRIPTS_SCRIPT_THREAD_ITERATOR_GET_NEXT_THREAD_ID);
		SCRIPTS.set_function("_IS_BACKGROUND_SCRIPT", LUA_NATIVE_SCRIPTS__IS_BACKGROUND_SCRIPT);
		SCRIPTS.set_function("GET_ID_OF_THIS_THREAD", LUA_NATIVE_SCRIPTS_GET_ID_OF_THIS_THREAD);
		SCRIPTS.set_function("TERMINATE_THIS_THREAD", LUA_NATIVE_SCRIPTS_TERMINATE_THIS_THREAD);
		SCRIPTS.set_function("GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH", LUA_NATIVE_SCRIPTS_GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH);
		SCRIPTS.set_function("_REQUEST_THREAD_EXIT", LUA_NATIVE_SCRIPTS__REQUEST_THREAD_EXIT);
		SCRIPTS.set_function("_REQUEST_THREAD_EXIT_FOR_ALL_THREADS_WITH_THIS_NAME", LUA_NATIVE_SCRIPTS__REQUEST_THREAD_EXIT_FOR_ALL_THREADS_WITH_THIS_NAME);
		SCRIPTS.set_function("IS_THREAD_EXIT_REQUESTED", LUA_NATIVE_SCRIPTS_IS_THREAD_EXIT_REQUESTED);
		SCRIPTS.set_function("_IS_THREAD_EXIT_REQUESTED_FOR_THREAD_WITH_THIS_ID", LUA_NATIVE_SCRIPTS__IS_THREAD_EXIT_REQUESTED_FOR_THREAD_WITH_THIS_ID);
		SCRIPTS.set_function("_GET_THREAD_EXIT_REASON", LUA_NATIVE_SCRIPTS__GET_THREAD_EXIT_REASON);
		SCRIPTS.set_function("GET_HASH_OF_THIS_SCRIPT_NAME", LUA_NATIVE_SCRIPTS_GET_HASH_OF_THIS_SCRIPT_NAME);
		SCRIPTS.set_function("GET_NUMBER_OF_EVENTS", LUA_NATIVE_SCRIPTS_GET_NUMBER_OF_EVENTS);
		SCRIPTS.set_function("GET_EVENT_EXISTS", LUA_NATIVE_SCRIPTS_GET_EVENT_EXISTS);
		SCRIPTS.set_function("GET_EVENT_AT_INDEX", LUA_NATIVE_SCRIPTS_GET_EVENT_AT_INDEX);
		SCRIPTS.set_function("GET_EVENT_DATA", LUA_NATIVE_SCRIPTS_GET_EVENT_DATA);
		SCRIPTS.set_function("SET_EVENT_FLAG_FOR_DELETION", LUA_NATIVE_SCRIPTS_SET_EVENT_FLAG_FOR_DELETION);
		SCRIPTS.set_function("TRIGGER_SCRIPT_EVENT", LUA_NATIVE_SCRIPTS_TRIGGER_SCRIPT_EVENT);
		SCRIPTS.set_function("_TRIGGER_SCRIPT_EVENT_2", LUA_NATIVE_SCRIPTS__TRIGGER_SCRIPT_EVENT_2);
		SCRIPTS.set_function("_0xE7282390542F570D", LUA_NATIVE_SCRIPTS__0xE7282390542F570D);
		SCRIPTS.set_function("_0x11B0A0B282FA9B10", LUA_NATIVE_SCRIPTS__0x11B0A0B282FA9B10);
		SCRIPTS.set_function("_0x6F700A4BF7C3331B", LUA_NATIVE_SCRIPTS__0x6F700A4BF7C3331B);
		SCRIPTS.set_function("_0xF9E951A1E5517C06", LUA_NATIVE_SCRIPTS__0xF9E951A1E5517C06);
		SCRIPTS.set_function("_0x76CBCD9EADC00955", LUA_NATIVE_SCRIPTS__0x76CBCD9EADC00955);
		SCRIPTS.set_function("SHUTDOWN_LOADING_SCREEN", LUA_NATIVE_SCRIPTS_SHUTDOWN_LOADING_SCREEN);
		SCRIPTS.set_function("SET_NO_LOADING_SCREEN", LUA_NATIVE_SCRIPTS_SET_NO_LOADING_SCREEN);
		SCRIPTS.set_function("GET_NO_LOADING_SCREEN", LUA_NATIVE_SCRIPTS_GET_NO_LOADING_SCREEN);
		SCRIPTS.set_function("_DISPLAY_LOADING_SCREENS", LUA_NATIVE_SCRIPTS__DISPLAY_LOADING_SCREENS);
		SCRIPTS.set_function("_0x29FB4CE89472C3CB", LUA_NATIVE_SCRIPTS__0x29FB4CE89472C3CB);
		SCRIPTS.set_function("STOP_DISPLAYING_MP_TRANSITION_LOADING_SCREENS", LUA_NATIVE_SCRIPTS_STOP_DISPLAYING_MP_TRANSITION_LOADING_SCREENS);
		SCRIPTS.set_function("IS_LOADING_SCREEN_VISIBLE", LUA_NATIVE_SCRIPTS_IS_LOADING_SCREEN_VISIBLE);
		SCRIPTS.set_function("BAIL_TO_LANDING_PAGE", LUA_NATIVE_SCRIPTS_BAIL_TO_LANDING_PAGE);
		SCRIPTS.set_function("BAIL_WITH_PASS_THROUGH_PARAMS", LUA_NATIVE_SCRIPTS_BAIL_WITH_PASS_THROUGH_PARAMS);
		SCRIPTS.set_function("BG_IS_EXITFLAG_SET", LUA_NATIVE_SCRIPTS_BG_IS_EXITFLAG_SET);
		SCRIPTS.set_function("BG_SET_EXITFLAG_RESPONSE", LUA_NATIVE_SCRIPTS_BG_SET_EXITFLAG_RESPONSE);
		SCRIPTS.set_function("BG_START_CONTEXT_HASH", LUA_NATIVE_SCRIPTS_BG_START_CONTEXT_HASH);
		SCRIPTS.set_function("BG_END_CONTEXT_HASH", LUA_NATIVE_SCRIPTS_BG_END_CONTEXT_HASH);
		SCRIPTS.set_function("BG_START_CONTEXT", LUA_NATIVE_SCRIPTS_BG_START_CONTEXT);
		SCRIPTS.set_function("BG_END_CONTEXT", LUA_NATIVE_SCRIPTS_BG_END_CONTEXT);
		SCRIPTS.set_function("BG_DOES_LAUNCH_PARAM_EXIST", LUA_NATIVE_SCRIPTS_BG_DOES_LAUNCH_PARAM_EXIST);
		SCRIPTS.set_function("BG_GET_LAUNCH_PARAM_VALUE", LUA_NATIVE_SCRIPTS_BG_GET_LAUNCH_PARAM_VALUE);
		SCRIPTS.set_function("BG_GET_SCRIPT_ID_FROM_NAME_HASH", LUA_NATIVE_SCRIPTS_BG_GET_SCRIPT_ID_FROM_NAME_HASH);
		SCRIPTS.set_function("_BG_RELOAD_ALL_BACKGROUND_SCRIPTS", LUA_NATIVE_SCRIPTS__BG_RELOAD_ALL_BACKGROUND_SCRIPTS);
		SCRIPTS.set_function("_ACTIVATE_GOAL_CONTEXT", LUA_NATIVE_SCRIPTS__ACTIVATE_GOAL_CONTEXT);
		SCRIPTS.set_function("_DEACTIVATE_GOAL_CONTEXT", LUA_NATIVE_SCRIPTS__DEACTIVATE_GOAL_CONTEXT);
		SCRIPTS.set_function("_IS_GOAL_CONTEXT_ACTIVE", LUA_NATIVE_SCRIPTS__IS_GOAL_CONTEXT_ACTIVE);
		SCRIPTS.set_function("_NET_RPC_GUID_TO_STRING", LUA_NATIVE_SCRIPTS__NET_RPC_GUID_TO_STRING);
		SCRIPTS.set_function("AWARDS_GET_RESULT_ITEM", LUA_NATIVE_SCRIPTS_AWARDS_GET_RESULT_ITEM);
		SCRIPTS.set_function("_AWARDS_GET_UNLOCK_CLAIM_DATA", LUA_NATIVE_SCRIPTS__AWARDS_GET_UNLOCK_CLAIM_DATA);
		SCRIPTS.set_function("_LOOT_GET_RESULT_ITEM", LUA_NATIVE_SCRIPTS__LOOT_GET_RESULT_ITEM);
		SCRIPTS.set_function("_LOOT_GET_LOOT_CLAIM_DATA", LUA_NATIVE_SCRIPTS__LOOT_GET_LOOT_CLAIM_DATA);
		SCRIPTS.set_function("_STORE_GLOBAL_BLOCK", LUA_NATIVE_SCRIPTS__STORE_GLOBAL_BLOCK);
		SCRIPTS.set_function("_RESTORE_GLOBAL_BLOCK", LUA_NATIVE_SCRIPTS__RESTORE_GLOBAL_BLOCK);
		SCRIPTS.set_function("_DOES_COMPRESSED_GLOBAL_BLOCK_BUFFER_EXIST", LUA_NATIVE_SCRIPTS__DOES_COMPRESSED_GLOBAL_BLOCK_BUFFER_EXIST);
		SCRIPTS.set_function("_SET_GLOBAL_BLOCK_CAN_BE_ACCESSED", LUA_NATIVE_SCRIPTS__SET_GLOBAL_BLOCK_CAN_BE_ACCESSED);
		SCRIPTS.set_function("_GET_GLOBAL_BLOCK_CAN_BE_ACCESSED", LUA_NATIVE_SCRIPTS__GET_GLOBAL_BLOCK_CAN_BE_ACCESSED);
		SCRIPTS.set_function("_SET_ALL_GLOBAL_BLOCKS_HAVE_BEEN_LOADED", LUA_NATIVE_SCRIPTS__SET_ALL_GLOBAL_BLOCKS_HAVE_BEEN_LOADED);
		SCRIPTS.set_function("HAVE_ALL_CHILD_SCRIPTS_TERMINATED", LUA_NATIVE_SCRIPTS_HAVE_ALL_CHILD_SCRIPTS_TERMINATED);
		SCRIPTS.set_function("START_NEW_SCRIPT", LUA_NATIVE_SCRIPTS_START_NEW_SCRIPT);
		SCRIPTS.set_function("START_NEW_SCRIPT_WITH_ARGS", LUA_NATIVE_SCRIPTS_START_NEW_SCRIPT_WITH_ARGS);
		SCRIPTS.set_function("START_NEW_SCRIPT_WITH_NAME_HASH", LUA_NATIVE_SCRIPTS_START_NEW_SCRIPT_WITH_NAME_HASH);
		SCRIPTS.set_function("START_NEW_SCRIPT_WITH_NAME_HASH_AND_ARGS", LUA_NATIVE_SCRIPTS_START_NEW_SCRIPT_WITH_NAME_HASH_AND_ARGS);
	}
}
