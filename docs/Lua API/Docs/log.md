<!-- markdownlint-disable -->

# log

## Methods

## `info`

```lua
function log.info(...) end
```

Logs an information message. Arguments are the same as [print](./print.md)

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `...` | `any` |  |

## `warning`

```lua
function log.warning(...) end
```

Logs a warning message. Arguments are the same as [print](./print.md)

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `...` | `any` |  |

## `debug`

```lua
function log.debug(...) end
```

Logs a debug message. Arguments are the same as [print](./print.md)

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `...` | `any` |  |

## `error`

```lua
function log.error(...) end
```

Logs an error message. Arguments are the same as [print](./print.md)

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `...` | `any` |  |

## `finfo`

```lua
function log.finfo(msg, ...) end
```

Logs a formatted information message. Formatting works the same as [string.format](./string.md.format)

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `msg` | `string` | Message. |
| `...` | `any` | Optional format arguments. |

## `fwarning`

```lua
function log.fwarning(msg, ...) end
```

Logs a formatted warning message. Formatting works the same as [string.format](./string.md.format)

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `msg` | `string` | Message. |
| `...` | `any` | Optional format arguments. |

## `fdebug`

```lua
function log.fdebug(msg, ...) end
```

Logs a formatted debug message. Formatting works the same as [string.format](./string.md.format)

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `msg` | `string` | Message. |
| `...` | `any` | Optional format arguments. |

## `ferror`

```lua
function log.ferror(msg, ...) end
```

Logs a formatted error message. Formatting works the same as [string.format](./string.md.format)

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `msg` | `string` | Message. |
| `...` | `any` | Optional format arguments. |
