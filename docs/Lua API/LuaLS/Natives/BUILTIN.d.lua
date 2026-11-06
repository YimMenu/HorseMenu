---@meta

---@class BUILTIN
BUILTIN = {}

---@param ms integer
function BUILTIN.WAIT(ms) end

---@return integer
function BUILTIN.TIMERA() end

---@return integer
function BUILTIN.TIMERB() end

---@param value integer
function BUILTIN.SETTIMERA(value) end

---@param value integer
function BUILTIN.SETTIMERB(value) end

---@return number
function BUILTIN.TIMESTEP() end

---@param value number
---@return number
function BUILTIN.SIN(value) end

---@param value number
---@return number
function BUILTIN.COS(value) end

---@param value number
---@return number
function BUILTIN.SQRT(value) end

---@param base number
---@param exponent number
---@return number
function BUILTIN.POW(base, exponent) end

---@param value number
---@return number
function BUILTIN.LOG10(value) end

---@param VecDirectionX number
---@param VecDirectionY number
---@param VecDirectionZ number
---@return number
function BUILTIN.VMAG(VecDirectionX, VecDirectionY, VecDirectionZ) end

---@param VecDirectionX number
---@param VecDirectionY number
---@param VecDirectionZ number
---@return number
function BUILTIN.VMAG2(VecDirectionX, VecDirectionY, VecDirectionZ) end

---@param VecCoors1X number
---@param VecCoors1Y number
---@param VecCoors1Z number
---@param VecCoors2X number
---@param VecCoors2Y number
---@param VecCoors2Z number
---@return number
function BUILTIN.VDIST(VecCoors1X, VecCoors1Y, VecCoors1Z, VecCoors2X, VecCoors2Y, VecCoors2Z) end

---@param VecCoors1X number
---@param VecCoors1Y number
---@param VecCoors1Z number
---@param VecCoors2X number
---@param VecCoors2Y number
---@param VecCoors2Z number
---@return number
function BUILTIN.VDIST2(VecCoors1X, VecCoors1Y, VecCoors1Z, VecCoors2X, VecCoors2Y, VecCoors2Z) end

---@param value integer
---@param bitShift integer
---@return integer
function BUILTIN.SHIFT_LEFT(value, bitShift) end

---@param value integer
---@param bitShift integer
---@return integer
function BUILTIN.SHIFT_RIGHT(value, bitShift) end

---@param value number
---@return integer
function BUILTIN.FLOOR(value) end

---@param value number
---@return integer
function BUILTIN.CEIL(value) end

---@param value number
---@return integer
function BUILTIN.ROUND(value) end

---@param value integer
---@return number
function BUILTIN.TO_FLOAT(value) end

---@param priority integer
function BUILTIN.SET_THIS_THREAD_PRIORITY(priority) end
