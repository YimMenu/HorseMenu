---@meta

---@class ImGuiTabBarFlags : integer
---@field None integer 
---@field Reorderable integer Allow manually dragging tabs to re-order them + New tabs are appended at the end of list
---@field AutoSelectNewTabs integer Automatically select new tabs when they appear
---@field TabListPopupButton integer Disable buttons to open the tab list popup
---@field NoCloseWithMiddleMouseButton integer Disable behavior of closing tabs (that are submitted with p_open != NULL) with middle mouse button. You may handle this behavior manually on user's side with if (IsItemHovered() && IsMouseClicked(2)) *p_open = false.
---@field NoTabListScrollingButtons integer Disable scrolling buttons (apply when fitting policy is ImGuiTabBarFlags_FittingPolicyScroll)
---@field NoTooltip integer Disable tooltips when hovering a tab
---@field DrawSelectedOverline integer Draw selected overline markers over selected tab
---@field FittingPolicyMixed integer Shrink down tabs when they don't fit, until width is style.TabMinWidthShrink, then enable scrolling buttons.
---@field FittingPolicyShrink integer Shrink down tabs when they don't fit
---@field FittingPolicyScroll integer Enable scrolling buttons when tabs don't fit
---@field FittingPolicyMask_ integer 
---@field FittingPolicyDefault_ integer 
ImGuiTabBarFlags = {}
