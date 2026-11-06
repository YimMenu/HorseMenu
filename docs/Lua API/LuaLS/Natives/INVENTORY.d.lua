---@meta

---@class INVENTORY
INVENTORY = {}

---@param ped integer
---@return integer
function INVENTORY._INVENTORY_GET_INVENTORY_ID_FROM_PED(ped) end

---@param inventoryId integer
---@param eRoleMaxLevel integer
---@return integer
function INVENTORY._GET_ITEM_ROLE_MAX_LEVEL_COUNT(inventoryId, eRoleMaxLevel) end

---@param provision integer
---@param slotId integer
---@return integer
function INVENTORY._GET_ITEM_SLOT_MAX_COUNT(provision, slotId) end

---@param inventoryId integer
---@param p1 integer
---@param year integer
---@param month integer
---@param day integer
---@param hour integer
---@param minute integer
---@param second integer
---@return boolean
---@return integer
---@return integer
---@return integer
---@return integer
---@return integer
---@return integer
function INVENTORY._0x112BCA290D2EB53C(inventoryId, p1, year, month, day, hour, minute, second) end

---@param inventoryId integer
---@param eInventoryItem integer
---@param p2 boolean
function INVENTORY._0x46743BBFEDBC859E(inventoryId, eInventoryItem, p2) end

---@param inventoryId integer
---@param guid integer
---@param inUse boolean
function INVENTORY._INVENTORY_SET_INVENTORY_ITEM_IN_USE(inventoryId, guid, inUse) end

---@param inventoryId integer
---@param guid integer
---@return boolean
function INVENTORY._INVENTORY_GET_INVENTORY_ITEM_IN_USE(inventoryId, guid) end

---@param inventoryId integer
---@param guid integer
---@param hidden boolean
function INVENTORY._INVENTORY_SET_INVENTORY_ITEM_HIDDEN(inventoryId, guid, hidden) end

---@param inventoryId integer
---@param guid integer
---@param hidden boolean
function INVENTORY._INVENTORY_SET_INVENTORY_ITEM_HIDDEN_2(inventoryId, guid, hidden) end

---@param inventoryId integer
---@param guid integer
---@return boolean
function INVENTORY._INVENTORY_GET_INVENTORY_ITEM_HIDDEN(inventoryId, guid) end

---@param item integer
---@return boolean
function INVENTORY._INVENTORY_GET_INVENTORY_ITEM_IS_ANIMAL_PELT(item) end

---@param item integer
---@return integer
function INVENTORY._INVENTORY_GET_INVENTORY_ITEM_DESCRIPTION_HASH(item) end

---@param item integer
---@param flag integer
---@return boolean
function INVENTORY._INVENTORY_IS_INVENTORY_ITEM_FLAG_ENABLED(item, flag) end

---@param item integer
---@param soundType integer
---@return boolean
function INVENTORY._INVENTORY_GET_IS_INVENTORY_ITEM_SOUND_VALID(item, soundType) end

---@param item integer
---@param soundType integer
---@return integer
function INVENTORY._INVENTORY_GET_INVENTORY_ITEM_SOUND(item, soundType) end

---@param item integer
---@param info integer
---@return boolean
function INVENTORY._INVENTORY_GET_INVENTORY_ITEM_INSPECTION_INFO(item, info) end

---@param inventoryId integer
---@param guid integer
---@return integer
function INVENTORY._INVENTORY_GET_INVENTORY_ITEM_WEAPON_COPY_ID(inventoryId, guid) end

---@param inventoryId integer
---@return boolean
function INVENTORY._INVENTORY_ARE_LOCAL_CHANGES_ALLOWED(inventoryId) end

---@param guid integer
---@return boolean
function INVENTORY._INVENTORY_IS_GUID_VALID(guid) end

---@param guid1 integer
---@param guid2 integer
---@return boolean
function INVENTORY._INVENTORY_COMPARE_GUIDS(guid1, guid2) end

