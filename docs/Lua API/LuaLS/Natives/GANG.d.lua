---@meta

---@class GANG
GANG = {}

---@param gangId any
---@return boolean
function GANG.NETWORK_IS_GANG_ID_VALID(gangId) end

---@param gangId any
---@return boolean
function GANG.NETWORK_IS_GANG_IN_SESSION(gangId) end

---@param gangId any
---@return boolean
function GANG.NETWORK_IS_GANG_ACTIVE(gangId) end

---@param gangId any
---@return boolean
function GANG._NETWORK_IS_GANG_OPEN(gangId) end

---@return integer
function GANG._NETWORK_GET_GANG_PRIVACY() end

---@param openStatus boolean
---@param campSize integer
function GANG._NETWORK_START_GANG(openStatus, campSize) end

---@param privacyType integer
---@return boolean
function GANG._NETWORK_SET_GANG_PRIVACY(privacyType) end

---@param disband boolean
function GANG._NETWORK_LEAVE_GANG(disband) end

---@param player integer
---@param banTimeSeconds integer
function GANG._NETWORK_KICK_GANG_MEMBER(player, banTimeSeconds) end

---@param gangId any
---@return boolean
function GANG._NETWORK_REQUEST_GANG_JOIN(gangId) end

---@param player integer
---@return boolean
function GANG.NETWORK_IS_GANG_LEADER(player) end

---@param gangId any
---@param player integer
---@return boolean
function GANG._NETWORK_IS_GANG_MEMBER(gangId, player) end

---@param player1 integer
---@param player2 integer
---@return boolean
function GANG.NETWORK_IS_IN_SAME_GANG(player1, player2) end

---@param player integer
---@return boolean
function GANG._NETWORK_IS_IN_MY_GANG(player) end

---@param gangId any
---@return integer
function GANG.NETWORK_GET_NUM_GANG_MEMBERS(gangId) end

---@param gangId any
---@return integer
function GANG._NETWORK_GET_GANG_SIZE(gangId) end

---@param size integer
---@return boolean
function GANG._NETWORK_SET_GANG_SIZE(size) end

---@param player integer
---@return any
function GANG.NETWORK_GET_GANG_ID(player) end

---@param gangId any
---@param memberHandles integer
---@return integer
function GANG._NETWORK_GET_GANG_MEMBERS(gangId, memberHandles) end

---@param player integer
---@return boolean
function GANG._0xDA801F7F6A5278D3(player) end

---@param p0 any
---@return any
function GANG._0x2F7EB8B6F6AFE79C(p0) end

---@param p0 any
---@param p1 any
---@return any
function GANG._0x53A94294FDDCF98C(p0, p1) end

---@param gangId any
---@return integer
function GANG.NETWORK_GET_GANG_LEADER(gangId) end

---@param gangId any
---@param gamerHandle integer
---@return boolean
function GANG._NETWORK_GET_GANG_LEADER_HANDLE(gangId, gamerHandle) end

---@param player integer
---@return boolean
function GANG._0x6102830F764B3DE1(player) end

function GANG._0xB38C256498748413() end

---@param p0 integer
---@return any
function GANG._0xE4C64CD37CB176AA(p0) end

---@param p0 any
---@param p1 any
---@return any
function GANG._0x7BAA30C9BBE8AEE7(p0, p1) end

---@param p0 any
---@return any
function GANG._0x0E5C9FB9ED5DFF1C(p0) end

---@param p0 any
function GANG._0xB22B1D9F74095382(p0) end

function GANG._0xEE4F20004D0288B7() end

---@param p0 any
function GANG._0xAD22AB64FA428DF3(p0) end

---@param p0 any
---@return any
function GANG._0x48D82C83987E18E4(p0) end

---@param p0 any
function GANG._0xA9CEAE8D6637FBAD(p0) end

---@return any
function GANG._0x51C5EF47086AA0D7() end

---@param p0 any
---@param p1 any
---@return any
function GANG._0x644E02F24F9D4E98(p0, p1) end

---@return any
function GANG._0x3ADC71A66356D706() end

---@return any
function GANG._0xFA7C5B7E087A4CEB() end

---@param p0 any
---@param p1 any
---@return any
function GANG._0x1F11702DDBD915C6(p0, p1) end

---@param player integer
---@return any
function GANG._0x7933754F260B428A(player) end

---@return any
function GANG._0xAFD3599A3CC5637D() end

---@param p0 any
function GANG._0xC81A9E2C8EFD28D5(p0) end
