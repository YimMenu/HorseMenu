---@meta

---@class AITRANSPORT
AITRANSPORT = {}

---@param args integer
function AITRANSPORT.TASK_ENTER_TRANSPORT(args) end

---@param args integer
function AITRANSPORT.TASK_EXIT_TRANSPORT(args) end

---@param ped integer
---@param transportEntity integer
---@param seat integer
---@param flags integer
function AITRANSPORT.SET_PED_ON_TRANSPORT_SEAT(ped, transportEntity, seat, flags) end

---@param ped integer
---@param flags integer
function AITRANSPORT.SET_PED_OFF_TRANSPORT_SEAT(ped, flags) end

---@param transportEntity integer
---@param flagId integer
---@param value boolean
function AITRANSPORT.SET_TRANSPORT_CONFIG_FLAG(transportEntity, flagId, value) end

---@param transportEntity integer
---@param flagId integer
---@param p2 boolean
---@return boolean
function AITRANSPORT.GET_TRANSPORT_CONFIG_FLAG(transportEntity, flagId, p2) end

---@param transportEntity integer
---@param flags integer
---@return any
---@return integer
function AITRANSPORT._GET_TRANSPORT_USAGE_FLAGS(transportEntity, flags) end

---@param transportEntity integer
---@param flags integer
function AITRANSPORT._SET_TRANSPORT_USAGE_FLAGS(transportEntity, flags) end

---@param transportEntity integer
---@param flags integer
function AITRANSPORT.SET_TRANSPORT_ACCESSIBLE_SEAT_FLAGS(transportEntity, flags) end

---@param p0 any
---@param p1 any
function AITRANSPORT._0x4B6C9A43F7D9109B(p0, p1) end

---@param ped integer
---@param transportEntity integer
---@return boolean
function AITRANSPORT._IS_PED_ON_TRANSPORT_ENTITY(ped, transportEntity) end

---@param ped integer
---@param p1 boolean
---@return boolean
function AITRANSPORT._IS_PED_ON_TRANSPORT_SEAT(ped, p1) end

---@param transportEntity integer
---@param seatIndex integer
---@return boolean
function AITRANSPORT._IS_TRANSPORT_SEAT_OCCUPIED(transportEntity, seatIndex) end

---@param transportEntity integer
---@param seatIndex integer
---@return boolean
function AITRANSPORT._IS_TRANSPORT_SEAT_FREE(transportEntity, seatIndex) end

---@param transportEntity integer
---@param seatIndex integer
---@return integer
function AITRANSPORT._GET_PED_IN_TRANSPORT_SEAT(transportEntity, seatIndex) end

---@param ped integer
---@param transportEntity integer
---@param p2 boolean
---@return boolean
function AITRANSPORT.IS_PED_ENTERING_TRANSPORT(ped, transportEntity, p2) end

---@param ped integer
---@param transportEntity integer
---@return boolean
function AITRANSPORT.IS_PED_EXITING_TRANSPORT(ped, transportEntity) end

---@param transportEntity integer
---@param ped integer
---@param p2 boolean
function AITRANSPORT._0x4248AB2EEB3C75AD(transportEntity, ped, p2) end

---@param ped integer
---@param transportEntity integer
---@param preferenceSlot integer
---@param p3 integer
---@param seatIndex integer
function AITRANSPORT._SET_PED_USE_TRANSPORT_SEAT_PREFERENCE(ped, transportEntity, preferenceSlot, p3, seatIndex) end

---@param transportEntity integer
function AITRANSPORT._0x5639FBEA922788DA(transportEntity) end

---@param transportEntity integer
---@param state boolean
function AITRANSPORT._SET_AI_CAN_USE_TRANSPORT(transportEntity, state) end

---@param ped integer
---@param p1 number
function AITRANSPORT._0x8C8371EDFAF014A0(ped, p1) end

---@param ped integer
function AITRANSPORT._0xF8C20282B237E3F7(ped) end

---@param transportEntity integer
---@param seatIndex integer
function AITRANSPORT._SET_TRANSPORT_PRIORITY_SEAT(transportEntity, seatIndex) end
