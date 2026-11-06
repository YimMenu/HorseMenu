---@meta

---@class INTERACTION
INTERACTION = {}

function INTERACTION.SET_MOUSE_CURSOR_THIS_FRAME() end

---@param style integer
function INTERACTION.SET_MOUSE_CURSOR_STYLE(style) end

function INTERACTION._SET_ALLOW_FIRST_PERSON_MOUSE_CAMERA_MOVEMENT() end

---@return boolean
function INTERACTION._POINTER_IS_BEING_MOVED() end

---@return boolean
function INTERACTION._POINTER_IS_LEFT_BUTTON_HELD() end

---@return boolean
function INTERACTION._POINTER_IS_LEFT_BUTTON_JUST_RELEASED() end
