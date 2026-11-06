<!-- markdownlint-disable -->

# Util

## Methods

## `Joaat`

```lua
function Util.Joaat(str) end
```

Computes the Jenkins one-at-a-time hash of a string.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `str` | `string` |  |

### Returns

| Type | Description |
| --- | --- |
| `integer` | hash |

## `WarpIntoVehicle`

```lua
function Util.WarpIntoVehicle(ped, vehicle) end
```

Warps the ped into the provided vehicle.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `ped` | `integer` | ped handle |
| `vehicle` | `integer` | vehicle handle |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | success |

## `LoadGroundAtCoords`

```lua
function Util.LoadGroundAtCoords(coords) end
```

Loads ground at the provided coordinates.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `coords` | `Vector3` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | success |

## `GetWaypointCoords`

```lua
function Util.GetWaypointCoords() end
```

Returns the current waypoint coordinates. If no waypoint is set, returns a zero vector.

### Returns

| Type | Description |
| --- | --- |
| `Vector3` | waypoint |

## `TeleportPlayerToCoords`

```lua
function Util.TeleportPlayerToCoords(player, coords) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `player` | `Player` |  |
| `coords` | `Vector3` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | success |

## `Teleport`

```lua
function Util.Teleport(entity, coords, loadGround) end
```

Teleports the entity to the desired coordinates.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `entity` | `integer` | entity handle |
| `coords` | `Vector3` |  |
| `loadGround` | `boolean?` | Load ground at the destination before teleporting the entity. Prevents falling through the map. |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | success |

## `GetScreenResolution`

```lua
function Util.GetScreenResolution() end
```

Returns the game's screen resolution or a zero vector on failure.

### Returns

| Type | Description |
| --- | --- |
| `Vector2` |  |
