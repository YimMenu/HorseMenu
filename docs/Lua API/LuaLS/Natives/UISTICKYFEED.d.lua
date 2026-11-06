---@meta

---@class UISTICKYFEED
UISTICKYFEED = {}

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@return integer
function UISTICKYFEED._UI_STICKY_FEED_CREATE_ERROR_MESSAGE(p0, p1, p2) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@return integer
function UISTICKYFEED._UI_STICKY_FEED_CREATE_DEATH_FAIL_MESSAGE(p0, p1, p2) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@return integer
function UISTICKYFEED._UI_STICKY_FEED_CREATE_WARNING_MESSAGE(p0, p1, p2) end

---@param msgId integer
---@param p1 integer
---@param p2 boolean
function UISTICKYFEED._UI_STICKY_FEED_UPDATE_MESSAGE(msgId, p1, p2) end

---@param msgId integer
function UISTICKYFEED._UI_STICKY_FEED_CLEAR_MESSAGE(msgId) end

---@param stickyFeedChannel integer
---@return boolean
function UISTICKYFEED._UI_STICKY_FEED_IS_CHANNEL_ACTIVE(stickyFeedChannel) end

---@return boolean
function UISTICKYFEED._UI_STICKY_FEED_IS_ALERT_SCREEN_ACTIVE() end

---@param msgId integer
---@return integer
function UISTICKYFEED._UI_STICKY_FEED_GET_MESSAGE_STATE(msgId) end
