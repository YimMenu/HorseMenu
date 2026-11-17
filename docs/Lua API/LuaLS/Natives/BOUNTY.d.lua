---@meta

---@class BOUNTY
BOUNTY = {}

---@param outRpcGuid integer
---@return boolean
function BOUNTY._BOUNTY_REQUEST_PAY_OFF_BOUNTY(outRpcGuid) end

---@param outRpcGuid integer
---@param p1 integer
---@param costType integer
---@return boolean
function BOUNTY._BOUNTY_REQUEST_PAY_OFF_BOUNTY_EX(outRpcGuid, p1, costType) end

---@param outRpcGuid integer
---@param crimeType integer
---@param p2 boolean
---@return boolean
function BOUNTY._BOUNTY_REQUEST_SELF_REPORT_CRIME(outRpcGuid, crimeType, p2) end

---@param outRpcGuid integer
---@return boolean
function BOUNTY._BOUNTY_REQUEST_SELF_REPORT_KILLED_BY_BOUNTY_HUNTER(outRpcGuid) end

---@param gamerHandle integer
---@param bountyData integer
---@return boolean
function BOUNTY.BOUNTY_GET_BOUNTY_ON_PLAYER(gamerHandle, bountyData) end

---@param rpcGuid integer
---@return boolean
function BOUNTY._BOUNTY_IS_REQUEST_PENDING(rpcGuid) end

---@param outRpcGuid integer
---@param p1 integer
---@return boolean
function BOUNTY._BOUNTY_REQUEST_BEGIN_WANTED_POSTER(outRpcGuid, p1) end

---@param p0 integer
---@return boolean
function BOUNTY._0x81847C2134039BDC(p0) end

---@param outRpcGuid integer
---@param p1 integer
---@return boolean
function BOUNTY._BOUNTY_REQUEST_COMPLETE_WANTED_POSTER(outRpcGuid, p1) end

---@param outRpcGuid integer
---@param p1 integer
---@return boolean
function BOUNTY._BOUNTY_REQUEST_COMPLETE_SPLIT_WANTED_POSTER(outRpcGuid, p1) end

function BOUNTY._BOUNTY_CANCEL_WANTED_POSTER() end

---@param outRpcGuid integer
---@param p1 integer
---@param p2 integer
---@return boolean
function BOUNTY.BOUNTY_REQUEST_BEGIN_LEGENDARY_MISSION(outRpcGuid, p1, p2) end

---@param outRpcGuid integer
---@param p1 integer
---@param p2 integer
---@return boolean
function BOUNTY.BOUNTY_REQUEST_BEGIN_LEGENDARY_MISSION_FOR_POSSE(outRpcGuid, p1, p2) end

---@param outRpcGuid integer
---@param p1 integer
---@return boolean
function BOUNTY._BOUNTY_REQUEST_COMPLETE_LEGENDARY_MISSION(outRpcGuid, p1) end

function BOUNTY._BOUNTY_CANCEL_LEGENDARY_MISSION() end

---@param p0 integer
---@param p1 integer
---@param p2 integer
---@return boolean
function BOUNTY.BOUNTY_GET_WANTED_POSTER_SLOT(p0, p1, p2) end

---@param p0 any
---@param p1 integer
---@return boolean
function BOUNTY.BOUNTY_GET_LEGENDARY_TARGET(p0, p1) end

---@param p0 integer
---@return boolean
function BOUNTY._0x86EC5F83867C4B70(p0) end

---@param p0 integer
---@return boolean
function BOUNTY.BOUNTY_GET_COOLDOWN_COLLECTION(p0) end

---@param outRpcGuid integer
---@return boolean
function BOUNTY._BOUNTY_REQUEST_BECOME_TARGET_OF_CHARACTER_BOUNTY_HUNT(outRpcGuid) end

---@param p0 integer
---@return boolean
function BOUNTY._0x27D3A0E1FE090A43(p0) end

---@param outRpcGuid integer
---@param p1 integer
---@param p2 integer
---@return boolean
function BOUNTY._BOUNTY_REQUEST_CLAIM_CHARACTER_BOUNTY(outRpcGuid, p1, p2) end

---@param outRpcGuid integer
---@param p1 integer
---@param p2 integer
---@return boolean
function BOUNTY._BOUNTY_REQUEST_POSSE_LEADER_CLAIM_CHARACTER_BOUNTY(outRpcGuid, p1, p2) end

---@param outRpcGuid integer
---@param p1 integer
---@return boolean
function BOUNTY._BOUNTY_REQUEST_POSSE_MEMBER_CLAIM_CHARACTER_BOUNTY_SHARE(outRpcGuid, p1) end

function BOUNTY._BOUNTY_CLEAR_BEING_BOUNTY_HUNTER() end

---@param outRpcGuid integer
---@return boolean
function BOUNTY._BOUNTY_REQUEST_ESCAPED_CHARACTER_BOUNTY_HUNT(outRpcGuid) end

---@param outRpcGuid integer
---@return boolean
function BOUNTY._BOUNTY_REQUEST_POSSE_LEADER_ESCAPED_CHARACTER_BOUNTY_HUNT(outRpcGuid) end

---@param outRpcGuid integer
---@return boolean
function BOUNTY._BOUNTY_REQUEST_POSSE_MEMBER_ESCAPED_CHARACTER_BOUNTY_HUNT(outRpcGuid) end

function BOUNTY._BOUNTY_CLEAR_BEING_TARGET() end

---@param outRpcGuid integer
---@return boolean
function BOUNTY._BOUNTY_REQUEST_SERVED_FULL_JAIL_SENTENCE(outRpcGuid) end

---@param outRpcGuid integer
---@param p1 integer
---@return boolean
function BOUNTY._BOUNTY_REQUEST_BRIBE_JAIL_GUARD(outRpcGuid, p1) end

---@return integer
function BOUNTY._0xF8BCC5ECA33AC9C1() end

---@param p0 integer
---@return integer
function BOUNTY._0xD6A67E2FF373D0E3(p0) end
