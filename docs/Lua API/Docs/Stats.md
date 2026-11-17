<!-- markdownlint-disable -->

# Stats

## Methods

## `IsValid`

```lua
function Stats.IsValid(baseName, permutationName) end
```

Returns whether the stat is valid.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseName` | `string` |  |
| `permutationName` | `string` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsValid`

```lua
function Stats.IsValid(baseHash, permutationHash) end
```

Returns whether the stat is valid.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseHash` | `integer` | JOAAT hash |
| `permutationHash` | `integer` | JOAAT hash |

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `GetInt`

```lua
function Stats.GetInt(baseName, permutationName) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseName` | `string` |  |
| `permutationName` | `string` |  |

### Returns

| Type | Description |
| --- | --- |
| `integer` |  |

## `GetInt`

```lua
function Stats.GetInt(baseHash, permutationHash) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseHash` | `integer` | JOAAT hash |
| `permutationHash` | `integer` | JOAAT hash |

### Returns

| Type | Description |
| --- | --- |
| `integer` |  |

## `GetFloat`

```lua
function Stats.GetFloat(baseName, permutationName) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseName` | `string` |  |
| `permutationName` | `string` |  |

### Returns

| Type | Description |
| --- | --- |
| `number` |  |

## `GetFloat`

```lua
function Stats.GetFloat(baseHash, permutationHash) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseHash` | `integer` | JOAAT hash |
| `permutationHash` | `integer` | JOAAT hash |

### Returns

| Type | Description |
| --- | --- |
| `number` |  |

## `GetBool`

```lua
function Stats.GetBool(baseName, permutationName) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseName` | `string` |  |
| `permutationName` | `string` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `GetBool`

```lua
function Stats.GetBool(baseHash, permutationHash) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseHash` | `integer` | JOAAT hash |
| `permutationHash` | `integer` | JOAAT hash |

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `SetInt`

```lua
function Stats.SetInt(baseName, permutationName, value, save) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseName` | `string` |  |
| `permutationName` | `string` |  |
| `value` | `integer` |  |
| `save` | `boolean?` | Whether to save changes. Defaults to true. |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | success |

## `SetInt`

```lua
function Stats.SetInt(baseHash, permutationHash, value, save) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseHash` | `integer` | JOAAT hash |
| `permutationHash` | `integer` | JOAAT hash |
| `value` | `integer` |  |
| `save` | `boolean?` | Whether to save changes. Defaults to true. |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | success |

## `SetFloat`

```lua
function Stats.SetFloat(baseName, permutationName, value, save) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseName` | `string` |  |
| `permutationName` | `string` |  |
| `value` | `number` |  |
| `save` | `boolean?` | Whether to save changes. Defaults to true. |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | success |

## `SetFloat`

```lua
function Stats.SetFloat(baseHash, permutationHash, value, save) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseHash` | `integer` | JOAAT hash |
| `permutationHash` | `integer` | JOAAT hash |
| `value` | `number` |  |
| `save` | `boolean?` | Whether to save changes. Defaults to true. |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | success |

## `SetBool`

```lua
function Stats.SetBool(baseName, permutationName, value, save) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseName` | `string` |  |
| `permutationName` | `string` |  |
| `value` | `boolean` |  |
| `save` | `boolean?` | Whether to save changes. Defaults to true. |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | success |

## `SetBool`

```lua
function Stats.SetBool(baseHash, permutationHash, value, save) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseHash` | `integer` | JOAAT hash |
| `permutationHash` | `integer` | JOAAT hash |
| `value` | `boolean` |  |
| `save` | `boolean?` | Whether to save changes. Defaults to true. |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | success |

## `SetString`

```lua
function Stats.SetString(baseName, permutationName, value, save) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseName` | `string` |  |
| `permutationName` | `string` |  |
| `value` | `string` |  |
| `save` | `boolean?` | Whether to save changes. Defaults to true. |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | success |

## `SetString`

```lua
function Stats.SetString(baseHash, permutationHash, value, save) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseHash` | `integer` | JOAAT hash |
| `permutationHash` | `integer` | JOAAT hash |
| `value` | `string` |  |
| `save` | `boolean?` | Whether to save changes. Defaults to true. |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | success |

## `DecrementInt`

```lua
function Stats.DecrementInt(baseName, permutationName, value) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseName` | `string` |  |
| `permutationName` | `string` |  |
| `value` | `integer` |  |

## `DecrementInt`

```lua
function Stats.DecrementInt(baseHash, permutationHash, value) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseHash` | `integer` | JOAAT hash |
| `permutationHash` | `integer` | JOAAT hash |
| `value` | `integer` |  |

## `IncrementInt`

```lua
function Stats.IncrementInt(baseName, permutationName, value) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseName` | `string` |  |
| `permutationName` | `string` |  |
| `value` | `integer` |  |

## `IncrementInt`

```lua
function Stats.IncrementInt(baseHash, permutationHash, value) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseHash` | `integer` | JOAAT hash |
| `permutationHash` | `integer` | JOAAT hash |
| `value` | `integer` |  |

## `IncrementFloat`

```lua
function Stats.IncrementFloat(baseName, permutationName, value) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseName` | `string` |  |
| `permutationName` | `string` |  |
| `value` | `number` |  |

## `IncrementFloat`

```lua
function Stats.IncrementFloat(baseHash, permutationHash, value) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `baseHash` | `integer` | JOAAT hash |
| `permutationHash` | `integer` | JOAAT hash |
| `value` | `number` |  |
