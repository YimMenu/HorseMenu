---@meta

---@class NETWORK
NETWORK = {}

---@return boolean
function NETWORK.NETWORK_IS_SIGNED_ONLINE() end

---@return integer
function NETWORK.NETWORK_GET_NP_UNAVAILABLE_REASON() end

---@return boolean
function NETWORK.NETWORK_HAS_VALID_ROS_CREDENTIALS() end

---@return boolean
function NETWORK.NETWORK_IS_CLOUD_AVAILABLE() end

---@return boolean
function NETWORK.NETWORK_HAS_SOCIAL_CLUB_ACCOUNT() end

---@return boolean
function NETWORK.NETWORK_IS_HOST() end

---@return boolean
function NETWORK.NETWORK_HAVE_ONLINE_PRIVILEGES() end

---@param nGamerIndex integer
---@return boolean
function NETWORK.NETWORK_CHECK_USER_CONTENT_PRIVILEGES(nGamerIndex) end

---@param nGamerIndex integer
---@return boolean
function NETWORK.NETWORK_CHECK_COMMUNICATION_PRIVILEGES(nGamerIndex) end

---@param gamerHandle integer
---@return boolean
function NETWORK.NETWORK_CAN_VIEW_GAMER_USER_CONTENT(gamerHandle) end

---@param gamerHandle integer
---@return boolean
function NETWORK._0xF23A6D6C11D8EC15(gamerHandle) end

---@param p0 integer
---@return integer
function NETWORK._0x3E8CCE6769DB5F34(p0) end

function NETWORK.NETWORK_SHOW_ACCOUNT_UPGRADE_UI() end

---@return boolean
function NETWORK.NETWORK_IS_PROMOTION_ENABLED() end

---@return boolean
function NETWORK.NETWORK_IS_CUSTOM_UPSELL_ENABLED() end

---@return boolean
function NETWORK.NETWORK_SHOULD_SHOW_PROMOTION_DLG() end

function NETWORK._0xFC6FCF4C03F1BBF6() end

---@return any
function NETWORK._0x160F0CE6D76A39C9() end

---@return integer
function NETWORK.NETWORK_GET_PROMOTION_DLG_SEEN_COUNT() end

function NETWORK._0xE5FF65CFF5160752() end

---@param nAccessCode integer
---@return boolean
---@return integer
function NETWORK.NETWORK_CAN_ACCESS_MULTIPLAYER(nAccessCode) end

---@return boolean
function NETWORK.NETWORK_CHECK_ACCESS_AND_ALERT_IF_FAIL() end

---@param entity integer
---@return integer
function NETWORK._NETWORK_GET_GLOBAL_ENTITY_FLAGS(entity) end

---@param p0 boolean
function NETWORK._0xA95470DA137587F5(p0) end

---@param p0 boolean
---@return any
function NETWORK._0xBB697756309D77EE(p0) end

---@return boolean
function NETWORK._NETWORK_HAS_COMPLETED_MP_INTRO_FLOW_ON_CURRENT_SLOT() end

---@param completed boolean
---@return boolean
function NETWORK.NETWORK_SET_COMPLETED_MP_INTRO_FLOW_ON_CURRENT_SLOT(completed) end

---@param p0 integer
---@return boolean
function NETWORK._0xD7D0DF27CB1765B5(p0) end

---@param enabled boolean
---@param flagIndex integer
---@return boolean
function NETWORK.NETWORK_SET_MP_MISSION_FLAG_ON_CURRENT_SLOT(enabled, flagIndex) end

---@param p0 boolean
function NETWORK._0x3E74A687A73979C6(p0) end

---@return boolean
function NETWORK.NETWORK_SESSION_IS_PRIVATE() end

---@param sessionId integer
function NETWORK._NETWORK_SESSION_GET_SESSION_ID(sessionId) end

---@param sessionId1 integer
---@param sessionId2 integer
---@return boolean
function NETWORK._NETWORK_SESSION_ARE_SESSION_IDS_EQUAL(sessionId1, sessionId2) end

---@param flags integer
---@param seamlessType integer
---@param sessionRequestId integer
---@return boolean
function NETWORK.NETWORK_REQUEST_SESSION_SEAMLESS(flags, seamlessType, sessionRequestId) end

---@param flags integer
---@param seamlessType integer
---@param userHash integer
---@param sessionRequestId integer
---@return boolean
function NETWORK.NETWORK_SESSION_REQUEST_SESSION_SEAMLESS(flags, seamlessType, userHash, sessionRequestId) end

---@param flags integer
---@param matchType integer
---@param userHash integer
---@param p3 integer
---@param sessionRequestId integer
---@return boolean
function NETWORK.NETWORK_SESSION_REQUEST_SESSION_COMPETITIVE(flags, matchType, userHash, p3, sessionRequestId) end

---@param flags integer
---@param numPlayers integer
---@param userHash integer
---@param sessionRequestId integer
---@return boolean
function NETWORK.NETWORK_SESSION_REQUEST_SESSION_PRIVATE(flags, numPlayers, userHash, sessionRequestId) end

---@param flags integer
---@param category integer
---@param p2 integer
---@param userHash integer
---@param sessionRequestId integer
---@return boolean
function NETWORK._NETWORK_SESSION_REQUEST_SESSION_ON_CALL(flags, category, p2, userHash, sessionRequestId) end

---@param flags integer
---@param userHash integer
---@param p2 integer
---@param sessionRequestId integer
---@return boolean
function NETWORK._NETWORK_SESSION_REQUEST_SESSION_NOMINATED(flags, userHash, p2, sessionRequestId) end

---@param sessionRequestId integer
---@return boolean
function NETWORK.NETWORK_SESSION_IS_SESSION_REQUEST_ID_VALID(sessionRequestId) end

---@return integer
function NETWORK.NETWORK_SESSION_GET_SESSION_TYPE() end

---@return integer
function NETWORK._0x1413B6BF27AB7A95() end

---@return boolean
function NETWORK.NETWORK_SESSION_IS_ANY_REQUEST_IN_PROGRESS() end

---@param sessionRequestId integer
---@return boolean
function NETWORK._0xAFA14F98327791CE(sessionRequestId) end

---@param sessionRequestId integer
---@return boolean
function NETWORK.NETWORK_SESSION_IS_REQUEST_IN_PROGRESS(sessionRequestId) end

---@param queueGroup integer
---@return boolean
function NETWORK._NETWORK_SESSION_IS_REQUEST_IN_PROGRESS_BY_QUEUE_GROUP(queueGroup) end

---@param sessionRequestId integer
---@return boolean
function NETWORK._NETWORK_SESSION_CANCEL_REQUEST(sessionRequestId) end

---@param p0 integer
function NETWORK._0xA6F1BAABFF6AD7B9(p0) end

---@param sessionRequestId integer
---@param p1 integer
---@return integer
---@return integer
function NETWORK._NETWORK_SESSION_GET_SESSION_REQUEST_RESULT(sessionRequestId, p1) end

---@param sessionRequestId integer
---@return boolean
function NETWORK.NETWORK_SESSION_IS_REQUEST_PENDING_TRANSITION(sessionRequestId) end

---@param sessionRequestId integer
---@return boolean
function NETWORK._NETWORK_SESSION_TRANSITION_TO_SESSION(sessionRequestId) end

---@param sessionRequestId integer
---@return boolean
function NETWORK._NETWORK_SESSION_IS_NSRR_SUCCESS(sessionRequestId) end

---@param sessionRequestId integer
---@return boolean
function NETWORK.NETWORK_SESSION_LEFT_QUEUE_OR_REQUESTED_SESSION(sessionRequestId) end

---@return boolean
function NETWORK.NETWORK_SESSION_LEAVE_SESSION() end

---@return boolean
function NETWORK.NETWORK_SESSION_IS_TRANSITIONING() end

function NETWORK._0xFD4272A137703449() end

function NETWORK._NETWORK_SESSION_PLAYLIST_GO_TO_NEXT_CONTENT() end

function NETWORK._NETWORK_SESSION_PLAYLIST_GET_UPCOMING_CONTENT() end

function NETWORK.NETWORK_DISABLE_REALTIME_MULTIPLAYER() end

---@param p0 boolean
function NETWORK._0x71FA2D1880C48032(p0) end

---@param nHour integer
---@param nMinute integer
---@param nSecond integer
---@return integer
---@return integer
---@return integer
function NETWORK.NETWORK_GET_GLOBAL_MULTIPLAYER_CLOCK(nHour, nMinute, nSecond) end

function NETWORK.NETWORK_CLEAR_CLOCK_TIME_OVERRIDE() end

---@return boolean
function NETWORK.NETWORK_IS_CLOCK_TIME_OVERRIDDEN() end

---@param hour integer
---@param minute integer
---@param second integer
---@return boolean
---@return integer
---@return integer
---@return integer
function NETWORK.NETWORK_GET_GLOBAL_CLOCK(hour, minute, second) end

---@param hour integer
---@param minute integer
---@param second integer
---@param transitionTime integer
---@param pauseClock boolean
function NETWORK._NETWORK_CLOCK_TIME_OVERRIDE(hour, minute, second, transitionTime, pauseClock) end

---@param hour integer
---@param minute integer
---@param second integer
---@param transitionTime integer
---@param pauseClock boolean
---@param clockwise boolean
function NETWORK._NETWORK_CLOCK_TIME_OVERRIDE_2(hour, minute, second, transitionTime, pauseClock, clockwise) end

---@param milliseconds integer
function NETWORK._NETWORK_CLEAR_CLOCK_OVERRIDE_OVERTIME(milliseconds) end

