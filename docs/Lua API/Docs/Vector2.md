<!-- markdownlint-disable -->

# Vector2

## Constructors

```lua
Vector2()
```
```lua
Vector2(x, y)
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `x` | `number` |  |
| `y` | `number` |  |
## Operators

### `len`

```lua
---@operator __len(): number
```

### `add`

```lua
---@operator __add(Vector2|number): Vector2
```

### `sub`

```lua
---@operator __sub(Vector2|number): Vector2
```

### `mul`

```lua
---@operator __mul(Vector2|number): Vector2
```

### `div`

```lua
---@operator __div(Vector2|number): Vector2
```

## Fields

| Name | Type | Description |
| --- | --- | --- |
| `x` | `number` | The X component of the vector. |
| `y` | `number` | The Y component of the vector. |

## Methods

## `IsZero`

```lua
function Vector2:IsZero() end
```

Returns true if all components of the vector are zero.

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `Magnitude`

```lua
function Vector2:Magnitude() end
```

Returns the magnitude of the vector. The length operator (`#`) does the same thing: `local mag = #myVec`

### Returns

| Type | Description |
| --- | --- |
| `number` | mag The magnitude of the vector. |

## `Distance`

```lua
function Vector2:Distance(other) end
```

Returns the distance between this vector and another.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `other` | `Vector2` |  |

### Returns

| Type | Description |
| --- | --- |
| `number` | dist The distance between the two vectors. |

## `Lerp`

```lua
function Vector2:Lerp(other, dt) end
```

Linearly interpolates this vector to target vector over delta time.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `other` | `Vector2` |  |
| `dt` | `number` | Delta |

### Returns

| Type | Description |
| --- | --- |
| `Vector2` |  |
