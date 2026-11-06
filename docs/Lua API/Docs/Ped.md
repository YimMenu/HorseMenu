<!-- markdownlint-disable -->

# Ped

## Constructors

```lua
Ped(handle)
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `handle` | `integer` | The RAGE script handle of the ped. |
## Methods

## `IsEnemy`

```lua
function Ped:IsEnemy() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `GetMount`

```lua
function Ped:GetMount() end
```

### Returns

| Type | Description |
| --- | --- |
| `Ped` | mount The ped's current mount, if any. |

## `GetLastMount`

```lua
function Ped:GetLastMount() end
```

### Returns

| Type | Description |
| --- | --- |
| `Ped` | mount The ped's last mount, if any. |

## `GetVehicle`

```lua
function Ped:GetVehicle() end
```

### Returns

| Type | Description |
| --- | --- |
| `Vehicle` | vehicle The ped's current vehicle, if any. |

## `GetMaxStamina`

```lua
function Ped:GetMaxStamina() end
```

### Returns

| Type | Description |
| --- | --- |
| `number` |  |

## `GetStamina`

```lua
function Ped:GetStamina() end
```

### Returns

| Type | Description |
| --- | --- |
| `number` |  |

## `SetStamina`

```lua
function Ped:SetStamina(value) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `value` | `number` |  |

## `GetRagdoll`

```lua
function Ped:GetRagdoll() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `SetRagdoll`

```lua
function Ped:SetRagdoll(enabled) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `enabled` | `boolean` |  |

## `GetBonePosition`

```lua
function Ped:GetBonePosition(bone) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `bone` | `integer` | The bone index. |

### Returns

| Type | Description |
| --- | --- |
| `Vector3` | bonePos The world position of the specified bone. |
