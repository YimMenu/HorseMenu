---@meta

---@class Vehicle : Entity
---@overload fun(handle: integer): Vehicle
Vehicle = {}

---@return boolean isDraft Whether this vehicle is a draft animal vehicle.
function Vehicle:IsDraft() end

---@return integer numDrafts Number of draft animals attached to this vehicle.
function Vehicle:GetNumDraftAnimals() end

---@param slot integer The harness slot index (0-5).
---@return Ped ped The ped in the specified harness slot, if any.
function Vehicle:GetPedInHarness(slot) end