---@param inventoryId integer
---@param guid integer
---@param p2 integer
---@param slotId integer
---@param outGuid integer
---@return boolean
function INVENTORY.INVENTORY_GET_GUID_FROM_ITEMID(inventoryId, guid, p2, slotId, outGuid) end

---@param inventoryId integer
---@param removeReason integer
---@return boolean
function INVENTORY._0x5D6182F3BCE1333B(inventoryId, removeReason) end

---@param inventoryId integer
---@param inData integer
---@param outData integer
---@param p3 boolean
---@return boolean
function INVENTORY.INVENTORY_GET_INVENTORY_ITEM(inventoryId, inData, outData, p3) end

---@param inventoryId integer
---@param guid integer
---@param p2 integer
---@param p3 integer
---@param p4 integer
---@return boolean
function INVENTORY._INVENTORY_GET_FULL_INVENTORY_ITEM_DATA(inventoryId, guid, p2, p3, p4) end

---@param inventoryId integer
---@param parentGuid integer
---@param childIndex any
---@param outInventoryItem integer
---@return boolean
function INVENTORY._INVENTORY_GET_INVENTORY_ITEM_CHILD(inventoryId, parentGuid, childIndex, outInventoryItem) end

---@param inventoryId integer
---@param guid1 integer
---@param guid2 integer
---@param item integer
---@param inventoryItemSlot integer
---@param p5 integer
---@param addReason integer
---@return boolean
function INVENTORY._INVENTORY_ADD_ITEM_WITH_GUID(inventoryId, guid1, guid2, item, inventoryItemSlot, p5, addReason) end

---@param inventoryId integer
---@param guid1 integer
---@param guid2 integer
---@param p3 integer
---@return boolean
function INVENTORY._INVENTORY_UPDATE_INVENTORY_ITEM(inventoryId, guid1, guid2, p3) end

---@param inventoryId integer
---@param guid integer
---@param quantity integer
---@param removeReason integer
---@return boolean
function INVENTORY._INVENTORY_REMOVE_INVENTORY_ITEM_WITH_GUID(inventoryId, guid, quantity, removeReason) end

---@param inventoryId integer
---@param item integer
---@param quantity integer
---@param removeReason integer
---@return boolean
function INVENTORY._INVENTORY_REMOVE_INVENTORY_ITEM_WITH_ITEMID(inventoryId, item, quantity, removeReason) end

---@param inventoryId integer
---@param guid1 integer
---@param guid2 integer
---@param slotId integer
---@param quantity integer
---@param outGuid integer
---@return boolean
function INVENTORY._INVENTORY_MOVE_INVENTORY_ITEM(inventoryId, guid1, guid2, slotId, quantity, outGuid) end

---@param inventoryId integer
---@param guid1 integer
---@param guid2 integer
---@return boolean
function INVENTORY._INVENTORY_SWAP_INVENTORY_ITEM(inventoryId, guid1, guid2) end

---@param inventoryId integer
---@param filterName any
---@param slotId integer
---@param size integer
---@return integer
---@return integer
function INVENTORY._INVENTORY_CREATE_ITEM_COLLECTION(inventoryId, filterName, slotId, size) end

---@param inventoryId integer
---@param filter integer
---@param numInCollection integer
---@return integer
---@return integer
function INVENTORY._INVENTORY_CREATE_ITEM_COLLECTION_WITH_FILTER(inventoryId, filter, numInCollection) end

---@param collectionId integer
---@param itemIndex integer
---@param itemData integer
---@return boolean
function INVENTORY._INVENTORY_GET_ITEM_FROM_COLLECTION_INDEX(collectionId, itemIndex, itemData) end

---@param collectionId integer
---@return boolean
function INVENTORY._INVENTORY_RELEASE_ITEM_COLLECTION(collectionId) end

---@param inventoryId integer
---@param guid integer
---@param bEquipped boolean
---@return boolean
function INVENTORY._INVENTORY_EQUIP_ITEM_WITH_GUID(inventoryId, guid, bEquipped) end

---@param inventoryId integer
---@param guid integer
---@param slotId integer
---@param outGuid integer
---@return boolean
function INVENTORY._INVENTORY_GET_INVENTORY_ITEM_EQUIPPED_IN_SLOT_BY_REF(inventoryId, guid, slotId, outGuid) end

