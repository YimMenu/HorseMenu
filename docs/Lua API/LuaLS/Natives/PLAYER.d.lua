---@meta

---@class PLAYER
PLAYER = {}

---@param PlayerIndex integer
---@return integer
function PLAYER.GET_PLAYER_PED(PlayerIndex) end

---@param player integer
---@return integer
function PLAYER._GET_PLAYER_PED_2(player) end

---@param toggle boolean
function PLAYER._0x325434C68358D282(toggle) end

---@param PlayerIndex integer
---@return integer
function PLAYER.GET_PLAYER_PED_SCRIPT_INDEX(PlayerIndex) end

---@param PlayerIndex integer
---@param PlayerModelHashKey integer
---@param p2 boolean
function PLAYER.SET_PLAYER_MODEL(PlayerIndex, PlayerModelHashKey, p2) end

---@param player integer
---@return boolean
function PLAYER._NETWORK_HAS_PLAYER_VALID_PED(player) end

---@param PlayerIndex integer
---@return integer
function PLAYER.GET_PLAYER_TEAM(PlayerIndex) end

---@param PlayerIndex integer
---@param Team integer
---@param bRestrictToThisScript boolean
function PLAYER.SET_PLAYER_TEAM(PlayerIndex, Team, bRestrictToThisScript) end

---@param PlayerIndex integer
---@return string
function PLAYER.GET_PLAYER_NAME(PlayerIndex) end

---@param string any
---@return string
function PLAYER._FORMAT_PLAYER_NAME_STRING(string) end

---@param WantedLevel integer
---@return number
function PLAYER.GET_WANTED_LEVEL_RADIUS(WantedLevel) end

---@param wantedLevel integer
---@return integer
function PLAYER.GET_WANTED_LEVEL_THRESHOLD(wantedLevel) end

---@param PlayerIndex integer
---@param WantedLevel integer
---@param bDelayLawResponse boolean
function PLAYER.SET_PLAYER_WANTED_LEVEL(PlayerIndex, WantedLevel, bDelayLawResponse) end

---@param PlayerIndex integer
---@param WantedLevel integer
---@return boolean
function PLAYER.IS_PLAYER_WANTED_LEVEL_GREATER(PlayerIndex, WantedLevel) end

---@param PlayerIndex integer
function PLAYER.CLEAR_PLAYER_WANTED_LEVEL(PlayerIndex) end

---@param PlayerIndex integer
---@return boolean
function PLAYER.IS_PLAYER_DEAD(PlayerIndex) end

---@param iPlayerIndex integer
---@param bSetControlOn boolean
---@param iFlags integer
---@param bPreventHeadingChange boolean
function PLAYER.SET_PLAYER_CONTROL(iPlayerIndex, bSetControlOn, iFlags, bPreventHeadingChange) end

---@param PlayerIndex integer
---@return integer
function PLAYER.GET_PLAYER_WANTED_LEVEL(PlayerIndex) end

---@param NewMaxLevel integer
function PLAYER.SET_MAX_WANTED_LEVEL(NewMaxLevel) end

---@param maxWantedLevel integer
function PLAYER._SET_MAX_WANTED_LEVEL_2(maxWantedLevel) end

---@param bBlips boolean
function PLAYER.SET_POLICE_RADAR_BLIPS(bBlips) end

---@param PlayerIndex integer
---@return boolean
function PLAYER.IS_PLAYER_PLAYING(PlayerIndex) end

---@param PlayerIndex integer
---@param IgnorePlayer boolean
function PLAYER.SET_EVERYONE_IGNORE_PLAYER(PlayerIndex, IgnorePlayer) end

---@param player integer
---@param p1 integer
---@return boolean
function PLAYER.GET_IS_PLAYER_UI_PROMPT_ACTIVE(player, p1) end

---@param player integer
---@param promptType integer
---@param promptMode integer
---@param disabled boolean
function PLAYER._MODIFY_PLAYER_UI_PROMPT(player, promptType, promptMode, disabled) end

---@param player integer
---@param promptType integer
---@param promptMode integer
---@return boolean
function PLAYER._GET_PLAYER_UI_PROMPT_IS_DISABLED(player, promptType, promptMode) end

---@param player integer
---@param ped integer
---@param promptType integer
---@param promptMode integer
---@param enabled boolean
function PLAYER._MODIFY_PLAYER_UI_PROMPT_FOR_PED(player, ped, promptType, promptMode, enabled) end

---@param player integer
---@param ped integer
---@param promptType integer
---@param promptMode integer
---@return boolean
function PLAYER._GET_PLAYER_UI_PROMPT_FOR_PED_IS_ENABLED(player, ped, promptType, promptMode) end

---@param player integer
function PLAYER._0x93624B36E8851B42(player) end

---@param p0 any
---@param p1 any
function PLAYER._0x9073EC5456651A90(p0, p1) end

---@param p0 any
function PLAYER._0x2E67707BEC52CA4B(p0) end

---@param PlayerIndex integer
---@param PedsFlee boolean
function PLAYER.SET_ALL_RANDOM_PEDS_FLEE(PlayerIndex, PedsFlee) end

---@param PlayerIndex integer
function PLAYER.SET_ALL_RANDOM_PEDS_FLEE_THIS_FRAME(PlayerIndex) end

---@param PlayerIndex integer
function PLAYER.SET_ALL_NEUTRAL_RANDOM_PEDS_FLEE_THIS_FRAME(PlayerIndex) end

---@param p0 any
function PLAYER._0x1D256EED194F5B58(p0) end

---@param p0 any
---@return any
function PLAYER._0x5B7B97E99F84138B(p0) end

---@param player integer
---@param disable boolean
function PLAYER._SET_DISABLE_PLAYER_WANTED_LEVEL(player, disable) end

---@return number
function PLAYER._GET_WANTED_LEVEL_MULTIPLIER() end

---@param Multiplier number
function PLAYER.SET_WANTED_LEVEL_MULTIPLIER(Multiplier) end

---@param PlayerIndex integer
function PLAYER.RESET_WANTED_LEVEL_DIFFICULTY(PlayerIndex) end

---@param PlayerIndex integer
function PLAYER.UPDATE_WANTED_POSITION_THIS_FRAME(PlayerIndex) end

---@param PlayerIndex integer
function PLAYER.SUPPRESS_WITNESSES_CALLING_POLICE_THIS_FRAME(PlayerIndex) end

---@param PlayerIndex integer
function PLAYER.REPORT_POLICE_SPOTTED_PLAYER(PlayerIndex) end

---@param fLawResponseDelay number
function PLAYER.SET_LAW_RESPONSE_DELAY_OVERRIDE(fLawResponseDelay) end

