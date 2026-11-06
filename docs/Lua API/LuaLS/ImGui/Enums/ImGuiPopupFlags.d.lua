---@meta

---@class ImGuiPopupFlags : integer
---@field None integer 
---@field MouseButtonLeft integer For BeginPopupContext*(): open on Left Mouse release. Guaranteed to always be == 0 (same as ImGuiMouseButton_Left)
---@field MouseButtonRight integer For BeginPopupContext*(): open on Right Mouse release. Guaranteed to always be == 1 (same as ImGuiMouseButton_Right)
---@field MouseButtonMiddle integer For BeginPopupContext*(): open on Middle Mouse release. Guaranteed to always be == 2 (same as ImGuiMouseButton_Middle)
---@field MouseButtonMask_ integer 
---@field MouseButtonDefault_ integer 
---@field NoReopen integer For OpenPopup*(), BeginPopupContext*(): don't reopen same popup if already open (won't reposition, won't reinitialize navigation)
---@field NoOpenOverExistingPopup integer For OpenPopup*(), BeginPopupContext*(): don't open if there's already a popup at the same level of the popup stack
---@field NoOpenOverItems integer For BeginPopupContextWindow(): don't return true when hovering items, only when hovering empty space
---@field AnyPopupId integer For IsPopupOpen(): ignore the ImGuiID parameter and test for any popup.
---@field AnyPopupLevel integer For IsPopupOpen(): search/test at any level of the popup stack (default test in the current level)
---@field AnyPopup integer 
ImGuiPopupFlags = {}
