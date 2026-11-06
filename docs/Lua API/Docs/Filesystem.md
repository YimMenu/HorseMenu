<!-- markdownlint-disable -->

# Filesystem

## Methods

## `MyRoot`

```lua
function Filesystem.MyRoot() end
```

Returns the module's root path.

### Returns

| Type | Description |
| --- | --- |
| `Path` |  |

## `IterDir`

```lua
function Filesystem.IterDir(path) end
```

Recursive directory iterator.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `path` | `Path` |  |

### Returns

| Type | Description |
| --- | --- |
| `fun():` | Path |

## `Rename`

```lua
function Filesystem.Rename(oldPath, newPath) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `oldPath` | `Path` |  |
| `newPath` | `Path` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | successOrFailure |
| `string` | failReason |

## `Remove`

```lua
function Filesystem.Remove(path, emptyOnly) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `path` | `Path` |  |
| `emptyOnly` | `boolean?` | If true, non-empty folders will not be removed. Defaults to `true`. |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | successOrFailure |
| `string` | failReason |
