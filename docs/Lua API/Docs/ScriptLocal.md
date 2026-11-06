<!-- markdownlint-disable -->

# ScriptLocal

## Constructors

```lua
ScriptLocal(scriptName, index)
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `scriptName` | `string` |  |
| `index` | `integer` |  |
```lua
ScriptLocal(scriptHash, index)
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `scriptHash` | `integer` |  |
| `index` | `integer` |  |
## Operators

### `add`

```lua
---@operator __add(integer): ScriptLocal
```

### `sub`

```lua
---@operator __sub(integer): ScriptLocal
```

## Methods

## `At`

```lua
function ScriptLocal:At(offset) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `offset` | `integer` |  |

### Returns

| Type | Description |
| --- | --- |
| `ScriptLocal` |  |

## `At`

```lua
function ScriptLocal:At(offset, size) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `offset` | `integer` |  |
| `size` | `integer` |  |

### Returns

| Type | Description |
| --- | --- |
| `ScriptLocal` |  |

## `GetPointer`

```lua
function ScriptLocal:GetPointer() end
```

### Returns

| Type | Description |
| --- | --- |
| `Pointer` |  |

## `ReadBool`

```lua
function ScriptLocal:ReadBool() end
```

Returns false if the value interpreted as integer equals zero, otherwise true.

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `ReadInt`

```lua
function ScriptLocal:ReadInt() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` |  |

## `ReadFloat`

```lua
function ScriptLocal:ReadFloat() end
```

### Returns

| Type | Description |
| --- | --- |
| `number` |  |

## `ReadVector3`

```lua
function ScriptLocal:ReadVector3() end
```

### Returns

| Type | Description |
| --- | --- |
| `Vector3` |  |

## `WriteInt`

```lua
function ScriptLocal:WriteInt(value) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `value` | `integer` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | success |

## `WriteFloat`

```lua
function ScriptLocal:WriteFloat(value) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `value` | `number` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | success |

## `WriteVector3`

```lua
function ScriptLocal:WriteVector3(value) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `value` | `Vector3` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | success |
