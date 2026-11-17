---@meta

---@class ImGuiComboFlags : integer
---@field None integer 
---@field PopupAlignLeft integer Align the popup toward the left by default
---@field HeightSmall integer Max ~4 items visible. Tip: If you want your combo popup to be a specific size you can use SetNextWindowSizeConstraints() prior to calling BeginCombo()
---@field HeightRegular integer Max ~8 items visible (default)
---@field HeightLarge integer Max ~20 items visible
---@field HeightLargest integer As many fitting items as possible
---@field NoArrowButton integer Display on the preview box without the square arrow button
---@field NoPreview integer Display only a square arrow button
---@field WidthFitPreview integer Width dynamically calculated from preview contents
---@field HeightMask_ integer 
ImGuiComboFlags = {}
