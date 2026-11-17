---@meta

---@class Stats
Stats = {}

-- Returns whether the stat is valid.
---@param baseName string 
---@param permutationName string 
---@return boolean 
function Stats.IsValid(baseName, permutationName) end

-- Returns whether the stat is valid.
---@param baseHash integer JOAAT hash
---@param permutationHash integer JOAAT hash
---@return boolean 
function Stats.IsValid(baseHash, permutationHash) end

---@param baseName string 
---@param permutationName string 
---@return integer 
function Stats.GetInt(baseName, permutationName) end

---@param baseHash integer JOAAT hash
---@param permutationHash integer JOAAT hash
---@return integer 
function Stats.GetInt(baseHash, permutationHash) end

---@param baseName string 
---@param permutationName string 
---@return number 
function Stats.GetFloat(baseName, permutationName) end

---@param baseHash integer JOAAT hash
---@param permutationHash integer JOAAT hash
---@return number 
function Stats.GetFloat(baseHash, permutationHash) end

---@param baseName string 
---@param permutationName string 
---@return boolean 
function Stats.GetBool(baseName, permutationName) end

---@param baseHash integer JOAAT hash
---@param permutationHash integer JOAAT hash
---@return boolean 
function Stats.GetBool(baseHash, permutationHash) end

---@param baseName string 
---@param permutationName string 
---@param value integer 
---@param save boolean? Whether to save changes. Defaults to true.
---@return boolean success
function Stats.SetInt(baseName, permutationName, value, save) end

---@param baseHash integer JOAAT hash
---@param permutationHash integer JOAAT hash
---@param value integer 
---@param save boolean? Whether to save changes. Defaults to true.
---@return boolean success
function Stats.SetInt(baseHash, permutationHash, value, save) end

---@param baseName string 
---@param permutationName string 
---@param value number 
---@param save boolean? Whether to save changes. Defaults to true.
---@return boolean success
function Stats.SetFloat(baseName, permutationName, value, save) end

---@param baseHash integer JOAAT hash
---@param permutationHash integer JOAAT hash
---@param value number 
---@param save boolean? Whether to save changes. Defaults to true.
---@return boolean success
function Stats.SetFloat(baseHash, permutationHash, value, save) end

---@param baseName string 
---@param permutationName string 
---@param value boolean 
---@param save boolean? Whether to save changes. Defaults to true.
---@return boolean success
function Stats.SetBool(baseName, permutationName, value, save) end

---@param baseHash integer JOAAT hash
---@param permutationHash integer JOAAT hash
---@param value boolean 
---@param save boolean? Whether to save changes. Defaults to true.
---@return boolean success
function Stats.SetBool(baseHash, permutationHash, value, save) end

---@param baseName string 
---@param permutationName string 
---@param value string 
---@param save boolean? Whether to save changes. Defaults to true.
---@return boolean success
function Stats.SetString(baseName, permutationName, value, save) end

---@param baseHash integer JOAAT hash
---@param permutationHash integer JOAAT hash
---@param value string 
---@param save boolean? Whether to save changes. Defaults to true.
---@return boolean success
function Stats.SetString(baseHash, permutationHash, value, save) end

---@param baseName string 
---@param permutationName string 
---@param value integer 
function Stats.DecrementInt(baseName, permutationName, value) end

---@param baseHash integer JOAAT hash
---@param permutationHash integer JOAAT hash
---@param value integer 
function Stats.DecrementInt(baseHash, permutationHash, value) end

---@param baseName string 
---@param permutationName string 
---@param value integer 
function Stats.IncrementInt(baseName, permutationName, value) end

---@param baseHash integer JOAAT hash
---@param permutationHash integer JOAAT hash
---@param value integer 
function Stats.IncrementInt(baseHash, permutationHash, value) end

---@param baseName string 
---@param permutationName string 
---@param value number 
function Stats.IncrementFloat(baseName, permutationName, value) end

---@param baseHash integer JOAAT hash
---@param permutationHash integer JOAAT hash
---@param value number 
function Stats.IncrementFloat(baseHash, permutationHash, value) end