---@param inventoryId integer
---@param guid integer
---@param item integer
---@return boolean
function INVENTORY._INVENTORY_DOES_ITEM_OWN_EQUIPMENT(inventoryId, guid, item) end

---@param inventoryId integer
---@param guid integer
---@param p2 integer
---@param p3 integer
---@return boolean
---@return integer
---@return integer
function INVENTORY._0xD08685BA892DBFAB(inventoryId, guid, p2, p3) end

---@param p0 boolean
---@param inventoryId integer
---@param guid integer
function INVENTORY._0x0349404A22736740(p0, inventoryId, guid) end

---@param inventoryId integer
---@param guid integer
---@param weatherEffectiveness integer
function INVENTORY._INVENTORY_SET_INVENTORY_ITEM_WEATHER_EFFECTIVENESS(inventoryId, guid, weatherEffectiveness) end

---@param inventoryId integer
---@param item integer
---@param gtxReason integer
function INVENTORY._INVENTORY_DISABLE_ITEM(inventoryId, item, gtxReason) end

---@param inventoryId integer
---@param item integer
function INVENTORY._INVENTORY_ENABLE_ITEM(inventoryId, item) end

---@param inventoryId integer
---@param item integer
---@param p2 boolean
---@return boolean
function INVENTORY._INVENTORY_IS_INVENTORY_ITEM_EQUIPPED(inventoryId, item, p2) end

---@param inventoryId integer
---@param p1 integer
---@param enabled boolean
---@return boolean
function INVENTORY._INVENTORY_SET_INVENTORY_ITEM_INSPECTION_ENABLED(inventoryId, p1, enabled) end

---@param itemGUID integer
---@return boolean
function INVENTORY._INVENTORY_IS_ITEM_EXPIRED(itemGUID) end

---@param itemGUID integer
---@return integer
function INVENTORY._INVENTORY_GET_ITEM_EXPIRY_TIME(itemGUID) end

---@param inventoryId integer
---@param guid integer
---@param p2 boolean
---@return integer
function INVENTORY._INVENTORY_GET_INVENTORY_ITEM_COUNT_WITH_GUID(inventoryId, guid, p2) end

---@param inventoryId integer
---@param eInventoryItem integer
---@param p2 boolean
---@return integer
function INVENTORY._INVENTORY_GET_INVENTORY_ITEM_COUNT_WITH_ITEMID(inventoryId, eInventoryItem, p2) end

---@param inventoryId integer
---@param itemGUID integer
---@return boolean
function INVENTORY._0xB1DD74A1F5536622(inventoryId, itemGUID) end

---@param inventoryId integer
---@param parentGuid integer
---@return integer
function INVENTORY._INVENTORY_GET_CHILDREN_COUNT(inventoryId, parentGuid) end

---@param inventoryId integer
---@param guid integer
---@param slotId integer
---@return integer
function INVENTORY.INVENTORY_GET_CHILDREN_IN_SLOT_COUNT(inventoryId, guid, slotId) end

---@param inventoryId integer
---@param guid integer
---@param slotId integer
---@param p3 integer
---@param p4 integer
---@return integer
function INVENTORY._INVENTORY_GET_INVENTORY_ITEM_EQUIPPED_IN_SLOT(inventoryId, guid, slotId, p3, p4) end

---@param item integer
---@param slotId integer
---@return boolean
function INVENTORY._INVENTORY_FITS_SLOT_ID(item, slotId) end

---@param item integer
---@param p1 integer
---@return integer
function INVENTORY._GET_DEFAULT_ITEM_SLOT_INFO(item, p1) end

---@param p0 integer
---@param p1 integer
---@param p2 integer
---@return boolean
function INVENTORY._INVENTORY_GET_INVENTORY_ITEM_FIT_SLOT(p0, p1, p2) end

---@param item integer
---@param p1 integer
---@param p2 integer
---@return boolean
function INVENTORY._0x9AC53CB6907B4428(item, p1, p2) end

