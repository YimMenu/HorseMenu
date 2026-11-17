---@meta

---@class ImGuiTabItemFlags : integer
---@field None integer 
---@field UnsavedDocument integer Display a dot next to the title + set ImGuiTabItemFlags_NoAssumedClosure.
---@field SetSelected integer Trigger flag to programmatically make the tab selected when calling BeginTabItem()
---@field NoCloseWithMiddleMouseButton integer Disable behavior of closing tabs (that are submitted with p_open != NULL) with middle mouse button. You may handle this behavior manually on user's side with if (IsItemHovered() && IsMouseClicked(2)) *p_open = false.
---@field NoPushId integer Don't call PushID()/PopID() on BeginTabItem()/EndTabItem()
---@field NoTooltip integer Disable tooltip for the given tab
---@field NoReorder integer Disable reordering this tab or having another tab cross over this tab
---@field Leading integer Enforce the tab position to the left of the tab bar (after the tab list popup button)
---@field Trailing integer Enforce the tab position to the right of the tab bar (before the scrolling buttons)
---@field NoAssumedClosure integer Tab is selected when trying to close + closure is not immediately assumed (will wait for user to stop submitting the tab). Otherwise closure is assumed when pressing the X, so if you keep submitting the tab may reappear at end of tab bar.
ImGuiTabItemFlags = {}
