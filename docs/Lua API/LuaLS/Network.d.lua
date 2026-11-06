---@meta

---@class Network
Network = {}

---@return boolean 
function Network.IsSessionStarted() end

---@param scr string|integer Script name or hash
function Network.ForceScriptHost(scr) end

-- Undocumented and untested. Do not use.
---@param bitset integer 
---@param args { [integer]: integer } An array of int args
function Network.TriggerScriptEvent(bitset, args) end
