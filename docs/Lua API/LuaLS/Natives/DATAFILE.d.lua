---@meta

---@class DATAFILE
DATAFILE = {}

---@param nCloudRequestID integer
function DATAFILE.DATAFILE_WATCH_REQUEST_ID(nCloudRequestID) end

---@param nCloudRequestID integer
---@return boolean
function DATAFILE.DATAFILE_HAS_LOADED_FILE_DATA(nCloudRequestID) end

---@param nCloudRequestID integer
---@return boolean
function DATAFILE.DATAFILE_HAS_VALID_FILE_DATA(nCloudRequestID) end

---@param nCloudRequestID integer
---@param datafileIndex integer
---@return boolean
function DATAFILE.DATAFILE_SELECT_ACTIVE_FILE(nCloudRequestID, datafileIndex) end

---@param nCloudRequestID integer
---@return boolean
function DATAFILE.DATAFILE_DELETE_REQUESTED_FILE(nCloudRequestID) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return any
function DATAFILE.UGC2_SET_PLAYER_DATA(p0, p1, p2, p3) end

---@param ugcRequestId any
---@param index integer
---@param p2 any
---@return any
function DATAFILE.DATAFILE_UGC_SELECT_DATA(ugcRequestId, index, p2) end

---@param datafileIndex integer
function DATAFILE.DATAFILE_CREATE(datafileIndex) end

---@param datafileIndex integer
function DATAFILE.DATAFILE_DELETE(datafileIndex) end

---@param datafileIndex integer
---@return integer
function DATAFILE.DATAFILE_GET_FILE_DICT(datafileIndex) end

---@param fileDict integer
---@return boolean
function DATAFILE.DATADICT_IS_DICT_VALID(fileDict) end

---@param fileDict integer
---@return boolean
function DATAFILE.DATADICT_IS_ARRAY_VALID(fileDict) end

---@param dict integer
---@param name any
---@param value integer
function DATAFILE.DATADICT_SET_INT(dict, name, value) end

---@param dict integer
---@param name any
---@return boolean
function DATAFILE.DATADICT_GET_BOOL(dict, name) end

---@param dict integer
---@param name any
---@return integer
function DATAFILE.DATADICT_GET_INT(dict, name) end

---@param dict integer
---@param name any
---@return number
function DATAFILE.DATADICT_GET_FLOAT(dict, name) end

---@param dict integer
---@param name any
---@return string
function DATAFILE.DATADICT_GET_STRING(dict, name) end

---@param dict integer
---@param name any
---@return Vector3
function DATAFILE.DATADICT_GET_VECTOR(dict, name) end

---@param parent integer
---@param name any
---@return integer
function DATAFILE.DATADICT_GET_DICT(parent, name) end

---@param parent integer
---@param name any
---@return integer
function DATAFILE.DATADICT_GET_ARRAY(parent, name) end

---@param dict integer
---@param name any
---@return integer
function DATAFILE.DATADICT_GET_TYPE(dict, name) end

