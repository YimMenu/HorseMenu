---@meta

---@class PROPSET
PROPSET = {}

---@param hash integer
---@return boolean
function PROPSET._REQUEST_PROP_SET(hash) end

---@param hash integer
---@return boolean
function PROPSET._REQUEST_PROP_SET_2(hash) end

---@param hash integer
---@return boolean
function PROPSET._HAS_PROP_SET_LOADED(hash) end

---@param hash integer
---@return boolean
function PROPSET._HAS_PROP_SET_LOADED_2(hash) end

---@param propSet integer
function PROPSET._SET_PROP_SET_AS_NO_LONGER_NEEDED(propSet) end

---@param propSet integer
---@param p1 boolean
---@param p2 boolean
function PROPSET._DELETE_PROP_SET(propSet, p1, p2) end

---@param hash integer
---@return boolean
function PROPSET._RELEASE_PROP_SET(hash) end

---@param propsetType integer
---@param x number
---@param y number
---@param z number
---@param placementType integer
---@param heading number
---@param zProbe number
---@param p7 boolean
---@param useVegMod boolean
---@return integer
function PROPSET._CREATE_PROP_SET(propsetType, x, y, z, placementType, heading, zProbe, p7, useVegMod) end

---@param propsetType integer
---@param x number
---@param y number
---@param z number
---@param placementType integer
---@param heading number
---@param zProbe number
---@param p7 boolean
---@param useVegMod boolean
---@return integer
function PROPSET._CREATE_PROP_SET_2(propsetType, x, y, z, placementType, heading, zProbe, p7, useVegMod) end

---@param hash integer
---@param x number
---@param y number
---@param z number
---@param entity integer
---@param p5 number
---@param p6 boolean
---@param p7 integer
---@param p8 boolean
---@return integer
function PROPSET.CREATE_PROP_SET_INSTANCE_ATTACHED_TO_ENTITY(hash, x, y, z, entity, p5, p6, p7, p8) end

---@param hash integer
---@param x number
---@param y number
---@param z number
---@param entity integer
---@param p5 number
---@param p6 boolean
---@param p7 integer
---@param p8 boolean
---@return integer
function PROPSET._CREATE_PROP_SET_INSTANCE_ATTACHED_TO_ENTITY_2(hash, x, y, z, entity, p5, p6, p7, p8) end

---@param propSet integer
---@return boolean
function PROPSET.DOES_PROP_SET_EXIST(propSet) end

---@param propsetHash integer
---@param x number
---@param y number
---@param z number
---@return boolean
function PROPSET._DOES_PROP_SET_OF_TYPE_EXIST_NEAR_COORDS(propsetHash, x, y, z) end

---@param propSet integer
---@return boolean
function PROPSET.IS_PROP_SET_FULLY_LOADED(propSet) end

---@param propSet integer
---@param toggle boolean
function PROPSET._SET_PROP_SET_VISIBLE(propSet, toggle) end

---@param propSet integer
---@return boolean
function PROPSET._IS_PROP_SET_VISIBLE(propSet) end

---@param propSet integer
---@return integer
function PROPSET._GET_PROP_SET_MODEL(propSet) end

---@param vehicle integer
---@return integer
function PROPSET._GET_VEHICLE_PROP_SET_HASH(vehicle) end

---@param propSet integer
---@param itemSet integer
---@param model integer
---@param p3 boolean
---@param p4 boolean
---@return integer
function PROPSET._GET_ENTITIES_FROM_PROP_SET(propSet, itemSet, model, p3, p4) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
function PROPSET._0xC4B67EF3FD65622D(p0, p1, p2, p3, p4, p5) end

---@param p0 any
function PROPSET._0x58E0B01D45CA7357(p0) end

---@param propSet integer
---@param flag integer
function PROPSET._SET_PROP_SET_FLAG(propSet, flag) end

---@param vehicle integer
---@return integer
function PROPSET._GET_VEHICLE_PROP_SET(vehicle) end

---@param vehicle integer
---@return boolean
function PROPSET._DOES_VEHICLE_HAVE_ANY_PROP_SET(vehicle) end

---@param vehicle integer
---@param propset integer
function PROPSET._ADD_PROP_SET_FOR_VEHICLE(vehicle, propset) end

---@param vehicle integer
function PROPSET._REMOVE_VEHICLE_PROP_SETS(vehicle) end

---@param vehicle integer
---@return boolean
function PROPSET._IS_VEHICLE_PROP_SET_LOADED(vehicle) end

---@param vehicle integer
---@param propset integer
function PROPSET._ADD_ADDITIONAL_PROP_SET_FOR_VEHICLE(vehicle, propset) end

---@param vehicle integer
---@return boolean
function PROPSET._IS_VEHICLE_PROP_SET_LOADED_ADDITIONAL(vehicle) end

---@param vehicle integer
---@return integer
function PROPSET._GET_VEHICLE_LIGHT_PROP_SET(vehicle) end

---@param vehicle integer
---@return boolean
function PROPSET._DOES_VEHICLE_HAVE_ANY_LIGHT_PROP_SET(vehicle) end

---@param vehicle integer
---@param lightPropset integer
function PROPSET._ADD_LIGHT_PROP_SET_TO_VEHICLE(vehicle, lightPropset) end

---@param vehicle integer
function PROPSET._REMOVE_VEHICLE_LIGHT_PROP_SETS(vehicle) end

---@param vehicle integer
---@return boolean
function PROPSET._IS_VEHICLE_LIGHT_PROP_SET_LOADED(vehicle) end

---@param trainCarriage integer
---@return integer
function PROPSET._GET_TRAIN_CARRIAGE_PROP_SET(trainCarriage) end

---@param vehicle integer
---@param wagonIndex integer
---@return boolean
function PROPSET._HAS_VEHICLE_TRAILER_PROP_SET_LOADED(vehicle, wagonIndex) end

---@param propsetHash integer
---@param x number
---@param y number
---@param z number
---@return integer
function PROPSET._GET_PROP_SET_AT_COORDS(propsetHash, x, y, z) end
