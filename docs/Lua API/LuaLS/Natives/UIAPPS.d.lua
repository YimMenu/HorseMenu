---@meta

---@class UIAPPS
UIAPPS = {}

---@param appNameHash integer
---@return boolean
function UIAPPS.IS_UIAPP_ACTIVE_BY_HASH(appNameHash) end

---@return boolean
function UIAPPS.IS_ANY_UIAPP_ACTIVE() end

---@param appNameHash integer
---@return boolean
function UIAPPS.IS_UIAPP_RUNNING_BY_HASH(appNameHash) end

---@param appName any
---@return boolean
function UIAPPS.IS_UIAPP_RUNNING(appName) end

---@return boolean
function UIAPPS.IS_ANY_UIAPP_RUNNING() end

---@param appNameHash integer
---@return integer
function UIAPPS._GET_UIAPP_CURRENT_ACTIVITY_BY_HASH(appNameHash) end

---@param appNameHash integer
function UIAPPS._CLOSE_UIAPP_BY_HASH(appNameHash) end

---@param appNameHash integer
function UIAPPS._CLOSE_UIAPP_BY_HASH_IMMEDIATE(appNameHash) end

---@param appName any
function UIAPPS._CLOSE_UIAPP(appName) end

---@param appName any
function UIAPPS._CLOSE_UIAPP_IMMEDIATE(appName) end

function UIAPPS._CLOSE_ALL_UIAPPS() end

function UIAPPS._CLOSE_ALL_UIAPPS_IMMEDIATE() end

---@param appNameHash integer
---@param entryHash integer
---@return integer
function UIAPPS.LAUNCH_UIAPP_BY_HASH_WITH_ENTRY(appNameHash, entryHash) end

---@param appNameHash integer
---@return integer
function UIAPPS.LAUNCH_UIAPP_BY_HASH(appNameHash) end

---@param appName any
---@param entry any
---@return integer
function UIAPPS.LAUNCH_UIAPP_WITH_ENTRY(appName, entry) end

---@param appNameHash integer
---@param entryHash integer
---@return boolean
function UIAPPS.CAN_LAUNCH_UIAPP_BY_HASH_WITH_ENTRY(appNameHash, entryHash) end

---@param appNameHash integer
---@return boolean
function UIAPPS.CAN_LAUNCH_UIAPP_BY_HASH(appNameHash) end

---@param appNameHash integer
---@param transitionHash integer
---@return boolean
function UIAPPS.REQUEST_UIAPP_TRANSITION_BY_HASH(appNameHash, transitionHash) end

---@param appNameHash integer
---@return boolean
function UIAPPS.IS_UIAPP_TRANSITIONING_BY_HASH(appNameHash) end
