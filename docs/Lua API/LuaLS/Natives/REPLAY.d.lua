---@meta

---@class REPLAY
REPLAY = {}

---@return boolean
function REPLAY.REPLAY_SYSTEM_HAS_REQUESTED_A_SCRIPT_CLEANUP() end

function REPLAY.SET_SCRIPTS_HAVE_CLEANED_UP_FOR_REPLAY_SYSTEM() end

---@return boolean
function REPLAY.OPEN_VIDEO_EDITOR() end

---@param p0 any
---@return boolean
function REPLAY.CLOSE_VIDEO_EDITOR(p0) end

---@return boolean
function REPLAY.IS_VIDEO_EDITOR_RUNNING() end