---@return boolean
function NETWORK._0x0E54D4DA6018FF8E() end

---@return boolean
function NETWORK.NETWORK_IS_FINDING_GAMERS() end

---@return boolean
function NETWORK.NETWORK_DID_FIND_GAMERS_SUCCEED() end

---@param outData integer
---@param p1 integer
---@return integer
function NETWORK._0x7BCA0A3972708436(outData, p1) end

function NETWORK.NETWORK_CLEAR_FOUND_GAMERS() end

---@param data integer
---@param count integer
---@return boolean
function NETWORK._NETWORK_GET_GAMER_SESSION_FROM_HANDLE(data, count) end

---@return boolean
function NETWORK._NETWORK_HAS_CURRENT_GET_GAMER_STATUS_STARTED() end

---@return boolean
function NETWORK.NETWORK_DID_GET_GAMER_STATUS_SUCCEED() end

---@param gamerHandle integer
---@param p1 integer
---@return integer
function NETWORK._NETWORK_GET_GAMER_STATUS(gamerHandle, p1) end

function NETWORK.NETWORK_CLEAR_GET_GAMER_STATUS() end

---@param bReady boolean
function NETWORK.NETWORK_SET_SCRIPT_READY_FOR_EVENTS(bReady) end

---@return boolean
function NETWORK._0x316FD416C432C761() end

---@return boolean
function NETWORK._0x062842D61D0D53FD() end

---@return boolean
function NETWORK.NETWORK_IS_GAME_IN_PROGRESS() end

---@return boolean
function NETWORK.NETWORK_IS_SESSION_ACTIVE() end

---@return boolean
function NETWORK.NETWORK_IS_IN_SESSION() end

---@return boolean
function NETWORK._NETWORK_IS_IN_SESSION_LOBBY() end

---@return boolean
function NETWORK.NETWORK_IS_SESSION_STARTED() end

---@return boolean
function NETWORK.NETWORK_CAN_SESSION_END() end

---@return integer
function NETWORK.NETWORK_GET_GAME_MODE() end

---@param flags integer
---@return boolean
function NETWORK._NETWORK_SESSION_ADD_SESSION_FLAGS(flags) end

---@param flags integer
---@return boolean
function NETWORK.NETWORK_SESSION_REMOVE_SESSION_FLAGS(flags) end

---@return integer
function NETWORK.NETWORK_SESSION_GET_SESSION_FLAGS() end

---@param flags integer
---@return boolean
function NETWORK._NETWORK_SESSION_SET_PLAYER_FLAGS(flags) end

---@param flags integer
---@return boolean
function NETWORK._NETWORK_SESSION_REMOVE_PLAYER_FLAGS(flags) end

---@return integer
function NETWORK._NETWORK_GET_SESSION_HOST() end

---@return any
function NETWORK._0xD3A3C8B9F3BDEF81() end

---@return boolean
function NETWORK._0x18B94666CF610AEB() end

---@param inviteIndex integer
---@return boolean
function NETWORK._0x981146E5C9CE9250(inviteIndex) end

---@return integer
function NETWORK._0xBF8276E51761F9DA() end

---@param p0 any
---@return boolean
function NETWORK._0xDCA4A74135E1DEA5(p0) end

---@return boolean
function NETWORK.NETWORK_HAS_PENDING_INVITE_FAILURE() end

---@param gamerHandle integer
---@return boolean
function NETWORK._NETWORK_CAN_RECEIVE_INVITE_FROM_HANDLE(gamerHandle) end

---@param setting boolean
function NETWORK._0x704F92B3AF20D857(setting) end

---@param p0 any
function NETWORK._0xF342F6BD0A8287D5(p0) end

function NETWORK._0xD39A72AE5EBD57E5() end

---@param gamerHandle integer
---@param contentId any
---@param data integer
---@param dataSize integer
---@param p4 integer
---@param flags integer
---@return boolean
function NETWORK._NETWORK_SEND_SESSION_INVITE(gamerHandle, contentId, data, dataSize, p4, flags) end

---@param p0 integer
---@return boolean
function NETWORK._0xD1FFB246F4E088AC(p0) end

---@param p0 integer
---@return integer
function NETWORK._0x27B1AE4D8C652F08(p0) end

---@param p0 integer
---@return integer
function NETWORK._0x6C27442A225A241A(p0) end

---@param p0 integer
---@return string
function NETWORK._0xE59F4924BD3A718D(p0) end

---@param p0 integer
---@return integer
function NETWORK._0x78271BC02AE9AF83(p0) end

---@param p0 integer
---@param gamerHandle integer
---@return boolean
function NETWORK._0x16EFB123C4451032(p0, gamerHandle) end

---@param p0 integer
---@return string
function NETWORK._0xE79BA3BC265895DA(p0) end

---@param p0 integer
---@param p1 any
---@param p2 integer
---@return any
function NETWORK._0xC0CFFDA87C2C163D(p0, p1, p2) end

---@param p0 integer
---@return any
function NETWORK._0x5ED39DA62BEB1330(p0) end

---@param p0 integer
---@return boolean
function NETWORK.NETWORK_ACCEPT_RS_INVITE(p0) end

---@param p0 integer
---@return boolean
function NETWORK._0x3AA0CDC63696166D(p0) end

---@param p0 any
---@return integer
function NETWORK.NETWORK_REQUEST_JOIN(p0) end

---@param p0 any
---@return integer
function NETWORK._0xE8E633215471BB5D(p0) end

---@param p0 any
---@return boolean
function NETWORK._0xA2837A5E21FB5A58(p0) end

---@param p0 any
---@param p1 any
---@return boolean
function NETWORK._0xE39600E50D608693(p0, p1) end

---@param p0 any
---@return boolean
function NETWORK._0xD7BAD4062074B9C1(p0) end

---@param p0 any
---@return integer
function NETWORK._0xCA58D4FD20D70F24(p0) end

---@param p0 any
---@return boolean
function NETWORK._0xC028B3F52C707C49(p0) end

---@return boolean
function NETWORK.NETWORK_IS_PLATFORM_INVITE_PENDING() end

function NETWORK._0x5B9C6AC118FD4774() end

---@return integer
function NETWORK._NETWORK_GET_PLATFORM_INVITE_ID() end

---@return boolean
function NETWORK.NETWORK_ACTION_PLATFORM_INVITE() end

function NETWORK.NETWORK_CLEAR_PLATFORM_INVITE() end

---@param p0 boolean
function NETWORK._0x603469298A4308AF(p0) end

---@return boolean
function NETWORK._NETWORK_ARE_ONLINE_NOTIFICATIONS_SHOWN_IN_STORY_MODE() end

---@return boolean
function NETWORK.NETWORK_IS_IN_PLATFORM_PARTY() end

---@param gamerHandle1 integer
---@param gamerHandle2 integer
---@return boolean
function NETWORK._NETWORK_ARE_PLAYERS_IN_SAME_PLATFORM_PARTY(gamerHandle1, gamerHandle2) end

---@return boolean
function NETWORK.NETWORK_IS_IN_PLATFORM_PARTY_CHAT() end

---@param nSeed integer
function NETWORK.NETWORK_SEED_RANDOM_NUMBER_GENERATOR(nSeed) end

---@param nMinimum integer
---@param nMaximum integer
---@return integer
function NETWORK.NETWORK_GET_RANDOM_INT_RANGED(nMinimum, nMaximum) end

---@param MaxNumPlayers integer
---@param activeInSinglePlayer boolean
---@param InstanceId integer
function NETWORK.NETWORK_SET_THIS_SCRIPT_IS_NETWORK_SCRIPT(MaxNumPlayers, activeInSinglePlayer, InstanceId) end

---@return boolean
function NETWORK.NETWORK_GET_THIS_SCRIPT_IS_NETWORK_SCRIPT() end

---@return integer
function NETWORK.NETWORK_GET_MAX_NUM_PARTICIPANTS() end

---@return integer
function NETWORK.NETWORK_GET_NUM_PARTICIPANTS() end

---@return integer
function NETWORK.NETWORK_GET_SCRIPT_STATUS() end

---@param Address integer
---@param Size integer
---@param DebugName any
function NETWORK.NETWORK_REGISTER_HOST_BROADCAST_VARIABLES(Address, Size, DebugName) end

---@param p0 integer
---@return integer
---@return integer
function NETWORK._NETWORK_GET_SIZE_OF_HOST_BROADCAST_DATA_STORAGE(p0) end

---@param Address integer
---@param Size integer
---@param DebugName any
function NETWORK.NETWORK_REGISTER_PLAYER_BROADCAST_VARIABLES(Address, Size, DebugName) end

---@param p0 integer
---@return integer
---@return integer
function NETWORK._NETWORK_GET_SIZE_OF_PLAYER_BROADCAST_DATA_STORAGE(p0) end

---@return boolean
function NETWORK.NETWORK_HAS_RECEIVED_HOST_BROADCAST_DATA() end

---@param Participant integer
---@return integer
function NETWORK.NETWORK_GET_PLAYER_INDEX(Participant) end

---@param Plr integer
---@return integer
function NETWORK.NETWORK_GET_PARTICIPANT_INDEX(Plr) end

---@param PedIndex integer
---@return integer
function NETWORK.NETWORK_GET_PLAYER_INDEX_FROM_PED(PedIndex) end

---@return integer
function NETWORK.NETWORK_GET_NUM_CONNECTED_PLAYERS() end

---@param Plr integer
---@return boolean
function NETWORK.NETWORK_IS_PLAYER_CONNECTED(Plr) end

