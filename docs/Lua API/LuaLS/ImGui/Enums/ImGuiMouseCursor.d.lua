---@meta

---@class ImGuiMouseCursor : integer
---@field None integer 
---@field Arrow integer 
---@field TextInput integer When hovering over InputText, etc.
---@field ResizeAll integer (Unused by Dear ImGui functions)
---@field ResizeNS integer When hovering over a horizontal border
---@field ResizeEW integer When hovering over a vertical border or a column
---@field ResizeNESW integer When hovering over the bottom-left corner of a window
---@field ResizeNWSE integer When hovering over the bottom-right corner of a window
---@field Hand integer (Unused by Dear ImGui functions. Use for e.g. hyperlinks)
---@field Wait integer When waiting for something to process/load.
---@field Progress integer When waiting for something to process/load, but application is still interactive.
---@field NotAllowed integer When hovering something with disallowed interaction. Usually a crossed circle.
ImGuiMouseCursor = {}
