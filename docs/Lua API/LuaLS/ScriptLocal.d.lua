---@meta

---@class ScriptLocal
---@overload fun(scriptName: string, index: integer): ScriptLocal
---@overload fun(scriptHash: integer, index: integer): ScriptLocal
---@operator add(integer): ScriptLocal
---@operator sub(integer): ScriptLocal
ScriptLocal = {}

---@param offset integer 
---@return ScriptLocal 
function ScriptLocal:At(offset) end

---@param offset integer 
---@param size integer 
---@return ScriptLocal 
function ScriptLocal:At(offset, size) end

---@return Pointer 
function ScriptLocal:GetPointer() end

-- Returns false if the value interpreted as integer equals zero, otherwise true.
---@return boolean 
function ScriptLocal:ReadBool() end

---@return integer 
function ScriptLocal:ReadInt() end

---@return number 
function ScriptLocal:ReadFloat() end

---@return Vector3 
function ScriptLocal:ReadVector3() end

---@param value integer 
---@return boolean success
function ScriptLocal:WriteInt(value) end

---@param value number 
---@return boolean success
function ScriptLocal:WriteFloat(value) end

---@param value Vector3 
---@return boolean success
function ScriptLocal:WriteVector3(value) end