---@return integer
function NETWORK.NETWORK_GET_TOTAL_NUM_PLAYERS() end

---@param Participant integer
---@return boolean
function NETWORK.NETWORK_IS_PARTICIPANT_ACTIVE(Participant) end

---@param Plr integer
---@return boolean
function NETWORK.NETWORK_IS_PLAYER_ACTIVE(Plr) end

---@param Plr integer
---@return boolean
function NETWORK.NETWORK_IS_PLAYER_A_PARTICIPANT(Plr) end

---@return boolean
function NETWORK.NETWORK_IS_HOST_OF_THIS_SCRIPT() end

---@return integer
function NETWORK.NETWORK_GET_HOST_OF_THIS_SCRIPT() end

---@param scriptName any
---@param instanceId integer
---@param p2 integer
---@return integer
function NETWORK.NETWORK_GET_HOST_OF_SCRIPT(scriptName, instanceId, p2) end

---@param threadId integer
---@return integer
function NETWORK.NETWORK_GET_HOST_OF_THREAD(threadId) end

function NETWORK.NETWORK_SET_MISSION_FINISHED() end

---@param scriptName any
---@param instanceId integer
---@param localOnly boolean
---@param p3 integer
---@return boolean
function NETWORK.NETWORK_IS_SCRIPT_ACTIVE(scriptName, instanceId, localOnly, p3) end

---@param scriptHash integer
---@param p1 integer
---@param p2 boolean
---@param p3 integer
---@return boolean
function NETWORK.NETWORK_IS_SCRIPT_ACTIVE_BY_HASH(scriptHash, p1, p2, p3) end

---@param threadId integer
---@return boolean
function NETWORK._NETWORK_IS_THREAD_ACTIVE(threadId) end

---@param threadId integer
---@return integer
function NETWORK._NETWORK_GET_INSTANCE_ID_OF_THREAD(threadId) end

---@param scriptName any
---@param instanceId integer
---@param positionHash integer
---@return integer
function NETWORK.NETWORK_GET_NUM_SCRIPT_PARTICIPANTS(scriptName, instanceId, positionHash) end

---@return integer
function NETWORK.NETWORK_GET_INSTANCE_ID_OF_THIS_SCRIPT() end

---@param Plr integer
---@param scriptName any
---@param instanceId integer
---@return boolean
function NETWORK.NETWORK_IS_PLAYER_A_PARTICIPANT_ON_SCRIPT(Plr, scriptName, instanceId) end

function NETWORK.NETWORK_PREVENT_SCRIPT_HOST_MIGRATION() end

---@param featureId integer
---@return boolean
function NETWORK.NETWORK_IS_FEATURE_SUPPORTED(featureId) end

---@return integer
function NETWORK.PARTICIPANT_ID() end

---@return integer
function NETWORK.PARTICIPANT_ID_TO_INT() end

---@param NetworkId integer
---@param TypeOfWeapon integer
---@return integer
---@return integer
function NETWORK.NETWORK_GET_DESTROYER_OF_NETWORK_ID(NetworkId, TypeOfWeapon) end

---@param ped integer
---@param p1 integer
---@return integer
function NETWORK._0x6CF82A7F65A5AD5F(ped, p1) end

---@param player integer
---@param ped integer
---@param p2 integer
---@return boolean
function NETWORK._0x236321F1178A5446(player, ped, p2) end

---@param playerIndexDamager integer
---@param entityDamaged integer
---@param damageDealt integer
---@return boolean
---@return integer
function NETWORK.NETWORK_GET_ASSISTED_DAMAGE_OF_ENTITY(playerIndexDamager, entityDamaged, damageDealt) end

---@param Plr integer
---@param TypeOfWeapon integer
---@return integer
---@return integer
function NETWORK.NETWORK_GET_ENTITY_KILLER_OF_PLAYER(Plr, TypeOfWeapon) end

---@param PosX number
---@param PosY number
---@param PosZ number
---@param Heading number
---@param p4 integer
---@param p5 boolean
---@param p6 any
---@param p7 boolean
function NETWORK.NETWORK_RESURRECT_LOCAL_PLAYER(PosX, PosY, PosZ, Heading, p4, p5, p6, p7) end

---@param args integer
function NETWORK._NETWORK_RESURRECT_LOCAL_PLAYER_2(args) end

---@param invincibilityTime integer
function NETWORK.NETWORK_SET_LOCAL_PLAYER_INVINCIBLE_TIME(invincibilityTime) end

---@param bSyncLookAt boolean
function NETWORK.NETWORK_SET_LOCAL_PLAYER_SYNC_LOOK_AT(bSyncLookAt) end

---@param EntityIndex integer
---@return boolean
function NETWORK.NETWORK_HAS_ENTITY_BEEN_REGISTERED_WITH_THIS_THREAD(EntityIndex) end

---@param EntityIndex integer
---@return integer
function NETWORK.NETWORK_GET_NETWORK_ID_FROM_ENTITY(EntityIndex) end

---@param NetworkId integer
---@return integer
function NETWORK.NETWORK_GET_ENTITY_FROM_NETWORK_ID(NetworkId) end

---@param entityIndex integer
---@return boolean
function NETWORK.NETWORK_GET_ENTITY_IS_NETWORKED(entityIndex) end

---@param entityIndex integer
function NETWORK.NETWORK_REGISTER_ENTITY_AS_NETWORKED(entityIndex) end

---@param NetworkId integer
---@return boolean
function NETWORK.NETWORK_DOES_NETWORK_ID_EXIST(NetworkId) end

---@param p0 any
---@return any
function NETWORK._0x950ACD8F05B7B9DF(p0) end

---@param NetworkId integer
---@return boolean
function NETWORK.NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(NetworkId) end

---@param NetworkId integer
---@return boolean
function NETWORK.NETWORK_HAS_CONTROL_OF_NETWORK_ID(NetworkId) end

---@param entityIndex integer
---@return boolean
function NETWORK.NETWORK_REQUEST_CONTROL_OF_ENTITY(entityIndex) end

---@param animScene integer
---@return boolean
function NETWORK._NETWORK_REQUEST_CONTROL_OF_ANIM_SCENE(animScene) end

---@param p0 any
---@return boolean
function NETWORK.NETWORK_REQUEST_CONTROL_OF_PICKUP_PLACEMENT(p0) end

---@param entityIndex integer
---@return boolean
function NETWORK.NETWORK_HAS_CONTROL_OF_ENTITY(entityIndex) end

---@param pickupIndex integer
---@return boolean
function NETWORK.NETWORK_HAS_CONTROL_OF_PICKUP(pickupIndex) end

---@param animScene integer
---@return boolean
function NETWORK._NETWORK_HAS_CONTROL_OF_ANIM_SCENE(animScene) end

---@param p0 any
---@return boolean
function NETWORK.NETWORK_HAS_CONTROL_OF_PICKUP_PLACEMENT(p0) end

---@param handle integer
---@return integer
function NETWORK._0xF260AF6F43953316(handle) end

---@param vehID integer
---@return integer
function NETWORK.VEH_TO_NET(vehID) end

---@param pedID integer
---@return integer
function NETWORK.PED_TO_NET(pedID) end

---@param objID integer
---@return integer
function NETWORK.OBJ_TO_NET(objID) end

---@param animScene integer
---@return integer
function NETWORK._ANIM_SCENE_TO_NET(animScene) end

---@param netID integer
---@return integer
function NETWORK.NET_TO_VEH(netID) end

---@param netID integer
---@return integer
function NETWORK.NET_TO_PED(netID) end

---@param netID integer
---@return integer
function NETWORK.NET_TO_OBJ(netID) end

---@param netID integer
---@return integer
function NETWORK.NET_TO_ENT(netID) end

---@param netId integer
---@return integer
function NETWORK._NET_TO_ANIM_SCENE(netId) end

---@param propSet integer
---@return integer
function NETWORK._PROPSET_TO_NET(propSet) end

---@param netId integer
---@return integer
function NETWORK._NET_TO_PROPSET(netId) end

---@param p0 integer
function NETWORK._0x0CC28C08613BA9E5(p0) end

---@param gamerHandle integer
function NETWORK.NETWORK_GET_LOCAL_HANDLE(gamerHandle) end

---@param playerIndex integer
---@param gamerHandle integer
function NETWORK.NETWORK_HANDLE_FROM_PLAYER(playerIndex, gamerHandle) end

---@param playerIndex integer
---@return integer
function NETWORK.NETWORK_HASH_FROM_PLAYER_HANDLE(playerIndex) end

---@param friendIndex integer
---@param gamerHandle integer
function NETWORK.NETWORK_HANDLE_FROM_FRIEND(friendIndex, gamerHandle) end

---@param gamerHandle integer
---@return string
function NETWORK.NETWORK_GET_GAMERTAG_FROM_HANDLE(gamerHandle) end

---@param gamerHandles integer
---@param count integer
---@return integer
function NETWORK.NETWORK_DISPLAYNAMES_FROM_HANDLES_START(gamerHandles, count) end

---@param requestId integer
---@param displayNames any
---@param count integer
---@return integer
function NETWORK.NETWORK_GET_DISPLAYNAMES_FROM_HANDLES(requestId, displayNames, count) end

---@param gamerHandle integer
---@param displayName string
---@return boolean
---@return string
function NETWORK._NETWORK_GET_DISPLAY_NAME_FROM_HANDLE(gamerHandle, displayName) end

