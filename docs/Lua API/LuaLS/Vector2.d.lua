---@meta

---@class Vector2
---@overload fun(): Vector2
---@overload fun(x: number, y: number): Vector2
---@field x number The X component of the vector.
---@field y number The Y component of the vector.
---@operator len(): number
---@operator add(Vector2|number): Vector2
---@operator sub(Vector2|number): Vector2
---@operator mul(Vector2|number): Vector2
---@operator div(Vector2|number): Vector2
Vector2 = {}

-- Returns true if all components of the vector are zero.
---@return boolean 
function Vector2:IsZero() end

-- Returns the magnitude of the vector. The length operator (`#`) does the same thing: `local mag = #myVec`
---@return number mag The magnitude of the vector.
function Vector2:Magnitude() end

-- Returns the distance between this vector and another.
---@param other Vector2 
---@return number dist The distance between the two vectors.
function Vector2:Distance(other) end

-- Linearly interpolates this vector to target vector over delta time.
---@param other Vector2 
---@param dt number Delta
---@return Vector2 
function Vector2:Lerp(other, dt) end