---@param p0 any
---@param p1 any
---@param p2 any
function DATAFILE._0xBC0DF006A4952C68(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
function DATAFILE._0x9F130129EBC31B34(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
function DATAFILE._0x277251C161B4C3F4(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
function DATAFILE._0x1C65CC931C0F946F(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function DATAFILE._0x7681B677400C7071(p0, p1, p2, p3, p4) end

---@param arr integer
---@param index integer
---@return boolean
function DATAFILE.DATAARRAY_GET_BOOL(arr, index) end

---@param arr integer
---@param index integer
---@return integer
function DATAFILE.DATAARRAY_GET_INT(arr, index) end

---@param arr integer
---@param index integer
---@return number
function DATAFILE.DATAARRAY_GET_FLOAT(arr, index) end

---@param arr integer
---@param index integer
---@return string
function DATAFILE.DATAARRAY_GET_STRING(arr, index) end

---@param arr integer
---@param index integer
---@return Vector3
function DATAFILE.DATAARRAY_GET_VECTOR(arr, index) end

---@param parent integer
---@param index integer
---@return integer
function DATAFILE.DATAARRAY_GET_DICT(parent, index) end

---@param arr integer
---@return integer
function DATAFILE.DATAARRAY_GET_COUNT(arr) end

---@param arr integer
---@param index integer
---@return integer
function DATAFILE.DATAARRAY_GET_TYPE(arr, index) end

---@param p0 any
---@return any
function DATAFILE._0x4F9E3ED7617123AC(p0) end

---@param p0 any
---@return any
function DATAFILE._0xCA56DD6AB7A39F64(p0) end

---@param p0 integer
---@return integer
function DATAFILE._PARSEDDATA_LOAD_FILE_HASH(p0) end

---@param fileHandle integer
function DATAFILE._PARSEDDATA_UNLOAD_FILE(fileHandle) end

---@param fileHandle integer
---@return boolean
function DATAFILE.PARSEDDATA_IS_FILE_VALID(fileHandle) end

---@param fileHandle integer
---@return boolean
function DATAFILE.PARSEDDATA_IS_FILE_LOADED(fileHandle) end

function DATAFILE._0x3168BA5D6DECE323() end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function DATAFILE._PARSEDDATA_REGISTER_QUERY(p0, p1, p2) end

---@param p0 integer
---@param p1 integer
---@return boolean
---@return integer
function DATAFILE.PARSEDDATA_RQ_FILLOUT_NODE(p0, p1) end

---@param p0 any
---@return any
function DATAFILE._PARSEDDATA_RQ_GET_NUM_NODES(p0) end

---@param p0 integer
---@param p1 integer
---@return integer
function DATAFILE._0xE13634BB6BAF0734(p0, p1) end

---@param p0 any
---@param p1 any
---@return any
function DATAFILE._PARSEDDATA_GET_NUM_CHILDREN(p0, p1) end

---@param p0 integer
---@param p1 integer
---@return boolean
---@return integer
function DATAFILE.PARSEDDATA_RQ_FILLOUT_HASH(p0, p1) end

---@param p0 string
---@param p1 integer
---@return boolean
---@return string
function DATAFILE._PARSEDDATA_RQ_FILLOUT_STRING_63(p0, p1) end

---@param p0 string
---@param p1 integer
---@return boolean
---@return string
function DATAFILE.PARSEDDATA_RQ_FILLOUT_STRING_127(p0, p1) end

---@param p0 Vector3
---@param p1 integer
---@return boolean
---@return Vector3
function DATAFILE._PARSEDDATA_RQ_FILLOUT_VECTOR(p0, p1) end

---@param p0 number
---@param p1 integer
---@return boolean
---@return number
function DATAFILE._PARSEDDATA_RQ_FILLOUT_FLOAT(p0, p1) end

---@param p0 integer
---@param p1 integer
---@return boolean
---@return integer
function DATAFILE._PARSEDDATA_RQ_FILLOUT_INT(p0, p1) end

---@param p0 boolean
---@param p1 integer
---@return boolean
---@return boolean
function DATAFILE._PARSEDDATA_RQ_FILLOUT_BOOL(p0, p1) end

---@param p0 integer
function DATAFILE._PARSEDDATA_GET_FILE(p0) end

---@param p0 integer
---@return boolean
function DATAFILE._PARSEDDATA_GET_ENTRIES(p0) end

---@param p0 integer
---@param p1 integer
---@param p2 integer
---@return boolean
function DATAFILE._PARSEDDATA_GET_FLOAT(p0, p1, p2) end

---@param p0 integer
---@param p1 integer
---@param p2 integer
---@return boolean
function DATAFILE._PARSEDDATA_GET_INT(p0, p1, p2) end

---@param p0 integer
---@param p1 integer
---@param section integer
---@return boolean
function DATAFILE._PARSEDDATA_GET_SECTION(p0, p1, section) end

---@param p0 boolean
---@param p1 integer
---@param p2 integer
---@return boolean
---@return boolean
function DATAFILE._PARSEDDATA_GET_BOOL(p0, p1, p2) end
