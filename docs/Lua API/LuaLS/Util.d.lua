---@meta

---@class Util
Util = {}

-- Computes the Jenkins one-at-a-time hash of a string.
---@param str string 
---@return integer hash
function Util.Joaat(str) end

-- Warps the ped into the provided vehicle.
---@param ped integer ped handle
---@param vehicle integer vehicle handle
---@return boolean success
function Util.WarpIntoVehicle(ped, vehicle) end

-- Loads ground at the provided coordinates.
---@param coords Vector3 
---@return boolean success
function Util.LoadGroundAtCoords(coords) end

-- Returns the current waypoint coordinates. If no waypoint is set, returns a zero vector.
---@return Vector3 waypoint
function Util.GetWaypointCoords() end

---@param player Player 
---@param coords Vector3 
---@return boolean success
function Util.TeleportPlayerToCoords(player, coords) end

-- Teleports the entity to the desired coordinates.
---@param entity integer entity handle
---@param coords Vector3 
---@param loadGround boolean? Load ground at the destination before teleporting the entity. Prevents falling through the map.
---@return boolean success
function Util.Teleport(entity, coords, loadGround) end

-- Returns the game's screen resolution or a zero vector on failure.
---@return Vector2 
function Util.GetScreenResolution() end
