<!-- markdownlint-disable -->

# Path

## Constructors

```lua
Path(path)
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `path` | `string` |  |
## Operators

### `div`

```lua
---@operator __div(string): Path
```

## Methods

## `Exists`

```lua
function Path:Exists() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsFile`

```lua
function Path:IsFile() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsDir`

```lua
function Path:IsDir() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `MakeDir`

```lua
function Path:MakeDir() end
```

Creates a directory if it doesn't exist

## `MakeDirs`

```lua
function Path:MakeDirs() end
```

Creates a directory and any missing parent directories

## `GetFilename`

```lua
function Path:GetFilename() end
```

### Returns

| Type | Description |
| --- | --- |
| `string` |  |

## `GetStem`

```lua
function Path:GetStem() end
```

### Returns

| Type | Description |
| --- | --- |
| `string` | stem The file name without the extension. |

## `GetExtension`

```lua
function Path:GetExtension() end
```

### Returns

| Type | Description |
| --- | --- |
| `string` | ext The file extension including the leading dot. Ex: `.json`. Returns empty string for folders. |

## `GetFileSize`

```lua
function Path:GetFileSize() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` | filesz The file size in bytes. |

## `GetParent`

```lua
function Path:GetParent() end
```

### Returns

| Type | Description |
| --- | --- |
| `Path` | parentDir The parent directory. Note: This will throw if the path is outside the module's root directory. |

## `Join`

```lua
function Path:Join(subPath) end
```

Joins the path with a sub-path. Does the same thing as the division operator *(__div)*: `myPath / "somefile.txt"`

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `subPath` | `string` |  |

### Returns

| Type | Description |
| --- | --- |
| `Path` |  |

## `Open`

```lua
function Path:Open(mode) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `mode` | `openmode?` |  |

### Returns

| Type | Description |
| --- | --- |
| `file*?` | File handle or nil |
| `string` | failReason An error message if the operation fails. |

## `ToString`

```lua
function Path:ToString() end
```

Returns the string representation of the path. `myPath:ToString()`, `myPath:__tostring()`, and `tostring(myPath)` all achieve the same thing.

### Returns

| Type | Description |
| --- | --- |
| `string` | strPath |

## `IterDir`

```lua
function Path:IterDir() end
```

Recursive directory iterator.

### Returns

| Type | Description |
| --- | --- |
| `fun():` | Path |