---@param gamerHandle1 integer
---@param gamerHandle2 integer
---@return boolean
function NETWORK.NETWORK_ARE_HANDLES_THE_SAME(gamerHandle1, gamerHandle2) end

---@param gamerHandle integer
---@return boolean
function NETWORK.NETWORK_IS_HANDLE_VALID(gamerHandle) end

---@param gamerHandle integer
---@return integer
function NETWORK.NETWORK_GET_PLAYER_FROM_GAMER_HANDLE(gamerHandle) end

---@param gamerHandle integer
---@return boolean
function NETWORK.NETWORK_IS_GAMER_IN_MY_SESSION(gamerHandle) end

---@param gamerHandle integer
function NETWORK.NETWORK_SHOW_PROFILE_UI(gamerHandle) end

---@param gamerHandle integer
---@param message any
function NETWORK._0x5759160AC17C13CE(gamerHandle, message) end

---@param entity integer
---@return integer
function NETWORK._0xF302AB9D978352EE(entity) end

---@param networkId integer
---@return integer
function NETWORK._0x4538EE7C321590BC(networkId) end

---@return boolean
function NETWORK._0xA47D48D06AA5A188() end

---@return integer
function NETWORK.NETWORK_GET_TOTAL_NUM_FRIENDS() end

---@return integer
function NETWORK._0xA94ECE191D90637A() end

---@param p0 any
function NETWORK._0x5CB8B0C846D0F30B(p0) end

---@param p0 any
function NETWORK._0xFF36F36B07E69059(p0) end

---@param p0 integer
---@return boolean
function NETWORK._NETWORK_GET_CURRENT_FRIEND_PAGE_DATA(p0) end

---@return integer
function NETWORK._0xB389289F031F059A() end

---@return boolean
function NETWORK.NETWORK_CAN_REFRESH_FRIEND_PAGE() end

---@return boolean
function NETWORK.NETWORK_REFRESH_CURRENT_FRIEND_PAGE() end

---@return boolean
function NETWORK._0xDA1BFED8582F61F0() end

---@return boolean
function NETWORK._0x232E1EB23CDB313C() end

---@return boolean
function NETWORK._0x3E4A16BC669E71B3() end

---@param gamerHandle integer
---@return boolean
function NETWORK._NETWORK_IS_FRIEND_HANDLE_ONLINE(gamerHandle) end

---@param gamerHandle integer
---@return boolean
function NETWORK._NETWORK_IS_FRIEND_HANDLE_IN_SAME_TITLE(gamerHandle) end

---@param gamerHandle integer
---@return string
function NETWORK._NETWORK_GET_GAMERTAG_FROM_FRIEND(gamerHandle) end

---@param gamerHandle integer
---@return boolean
function NETWORK.NETWORK_IS_FRIEND(gamerHandle) end

---@param gamerHandle integer
---@return boolean
function NETWORK.NETWORK_IS_PENDING_FRIEND(gamerHandle) end

---@param gamerHandle integer
---@param message any
---@return boolean
function NETWORK.NETWORK_ADD_FRIEND(gamerHandle, message) end

---@param gamerHandle integer
---@return boolean
function NETWORK._NETWORK_REMOVE_FRIEND(gamerHandle) end

---@param gamerHandle integer
---@return boolean
function NETWORK._NETWORK_CAN_ADD_FRIEND(gamerHandle) end

---@param toggle boolean
function NETWORK.NETWORK_SET_PLAYER_IS_PASSIVE(toggle) end

---@param friendlyFire boolean
function NETWORK.NETWORK_SET_FRIENDLY_FIRE_OPTION(friendlyFire) end

---@param id integer
---@param data integer
---@param sizeOfData integer
---@param numFields integer
function NETWORK.NETWORK_SET_RICH_PRESENCE(id, data, sizeOfData, numFields) end

---@return integer
function NETWORK.NETWORK_GET_TIMEOUT_TIME() end

---@param p0 boolean
function NETWORK._0xBC7D36946D19E60E(p0) end

---@param p0 integer
---@param p1 integer
---@param x number
---@param y number
---@param z number
---@param p5 number
---@param p6 any
---@return boolean
function NETWORK._0x880A7202301E282B(p0, p1, x, y, z, p5, p6) end

---@return any
function NETWORK._0xC964FCD3D1720697() end

---@return any
function NETWORK._0xEC089F84A9C16C62() end

---@param netId integer
function NETWORK.PREVENT_NETWORK_ID_MIGRATION(netId) end

---@param netId integer
---@param p1 boolean
---@param p2 integer
function NETWORK.KEEP_NETWORK_ID_IN_FAST_INSTANCE(netId, p1, p2) end

---@param player integer
---@param p1 any
function NETWORK._0x02C4C6C2900D84DF(player, p1) end

---@param player integer
function NETWORK._0xD78A26024BB13E08(player) end

---@param NetworkId integer
---@param ExistsOnAll boolean
function NETWORK.SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(NetworkId, ExistsOnAll) end

---@param NetworkId integer
---@param PlayerId integer
---@param AlwaysExistsForPlayer boolean
function NETWORK.SET_NETWORK_ID_ALWAYS_EXISTS_FOR_PLAYER(NetworkId, PlayerId, AlwaysExistsForPlayer) end

---@param networkId integer
---@param bStopCloning boolean
function NETWORK.SET_NETWORK_ID_STOP_CLONING(networkId, bStopCloning) end

---@param entity integer
---@param toggle boolean
function NETWORK.NETWORK_SET_ENTITY_REMAINS_WHEN_UNNETWORKED(entity, toggle) end

---@param EntityIndex integer
---@param Exists boolean
function NETWORK.NETWORK_SET_ENTITY_ONLY_EXISTS_FOR_PARTICIPANTS(EntityIndex, Exists) end

---@param entity integer
function NETWORK._0xE31A04513237DC89(entity) end

---@param NetworkId integer
---@param Visible boolean
---@param RemotelyVisible boolean
---@param p3 any
function NETWORK.SET_NETWORK_ID_VISIBLE_IN_CUTSCENE(NetworkId, Visible, RemotelyVisible, p3) end

---@param NetworkId integer
---@return boolean
function NETWORK.IS_NETWORK_ID_OWNED_BY_PARTICIPANT(NetworkId) end

---@param netId integer
---@return integer
function NETWORK._NETWORK_GET_PLAYER_OWNER_OF_NETWORK_ID(netId) end

---@param LocallyVisible boolean
---@param RemotelyVisible boolean
---@param instanceId integer
function NETWORK.SET_LOCAL_PLAYER_VISIBLE_IN_CUTSCENE(LocallyVisible, RemotelyVisible, instanceId) end

---@param toggle boolean
function NETWORK.PREVENT_MIGRATION_OF_ENTITIES_IN_FAST_INSTANCE_FOR_LOCAL_PLAYER(toggle) end

---@param bIncludePlayersVehicle boolean
function NETWORK.SET_LOCAL_PLAYER_INVISIBLE_LOCALLY(bIncludePlayersVehicle) end

---@param PlayerId integer
---@param bIncludePlayersVehicle boolean
function NETWORK.SET_PLAYER_INVISIBLE_LOCALLY(PlayerId, bIncludePlayersVehicle) end

---@param PlayerId integer
---@param bIncludePlayersVehicle boolean
function NETWORK.SET_PLAYER_VISIBLE_LOCALLY(PlayerId, bIncludePlayersVehicle) end

---@param EntityIndex integer
---@param Visible boolean
---@param RemotelyVisible boolean
---@param p3 integer
function NETWORK.SET_ENTITY_VISIBLE_IN_CUTSCENE(EntityIndex, Visible, RemotelyVisible, p3) end

---@param doorHash integer
function NETWORK._SET_DOOR_NETWORKED(doorHash) end

---@param p0 any
---@param toggle boolean
function NETWORK._SET_DOOR_UNNETWORKED(p0, toggle) end

---@param NetworkId integer
---@return boolean
function NETWORK.IS_DAMAGE_TRACKER_ACTIVE_ON_NETWORK_ID(NetworkId) end

---@param NetworkId integer
---@param ActivateTracker boolean
function NETWORK.ACTIVATE_DAMAGE_TRACKER_ON_NETWORK_ID(NetworkId, ActivateTracker) end

---@param PosX number
---@param PosY number
---@param PosZ number
---@param minRadius number
---@param maxRadius number
---@return boolean
function NETWORK.IS_SPHERE_VISIBLE_TO_ANOTHER_MACHINE(PosX, PosY, PosZ, minRadius, maxRadius) end

---@param PlayerId integer
---@param PosX number
---@param PosY number
---@param PosZ number
---@param minRadius number
---@param maxRadius number
---@return boolean
function NETWORK.IS_SPHERE_VISIBLE_TO_PLAYER(PlayerId, PosX, PosY, PosZ, minRadius, maxRadius) end

---@param p0 boolean
function NETWORK._0xD42C543F73233041(p0) end

---@param NumObjectsToReserve integer
function NETWORK.RESERVE_NETWORK_MISSION_OBJECTS(NumObjectsToReserve) end

---@param amount integer
function NETWORK.RESERVE_NETWORK_CLIENT_MISSION_OBJECTS(amount) end

---@param NumPedsToReserve integer
function NETWORK.RESERVE_NETWORK_MISSION_PEDS(NumPedsToReserve) end

---@param amount integer
function NETWORK.RESERVE_NETWORK_CLIENT_MISSION_PEDS(amount) end

---@param NumVehiclesToReserve integer
function NETWORK.RESERVE_NETWORK_MISSION_VEHICLES(NumVehiclesToReserve) end

