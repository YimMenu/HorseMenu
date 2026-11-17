---@meta

---@class Entities
Entities = {}

---@return table<integer,integer> peds Array of handles
function Entities.GetAllPedsAsHandles() end

---@return table<integer,integer> vehicles Array of handles
function Entities.GetAllVehiclesAsHandles() end

---@return table<integer,integer> objects Array of handles
function Entities.GetAllObjectsAsHandles() end

---@return table<integer,integer> pickups Array of handles
function Entities.GetAllPickupsAsHandles() end

---@param blipIndex integer 
---@return integer ped entity handle or 0
function Entities.GetPedFromBlip(blipIndex) end

---@param blipIndex integer 
---@return integer vehicle entity handle or 0
function Entities.GetVehicleFromBlip(blipIndex) end

---@param blipIndex integer 
---@return integer object entity handle or 0
function Entities.GetObjectFromBlip(blipIndex) end
