---@meta

---@class CREW
CREW = {}

---@param crewId integer
---@return boolean
function CREW.NETWORK_FIND_GAMERS_IN_CREW(crewId) end

---@return boolean
function CREW.NETWORK_CLAN_SERVICE_IS_VALID() end

---@param gamerHandle integer
---@return boolean
function CREW.NETWORK_CLAN_PLAYER_IS_ACTIVE(gamerHandle) end

---@param memberInfo integer
---@param sizeOfData integer
---@param gamerHandle integer
---@return boolean
function CREW.NETWORK_CLAN_PLAYER_GET_DESC(memberInfo, sizeOfData, gamerHandle) end

---@return integer
function CREW.NETWORK_CLAN_GET_LOCAL_MEMBERSHIPS_COUNT() end

---@param memberInfo integer
---@param membershipIndex integer
---@return boolean
function CREW.NETWORK_CLAN_GET_MEMBERSHIP_DESC(memberInfo, membershipIndex) end

---@param p0 any
---@return boolean
function CREW._0x58D378AF2C8765B7(p0) end

---@param p0 any
---@return boolean
function CREW._NETWORK_CLAN_INVITE_PLAYER(p0) end

---@param crewInviteIndex integer
---@return boolean
function CREW._NETWORK_ACCEPT_CLAN_INVITE(crewInviteIndex) end

---@param clanId integer
---@return boolean
function CREW.NETWORK_CLAN_REQUEST_EMBLEM(clanId) end

---@param clanId integer
---@param outTXDName integer
---@return boolean
function CREW.NETWORK_CLAN_IS_EMBLEM_READY(clanId, outTXDName) end

---@param clanId integer
function CREW.NETWORK_CLAN_RELEASE_EMBLEM(clanId) end

---@return any
function CREW.NETWORK_GET_PRIMARY_CLAN_DATA_CLEAR() end

---@param gamerHandleData integer
---@param nGamerHandles integer
---@return boolean
function CREW.NETWORK_GET_PRIMARY_CLAN_DATA_START(gamerHandleData, nGamerHandles) end

---@return boolean
function CREW.NETWORK_GET_PRIMARY_CLAN_DATA_PENDING() end

---@return boolean
function CREW.NETWORK_GET_PRIMARY_CLAN_DATA_SUCCESS() end

---@param hGamer integer
---@param memberInfo integer
---@return boolean
function CREW.NETWORK_GET_PRIMARY_CLAN_DATA_NEW(hGamer, memberInfo) end

---@param p0 any
---@return any
function CREW._NETWORK_CLAN_SET_ACTIVE(p0) end
