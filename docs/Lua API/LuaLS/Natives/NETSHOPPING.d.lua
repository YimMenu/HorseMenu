---@meta

---@class NETSHOPPING
NETSHOPPING = {}

---@param p0 integer
---@param p1 integer
---@return boolean
---@return integer
---@return integer
function NETSHOPPING.CASHINVENTORY_INIT_SESSION_STATUS(p0, p1) end

---@return boolean
function NETSHOPPING._CASHINVENTORY_IS_SESSION_READY() end

---@return boolean
function NETSHOPPING.CASHINVENTORY_IS_CONNECTION_FAULTED() end

---@return boolean
function NETSHOPPING._CASHINVENTORY_INIT_SESSION_IS_FAULTED() end

---@param actionHash integer
---@param id integer
---@param item integer
---@param p3 integer
---@return boolean
---@return integer
function NETSHOPPING._CASHINVENTORY_TRANSACTION_FIRE_AND_FORGET_ITEM(actionHash, id, item, p3) end

---@param id integer
---@param type integer
---@param actionHash integer
---@return boolean
---@return integer
function NETSHOPPING._CASHINVENTORY_TRANSACTION_START(id, type, actionHash) end

---@param id integer
---@return boolean
function NETSHOPPING._CASHINVENTORY_TRANSACTION_GET_BASKET_IS_VALID(id) end

---@param id integer
---@return boolean
function NETSHOPPING._CASHINVENTORY_TRANSACTION_DELETE(id) end

---@param p0 integer
---@param p1 integer
---@return integer
function NETSHOPPING._CASHINVENTORY_TRANSACTION_VALIDATE_ITEM(p0, p1) end

---@param p0 integer
---@return integer
function NETSHOPPING._0x38640A8C2DEF011B(p0) end

---@param p0 integer
---@param p1 integer
---@param p2 integer
---@param p3 integer
---@param p4 integer
---@param p5 integer
---@return boolean
function NETSHOPPING._0xA3B8D31C13CB4239(p0, p1, p2, p3, p4, p5) end

---@param id integer
---@param hash integer
---@param p2 integer
---@param p3 integer
---@return boolean
function NETSHOPPING._CASHINVENTORY_TRANSACTION_ADD_AWARD(id, hash, p2, p3) end

---@param id integer
---@param index integer
---@param itemInfo integer
---@return boolean
function NETSHOPPING._CASHINVENTORY_TRANSACTION_GET_ITEM_INFO(id, index, itemInfo) end

---@param id integer
---@return integer
function NETSHOPPING._CASHINVENTORY_TRANSACTION_GET_NUM_OF_ITEMS(id) end

---@param id integer
---@return integer
function NETSHOPPING._CASHINVENTORY_TRANSACTION_GET_ACTION(id) end

---@param id integer
---@return boolean
function NETSHOPPING._CASHINVENTORY_TRANSACTION_CHECKOUT(id) end

---@param id integer
---@param status integer
---@return boolean
---@return integer
function NETSHOPPING._CASHINVENTORY_TRANSACTION_CHECKOUT_STATUS(id, status) end

---@param p0 integer
---@param p1 integer
---@return integer
function NETSHOPPING._0xB6F4557060EF0FB4(p0, p1) end

---@param id integer
---@param index integer
---@param itemInfo integer
---@return boolean
function NETSHOPPING._CASHINVENTORY_TRANSACTION_RESPONSE_GET_ITEM_INFO(id, index, itemInfo) end

---@param p0 integer
---@return boolean
function NETSHOPPING._0xCE54C9ABE6FBC6DB(p0) end

---@param p0 integer
---@param p1 any
---@return boolean
function NETSHOPPING._0xA0B7094629724974(p0, p1) end

---@param id integer
---@param index integer
---@param p2 integer
---@return boolean
function NETSHOPPING._0x92A32BA29622763F(id, index, p2) end

---@param p0 integer
---@param p1 integer
---@param p2 integer
---@param p3 any
---@param p4 integer
---@return boolean
function NETSHOPPING._0x3FA09DD57B93C0DE(p0, p1, p2, p3, p4) end

---@param p0 integer
---@param p1 integer
---@param p2 integer
---@param p3 any
---@param p4 integer
---@return boolean
function NETSHOPPING._0xD1555FBC96C88444(p0, p1, p2, p3, p4) end
