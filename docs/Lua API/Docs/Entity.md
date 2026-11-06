<!-- markdownlint-disable -->

# Entity

## Constructors

```lua
Entity(handle)
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `handle` | `integer` | The RAGE script handle of the entity. |
## Methods

## `IsValid`

```lua
function Entity:IsValid() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsDead`

```lua
function Entity:IsDead() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsPed`

```lua
function Entity:IsPed() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsVehicle`

```lua
function Entity:IsVehicle() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsObject`

```lua
function Entity:IsObject() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsPlayer`

```lua
function Entity:IsPlayer() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsAnimal`

```lua
function Entity:IsAnimal() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsMissionEntity`

```lua
function Entity:IsMissionEntity() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsNetworked`

```lua
function Entity:IsNetworked() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsVisible`

```lua
function Entity:IsVisible() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsInvincible`

```lua
function Entity:IsInvincible() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `HasInterior`

```lua
function Entity:HasInterior() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `GetHandle`

```lua
function Entity:GetHandle() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` | handle RAGE script handle |

## `GetAlpha`

```lua
function Entity:GetAlpha() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` | alpha Current transparency value (0-255) |

## `SetAlpha`

```lua
function Entity:SetAlpha(alpha) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `alpha` | `integer` | Transparency value (0-255) |

## `ResetAlpha`

```lua
function Entity:ResetAlpha() end
```

Restores the entity's default alpha value.

## `GetPosition`

```lua
function Entity:GetPosition() end
```

### Returns

| Type | Description |
| --- | --- |
| `Vector3` | pos the entity's current coordinates. |

## `SetPosition`

```lua
function Entity:SetPosition(pos) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `pos` | `Vector3` |  |

## `GetRotation`

```lua
function Entity:GetRotation(order) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `order` | `integer?` | The order of rotation (0 = XYZ, 1 = XZY, 2 = YXZ, 3 = YZX, 4 = ZXY, 5 = ZYX). Defaults to 2 |

### Returns

| Type | Description |
| --- | --- |
| `Vector3` | rot the entity's current rotation vector. |

## `SetRotation`

```lua
function Entity:SetRotation(rot, order) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `rot` | `Vector3` |  |
| `order` | `integer?` | The order of rotation (0 = XYZ, 1 = XZY, 2 = YXZ, 3 = YZX, 4 = ZXY, 5 = ZYX). Defaults to 2 |

## `GetVelocity`

```lua
function Entity:GetVelocity() end
```

### Returns

| Type | Description |
| --- | --- |
| `Vector3` | velocity |

## `SetVelocity`

```lua
function Entity:SetVelocity(vel) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `vel` | `Vector3` |  |

## `GetModel`

```lua
function Entity:GetModel() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` | hash Entity model hash. |

## `GetMaxHealth`

```lua
function Entity:GetMaxHealth() end
```

### Returns

| Type | Description |
| --- | --- |
| `number` | maxHp |

## `GetHealth`

```lua
function Entity:GetHealth() end
```

### Returns

| Type | Description |
| --- | --- |
| `number` | hp |

## `SetHealth`

```lua
function Entity:SetHealth(hp) end
```

**WARNING:** Do not use this method on other players.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `hp` | `number` |  |

## `SetCollision`

```lua
function Entity:SetCollision(enabled) end
```

**WARNING:** Do not use this method on other players.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `enabled` | `boolean` |  |

## `SetFrozen`

```lua
function Entity:SetFrozen(enabled) end
```

**WARNING:** Do not use this method on other players.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `enabled` | `boolean` |  |

## `SetInvincible`

```lua
function Entity:SetInvincible(enabled) end
```

**WARNING:** Do not use this method on other players.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `enabled` | `boolean` |  |

## `Kill`

```lua
function Entity:Kill() end
```

**WARNING:** Do not use this method on players.

## `Delete`

```lua
function Entity:Delete() end
```

**WARNING:** Do not use this method on players.
