<!-- markdownlint-disable -->

# Vector3

## Constructors

```lua
Vector3()
```
```lua
Vector3(x, y, z)
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `x` | `number` |  |
| `y` | `number` |  |
| `z` | `number` |  |
## Operators

### `len`

```lua
---@operator __len(): number
```

### `add`

```lua
---@operator __add(Vector3|number): Vector3
```

### `sub`

```lua
---@operator __sub(Vector3|number): Vector3
```

### `mul`

```lua
---@operator __mul(Vector3|number): Vector3
```

### `div`

```lua
---@operator __div(Vector3|number): Vector3
```

## Fields

| Name | Type | Description |
| --- | --- | --- |
| `x` | `number` | The X component of the vector. |
| `y` | `number` | The Y component of the vector. |
| `z` | `number` | The Z component of the vector. |

## Methods

## `IsZero`

```lua
function Vector3:IsZero() end
```

Returns true if all components of the vector are zero.

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `Magnitude`

```lua
function Vector3:Magnitude() end
```

Returns the magnitude of the vector. The length operator (`#`) does the same thing: `local mag = #myVec`

### Returns

| Type | Description |
| --- | --- |
| `number` | mag The magnitude of the vector. |

## `Distance`

```lua
function Vector3:Distance(other) end
```

Returns the distance between this vector and another.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `other` | `Vector3` |  |

### Returns

| Type | Description |
| --- | --- |
| `number` | dist The distance between the two vectors. |

## `Lerp`

```lua
function Vector3:Lerp(other, dt) end
```

Linearly interpolates this vector to target vector over delta time.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `other` | `Vector3` |  |
| `dt` | `number` | Delta |

### Returns

| Type | Description |
| --- | --- |
| `Vector3` |  |
