---@meta

---@class INTERIOR
INTERIOR = {}

---@param InteriorInstanceIndex integer
---@return boolean
function INTERIOR.IS_VALID_INTERIOR(InteriorInstanceIndex) end

---@param interior integer
---@param position Vector3
---@param nameHash integer
---@return Vector3
---@return integer
function INTERIOR.GET_INTERIOR_LOCATION_AND_NAMEHASH(interior, position, nameHash) end

---@param interior integer
---@return integer
function INTERIOR._GET_INTERIOR_MINIMAP_HASH(interior) end

---@param interior integer
---@return Vector3
function INTERIOR._GET_INTERIOR_POSITION(interior) end

---@return boolean
function INTERIOR.IS_INTERIOR_SCENE() end

---@param EntityIndex integer
function INTERIOR.CLEAR_ROOM_FOR_ENTITY(EntityIndex) end

---@param EntityIndex integer
---@param InteriorInstanceIndex integer
---@param RoomKey integer
function INTERIOR.FORCE_ROOM_FOR_ENTITY(EntityIndex, InteriorInstanceIndex, RoomKey) end

---@param EntityIndex integer
---@return integer
function INTERIOR.GET_ROOM_KEY_FROM_ENTITY(EntityIndex) end

---@param EntityIndex integer
---@return integer
function INTERIOR.GET_KEY_FOR_ENTITY_IN_ROOM(EntityIndex) end

---@param EntityIndex integer
---@return integer
function INTERIOR.GET_INTERIOR_FROM_ENTITY(EntityIndex) end

---@param EntityIndex integer
---@param InteriorInstanceIndex integer
function INTERIOR.RETAIN_ENTITY_IN_INTERIOR(EntityIndex, InteriorInstanceIndex) end

---@param InteriorInstanceIndex integer
---@param RoomKey integer
function INTERIOR.FORCE_ROOM_FOR_GAME_VIEWPORT(InteriorInstanceIndex, RoomKey) end

function INTERIOR.CLEAR_ROOM_FOR_GAME_VIEWPORT() end

---@return integer
function INTERIOR.GET_INTERIOR_FROM_PRIMARY_VIEW() end

---@param VecInCoorsX number
---@param VecInCoorsY number
---@param VecInCoorsZ number
---@return integer
function INTERIOR.GET_INTERIOR_AT_COORDS(VecInCoorsX, VecInCoorsY, VecInCoorsZ) end

---@param InteriorInstanceIndex integer
function INTERIOR.PIN_INTERIOR_IN_MEMORY(InteriorInstanceIndex) end

---@param InteriorInstanceIndex integer
function INTERIOR.UNPIN_INTERIOR(InteriorInstanceIndex) end

---@param InteriorInstanceIndex integer
---@return boolean
function INTERIOR.IS_INTERIOR_READY(InteriorInstanceIndex) end

---@param InteriorInstanceIndex integer
---@return boolean
function INTERIOR.SET_INTERIOR_IN_USE(InteriorInstanceIndex) end

---@param VecInCoorsX number
---@param VecInCoorsY number
---@param VecInCoorsZ number
---@param Name any
---@return integer
function INTERIOR.GET_INTERIOR_AT_COORDS_WITH_TYPE(VecInCoorsX, VecInCoorsY, VecInCoorsZ, Name) end

---@param VecInCoorsX number
---@param VecInCoorsY number
---@param VecInCoorsZ number
---@param NameHash integer
---@return integer
function INTERIOR.GET_INTERIOR_AT_COORDS_WITH_TYPEHASH(VecInCoorsX, VecInCoorsY, VecInCoorsZ, NameHash) end

---@param VecInCoorsX number
---@param VecInCoorsY number
---@param VecInCoorsZ number
---@return boolean
function INTERIOR.IS_COLLISION_MARKED_OUTSIDE(VecInCoorsX, VecInCoorsY, VecInCoorsZ) end

---@param VecInCoorsX number
---@param VecInCoorsY number
---@param VecInCoorsZ number
---@return integer
function INTERIOR.GET_INTERIOR_FROM_COLLISION(VecInCoorsX, VecInCoorsY, VecInCoorsZ) end

---@param InteriorInstanceIndex integer
---@param entitySetName any
---@param p2 integer
function INTERIOR.ACTIVATE_INTERIOR_ENTITY_SET(InteriorInstanceIndex, entitySetName, p2) end

---@param InteriorInstanceIndex integer
---@param entitySetName any
---@param p2 boolean
function INTERIOR.DEACTIVATE_INTERIOR_ENTITY_SET(InteriorInstanceIndex, entitySetName, p2) end

---@param InteriorInstanceIndex integer
---@param entitySetName any
---@return boolean
function INTERIOR.IS_INTERIOR_ENTITY_SET_ACTIVE(InteriorInstanceIndex, entitySetName) end

---@param interior integer
---@param entitySetName any
---@return boolean
function INTERIOR._IS_INTERIOR_ENTITY_SET_VALID(interior, entitySetName) end

---@param InteriorInstanceIndex integer
---@param bDisable boolean
function INTERIOR.DISABLE_INTERIOR(InteriorInstanceIndex, bDisable) end

---@param p0 any
---@param p1 any
function INTERIOR._0x2533F2AB0EB9C6F9(p0, p1) end

---@param p0 any
---@param p1 any
function INTERIOR._0xFE2B3D5500B1B2E4(p0, p1) end