---@param amount integer
function NETWORK.RESERVE_NETWORK_MISSION_PICKUPS(amount) end

---@param NumObjectsToRegister integer
---@return boolean
function NETWORK.CAN_REGISTER_MISSION_OBJECTS(NumObjectsToRegister) end

---@param NumPedsToRegister integer
---@return boolean
function NETWORK.CAN_REGISTER_MISSION_PEDS(NumPedsToRegister) end

---@param NumVehiclesToRegister integer
---@return boolean
function NETWORK.CAN_REGISTER_MISSION_VEHICLES(NumVehiclesToRegister) end

---@param amount integer
---@return boolean
function NETWORK.CAN_REGISTER_MISSION_PICKUPS(amount) end

---@param NumPedsToRegister integer
---@param NumVehiclesToRegister integer
---@param NumObjectsToRegister integer
---@param NumPickupsToRegister integer
---@return boolean
function NETWORK.CAN_REGISTER_MISSION_ENTITIES(NumPedsToRegister, NumVehiclesToRegister, NumObjectsToRegister, NumPickupsToRegister) end

---@param bForAllScripts boolean
---@return integer
function NETWORK.GET_NUM_RESERVED_MISSION_OBJECTS(bForAllScripts) end

---@param bForAllScripts boolean
---@return integer
function NETWORK.GET_NUM_RESERVED_MISSION_PEDS(bForAllScripts) end

---@param bForAllScripts boolean
---@return integer
function NETWORK.GET_NUM_RESERVED_MISSION_VEHICLES(bForAllScripts) end

---@param p0 boolean
---@return integer
function NETWORK._GET_NUM_RESERVED_MISSION_PICKUPS(p0) end

---@param bForAllScripts boolean
---@return integer
function NETWORK.GET_NUM_CREATED_MISSION_OBJECTS(bForAllScripts) end

---@param bForAllScripts boolean
---@return integer
function NETWORK.GET_NUM_CREATED_MISSION_PEDS(bForAllScripts) end

---@param bForAllScripts boolean
---@return integer
function NETWORK.GET_NUM_CREATED_MISSION_VEHICLES(bForAllScripts) end

---@param p0 boolean
---@return integer
function NETWORK._GET_NUM_CREATED_MISSION_PICKUPS(p0) end

---@param threadId integer
---@param pedMax integer
---@param vehicleMax integer
---@param unkMax integer
---@param pedMin integer
---@param vehicleMin integer
---@param unkMin integer
---@return integer
---@return integer
---@return integer
---@return integer
---@return integer
---@return integer
function NETWORK._GET_RESERVED_MISSION_ENTITIES_FOR_THREAD(threadId, pedMax, vehicleMax, unkMax, pedMin, vehicleMin, unkMin) end

---@param locationX number
---@param locationY number
---@param locationZ number
---@param includeLocalScripts boolean
---@param numReservedPeds integer
---@param numReservedVehicles integer
---@param numReservedObjects integer
---@param numReservedPickups integer
---@return integer
---@return integer
---@return integer
---@return integer
function NETWORK.GET_RESERVED_MISSION_ENTITIES_IN_AREA(locationX, locationY, locationZ, includeLocalScripts, numReservedPeds, numReservedVehicles, numReservedObjects, numReservedPickups) end

---@param p0 integer
---@param p1 integer
---@param p2 integer
---@param p3 integer
---@return boolean
function NETWORK._0x5F328FC909F0E0FF(p0, p1, p2, p3) end

---@return integer
function NETWORK.GET_MAX_NUM_NETWORK_OBJECTS() end

---@return integer
function NETWORK.GET_MAX_NUM_NETWORK_PEDS() end

---@return integer
function NETWORK.GET_MAX_NUM_NETWORK_VEHICLES() end

---@return integer
function NETWORK.GET_MAX_NUM_NETWORK_PICKUPS() end

---@param entity integer
---@param player integer
---@param p2 integer
---@return boolean
function NETWORK._0x75FC34A2BA345BD1(entity, player, p2) end

---@param entity integer
---@param p1 boolean
function NETWORK._0x979765465A6F25FC(entity, p1) end

---@return integer
function NETWORK._0x5133CF81924F1129() end

---@param p0 boolean
---@return integer
function NETWORK._0x1E4E097D71D449FB(p0) end

---@param p0 boolean
---@return integer
function NETWORK._0x982D7AD755B8F62C(p0) end

---@param p0 boolean
---@return integer
function NETWORK._0x917AD74BDCF8B6E9(p0) end

---@param p0 boolean
---@return integer
function NETWORK._0xF8DC69DC1AD19072(p0) end

---@param p0 boolean
---@return integer
function NETWORK._0x744BFBB0CA908161(p0) end

---@param p0 boolean
---@return integer
function NETWORK._0x106CBDD5077DEDE1(p0) end

---@param p0 boolean
---@return integer
function NETWORK._0xBAF7E2979442B29F(p0) end

---@param p0 boolean
---@return integer
function NETWORK._0x039B692B3318FAB6(p0) end

---@param p0 boolean
---@return integer
function NETWORK._0x4835413EA6F9C9CD(p0) end

---@return integer
function NETWORK.GET_NETWORK_TIME() end

---@return integer
function NETWORK.GET_NETWORK_TIME_ACCURATE() end

---@return boolean
function NETWORK.HAS_NETWORK_TIME_STARTED() end

---@param Time1 integer
---@param Offset integer
---@return integer
function NETWORK.GET_TIME_OFFSET(Time1, Offset) end

---@param Time1 integer
---@param Time2 integer
---@return boolean
function NETWORK.IS_TIME_LESS_THAN(Time1, Time2) end

---@param Time1 integer
---@param Time2 integer
---@return boolean
function NETWORK.IS_TIME_MORE_THAN(Time1, Time2) end

---@param Time1 integer
---@param Time2 integer
---@return integer
function NETWORK.GET_TIME_DIFFERENCE(Time1, Time2) end

---@return integer
function NETWORK.GET_CLOUD_TIME_AS_INT() end

---@param nContentIndex integer
---@param sDate integer
function NETWORK.CONVERT_POSIX_TIME(nContentIndex, sDate) end

---@param InSpectatorMode boolean
---@param playerIndex integer
function NETWORK.NETWORK_SET_IN_SPECTATOR_MODE(InSpectatorMode, playerIndex) end

---@param toggle boolean
---@param x number
---@param y number
---@param z number
function NETWORK._NETWORK_SET_IN_STATIC_SPECTATOR_MODE(toggle, x, y, z) end

---@return boolean
function NETWORK.NETWORK_IS_IN_SPECTATOR_MODE() end

---@param player integer
---@return boolean
function NETWORK._NETWORK_IS_PLAYER_IN_SPECTATOR_MODE(player) end

---@param p0 boolean
---@param p1 boolean
---@param p2 integer
---@param p3 boolean
function NETWORK.NETWORK_SET_IN_MP_CUTSCENE(p0, p1, p2, p3) end

---@return boolean
function NETWORK.NETWORK_IS_IN_MP_CUTSCENE() end

---@param playerIndex integer
---@return boolean
function NETWORK.NETWORK_IS_PLAYER_IN_MP_CUTSCENE(playerIndex) end

---@param p0 boolean
function NETWORK._0x34BC1E79546BA543(p0) end

---@param entity integer
---@param timer integer
---@param p2 boolean
function NETWORK._SET_NETWORK_RESPOT_TIMER(entity, timer, p2) end

---@param entity integer
---@return boolean
function NETWORK._0x26A867C0B7A456D1(entity) end

---@param bSet boolean
function NETWORK.SET_LOCAL_PLAYER_AS_GHOST(bSet) end

---@param EntityIndex integer
---@return boolean
function NETWORK.IS_ENTITY_A_GHOST(EntityIndex) end

---@param player integer
---@param disabled boolean
function NETWORK._SET_PLAYER_VISIBILITY_TO_LOCAL_PLAYER_DISABLED(player, disabled) end

---@param entity integer
---@param toggle boolean
function NETWORK._SET_ENTITY_GHOSTED_TO_LOCAL_PLAYER(entity, toggle) end

---@return boolean
function NETWORK.IS_OBJECT_REASSIGNMENT_IN_PROGRESS() end

---@return integer
function NETWORK._0x039AD6B57D5179FF() end

---@return integer
function NETWORK._0x02B3CDD652B3CDD6() end

---@return integer
function NETWORK._GET_NUM_PEER_NEGOTIATION_RESPONSES() end

---@param p0 integer
function NETWORK._NETWORK_DEBUG_REQUEST_ENTITY_POSITION(p0) end

---@param ropeId integer
---@return integer
function NETWORK.NETWORK_GET_NETWORK_ID_FROM_ROPE_ID(ropeId) end

---@param netId integer
---@return integer
function NETWORK.NETWORK_GET_ROPE_ID_FROM_NETWORK_ID(netId) end

---@param x number
---@param y number
---@param z number
---@param heading number
function NETWORK._NETWORK_SPAWN_CONFIG_ADD_SPAWN_POINT(x, y, z, heading) end

function NETWORK._0xA63E4F050F20021F() end

---@param volume integer
function NETWORK._NETWORK_SPAWN_CONFIG_ADD_EXCLUSION_VOLUME(volume) end

---@param volume integer
function NETWORK._NETWORK_SPAWN_CONFIG_REMOVE_EXCLUSION_VOLUME(volume) end

function NETWORK._0x0BF90CBB6B72977B() end

---@param player integer
function NETWORK._0x7B3FF2D193628126(player) end

