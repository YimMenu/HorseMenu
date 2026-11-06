---@meta

---@class TXD
TXD = {}

---@param txdHash integer
---@return boolean
function TXD.DOES_STREAMED_TXD_EXIST(txdHash) end

---@param txdHash integer
---@param p1 boolean
function TXD.REQUEST_STREAMED_TXD(txdHash, p1) end

---@param txdHash integer
---@return boolean
function TXD.HAS_STREAMED_TXD_LOADED(txdHash) end

---@param txdHash integer
function TXD.SET_STREAMED_TXD_AS_NO_LONGER_NEEDED(txdHash) end

---@param textureDict any
---@return boolean
function TXD.DOES_STREAMED_TEXTURE_DICT_EXIST(textureDict) end

---@param TxdName any
---@param bPriority boolean
function TXD.REQUEST_STREAMED_TEXTURE_DICT(TxdName, bPriority) end

---@param TxdName any
---@return boolean
function TXD.HAS_STREAMED_TEXTURE_DICT_LOADED(TxdName) end

---@param TxdName any
function TXD.SET_STREAMED_TEXTURE_DICT_AS_NO_LONGER_NEEDED(TxdName) end
