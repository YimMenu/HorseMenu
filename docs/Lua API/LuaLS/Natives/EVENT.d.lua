---@meta

---@class EVENT
EVENT = {}

---@param PedIndex integer
---@param DecisionMakerId integer
function EVENT.SET_DECISION_MAKER(PedIndex, DecisionMakerId) end

---@param ped integer
function EVENT.SET_DECISION_MAKER_TO_DEFAULT(ped) end

---@param args integer
---@return integer
function EVENT._CREATE_SHOCKING_EVENT(args) end

---@param eventType integer
---@param posX number
---@param posY number
---@param posZ number
---@param p4 number
---@param p5 number
---@param p6 number
---@param p7 number
---@param p8 number
---@param p9 integer
---@param p10 integer
---@return integer
function EVENT.ADD_SHOCKING_EVENT_AT_POSITION(eventType, posX, posY, posZ, p4, p5, p6, p7, p8, p9, p10) end

---@param eventType integer
---@param ent integer
---@param p2 number
---@param p3 number
---@param p4 number
---@param p5 number
---@param p6 number
---@param p7 number
---@param p8 boolean
---@param p9 boolean
---@param p10 integer
---@param p11 integer
---@return integer
function EVENT.ADD_SHOCKING_EVENT_FOR_ENTITY(eventType, ent, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11) end

---@param eventType integer
---@param posX number
---@param posY number
---@param posZ number
---@param radius number
---@return boolean
function EVENT.IS_SHOCKING_EVENT_IN_SPHERE(eventType, posX, posY, posZ, radius) end

---@param shockingEventId integer
---@return boolean
function EVENT.REMOVE_SHOCKING_EVENT(shockingEventId) end

---@param scriptCreatedOnly boolean
function EVENT.REMOVE_ALL_SHOCKING_EVENTS(scriptCreatedOnly) end

---@param x number
---@param y number
---@param z number
---@param radius number
---@param p4 boolean
function EVENT._REMOVE_ALL_SHOCKING_EVENTS_IN_AREA(x, y, z, radius, p4) end

---@param eventType integer
---@param x number
---@param y number
---@param z number
---@param radius number
---@param p5 boolean
function EVENT._REMOVE_ALL_SHOCKING_EVENTS_OF_TYPE_IN_AREA(eventType, x, y, z, radius, p5) end

---@param eventType integer
---@param p1 boolean
function EVENT.REMOVE_ALL_SHOCKING_EVENTS_OF_TYPE(eventType, p1) end

function EVENT.REMOVE_SHOCKING_EVENT_SPAWN_BLOCKING_AREAS() end

---@param entity integer
---@param p1 integer
---@return any
function EVENT._0x36D0F2BA2C0D9BDE(entity, p1) end

---@param ped1 integer
---@param ped2 integer
---@param p2 integer
---@param p3 integer
function EVENT._0x7C511E91738A0828(ped1, ped2, p2, p3) end

function EVENT.SUPPRESS_SHOCKING_EVENTS_NEXT_FRAME() end

function EVENT._0xB6F4825153920582() end

---@param p0 number
function EVENT._0x4B2B1A891D437CA7(p0) end

---@param ped integer
---@param p1 boolean
function EVENT._0x9520175B35E2268D(ped, p1) end

---@param volume integer
---@param p1 boolean
---@param p2 boolean
---@return any
function EVENT._0x18E93EBFC1FCFA48(volume, p1, p2) end

---@param p0 any
function EVENT._0x56B3410626A473E7(p0) end

---@param model integer
---@param p1 boolean
---@param p2 boolean
function EVENT._ADD_MODEL_TO_EVENT_MONITOR(model, p1, p2) end

---@param model integer
function EVENT._0x4465C3D1475BD3FD(model) end

---@param object integer
---@param p1 boolean
---@param p2 boolean
---@return any
function EVENT._0x2DD42FAD06E6F19E(object, p1, p2) end

---@param object integer
function EVENT._0xA86B0EE9B39D15D6(object) end

---@param object integer
---@return boolean
function EVENT._0x26054EB81AC0893B(object) end

---@param ped integer
---@param eventName any
---@param p2 integer
function EVENT._SET_EVENT_TRACKER_FOR_PED(ped, eventName, p2) end

---@param entity integer
---@param p1 integer
---@param p2 integer
---@return integer
function EVENT._0xAD17A18215DD23D6(entity, p1, p2) end

---@param entity integer
---@param eventType integer
---@param p2 integer
---@param p3 integer
---@return integer
function EVENT._EVENT_GET_TIME_SINCE_EVENT(entity, eventType, p2, p3) end

---@param entity integer
---@param p1 integer
---@param p2 integer
---@return integer
function EVENT._EVENT_GET_RECENT_EVENT(entity, p1, p2) end

---@param eventName any
---@param shockingEvent integer
---@return boolean
function EVENT._IS_EVENT_TRACKER_ACTIVE(eventName, shockingEvent) end

---@param entity integer
---@param eventType integer
---@param p2 integer
---@param p3 integer
---@return integer
function EVENT._EVENT_GET_SOURCE_ENTITY_FROM_EVENT(entity, eventType, p2, p3) end

---@param entity integer
---@param eventType integer
---@param p2 integer
---@param p3 integer
---@return integer
function EVENT._EVENT_GET_TARGET_ENTITY_FROM_EVENT(entity, eventType, p2, p3) end

---@param ped integer
---@return any
function EVENT._0x1D1B448D719415AB(ped) end

---@param entity integer
---@param p1 integer
---@return any
function EVENT._0x83D43F0FD5276E4D(entity, p1) end

---@param entity integer
---@param eventType integer
---@param p2 integer
function EVENT._0xE28D7FC9FD32ABEB(entity, eventType, p2) end

---@param ped integer
---@param p1 integer
function EVENT._0x1A5C5D350068A673(ped, p1) end

---@param ped integer
function EVENT._EVENT_FLUSH_ALL_EVENT_TRACKERS(ped) end

function EVENT._0xE2C2FBB7825FFC66() end
