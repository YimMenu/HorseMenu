---@meta

---@class Vector3
---@overload fun(): Vector3
---@overload fun(x: number, y: number, z: number): Vector3
---@field x number The X component of the vector.
---@field y number The Y component of the vector.
---@field z number The Z component of the vector.
---@operator len(): number
---@operator add(Vector3|number): Vector3
---@operator sub(Vector3|number): Vector3
---@operator mul(Vector3|number): Vector3
---@operator div(Vector3|number): Vector3
Vector3 = {}

-- Returns true if all components of the vector are zero.
---@return boolean 
function Vector3:IsZero() end

-- Returns the magnitude of the vector. The length operator (`#`) does the same thing: `local mag = #myVec`
---@return number mag The magnitude of the vector.
function Vector3:Magnitude() end

-- Returns the distance between this vector and another.
---@param other Vector3 
---@return number dist The distance between the two vectors.
function Vector3:Distance(other) end

-- Linearly interpolates this vector to target vector over delta time.
---@param other Vector3 
---@param dt number Delta
---@return Vector3 
function Vector3:Lerp(other, dt) end
