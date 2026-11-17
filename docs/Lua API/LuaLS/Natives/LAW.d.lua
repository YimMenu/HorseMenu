---@meta

---@class LAW
LAW = {}

---@param player integer
---@param crimeType integer
---@param bounty integer
---@param entity integer
---@param isKnownSuspect boolean
function LAW._REPORT_CRIME(player, crimeType, bounty, entity, isKnownSuspect) end

---@param player integer
---@param crimeType integer
---@param p2 integer
---@param p3 integer
---@param p4 integer
function LAW.SUPPRESS_CRIME_THIS_FRAME(player, crimeType, p2, p3, p4) end

---@param player integer
---@param crimeType integer
---@return integer
function LAW.NUM_CRIMES_SUPPRESSED(player, crimeType) end

---@param ped integer
---@param crimeType integer
---@param p2 boolean
---@return any
function LAW._0xFFEBE5AA96BC2E4E(ped, crimeType, p2) end

---@param p0 integer
function LAW._0x15ABD5004CAD2D99(p0) end

---@param crimeType integer
---@param p1 boolean
function LAW._0xF611DE44AEB36A1D(crimeType, p1) end

---@return boolean
function LAW._0x3D2674828A4E6B3C() end

---@param p0 boolean
function LAW._0xC5EB2755FA25F1E9(p0) end

---@param player integer
---@return integer
function LAW.GET_BOUNTY(player) end

---@param player integer
---@param itemValueAmount integer
function LAW.ADD_BOUNTY(player, itemValueAmount) end

---@param player integer
---@param amount integer
function LAW.SET_BOUNTY(player, amount) end

---@param player integer
function LAW.CLEAR_BOUNTY(player) end

---@param player integer
---@return integer
function LAW.GET_WANTED_SCORE(player) end

---@param player integer
---@param intensity integer
function LAW.SET_WANTED_SCORE(player, intensity) end

---@param player integer
function LAW.CLEAR_WANTED_SCORE(player) end

---@param p0 any
function LAW._0x331D349E0380B097(p0) end

function LAW._0x292AD61A33A7A485() end

---@param player integer
function LAW._0x07E8B8B20570271C(player) end

---@param player integer
---@param lawRegionHash integer
function LAW._0x22741652985C84D0(player, lawRegionHash) end

---@param player integer
---@param dispatchResponseHash integer
function LAW._REPORT_PLAYER_LAW_DISPATCH_RESPONSE_OVERRIDE(player, dispatchResponseHash) end

---@return boolean
function LAW._0x9EF07CFBB19A9733() end

---@param toggle boolean
function LAW._SET_LAW_DISABLED(toggle) end

function LAW._FORCE_LAW_ON_LOCAL_PLAYER_IMMEDIATELY() end

---@param player integer
---@param lawRegionHash integer
---@param stateHash integer
function LAW._SET_LAW_REGION(player, lawRegionHash, stateHash) end

---@param player integer
---@param p1 boolean
function LAW._0x5E6F375CA101C108(player, p1) end

---@param player integer
---@param p1 integer
function LAW._SET_LAW_RBS_VOLUME(player, p1) end

---@param player integer
---@return boolean
function LAW.IS_LAW_INCIDENT_ACTIVE(player) end

---@param player integer
---@return integer
function LAW._0x148E7AC8141C9E64(player) end

---@param player integer
---@param crimeType integer
---@param bounty integer
---@param p3 number
---@param p4 number
---@param p5 boolean
---@param p6 number
---@param p7 number
---@param p8 any
function LAW._0xEDFC6C1FD1C964F5(player, crimeType, bounty, p3, p4, p5, p6, p7, p8) end

---@param pedGroup1 integer
---@param ped integer
---@param pedGroup2 integer
---@param x number
---@param y number
---@param z number
---@param crimeType integer
---@return boolean
function LAW._LAW_WITNESS_RESPONSE_TASK(pedGroup1, ped, pedGroup2, x, y, z, crimeType) end

---@param ped integer
---@param p1 integer
---@return any
function LAW._0x018F30D762E62DF8(ped, p1) end

---@param ped integer
---@param p1 integer
---@return any
function LAW._0x318F0F9A4426CFA2(ped, p1) end

---@param entity integer
---@param ped integer
---@param p2 boolean
---@param x number
---@param y number
---@param z number
---@param crimeType integer
---@return any
function LAW._0x95878B13E272EF1F(entity, ped, p2, x, y, z, crimeType) end

---@param player integer
---@param crimeType integer
---@param pedGroup integer
function LAW._ADD_WITNESS_RESPONSE(player, crimeType, pedGroup) end

---@param player integer
---@param crimeType integer
---@param p2 integer
function LAW._0xD7494DED50C6EF52(player, crimeType, p2) end

---@param player integer
---@return boolean
function LAW.ARE_WITNESSES_ACTIVE(player) end

---@param player integer
---@return boolean
function LAW._ARE_WITNESSES_PENDING(player) end