function PLAYER.RESET_LAW_RESPONSE_DELAY_OVERRIDE() end

---@param PlayerIndex integer
---@return boolean
function PLAYER.CAN_PLAYER_START_MISSION(PlayerIndex) end

---@param PlayerIndex integer
---@return boolean
function PLAYER.IS_PLAYER_READY_FOR_CUTSCENE(PlayerIndex) end

---@param PlayerIndex integer
---@param EntityIndex integer
---@param p2 boolean
---@return boolean
function PLAYER.IS_PLAYER_TARGETTING_ENTITY(PlayerIndex, EntityIndex, p2) end

---@param PlayerIndex integer
---@param EntityIndex integer
---@return boolean
---@return integer
function PLAYER.GET_PLAYER_TARGET_ENTITY(PlayerIndex, EntityIndex) end

---@param player integer
---@return boolean
function PLAYER._0x927861B2C08DBEA5(player) end

---@param player integer
---@return boolean
function PLAYER._IS_PLAYER_FREE_FOCUSING(player) end

---@param player integer
---@param outEntity integer
---@param p2 boolean
---@param p3 boolean
---@return boolean
---@return integer
function PLAYER.GET_PLAYER_INTERACTION_TARGET_ENTITY(player, outEntity, p2, p3) end

---@param p0 any
---@param p1 any
---@return any
function PLAYER._0xBEA3A6E5F5F79A6F(p0, p1) end

---@param player integer
---@return boolean
function PLAYER._IS_PLAYER_IN_SCOPE(player) end

---@param PlayerIndex integer
---@return boolean
function PLAYER.IS_PLAYER_FREE_AIMING(PlayerIndex) end

---@param PlayerIndex integer
---@param EntityIndex integer
---@return boolean
function PLAYER.IS_PLAYER_FREE_AIMING_AT_ENTITY(PlayerIndex, EntityIndex) end

---@param PlayerIndex integer
---@param EntityIndex integer
---@return boolean
---@return integer
function PLAYER.GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PlayerIndex, EntityIndex) end

---@param p0 any
---@param p1 any
function PLAYER._0x3DAABE78A23694BC(p0, p1) end

---@param player integer
---@param ped integer
---@return boolean
---@return integer
function PLAYER._0x7AE93C45EC14A166(player, ped) end

---@param PlayerIndex integer
---@param Range number
function PLAYER.SET_PLAYER_LOCKON_RANGE_OVERRIDE(PlayerIndex, Range) end

---@param PlayerIndex integer
---@param bCanBeHassled boolean
function PLAYER.SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(PlayerIndex, bCanBeHassled) end

---@param PlayerIndex integer
---@param CanUseCover boolean
function PLAYER.SET_PLAYER_CAN_USE_COVER(PlayerIndex, CanUseCover) end

---@param p0 any
---@param p1 any
function PLAYER._0xD1A70C1E8D1031FE(p0, p1) end

---@param player integer
---@param p1 boolean
function PLAYER._0xACA45DDCEF6071C4(player, p1) end

---@param player integer
---@param p1 integer
---@param enable boolean
function PLAYER._0xA0C683284DF027C7(player, p1, enable) end

---@param player integer
---@param toggle boolean
function PLAYER._SET_PLAYER_CAN_MERCY_KILL(player, toggle) end

---@param player integer
---@param p1 integer
function PLAYER._0x4EC8BE63B8A5D4EF(player, p1) end

---@return integer
function PLAYER.GET_MAX_WANTED_LEVEL() end

---@param PlayerIndex integer
---@return boolean
function PLAYER.IS_PLAYER_TARGETTING_ANYTHING(PlayerIndex) end

---@param PlayerIndex integer
---@param fPercent number
function PLAYER.RESTORE_PLAYER_STAMINA(PlayerIndex, fPercent) end

---@param player integer
---@param toggle boolean
function PLAYER._0x8591EE69CC3ED257(player, toggle) end

---@param PlayerIndex integer
---@return integer
function PLAYER.GET_PLAYER_GROUP(PlayerIndex) end

