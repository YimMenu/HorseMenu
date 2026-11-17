<!-- markdownlint-disable -->

# ImGuiTabBarFlags

## Fields

| Name | Type | Description |
| --- | --- | --- |
| `None` | `integer` |  |
| `Reorderable` | `integer` | Allow manually dragging tabs to re-order them + New tabs are appended at the end of list |
| `AutoSelectNewTabs` | `integer` | Automatically select new tabs when they appear |
| `TabListPopupButton` | `integer` | Disable buttons to open the tab list popup |
| `NoCloseWithMiddleMouseButton` | `integer` | Disable behavior of closing tabs (that are submitted with p_open != NULL) with middle mouse button. You may handle this behavior manually on user's side with if (IsItemHovered() && IsMouseClicked(2)) *p_open = false. |
| `NoTabListScrollingButtons` | `integer` | Disable scrolling buttons (apply when fitting policy is ImGuiTabBarFlags_FittingPolicyScroll) |
| `NoTooltip` | `integer` | Disable tooltips when hovering a tab |
| `DrawSelectedOverline` | `integer` | Draw selected overline markers over selected tab |
| `FittingPolicyMixed` | `integer` | Shrink down tabs when they don't fit, until width is style.TabMinWidthShrink, then enable scrolling buttons. |
| `FittingPolicyShrink` | `integer` | Shrink down tabs when they don't fit |
| `FittingPolicyScroll` | `integer` | Enable scrolling buttons when tabs don't fit |
| `FittingPolicyMask_` | `integer` |  |
| `FittingPolicyDefault_` | `integer` |  |