---@param player integer
---@param areInvestigatorsActive boolean
---@param p2 any
---@return boolean
function LAW._ARE_INVESTIGATORS_ACTIVE(player, areInvestigatorsActive, p2) end

---@param player integer
---@param itemSet integer
function LAW._0x522F74636DF10201(player, itemSet) end

---@param itemSet integer
---@param p1 boolean
---@param p2 boolean
function LAW._0xDA1A9ADC4E3D4B16(itemSet, p1, p2) end

---@param toggle boolean
function LAW._ENABLE_DISPATCH_LAW(toggle) end

---@param toggle boolean
function LAW._ENABLE_DISPATCH_LAW_2(toggle) end

---@return boolean
function LAW._ARE_ANY_LAW_PEDS_INVESTIGATING() end

---@return boolean
function LAW._ARE_LAW_PEDS_ENABLED_FOR_TRAIN() end

---@param p0 integer
function LAW._0x82F11E1296996574(p0) end

---@param p0 integer
function LAW._0x3852237A3D9DF145(p0) end

---@param ped integer
---@return boolean
function LAW._0x0EAF918F751F27BA(ped) end

---@param ped integer
---@return boolean
function LAW._0xC0DF161950FB101E(ped) end

---@param player integer
---@param p1 integer
---@return any
function LAW._0xE4D6E45F491A66CB(player, p1) end

---@param player integer
---@return integer
function LAW._0xE9EB79CBF9C0F58A(player) end

---@param player integer
---@param ped integer
---@param outCoords Vector3
---@return Vector3
function LAW._0x21213B833EF4DAE7(player, ped, outCoords) end

---@param player integer
function LAW._0x61B98367D93F012F(player) end

---@param player integer
---@param crimeType integer
---@param p2 any
---@return integer
function LAW._0x6ABC50979655BEE7(player, crimeType, p2) end

---@param player integer
---@param p1 boolean
function LAW._0x390710D2DAFA6BFF(player, p1) end

---@param crimeType integer
---@return integer
function LAW._GET_CRIME_BOUNTY_AMOUNT_BY_TYPE(crimeType) end

---@param crimeType integer
---@param p1 any
---@return integer
function LAW._0xDAEFDFDB2AEECE37(crimeType, p1) end

---@param player integer
---@return integer
function LAW._GET_HUD_PLAYER_CRIME_TYPE(player) end

---@param player integer
---@return integer
function LAW._0xE083BEDA81709891(player) end

---@param player integer
---@param p1 integer
---@param p2 integer
---@return boolean
function LAW._0x89E005B1662F6E48(player, p1, p2) end

---@param player integer
---@param p1 integer
---@param p2 integer
---@return boolean
function LAW._0x3738B784DDD35CC6(player, p1, p2) end

---@param crimeType integer
---@return integer
function LAW._0x0BDFEBCF40A5F7E3(crimeType) end

---@param dispatchResponseHash integer
function LAW._SET_CUSTOM_LAW_DISPATCH_RESPONSE(dispatchResponseHash) end

---@param x number
---@param y number
---@param z number
---@param dispatchResponseHash integer
---@return any
function LAW._CREATE_LAW_DISPATCH_RESPONSE_FOR_COORDS(x, y, z, dispatchResponseHash) end

function LAW._SET_BOUNTY_HUNTER_PURSUIT_CLEARED() end

function LAW._0xBD944A3D36E992DE() end

---@param p0 boolean
function LAW._0x987BE590FB9D41E5(p0) end

---@param p0 boolean
function LAW._0xDCF12B89624AAC96(p0) end

---@param p0 boolean
function LAW._0xDDCE8E960D1DE240(p0) end

function LAW._0xDEA083C16BB91345() end

---@param player integer
---@param itemSet integer
function LAW._0x9C8A2BF37E966464(player, itemSet) end

---@param player integer
---@return boolean
function LAW._0x9D5C9A5A3321B128(player) end

---@param player integer
---@return boolean
function LAW._0x0F230DE0DDBE3649(player) end

---@param player integer
---@return boolean
function LAW._0x9945A3E2528A02E8(player) end

---@param player integer
---@return number
function LAW._GET_TIME_SINCE_LAST_SEEN_BY_LAW(player) end

---@param p0 number
function LAW._0x9B4C564BFA7CFF37(p0) end

---@param toggle boolean
function LAW._SET_ALLOW_DISABLED_LAW_RESPONSES(toggle) end

---@param player integer
function LAW.RESET_WANTED_FOR_NEW_INCIDENT(player) end

---@param ped integer
---@return boolean
function LAW._0x856CE8FDE2416602(ped) end

---@param entity integer
---@return boolean
function LAW._0x7351DA734F989F4E(entity) end

---@param p0 integer
---@return integer
function LAW._GET_BOUNTY_HUNTER_GLOBAL_COOLDOWN(p0) end

---@param p0 integer
---@param p1 integer
function LAW._SET_BOUNTY_HUNTER_GLOBAL_COOLDOWN(p0, p1) end

