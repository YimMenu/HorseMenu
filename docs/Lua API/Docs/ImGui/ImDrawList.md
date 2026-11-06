<!-- markdownlint-disable -->

# ImDrawList

## Methods

## `AddText`

```lua
function ImDrawList:AddText(pos, col, text) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `pos` | `Vector2` |  |
| `col` | `integer` |  |
| `text` | `string` |  |

## `AddText`

```lua
function ImDrawList:AddText(fontSize, pos, col, text, wrapWidth) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `fontSize` | `number` |  |
| `pos` | `Vector2` |  |
| `col` | `integer` |  |
| `text` | `string` |  |
| `wrapWidth` | `number?` |  |

## `AddLine`

```lua
function ImDrawList:AddLine(p1, p2, col, thickness) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `p1` | `Vector2` |  |
| `p2` | `Vector2` |  |
| `col` | `integer` |  |
| `thickness` | `number?` |  |

## `AddPolyLine`

```lua
function ImDrawList:AddPolyLine(points, numPoints, col, flags, thickness) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `points` | `{ [integer]: Vector2 }` | An array of Vector2 objects. **MUST** be a contiguous Vector2 array, else the function will throw. |
| `numPoints` | `integer` |  |
| `col` | `integer` |  |
| `flags` | `integer` | [ImDrawFlags](./ImDrawFlags.md) |
| `thickness` | `number` |  |

## `AddRect`

