---@meta

---@class Entity
---@overload fun(handle: integer): Entity
Entity = {}

---@return boolean 
function Entity:IsValid() end

---@return boolean 
function Entity:IsDead() end

---@return boolean 
function Entity:IsPed() end

---@return boolean 
function Entity:IsVehicle() end

---@return boolean 
function Entity:IsObject() end

---@return boolean 
function Entity:IsPlayer() end

---@return boolean 
function Entity:IsAnimal() end

---@return boolean 
function Entity:IsMissionEntity() end

---@return boolean 
function Entity:IsNetworked() end

---@return boolean 
function Entity:IsVisible() end

---@return boolean 
function Entity:IsInvincible() end

---@return boolean 
function Entity:HasInterior() end

---@return integer handle RAGE script handle
function Entity:GetHandle() end

---@return integer alpha Current transparency value (0-255)
function Entity:GetAlpha() end

---@param alpha integer Transparency value (0-255)
function Entity:SetAlpha(alpha) end

-- Restores the entity's default alpha value.
function Entity:ResetAlpha() end

---@return Vector3 pos the entity's current coordinates.
function Entity:GetPosition() end

---@param pos Vector3 
function Entity:SetPosition(pos) end

---@param order integer? The order of rotation (0 = XYZ, 1 = XZY, 2 = YXZ, 3 = YZX, 4 = ZXY, 5 = ZYX). Defaults to 2
---@return Vector3 rot the entity's current rotation vector.
function Entity:GetRotation(order) end

---@param rot Vector3 
---@param order integer? The order of rotation (0 = XYZ, 1 = XZY, 2 = YXZ, 3 = YZX, 4 = ZXY, 5 = ZYX). Defaults to 2
function Entity:SetRotation(rot, order) end

---@return Vector3 velocity
function Entity:GetVelocity() end

---@param vel Vector3 
function Entity:SetVelocity(vel) end

---@return integer hash Entity model hash.
function Entity:GetModel() end

---@return number maxHp
function Entity:GetMaxHealth() end

---@return number hp
function Entity:GetHealth() end

-- **WARNING:** Do not use this method on other players.
---@param hp number 
function Entity:SetHealth(hp) end

-- **WARNING:** Do not use this method on other players.
---@param enabled boolean 
function Entity:SetCollision(enabled) end

-- **WARNING:** Do not use this method on other players.
---@param enabled boolean 
function Entity:SetFrozen(enabled) end

-- **WARNING:** Do not use this method on other players.
---@param enabled boolean 
function Entity:SetInvincible(enabled) end

-- **WARNING:** Do not use this method on players.
function Entity:Kill() end

-- **WARNING:** Do not use this method on players.
function Entity:Delete() end
