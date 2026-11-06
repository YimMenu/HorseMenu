---@meta

---@class COLLECTION
COLLECTION = {}

---@param collectableItem integer
---@return integer
function COLLECTION._COLLECTABLE_GET_CATEGORY(collectableItem) end

---@param collectableItem integer
---@return integer
function COLLECTION._COLLECTABLE_GET_SUBCATEGORY(collectableItem) end

---@param collectableItem integer
---@return integer
function COLLECTION._COLLECTABLE_GET_IPL(collectableItem) end

---@param collectableItem integer
---@return Vector3
function COLLECTION._COLLECTABLE_GET_PLACEMENT_LOCATION(collectableItem) end

---@param collectableItem integer
---@return integer
function COLLECTION._COLLECTABLE_GET_NUM_FOUND(collectableItem) end

---@param collectableItem integer
---@return integer
function COLLECTION._COLLECTABLE_GET_NUM_TURNED_IN(collectableItem) end

---@param collectableItem integer
---@param amount integer
function COLLECTION._COLLECTABLE_INCREMENT_NUM_FOUND(collectableItem, amount) end

---@param collectableItem integer
---@param amount integer
function COLLECTION._COLLECTABLE_INCREMENT_NUM_TURNED_IN(collectableItem, amount) end

---@param collectableCategory integer
---@param collectableSubcategory integer
---@return integer
function COLLECTION._COLLECTABLE_CATEGORY_GET_NUM_COLLECTABLES(collectableCategory, collectableSubcategory) end

---@param index integer
---@param collectableCategory integer
---@param collectableSubcategory integer
---@return integer
function COLLECTION._COLLECTABLE_GET_COLLECTABLE_ITEM_HASH(index, collectableCategory, collectableSubcategory) end

---@param collectableCategory integer
---@param collectableSubcategory integer
---@return integer
function COLLECTION._COLLECTABLE_CATEGORY_GET_NUM_FOUND(collectableCategory, collectableSubcategory) end

---@param collectableCategory integer
---@param collectableSubcategory integer
---@return integer
function COLLECTION._COLLECTABLE_CATEGORY_GET_NUM_TURNED_IN(collectableCategory, collectableSubcategory) end

---@param collectableCategory integer
---@param p1 integer
---@return integer
function COLLECTION._0x33825A7388A6B9F6(collectableCategory, p1) end

---@param collectableCategory integer
---@param p1 integer
---@return integer
function COLLECTION._0x755901C7598B97BC(collectableCategory, p1) end

---@param collectableCategory integer
---@param p1 integer
---@param index integer
---@return any
function COLLECTION._0xB9020EC89C07DF04(collectableCategory, p1, index) end

---@param collectableCategory integer
---@param p1 integer
---@return boolean
function COLLECTION._0xFC832B06127D8E99(collectableCategory, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function COLLECTION.COLLECTABLE_CATEGORY_SET_HAS_RECEIVED_LIST(p0, p1, p2) end

---@param collectableCategory integer
---@param p1 integer
---@return boolean
function COLLECTION._0x6BAB7ACED1017204(collectableCategory, p1) end

---@param collectableCategory integer
---@param p1 integer
---@return boolean
function COLLECTION._0x61BEFBA3CE7A3BC8(collectableCategory, p1) end

---@param collectableCategory integer
---@param p1 any
---@return any
function COLLECTION._0xC4AC39719C1BB559(collectableCategory, p1) end

---@param p0 any
---@param p1 any
---@return any
function COLLECTION._0x93F2E7B5DB85657B(p0, p1) end

---@param collectableCategory integer
---@param p1 integer
---@return integer
function COLLECTION.COLLECTABLE_GET_CATEGORY_ITEM_SET_BUY_AWARD(collectableCategory, p1) end

---@param collectableCategory integer
---@return integer
function COLLECTION._0x9ADEE485726025D4(collectableCategory) end

---@param collectableCategory integer
---@param p1 integer
---@return any
function COLLECTION._0xD1806FB3EDED6D11(collectableCategory, p1) end

---@param collectableCategory integer
---@param p1 integer
---@return any
function COLLECTION._0x3FD91F1A148A0468(collectableCategory, p1) end

---@param collectableCategory integer
---@param p1 integer
---@return any
function COLLECTION._0xC3CA424E1F12ED0C(collectableCategory, p1) end

---@param collectableCategory integer
---@param collectableSubcategory integer
---@return integer
function COLLECTION._COLLECTABLE_CATEGORY_GET_TOAST_TEXTURE_NAME(collectableCategory, collectableSubcategory) end

---@param collectableCategory integer
---@param collectableSubcategory integer
---@return integer
function COLLECTION._COLLECTABLE_CATEGORY_GET_TOAST_TEXTURE_DICTIONARY(collectableCategory, collectableSubcategory) end

---@param collectableCategory integer
---@param p1 integer
---@return any
function COLLECTION._0xD297F68928A58130(collectableCategory, p1) end

---@param collectableCategory integer
---@param p1 integer
---@return any
function COLLECTION._0x775FA1FC87666847(collectableCategory, p1) end

---@param p0 integer
---@return any
function COLLECTION._0xEC3959E9950BF56B(p0) end
