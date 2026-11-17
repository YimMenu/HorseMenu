---@meta

---@class CLOCK
CLOCK = {}

---@param h integer
---@param m integer
---@param s integer
function CLOCK.SET_CLOCK_TIME(h, m, s) end

---@param pause boolean
---@param unused any
function CLOCK.PAUSE_CLOCK(pause, unused) end

---@param toggle boolean
function CLOCK._PAUSE_CLOCK_THIS_FRAME(toggle) end

---@param h integer
---@param m integer
---@param s integer
function CLOCK.ADVANCE_CLOCK_TIME_TO(h, m, s) end

---@param h integer
---@param m integer
---@param s integer
function CLOCK.ADD_TO_CLOCK_TIME(h, m, s) end

---@return integer
function CLOCK.GET_CLOCK_HOURS() end

---@return integer
function CLOCK.GET_CLOCK_MINUTES() end

---@return integer
function CLOCK.GET_CLOCK_SECONDS() end

---@param ms integer
function CLOCK._SET_MILLISECONDS_PER_GAME_MINUTE(ms) end

---@return integer
function CLOCK._GET_SECONDS_SINCE_BASE_YEAR() end

---@param d integer
---@param m integer
---@param y integer
function CLOCK.SET_CLOCK_DATE(d, m, y) end

---@return integer
function CLOCK.GET_CLOCK_DAY_OF_WEEK() end

---@return integer
function CLOCK.GET_CLOCK_DAY_OF_MONTH() end

---@return integer
function CLOCK.GET_CLOCK_MONTH() end

---@return integer
function CLOCK.GET_CLOCK_YEAR() end

---@return integer
function CLOCK.GET_MILLISECONDS_PER_GAME_MINUTE() end

---@param year integer
---@param month integer
---@param day integer
---@param hour integer
---@param min integer
---@param sec integer
---@return integer
---@return integer
---@return integer
---@return integer
---@return integer
---@return integer
function CLOCK.GET_POSIX_TIME(year, month, day, hour, min, sec) end

---@param outTime integer
function CLOCK._GET_POSIX_TIME_STRUCT(outTime) end

---@param inDateTime integer
---@param timeToAdd integer
---@param outDateTime integer
function CLOCK._ADD_TIME_TO_DATE_TIME(inDateTime, timeToAdd, outDateTime) end
