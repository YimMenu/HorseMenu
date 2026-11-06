---@meta

---@class PHYSICS
PHYSICS = {}

---@param posX number
---@param posY number
---@param posZ number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param len number
---@param ropeType integer
---@param maxLength number
---@param minLength number
---@param p10 number
---@param p11 boolean
---@param p12 boolean
---@param rigid boolean
---@param p14 number
---@param breakWhenShot boolean
---@param unkPtr integer
---@param p17 boolean
---@return integer
function PHYSICS.ADD_ROPE(posX, posY, posZ, rotX, rotY, rotZ, len, ropeType, maxLength, minLength, p10, p11, p12, rigid, p14, breakWhenShot, unkPtr, p17) end

---@param x number
---@param y number
---@param z number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param length number
---@param ropeType integer
---@param isNetworked boolean
---@param p9 integer
---@param p10 number
---@return integer
function PHYSICS._ADD_ROPE_2(x, y, z, rotX, rotY, rotZ, length, ropeType, isNetworked, p9, p10) end

---@param ropeID integer
---@return integer
function PHYSICS.DELETE_ROPE(ropeID) end

---@param ropeId integer
function PHYSICS._RELEASE_ROPE(ropeId) end

---@param ropeID integer
function PHYSICS.DELETE_CHILD_ROPE(ropeID) end

---@param ropeId integer
---@param ropeTop integer
---@param ropeBottom integer
---@param offsetX number
---@param offsetY number
---@param offsetZ number
---@param p6 integer
---@return integer
---@return integer
---@return integer
function PHYSICS._BREAK_ROPE(ropeId, ropeTop, ropeBottom, offsetX, offsetY, offsetZ, p6) end

---@param ropeID integer
---@return boolean
function PHYSICS.DOES_ROPE_EXIST(ropeID) end

---@param ropeId integer
---@return boolean
function PHYSICS._IS_ROPE_BROKEN(ropeId) end

---@param ropeId integer
---@param visible boolean
---@return integer
function PHYSICS._ROPE_CHANGE_VISIBILITY(ropeId, visible) end

---@param ropeID integer
---@param isDrawEnabled boolean
---@return integer
function PHYSICS.ROPE_DRAW_SHADOW_ENABLED(ropeID, isDrawEnabled) end

---@param ropeID integer
---@return integer
function PHYSICS.GET_ROPE_VERTEX_COUNT(ropeID) end

---@param ropeId integer
---@param p1 integer
---@param x number
---@param y number
---@param z number
function PHYSICS._0xE54BF2CE6C7D23A9(ropeId, p1, x, y, z) end

---@param p0 any
function PHYSICS._0x9C24846D0A4A2776(p0) end

