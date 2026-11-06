---@meta

---@class COMPENDIUM
COMPENDIUM = {}

---@param category integer
---@return number
function COMPENDIUM._0x725D52F21A5E9E22(category) end

---@param category integer
---@return integer
function COMPENDIUM._COMPENDIUM_GET_NUM_OF_ENTRIES_IN_CATEGORY(category) end

---@param category integer
---@return integer
function COMPENDIUM._0x729D52461AEA9E22(category) end

---@param ped integer
---@return integer
function COMPENDIUM.COMPENDIUM_GET_SHORT_DESCRIPTION_FROM_PED(ped) end

---@param category integer
---@param ped integer
---@return integer
function COMPENDIUM.COMPENDIUM_GET_SUBCATEGORY_PED_IS_IN(category, ped) end

---@param category integer
---@param animalType integer
---@return integer
function COMPENDIUM._COMPENDIUM_GET_SUBCATEGORY_HASH_FROM_ANIMAL_TYPE(category, animalType) end

---@param category integer
---@param subcategory integer
---@return integer
function COMPENDIUM.COMPENDIUM_GET_NUM_ENTRIES_IN_SUBCATEGORY(category, subcategory) end

---@param category integer
---@param subcategory integer
---@param count integer
---@return integer
function COMPENDIUM.COMPENDIUM_GET_ENTRY_BY_INDEX_IN_SUBCATEGORY(category, subcategory, count) end

---@param category integer
---@param ped integer
---@return integer
function COMPENDIUM.COMPENDIUM_GET_ENTRY_BY_PED_INDEX(category, ped) end

---@param category integer
---@param animalType integer
---@return integer
function COMPENDIUM.COMPENDIUM_GET_ENTRY_BY_STAT_ITEM(category, animalType) end

---@param category integer
---@param subcategory integer
---@return any
function COMPENDIUM.COMPENDIUM_GET_SUBCATEGORY_TOAST_APP_ID(category, subcategory) end

---@param animalStatItem integer
---@param x number
---@param y number
---@param z number
---@return integer
function COMPENDIUM.COMPENDIUM_GET_MAP_DISCOVERABLE_FROM_STAT_ITEM(animalStatItem, x, y, z) end

---@param animalType integer
---@param disableCompendiumToast boolean
function COMPENDIUM.COMPENDIUM_ANIMAL_OBSERVED_BY_STAT_NAME(animalType, disableCompendiumToast) end

---@param ped integer
---@return boolean
function COMPENDIUM.COMPENDIUM_WAS_ANIMAL_OBSERVED(ped) end

---@param compendiumEntry integer
function COMPENDIUM.COMPENDIUM_ANIMAL_SET_DISCOVERED(compendiumEntry) end

---@param ped integer
---@return any
function COMPENDIUM.COMPENDIUM_GET_STUDY_AWARD_ID(ped) end

---@param compendiumEntry integer
---@return any
function COMPENDIUM.COMPENDIUM_ANIMAL_GET_SAMPLE_INVENTORY_ITEM(compendiumEntry) end

---@param compendiumEntry integer
---@return boolean
function COMPENDIUM.COMPENDIUM_ANIMAL_HAS_SAMPLE(compendiumEntry) end

---@param compendiumEntry integer
---@return boolean
function COMPENDIUM.COMPENDIUM_ANIMAL_HAS_STAMP(compendiumEntry) end

---@param category integer
---@param subcategory integer
---@return string
function COMPENDIUM.COMPENDIUM_GET_SUBCATEGORY_SAMPLE_TOAST_TITLE(category, subcategory) end

---@param category integer
---@param subcategory integer
---@return string
function COMPENDIUM.COMPENDIUM_GET_SUBCATEGORY_SAMPLE_TOAST_DESC_PROGRESS(category, subcategory) end

---@param category integer
---@param subcategory integer
---@return string
function COMPENDIUM.COMPENDIUM_GET_SUBCATEGORY_SAMPLE_TOAST_DESC_COMPLETE(category, subcategory) end

---@param ped integer
---@param category integer
function COMPENDIUM.COMPENDIUM_FISH_CAUGHT(ped, category) end

---@param animalType integer
---@param baitType integer
---@return integer
function COMPENDIUM.COMPENDIUM_FISH_GET_LURE_SUITABILITY_BY_STAT_ITEM(animalType, baitType) end

---@param p0 any
---@param p1 any
function COMPENDIUM.COMPENDIUM_GANG_CAMP_FOUND(p0, p1) end

---@param p0 any
function COMPENDIUM.COMPENDIUM_GANG_AMBUSH_SURVIVED(p0) end

---@param p0 any
function COMPENDIUM.COMPENDIUM_GANG_ENCOUNTERED(p0) end

---@param p0 any
function COMPENDIUM.COMPENDIUM_GANG_BOUNTY_CAPTURED(p0) end

---@param p0 any
function COMPENDIUM.COMPENDIUM_GANG_MEMBER_KILLED(p0) end

---@param p0 any
---@param p1 any
function COMPENDIUM.COMPENDIUM_GANG_HIDEOUT_FOUND(p0, p1) end

---@param herbType integer
---@param x number
---@param y number
---@param z number
function COMPENDIUM.COMPENDIUM_HERB_PICKED(herbType, x, y, z) end

---@param ped integer
---@param bondingLevel integer
function COMPENDIUM.COMPENDIUM_HORSE_BONDING(ped, bondingLevel) end

---@param ped integer
function COMPENDIUM.COMPENDIUM_HORSE_WILD_BROKEN(ped) end

---@param ped integer
---@param disableCompendiumToast boolean
function COMPENDIUM.COMPENDIUM_HORSE_OBSERVED(ped, disableCompendiumToast) end
