---@meta

---@class Ped : Entity
---@overload fun(handle: integer): Ped
Ped = {}

---@return boolean 
function Ped:IsEnemy() end

---@return Ped mount The ped's current mount, if any.
function Ped:GetMount() end

---@return Ped mount The ped's last mount, if any.
function Ped:GetLastMount() end

---@return Vehicle vehicle The ped's current vehicle, if any.
function Ped:GetVehicle() end

---@return number 
function Ped:GetMaxStamina() end

---@return number 
function Ped:GetStamina() end

---@param value number 
function Ped:SetStamina(value) end

---@return boolean 
function Ped:GetRagdoll() end

---@param enabled boolean 
function Ped:SetRagdoll(enabled) end

---@param bone integer The bone index.
---@return Vector3 bonePos The world position of the specified bone.
function Ped:GetBonePosition(bone) end
