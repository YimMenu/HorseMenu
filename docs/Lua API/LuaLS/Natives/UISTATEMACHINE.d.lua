---@meta

---@class UISTATEMACHINE
UISTATEMACHINE = {}

---@param p0 any
---@return any
function UISTATEMACHINE._UIFLOWBLOCK_REQUEST(p0) end

---@param p0 any
function UISTATEMACHINE._UIFLOWBLOCK_RELEASE(p0) end

---@param p0 any
---@return any
function UISTATEMACHINE._UIFLOWBLOCK_IS_LOADED(p0) end

---@param p0 any
---@param p1 any
---@return any
function UISTATEMACHINE._UIFLOWBLOCK_ENTER(p0, p1) end

---@param p0 any
---@return any
function UISTATEMACHINE.UI_STATE_MACHINE_EXISTS(p0) end

---@param p0 any
---@param p1 any
---@return any
function UISTATEMACHINE.UI_STATE_MACHINE_CREATE(p0, p1) end

---@param p0 any
---@return any
function UISTATEMACHINE.UI_STATE_MACHINE_CAN_REQUEST_TRANSITION(p0) end

---@param p0 any
---@param p1 any
---@return any
function UISTATEMACHINE.UI_STATE_MACHINE_REQUEST_TRANSITION(p0, p1) end

---@param p0 any
---@param p1 any
function UISTATEMACHINE.UI_STATE_MACHINE_REQUEST_EXIT(p0, p1) end

---@param p0 integer
---@return boolean
function UISTATEMACHINE._UI_STATE_MACHINE_IS_EXITED(p0) end

---@param p0 any
function UISTATEMACHINE.UI_STATE_MACHINE_DESTROY(p0) end

---@param p0 integer
function UISTATEMACHINE.UI_STATE_MACHINE_DESTROY_AND_CLEAR(p0) end