---@param p0 any
function LAW._0x2001687F9562FD9D(p0) end

---@param p0 integer
---@param p1 boolean
---@param p2 any
function LAW._PAUSE_BOUNTY_HUNTER_COOLDOWN(p0, p1, p2) end

---@param p0 boolean
---@param p1 any
function LAW._0xE9AC8466ABE484BB(p0, p1) end

---@param ped integer
---@return boolean
function LAW._0x40851BCC33ACD9AB(ped) end

---@return boolean
function LAW._0xF46108C50A22B029() end

function LAW._0x7803436E68C32B26() end

function LAW._0xC310239ACCCF5579() end

function LAW._0x29CD4896ECB66C12() end

function LAW._0xE94B5E938619712E() end

---@param player integer
---@return integer
function LAW._0x7FC667F6DDFBCDCC(player) end

---@param crimeType integer
---@return integer
function LAW._0x9C5BD8C562565CE6(crimeType) end

---@param player integer
---@param data integer
function LAW._0xCBFB4951F2E3934C(player, data) end

---@param ped integer
---@param behaviour integer
function LAW._SET_PED_LAW_BEHAVIOUR(ped, behaviour) end

---@param ped integer
---@param bitset integer
function LAW._0x00DB0BC05E3FAA4E(ped, bitset) end

---@param x number
---@param y number
---@param z number
---@param p3 number
---@param itemSet integer
function LAW._0x0C392DB374655176(x, y, z, p3, itemSet) end

---@param p0 integer
---@return any
function LAW._0xC687A23E166DCF68(p0) end

---@param multiplier number
function LAW._SET_DISPATCH_MULTIPLIER_OVERRIDE(multiplier) end

---@param player integer
---@return boolean
function LAW._0x26934083D3F2579C(player) end

---@param player integer
---@param p1 integer
---@param crimeType integer
---@return boolean
---@return integer
function LAW.GET_PLAYER_REGISTERED_CRIME(player, p1, crimeType) end

---@param player integer
---@param p1 integer
---@param crimeType integer
---@return boolean
---@return integer
function LAW._0xB527099D1E1EED49(player, p1, crimeType) end

---@param player integer
function LAW.CLEAR_PLAYER_PAST_CRIMES(player) end

---@param player integer
---@param lawRegionHash integer
function LAW.SET_PLAYER_ARRESTED_IN_REGION(player, lawRegionHash) end

---@param player integer
---@param lawRegionHash integer
function LAW.SET_PLAYER_TURNED_IN_BOUNTY_IN_REGION(player, lawRegionHash) end

---@param player integer
---@param p1 boolean
function LAW._0xD6C0A8C7C0B2F82C(player, p1) end

---@param player integer
---@param range number
function LAW.SET_LAW_SENSE_RANGE_MODIFIER(player, range) end

---@param flag integer
---@param p1 boolean
function LAW._0x7EF2A2FE38D74456(flag, p1) end

---@param flag integer
---@return boolean
function LAW._0xC7DC5A0A7DF608CB(flag) end

---@param player integer
---@param p1 boolean
function LAW.SET_DISABLE_DISTURBANCE_CRIMES(player, p1) end

---@param player integer
---@param p1 boolean
function LAW.SET_POSTPONE_DISTURBANCE_CRIMES_DURING_COMBAT(player, p1) end

---@param name any
function LAW._CREATE_GUARD_ZONE(name) end

---@param name any
function LAW._REMOVE_GUARD_ZONE(name) end

---@param ped integer
---@param name any
function LAW._0x9772395CC73E8D1F(ped, name) end

---@param name any
function LAW._DISABLE_GUARD_ZONE(name) end

---@param name any
---@return boolean
function LAW._0x0DBACA9C38C9A686(name) end

---@param ped integer
---@return boolean
function LAW._IS_GUARD_PED_INVESTIGATING(ped) end

---@param guardZoneName any
---@param entity integer
---@param x number
---@param y number
---@param z number
---@return boolean
function LAW._CREATE_GUARD_ZONE_FOR_ENTITY(guardZoneName, entity, x, y, z) end

---@param name any
---@param volume integer
function LAW._SET_GUARD_ZONE_VOLUME_REGISTRATION_START(name, volume) end

---@param name any
---@param volume integer
function LAW._SET_GUARD_ZONE_VOLUME_RESTRICTED(name, volume) end

---@param name any
---@param volume integer
function LAW._SET_GUARD_ZONE_VOLUME_THREAT(name, volume) end

---@param name any
---@param volume integer
function LAW._SET_GUARD_ZONE_VOLUME_WARNING(name, volume) end

---@param name any
---@param volume integer
function LAW._SET_GUARD_ZONE_VOLUME_REGISTRATION_END(name, volume) end

---@param name any
---@param x number
---@param y number
---@param z number
function LAW._SET_GUARD_ZONE_POSITION(name, x, y, z) end

---@param name any
---@param x number
---@param y number
---@param z number
function LAW._SET_GUARD_ZONE_POSITION_2(name, x, y, z) end