function NETWORK._0x19B52C20B5C4757C() end

---@param flags integer
function NETWORK.NETWORK_SPAWN_CONFIG_SET_FLAGS(flags) end

function NETWORK._0x6CEE2E30021DAEC6() end

---@param configProperty integer
---@param include boolean
function NETWORK._NETWORK_SPAWN_CONFIG_ADD_PROPERTY_SCRIPTED(configProperty, include) end

function NETWORK._0xB131E686BD97B3F8() end

---@param configProperty integer
---@param include boolean
---@param weight number
function NETWORK._NETWORK_SPAWN_CONFIG_ADD_PROPERTY_PREFERENCE(configProperty, include, weight) end

---@param volume integer
---@param p1 boolean
---@param p2 any
---@param p3 any
function NETWORK._0x405DDEFB1F531B18(volume, p1, p2, p3) end

function NETWORK._0x43CF999205084B4B() end

---@param volume integer
---@param p1 boolean
---@param originalWeight number
---@param p3 any
---@param p4 any
function NETWORK._0x13F592FC3BF0EA84(volume, p1, originalWeight, p3, p4) end

---@param p0 any
function NETWORK._0xCF23AB5BD47B384D(p0) end

---@param p0 number
function NETWORK._0xE5634491A58C2703(p0) end

---@param offset number
function NETWORK.NETWORK_SPAWN_CONFIG_SET_GROUND_TO_ROOT_OFFSET(offset) end

---@param waterDepthLevel integer
function NETWORK._NETWORK_SPAWN_CONFIG_SET_LEVEL_WATER_DEPTH(waterDepthLevel) end

---@param p0 integer
---@param p1 number
function NETWORK.NETWORK_SPAWN_CONFIG_SET_TUNING_FLOAT(p0, p1) end

---@param nsctf integer
function NETWORK._0x5D3C528B7A7DF836(nsctf) end

---@param x number
---@param y number
---@param z number
function NETWORK._0x2686BD9566B65EDA(x, y, z) end

---@param entity integer
function NETWORK._0xBB1EC8C2EEF33BAA(entity) end

---@return boolean
function NETWORK._0x67CCDF74C4DF7169() end

function NETWORK._0xC8B6D18E22484643() end

function NETWORK._0x97BCE4C4B3191228() end

---@return integer
function NETWORK._0x41452E8A3B9C0C4B() end

---@return boolean
function NETWORK._NETWORK_SPAWN_CONFIG_SEARCH_IN_PROGRESS() end

function NETWORK._0x61BFBAA795E712AD() end

function NETWORK._NETWORK_SPAWN_CONFIG_SET_CANCEL_SEARCH() end

---@param p0 any
---@param p1 integer
function NETWORK._0x691E4DE5309EAEFC(p0, p1) end

function NETWORK.NETWORK_START_SOLO_TUTORIAL_SESSION() end

function NETWORK.NETWORK_END_TUTORIAL_SESSION() end

---@return boolean
function NETWORK.NETWORK_IS_IN_TUTORIAL_SESSION() end

---@return boolean
function NETWORK.NETWORK_IS_TUTORIAL_SESSION_CHANGE_PENDING() end

---@param FirstPlayerIndex integer
---@param SecondPlayerIndex integer
---@return boolean
function NETWORK.NETWORK_ARE_PLAYERS_IN_SAME_TUTORIAL_SESSION(FirstPlayerIndex, SecondPlayerIndex) end

---@param toggle boolean
function NETWORK.NETWORK_ALLOW_ALL_ENTITY_FADING_FOR_INSTANCES(toggle) end

---@param entity integer
---@param toggle boolean
function NETWORK.NETWORK_ALLOW_ENTITY_FADING_FOR_INSTANCES(entity, toggle) end

---@param p0 boolean
---@param p1 boolean
function NETWORK._0xDC6AD5C046F33AB4(p0, p1) end

function NETWORK._0x6C7E04E9DE451789() end

---@param instanceId integer
function NETWORK.NETWORK_SET_LOCAL_PLAYER_PENDING_FAST_INSTANCE_ID(instanceId) end

---@param player integer
---@return integer
function NETWORK._NETWORK_GET_PLAYER_FAST_INSTANCE_ID(player) end

---@param PlayerIndex integer
---@param Conceal boolean
function NETWORK.NETWORK_CONCEAL_PLAYER(PlayerIndex, Conceal) end

---@param PlayerIndex integer
---@return boolean
function NETWORK.NETWORK_IS_PLAYER_CONCEALED(PlayerIndex) end

function NETWORK._0x40FEDB13870042F1() end

---@param p0 integer
function NETWORK._0x422F9D6D6C7BC290(p0) end

function NETWORK.NETWORK_REQUEST_CLOUD_TUNABLES() end

---@return boolean
function NETWORK.NETWORK_IS_TUNABLE_CLOUD_REQUEST_PENDING() end

---@return integer
function NETWORK.NETWORK_GET_TUNABLE_CLOUD_CRC() end

---@param tunableContext integer
---@param tunableName integer
---@return boolean
function NETWORK.NETWORK_DOES_TUNABLE_EXIST(tunableContext, tunableName) end

---@param tunableContext integer
---@param tunableName integer
---@param value integer
---@return boolean
---@return integer
function NETWORK.NETWORK_ACCESS_TUNABLE_INT(tunableContext, tunableName, value) end

---@param tunableContext integer
---@param tunableName integer
---@return boolean
function NETWORK.NETWORK_ACCESS_TUNABLE_BOOL(tunableContext, tunableName) end

---@param tunableContext integer
---@param tunableName integer
---@param defaultValue integer
---@return integer
function NETWORK.NETWORK_TRY_ACCESS_TUNABLE_INT_HASH(tunableContext, tunableName, defaultValue) end

---@param tunableContext integer
---@param tunableName integer
---@param defaultValue number
---@return number
function NETWORK.NETWORK_TRY_ACCESS_TUNABLE_FLOAT_HASH(tunableContext, tunableName, defaultValue) end

---@param tunableContext integer
---@param tunableName integer
---@param defaultValue boolean
---@return boolean
function NETWORK.NETWORK_TRY_ACCESS_TUNABLE_BOOL_HASH(tunableContext, tunableName, defaultValue) end

---@param netHandle integer
---@param p1 any
function NETWORK._0x894B5ECAB45D2342(netHandle, p1) end

---@param NetworkId integer
function NETWORK.NETWORK_DISABLE_PROXIMITY_MIGRATION(NetworkId) end

---@return boolean
function NETWORK._COMMERCE_STORE_IS_OPEN() end

---@return boolean
function NETWORK._COMMERCE_STORE_IS_ENABLED() end

---@param nRequestID integer
---@return boolean
function NETWORK.CLOUD_HAS_REQUEST_COMPLETED(nRequestID) end

---@param nRequestID integer
---@return boolean
function NETWORK.CLOUD_DID_REQUEST_SUCCEED(nRequestID) end

---@param paramName any
---@return boolean
function NETWORK._GET_LAUNCH_PARAM_EXISTS(paramName) end

---@param paramName any
---@return string
function NETWORK.GET_LAUNCH_PARAM_VALUE(paramName) end

---@param paramName any
---@param value any
function NETWORK._SET_LAUNCH_PARAM_VALUE(paramName, value) end

---@param paramName any
function NETWORK._CLEAR_LAUNCH_PARAM(paramName) end

---@return string
function NETWORK._GET_LAUNCH_PARAM_STRING() end

---@param params any
function NETWORK._SET_LAUNCH_PARAM_STRING(params) end

function NETWORK.CLEAR_SERVICE_EVENT_ARGUMENTS() end

---@param ugcRequestId integer
---@return boolean
function NETWORK.UGC_IS_REQUEST_PENDING(ugcRequestId) end

---@param ugcRequestId integer
---@return boolean
function NETWORK.UGC_HAS_REQUEST_FINISHED(ugcRequestId) end

---@param ugcRequestId integer
---@return boolean
function NETWORK.UGC_DID_REQUEST_SUCCEED(ugcRequestId) end

---@param ugcRequestId integer
---@return boolean
function NETWORK._0xCD53E6CBF609C012(ugcRequestId) end

---@param p0 integer
---@param maxGet integer
---@param contentTypeName any
---@param p3 integer
---@param p4 integer
---@param p5 integer
---@return integer
function NETWORK._UGC_QUERY_BY_CONTENT_TYPE(p0, maxGet, contentTypeName, p3, p4, p5) end

---@param categoryType integer
---@param p1 integer
---@param maxGet integer
---@param contentTypeName any
---@param p4 integer
---@param p5 boolean
---@return integer
function NETWORK._UGC_QUERY_BY_CATEGORY(categoryType, p1, maxGet, contentTypeName, p4, p5) end

---@param contentId any
---@param latestVersion boolean
---@param contentTypeName any
---@return integer
function NETWORK._UGC_QUERY_BY_CONTENT_ID(contentId, latestVersion, contentTypeName) end

---@param contentId any
---@return boolean
function NETWORK._UGC_IS_BOOK_MARKED(contentId) end

---@param ugcRequestId integer
function NETWORK.UGC_CLEAR_QUERY_RESULTS(ugcRequestId) end

---@param ugcRequestId integer
---@return boolean
function NETWORK.UGC_QUERY_WAS_FORCE_CANCELLED(ugcRequestId) end

---@param ugcRequestId integer
---@return integer
function NETWORK.UGC_QUERY_GET_CONTENT_NUM(ugcRequestId) end

