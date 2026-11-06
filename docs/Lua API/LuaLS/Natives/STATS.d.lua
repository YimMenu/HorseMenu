---@meta

---@class STATS
STATS = {}

---@param statId integer
---@return boolean
function STATS.STAT_ID_IS_VALID(statId) end

---@param statId integer
---@param value integer
---@param p2 boolean
---@return boolean
function STATS.STAT_ID_SET_INT(statId, value, p2) end

---@param statId integer
---@param value number
---@param p2 boolean
---@return boolean
function STATS.STAT_ID_SET_FLOAT(statId, value, p2) end

---@param statId integer
---@param value boolean
---@param p2 boolean
---@return boolean
function STATS.STAT_ID_SET_BOOL(statId, value, p2) end

---@param statId integer
---@param label any
---@param p2 boolean
---@return boolean
function STATS.STAT_ID_SET_GXT_LABEL(statId, label, p2) end

---@param statId integer
---@param date integer
---@param p2 boolean
---@return boolean
function STATS.STAT_ID_SET_DATE(statId, date, p2) end

---@param statId integer
---@param p1 integer
---@return boolean
---@return integer
function STATS.STAT_ID_GET_INT(statId, p1) end

---@param statId integer
---@param value number
---@return boolean
---@return number
function STATS.STAT_ID_GET_FLOAT(statId, value) end

---@param statId integer
---@param value boolean
---@return boolean
---@return boolean
function STATS.STAT_ID_GET_BOOL(statId, value) end

---@param statId integer
---@param date integer
---@return boolean
function STATS.STAT_ID_GET_DATE(statId, date) end

---@param statId integer
function STATS._0x0FEE2561120F3333(statId) end

---@param statId integer
---@param value integer
function STATS._STAT_ID_INCREMENT_INT(statId, value) end

---@param statId integer
---@param value number
function STATS._STAT_ID_INCREMENT_FLOAT(statId, value) end

---@param statId integer
---@param value integer
function STATS._STAT_ID_DECREMENT_INT(statId, value) end

---@param statId integer
---@param value integer
function STATS._0x91A4F58E01ED5E4C(statId, value) end

---@param statId integer
---@param value number
function STATS._0xE141F6B40B1E3683(statId, value) end

---@param statId integer
function STATS.STAT_ID_SET_TO_POSSE_ID(statId) end

---@param value integer
---@return integer
function STATS._STAT_CALCULATE_COOLDOWN(value) end

---@param entity integer
---@param statId integer
---@return boolean
function STATS._STAT_PHEROMONE_COOLDOWN_LEGENDARY_ANIMAL(entity, statId) end

---@param fish integer
---@param weight number
---@param category integer
---@param subcategory integer
function STATS._STAT_ITEM_FISH_CAUGHT(fish, weight, category, subcategory) end

---@param ped integer
function STATS._STAT_CARRIED_SATCHEL_ITEM_FROM_PED(ped) end

---@param item integer
---@param slot integer
---@param p2 any
---@param p3 any
function STATS._STAT_DONATE_INCREMENT_ITEM(item, slot, p2, p3) end

---@param animalType integer
function STATS._0x8312F09C56149A8A(animalType) end

---@param p0 integer
function STATS._0x378D3B1B11D9385B(p0) end

---@param p0 integer
function STATS._0xDA26263C07CCE9C2(p0) end

---@param ped integer
---@param animalType integer
function STATS._0xD64DBC8B0424135F(ped, animalType) end

---@param p0 any
---@param p1 boolean
---@param p2 boolean
---@param p3 boolean
function STATS._0xA59590050F80FF2E(p0, p1, p2, p3) end

---@param animalType integer
function STATS._STAT_ADD_ANIMAL_SAMPLE_TARGET(animalType) end

---@param ped integer
function STATS._0xF8181B5EF156862C(ped) end

---@param unlockHash integer
---@param ped integer
function STATS.STAT_ADD_BOUNTY_TARGET(unlockHash, ped) end

---@param p0 any
---@param ped integer
function STATS._0x8C889E4CBB4B2356(p0, ped) end

---@param entity integer
function STATS.STAT_BOUNTY_CAPTURED(entity) end

---@param ped integer
---@param p1 boolean
function STATS._0xA596890CF55B5095(ped, p1) end

---@param ped integer
function STATS.STAT_BOUNTY_ESCAPED(ped) end

---@param p0 any
---@param p1 integer
---@param p2 integer
function STATS._0xF21A5D66874FCEDD(p0, p1, p2) end

---@param statItem integer
---@param p1 integer
function STATS._0x3EB2791A1FBC8A42(statItem, p1) end

function STATS._0xDF95DF488A645CE7() end

---@param itemset integer
function STATS.STAT_PHOTOGRAPH_TAKEN(itemset) end

---@param unlockHash integer
---@param ped integer
---@param animalType integer
function STATS._0xBE66B26B6529E943(unlockHash, ped, animalType) end

---@param unlockHash integer
---@param ped1 integer
---@param ped2 integer
function STATS._0xF2B5ABDE09958689(unlockHash, ped1, ped2) end

---@param deedHash integer
function STATS.STAT_REGISTER_LEGENDARY_ANIMAL_DEED(deedHash) end

---@param statId integer
---@param p1 integer
---@param p2 integer
---@return boolean
---@return integer
function STATS._0x302E71C1D9EE75B9(statId, p1, p2) end

