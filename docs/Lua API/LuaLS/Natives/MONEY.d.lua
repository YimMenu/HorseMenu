---@meta

---@class MONEY
MONEY = {}

---@return integer
function MONEY._MONEY_GET_CASH_BALANCE() end

---@param amount integer
---@return boolean
function MONEY._MONEY_DECREMENT_CASH_BALANCE(amount) end

---@param amount integer
---@param addReason integer
---@return boolean
function MONEY._MONEY_INCREMENT_CASH_BALANCE(amount, addReason) end

---@return string
function MONEY._NETWORK_GET_STRING_CASH_BALANCE() end

---@param cashBalance integer
---@param goldBarBalance integer
---@return boolean
function MONEY._NETWORK_IS_MONEY_BALANCE_NOT_LESS_THAN(cashBalance, goldBarBalance) end

---@return string
function MONEY._0xA46FD001D1BE896C() end

---@param p0 any
---@param p1 any
---@return boolean
function MONEY._0x07AD9E43FD478527(p0, p1) end

---@return integer
function MONEY._NETWORK_GET_CASH_BALANCE() end
