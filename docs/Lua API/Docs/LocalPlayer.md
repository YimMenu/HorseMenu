<!-- markdownlint-disable -->

# LocalPlayer

## Methods

## `GetPed`

```lua
function LocalPlayer:GetPed() end
```

Returns the local player's [Ped](./Ped.md) class instance.

### Returns

| Type | Description |
| --- | --- |
| `Ped` | ped |

## `GetPlayer`

```lua
function LocalPlayer:GetPlayer() end
```

Returns the local player's [Player](./Player.md) class instance.

### Returns

| Type | Description |
| --- | --- |
| `Player` | player |

## `GetMount`

```lua
function LocalPlayer:GetMount() end
```

Returns the local player's mount if any.

### Returns

| Type | Description |
| --- | --- |
| `Ped` | mount |

## `GetVehicle`

```lua
function LocalPlayer:GetVehicle() end
```

Returns the local player's vehicle if any.

### Returns

| Type | Description |
| --- | --- |
| `Vehicle` | vehicle |

## `Teleport`

```lua
function LocalPlayer:Teleport(coords, loadGround) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `coords` | `Vector3` |  |
| `loadGround` | `boolean?` | Optional: load ground at the coordinates before teleporting. Prevents falling through the map. |