---@param data any
---@param effects any
---@param p2 boolean
---@param p3 boolean
---@return integer
function INVENTORY._0x9D21B185ABC2DBC4(data, effects, p2, p3) end

---@param databindingEntryId integer
---@param p1 boolean
---@param p2 boolean
function INVENTORY._0x75CFAC49301E134F(databindingEntryId, p1, p2) end

---@param data any
---@param stats any
---@param p2 integer
---@param p3 integer
---@return integer
function INVENTORY._0x9D21B185ABC2DBC5(data, stats, p2, p3) end

---@param data any
---@param p1 boolean
---@param ped integer
function INVENTORY._0x75CFAC49301E134E(data, p1, ped) end

---@param data any
---@param stats any
---@param guid integer
---@param ped integer
---@return integer
function INVENTORY._0x46DB71883EE9D5AF(data, stats, guid, ped) end

---@param p0 any
---@param outGuid integer
---@param ped integer
function INVENTORY._0x951847CEF3D829FF(p0, outGuid, ped) end

---@param inventoryId integer
---@param guid integer
---@param p2 integer
---@param p3 integer
---@return boolean
function INVENTORY._0x6862E4D93F64CF01(inventoryId, guid, p2, p3) end

---@param toggle boolean
function INVENTORY._SET_USE_MISSION_INVENTORY(toggle) end

function INVENTORY.INVENTORY_DISABLE_MISSION_INVENTORY_PICKUPS() end

---@param enable boolean
---@param mirrorTransactions boolean
function INVENTORY._INVENTORY_USE_MISSION_INVENTORY(enable, mirrorTransactions) end

---@param p0 boolean
---@param p1 boolean
---@param bCopySatchelItems boolean
---@param bCopyEmotes boolean
---@param bCopyHorse boolean
---@param p5 boolean
function INVENTORY.INVENTORY_COPY_MP_INVENTORY_TO_MISSION_INVENTORY(p0, p1, bCopySatchelItems, bCopyEmotes, bCopyHorse, p5) end

---@param guid integer
---@param p1 boolean
function INVENTORY._INVENTORY_COPY_ITEM_TO_MISSION_INVENTORY(guid, p1) end

---@param p0 boolean
function INVENTORY._0xE36D4A38D28D9CFB(p0) end

---@return boolean
function INVENTORY._INVENTORY_USE_SP_BACKUP() end

---@return boolean
function INVENTORY._INVENTORY_IS_PLAYER_INVENTORY_MIRRORING_TRANSACTIONS() end

---@param inventoryId integer
---@param inventoryIdCloned integer
---@param p2 integer
---@param p3 any
function INVENTORY._INVENTORY_COPY_ITEM_TO_INVENTORY(inventoryId, inventoryIdCloned, p2, p3) end

---@param ped integer
---@param p1 integer
function INVENTORY._0x9E58207B194488AC(ped, p1) end

---@param p0 integer
function INVENTORY._SET_ITEM_PROMPT_INFO_REQUEST(p0) end

function INVENTORY._0x9B4E793B1CB6550A() end

---@param data integer
function INVENTORY._SET_CARRIABLE_CARRY_ACTION_PROMPT_OVERRIDE(data) end

---@param inventoryId integer
function INVENTORY._INVENTORY_ENABLE_WEAPONS(inventoryId) end

---@param inventoryId integer
---@param p1 any
function INVENTORY._INVENTORY_DISABLE_WEAPONS(inventoryId, p1) end

---@param inventoryId integer
function INVENTORY._0xE1F45A67A9F0DCBC(inventoryId) end

---@param inventoryId integer
function INVENTORY._0x6968CE7AC32F6788(inventoryId) end

---@param collectionSize integer
---@return integer
---@return integer
function INVENTORY._INVENTORY_CREATE_ITEM_COLLECTION_2(collectionSize) end

---@param inventoryId integer
---@param p1 integer
---@param size integer
---@return integer
---@return integer
function INVENTORY._INVENTORY_CREATE_SORTED_COLLECTION(inventoryId, p1, size) end
