---@meta

---@class ITEMSET
ITEMSET = {}

---@param autoClean boolean
---@return integer
function ITEMSET.CREATE_ITEMSET(autoClean) end

---@param itemSet integer
function ITEMSET.DESTROY_ITEMSET(itemSet) end

---@param itemSet integer
---@return boolean
function ITEMSET.IS_ITEMSET_VALID(itemSet) end

---@param itemToAdd integer
---@param itemSetToAddTo integer
---@return boolean
function ITEMSET.ADD_TO_ITEMSET(itemToAdd, itemSetToAddTo) end

---@param itemToRemove integer
---@param itemSetToRemoveFrom integer
function ITEMSET.REMOVE_FROM_ITEMSET(itemToRemove, itemSetToRemoveFrom) end

---@param itemSet integer
---@return integer
function ITEMSET.GET_ITEMSET_SIZE(itemSet) end

---@param indexInSet integer
---@param itemSet integer
---@return integer
function ITEMSET.GET_INDEXED_ITEM_IN_ITEMSET(indexInSet, itemSet) end

---@param index integer
---@param itemset integer
---@return any
function ITEMSET.GET_INDEXED_SCENARIO_POINT_INDEX_IN_ITEMSET(index, itemset) end

---@param objToCheck integer
---@param itemSet integer
---@return boolean
function ITEMSET.IS_IN_ITEMSET(objToCheck, itemSet) end

---@param itemSet integer
function ITEMSET.CLEAN_ITEMSET(itemSet) end

---@param itemset integer
function ITEMSET._CLEAR_ITEMSET(itemset) end