---@param p0 integer
---@return boolean
function STATS.STATSTRACKER_IS_INITIALIZED(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function STATS._0x6123E2832C34243D(p0, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function STATS._0xCA41E86545413B5B(p0, p1, p2, p3, p4, p5, p6) end

---@param p0 integer
---@param p1 any
function STATS.STATSTRACKER_DEED_STARTED(p0, p1) end

---@param deedType integer
---@param deedHash integer
---@param missionStatus integer
---@param data integer
function STATS._STATSTRACKER_DEED_STATUS(deedType, deedHash, missionStatus, data) end

---@param p0 any
---@param p1 integer
---@param x number
---@param y number
---@param z number
function STATS._0x99230691875FC218(p0, p1, x, y, z) end

---@param p0 integer
function STATS._0x025E98E317652CDD(p0) end

---@param p0 integer
function STATS._0xE5A680A5D8B1F687(p0) end

---@param p0 integer
---@return boolean
function STATS._0x4DAC398297981B87(p0) end

---@param chalHash integer
---@param goalHash integer
---@return boolean
function STATS.CHAL_IS_GOAL_ACTIVE(chalHash, goalHash) end

---@param chalHash integer
---@param goalHash integer
---@param disabled boolean
function STATS.CHAL_SET_GOAL_DISABLED(chalHash, goalHash, disabled) end

---@param chalHash integer
---@return integer
function STATS.CHAL_GET_NUM_RANKS_COMPLETED(chalHash) end

---@param chalHash integer
---@return integer
function STATS.CHAL_GET_MAX_RANKS(chalHash) end

---@param chalHash integer
---@param goalHash integer
---@param value integer
function STATS.CHAL_ADD_GOAL_PROGRESS_INT(chalHash, goalHash, value) end

---@param chalHash integer
---@param goalHash integer
---@param value number
function STATS.CHAL_ADD_GOAL_PROGRESS_FLOAT(chalHash, goalHash, value) end

---@param chalHash integer
---@param goalHash integer
---@param value integer
function STATS.CHAL_SET_GOAL_PROGRESS_INT(chalHash, goalHash, value) end

---@param p0 integer
---@param value integer
function STATS.CHAL_ADD_GOAL_PROGRESS_INT_BY_SCORE_ID(p0, value) end

---@param p0 integer
---@param value number
function STATS.CHAL_ADD_GOAL_PROGRESS_FLOAT_BY_SCORE_ID(p0, value) end

---@param p0 integer
---@param p1 integer
---@return boolean
function STATS.CHAL_ACHIEVEMENT_IS_COMPLETE(p0, p1) end

---@param p0 integer
---@param p1 integer
---@return integer
function STATS.CHAL_ACHIEVEMENT_GET_PROGRESS_INT(p0, p1) end

---@param chalHash integer
function STATS.CHAL_NET_START_CHAL(chalHash) end

---@param chalHash integer
function STATS.CHAL_NET_STOP_CHAL(chalHash) end

---@param chalHash integer
---@param goalHash integer
function STATS.CHAL_NET_START_GOAL(chalHash, goalHash) end

---@param chalHash integer
---@param goalHash integer
function STATS.CHAL_NET_STOP_GOAL(chalHash, goalHash) end

---@param chalHash integer
---@param goalHash integer
---@param player integer
---@return integer
function STATS._0xDDBD560745B1EE98(chalHash, goalHash, player) end

---@param p0 integer
---@param p1 integer
---@return string
function STATS._0xB112B9262EC29C20(p0, p1) end

---@param p0 integer
function STATS._0x4FCBCC0584CD08E9(p0) end

---@param p0 integer
---@return boolean
function STATS._0xCA1F0B5103936891(p0) end

---@param p0 integer
---@return integer
function STATS._0x8BA3D7B1E83EF803(p0) end

---@param missionHash integer
---@return integer
function STATS.CHAL_MISSION_GET_NUM_GOALS(missionHash) end

---@param missionHash integer
---@return integer
function STATS.CHAL_MISSION_GET_NUM_GOALS_COMPLETE(missionHash) end

---@param missionHash integer
---@param goalHash integer
---@return boolean
function STATS.CHAL_MISSION_IS_GOAL_COMPLETE(missionHash, goalHash) end

---@param missionHash integer
---@param goalHash integer
---@param value integer
function STATS.CHAL_MISSION_ADD_GOAL_PROGRESS_INT(missionHash, goalHash, value) end

---@return number
function STATS._0x9D0F5D2E1951CD84() end

function STATS._0x218F7710A139D012() end

---@return boolean
function STATS._0x3AEABAE3F3C7600C() end

---@return string
function STATS._0x3F6FD87D2030ADC6() end

---@param p0 integer
---@return any
function STATS._0xA2E2BEA4E83F6270(p0) end

---@param p0 integer
---@param p1 integer
---@param scheduleLocation integer
---@return boolean
---@return integer
function STATS._0xB5E2EDA2135E0FA1(p0, p1, scheduleLocation) end

---@param chalHash integer
---@return integer
function STATS.WEEKLY_COLLECTIBLE_GET_NUM_SETS(chalHash) end

---@param chalHash integer
---@param index integer
---@return integer
function STATS.WEEKLY_COLLECTIBLE_GET_ITEM_SET_BUY_AWARD(chalHash, index) end

---@param chalHash integer
---@param index integer
---@return integer
function STATS.WEEKLY_COLLECTIBLE_GET_ITEM_SET_LABEL(chalHash, index) end

---@param chalHash integer
---@param index integer
---@return integer
function STATS.WEEKLY_COLLECTIBLE_GET_NUM_ITEMS_IN_SET(chalHash, index) end

---@param chalHash integer
---@param setIndex integer
---@param itemIndex integer
---@param p3 integer
---@param p4 integer
---@return boolean
---@return integer
---@return integer
function STATS.WEEKLY_COLLECTIBLE_GET_ITEM_IN_SET(chalHash, setIndex, itemIndex, p3, p4) end

function STATS._0x4F2D5FA23DB992DE() end

function STATS._0x4E463A3CDEFFFE96() end
