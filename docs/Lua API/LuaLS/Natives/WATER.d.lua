---@meta

---@class WATER
WATER = {}

function WATER.DISABLE_WATER_LOOKUP() end

function WATER.ENABLE_WATER_LOOKUP() end

---@param PosX number
---@param PosY number
---@param PosZ number
---@param Height number
---@return boolean
---@return number
function WATER.GET_WATER_HEIGHT(PosX, PosY, PosZ, Height) end

---@param PosX number
---@param PosY number
---@param PosZ number
---@param Height number
---@return boolean
---@return number
function WATER.GET_WATER_HEIGHT_NO_WAVES(PosX, PosY, PosZ, Height) end

---@param StartPosX number
---@param StartPosY number
---@param StartPosZ number
---@param EndPosX number
---@param EndPosY number
---@param EndPosZ number
---@param BlockingFlags integer
---@param IntersectionPos Vector3
---@return integer
---@return Vector3
function WATER.TEST_PROBE_AGAINST_ALL_WATER(StartPosX, StartPosY, StartPosZ, EndPosX, EndPosY, EndPosZ, BlockingFlags, IntersectionPos) end

---@param StartPosX number
---@param StartPosY number
---@param StartPosZ number
---@param BlockingFlags integer
---@param Height number
---@return integer
---@return number
function WATER.TEST_VERTICAL_PROBE_AGAINST_ALL_WATER(StartPosX, StartPosY, StartPosZ, BlockingFlags, Height) end

---@param Idx integer
function WATER.REMOVE_EXTRA_CALMING_QUAD(Idx) end

---@param p0 integer
function WATER._0x09A1C7DFDCE54FBC(p0) end

---@param ped integer
function WATER._0xF0FBF193F1F5C0EA(ped) end

function WATER._0xA33F5069B0CB89B8() end

---@param entity integer
function WATER._0xB34A6009A0DB80B8(entity) end

---@param wavesHeight number
---@param p1 number
---@param p2 integer
---@param p3 number
---@param p4 number
---@param p5 number
---@param p6 number
---@param wavesStrength number
---@param p8 integer
function WATER._SET_OCEAN_GUARMA_WATER_QUADRANT(wavesHeight, p1, p2, p3, p4, p5, p6, wavesStrength, p8) end

function WATER._RESET_GUARMA_WATER_STATE() end

---@param waterType integer
function WATER._SET_WORLD_WATER_TYPE(waterType) end

---@return integer
function WATER._GET_WORLD_WATER_TYPE() end

---@param entity integer
---@param p1 integer
function WATER._0x0DCEC6A92E497E17(entity, p1) end

function WATER._0xE8126623008372AA() end
