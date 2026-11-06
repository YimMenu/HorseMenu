---@meta

---@class PAD
PAD = {}

---@param control integer
---@param context integer
function PAD._SET_CONTROL_CONTEXT(control, context) end

---@param control integer
---@return integer
function PAD._GET_CURRENT_CONTROL_CONTEXT(control) end

---@param action integer
---@param control integer
---@return boolean
function PAD._IS_CONTROL_ACTION_VALID(action, control) end

---@param control integer
---@param action integer
---@return boolean
function PAD.IS_CONTROL_ENABLED(control, action) end

---@param control integer
---@param action integer
---@return boolean
function PAD.IS_CONTROL_PRESSED(control, action) end

---@param control integer
---@param action integer
---@return boolean
function PAD.IS_CONTROL_RELEASED(control, action) end

---@param control integer
---@param action integer
---@return boolean
function PAD.IS_CONTROL_JUST_PRESSED(control, action) end

---@param control integer
---@param action integer
---@return boolean
function PAD.IS_CONTROL_JUST_RELEASED(control, action) end

---@param control integer
---@param action integer
---@return integer
function PAD.GET_CONTROL_VALUE(control, action) end

---@param control integer
---@param action integer
---@return number
function PAD.GET_CONTROL_NORMAL(control, action) end

---@param control integer
---@param action integer
---@return number
function PAD.GET_CONTROL_UNBOUND_NORMAL(control, action) end

---@param control integer
---@param action integer
---@param value number
---@return boolean
function PAD.SET_CONTROL_VALUE_NEXT_FRAME(control, action, value) end

---@param control integer
---@param action integer
---@return boolean
function PAD.IS_DISABLED_CONTROL_PRESSED(control, action) end

---@param control integer
---@param action integer
---@return boolean
function PAD.IS_DISABLED_CONTROL_JUST_PRESSED(control, action) end

---@param control integer
---@param action integer
---@return boolean
function PAD.IS_DISABLED_CONTROL_JUST_RELEASED(control, action) end

---@param control integer
---@param action integer
---@return number
function PAD.GET_DISABLED_CONTROL_NORMAL(control, action) end

---@param control integer
---@param action integer
---@return number
function PAD.GET_DISABLED_CONTROL_UNBOUND_NORMAL(control, action) end

---@param control integer
---@return integer
function PAD.GET_CONTROL_HOW_LONG_AGO(control) end

---@param control integer
---@return integer
function PAD._GET_DISABLED_CONTROL_HOW_LONG_AGO(control) end

---@param control integer
---@return boolean
function PAD.IS_USING_KEYBOARD_AND_MOUSE(control) end

---@param p0 any
---@param p1 any
---@return any
function PAD._0x43F35DDB2905D945(p0, p1) end

---@param p0 any
---@return any
function PAD._0xBD629C1C4F501C80(p0) end

---@param control integer
---@return boolean
function PAD.HAVE_CONTROLS_CHANGED(control) end

---@param control integer
---@param red integer
---@param green integer
---@param blue integer
function PAD.SET_CONTROL_LIGHT_EFFECT_COLOR(control, red, green, blue) end

---@param control integer
function PAD.CLEAR_CONTROL_LIGHT_EFFECT(control) end

---@param control integer
---@param red integer
---@param green integer
---@param blue integer
function PAD.SET_CONTROL_LIGHT_EFFECT_FLASHING_COLOR(control, red, green, blue) end

---@param control integer
---@param Duration integer
---@param Frequency integer
function PAD.SET_CONTROL_SHAKE(control, Duration, Frequency) end

---@param control integer
---@param leftDuration integer
---@param leftFrequency integer
---@param rightDuration integer
---@param rightFrequency integer
function PAD.SET_CONTROL_TRIGGER_SHAKE(control, leftDuration, leftFrequency, rightDuration, rightFrequency) end

---@param control integer
function PAD.STOP_CONTROL_SHAKE(control) end

---@param control integer
---@param SupressId integer
function PAD.SET_CONTROL_SHAKE_SUPPRESSED_ID(control, SupressId) end

---@param control integer
function PAD.CLEAR_CONTROL_SHAKE_SUPPRESSED_ID(control) end

---@return boolean
function PAD.IS_LOOK_INVERTED() end

---@param control integer
---@param action integer
function PAD.SET_INPUT_EXCLUSIVE(control, action) end

---@param control integer
---@param action integer
---@param disableRelatedActions boolean
function PAD.DISABLE_CONTROL_ACTION(control, action, disableRelatedActions) end

---@param control integer
---@param action integer
---@param enableRelatedActions boolean
function PAD.ENABLE_CONTROL_ACTION(control, action, enableRelatedActions) end

---@param control integer
function PAD.DISABLE_ALL_CONTROL_ACTIONS(control) end

---@param rumbleCurve any
---@param p1 number
function PAD._0x5F217BC1190503D8(rumbleCurve, p1) end

function PAD._0x709BA8C08C5C008D() end

---@return boolean
function PAD._0x1252C029FC8EBB4D() end

---@param p0 any
function PAD._0x52C68E92D6E23ADD(p0) end
