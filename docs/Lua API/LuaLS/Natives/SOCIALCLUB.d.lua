---@meta

---@class SOCIALCLUB
SOCIALCLUB = {}

---@return integer
function SOCIALCLUB.SC_INBOX_GET_TOTAL_NUM_MESSAGES() end

---@param msgIndex integer
---@return integer
function SOCIALCLUB.SC_INBOX_GET_MESSAGE_TYPE_AT_INDEX(msgIndex) end

---@param msgIndex integer
---@return boolean
function SOCIALCLUB.SC_INBOX_GET_MESSAGE_IS_READ_AT_INDEX(msgIndex) end

---@param msgIndex integer
---@return boolean
function SOCIALCLUB.SC_INBOX_SET_MESSAGE_AS_READ_AT_INDEX(msgIndex) end

---@param msgIndex integer
---@param name any
---@param value integer
---@return boolean
---@return integer
function SOCIALCLUB.SC_INBOX_MESSAGE_GET_DATA_INT(msgIndex, name, value) end

---@param msgIndex integer
---@param name any
---@param value string
---@return boolean
---@return string
function SOCIALCLUB.SC_INBOX_MESSAGE_GET_DATA_STRING(msgIndex, name, value) end

---@param msgIndex integer
---@return string
function SOCIALCLUB.SC_INBOX_MESSAGE_GET_RAW_TYPE_AT_INDEX(msgIndex) end

---@param valueId integer
---@param value number
---@return boolean
function SOCIALCLUB.SC_PRESENCE_ATTR_SET_FLOAT(valueId, value) end

---@param attrName any
---@param value integer
---@param p2 boolean
---@return boolean
function SOCIALCLUB.SC_PRESENCE_ATTR_SET_INT_EX(attrName, value, p2) end

---@param attrName any
---@param value number
---@param p2 boolean
---@return boolean
function SOCIALCLUB.SC_PRESENCE_ATTR_SET_FLOAT_EX(attrName, value, p2) end

---@param attrName any
---@param value any
---@param p2 boolean
---@return boolean
function SOCIALCLUB.SC_PRESENCE_ATTR_SET_STRING_EX(attrName, value, p2) end

---@param textString any
---@param outToken integer
---@return boolean
---@return integer
function SOCIALCLUB.SC_PROFANITY_CHECK_STRING(textString, outToken) end

---@param token integer
---@return boolean
function SOCIALCLUB.SC_PROFANITY_GET_CHECK_IS_VALID(token) end

---@param token integer
---@return boolean
function SOCIALCLUB.SC_PROFANITY_GET_CHECK_IS_PENDING(token) end

---@param token integer
---@return boolean
function SOCIALCLUB.SC_PROFANITY_GET_STRING_PASSED(token) end

---@param token integer
---@return integer
function SOCIALCLUB.SC_PROFANITY_GET_STRING_STATUS(token) end

---@return boolean
function SOCIALCLUB.SC_COMMUNITY_EVENT_IS_ACTIVE() end

---@return integer
function SOCIALCLUB.SC_COMMUNITY_EVENT_GET_EVENT_ID() end

---@param name any
---@param value integer
---@return boolean
---@return integer
function SOCIALCLUB.SC_COMMUNITY_EVENT_GET_EXTRA_DATA_INT(name, value) end

---@param name any
---@param value number
---@return boolean
---@return number
function SOCIALCLUB.SC_COMMUNITY_EVENT_GET_EXTRA_DATA_FLOAT(name, value) end

---@param name any
---@param value string
---@return boolean
---@return string
function SOCIALCLUB.SC_COMMUNITY_EVENT_GET_EXTRA_DATA_STRING(name, value) end

---@param value string
---@return boolean
---@return string
function SOCIALCLUB.SC_COMMUNITY_EVENT_GET_DISPLAY_NAME(value) end

---@param eventType any
---@return boolean
function SOCIALCLUB.SC_COMMUNITY_EVENT_IS_ACTIVE_FOR_TYPE(eventType) end

---@param eventType any
---@return integer
function SOCIALCLUB.SC_COMMUNITY_EVENT_GET_EVENT_ID_FOR_TYPE(eventType) end

---@param name any
---@param value integer
---@param eventType any
---@return boolean
---@return integer
function SOCIALCLUB.SC_COMMUNITY_EVENT_GET_EXTRA_DATA_INT_FOR_TYPE(name, value, eventType) end

---@param name any
---@param value number
---@param eventType any
---@return boolean
---@return number
function SOCIALCLUB.SC_COMMUNITY_EVENT_GET_EXTRA_DATA_FLOAT_FOR_TYPE(name, value, eventType) end

---@param name any
---@param value string
---@param eventType any
---@return boolean
---@return string
function SOCIALCLUB.SC_COMMUNITY_EVENT_GET_EXTRA_DATA_STRING_FOR_TYPE(name, value, eventType) end

---@param value string
---@param p1 any
---@return boolean
---@return string
function SOCIALCLUB.SC_COMMUNITY_EVENT_GET_DISPLAY_NAME_FOR_TYPE(value, p1) end

---@param eventId integer
---@return boolean
function SOCIALCLUB.SC_COMMUNITY_EVENT_IS_ACTIVE_BY_ID(eventId) end

---@param eventId integer
---@param name any
---@param value integer
---@return boolean
---@return integer
function SOCIALCLUB.SC_COMMUNITY_EVENT_GET_EXTRA_DATA_INT_BY_ID(eventId, name, value) end

---@param eventId integer
---@param name any
---@param value number
---@return boolean
---@return number
function SOCIALCLUB.SC_COMMUNITY_EVENT_GET_EXTRA_DATA_FLOAT_BY_ID(eventId, name, value) end

---@param eventId integer
---@param name any
---@param value string
---@return boolean
---@return string
function SOCIALCLUB.SC_COMMUNITY_EVENT_GET_EXTRA_DATA_STRING_BY_ID(eventId, name, value) end

---@param eventID integer
---@param value string
---@return boolean
---@return string
function SOCIALCLUB.SC_COMMUNITY_EVENT_GET_DISPLAY_NAME_BY_ID(eventID, value) end
