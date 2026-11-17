---@meta

---@class VOLUME
VOLUME = {}

---@param volumeType integer
---@param x number
---@param y number
---@param z number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param scaleX number
---@param scaleY number
---@param scaleZ number
---@return integer
function VOLUME._CREATE_VOLUME_BY_HASH(volumeType, x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ) end

---@param x number
---@param y number
---@param z number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param scaleX number
---@param scaleY number
---@param scaleZ number
---@return integer
function VOLUME.CREATE_VOLUME_BOX(x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ) end

---@param x number
---@param y number
---@param z number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param scaleX number
---@param scaleY number
---@param scaleZ number
---@return integer
function VOLUME.CREATE_VOLUME_CYLINDER(x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ) end

---@param x number
---@param y number
---@param z number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param scaleX number
---@param scaleY number
---@param scaleZ number
---@return integer
function VOLUME.CREATE_VOLUME_SPHERE(x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ) end

---@return integer
function VOLUME.CREATE_VOLUME_AGGREGATE() end

---@param volumeType integer
---@param x number
---@param y number
---@param z number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param scaleX number
---@param scaleY number
---@param scaleZ number
---@param name any
---@return integer
function VOLUME._CREATE_VOLUME_BY_HASH_WITH_CUSTOM_NAME(volumeType, x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ, name) end

---@param volumeType integer
---@param x number
---@param y number
---@param z number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param scaleX number
---@param scaleY number
---@param scaleZ number
---@return integer
function VOLUME._CREATE_ANTI_GRIEF_VOLUME(volumeType, x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ) end

---@param volume integer
---@param toggle boolean
function VOLUME._SET_ANTI_GRIEF_VOLUME_BLOCKS_HORSE(volume, toggle) end

