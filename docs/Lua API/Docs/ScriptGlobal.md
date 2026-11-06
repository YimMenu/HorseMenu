<!-- markdownlint-disable -->

# ScriptGlobal

## Constructors

```lua
ScriptGlobal(index)
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `index` | `integer` |  |
## Operators

### `add`

```lua
---@operator __add(integer): ScriptGlobal
```

### `sub`

```lua
---@operator __sub(integer): ScriptGlobal
```

## Methods

## `CanAccess`

```lua
function ScriptGlobal:CanAccess(muliplayer) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `muliplayer` | `boolean?` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `At`

```lua
function ScriptGlobal:At(offset) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `offset` | `integer` |  |

### Returns

| Type | Description |
| --- | --- |
| `ScriptGlobal` |  |

## `At`

```lua
function ScriptGlobal:At(offset, size) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `offset` | `integer` |  |
| `size` | `integer` |  |

### Returns

| Type | Description |
| --- | --- |
| `ScriptGlobal` |  |

## `GetPointer`

```lua
function ScriptGlobal:GetPointer() end
```

### Returns

| Type | Description |
| --- | --- |
| `Pointer` |  |

## `ReadString`

```lua
function ScriptGlobal:ReadString() end
```

### Returns

| Type | Description |
| --- | --- |
| `string` |  |

## `ReadBool`

```lua
function ScriptGlobal:ReadBool() end
```

Returns false if the value interpreted as integer equals zero, otherwise true.

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `ReadInt`

```lua
function ScriptGlobal:ReadInt() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` |  |

## `ReadFloat`

```lua
function ScriptGlobal:ReadFloat() end
```

### Returns

| Type | Description |
| --- | --- |
| `number` |  |

## `ReadVector3`

```lua
function ScriptGlobal:ReadVector3() end
```

### Returns

| Type | Description |
| --- | --- |
| `Vector3` |  |

## `WriteString`

```lua
function ScriptGlobal:WriteString(value, maxLength) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `value` | `string` |  |
| `maxLength` | `integer?` | Optional maximum length. If provided and the string's size is less than this value, the difference will be padded with null terminators. |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | success |

## `WriteInt`

```lua
function ScriptGlobal:WriteInt(value) end
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
function ScriptGlobal:WriteFloat(value) end
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
function ScriptGlobal:WriteVector3(value) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `value` | `Vector3` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | success |
