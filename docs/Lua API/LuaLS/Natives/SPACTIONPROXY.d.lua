---@meta

---@class SPACTIONPROXY
SPACTIONPROXY = {}

---@return boolean
function SPACTIONPROXY._SPACTIONPROXY_START_MANAGER() end

---@return boolean
function SPACTIONPROXY._SPACTIONPROXY_MANAGER_IS_READY() end

---@return boolean
function SPACTIONPROXY._SPACTIONPROXY_MANAGER_IS_FAILED() end

---@param data integer
---@return boolean
function SPACTIONPROXY._SPACTIONPROXY_GET_NEXT_PENDING_CRAFTING_ACTION(data) end

---@param data integer
---@return boolean
function SPACTIONPROXY._SPACTIONPROXY_GET_NEXT_PENDING_BUY_ACTION(data) end

---@param p0 any
---@param p1 boolean
---@return boolean
function SPACTIONPROXY._SPACTIONPROXY_PROCESS_ACTION(p0, p1) end
