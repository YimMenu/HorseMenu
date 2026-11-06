<!-- markdownlint-disable -->

# Vector4

## Constructors

```lua
Vector4()
```
```lua
Vector4(x, y, z, w)
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `x` | `number` |  |
| `y` | `number` |  |
| `z` | `number` |  |
| `w` | `number` |  |
## Operators

### `len`

```lua
---@operator __len(): number
```

### `add`

```lua
---@operator __add(Vector4|number): Vector4
```

### `sub`

```lua
---@operator __sub(Vector4|number): Vector4
```

### `mul`

```lua
---@operator __mul(Vector4|number): Vector4
```

### `div`

```lua
---@operator __div(Vector4|number): Vector4
```

## Fields

| Name | Type | Description |
| --- | --- | --- |
| `x` | `number` | The X component of the vector. |
| `y` | `number` | The Y component of the vector. |
| `z` | `number` | The Z component of the vector. |
| `w` | `number` | The W component of the vector. |

## Methods

## `IsZero`

```lua
function Vector4:IsZero() end
```

Returns true if all components of the vector are zero.

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `Magnitude`

```lua
function Vector4:Magnitude() end
```

Returns the magnitude of the vector. The length operator (`#`) does the same thing: `local mag = #myVec`

### Returns

| Type | Description |
| --- | --- |
| `number` | mag The magnitude of the vector. |

## `Distance`

```lua
function Vector4:Distance(other) end
```

Returns the distance between this vector and another.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `other` | `Vector4` |  |

### Returns

| Type | Description |
| --- | --- |
| `number` | dist The distance between the two vectors. |

## `Lerp`

```lua
function Vector4:Lerp(other, dt) end
```

Linearly interpolates this vector to target vector over delta time.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `other` | `Vector4` |  |
| `dt` | `number` | Delta |

### Returns

| Type | Description |
| --- | --- |
| `Vector4` |  |
