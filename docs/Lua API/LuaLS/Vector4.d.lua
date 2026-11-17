---@meta

---@class Vector4
---@overload fun(): Vector4
---@overload fun(x: number, y: number, z: number, w: number): Vector4
---@field x number The X component of the vector.
---@field y number The Y component of the vector.
---@field z number The Z component of the vector.
---@field w number The W component of the vector.
---@operator len(): number
---@operator add(Vector4|number): Vector4
---@operator sub(Vector4|number): Vector4
---@operator mul(Vector4|number): Vector4
---@operator div(Vector4|number): Vector4
Vector4 = {}

-- Returns true if all components of the vector are zero.
---@return boolean 
function Vector4:IsZero() end

-- Returns the magnitude of the vector. The length operator (`#`) does the same thing: `local mag = #myVec`
---@return number mag The magnitude of the vector.
function Vector4:Magnitude() end

-- Returns the distance between this vector and another.
---@param other Vector4 
---@return number dist The distance between the two vectors.
function Vector4:Distance(other) end

-- Linearly interpolates this vector to target vector over delta time.
---@param other Vector4 
---@param dt number Delta
---@return Vector4 
function Vector4:Lerp(other, dt) end
