<!-- markdownlint-disable -->

# Memory

## Methods

## `ScanPattern`

```lua
function Memory.ScanPattern(sig, name) end
```

Scans a byte signature and returns a Pointer object. The function is synchronous so it's best to run it in a fiber.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `sig` | `string` | IDA-style byte signature. Example: `"8B 88 C0 ? ? ? 89 8F"` |
| `name` | `string?` | Optional name of the pattern to scan. Purely for logging purposes. |

### Returns

| Type | Description |
| --- | --- |
| `Pointer` | ptr A pointer at the found address or a null pointer if the scan fails. This is guaranteed to always return a Pointer object. |

## `HandleToPointer`

```lua
function Memory.HandleToPointer(handle) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `handle` | `integer` | RAGE entity handle |

### Returns

| Type | Description |
| --- | --- |
| `Pointer` |  |

## `PointerToHandle`

```lua
function Memory.PointerToHandle(ptr) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `ptr` | `Pointer` | entity pointer |

### Returns

| Type | Description |
| --- | --- |
| `integer` | handle |

## `Allocate`

```lua
function Memory.Allocate(size) end
```

Allocates a memory block and returns a Pointer to the allocated memory address.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `size` | `integer` | size in bytes |

### Returns

| Type | Description |
| --- | --- |
| `Pointer` | ptr Pointer to the allocated memory address. |

## `Free`

```lua
function Memory.Free(ptr) end
```

Frees an allocated memory block.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `ptr` | `Pointer` |  |
