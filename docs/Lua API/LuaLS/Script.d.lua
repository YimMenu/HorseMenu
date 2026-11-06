---@meta

---@class Script
Script = {}

-- Executes a callback in a fiber context
---@param callback function The callback to execute
function Script.RunInFiber(callback) end

-- Executes a callback in a fiber context after a delay
---@param callback function The callback to execute
---@param delay integer Delay in milliseconds.
function Script.RunInFiberAfterDelay(callback, delay) end

---@param ms integer Sleep time in milliseconds
function Script.Sleep(ms) end

---@param ms integer? Optional yield time in milliseconds
function Script.Yield(ms) end

---@param scrName string Name of the game script to check. Ex: `"aberdeenpigfarm"`
---@return boolean state
function Script.IsActive(scrName) end

---@param scrName string Name of the game script. Ex: `"net_camp_manager"`
---@param fn function Callback to execute once in the script's thread context.
function Script.RunAsScript(scrName, fn) end
