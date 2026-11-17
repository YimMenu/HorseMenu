---@meta

---@class UIFEED
UIFEED = {}

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@return integer
function UIFEED._UI_FEED_POST_HELP_TEXT(p0, p1, p2) end

---@param duration integer
---@param data integer
---@param p2 boolean
---@param p3 boolean
---@return integer
function UIFEED._UI_FEED_POST_LOCATION_SHARD(duration, data, p2, p3) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@return integer
function UIFEED._UI_FEED_POST_OBJECTIVE(p0, p1, p2) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@return integer
function UIFEED._UI_FEED_POST_FEED_TICKER(p0, p1, p2) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@param p3 boolean
---@return integer
function UIFEED._UI_FEED_POST_SAMPLE_TOAST(p0, p1, p2, p3) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@param p3 boolean
---@param collectableCategory integer
---@return integer
function UIFEED._0xAFF5BE9BA496CE40(p0, p1, p2, p3, collectableCategory) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@param p3 boolean
---@param p4 boolean
---@return integer
function UIFEED._UI_FEED_POST_SAMPLE_TOAST_WITH_APP_LINK(p0, p1, p2, p3, p4) end

---@param p0 integer
---@param p1 integer
---@param p2 integer
---@param p3 integer
---@return integer
function UIFEED._UI_FEED_POST_SAMPLE_NOTIFICATION(p0, p1, p2, p3) end

---@param p0 integer
---@param p1 integer
---@param p2 integer
---@param p3 integer
---@return integer
function UIFEED._UI_FEED_POST_RANKUP_TOAST(p0, p1, p2, p3) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@param p3 boolean
---@return integer
function UIFEED._0x18D6869FBFFEC0F8(p0, p1, p2, p3) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@return integer
function UIFEED._UI_FEED_POST_SAMPLE_TOAST_RIGHT(p0, p1, p2) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@return integer
function UIFEED._UI_FEED_POST_MISSION_NAME(p0, p1, p2) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@return integer
function UIFEED._UI_FEED_POST_RETICLE_MESSAGE(p0, p1, p2) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@return integer
function UIFEED._UI_FEED_POST_ONE_TEXT_SHARD(p0, p1, p2) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@param p3 boolean
---@return integer
function UIFEED._UI_FEED_POST_TWO_TEXT_SHARD(p0, p1, p2, p3) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@param p3 boolean
---@param p4 boolean
---@return integer
function UIFEED._UI_FEED_POST_THREE_TEXT_SHARD(p0, p1, p2, p3, p4) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@return integer
function UIFEED._UI_FEED_POST_GAME_UPDATE_SHARD(p0, p1, p2) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
---@return integer
function UIFEED._UI_FEED_POST_VOICE_CHAT_FEED(p0, p1, p2) end

---@param feedChannel integer
---@param p1 boolean
---@param p2 boolean
function UIFEED.UI_FEED_CLEAR_CHANNEL(feedChannel, p1, p2) end

function UIFEED._UI_FEED_CLEAR_ALL_CHANNELS() end

---@param feedMessage integer
---@param p1 boolean
function UIFEED._UI_FEED_CLEAR_HELP_TEXT_FEED(feedMessage, p1) end

---@param feedChannel integer
---@param p1 integer
---@param p2 boolean
function UIFEED._0x6D85126F6CCF02C9(feedChannel, p1, p2) end

---@param p0 integer
---@param p1 boolean
---@return integer
function UIFEED._0x4E88A65968A55C78(p0, p1) end

---@param p0 integer
---@param p1 boolean
---@return integer
function UIFEED._0x0FD07141AD048AAE(p0, p1) end

---@param feedMessage integer
---@return integer
function UIFEED._UI_FEED_GET_MESSAGE_STATE(feedMessage) end

---@param feedChannel integer
---@return integer
function UIFEED.UI_FEED_GET_CURRENT_MESSAGE(feedChannel) end

---@param feedChannel integer
---@return boolean
function UIFEED._0xB7223B91CD6B7E07(feedChannel) end