---@param p0 any
---@param index integer
---@param gamerHandle integer
---@return any
function NETWORK._UGC_QUERY_GET_CREATOR_HANDLE(p0, index, gamerHandle) end

---@param p0 any
---@param index integer
---@return string
function NETWORK._UGC_QUERY_GET_OWNER_ID(p0, index) end

---@param p0 any
---@param index integer
---@return string
function NETWORK._UGC_QUERY_GET_NAME(p0, index) end

---@param p0 any
---@param index integer
---@return string
function NETWORK._UGC_QUERY_GET_ROOT_CONTENT_ID(p0, index) end

---@param p0 any
---@param index integer
---@return string
function NETWORK._UGC_QUERY_GET_PLAYLIST_NAME(p0, index) end

---@param p0 any
---@param index integer
---@return integer
function NETWORK._UGC_QUERY_GET_MISSION_DESC_HASH(p0, index) end

---@param p0 any
---@param p1 integer
---@param p2 any
---@return string
function NETWORK._UGC_QUERY_GET_CREATOR_PHOTO(p0, p1, p2) end

---@param p0 any
---@param index integer
---@param p2 integer
function NETWORK._UGC_QUERY_GET_DATE(p0, index, p2) end

---@param p0 any
---@param p1 any
---@return integer
function NETWORK._UGC_QUERY_GET_POSIX_UPDATED_DATE(p0, p1) end

---@param p0 any
---@param p1 any
---@return integer
function NETWORK._UGC_QUERY_GET_POSIX_PUBLISHED_DATE(p0, p1) end

---@param p0 any
---@param index integer
---@param p2 integer
---@return integer
function NETWORK._UGC_QUERY_GET_VERSION(p0, index, p2) end

---@param p0 any
---@param index integer
---@return integer
function NETWORK._UGC_QUERY_GET_LANGUAGE(p0, index) end

---@param p0 any
---@param p1 any
---@return boolean
function NETWORK._UGC_QUERY_GET_PUBLISHED(p0, p1) end

---@param p0 any
---@param index integer
---@param p2 integer
---@return number
function NETWORK._UGC_QUERY_GET_RATING(p0, index, p2) end

---@param p0 any
---@param index integer
---@param p2 integer
---@return any
function NETWORK._0x5F0E99071582DECA(p0, index, p2) end

---@param p0 any
---@param index integer
---@return boolean
function NETWORK.UGC_QUERY_GET_CONTENT_HAS_PLAYER_RECORD(p0, index) end

---@param p0 any
---@param index integer
---@return boolean
function NETWORK._UGC_QUERY_GET_BOOK_MARKED(p0, index) end

---@return boolean
function NETWORK._UGC_HAS_PRIVILEGE() end

---@param szContentType any
---@param szContentID any
---@param nFileID integer
---@param nFileVersion integer
---@param nLanguage integer
---@return integer
function NETWORK.UGC_REQUEST_CONTENT_DATA_FROM_PARAMS(szContentType, szContentID, nFileID, nFileVersion, nLanguage) end

---@param nHash integer
---@return integer
function NETWORK.UGC_REQUEST_CACHED_DESCRIPTION(nHash) end

---@param nHash integer
---@return boolean
function NETWORK.UGC_IS_DESCRIPTION_REQUEST_IN_PROGRESS(nHash) end

---@param nHash integer
---@return boolean
function NETWORK.UGC_HAS_DESCRIPTION_REQUEST_FINISHED(nHash) end

---@param nHash integer
---@return boolean
function NETWORK.UGC_DID_DESCRIPTION_REQUEST_SUCCEED(nHash) end

---@param nHash integer
---@param nMaxLength integer
---@return string
function NETWORK.UGC_GET_CACHED_DESCRIPTION(nHash, nMaxLength) end

---@param nHash integer
---@return boolean
function NETWORK.UGC_RELEASE_CACHED_DESCRIPTION(nHash) end

function NETWORK.UGC_RELEASE_ALL_CACHED_DESCRIPTIONS() end

---@param bFromOffline boolean
function NETWORK.UGC_SET_QUERY_DATA_FROM_OFFLINE(bFromOffline) end

---@param nLanguage integer
---@return boolean
function NETWORK.UGC_IS_LANGUAGE_SUPPORTED(nLanguage) end

---@param p0 any
---@param p1 integer
---@param p2 integer
---@return any
function NETWORK._0xD4022C7286B0DFA2(p0, p1, p2) end

---@param texture any
---@param personaPhotoType integer
---@param formatIndex integer
---@return boolean
function NETWORK._NETWORK_PERSONA_PHOTO_WRITE_SC_PROFILE(texture, personaPhotoType, formatIndex) end

---@param texture any
---@param playerSlot integer
---@param p2 integer
---@param personaPhotoLocalCacheType integer
---@return boolean
function NETWORK._NETWORK_PERSONA_PHOTO_WRITE_LOCAL(texture, playerSlot, p2, personaPhotoLocalCacheType) end

---@return boolean
function NETWORK._NETWORK_IS_PREVIOUS_UPLOAD_PENDING() end

---@return any
function NETWORK._0xCC4E72C339461ED1() end

---@param player integer
---@param personaPhotoLocalCacheType integer
---@return string
function NETWORK._REQUEST_PEDSHOT_TEXTURE_LOCAL_BACKUP_DOWNLOAD(player, personaPhotoLocalCacheType) end

---@param gamerHandle integer
---@param p1 integer
---@return string
function NETWORK._REQUEST_PEDSHOT_TEXTURE_LOCAL_DOWNLOAD(gamerHandle, p1) end

---@param gamerHandle integer
---@param p1 integer
---@return string
function NETWORK._REQUEST_PEDSHOT_TEXTURE_MULTIPLAYER_DOWNLOAD(gamerHandle, p1) end

---@param name any
---@return boolean
function NETWORK._TEXTURE_DOWNLOAD_TEXTURE_NAME_IS_VALID(name) end

---@param gamerHandle integer
---@param cloudPath any
---@param textureName any
---@param useCacheWithoutCloudChecks boolean
---@return integer
function NETWORK.TEXTURE_DOWNLOAD_REQUEST(gamerHandle, cloudPath, textureName, useCacheWithoutCloudChecks) end

---@param gamerHandle integer
---@param p1 integer
---@param name any
---@param p3 boolean
---@return integer
function NETWORK._MUGSHOT_TEXTURE_DOWNLOAD_REQUEST(gamerHandle, p1, name, p3) end

---@param contentID any
---@param nFileID integer
---@param nFileVersion integer
---@param nLanguage integer
---@param textureName any
---@param useCacheWithoutCloudChecks boolean
---@return integer
function NETWORK.UGC_TEXTURE_DOWNLOAD_REQUEST(contentID, nFileID, nFileVersion, nLanguage, textureName, useCacheWithoutCloudChecks) end

---@param playerSlot integer
---@param personaPhotoLocalCacheType integer
---@return integer
function NETWORK._LOCAL_PLAYER_PEDSHOT_TEXTURE_DOWNLOAD_REQUEST(playerSlot, personaPhotoLocalCacheType) end

---@param textureDownloadHandle integer
function NETWORK.TEXTURE_DOWNLOAD_RELEASE(textureDownloadHandle) end

---@param name any
function NETWORK._TEXTURE_DOWNLOAD_RELEASE_BY_NAME(name) end

---@param textureDownloadHandle integer
---@return string
function NETWORK.TEXTURE_DOWNLOAD_GET_NAME(textureDownloadHandle) end

---@param textureDownloadHandle integer
---@return integer
function NETWORK.GET_STATUS_OF_TEXTURE_DOWNLOAD(textureDownloadHandle) end

---@return integer
function NETWORK._PEDMUGSHOT_GET_STATUS() end

---@return boolean
function NETWORK._PEDMUGSHOT_TAKE() end

---@return any
function NETWORK._PEDMUGSHOT_REQUEST_SEND() end

function NETWORK._0x814729078AED6D30() end

---@return boolean
function NETWORK.NETWORK_HAVE_ROS_BANNED_PRIV() end

---@param privilegeId integer
---@return boolean
function NETWORK.NETWORK_HAS_ROS_PRIVILEGE(privilegeId) end

---@param hGamer integer
---@return integer
function NETWORK.NETWORK_START_USER_CONTENT_PERMISSIONS_CHECK(hGamer) end

---@param toggle boolean
function NETWORK._NETWORK_AUTO_SESSION_SET_ALLOWED_TO_SPLIT(toggle) end

---@return boolean
function NETWORK.NETWORK_AUTO_SESSION_IS_ALLOWED_TO_MERGE() end

---@param toggle boolean
---@param p1 integer
---@param p2 integer
function NETWORK._NETWORK_AUTO_SESSION_SET_ALLOWED_TO_MERGE(toggle, p1, p2) end

---@return boolean
function NETWORK._NETWORK_AUTO_SESSION_IS_AUTO_WARP_DISABLED() end

---@param toggle boolean
function NETWORK._NETWORK_AUTO_SESSION_SET_AUTO_WARP_ENABLED(toggle) end

---@param p0 integer
---@return boolean
---@return integer
function NETWORK.NETWORK_AUTO_SESSION_CAN_SPLIT_SESSION(p0) end

---@param playersToTake integer
---@param maxInstancePlayers integer
---@param sessionFlags integer
---@param bucketId integer
---@return boolean
function NETWORK.NETWORK_AUTO_SESSION_SPLIT_SESSION(playersToTake, maxInstancePlayers, sessionFlags, bucketId) end

---@return boolean
function NETWORK._NETWORK_AUTO_SESSION_IS_PROCESSING_SESSION_SPLIT() end

