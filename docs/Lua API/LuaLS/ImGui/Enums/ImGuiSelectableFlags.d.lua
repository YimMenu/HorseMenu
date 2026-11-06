---@meta

---@class ImGuiSelectableFlags : integer
---@field None integer 
---@field NoAutoClosePopups integer Clicking this doesn't close parent popup window (overrides ImGuiItemFlags_AutoClosePopups)
---@field SpanAllColumns integer Frame will span all columns of its container table (text will still fit in current column)
---@field AllowDoubleClick integer Generate press events on double clicks too
---@field Disabled integer Cannot be selected, display grayed out text
---@field AllowOverlap integer (WIP) Hit testing to allow subsequent widgets to overlap this one
---@field Highlight integer Make the item be displayed as if it is hovered
---@field SelectOnNav integer Auto-select when moved into, unless Ctrl is held. Automatic when in a BeginMultiSelect() block.
ImGuiSelectableFlags = {}
