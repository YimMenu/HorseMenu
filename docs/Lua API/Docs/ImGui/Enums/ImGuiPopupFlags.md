<!-- markdownlint-disable -->

# ImGuiPopupFlags

## Fields

| Name | Type | Description |
| --- | --- | --- |
| `None` | `integer` |  |
| `MouseButtonLeft` | `integer` | For BeginPopupContext*(): open on Left Mouse release. Guaranteed to always be == 0 (same as ImGuiMouseButton_Left) |
| `MouseButtonRight` | `integer` | For BeginPopupContext*(): open on Right Mouse release. Guaranteed to always be == 1 (same as ImGuiMouseButton_Right) |
| `MouseButtonMiddle` | `integer` | For BeginPopupContext*(): open on Middle Mouse release. Guaranteed to always be == 2 (same as ImGuiMouseButton_Middle) |
| `MouseButtonMask_` | `integer` |  |
| `MouseButtonDefault_` | `integer` |  |
| `NoReopen` | `integer` | For OpenPopup*(), BeginPopupContext*(): don't reopen same popup if already open (won't reposition, won't reinitialize navigation) |
| `NoOpenOverExistingPopup` | `integer` | For OpenPopup*(), BeginPopupContext*(): don't open if there's already a popup at the same level of the popup stack |
| `NoOpenOverItems` | `integer` | For BeginPopupContextWindow(): don't return true when hovering items, only when hovering empty space |
| `AnyPopupId` | `integer` | For IsPopupOpen(): ignore the ImGuiID parameter and test for any popup. |
| `AnyPopupLevel` | `integer` | For IsPopupOpen(): search/test at any level of the popup stack (default test in the current level) |
| `AnyPopup` | `integer` |  |
