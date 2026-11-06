<!-- markdownlint-disable -->

# Script

## Methods

## `RunInFiber`

```lua
function Script.RunInFiber(callback) end
```

Executes a callback in a fiber context

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `callback` | `function` | The callback to execute |

## `RunInFiberAfterDelay`

```lua
function Script.RunInFiberAfterDelay(callback, delay) end
```

Executes a callback in a fiber context after a delay

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `callback` | `function` | The callback to execute |
| `delay` | `integer` | Delay in milliseconds. |

## `Sleep`

```lua
function Script.Sleep(ms) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `ms` | `integer` | Sleep time in milliseconds |

## `Yield`

```lua
function Script.Yield(ms) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `ms` | `integer?` | Optional yield time in milliseconds |

## `IsActive`

```lua
function Script.IsActive(scrName) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `scrName` | `string` | Name of the game script to check. Ex: `"aberdeenpigfarm"` |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | state |

## `RunAsScript`

```lua
function Script.RunAsScript(scrName, fn) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `scrName` | `string` | Name of the game script. Ex: `"net_camp_manager"` |
| `fn` | `function` | Callback to execute once in the script's thread context. |