---@param p0 any
function PHYSICS._0x0CB16D05E03FB525(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function PHYSICS._0xF27F1A8DE4F50A1B(p0, p1, p2, p3, p4, p5, p6) end

---@param ropeId integer
---@param p1 boolean
---@param p2 number
---@param p3 number
---@param p4 number
---@param p5 number
---@param p6 number
---@param p7 number
---@param p8 number
---@param p9 number
---@param p10 integer
function PHYSICS._0x21D0890D88DFB0B0(ropeId, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) end

---@param ropeID integer
---@param iEntityAID integer
---@param iEntityBID integer
---@param worldPositionAX number
---@param worldPositionAY number
---@param worldPositionAZ number
---@param worldPositionBX number
---@param worldPositionBY number
---@param worldPositionBZ number
---@param ropeLength number
---@param componentPartA integer
---@param componentPartB integer
---@param boneNamePartA any
---@param boneNamePartB any
---@param p14 boolean
---@param boneId1 integer
---@param boneId2 integer
---@param alwaysZero3 integer
---@param alwaysZero4 integer
---@param p19 boolean
---@param p20 boolean
function PHYSICS.ATTACH_ENTITIES_TO_ROPE(ropeID, iEntityAID, iEntityBID, worldPositionAX, worldPositionAY, worldPositionAZ, worldPositionBX, worldPositionBY, worldPositionBZ, ropeLength, componentPartA, componentPartB, boneNamePartA, boneNamePartB, p14, boneId1, boneId2, alwaysZero3, alwaysZero4, p19, p20) end

---@param ropeId integer
---@param entity1 integer
---@param entity2 integer
---@param ent1X number
---@param ent1Y number
---@param ent1Z number
---@param ent2X number
---@param ent2Y number
---@param ent2Z number
---@param boneName1 any
---@param boneName2 any
function PHYSICS._ATTACH_ENTITIES_TO_ROPE_2(ropeId, entity1, entity2, ent1X, ent1Y, ent1Z, ent2X, ent2Y, ent2Z, boneName1, boneName2) end

---@param ropeId integer
---@param entity1 integer
---@param entity2 integer
---@param p3 number
---@param p4 number
---@param p5 number
---@param p6 number
---@param p7 number
---@param p8 number
---@param p9 any
---@param p10 any
function PHYSICS._ATTACH_ENTITES_TO_ROPE_3(ropeId, entity1, entity2, p3, p4, p5, p6, p7, p8, p9, p10) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function PHYSICS._0x69C810B72291D831(p0, p1, p2, p3, p4, p5, p6) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
function PHYSICS._0xB7469CB9AC3C0FD4(p0, p1, p2, p3, p4, p5, p6, p7) end

---@param ropeId integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
function PHYSICS._0xC64E7A62632AD2FE(ropeId, p1, p2, p3, p4, p5, p6, p7) end

---@param ropeId integer
---@param entity integer
---@return boolean
function PHYSICS._IS_ROPE_ATTACHED_TO_ENTITY(ropeId, entity) end

---@param ropeID integer
---@param iEntityID integer
function PHYSICS.DETACH_ROPE_FROM_ENTITY(ropeID, iEntityID) end

---@param horse integer
---@param x number
---@param y number
---@param z number
function PHYSICS._HITCH_HORSE(horse, x, y, z) end

---@param horse integer
function PHYSICS._UNHITCH_HORSE(horse) end

---@param p0 any
function PHYSICS._0x6EA0E93CFFA472CC(p0) end

---@param p0 any
function PHYSICS._0xBDDA142759307528(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
function PHYSICS._0x32F4DBFDFCCCC735(p0, p1, p2) end

---@param p0 any
---@param p1 any
function PHYSICS._0xF8CA39D5C0D1D9A1(p0, p1) end

---@param p0 any
function PHYSICS._0xEAF529446488EB18(p0) end

---@param p0 any
---@param p1 any
function PHYSICS._0x31160EC47E7C9549(p0, p1) end

---@param p0 any
---@param p1 any
function PHYSICS._0x5E981C764DF33117(p0, p1) end

---@param ropeID integer
---@param iUpdateOrder integer
function PHYSICS.ROPE_SET_UPDATE_ORDER(ropeID, iUpdateOrder) end

---@param ropeId integer
---@param p1 boolean
function PHYSICS._0xFB9153A54AC713E8(ropeId, p1) end

---@param ropeId integer
---@param p1 number
---@param p2 number
---@param p3 number
---@param p4 boolean
function PHYSICS._0xD699E688B49C0FD2(ropeId, p1, p2, p3, p4) end

---@param ropeId integer
---@param p1 boolean
---@param p2 boolean
---@param p3 boolean
---@param p4 boolean
function PHYSICS._0xBB3E9B073E66C3C9(ropeId, p1, p2, p3, p4) end

---@param ropeId integer
---@param p1 any
---@param p2 any
function PHYSICS._0x522FA3F490E2F7AC(ropeId, p1, p2) end

---@param p0 any
---@param p1 any
function PHYSICS._0x3900491C0D61ED4B(p0, p1) end

---@param ropeId integer
---@param p1 number
function PHYSICS._0xC89E7410A93AC19A(ropeId, p1) end

---@param ropeId integer
---@param p1 integer
function PHYSICS._0x1D97DA8ACB5D2582(ropeId, p1) end

---@param ropeId integer
---@param p1 any
---@param ropeModelType any
---@param length number
---@param p4 boolean
function PHYSICS._CREATE_ROPE_WINDING_ABILITY(ropeId, p1, ropeModelType, length, p4) end

---@param ropeID integer
---@return Vector3
function PHYSICS.GET_ROPE_LAST_VERTEX_COORD(ropeID) end

---@param ropeID integer
---@param vtxIndex integer
---@return Vector3
function PHYSICS.GET_ROPE_VERTEX_COORD(ropeID, vtxIndex) end

---@param ropeID integer
function PHYSICS.START_ROPE_WINDING(ropeID) end

---@param ropeID integer
function PHYSICS.STOP_ROPE_WINDING(ropeID) end

---@param ropeID integer
function PHYSICS.START_ROPE_UNWINDING_FRONT(ropeID) end

---@param ropeID integer
function PHYSICS.STOP_ROPE_UNWINDING_FRONT(ropeID) end

---@param ropeId integer
function PHYSICS._START_ROPE_UNWINDING_BACK(ropeId) end

---@param ropeId integer
function PHYSICS._STOP_ROPE_UNWINDING_BACK(ropeId) end

---@param ropeId integer
---@param p1 boolean
function PHYSICS._0x461FCBDEB4D06717(ropeId, p1) end

---@param p0 any
---@param p1 any
function PHYSICS._0x423C6B1F3786D28B(p0, p1) end

---@param ropeId integer
---@param p1 number
function PHYSICS._0x76BAD9D538BCA1AA(ropeId, p1) end

---@param ropeId integer
---@param p1 number
function PHYSICS._0xB40EA9E0D2E2F7F3(ropeId, p1) end

---@param ropeId integer
---@return number
function PHYSICS._ROPE_GET_FORCED_LENGTH(ropeId) end

---@param p0 any
function PHYSICS._0x751DF00EEFF122E3(p0) end

---@param ropeID integer
---@param len number
function PHYSICS.ROPE_FORCE_LENGTH(ropeID, len) end

---@param ropeId integer
---@param p1 number
function PHYSICS._0x8D59079C37C21D78(ropeId, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function PHYSICS._0x814D453FCFDF119F(p0, p1, p2) end

---@param ropeId integer
---@param p1 number
function PHYSICS._0x1FC92BDBA1106BD2(ropeId, p1) end

---@param ropeId integer
---@param p1 boolean
function PHYSICS._0xDEDE679ED29DD4E7(ropeId, p1) end

---@param ropeId integer
---@param p1 boolean
function PHYSICS._0xF1EA2A881EB7F2CD(ropeId, p1) end

---@param p0 any
---@param p1 any
function PHYSICS._0x5A989B7EE3672A56(p0, p1) end

---@param p0 any
---@param p1 any
function PHYSICS._0x483D4E917B0D35A9(p0, p1) end

---@param ropeId integer
---@return integer
function PHYSICS._ROPE_GET_BREAKER_OF_ROPE(ropeId) end

---@param entityID integer
---@param dampingType integer
---@param dampingValue number
function PHYSICS.SET_DAMPING(entityID, dampingType, dampingValue) end

---@param entityID integer
function PHYSICS.ACTIVATE_PHYSICS(entityID) end

---@param entityId integer
---@param impactPositionX number
---@param impactPositionY number
---@param impactPositionZ number
---@param impactRadius number
---@param impulseX number
---@param impulseY number
---@param impulseZ number
---@param damage number
---@param crackType integer
---@param silent boolean
function PHYSICS.BREAK_ENTITY_GLASS(entityId, impactPositionX, impactPositionY, impactPositionZ, impactRadius, impulseX, impulseY, impulseZ, damage, crackType, silent) end

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
function PHYSICS._0x8EEDFD8921389928(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9) end

---@param entityId integer
---@param disableBreaking boolean
function PHYSICS.SET_DISABLE_BREAKING(entityId, disableBreaking) end

---@param entityId integer
---@param disableDamage boolean
function PHYSICS.SET_DISABLE_FRAG_DAMAGE(entityId, disableDamage) end

---@param p0 any
---@param p1 any
function PHYSICS._0x5BD7457221CC5FF4(p0, p1) end
