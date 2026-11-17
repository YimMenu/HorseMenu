---@meta

---@class ITEMDATABASE
ITEMDATABASE = {}

---@param p0 any
---@param p1 any
---@param slotId integer
---@return boolean
function ITEMDATABASE._ITEMDATABASE_CAN_EQUIP_ITEM_ON_CATEGORY(p0, p1, slotId) end

---@param p0 any
---@return integer
function ITEMDATABASE._ITEMDATABASE_GET_FITS_SLOT_COUNT(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_FITS_SLOT_INFO(p0, p1, p2) end

---@param p0 any
---@return integer
function ITEMDATABASE._ITEMDATABASE_GET_HAS_SLOT_COUNT(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_HAS_SLOT_INFO(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@return boolean
function ITEMDATABASE.ITEMDATABASE_FILLOUT_ITEM_BY_NAME(p0, p1) end

---@param p0 integer
---@param p1 integer
---@return boolean
function ITEMDATABASE.ITEMDATABASE_FILLOUT_ITEM_INFO(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_FILLOUT_ACQUIRE_COST(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_FILLOUT_SELL_PRICE(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_FILLOUT_SATCHEL_DATA(p0, p1) end

---@param p0 any
---@param p1 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_FILLOUT_UI_DATA(p0, p1) end

---@param p0 any
---@param p1 any
---@return boolean
function ITEMDATABASE._0x74C3B1093728D263(p0, p1) end

---@param p0 any
---@param p1 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_FILLOUT_ITEM_EFFECT_IDS(p0, p1) end

---@param p0 any
---@param p1 any
---@return boolean
function ITEMDATABASE.ITEMDATABASE_FILLOUT_ITEM_EFFECT_ID_INFO(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_FILLOUT_TAG_DATA(p0, p1, p2, p3) end

---@param p0 any
---@return integer
function ITEMDATABASE._ITEMDATABASE_GET_ACQUIRE_COSTS_COUNT(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_ACQUIRE_COST(p0, p1, p2) end

---@param p0 integer
---@param costShop integer
---@return integer
function ITEMDATABASE._0xDEE7B3C76ED664BE(p0, costShop) end

---@param p0 integer
---@param costShop integer
---@param fillOutIndex integer
---@param p3 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_FILLOUT_ITEM(p0, costShop, fillOutIndex, p3) end

---@param p0 any
---@return integer
function ITEMDATABASE._ITEMDATABASE_GET_AWARD_ACQUIRE_COST_TYPE(p0) end

---@param p0 any
---@param index integer
---@param data integer
---@return boolean
function ITEMDATABASE._0x1FC25AEB5F76B38D(p0, index, data) end

---@param award any
---@param cost integer
---@return integer
function ITEMDATABASE._0xF540239F9937033B(award, cost) end

---@param award any
---@param cost integer
---@param index integer
---@param p3 any
---@return boolean
function ITEMDATABASE._0xF27F01BBF5ACD3F3(award, cost, index, p3) end

---@param p0 integer
---@param size integer
---@param comparisonType integer
---@return integer
---@return integer
function ITEMDATABASE._ITEMDATABASE_CREATE_ITEM_COLLECTION(p0, size, comparisonType) end

---@param collectionId integer
---@return integer
function ITEMDATABASE._ITEMDATABASE_GET_COLLECTION_SIZE(collectionId) end

---@param collectionId integer
---@param index integer
---@param p2 integer
---@return boolean
---@return integer
function ITEMDATABASE._ITEMDATABASE_GET_COMPONENT_ITEM(collectionId, index, p2) end

---@param collectionId integer
---@return boolean
function ITEMDATABASE._ITEMDATABASE_RELEASE_ITEM_COLLECTION(collectionId) end

---@param p0 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_IS_INTRINSIC_ITEM(p0) end

---@param p0 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_IS_OVERPOWERED_ITEM(p0) end

---@param p0 any
---@param p1 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_IS_KEY_VALID(p0, p1) end

---@param p0 integer
---@param p1 any
---@return boolean
function ITEMDATABASE._0x537A0555F62CA01A(p0, p1) end

---@param p0 any
---@return integer
function ITEMDATABASE._ITEMDATABASE_GET_BUNDLE_ID(p0) end

---@param p0 any
---@param p1 any
---@return integer
function ITEMDATABASE._ITEMDATABASE_GET_BUNDLE_ITEM_COUNT(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_BUNDLE_ITEM_INFO(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_IS_BUNDLE_VALID(p0, p1) end

---@param bundle any
---@param p1 any
---@return integer
function ITEMDATABASE._0x799FCD53358ED5FA(bundle, p1) end

---@param bundle any
---@param p1 any
---@param index integer
---@param p3 any
---@return boolean
function ITEMDATABASE._0xC4146375D8A0B374(bundle, p1, index, p3) end

---@param p0 any
---@param p1 any
---@return boolean
function ITEMDATABASE._0xA97EE5E4589FCF5A(p0, p1) end

---@param p0 any
---@return integer
function ITEMDATABASE._0x7A35A72A692BE9DB(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return boolean
function ITEMDATABASE._0x3A0B667ABFF87F6E(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@return integer
function ITEMDATABASE._0x388088BFF3681189(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_FILLOUT_BUNDLE(p0, p1, p2, p3) end

---@param p0 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_IS_SHOP_KEY_VALID(p0) end

---@param p0 any
---@return integer
function ITEMDATABASE._ITEMDATABASE_GET_SHOP_INVENTORIES_ITEMS_COUNT(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_SHOP_INVENTORIES_ITEM_INFO(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_SHOP_INVENTORIES_ITEM_INFO_BY_KEY(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_SHOP_INVENTORIES_REQUIREMENT_GROUP_INFO(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_SHOP_INVENTORIES_REQUIREMENT_INFO(p0, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return boolean
function ITEMDATABASE._0x17721003A66C72BF(p0, p1, p2) end

---@param p0 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_IS_SHOP_LAYOUT_KEY_VALID(p0) end

---@param p0 any
---@param p1 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_SHOP_LAYOUT_INFO(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_SHOP_LAYOUT_ROOT_MENU_INFO(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_SHOP_LAYOUT_MENU_INFO_BY_ID(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_SHOP_LAYOUT_MENU_INFO_BY_INDEX(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_SHOP_LAYOUT_MENU_PAGE_KEY(p0, p1, p2, p3) end

---@param p0 any
---@param index integer
---@param menuKey any
---@return boolean
function ITEMDATABASE._0xDBEADA0DF5F9AB9F(p0, index, menuKey) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_SHOP_LAYOUT_PAGE_INFO_BY_KEY(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_SHOP_LAYOUT_PAGE_ITEM_KEY(p0, p1, p2, p3, p4, p5) end

---@param p0 any
---@return boolean
function ITEMDATABASE.ITEMDATABASE_IS_BUYABLE_AWARD_VALID(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_FILLOUT_BUY_AWARD_ACQUIRE_COSTS(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@return boolean
function ITEMDATABASE._0xF8D09EF8CE61D7BF(p0, p1) end

---@param p0 any
---@param p1 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_ITEM_PRICE_MODIFIERS(p0, p1) end

---@param p0 any
---@param p1 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_FILLOUT_PRICE_MODIFIER_BY_KEY(p0, p1) end

---@param p0 any
---@return integer
function ITEMDATABASE._ITEMDATABASE_GET_NUMBER_OF_MODIFIED_PRICES(p0) end

---@param p0 any
---@param p1 any
---@return integer
function ITEMDATABASE._ITEMDATABASE_GET_MODIFIED_PRICE(p0, p1) end

---@param p0 any
---@return integer
function ITEMDATABASE._ITEMDATABASE_GET_NUMBER_OF_MODIFIERS(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_FILLOUT_MODIFIER(p0, p1, p2) end

---@param award integer
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_PRIORITY_ACCESS_AWARD(award) end

---@param award integer
---@return integer
function ITEMDATABASE._ITEMDATABASE_GET_AWARD_ITEM_COUNT(award) end

---@param award integer
---@return integer
function ITEMDATABASE._0x48229CE0C7938237(award) end

---@param award integer
---@param index integer
---@param currency integer
---@return boolean
---@return integer
function ITEMDATABASE._ITEMDATABASE_FILLOUT_AWARD_ITEM_INFO(award, index, currency) end

---@param award integer
---@param p1 any
---@param p2 any
---@return boolean
function ITEMDATABASE._0x8D029948CA29409B(award, p1, p2) end

---@param p0 any
---@param p1 any
---@return boolean
function ITEMDATABASE._ITEMDATABASE_GET_AWARD_COST_MODIFIERS(p0, p1) end

---@param p0 any
---@param p1 any
---@return boolean
function ITEMDATABASE._0xD076DB9B96FAADF1(p0, p1) end

---@param item integer
---@param tag integer
---@param tagType integer
---@return boolean
function ITEMDATABASE._ITEMDATABASE_DOES_ITEM_HAVE_TAG(item, tag, tagType) end

---@param bundle integer
---@param tag integer
---@param tagType integer
---@return boolean
function ITEMDATABASE._ITEMDATABASE_DOES_BUNDLE_HAVE_TAG(bundle, tag, tagType) end

---@param item integer
---@param tag integer
---@return integer
function ITEMDATABASE._ITEMDATABASE_GET_ITEM_TAG_TYPE(item, tag) end

---@param p0 any
---@param tagType integer
---@param p2 any
---@return integer
function ITEMDATABASE._0x8870895BA5ED9385(p0, tagType, p2) end

---@param p0 any
---@return integer
function ITEMDATABASE._ITEMDATABASE_LOCALIZATION_GET_NUM_LABEL_TYPES(p0) end

---@param p0 any
---@param p1 any
---@return integer
function ITEMDATABASE._ITEMDATABASE_LOCALIZATION_GET_NUM_VALUES(p0, p1) end

---@param p0 any
---@param p1 any
---@return any
function ITEMDATABASE._ITEMDATABASE_LOCALIZATION_GET_TYPE(p0, p1) end

---@param p0 any
---@param label integer
---@param p2 any
---@return integer
function ITEMDATABASE._ITEMDATABASE_LOCALIZATION_GET_VALUE(p0, label, p2) end

---@param item integer
---@param p1 integer
---@return integer
function ITEMDATABASE._ITEMDATABASE_GET_ITEM_PATHSET(item, p1) end

---@param p0 any
---@param p1 integer
---@return integer
function ITEMDATABASE._0xAA29A5F13B2C20B2(p0, p1) end
