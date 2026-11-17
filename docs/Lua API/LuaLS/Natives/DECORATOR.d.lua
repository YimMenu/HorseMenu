---@meta

---@class DECORATOR
DECORATOR = {}

---@param guid integer
---@param decoratorName any
---@param value boolean
---@return boolean
function DECORATOR.DECOR_SET_BOOL(guid, decoratorName, value) end

---@param guid integer
---@param decoratorName any
---@param value number
---@return boolean
function DECORATOR.DECOR_SET_FLOAT(guid, decoratorName, value) end

---@param guid integer
---@param decoratorName any
---@param value integer
---@return boolean
function DECORATOR.DECOR_SET_INT(guid, decoratorName, value) end

---@param entity integer
---@param propertyName any
---@param value integer
---@return boolean
function DECORATOR._DECOR_SET_UINT8(entity, propertyName, value) end

---@param entity integer
---@param propertyName any
---@param value any
---@return boolean
function DECORATOR.DECOR_SET_STRING(entity, propertyName, value) end

---@param guid integer
---@param decoratorName any
---@return boolean
function DECORATOR.DECOR_GET_BOOL(guid, decoratorName) end

---@param guid integer
---@param decoratorName any
---@return number
function DECORATOR.DECOR_GET_FLOAT(guid, decoratorName) end

---@param guid integer
---@param decoratorName any
---@return integer
function DECORATOR.DECOR_GET_INT(guid, decoratorName) end

---@param entity integer
---@param propertyName any
---@return integer
function DECORATOR._DECOR_GET_UINT8(entity, propertyName) end

---@param guid integer
---@param decoratorName any
---@return boolean
function DECORATOR.DECOR_EXIST_ON(guid, decoratorName) end

---@param guid integer
---@param decoratorName any
---@return boolean
function DECORATOR.DECOR_REMOVE(guid, decoratorName) end

---@param entity integer
---@return boolean
function DECORATOR.DECOR_REMOVE_ALL(entity) end

---@param decoratorName any
---@param type integer
function DECORATOR.DECOR_REGISTER(decoratorName, type) end

---@param propertyName any
---@param type integer
---@param p2 boolean
function DECORATOR._DECOR_REGISTER_2(propertyName, type, p2) end

---@param decoratorName any
---@param type integer
---@return boolean
function DECORATOR.DECOR_IS_REGISTERED_AS_TYPE(decoratorName, type) end