---@param volume integer
---@param toggle boolean
function VOLUME._SET_ANTI_GRIEF_VOLUME_BLOCKS_PLAYER(volume, toggle) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
---@param p8 any
---@param p9 any
---@param p10 any
---@param p11 any
---@param p12 any
---@return integer
function VOLUME._CREATE_WALK_AND_TALK_VOLUME(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
---@param p8 any
---@param p9 any
---@param p10 any
---@param p11 any
---@param p12 any
---@param p13 any
---@param p14 any
---@return integer
function VOLUME._CREATE_SPEED_VOLUME(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14) end

---@param x number
---@param y number
---@param z number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param scaleX number
---@param scaleY number
---@param scaleZ number
---@param name any
---@return integer
function VOLUME._CREATE_VOLUME_BOX_WITH_CUSTOM_NAME(x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ, name) end

---@param x number
---@param y number
---@param z number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param scaleX number
---@param scaleY number
---@param scaleZ number
---@param name any
---@return integer
function VOLUME._CREATE_VOLUME_CYLINDER_WITH_CUSTOM_NAME(x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ, name) end

---@param x number
---@param y number
---@param z number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param scaleX number
---@param scaleY number
---@param scaleZ number
---@param name any
---@return integer
function VOLUME._CREATE_VOLUME_SPHERE_WITH_CUSTOM_NAME(x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ, name) end

---@param name any
---@return integer
function VOLUME._CREATE_VOLUME_AGGREGATE_WITH_CUSTOM_NAME(name) end

---@param volume integer
---@param aggregate integer
function VOLUME._ADD_BOUNDS_TO_AGGREGATE_VOLUME(volume, aggregate) end

---@param volume integer
---@param aggregate integer
function VOLUME._REMOVE_BOUNDS_FROM_AGGREGATE_VOLUME(volume, aggregate) end

---@param aggregate integer
---@param typeHash integer
---@param x number
---@param y number
---@param z number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param scaleX number
---@param scaleY number
---@param scaleZ number
function VOLUME._ADD_VOLUME_TO_VOLUME_AGGREGATE(aggregate, typeHash, x, y, z, rotX, rotY, rotZ, scaleX, scaleY, scaleZ) end

---@param aggregate integer
---@param p1 number
---@param p2 number
---@param p3 number
---@param p4 number
---@param p5 number
---@param p6 number
---@param p7 number
---@param p8 number
---@param p9 number
function VOLUME._ADD_BOX_VOLUME_TO_VOLUME_AGGREGATE(aggregate, p1, p2, p3, p4, p5, p6, p7, p8, p9) end

---@param aggregate integer
---@param p1 number
---@param p2 number
---@param p3 number
---@param p4 number
---@param p5 number
---@param p6 number
---@param p7 number
---@param p8 number
---@param p9 number
function VOLUME._ADD_CYLINDER_VOLUME_TO_VOLUME_AGGREGATE(aggregate, p1, p2, p3, p4, p5, p6, p7, p8, p9) end

---@param aggregate integer
---@param p1 number
---@param p2 number
---@param p3 number
---@param p4 number
---@param p5 number
---@param p6 number
---@param p7 number
---@param p8 number
---@param p9 number
function VOLUME._ADD_SPHERE_VOLUME_TO_VOLUME_AGGREGATE(aggregate, p1, p2, p3, p4, p5, p6, p7, p8, p9) end

---@param volume integer
function VOLUME.DELETE_VOLUME(volume) end

---@param volume integer
---@return boolean
function VOLUME.DOES_VOLUME_EXIST(volume) end

---@param volume integer
---@param x number
---@param y number
---@param z number
---@return boolean
function VOLUME.IS_POINT_IN_VOLUME(volume, x, y, z) end

---@param volume integer
---@return Vector3
function VOLUME.GET_VOLUME_COORDS(volume) end

---@param volume integer
---@param posX number
---@param posY number
---@param posZ number
---@return boolean
function VOLUME.SET_VOLUME_COORDS(volume, posX, posY, posZ) end

---@param volume integer
---@return Vector3
function VOLUME.GET_VOLUME_ROTATION(volume) end

---@param volume integer
---@param rotX number
---@param rotY number
---@param rotZ number
---@return boolean
function VOLUME.SET_VOLUME_ROTATION(volume, rotX, rotY, rotZ) end

---@param volume integer
---@return Vector3
function VOLUME.GET_VOLUME_SCALE(volume) end

---@param volume integer
---@param scaleX number
---@param scaleY number
---@param scaleZ number
---@return boolean
function VOLUME.SET_VOLUME_SCALE(volume, scaleX, scaleY, scaleZ) end

---@param volume integer
---@param min Vector3
---@param max Vector3
---@return Vector3
---@return Vector3
function VOLUME._GET_VOLUME_BOUNDS(volume, min, max) end

---@param p0 boolean
function VOLUME._0x748C5F51A18CB8F0(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@return any
function VOLUME._0x2B32B11520626229(p0, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
---@return any
function VOLUME._0x40F769D31A00D5A0(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@return Vector3
function VOLUME._0xD882C5B3991575B7(p0, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
function VOLUME._0xB469CFD9E065EB99(p0, p1) end

---@param p0 any
---@return any
function VOLUME._0x7FD78DFD0C5D7B9B(p0) end

---@param p0 any
---@param p1 any
---@return any
function VOLUME._0xEE1D6FF54CAF7714(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function VOLUME._0xD52DF30355EA7C8E(p0, p1, p2) end

---@param volume integer
---@param persChar integer
---@param p2 boolean
function VOLUME.SET_VOLUME_OWNER_PERSISTENT_CHARACTER(volume, persChar, p2) end

---@param p0 any
function VOLUME._0x6D5F9E69BA1BE783(p0) end

---@param p0 any
function VOLUME._0x998202B206872672(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
function VOLUME._0x4A8FEFC43FD8AC9B(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function VOLUME._0xF3A2FBA5985C8CD5(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function VOLUME._0x53D05D60E5F5B40C(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@return any
function VOLUME._0xCA5C90D40665D5CE(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function VOLUME._0x3EFABB21E14A6BD1(p0, p1, p2) end

---@param volume integer
---@return boolean
function VOLUME._IS_AGGREGATE_VOLUME(volume) end

---@param x number
---@param y number
---@param z number
---@param radius number
---@param flag integer
---@param p5 any
---@return integer
function VOLUME._CREATE_VOLUME_LOCK(x, y, z, radius, flag, p5) end

---@param entity integer
---@param radius number
---@param flag integer
---@param p3 any
---@return integer
function VOLUME._CREATE_VOLUME_LOCK_ATTACHED_TO_ENTITY(entity, radius, flag, p3) end

---@param volLockRequestId integer
---@return boolean
function VOLUME._IS_VOLUME_LOCK_REQUEST_VALID_2(volLockRequestId) end

---@param volLockRequestId integer
---@return Vector3
function VOLUME._0xC4019CF9AE8E931A(volLockRequestId) end

---@param p0 any
---@return any
function VOLUME._0xF6CE6F9C3897804E(p0) end

---@param p0 any
---@return any
function VOLUME._0xF6F5447D418DAA82(p0) end

---@param p0 any
---@param p1 any
function VOLUME._0xD4FA73FE628FEC63(p0, p1) end

---@param volume integer
---@param p1 any
function VOLUME._0xB440F4E35393FC39(volume, p1) end

---@param volume integer
---@param p1 any
function VOLUME._0xD460135C98940274(volume, p1) end

---@param p0 any
---@param p1 any
function VOLUME._0xEBA87B9273835CF3(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@return any
function VOLUME._0xAA9EE2AAFC717623(p0, p1, p2, p3, p4, p5) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@return any
function VOLUME._0x870E9981ED27C815(p0, p1, p2, p3, p4, p5) end

---@param x number
---@param y number
---@param z number
---@param radius number
---@param p4 boolean
---@param p5 integer
---@param p6 integer
---@return boolean
function VOLUME.DOES_VOLUME_COLLIDE_WITH_ANY_VOLUME_LOCK(x, y, z, radius, p4, p5, p6) end

---@param x number
---@param y number
---@param z number
---@param radius number
---@param p4 integer
---@param p5 integer
---@param flags integer
---@return boolean
function VOLUME._IS_POINT_NEAR_VOLUME_LOCK_CENTER(x, y, z, radius, p4, p5, flags) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@return any
function VOLUME._0x51E52C9687FCDEEC(p0, p1, p2, p3, p4, p5, p6) end

---@param args integer
---@return integer
function VOLUME._FIND_VOLUME_LOCK_REQUEST_ID_WITH_ARGS(args) end

---@param volLock integer
---@param x number
---@param y number
---@param z number
function VOLUME._MODIFY_VOLUME_LOCK_LOCATION(volLock, x, y, z) end

---@param p0 any
---@param p1 any
function VOLUME._0x695DAC2DB928F308(p0, p1) end

---@param volLockRequestId integer
function VOLUME._RELEASE_LOCK_VOLUME(volLockRequestId) end

---@param p0 any
function VOLUME._0xAC355980681A7F89(p0) end

---@param args integer
---@return boolean
function VOLUME._ADD_ENTRY_VOLUME_LOCK(args) end

function VOLUME._0xC61E2FD926DBB406() end

---@param x number
---@param y number
---@param z number
---@param radius number
---@param p4 integer
---@param p5 integer
---@return integer
function VOLUME.REQUEST_VOLUME_LOCK(x, y, z, radius, p4, p5) end

---@param args integer
---@return integer
function VOLUME.REQUEST_VOLUME_LOCK_WITH_ARGS(args) end

---@param volLockRequestId integer
---@return boolean
function VOLUME.IS_VOLUME_LOCK_REQUEST_VALID(volLockRequestId) end

---@param volLockRequestId integer
---@return integer
function VOLUME.GET_VOLUME_LOCK_REQUEST_STATUS(volLockRequestId) end

---@param p0 any
---@return any
function VOLUME._0x351D71B8B72B858B(p0) end

function VOLUME._0xFA15C9A320E707B0() end

---@param p0 any
---@param p1 any
---@param p2 any
function VOLUME._0x52572B331E693AED(p0, p1, p2) end

---@param p0 any
function VOLUME._0x128FC3A893BF853A(p0) end

---@param volume integer
---@param relationshipGroup integer
function VOLUME._SET_VOLUME_RELATIONSHIP(volume, relationshipGroup) end

---@param volume integer
---@return integer
function VOLUME._GET_VOLUME_RELATIONSHIP(volume) end
