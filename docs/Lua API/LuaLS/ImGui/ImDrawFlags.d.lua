---@meta

---@class ImDrawFlags : integer
---@field None integer 
---@field Closed integer PathStroke(), AddPolyline(): specify that shape should be closed (Important: this is always == 1 for legacy reason)
---@field RoundCornersTopLeft integer AddRect(), AddRectFilled(), PathRect(): enable rounding top-left corner only (when rounding > 0.0f, we default to all corners). Was 0x01.
---@field RoundCornersTopRight integer AddRect(), AddRectFilled(), PathRect(): enable rounding top-right corner only (when rounding > 0.0f, we default to all corners). Was 0x02.
---@field RoundCornersBottomLeft integer AddRect(), AddRectFilled(), PathRect(): enable rounding bottom-left corner only (when rounding > 0.0f, we default to all corners). Was 0x04.
---@field RoundCornersBottomRight integer AddRect(), AddRectFilled(), PathRect(): enable rounding bottom-right corner only (when rounding > 0.0f, we default to all corners). Wax 0x08.
---@field RoundCornersNone integer AddRect(), AddRectFilled(), PathRect(): disable rounding on all corners (when rounding > 0.0f). This is NOT zero, NOT an implicit flag!
---@field RoundCornersTop integer 
---@field RoundCornersBottom integer 
---@field RoundCornersLeft integer 
---@field RoundCornersRight integer 
---@field RoundCornersAll integer 
---@field RoundCornersDefault_ integer Default to ALL corners if none of the _RoundCornersXX flags are specified.
---@field RoundCornersMask_ integer 
ImDrawFlags = {}