---@param p0 any
---@param p1 any
function PLAYER._0x3D9DA5C9EFD20D88(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function PLAYER._0x2BEED53B912537D0(p0, p1, p2) end

---@param p0 any
function PLAYER._0x908D4B72854C8F62(p0) end

---@param p0 any
---@return any
function PLAYER._0xD1F6B912785BFD35(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
function PLAYER._0xC4873B053054C04B(p0, p1, p2, p3, p4, p5, p6, p7) end

---@param p0 any
---@param p1 any
function PLAYER._0xCA59808E51FD67C4(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
function PLAYER._0xBA5CA1FEB5DE0DF6(p0, p1, p2, p3, p4, p5) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
function PLAYER._0x0869D499A7848309(p0, p1, p2, p3, p4, p5, p6, p7) end

---@param player integer
---@param p1 integer
---@return boolean
function PLAYER._0xB331D8A73F9D2BDF(player, p1) end

---@param player integer
---@param ped integer
---@param p2 number
---@param p3 number
---@param followMode integer
---@param followPriority integer
---@param p6 boolean
function PLAYER._ADD_PLAYER_AS_FOLLOW_TARGET(player, ped, p2, p3, followMode, followPriority, p6) end

---@param player integer
---@param ped integer
function PLAYER._REMOVE_PLAYER_AS_FOLLOW_TARGET(player, ped) end

---@param p0 any
function PLAYER._0x12E09E278C6C29B7(p0) end

---@param player integer
---@param ped integer
---@param p2 integer
function PLAYER._0xDD33A82352C4652F(player, ped, p2) end

---@param player integer
---@param ped integer
---@param useSteerassist boolean
function PLAYER._0x1FDA57E8908F2609(player, ped, useSteerassist) end

---@param player integer
---@param ped integer
---@param p2 any
function PLAYER._0x84481018E668E1B8(player, ped, p2) end

---@param player integer
---@return boolean
function PLAYER._0x2009F8AB7A5E9D6D(player) end

---@param player integer
---@param ped integer
---@return boolean
function PLAYER._IS_PLAYER_FOLLOWING_TARGET(player, ped) end

---@param player integer
---@param ped integer
---@return boolean
function PLAYER._0xE7F8707269544B29(player, ped) end

---@param p0 any
---@return any
function PLAYER._0xE631EAF35828FA67(p0) end

---@param p0 any
---@param p1 any
function PLAYER._0x086549F3B0381CB1(p0, p1) end

---@param PlayerIndex integer
---@return boolean
function PLAYER.IS_PLAYER_CONTROL_ON(PlayerIndex) end

---@param PlayerIndex integer
---@return boolean
function PLAYER.IS_PLAYER_SCRIPT_CONTROL_ON(PlayerIndex) end

---@param PlayerIndex integer
---@return boolean
function PLAYER.IS_PLAYER_CLIMBING(PlayerIndex) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function PLAYER._0xEBB6E27AC2FF32DA(p0, p1, p2, p3, p4) end

---@param p0 any
---@return any
function PLAYER._0xB15CD2F9932C9AB5(p0) end

---@param player integer
---@return boolean
function PLAYER._0x621D1B289CAF5978(player) end

---@param PlayerIndex integer
---@param CheckBustedTask boolean
---@return boolean
function PLAYER.IS_PLAYER_BEING_ARRESTED(PlayerIndex, CheckBustedTask) end

---@param PlayerIndex integer
function PLAYER.RESET_PLAYER_ARREST_STATE(PlayerIndex) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function PLAYER._0xCBB54CC7FFFFAB86(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
function PLAYER._0xBED386157F65942C(p0, p1) end

---@param p0 any
---@return any
function PLAYER._0xDAB6A2FC56B7DE65(p0) end

---@param p0 any
---@return any
function PLAYER._0x0F4EAF69DA41AF43(p0) end

---@param player integer
---@param target integer
function PLAYER._SET_BOUNTY_TARGET(player, target) end

---@param player integer
function PLAYER._CLEAR_BOUNTY_TARGET(player) end

---@return integer
function PLAYER.GET_PLAYERS_LAST_VEHICLE() end

---@return integer
function PLAYER.GET_PLAYER_INDEX() end

---@param Arg integer
---@return integer
function PLAYER.INT_TO_PLAYERINDEX(Arg) end

---@param Arg integer
---@return integer
function PLAYER.INT_TO_PARTICIPANTINDEX(Arg) end

---@return integer
function PLAYER.PLAYER_ID() end

---@return integer
function PLAYER.PLAYER_PED_ID() end

---@return integer
function PLAYER.NETWORK_PLAYER_ID_TO_INT() end

---@param ForceCleanupBitField integer
---@return boolean
function PLAYER.HAS_FORCE_CLEANUP_OCCURRED(ForceCleanupBitField) end

---@param ForceCleanupBitField integer
function PLAYER.FORCE_CLEANUP(ForceCleanupBitField) end

---@param pName any
---@param ForceCleanupBitField integer
function PLAYER.FORCE_CLEANUP_FOR_ALL_THREADS_WITH_THIS_NAME(pName, ForceCleanupBitField) end

---@param Thread_Id integer
---@param ForceCleanupBitField integer
function PLAYER.FORCE_CLEANUP_FOR_THREAD_WITH_THIS_ID(Thread_Id, ForceCleanupBitField) end

---@return integer
function PLAYER.GET_CAUSE_OF_MOST_RECENT_FORCE_CLEANUP() end

---@param player integer
---@param mood integer
function PLAYER._SET_PLAYER_MOOD(player, mood) end

---@param player integer
---@return integer
function PLAYER._GET_PLAYER_MOOD(player) end

---@param PlayerIndex integer
---@param iVehicleID integer
function PLAYER.SET_PLAYER_MAY_ONLY_ENTER_THIS_VEHICLE(PlayerIndex, iVehicleID) end

---@param p0 any
---@param p1 any
function PLAYER._0xC71D07C96946E263(p0, p1) end

---@param PlayerIndex integer
function PLAYER.SET_PLAYER_MAY_NOT_ENTER_ANY_VEHICLE(PlayerIndex) end

---@return boolean
function PLAYER.IS_SYSTEM_UI_BEING_DISPLAYED() end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
---@param p8 any
---@param p9 any
function PLAYER._0xD48227263E3D06AE(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9) end

---@param player integer
---@param ped integer
---@param p2 any
---@param x number
---@param y number
---@param z number
---@param targetEntity integer
---@param p7 any
function PLAYER._0x3946FC742AC305CD(player, ped, p2, x, y, z, targetEntity, p7) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
---@param p8 any
---@param p9 any
---@param p10 any
function PLAYER._0xA28056CD1B04B250(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) end

---@param player integer
---@param name any
function PLAYER._0xC67A4910425F11F1(player, name) end

---@param PlayerIndex integer
---@param Invincible boolean
function PLAYER.SET_PLAYER_INVINCIBLE(PlayerIndex, Invincible) end

---@param PlayerIndex integer
---@return boolean
function PLAYER.GET_PLAYER_INVINCIBLE(PlayerIndex) end

---@param PlayerIndex integer
---@param bActive boolean
function PLAYER.SET_PLAYER_LOCKON(PlayerIndex, bActive) end

---@param player integer
---@param toggle boolean
function PLAYER.SET_LOCKON_TO_FRIENDLY_PLAYERS(player, toggle) end

---@param TargetMode integer
function PLAYER.SET_PLAYER_TARGETING_MODE(TargetMode) end

---@param targetMode integer
function PLAYER._SET_PLAYER_IN_VEHICLE_TARGETING_MODE(targetMode) end

---@param p0 any
---@param p1 any
---@return any
function PLAYER._0x747257807B8721CE(p0, p1) end

---@param p0 any
---@param p1 any
---@return any
function PLAYER._0x8702D9150D9FBB3D(p0, p1) end

---@param p0 any
---@param p1 any
function PLAYER._0xCB0B9506BC91E441(p0, p1) end

---@param PlayerIndex integer
function PLAYER.CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_PED(PlayerIndex) end

---@param PlayerIndex integer
---@return boolean
function PLAYER.HAS_PLAYER_DAMAGED_AT_LEAST_ONE_PED(PlayerIndex) end

---@param PlayerIndex integer
function PLAYER.CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_NON_ANIMAL_PED(PlayerIndex) end

---@param PlayerIndex integer
---@return boolean
function PLAYER.HAS_PLAYER_DAMAGED_AT_LEAST_ONE_NON_ANIMAL_PED(PlayerIndex) end

---@param p0 any
function PLAYER._0xEACEBAAE0A33FB3F(p0) end

---@param player integer
---@param p1 integer
---@return boolean
function PLAYER._0x72AD59F7B7FB6E24(player, p1) end

---@param player integer
---@param p1 integer
---@param p2 integer
---@return boolean
function PLAYER._0x1A6E84F13C952094(player, p1, p2) end

---@param player integer
---@param damageInfo any
function PLAYER._SET_PLAYER_DAMAGE_INFO_OVERRIDE(player, damageInfo) end

---@param player integer
function PLAYER._0x1F488807BC8E0630(player) end

---@param PlayerIndex integer
---@param fDragMult number
function PLAYER.SET_AIR_DRAG_MULTIPLIER_FOR_PLAYERS_VEHICLE(PlayerIndex, fDragMult) end

---@param PlayerIndex integer
---@param fMultiplier number
function PLAYER.SET_SWIM_MULTIPLIER_FOR_PLAYER(PlayerIndex, fMultiplier) end

---@return boolean
function PLAYER._0x73EB2EF2E92D23BF() end

---@param PlayerIndex integer
---@param ForcedAim boolean
---@param ped integer
---@param p3 integer
---@param p4 boolean
function PLAYER.SET_PLAYER_FORCED_AIM(PlayerIndex, ForcedAim, ped, p3, p4) end

---@param player integer
---@param ped integer
---@param p2 integer
function PLAYER._0x310CE349E0C0EC4B(player, ped, p2) end

---@param PlayerIndex integer
---@param disable boolean
function PLAYER.DISABLE_PLAYER_FIRING(PlayerIndex, disable) end

---@param p0 any
---@param p1 any
function PLAYER._0xEBFF94328FF7A18A(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function PLAYER._0xF993373285053D77(p0, p1, p2) end

---@param p0 any
---@return any
function PLAYER._0xE956C2340A76272E(p0) end

---@param player integer
---@param enable boolean
function PLAYER._ENABLE_CUSTOM_DEADEYE_ABILITY(player, enable) end

---@param p0 any
---@return any
function PLAYER._0xDE6C85975F9D4894(p0) end

---@param player integer
function PLAYER._0xBBA140062B15A8AC(player) end

---@param player integer
---@param disabled boolean
function PLAYER._SPECIAL_ABILITY_SET_DISABLED(player, disabled) end

---@param player integer
---@return boolean
function PLAYER._IS_SPECIAL_ABILITY_ACTIVE(player) end

---@param player integer
---@param toggle boolean
function PLAYER._MODIFY_INFINITE_TRAIL_VISION(player, toggle) end

---@param player integer
function PLAYER._SPECIAL_ABILITY_SET_EAGLE_EYE_DISABLED(player) end

---@param player integer
---@param amount number
---@param p2 integer
---@param p3 integer
---@param p4 integer
function PLAYER._SPECIAL_ABILITY_RESTORE_BY_AMOUNT(player, amount, p2, p3, p4) end

---@param player integer
---@param p1 number
---@param p2 integer
---@param p3 integer
---@param p4 integer
function PLAYER._0xFA437FA0738C370C(player, p1, p2, p3, p4) end

---@param player integer
---@param amount number
function PLAYER._SPECIAL_ABILITY_RESTORE_OUTER_RING(player, amount) end

---@param player integer
---@return number
function PLAYER._GET_PLAYER_REQUIRED_DEAD_EYE_AMOUNT(player) end

---@param player integer
---@return number
function PLAYER._SPECIAL_ABILITY_GET_AMOUNT_CACHED(player) end

---@param player integer
---@param amount number
---@param p2 any
function PLAYER._SPECIAL_ABILITY_DRAIN_BY_AMOUNT(player, amount, p2) end

---@param player integer
---@param p1 integer
---@param p2 boolean
function PLAYER._SPECIAL_ABILITY_START_RESTORE(player, p1, p2) end

---@param player integer
---@param multiplier number
function PLAYER._SET_SPECIAL_ABILITY_MULTIPLIER(player, multiplier) end

---@param player integer
---@return number
function PLAYER._GET_PLAYER_SPECIAL_ABILITY_MULTIPLIER(player) end

---@param player integer
---@param type integer
function PLAYER._SET_SPECIAL_ABILITY_TYPE(player, type) end

---@param player integer
---@param p1 number
function PLAYER._0x22B3CABEDDB538B2(player, p1) end

---@param player integer
---@param durationCost number
function PLAYER._SET_SPECIAL_ABILITY_DURATION_COST(player, durationCost) end

---@param player integer
---@param timer number
function PLAYER._SET_SPECIAL_ABILITY_DISABLE_TIMER(player, timer) end

---@param p0 any
---@return any
function PLAYER._0x57D9991DC1334151(p0) end

---@param p0 any
---@return any
function PLAYER._0x21091B4BEB6376EE(p0) end

---@param player integer
---@param activationCost number
---@param p2 integer
function PLAYER._SET_SPECIAL_ABILITY_ACTIVATION_COST(player, activationCost, p2) end

---@param player integer
---@param p1 number
function PLAYER._0x4D1699543B1C023C(player, p1) end

---@param player integer
---@param p1 boolean
---@return number
function PLAYER._GET_PLAYER_DEAD_EYE_METER_LEVEL(player, p1) end

---@param player integer
---@return number
function PLAYER._GET_PLAYER_DEAD_EYE(player) end

---@param player integer
---@return number
function PLAYER._GET_PLAYER_CACHED_DEAD_EYE_AMOUNT(player) end

---@param player integer
---@param p1 any
---@return number
function PLAYER._GET_PLAYER_MAX_DEAD_EYE(player, p1) end

---@param player integer
---@return number
function PLAYER._GET_PLAYER_HEALTH(player) end

---@param player integer
---@return number
function PLAYER._GET_PLAYER_STAMINA(player) end

---@param player integer
---@param p1 integer
function PLAYER._SET_PLAYER_STAT_FLAG_HASH(player, p1) end

---@param health number
---@param stamina number
---@param deadeye number
---@param healthCore integer
---@param staminaCore integer
---@param deadeyeCore integer
function PLAYER._SET_USED_ITEM_EFFECT(health, stamina, deadeye, healthCore, staminaCore, deadeyeCore) end

---@param p0 any
---@param p1 any
function PLAYER._0x08E22898A6AF4905(p0, p1) end

---@param p0 any
---@return any
function PLAYER._0xBEFED69CE8317F91(p0) end

---@param player integer
---@param enable boolean
function PLAYER._ENABLE_EAGLEEYE(player, enable) end

---@param player integer
---@return boolean
function PLAYER._IS_SECONDARY_SPECIAL_ABILITY_ENABLED(player) end

---@param player integer
function PLAYER._SECONDARY_SPECIAL_ABILITY_SET_ACTIVE(player) end

---@param player integer
---@param disabled boolean
function PLAYER._SECONDARY_SPECIAL_ABILITY_SET_DISABLED(player, disabled) end

---@param player integer
---@return boolean
function PLAYER._IS_SECONDARY_SPECIAL_ABILITY_ACTIVE(player) end

---@param p0 any
function PLAYER._0x107F2A66E1C4C83A(p0) end

---@param PlayerIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param heading number
---@param p5 boolean
---@param p6 boolean
---@param p7 boolean
---@param p8 boolean
function PLAYER.START_PLAYER_TELEPORT(PlayerIndex, VecCoorsX, VecCoorsY, VecCoorsZ, heading, p5, p6, p7, p8) end

---@param p0 boolean
function PLAYER._0x2C2D287748E8E9B7(p0) end

---@param PlayerIndex integer
---@return boolean
function PLAYER.UPDATE_PLAYER_TELEPORT(PlayerIndex) end

function PLAYER.STOP_PLAYER_TELEPORT() end

---@return boolean
function PLAYER.IS_PLAYER_TELEPORT_ACTIVE() end

---@param PlayerIndex integer
---@return number
function PLAYER.GET_PLAYER_CURRENT_STEALTH_NOISE(PlayerIndex) end

---@param PlayerIndex integer
---@param Mult number
function PLAYER.SET_PLAYER_HEALTH_RECHARGE_MULTIPLIER(PlayerIndex, Mult) end

---@param player integer
---@return number
function PLAYER._GET_PLAYER_HEALTH_RECHARGE_MULTIPLIER(player) end

---@param player integer
---@param modifier number
function PLAYER._SET_PLAYER_HEALTH_RECHARGE_TIME_MODIFIER(player, modifier) end

---@param player integer
---@param multiplier number
function PLAYER.SET_PLAYER_STAMINA_RECHARGE_MULTIPLIER(player, multiplier) end

---@param player integer
---@return number
function PLAYER._GET_PLAYER_STAMINA_RECHARGE_MULTIPLIER(player) end

---@param player integer
---@param multiplier number
function PLAYER._SET_PLAYER_STAMINA_SPRINT_DEPLETION_MULTIPLIER(player, multiplier) end

---@param player integer
---@return number
function PLAYER._GET_PLAYER_STAMINA_DEPLETION_MULTIPLIER(player) end

---@param player integer
---@param horse integer
function PLAYER._SET_PED_ACTIVE_PLAYER_HORSE(player, horse) end

---@param player integer
---@return integer
function PLAYER._GET_ACTIVE_HORSE_FOR_PLAYER(player) end

---@param player integer
---@param mount integer
function PLAYER._SET_PED_AS_SADDLE_HORSE_FOR_PLAYER(player, mount) end

---@param player integer
---@return integer
function PLAYER._GET_SADDLE_HORSE_FOR_PLAYER(player) end

---@param player integer
---@param horse integer
---@return boolean
function PLAYER.SET_PED_AS_TEMP_PLAYER_HORSE(player, horse) end

---@param player integer
---@return integer
function PLAYER._GET_TEMP_PLAYER_HORSE(player) end

---@param p0 any
---@param p1 any
function PLAYER._0x77B0B6D17A3AC9AA(p0, p1) end

---@param player integer
---@param active boolean
function PLAYER._SET_PLAYER_MOUNT_STATE_ACTIVE(player, active) end

---@param p0 any
---@param p1 any
function PLAYER._0x694FFA4308060CD1(p0, p1) end

---@param player integer
---@param speedBoost number
---@param duration integer
function PLAYER.BOOST_PLAYER_HORSE_SPEED_FOR_TIME(player, speedBoost, duration) end

---@param PlayerIndex integer
---@param Modifier number
function PLAYER.SET_PLAYER_WEAPON_DAMAGE_MODIFIER(PlayerIndex, Modifier) end

---@param PlayerIndex integer
---@param Modifier number
function PLAYER.SET_PLAYER_WEAPON_DEFENSE_MODIFIER(PlayerIndex, Modifier) end

---@param player integer
---@param p1 boolean
function PLAYER._0x818241B3EDA84191(player, p1) end

---@param PlayerIndex integer
---@param Modifier number
function PLAYER.SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(PlayerIndex, Modifier) end

---@param player integer
---@param modifier number
function PLAYER._SET_PLAYER_EXPLOSIVE_WEAPON_DAMAGE_MODIFIER(player, modifier) end

---@param p0 any
---@param p1 any
function PLAYER._0x83C989D5B5B5B466(p0, p1) end

---@param p0 any
---@return any
function PLAYER._0x03B4B759A8990505(p0) end

---@param p0 any
---@param p1 any
function PLAYER._0x67659A8F248E0141(p0, p1) end

---@param player integer
---@param damageDecrease number
function PLAYER._SET_RECEIVED_HORSEBACK_DAMAGE_DECREASE(player, damageDecrease) end

---@param player integer
---@param modifier number
function PLAYER._SET_AI_PLAYER_DEFENSE_MODIFIER_AGAINST_AI(player, modifier) end

---@param player integer
---@return number
function PLAYER._GET_AI_PLAYER_DEFENSE_MODIFIER_AGAINST_AI(player) end

---@param p0 any
---@param p1 any
---@return any
function PLAYER._0x19B2C7A6C34FAD54(p0, p1) end

---@param p0 any
---@return any
function PLAYER._0x9422743A5BA50E10(p0) end

---@param player integer
---@param weaponDefenseMod number
---@param meleeDefenseMod number
function PLAYER._SET_PLAYER_DEFENSE_MODIFIER(player, weaponDefenseMod, meleeDefenseMod) end

---@param player integer
---@param type integer
---@param defenseModifier number
function PLAYER._SET_PLAYER_DEFENSE_TYPE_MODIFIER(player, type, defenseModifier) end

---@param player integer
---@param weaponHash integer
---@param damageModifier number
function PLAYER.SET_PLAYER_WEAPON_TYPE_DAMAGE_MODIFIER(player, weaponHash, damageModifier) end

---@param player integer
---@param weaponHash integer
---@return number
function PLAYER._GET_PLAYER_WEAPON_DAMAGE(player, weaponHash) end

---@param p0 any
---@param p1 any
---@param p2 any
function PLAYER._0x5C2E5E3CAEEB1F58(p0, p1, p2) end

---@param player integer
---@param weaponGroup integer
---@param modifier number
function PLAYER._SET_PLAYER_WEAPON_GROUP_DAMAGE_MODIFIER(player, weaponGroup, modifier) end

---@param player integer
---@param weaponGroup integer
---@param toggle boolean
function PLAYER._SET_PLAYER_WEAPON_GROUP_AS_INSTANT_KILL(player, weaponGroup, toggle) end

---@param player integer
---@param modifier number
function PLAYER._SET_PLAYER_TRAMPLE_DAMAGE_MODIFIER(player, modifier) end

---@param player integer
---@param damage number
function PLAYER._SET_PLAYER_LASSO_DAMAGE_PER_SECOND(player, damage) end

---@param player integer
---@param accuracy number
function PLAYER._SET_PLAYER_TOTAL_ACCURACY_MODIFIER(player, accuracy) end

---@param player integer
---@param accuracy number
function PLAYER._SET_PLAYER_LOCAL_ACCURACY_FLOOR_MODIFIER(player, accuracy) end

---@param player integer
---@param accuracy number
function PLAYER._SET_PLAYER_REMOTE_ACCURACY_FLOOR_MODIFIER(player, accuracy) end

---@param p0 any
---@param p1 any
function PLAYER._0x3AD212429E095EFB(p0, p1) end

---@param PlayerIndex integer
---@param Mult number
function PLAYER.SET_PLAYER_NOISE_MULTIPLIER(PlayerIndex, Mult) end

---@param p0 any
---@param p1 any
function PLAYER._0x113EF458AB6CDA67(p0, p1) end

---@param PlayerIndex integer
---@param Mult number
function PLAYER.SET_PLAYER_SNEAKING_NOISE_MULTIPLIER(PlayerIndex, Mult) end

---@param playerIdx integer
---@param moveBlendRatio number
---@param timer integer
---@param heading number
---@param useRelativeHeading boolean
---@param noInputInterruption boolean
function PLAYER.SIMULATE_PLAYER_INPUT_GAIT(playerIdx, moveBlendRatio, timer, heading, useRelativeHeading, noInputInterruption) end

---@param playerIdx integer
function PLAYER.RESET_PLAYER_INPUT_GAIT(playerIdx) end

---@param PlayerIndex integer
---@param SimulateAiming boolean
function PLAYER.SET_PLAYER_SIMULATE_AIMING(PlayerIndex, SimulateAiming) end

---@param PlayerIndex integer
---@param pinFrames integer
function PLAYER.SET_PLAYER_CLOTH_PIN_FRAMES(PlayerIndex, pinFrames) end

---@param PlayerIndex integer
---@return boolean
function PLAYER.HAS_PLAYER_BEEN_SPOTTED_IN_STOLEN_VEHICLE(PlayerIndex) end

---@param PlayerIndex integer
---@param nTime integer
---@param bIncludeLocalEvents boolean
---@return boolean
function PLAYER.GET_PLAYER_RECEIVED_BATTLE_EVENT_RECENTLY(PlayerIndex, nTime, bIncludeLocalEvents) end

---@param disabled boolean
function PLAYER._SET_MOUNT_PROMPT_DISABLED(disabled) end

---@param PlayerIndex integer
---@return boolean
function PLAYER.IS_PLAYER_RIDING_TRAIN(PlayerIndex) end

---@param p0 any
---@param p1 any
function PLAYER._0x9AFCF9FE1884BF62(p0, p1) end

---@param p0 any
---@return any
function PLAYER._0x1E8099F449ABB0BA(p0) end

---@param player integer
---@return integer
function PLAYER._GET_DEADEYE_ABILITY_LEVEL(player) end

---@param player integer
---@param level integer
function PLAYER._SET_DEADEYE_ABILITY_LEVEL(player, level) end

---@param player integer
---@param abilityType integer
---@return boolean
function PLAYER._IS_DEADEYE_ABILITY_LOCKED(player, abilityType) end

---@param player integer
---@param abilityType integer
---@param toggle boolean
function PLAYER._SET_DEADEYE_ABILITY_LOCKED(player, abilityType, toggle) end

---@param player integer
---@param toggle boolean
function PLAYER._SET_DEADEYE_TAGGING_ENABLED(player, toggle) end

---@param player integer
---@return boolean
function PLAYER._GET_IS_DEADEYE_TAGGING_ENABLED(player) end

---@param p0 any
---@param p1 any
function PLAYER._0x3C4AE8506638C7E2(p0, p1) end

---@param p0 any
---@return any
function PLAYER._0x51139D8C17B16FBC(p0) end

---@param p0 any
---@param p1 any
function PLAYER._0x8F44EBB3BA8F6D44(p0, p1) end

---@param player integer
---@param filter integer
function PLAYER._SET_DEADEYE_TAGGING_CONFIG(player, filter) end

---@param p0 any
---@return any
function PLAYER._0xE92261BD28C0878F(p0) end

---@param player integer
---@param delay number
function PLAYER._SET_DEADEYE_ABILITY_DEPLETION_DELAY(player, delay) end

---@param p0 any
---@return any
function PLAYER._0xA54000D4BFD90BDE(p0) end

---@param p0 any
---@param p1 any
function PLAYER._0x6EDB5D08CB03E763(p0, p1) end

---@param p0 any
---@param p1 any
---@return any
function PLAYER._0x27AD7162D3FED01E(p0, p1) end

---@param player integer
---@return integer
function PLAYER._GET_NUM_MARKED_DEADEYE_TARGETS(player) end

---@param p0 any
---@return any
function PLAYER._0xC93A9A45430D484E(p0) end

---@param player integer
---@param p1 boolean
function PLAYER._0x570A13A4CA2799BB(player, p1) end

---@param player integer
---@param p1 boolean
function PLAYER._0x3ACAC8832E77BC93(player, p1) end

---@param player integer
---@param p1 integer
function PLAYER._0x2B12B6FC8B8772AB(player, p1) end

---@param player integer
function PLAYER._0xE910932F4B30BE23(player) end

---@param player integer
---@param p1 number
---@param p2 number
---@param p3 number
---@param p4 number
---@param p5 any
function PLAYER._0x131E294EF60160DF(player, p1, p2, p3, p4, p5) end

---@param player integer
---@param bitflag integer
function PLAYER._0x0E9057A9DA78D0F8(player, bitflag) end

---@param player integer
---@param p1 integer
function PLAYER._0x263D69767F76059C(player, p1) end

---@param player integer
---@param entity integer
---@param p2 boolean
function PLAYER._REGISTER_EAGLE_EYE_FOR_ENTITY(player, entity, p2) end

---@param player integer
---@param entity integer
---@param p2 any
function PLAYER._REGISTER_EAGLE_EYE_TRAILS_FOR_ENTITY(player, entity, p2) end

---@param player integer
---@param entity integer
function PLAYER._UNREGISTER_EAGLE_EYE_FOR_ENTITY(player, entity) end

---@param player integer
---@param entity integer
---@param p2 any
function PLAYER._UNREGISTER_EAGLE_EYE_TRAILS_FOR_ENTITY(player, entity, p2) end

---@param player integer
function PLAYER._0xE5D3EB37ABC1EB03(player) end

---@param player integer
---@param entity integer
---@return boolean
function PLAYER._IS_EAGLE_EYE_REGISTERED_FOR_ENTITY(player, entity) end

---@param p0 any
---@param p1 any
---@return any
function PLAYER._0x6852288340B43239(p0, p1) end

---@param p0 any
---@param p1 any
---@return any
function PLAYER._0xE50A67C33514A390(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function PLAYER._0xD288E02E364972D2(p0, p1, p2) end

---@param entity integer
---@param trail any
---@param p2 any
---@param p3 any
function PLAYER._EAGLE_EYE_DISABLE_TRACKING_TRAIL(entity, trail, p2, p3) end

---@param entity1 integer
---@param entity2 integer
---@param p2 any
---@param p3 number
function PLAYER._0x6ECFC621A168424C(entity1, entity2, p2, p3) end

---@param entity1 integer
---@param entity2 integer
---@param p2 any
function PLAYER._0xDC5E09D012D759C4(entity1, entity2, p2) end

---@param p0 any
function PLAYER._0x00B156AFEBCC5AE0(p0) end

---@param p0 any
function PLAYER._0xC58CE6824E604DEC(p0) end

---@param p0 any
---@param p1 any
function PLAYER._0x330CA55A3647FA1C(p0, p1) end

---@param p0 any
---@return any
function PLAYER._0xA62BBAAE67A05BB0(p0) end

---@param player integer
---@param p1 boolean
---@param p2 integer
function PLAYER._EAGLE_EYE_SET_COLOR(player, p1, p2) end

---@param p0 any
---@param p1 any
function PLAYER._0x22C8B10802301381(p0, p1) end

---@param player integer
---@param modifier number
function PLAYER._EAGLE_EYE_SET_DRAIN_RATE_MODIFIER(player, modifier) end

---@param ped integer
---@param p1 boolean
function PLAYER._0x06E1FB78B1E59CA5(ped, p1) end

---@param ped integer
---@param disabled boolean
function PLAYER._EAGLE_EYE_SET_PLUS_FLAG_DISABLED(ped, disabled) end

---@param p0 any
---@return any
function PLAYER._0x3813E11A378958A5(p0) end

---@param player integer
---@param linkedWaypointPed integer
function PLAYER._EAGLE_EYE_SET_FOCUS_ON_ASSOCIATED_CLUE_TRAIL(player, linkedWaypointPed) end

---@param p0 any
function PLAYER._0x0F9CF06986300875(p0) end

---@param player integer
---@param p1 number
function PLAYER._EAGLE_EYE_SET_TRACKING_UPGRADE(player, p1) end

---@param player integer
---@param p1 number
function PLAYER._EAGLE_EYE_SET_TRACKING_UPGRADE_2(player, p1) end

---@param p0 any
---@return any
function PLAYER._0x1DA5C5B0923E1B85(p0) end

---@param p0 any
---@return any
function PLAYER._0xAAED694CE814817F(p0) end

---@param entity integer
---@param red integer
---@param green integer
---@param blue integer
function PLAYER.EAGLE_EYE_SET_CUSTOM_ENTITY_TINT(entity, red, green, blue) end

---@param entity integer
---@param p1 any
function PLAYER._0xBC02B3D151D3859F(entity, p1) end

---@param entity integer
---@param distance number
function PLAYER._EAGLE_EYE_SET_CUSTOM_DISTANCE(entity, distance) end

---@param player integer
function PLAYER._0xF21C7A3F3FFBA629(player) end

---@param player integer
---@param p1 number
function PLAYER._SET_PLAYER_MANAGE_BUFF_SUPER_JUMP(player, p1) end

---@param flagId integer
---@param toggle boolean
function PLAYER._SET_LOCAL_PLAYER_PERSONA_ABILITY_FLAG(flagId, toggle) end

---@param player integer
---@param ammoType integer
---@param amount integer
function PLAYER._SET_PLAYER_MAX_AMMO_OVERRIDE_FOR_AMMO_TYPE(player, ammoType, amount) end

---@param player integer
function PLAYER._0xC900A465364A85D6(player) end

---@param p0 any
---@param p1 any
---@param p2 any
function PLAYER._0xCFB2EED4FCB7BD77(p0, p1, p2) end

---@param p0 any
function PLAYER._0x2BB8D58E88777499(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
function PLAYER._0x00EB5A760638DB55(p0, p1, p2) end

---@param p0 any
function PLAYER._0x65887EAC535A0B0C(p0) end

---@param player integer
---@param modifier number
function PLAYER._SET_WEAPON_DEGRADATION_MODIFIER(player, modifier) end

---@param player integer
---@param drawReductionTime number
function PLAYER._SET_BOW_DRAW_REDUCTION_TIME_IN_DEADEYE(player, drawReductionTime) end

---@param player integer
---@param staminaDrain number
function PLAYER._SET_BOW_STAMINA_DRAIN_SPEED(player, staminaDrain) end

---@param player integer
---@param closeRangeLowerBound number
---@param closeRangeUpperBound number
function PLAYER._SET_DAMAGE_CLOSE_DISTANCE_BONUS(player, closeRangeLowerBound, closeRangeUpperBound) end

---@param player integer
---@param closeDamageBonus number
function PLAYER._SET_DAMAGE_CLOSE_DISTANCE_BONUS_TOTAL(player, closeDamageBonus) end

---@param player integer
---@param farRangeLowerBound number
---@param farRangeUpperBound number
function PLAYER._SET_DAMAGE_FAR_DISTANCE_BONUS(player, farRangeLowerBound, farRangeUpperBound) end

---@param player integer
---@param farDamageBonus number
function PLAYER._SET_DAMAGE_FAR_DISTANCE_BONUS_TOTAL(player, farDamageBonus) end

---@param p0 any
---@return any
function PLAYER._0x6C54E69516CC56BD(p0) end

---@param p0 any
---@param p1 any
function PLAYER._0x3A8611BD7BDE84F7(p0, p1) end

---@param p0 any
---@param p1 any
function PLAYER._0xC177C827CEFC0AA4(p0, p1) end

---@param p0 any
---@param p1 any
function PLAYER._0xBD96185264DDAAEA(p0, p1) end

---@param p0 any
---@param p1 any
function PLAYER._0x628E742FE1F79C4A(p0, p1) end

---@param player integer
---@param speech any
function PLAYER._SET_PLAYER_INTERACTION_POSITIVE_RESPONSE(player, speech) end

---@param player integer
---@param speech any
function PLAYER._SET_PLAYER_INTERACTION_NEGATIVE_RESPONSE(player, speech) end

---@param player integer
---@param p1 any
function PLAYER._0x216BC0D3D2E413D2(player, p1) end

---@param p0 any
---@param p1 any
function PLAYER._0x45EF176B532CA851(p0, p1) end

---@param p0 any
---@param p1 any
function PLAYER._0xA342495F93B7B838(p0, p1) end

---@param p0 any
function PLAYER._0x3BB84F812E052C90(p0) end

---@param p0 any
---@param p1 any
function PLAYER._0x9FC5A003FB76EDBD(p0, p1) end

---@param player integer
---@param p1 any
function PLAYER._0x0FAF95D71ED67ADE(player, p1) end

---@param player integer
---@param p1 any
function PLAYER._0x988C9045531B9FCE(player, p1) end

---@param player integer
---@param p1 any
function PLAYER._0x06C3DB00B69D5435(player, p1) end

---@param category integer
---@param emote integer
function PLAYER._0xBB6EA5D59E926095(category, emote) end

---@param emote integer
---@return boolean
function PLAYER._0xE1D356F5A66D0FFA(emote) end

---@param p0 any
---@param p1 any
function PLAYER._0x929DDD5538F3DF1F(p0, p1) end

---@param p0 any
---@param p1 any
function PLAYER._0xFA7DAAE3959E6C7B(p0, p1) end

---@param p0 any
---@param p1 any
function PLAYER._0x9461A8FAB0378E5B(p0, p1) end

---@param p0 any
---@param p1 any
function PLAYER._0xCB61A63AA53D7D22(p0, p1) end

---@param player integer
---@param weapon integer
---@param p2 boolean
function PLAYER._0xCFFC3ECCD7A5CCEB(player, weapon, p2) end

---@param p0 any
function PLAYER._0x76F7E1BCD623A429(p0) end

---@param p0 any
---@param p1 any
function PLAYER._0x585CE159DB46FADB(p0, p1) end

---@param player integer
---@param playerResetFlag integer
---@param p2 boolean
function PLAYER._SET_PLAYER_RESET_FLAG(player, playerResetFlag, p2) end

---@param player integer
---@param playerResetFlag integer
---@return boolean
function PLAYER._GET_PLAYER_RESET_FLAG(player, playerResetFlag) end

---@param player integer
---@return integer
function PLAYER.GET_MOUNT_OWNED_BY_PLAYER(player) end

---@param mount integer
---@return integer
function PLAYER._GET_PLAYER_OWNER_OF_MOUNT(mount) end

---@param player integer
---@param mount integer
function PLAYER._SET_PLAYER_OWNS_MOUNT(player, mount) end

---@param player integer
---@return integer
function PLAYER._GET_VEHICLE_OWNED_BY_PLAYER(player) end

---@param vehicle integer
---@return integer
function PLAYER._GET_PLAYER_OWNER_OF_VEHICLE(vehicle) end

---@param player integer
---@param vehicle integer
function PLAYER._SET_PLAYER_OWNS_VEHICLE(player, vehicle) end

---@param player integer
---@return integer
function PLAYER._GET_PLAYER_HUNTING_WAGON(player) end

---@param player integer
---@param wagon integer
function PLAYER._SET_PLAYER_HUNTING_WAGON(player, wagon) end

---@param p0 any
---@param p1 any
function PLAYER._0x9044835BE9D9DBFE(p0, p1) end

---@param entity integer
---@param type integer
---@return integer
---@return integer
function PLAYER.GET_DISCOVERABLE_NAME_HASH_AND_TYPE_FOR_ENTITY(entity, type) end

---@param p0 integer
---@param model boolean
---@param outfit boolean
---@return integer
function PLAYER._GET_CONSTRUCTED_DISCOVERED_CHARACTER_NAME(p0, model, outfit) end

---@param ped integer
---@return integer
function PLAYER.GET_TARGET_CHARACTER_NAME_SCRIPT_OVERRIDE_HASH(ped) end

---@param ped integer
---@return string
function PLAYER.GET_TARGET_CHARACTER_NAME_SCRIPT_OVERRIDE_RAW_STRING(ped) end

---@param ped integer
---@return integer
function PLAYER.GET_TARGET_CHARACTER_NAME_FOR_LOCAL_PLAYER(ped) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function PLAYER._0xDA9D7BE231FE865F(p0, p1, p2) end

---@param player integer
---@param p1 integer
---@param discoveryHash integer
function PLAYER._SET_PLAYER_HAS_DISCOVERED_CHARACTER_NAME_SP(player, p1, discoveryHash) end

---@param player integer
---@param p1 integer
---@param discoveryHash integer
---@return boolean
function PLAYER._GET_HAS_PLAYER_DISCOVERED_CHARACTER_NAME_SP(player, p1, discoveryHash) end

---@param p0 any
---@param p1 any
---@param p2 any
function PLAYER._0xCDDD4B74660E2335(p0, p1, p2) end

---@param p0 any
function PLAYER._0x77E83C315A3B31CA(p0) end

---@param discoveryHash integer
function PLAYER._SET_PLAYER_HAS_DISCOVERED_CHARACTER_NAME_MP(discoveryHash) end

---@param discoveryHash integer
---@return boolean
function PLAYER.GET_HAS_PLAYER_DISCOVERED_CHARACTER_NAME_MP(discoveryHash) end

---@param discoveryHash integer
function PLAYER._MODIFY_PLAYER_DISCOVERED_CHARACTER_NAME_MP_SET_UNDISCOVERED(discoveryHash) end

---@param player integer
---@param showingInfoCard boolean
function PLAYER._SET_SHOW_INFO_CARD(player, showingInfoCard) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function PLAYER._0x4DBC4873707E8FD6(p0, p1, p2, p3) end

---@param p0 any
function PLAYER._0xCEDC16930526F728(p0) end

---@param location integer
function PLAYER._0x14E57F88BA0A07FC(location) end

---@return any
function PLAYER._0x2E1ABE627C95ED9B() end

function PLAYER._0x497A18F8F88AA9D8() end

---@param p0 integer
function PLAYER._0x4F0D2256AAE94EDA(p0) end

---@param player integer
---@param p1 any
function PLAYER._SET_LOCKON_FOCUS_FIRE_VFX(player, p1) end

---@return any
function PLAYER._0x0B7803F6F7BB43E0() end

---@param p0 any
---@return any
function PLAYER._0xC74EB3F2EC169F6B(p0) end

---@param p0 any
---@param p1 any
function PLAYER._0x3B296934DB026873(p0, p1) end

---@param mount integer
---@param iMinBuckTime integer
function PLAYER.SET_MIN_TIME_BEFORE_HORSE_BUCKING(mount, iMinBuckTime) end

---@return any
function PLAYER._0xF4CB347D7B5EB0FD() end

---@param p0 any
---@param p1 any
function PLAYER._0xCD7CA3013FD12749(p0, p1) end

---@param toggle boolean
function PLAYER._FORCE_REST_SCENARIO(toggle) end

---@return boolean
function PLAYER._0x57028FD99886F6F9() end

---@param p0 any
function PLAYER._0x35A33783EC3C3448(p0) end

---@param p0 any
function PLAYER._0x39D8D7082BC34B72(p0) end

---@param p0 any
function PLAYER._0x1AD8AD999C27F44A(p0) end
