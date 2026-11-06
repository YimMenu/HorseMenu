---@meta

---@class UNLOCK
UNLOCK = {}

---@param unlockHash integer
---@param flag integer
---@return boolean
function UNLOCK._UNLOCK_IS_UNLOCK_FLAG_SET(unlockHash, flag) end

---@param unlockHash integer
---@return boolean
function UNLOCK.UNLOCK_IS_UNLOCKED(unlockHash) end

---@param unlockHash integer
---@param toggle boolean
function UNLOCK.UNLOCK_SET_UNLOCKED(unlockHash, toggle) end

---@param unlockHash integer
---@return boolean
function UNLOCK.UNLOCK_IS_VISIBLE(unlockHash) end

---@param unlockHash integer
---@param toggle boolean
function UNLOCK.UNLOCK_SET_VISIBLE(unlockHash, toggle) end

---@param unlockHash integer
---@return boolean
function UNLOCK._UNLOCK_IS_NEW(unlockHash) end

---@param unlockHash integer
---@param toggle boolean
function UNLOCK._UNLOCK_SET_NEW(unlockHash, toggle) end

---@param unlockHash integer
---@return boolean
function UNLOCK._UNLOCK_IS_LOOTABLE(unlockHash) end

---@param unlockHash integer
---@param outData integer
function UNLOCK._UNLOCK_GET_ITEM_ROLE_UNLOCK_INFO(unlockHash, outData) end