---@return boolean
function NETWORK._NETWORK_AUTO_SESSION_SPLIT_SESSION_SUCCESSFUL() end

---@return boolean
function NETWORK._NETWORK_AUTO_SESSION_IS_INSTANCED_SESSION() end

function NETWORK.NETWORK_AUTO_SESSION_FINISH_INSTANCE() end

function NETWORK._0xFD8112109A96877C() end

---@param player integer
---@param p1 number
function NETWORK._0x5A91BCEF74944E93(player, p1) end

---@return integer
function NETWORK._0xFB3205788F8AFA3F() end

---@param p0 integer
function NETWORK._0x335AF56613CA0F49(p0) end

---@param p0 integer
---@return boolean
function NETWORK._0x9E5A47744C0F0376(p0) end

---@param p0 integer
function NETWORK._0xD3B6EBC6C3D77D44(p0) end

---@param p0 integer
function NETWORK._0xA7670F7991099680(p0) end

function NETWORK._0x7673C0D2C5CDAC55() end

---@param p0 integer
---@param p1 integer
---@param p2 number
function NETWORK._0x3CBD6565D9C3B133(p0, p1, p2) end

---@param p0 integer
---@param p1 integer
function NETWORK._0x0D183D8490EE4366(p0, p1) end

---@param p0 integer
function NETWORK._0xC1968045EEB563B7(p0) end

---@return boolean
function NETWORK.NETWORK_AUTO_SESSION_IS_OBJECT_CREATION_PAUSED() end

---@return boolean
function NETWORK._0x0B6B4507AC5EA8B8() end

---@return boolean
function NETWORK.NETWORK_IS_RESETTING_POPULATION() end

---@param p0 boolean
---@param p1 integer
---@return boolean
function NETWORK.NETWORK_RESET_POPULATION(p0, p1) end

---@param flag boolean
function NETWORK.NETWORK_DISABLE_LEAVE_REMOTE_PED_BEHIND(flag) end

---@param p0 boolean
function NETWORK._0x3034C77C79A58880(p0) end

---@param EntityIndex integer
---@param CanModify boolean
function NETWORK.NETWORK_ALLOW_REMOTE_ATTACHMENT_MODIFICATION(EntityIndex, CanModify) end

---@param localGamerIndex integer
function NETWORK.NETWORK_SHOW_CHAT_RESTRICTION_MSC(localGamerIndex) end

function NETWORK.NETWORK_SHOW_PSN_UGC_RESTRICTION() end

---@param PlayerIndex integer
---@return boolean
function NETWORK.NETWORK_IS_CONNECTED_VIA_RELAY(PlayerIndex) end

---@param PlayerIndex integer
---@return number
function NETWORK.NETWORK_GET_AVERAGE_LATENCY(PlayerIndex) end

---@param PlayerIndex integer
---@return number
function NETWORK.NETWORK_GET_AVERAGE_PING(PlayerIndex) end

---@param PlayerIndex integer
---@return number
function NETWORK.NETWORK_GET_AVERAGE_PACKET_LOSS(PlayerIndex) end

---@param PlayerIndex integer
---@return integer
function NETWORK.NETWORK_GET_NUM_UNACKED_RELIABLES(PlayerIndex) end

---@param PlayerIndex integer
---@return integer
function NETWORK.NETWORK_GET_UNRELIABLE_RESEND_COUNT(PlayerIndex) end

---@param PlayerIndex integer
---@return integer
function NETWORK.NETWORK_GET_HIGHEST_RELIABLE_RESEND_COUNT(PlayerIndex) end

function NETWORK.NETWORK_DUMP_NET_IF_CONFIG() end

function NETWORK.NETWORK_GET_NET_STATISTICS_INFO() end

---@param player integer
---@return boolean
function NETWORK.NETWORK_IS_PLAYER_INDEX_VALID(player) end

---@param player integer
---@return boolean
function NETWORK._GET_PLAYER_WAYPOINT_IS_ACTIVE(player) end

---@param p0 boolean
function NETWORK._0x455156F47DC6B78C(p0) end

---@param player integer
---@param damageMultiplier number
function NETWORK._SET_LOCAL_PLAYER_DAMAGE_MULTIPLIER_FOR_PLAYER(player, damageMultiplier) end

---@param EntityIndex integer
---@param shouldTrigger boolean
function NETWORK.NETWORK_TRIGGER_DAMAGE_EVENT_FOR_ZERO_DAMAGE(EntityIndex, shouldTrigger) end

---@param p0 any
function NETWORK._0x5CD3AAD8FF9ED121(p0) end

---@param player integer
---@param type integer
function NETWORK._0x51951DE06C0D1C40(player, type) end

---@param setting integer
function NETWORK._0xE3AB5EEFCB6671A2(setting) end

function NETWORK._0x9B39B0555CC692B5() end

---@param player1 integer
---@param player2 integer
---@return integer
function NETWORK._0xFE53B1F8D43F19BF(player1, player2) end

---@param player1 integer
---@param player2 integer
---@return boolean
function NETWORK._0x862C5040F4888741(player1, player2) end

function NETWORK._0x2CD41AC000E6F611() end

function NETWORK._0xACC44768AF229042() end

---@param p0 integer
---@param p1 integer
---@param p2 integer
---@param p3 integer
---@param p4 integer
---@param p5 integer
---@param p6 integer
---@param p7 integer
---@param p8 integer
---@param p9 integer
---@param p10 integer
---@param p11 integer
---@param p12 integer
---@param p13 integer
---@param p14 integer
function NETWORK._0x7E300B5B86AB1D1A(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14) end

---@param player integer
---@return integer
function NETWORK.GET_UNIQUE_INT_FOR_PLAYER(player) end

---@param toggle boolean
function NETWORK._0x780A13F780A13F1B(toggle) end

---@param player integer
---@param trackedPlayer integer
---@return boolean
function NETWORK._NETWORK_IS_TRACKED_PLAYER_VISIBLE(player, trackedPlayer) end

---@param player integer
---@return boolean
function NETWORK.NETWORK_IS_AIM_CAM_ACTIVE(player) end

---@param ctx integer
---@param lh integer
---@param ec integer
---@param h integer
function NETWORK._NETWORK_ALERT(ctx, lh, ec, h) end

---@param ctx integer
---@param ec integer
---@param ex boolean
---@param ro boolean
function NETWORK._0x19447FCAE97704DC(ctx, ec, ex, ro) end

---@param p0 any
function NETWORK._0x2C4E98DDA475364F(p0) end

---@param p0 integer
---@param p1 integer
function NETWORK._0x3F0ABAE38A0515AD(p0, p1) end

---@param p0 integer
---@return integer
function NETWORK._0x3F2EE18A3E294801(p0) end

---@param toggle boolean
function NETWORK._SET_SOCIAL_MATCHMAKING_ALLOWED(toggle) end

---@return boolean
function NETWORK._GET_SOCIAL_MATCHMAKING_ALLOWED() end

---@param p0 any
---@return boolean
function NETWORK.NETWORK_AWARD_HAS_REACHED_MAXCLAIM(p0) end

---@param p0 any
---@param p1 any
---@return any
function NETWORK._0x271F95E55C663B8B(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return any
function NETWORK._0x64A36BA85CE01A81(p0, p1, p2, p3) end

---@param p0 any
---@return any
function NETWORK._0xE10F2D7715ABABEC(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function NETWORK._0x7A8E8DF782B47EB0(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function NETWORK._0x77B299E8799B1332(p0, p1, p2) end

---@param p0 any
---@return any
function NETWORK._0x923346025512DFB7(p0) end

---@return integer
function NETWORK._NETWORK_GET_XP() end

---@return integer
function NETWORK._NETWORK_GET_RANK() end

---@param toggle boolean
function NETWORK.NETWORK_SET_RECENT_GAMERS_ENABLED(toggle) end

---@return boolean
function NETWORK._0x273E04A3A7AD1F2D() end

---@param player integer
---@param p1 integer
function NETWORK._NETWORK_ADD_PLAYER_TO_RECENT_GAMERS_LIST(player, p1) end

---@param p0 integer
---@param playerCount integer
---@return boolean
function NETWORK.NETWORK_REQUEST_RECENT_GAMER_NAMES(p0, playerCount) end

---@return boolean
function NETWORK._NETWORK_IS_RECENT_GAMER_NAMES_REQUEST_IN_PROGRESS() end

---@return boolean
function NETWORK._NETWORK_DID_RECENT_GAMER_NAMES_REQUEST_SUCCEED() end

---@return integer
function NETWORK._NETWORK_GET_NUM_RECENT_GAMERS() end

---@param p0 integer
---@param p1 integer
---@param outData integer
---@param dataSize integer
---@return boolean
function NETWORK.NETWORK_GET_RECENT_GAMER_NAMES(p0, p1, outData, dataSize) end

function NETWORK._0x49CF17A564918E8D() end

---@param p0 integer
function NETWORK._0xD637D327080CD86E(p0) end

function NETWORK._0x564552C6AF1EEAB1() end

function NETWORK.NETWORK_ACTIVITY_RESET_TO_IDLE() end

---@param netPlaylistActivity integer
function NETWORK.NETWORK_ACTIVITY_SET_CURRENT(netPlaylistActivity) end

---@return string
function NETWORK._NETWORK_GET_ROS_TITLE_NAME() end

---@param player integer
---@param reportType integer
---@param description any
---@param horseName any
function NETWORK._REPORT_PLAYER(player, reportType, description, horseName) end
