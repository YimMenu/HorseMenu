---@meta

---@class UILOG
UILOG = {}

---@param p0 integer
---@param p1 integer
---@return boolean
function UILOG._UILOG_IS_ENTRY_REGISTERED(p0, p1) end

---@param p0 integer
---@param p1 integer
---@param x number
---@param y number
---@param z number
---@param p5 integer
---@param p6 integer
---@param p7 any
function UILOG._UILOG_ADD_ENTRY_HASH(p0, p1, x, y, z, p5, p6, p7) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
function UILOG._UILOG_ADD_ITEM_TO_TASK_LIST(p0, p1, p2, p3, p4, p5, p6, p7) end

---@param p0 integer
---@param p1 integer
---@param icon integer
---@param iconDictionary integer
function UILOG._UILOG_SET_ENTRY_ICON_TEXTURE(p0, p1, icon, iconDictionary) end

---@param p0 integer
---@param p1 integer
---@param texture integer
---@param textureDictionary integer
function UILOG._UILOG_SET_ENTRY_BRIEF_TEXTURE(p0, p1, texture, textureDictionary) end

---@param p0 integer
---@param p1 integer
---@param p2 any
function UILOG._UILOG_UPDATE_ENTRY_SUBHEADER(p0, p1, p2) end

---@param p0 integer
---@param p1 integer
---@param p2 boolean
function UILOG._UILOG_SET_ENTRY_PINNED(p0, p1, p2) end

---@param p0 integer
function UILOG._UILOG_MARK_MISSION_COMPLETED(p0) end

---@param p0 integer
---@param p1 integer
---@param p2 integer
---@param p3 any
function UILOG._UILOG_MARK_ENTRY_AVAILABILITY(p0, p1, p2, p3) end

---@param p0 integer
---@param p1 any
function UILOG._UILOG_MARK_ALL_ENTRIES_AVAILABILITY(p0, p1) end

---@param p0 integer
---@param p1 integer
function UILOG._UILOG_REMOVE_ENTRY(p0, p1) end

---@param logEntryType integer
---@param p1 integer
---@param p2 boolean
function UILOG._UILOG_SET_DISPLAY_COMPLETION_RATING(logEntryType, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function UILOG._0xA49D6D503E3EA847(p0, p1, p2, p3, p4) end

---@param p0 integer
---@param p1 integer
---@param p2 any
function UILOG._0x763637F9B838B0A7(p0, p1, p2) end

function UILOG._UILOG_CLEAR_ALL_ENTRIES() end

---@param p0 integer
---@param p1 integer
---@param p2 integer
---@param p3 any
---@param p4 boolean
---@param p5 boolean
---@param p6 boolean
function UILOG._UILOG_ADD_OR_UPDATE_OBJECTIVE(p0, p1, p2, p3, p4, p5, p6) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
function UILOG._0xA20398536B7F1134(p0, p1, p2, p3, p4, p5) end

---@param p0 any
function UILOG._UILOG_SET_CACHED_OBJECTIVE(p0) end

function UILOG._UILOG_CLEAR_CACHED_OBJECTIVE() end

---@return boolean
function UILOG._UILOG_HAS_DISPLAYED_CACHED_OBJECTIVE() end

function UILOG._UILOG_CLEAR_HAS_DISPLAYED_CACHED_OBJECTIVE() end

function UILOG._UILOG_SET_HAS_DISPLAYED_CACHED_OBJECTIVE() end

---@return string
function UILOG._UILOG_GET_CACHED_OBJECTIVE() end

function UILOG._UILOG_PRINT_CACHED_OBJECTIVE() end

---@param p0 integer
---@param p1 integer
---@return any
function UILOG._UILOG_SET_PENDING_DETAILS_ID(p0, p1) end

---@return any
function UILOG._0x2A4765812202E671() end

---@param p0 integer
---@param p1 integer
---@param p2 any
---@param p3 any
---@param p4 integer
function UILOG._UILOG_ADD_TOTAL_TAKE_ENTRY(p0, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
function UILOG._UILOG_SET_TOTAL_TAKE_SUMMARY(p0, p1) end

---@param data integer
---@return integer
function UILOG._UILOG_POST_NOTIFICATION(data) end

function UILOG._0xDA0A30153FCC0FFD() end
