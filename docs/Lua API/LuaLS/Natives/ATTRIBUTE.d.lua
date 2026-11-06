---@meta

---@class ATTRIBUTE
ATTRIBUTE = {}

---@param ped integer
---@param attributeIndex integer
---@param newValue integer
function ATTRIBUTE.SET_ATTRIBUTE_BASE_RANK(ped, attributeIndex, newValue) end

---@param ped integer
---@param attributeIndex integer
---@return integer
function ATTRIBUTE.GET_ATTRIBUTE_RANK(ped, attributeIndex) end

---@param ped integer
---@param attributeIndex integer
---@return integer
function ATTRIBUTE.GET_ATTRIBUTE_BASE_RANK(ped, attributeIndex) end

---@param ped integer
---@param coreIndex integer
---@return integer
function ATTRIBUTE.GET_ATTRIBUTE_BONUS_RANK(ped, coreIndex) end

---@param ped integer
---@param attributeIndex integer
---@return integer
function ATTRIBUTE.GET_MAX_ATTRIBUTE_RANK(ped, attributeIndex) end

---@param ped integer
---@param attributeIndex integer
---@param newValue integer
function ATTRIBUTE.SET_ATTRIBUTE_BONUS_RANK(ped, attributeIndex, newValue) end

---@param ped integer
---@param attributeIndex integer
---@return integer
function ATTRIBUTE.GET_DEFAULT_ATTRIBUTE_RANK(ped, attributeIndex) end

---@param ped integer
---@param attributeIndex integer
---@return integer
function ATTRIBUTE.GET_DEFAULT_MAX_ATTRIBUTE_RANK(ped, attributeIndex) end

---@param ped integer
---@param attributeIndex integer
---@param p2 integer
function ATTRIBUTE.ADD_ATTRIBUTE_POINTS(ped, attributeIndex, p2) end

---@param ped integer
---@param attributeIndex integer
---@param p2 integer
function ATTRIBUTE.SET_ATTRIBUTE_POINTS(ped, attributeIndex, p2) end

---@param ped integer
---@param attributeIndex integer
---@return integer
function ATTRIBUTE.GET_ATTRIBUTE_POINTS(ped, attributeIndex) end

---@param ped integer
---@param attributeIndex integer
---@return integer
function ATTRIBUTE.GET_MAX_ATTRIBUTE_POINTS(ped, attributeIndex) end

---@param ped integer
---@param coreIndex integer
---@param value integer
function ATTRIBUTE._SET_ATTRIBUTE_CORE_VALUE(ped, coreIndex, value) end

---@param ped integer
---@param coreIndex integer
---@return integer
function ATTRIBUTE._GET_ATTRIBUTE_CORE_VALUE(ped, coreIndex) end

---@param modelHash integer
---@param attributeIndex integer
---@param rank integer
---@return integer
function ATTRIBUTE.GET_DEFAULT_ATTRIBUTE_POINTS_NEEDED_FOR_RANK(modelHash, attributeIndex, rank) end

---@param ped integer
---@param attributeIndex integer
---@param value number
---@param makeSound boolean
function ATTRIBUTE.ENABLE_ATTRIBUTE_OVERPOWER(ped, attributeIndex, value, makeSound) end

---@param ped integer
---@param coreIndex integer
---@param value number
---@param makeSound boolean
function ATTRIBUTE._ENABLE_ATTRIBUTE_CORE_OVERPOWER(ped, coreIndex, value, makeSound) end

---@param ped integer
---@param attributeIndex integer
function ATTRIBUTE.DISABLE_ATTRIBUTE_OVERPOWER(ped, attributeIndex) end

---@param ped integer
---@param attributeIndex integer
---@return boolean
function ATTRIBUTE._IS_ATTRIBUTE_OVERPOWERED(ped, attributeIndex) end

---@param ped integer
---@param coreIndex integer
---@return boolean
function ATTRIBUTE._IS_ATTRIBUTE_CORE_OVERPOWERED(ped, coreIndex) end

---@param ped integer
---@param attributeIndex integer
---@return number
function ATTRIBUTE._GET_ATTRIBUTE_OVERPOWER_SECONDS_LEFT(ped, attributeIndex) end

---@param ped integer
---@param coreIndex integer
---@return number
function ATTRIBUTE._GET_ATTRIBUTE_CORE_OVERPOWER_SECONDS_LEFT(ped, coreIndex) end

---@param p0 any
---@param p1 integer
function ATTRIBUTE._START_ITEM_PREVIEW(p0, p1) end

function ATTRIBUTE.STOP_ITEM_PREVIEW() end

---@param statusEffectType integer
function ATTRIBUTE._SET_STATUS_EFFECT_CORE_ICON(statusEffectType) end

---@param statusEffectType integer
function ATTRIBUTE._SET_STATUS_EFFECT_PERIODIC_ICON(statusEffectType) end

---@param statusEffectType integer
function ATTRIBUTE._STOP_STATUS_EFFECT_PERIODIC_ICON(statusEffectType) end