```lua
function ImDrawList:AddRect(pMin, pMax, col, rounding) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `pMin` | `Vector2` |  |
| `pMax` | `Vector2` |  |
| `col` | `integer` |  |
| `rounding` | `number?` |  |

## `AddRect`

```lua
function ImDrawList:AddRect(pMin, pMax, col, rounding, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `pMin` | `Vector2` |  |
| `pMax` | `Vector2` |  |
| `col` | `integer` |  |
| `rounding` | `number` |  |
| `flags` | `integer?` | Optional [ImDrawFlags](./ImDrawFlags.md) |

## `AddRect`

```lua
function ImDrawList:AddRect(pMin, pMax, col, rounding, flags, thickness) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `pMin` | `Vector2` |  |
| `pMax` | `Vector2` |  |
| `col` | `integer` |  |
| `rounding` | `number` |  |
| `flags` | `integer` | [ImDrawFlags](./ImDrawFlags.md) |
| `thickness` | `number?` |  |

## `AddRectFilled`

```lua
function ImDrawList:AddRectFilled(pMin, pMax, col, rounding) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `pMin` | `Vector2` |  |
| `pMax` | `Vector2` |  |
| `col` | `integer` |  |
| `rounding` | `number?` |  |

## `AddRectFilled`

```lua
function ImDrawList:AddRectFilled(pMin, pMax, col, rounding, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `pMin` | `Vector2` |  |
| `pMax` | `Vector2` |  |
| `col` | `integer` |  |
| `rounding` | `number` |  |
| `flags` | `integer?` | Optional [ImDrawFlags](./ImDrawFlags.md) |

## `AddCircle`

```lua
function ImDrawList:AddCircle(center, radius, col, numSegments) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `center` | `Vector2` |  |
| `radius` | `number` |  |
| `col` | `integer` |  |
| `numSegments` | `integer?` |  |

## `AddCircle`

```lua
function ImDrawList:AddCircle(center, radius, col, numSegments, thickness) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `center` | `Vector2` |  |
| `radius` | `number` |  |
| `col` | `integer` |  |
| `numSegments` | `integer` |  |
| `thickness` | `number?` |  |

## `AddCircleFilled`

```lua
function ImDrawList:AddCircleFilled(center, radius, col, numSegments) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `center` | `Vector2` |  |
| `radius` | `number` |  |
| `col` | `integer` |  |
| `numSegments` | `integer?` |  |

## `AddNgon`

```lua
function ImDrawList:AddNgon(center, radius, col, numSegments, thickness) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `center` | `Vector2` |  |
| `radius` | `number` |  |
| `col` | `integer` |  |
| `numSegments` | `integer` |  |
| `thickness` | `number?` |  |

## `AddNgonFilled`

```lua
function ImDrawList:AddNgonFilled(center, radius, col, numSegments) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `center` | `Vector2` |  |
| `radius` | `number` |  |
| `col` | `integer` |  |
| `numSegments` | `integer` |  |

## `AddQuad`

```lua
function ImDrawList:AddQuad(p1, p2, p3, p4, col, thickness) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `p1` | `Vector2` |  |
| `p2` | `Vector2` |  |
| `p3` | `Vector2` |  |
| `p4` | `Vector2` |  |
| `col` | `integer` |  |
| `thickness` | `number?` |  |

## `AddQuadFilled`

```lua
function ImDrawList:AddQuadFilled(p1, p2, p3, p4, col) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `p1` | `Vector2` |  |
| `p2` | `Vector2` |  |
| `p3` | `Vector2` |  |
| `p4` | `Vector2` |  |
| `col` | `integer` |  |

## `AddBezierCubic`

```lua
function ImDrawList:AddBezierCubic(p1, p2, p3, p4, col, thickness, numSegments) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `p1` | `Vector2` |  |
| `p2` | `Vector2` |  |
| `p3` | `Vector2` |  |
| `p4` | `Vector2` |  |
| `col` | `integer` |  |
| `thickness` | `number` |  |
| `numSegments` | `integer?` |  |

## `AddBezierQuadratic`

```lua
function ImDrawList:AddBezierQuadratic(p1, p2, p3, col, thickness, numSegments) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `p1` | `Vector2` |  |
| `p2` | `Vector2` |  |
| `p3` | `Vector2` |  |
| `col` | `integer` |  |
| `thickness` | `number` |  |
| `numSegments` | `integer?` |  |

## `AddTriangle`

```lua
function ImDrawList:AddTriangle(p1, p2, p3, col, thickness) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `p1` | `Vector2` |  |
| `p2` | `Vector2` |  |
| `p3` | `Vector2` |  |
| `col` | `integer` |  |
| `thickness` | `number?` |  |

## `AddTriangleFilled`

```lua
function ImDrawList:AddTriangleFilled(p1, p2, p3, col) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `p1` | `Vector2` |  |
| `p2` | `Vector2` |  |
| `p3` | `Vector2` |  |
| `col` | `integer` |  |

## `PathClear`

```lua
function ImDrawList:PathClear() end
```

## `PathLineTo`

```lua
function ImDrawList:PathLineTo(pos) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `pos` | `Vector2` |  |

## `PathStroke`

```lua
function ImDrawList:PathStroke(col, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `col` | `integer` |  |
| `flags` | `integer?` |  |

## `PathStroke`

```lua
function ImDrawList:PathStroke(col, flags, thickness) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `col` | `integer` |  |
| `flags` | `integer` |  |
| `thickness` | `number?` |  |

## `PathArcTo`

```lua
function ImDrawList:PathArcTo(center, radius, aMin, aMax, numSegments) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `center` | `Vector2` |  |
| `radius` | `number` |  |
| `aMin` | `number` |  |
| `aMax` | `number` |  |
| `numSegments` | `integer?` |  |

## `PathArcToFast`

```lua
function ImDrawList:PathArcToFast(center, radius, aMinOf12, aMaxOf12) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `center` | `Vector2` |  |
| `radius` | `number` |  |
| `aMinOf12` | `integer` | Minimum indices into the 12-step circle approximation |
| `aMaxOf12` | `integer` | Maximum indices into the 12-step circle approximation |

## `PathFillConcave`

```lua
function ImDrawList:PathFillConcave(col) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `col` | `integer` |  |

## `PathRect`

```lua
function ImDrawList:PathRect(rectMin, rectMax, rounding) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `rectMin` | `Vector2` |  |
| `rectMax` | `Vector2` |  |
| `rounding` | `number?` |  |

## `PathRect`

```lua
function ImDrawList:PathRect(rectMin, rectMax, rounding, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `rectMin` | `Vector2` |  |
| `rectMax` | `Vector2` |  |
| `rounding` | `number` |  |
| `flags` | `integer?` |  |

## `PathFillConvex`

```lua
function ImDrawList:PathFillConvex(col) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `col` | `integer` |  |

## `PathBezierCubicCurveTo`

```lua
function ImDrawList:PathBezierCubicCurveTo(p2, p3, p4, numSegments) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `p2` | `Vector2` |  |
| `p3` | `Vector2` |  |
| `p4` | `Vector2` |  |
| `numSegments` | `integer?` |  |

## `PathBezierQuadraticCurveTo`

```lua
function ImDrawList:PathBezierQuadraticCurveTo(p2, p3, numSegments) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `p2` | `Vector2` |  |
| `p3` | `Vector2` |  |
| `numSegments` | `integer?` |  |

## `PathEllipticalArcTo`

```lua
function ImDrawList:PathEllipticalArcTo(center, radius, rot, aMin, aMax, numSegments) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `center` | `Vector2` |  |
| `radius` | `Vector2` |  |
| `rot` | `number` |  |
| `aMin` | `number` |  |
| `aMax` | `number` |  |
| `numSegments` | `integer?` |  |

## `PushClipRect`

```lua
function ImDrawList:PushClipRect(min, max, intersectWithCurrentClipRect) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `min` | `Vector2` |  |
| `max` | `Vector2` |  |
| `intersectWithCurrentClipRect` | `boolean?` |  |

## `PopClipRect`

```lua
function ImDrawList:PopClipRect() end
```
