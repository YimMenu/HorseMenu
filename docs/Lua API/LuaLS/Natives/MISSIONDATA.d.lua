---@meta

---@class MISSIONDATA
MISSIONDATA = {}

---@param p0 any
---@return boolean
function MISSIONDATA.MISSIONDATA_IS_VALID(p0) end

---@param missionId integer
---@return integer
function MISSIONDATA.MISSIONDATA_GET_CATAGORY(missionId) end

---@param missionId integer
---@return integer
function MISSIONDATA.MISSIONDATA_GET_TEXTURE_NAME(missionId) end

---@param missionId integer
---@return integer
function MISSIONDATA.MISSIONDATA_GET_TEXTURE_TXD(missionId) end

---@param missionId integer
---@return boolean
function MISSIONDATA.MISSIONDATA_WAS_COMPLETED(missionId) end

---@param missionId integer
---@return integer
function MISSIONDATA.MISSIONDATA_GET_RATING(missionId) end

---@param missionId integer
---@param rating integer
function MISSIONDATA._MISSIONDATA_SET_MISSION_RATING(missionId, rating) end

---@param missionId integer
---@return boolean
function MISSIONDATA.MISSIONDATA_IS_REQUIRED_STORY_MISSION(missionId) end

---@param missionId integer
---@param replayState integer
function MISSIONDATA._MISSIONDATA_SET_REPLAY_STATE_LOCKED(missionId, replayState) end

---@param p0 any
---@return integer
function MISSIONDATA.MISSIONDATA_GET_REPLAY_STATE(p0) end

---@param missionId integer
---@param bronzeScore integer
---@param silverScore integer
---@param goldScore integer
function MISSIONDATA.MISSIONDATA_SET_RATING_SCORES(missionId, bronzeScore, silverScore, goldScore) end

---@param missionId integer
---@param score integer
function MISSIONDATA.MISSIONDATA_SET_HIGH_SCORE(missionId, score) end

---@param missionId integer
---@return integer
function MISSIONDATA.MISSIONDATA_GET_HIGH_SCORE(missionId) end

---@param category integer
---@return boolean
function MISSIONDATA._MISSIONDATA_IS_REPLAY_CATEGORY_LOCKED(category) end

---@param category integer
---@param locked boolean
function MISSIONDATA.MISSIONDATA_SET_REPLAY_LOCKED_FOR_CATEGORY(category, locked) end

---@param timecycleName any
function MISSIONDATA._MISSIONDATA_TIMECYCLE_BOX_SET_MODIFIER(timecycleName) end

function MISSIONDATA._MISSIONDATA_TIMECYCLE_BOX_DELETE() end

---@return boolean
function MISSIONDATA._MISSIONDATA_TIMECYCLE_BOX_EXISTS() end
