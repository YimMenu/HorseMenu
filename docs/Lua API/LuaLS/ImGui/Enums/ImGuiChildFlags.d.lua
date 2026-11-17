---@meta

---@class ImGuiChildFlags : integer
---@field None integer 
---@field Borders integer Show an outer border and enable WindowPadding. (IMPORTANT: this is always == 1 == true for legacy reason)
---@field AlwaysUseWindowPadding integer Pad with style.WindowPadding even if no border are drawn (no padding by default for non-bordered child windows because it makes more sense)
---@field ResizeX integer Allow resize from right border (layout direction). Enable .ini saving (unless ImGuiWindowFlags_NoSavedSettings passed to window flags)
---@field ResizeY integer Allow resize from bottom border (layout direction). "
---@field AutoResizeX integer Enable auto-resizing width. Read "IMPORTANT: Size measurement" details above.
---@field AutoResizeY integer Enable auto-resizing height. Read "IMPORTANT: Size measurement" details above.
---@field AlwaysAutoResize integer Combined with AutoResizeX/AutoResizeY. Always measure size even when child is hidden, always return true, always disable clipping optimization! NOT RECOMMENDED.
---@field FrameStyle integer Style the child window like a framed item: use FrameBg, FrameRounding, FrameBorderSize, FramePadding instead of ChildBg, ChildRounding, ChildBorderSize, WindowPadding.
---@field NavFlattened integer [BETA] Share focus scope, allow keyboard/gamepad navigation to cross over parent border to this child or between sibling child windows.
ImGuiChildFlags = {}
