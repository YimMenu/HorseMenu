---@meta

---@class SCRIPTS
SCRIPTS = {}

---@param value integer
---@param bitIndex integer
function SCRIPTS._SET_PLAYER_BIT_AT_INDEX(value, bitIndex) end

---@param value integer
---@param bitIndex integer
function SCRIPTS._CLEAR_PLAYER_BIT_AT_INDEX(value, bitIndex) end

---@param p0 any
---@param p1 any
---@param p2 any
function SCRIPTS._0xE4ABE20DCE7C7CFE(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
function SCRIPTS._0xFFDDF802279BE128(p0, p1, p2) end

---@param p0 integer
---@param p1 integer
---@param p2 integer
function SCRIPTS._0x64F765D9A1F8F02C(p0, p1, p2) end

---@param value integer
function SCRIPTS._SET_ALL_PLAYER_BITS(value) end

---@param value integer
function SCRIPTS._CLEAR_ALL_PLAYER_BITS(value) end

---@param value integer
---@param bitIndex integer
---@return boolean
function SCRIPTS._IS_PLAYER_BIT_SET_AT_INDEX(value, bitIndex) end

---@param playerBits integer
---@return boolean
---@return integer
function SCRIPTS._IS_ANY_PLAYER_BIT_SET(playerBits) end

---@param value integer
---@param p1 integer
---@return integer
function SCRIPTS.GET_BLOCK_OF_PLAYER_BITS(value, p1) end

---@param value integer
---@param p1 integer
---@param p2 integer
function SCRIPTS.SET_BLOCK_OF_PLAYER_BITS(value, p1, p2) end

---@param value integer
---@return integer
function SCRIPTS.COUNT_PLAYER_BITS(value) end

---@param p0 any
---@param p1 any
function SCRIPTS._0x1BDB5A07307F6929(p0, p1) end

---@param p0 any
---@param p1 any
function SCRIPTS._0x1C5EB3C27F7508CB(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function SCRIPTS._0x42A429CDFED6D99D(p0, p1, p2) end

---@param p0 any
function SCRIPTS._0x5827BE85A87B073D(p0) end

---@param p0 any
---@param p1 any
---@return any
function SCRIPTS._0x0A79C81C418F5D38(p0, p1) end

---@param p0 any
---@return any
function SCRIPTS._0xA88E1D7FA1E20080(p0) end

---@param value integer
---@return integer
function SCRIPTS.COUNT_PARTICIPANT_BITS(value) end

---@param scriptname any
function SCRIPTS.REQUEST_SCRIPT(scriptname) end

---@param scriptname any
function SCRIPTS.SET_SCRIPT_AS_NO_LONGER_NEEDED(scriptname) end

---@param scriptname any
---@return boolean
function SCRIPTS.HAS_SCRIPT_LOADED(scriptname) end

---@param scriptname any
---@return boolean
function SCRIPTS.DOES_SCRIPT_EXIST(scriptname) end

---@param hashOfScriptName integer
function SCRIPTS.REQUEST_SCRIPT_WITH_NAME_HASH(hashOfScriptName) end

---@param hashOfScriptName integer
function SCRIPTS.SET_SCRIPT_WITH_NAME_HASH_AS_NO_LONGER_NEEDED(hashOfScriptName) end

---@param hashOfScriptName integer
---@return boolean
function SCRIPTS.HAS_SCRIPT_WITH_NAME_HASH_LOADED(hashOfScriptName) end

---@param hashOfScriptName integer
---@return boolean
function SCRIPTS.DOES_SCRIPT_WITH_NAME_HASH_EXIST(hashOfScriptName) end

---@param thread integer
function SCRIPTS.TERMINATE_THREAD(thread) end

---@param thread integer
---@param ignoreKilledState boolean
---@return boolean
function SCRIPTS.IS_THREAD_ACTIVE(thread, ignoreKilledState) end

---@param threadId integer
---@return boolean
function SCRIPTS.DOES_THREAD_EXIST(threadId) end

---@param threadId integer
---@param threadExists boolean
---@param hasScriptHandler boolean
---@return boolean
---@return boolean
function SCRIPTS.GET_THREAD_EXISTENCE_DETAILS(threadId, threadExists, hasScriptHandler) end

---@param threadId integer
---@return integer
function SCRIPTS._GET_HASH_OF_THREAD(threadId) end

function SCRIPTS.SCRIPT_THREAD_ITERATOR_RESET() end

---@return integer
function SCRIPTS.SCRIPT_THREAD_ITERATOR_GET_NEXT_THREAD_ID() end

---@param threadId integer
---@return boolean
function SCRIPTS._IS_BACKGROUND_SCRIPT(threadId) end

---@return integer
function SCRIPTS.GET_ID_OF_THIS_THREAD() end

function SCRIPTS.TERMINATE_THIS_THREAD() end

---@param HashOfScriptName integer
---@return integer
function SCRIPTS.GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH(HashOfScriptName) end

---@param threadId integer
function SCRIPTS._REQUEST_THREAD_EXIT(threadId) end

---@param nameHash integer
function SCRIPTS._REQUEST_THREAD_EXIT_FOR_ALL_THREADS_WITH_THIS_NAME(nameHash) end

---@return boolean
function SCRIPTS.IS_THREAD_EXIT_REQUESTED() end

---@param threadId integer
---@return boolean
function SCRIPTS._IS_THREAD_EXIT_REQUESTED_FOR_THREAD_WITH_THIS_ID(threadId) end

---@return integer
function SCRIPTS._GET_THREAD_EXIT_REASON() end

---@return integer
function SCRIPTS.GET_HASH_OF_THIS_SCRIPT_NAME() end

---@param eventQueue integer
---@return integer
function SCRIPTS.GET_NUMBER_OF_EVENTS(eventQueue) end

---@param eventQueue integer
---@param eventType integer
---@return boolean
function SCRIPTS.GET_EVENT_EXISTS(eventQueue, eventType) end

---@param eventQueue integer
---@param eventIndex integer
---@return integer
function SCRIPTS.GET_EVENT_AT_INDEX(eventQueue, eventIndex) end

---@param eventQueue integer
---@param eventIndex integer
---@param data integer
---@param dataSize integer
---@return boolean
function SCRIPTS.GET_EVENT_DATA(eventQueue, eventIndex, data, dataSize) end

---@param eventGroup integer
---@param eventIndex integer
---@param p2 boolean
function SCRIPTS.SET_EVENT_FLAG_FOR_DELETION(eventGroup, eventIndex, p2) end

---@param eventQueue integer
---@param data integer
---@param sizeOfData integer
---@param scriptMetadataIndex integer
---@param playerBits integer
---@return integer
function SCRIPTS.TRIGGER_SCRIPT_EVENT(eventQueue, data, sizeOfData, scriptMetadataIndex, playerBits) end

---@param eventData integer
---@param eventDataSize integer
---@param scriptMetadataIndex integer
---@param threadId integer
function SCRIPTS._TRIGGER_SCRIPT_EVENT_2(eventData, eventDataSize, scriptMetadataIndex, threadId) end

---@param p0 any
---@return any
function SCRIPTS._0xE7282390542F570D(p0) end

---@param p0 boolean
function SCRIPTS._0x11B0A0B282FA9B10(p0) end

---@param p0 boolean
function SCRIPTS._0x6F700A4BF7C3331B(p0) end

function SCRIPTS._0xF9E951A1E5517C06() end

function SCRIPTS._0x76CBCD9EADC00955() end

function SCRIPTS.SHUTDOWN_LOADING_SCREEN() end

---@param state boolean
function SCRIPTS.SET_NO_LOADING_SCREEN(state) end

---@return boolean
function SCRIPTS.GET_NO_LOADING_SCREEN() end

---@param p0 integer
---@param p1 integer
---@param p2 integer
---@param gamemodeName any
---@param title any
---@param subtitle any
function SCRIPTS._DISPLAY_LOADING_SCREENS(p0, p1, p2, gamemodeName, title, subtitle) end

---@param p0 any
---@param p1 any
---@param p2 number
---@param p3 number
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 integer
function SCRIPTS._0x29FB4CE89472C3CB(p0, p1, p2, p3, p4, p5, p6, p7) end

---@param p0 any
function SCRIPTS.STOP_DISPLAYING_MP_TRANSITION_LOADING_SCREENS(p0) end

---@return boolean
function SCRIPTS.IS_LOADING_SCREEN_VISIBLE() end

---@param bailCode integer
function SCRIPTS.BAIL_TO_LANDING_PAGE(bailCode) end

---@param params any
function SCRIPTS.BAIL_WITH_PASS_THROUGH_PARAMS(params) end

---@return boolean
function SCRIPTS.BG_IS_EXITFLAG_SET() end

function SCRIPTS.BG_SET_EXITFLAG_RESPONSE() end

---@param context integer
function SCRIPTS.BG_START_CONTEXT_HASH(context) end

---@param context integer
function SCRIPTS.BG_END_CONTEXT_HASH(context) end

---@param context any
function SCRIPTS.BG_START_CONTEXT(context) end

---@param context any
function SCRIPTS.BG_END_CONTEXT(context) end

---@param bgScriptId integer
---@param paramName any
---@return boolean
function SCRIPTS.BG_DOES_LAUNCH_PARAM_EXIST(bgScriptId, paramName) end

---@param bgScriptId integer
---@param paramName any
---@return integer
function SCRIPTS.BG_GET_LAUNCH_PARAM_VALUE(bgScriptId, paramName) end

---@param scriptNameHash integer
---@return integer
function SCRIPTS.BG_GET_SCRIPT_ID_FROM_NAME_HASH(scriptNameHash) end

function SCRIPTS._BG_RELOAD_ALL_BACKGROUND_SCRIPTS() end

---@param goalContext integer
function SCRIPTS._ACTIVATE_GOAL_CONTEXT(goalContext) end

---@param goalContext integer
function SCRIPTS._DEACTIVATE_GOAL_CONTEXT(goalContext) end

---@param goalContext integer
---@return boolean
function SCRIPTS._IS_GOAL_CONTEXT_ACTIVE(goalContext) end

---@param netRpcGuid integer
---@return string
function SCRIPTS._NET_RPC_GUID_TO_STRING(netRpcGuid) end

---@param rpcGuid integer
---@param awardHash integer
---@param itemIndex integer
---@param outResultItem integer
---@return boolean
function SCRIPTS.AWARDS_GET_RESULT_ITEM(rpcGuid, awardHash, itemIndex, outResultItem) end

---@param rpcGuid integer
---@param awardHash integer
---@param dataIndex integer
---@param outUnlockData integer
---@return boolean
function SCRIPTS._AWARDS_GET_UNLOCK_CLAIM_DATA(rpcGuid, awardHash, dataIndex, outUnlockData) end

---@param rpcGuid integer
---@param itemIndex integer
---@param outResultItem integer
---@return boolean
function SCRIPTS._LOOT_GET_RESULT_ITEM(rpcGuid, itemIndex, outResultItem) end

---@param rpcGuid integer
---@param dataIndex integer
---@param outLootData integer
---@return boolean
function SCRIPTS._LOOT_GET_LOOT_CLAIM_DATA(rpcGuid, dataIndex, outLootData) end

---@param index integer
---@return boolean
function SCRIPTS._STORE_GLOBAL_BLOCK(index) end

---@param index integer
---@return boolean
function SCRIPTS._RESTORE_GLOBAL_BLOCK(index) end

---@param index integer
---@return boolean
function SCRIPTS._DOES_COMPRESSED_GLOBAL_BLOCK_BUFFER_EXIST(index) end

---@param index integer
---@param toggle boolean
function SCRIPTS._SET_GLOBAL_BLOCK_CAN_BE_ACCESSED(index, toggle) end

---@param index integer
---@return boolean
function SCRIPTS._GET_GLOBAL_BLOCK_CAN_BE_ACCESSED(index) end

---@param toggle boolean
function SCRIPTS._SET_ALL_GLOBAL_BLOCKS_HAVE_BEEN_LOADED(toggle) end

---@param p0 integer
---@return boolean
function SCRIPTS.HAVE_ALL_CHILD_SCRIPTS_TERMINATED(p0) end

---@param pScriptName any
---@param stackSize integer
---@return integer
function SCRIPTS.START_NEW_SCRIPT(pScriptName, stackSize) end

---@param pScriptName any
---@param args integer
---@param argCount integer
---@param stackSize integer
---@return integer
function SCRIPTS.START_NEW_SCRIPT_WITH_ARGS(pScriptName, args, argCount, stackSize) end

---@param scriptHash integer
---@param stackSize integer
---@return integer
function SCRIPTS.START_NEW_SCRIPT_WITH_NAME_HASH(scriptHash, stackSize) end

---@param scriptHash integer
---@param args integer
---@param argCount integer
---@param stackSize integer
---@return integer
function SCRIPTS.START_NEW_SCRIPT_WITH_NAME_HASH_AND_ARGS(scriptHash, args, argCount, stackSize) end
