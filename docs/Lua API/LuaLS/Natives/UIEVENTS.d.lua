---@meta

---@class UIEVENTS
UIEVENTS = {}

---@param hash integer
---@return boolean
function UIEVENTS.EVENTS_UI_IS_PENDING(hash) end

---@param hash integer
---@param eventData integer
---@return boolean
function UIEVENTS.EVENTS_UI_GET_MESSAGE(hash, eventData) end

---@param hash integer
---@param eventData integer
---@return boolean
function UIEVENTS.EVENTS_UI_PEEK_MESSAGE(hash, eventData) end

---@param hash integer
function UIEVENTS.EVENTS_UI_POP_MESSAGE(hash) end
