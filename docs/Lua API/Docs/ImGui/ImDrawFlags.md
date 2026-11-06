<!-- markdownlint-disable -->

# ImDrawFlags

## Fields

| Name | Type | Description |
| --- | --- | --- |
| `None` | `integer` |  |
| `Closed` | `integer` | PathStroke(), AddPolyline(): specify that shape should be closed (Important: this is always == 1 for legacy reason) |
| `RoundCornersTopLeft` | `integer` | AddRect(), AddRectFilled(), PathRect(): enable rounding top-left corner only (when rounding > 0.0f, we default to all corners). Was 0x01. |
| `RoundCornersTopRight` | `integer` | AddRect(), AddRectFilled(), PathRect(): enable rounding top-right corner only (when rounding > 0.0f, we default to all corners). Was 0x02. |
| `RoundCornersBottomLeft` | `integer` | AddRect(), AddRectFilled(), PathRect(): enable rounding bottom-left corner only (when rounding > 0.0f, we default to all corners). Was 0x04. |
| `RoundCornersBottomRight` | `integer` | AddRect(), AddRectFilled(), PathRect(): enable rounding bottom-right corner only (when rounding > 0.0f, we default to all corners). Wax 0x08. |
| `RoundCornersNone` | `integer` | AddRect(), AddRectFilled(), PathRect(): disable rounding on all corners (when rounding > 0.0f). This is NOT zero, NOT an implicit flag! |
| `RoundCornersTop` | `integer` |  |
| `RoundCornersBottom` | `integer` |  |
| `RoundCornersLeft` | `integer` |  |
| `RoundCornersRight` | `integer` |  |
| `RoundCornersAll` | `integer` |  |
| `RoundCornersDefault_` | `integer` | Default to ALL corners if none of the _RoundCornersXX flags are specified. |
| `RoundCornersMask_` | `integer` |  |
