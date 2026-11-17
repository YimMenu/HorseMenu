---@meta

---@class BRAIN
BRAIN = {}

---@param pScriptName any
---@param ObjectModelHashKey integer
---@param PercentageChance integer
---@param fActivationRange number
---@param ObjectGroupingID integer
---@param SetToWhichThisBrainBelongs integer
function BRAIN.REGISTER_OBJECT_SCRIPT_BRAIN(pScriptName, ObjectModelHashKey, PercentageChance, fActivationRange, ObjectGroupingID, SetToWhichThisBrainBelongs) end

---@param entity integer
---@param scriptName any
---@param scriptStackSize integer
---@param p3 boolean
---@return integer
function BRAIN._START_PRELOADED_SCRIPT_BRAIN(entity, scriptName, scriptStackSize, p3) end

---@param entity integer
---@param scriptName any
---@param p2 integer
---@param p3 integer
---@param p4 integer
---@param p5 boolean
---@return integer
function BRAIN._START_SCRIPT_BRAIN(entity, scriptName, p2, p3, p4, p5) end

---@param entity integer
function BRAIN._REMOVE_SCRIPT_BRAIN_ENTITY(entity) end

---@return integer
function BRAIN._GET_SCRIPT_BRAIN_ENTITY() end

---@param flag integer
function BRAIN._0xA6AC35DB4A7957A8(flag) end

---@param flag integer
function BRAIN._0x4AA5EA1EDFB25786(flag) end

---@param set integer
function BRAIN.ENABLE_SCRIPT_BRAIN_SET(set) end

---@param set integer
function BRAIN.DISABLE_SCRIPT_BRAIN_SET(set) end

function BRAIN.REACTIVATE_ALL_OBJECT_BRAINS_THAT_ARE_WAITING_TILL_OUT_OF_RANGE() end

---@param pScriptName any
function BRAIN.REACTIVATE_NAMED_OBJECT_BRAINS_WAITING_TILL_OUT_OF_RANGE(pScriptName) end
