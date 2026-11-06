---@meta

---@class ScriptGlobal
---@overload fun(index: integer): ScriptGlobal
---@operator add(integer): ScriptGlobal
---@operator sub(integer): ScriptGlobal
ScriptGlobal = {}

---@param muliplayer boolean? 
---@return boolean 
function ScriptGlobal:CanAccess(muliplayer) end

---@param offset integer 
---@return ScriptGlobal 
function ScriptGlobal:At(offset) end

---@param offset integer 
---@param size integer 
---@return ScriptGlobal 
function ScriptGlobal:At(offset, size) end

---@return Pointer 
function ScriptGlobal:GetPointer() end

---@return string 
function ScriptGlobal:ReadString() end

-- Returns false if the value interpreted as integer equals zero, otherwise true.
---@return boolean 
function ScriptGlobal:ReadBool() end

---@return integer 
function ScriptGlobal:ReadInt() end

---@return number 
function ScriptGlobal:ReadFloat() end

---@return Vector3 
function ScriptGlobal:ReadVector3() end

---@param value string 
---@param maxLength integer? Optional maximum length. If provided and the string's size is less than this value, the difference will be padded with null terminators.
---@return boolean success
function ScriptGlobal:WriteString(value, maxLength) end

---@param value integer 
---@return boolean success
function ScriptGlobal:WriteInt(value) end

---@param value number 
---@return boolean success
function ScriptGlobal:WriteFloat(value) end

---@param value Vector3 
---@return boolean success
function ScriptGlobal:WriteVector3(value) end
