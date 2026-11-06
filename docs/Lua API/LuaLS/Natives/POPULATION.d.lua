---@meta

---@class POPULATION
POPULATION = {}

---@param popSetHash integer
---@return integer
function POPULATION.GET_NUM_MODELS_IN_POPULATION_SET(popSetHash) end

---@param popSetHash integer
---@param index integer
---@return integer
function POPULATION.GET_PED_MODEL_NAME_IN_POPULATION_SET(popSetHash, index) end

---@param popSetHash integer
---@param flags integer
---@param p2 integer
---@param p3 boolean
---@param p4 boolean
---@param x number
---@param y number
---@param z number
---@return integer
function POPULATION.GET_RANDOM_MODEL_FROM_POPULATION_SET(popSetHash, flags, p2, p3, p4, x, y, z) end

---@param volume integer
---@return integer
function POPULATION._CREATE_POPZONE_FROM_VOLUME(volume) end

---@param popZone integer
function POPULATION._DELETE_SCRIPT_POPZONE(popZone) end

---@param popZone integer
---@return boolean
function POPULATION._IS_POPZONE_VALID(popZone) end

---@param popZone integer
---@param populationSetHash integer
function POPULATION.SET_POPZONE_POPULATION_SET(popZone, populationSetHash) end

---@param popZone integer
---@param p1 integer
---@param p2 integer
function POPULATION._0x7E6BC0B94F5928F0(popZone, p1, p2) end

---@param popZone integer
---@param p1 integer
function POPULATION._0x578E2FA64E847C60(popZone, p1) end

---@param popZone integer
---@param p1 boolean
function POPULATION._0x08892122769770D5(popZone, p1) end

---@param popZone integer
---@param p1 boolean
function POPULATION._0x0F1861101C9A9944(popZone, p1) end

---@param p0 integer
---@param p1 integer
---@param priority integer
function POPULATION.SET_SPAWNER_INFO_PRIORITY(p0, p1, priority) end

---@param p0 integer
---@param p1 integer
function POPULATION.CLEAR_SPAWNER_INFO_PRIORITY(p0, p1) end

---@param p0 any
---@param p1 any
function POPULATION._0x638FCFC6042A9473(p0, p1) end

---@param volume integer
---@param includeFlags integer
---@param excludeFlags integer
---@param p3 integer
---@param p4 integer
---@param p5 integer
---@param p6 integer
function POPULATION._ADD_AMBIENT_AVOIDANCE_RESTRICTION(volume, includeFlags, excludeFlags, p3, p4, p5, p6) end

---@param volume integer
function POPULATION._REMOVE_AMBIENT_AVOIDANCE_RESTRICTION(volume) end

---@param volume integer
---@param includeFlags integer
---@param excludeFlags integer
---@param p3 integer
---@param p4 integer
---@param p5 integer
---@param p6 integer
function POPULATION._ADD_AMBIENT_SPAWN_RESTRICTION(volume, includeFlags, excludeFlags, p3, p4, p5, p6) end

---@param volume integer
function POPULATION._REMOVE_AMBIENT_SPAWN_RESTRICTION(volume) end

---@param includeFlags integer
---@param excludeFlags integer
---@param p2 integer
---@param p3 integer
---@param p4 integer
---@param volume integer
function POPULATION._0x2161278C6322F740(includeFlags, excludeFlags, p2, p3, p4, volume) end

---@param bitFlag integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function POPULATION._0xF45E46DEECF7DF6E(bitFlag, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
function POPULATION._0x8EC7CD701F872F87(p0, p1, p2, p3, p4, p5) end

---@param p0 any
function POPULATION._0xC4533E3E87125C9E(p0) end

---@param ped integer
---@param p1 integer
function POPULATION._SET_PED_SHOULD_IGNORE_AVOIDANCE_VOLUMES(ped, p1) end

---@param p0 any
---@param p1 any
function POPULATION._0xDBBF12EA7C1029B2(p0, p1) end

---@param p0 any
function POPULATION._0x247F86595D396344(p0) end

function POPULATION._0x324AB2A68AD8AEE5() end

---@param unk boolean
function POPULATION.DISABLE_AMBIENT_ROAD_POPULATION(unk) end

function POPULATION.ENABLE_AMBIENT_ROAD_POPULATION() end

---@param p0 any
---@param p1 any
---@param p2 any
function POPULATION._0x2660E7720EDC4BD0(p0, p1, p2) end

---@return integer
function POPULATION._GET_RANDOM_FISH_TYPE_FOR_LOCATION() end

---@param p0 boolean
function POPULATION._0xEC116EDB683AD479(p0) end
