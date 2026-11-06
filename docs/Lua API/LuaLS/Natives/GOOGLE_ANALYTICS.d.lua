---@meta

---@class GOOGLE_ANALYTICS
GOOGLE_ANALYTICS = {}

---@param pageName any
function GOOGLE_ANALYTICS._GOOGLE_ANALYTICS_PUSH_PAGE(pageName) end

---@param pageName any
function GOOGLE_ANALYTICS._GOOGLE_ANALYTICS_POP_PAGE(pageName) end

---@param eventCategory any
---@param eventAction any
---@param eventLabel any
---@param eventValue integer
---@return boolean
function GOOGLE_ANALYTICS._GOOGLE_ANALYTICS_START_EVENT(eventCategory, eventAction, eventLabel, eventValue) end

---@return boolean
function GOOGLE_ANALYTICS._GOOGLE_ANALYTICS_END_EVENT() end
