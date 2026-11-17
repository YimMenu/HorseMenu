<!-- markdownlint-disable -->

# ImGuiHoveredFlags

## Fields

| Name | Type | Description |
| --- | --- | --- |
| `None` | `integer` | Return true if directly over the item/window, not obstructed by another window, not obstructed by an active popup or modal blocking inputs under them. |
| `ChildWindows` | `integer` | IsWindowHovered() only: Return true if any children of the window is hovered |
| `RootWindow` | `integer` | IsWindowHovered() only: Test from root window (top most parent of the current hierarchy) |
| `AnyWindow` | `integer` | IsWindowHovered() only: Return true if any window is hovered |
| `NoPopupHierarchy` | `integer` | IsWindowHovered() only: Do not consider popup hierarchy (do not treat popup emitter as parent of popup) (when used with _ChildWindows or _RootWindow) |
| `AllowWhenBlockedByPopup` | `integer` | Return true even if a popup window is normally blocking access to this item/window |
| `AllowWhenBlockedByActiveItem` | `integer` | Return true even if an active item is blocking access to this item/window. Useful for Drag and Drop patterns. |
| `AllowWhenOverlappedByItem` | `integer` | IsItemHovered() only: Return true even if the item uses AllowOverlap mode and is overlapped by another hoverable item. |
| `AllowWhenOverlappedByWindow` | `integer` | IsItemHovered() only: Return true even if the position is obstructed or overlapped by another window. |
| `AllowWhenDisabled` | `integer` | IsItemHovered() only: Return true even if the item is disabled |
| `NoNavOverride` | `integer` | IsItemHovered() only: Disable using keyboard/gamepad navigation state when active, always query mouse |
| `AllowWhenOverlapped` | `integer` |  |
| `RectOnly` | `integer` |  |
| `RootAndChildWindows` | `integer` |  |
| `Stationary` | `integer` | Require mouse to be stationary for style.HoverStationaryDelay (~0.15 sec) _at least one time_. After this, can move on same item/window. Using the stationary test tends to reduces the need for a long delay. |
| `DelayNone` | `integer` | IsItemHovered() only: Return true immediately (default). As this is the default you generally ignore this. |
| `DelayShort` | `integer` | IsItemHovered() only: Return true after style.HoverDelayShort elapsed (~0.15 sec) (shared between items) + requires mouse to be stationary for style.HoverStationaryDelay (once per item). |
| `DelayNormal` | `integer` | IsItemHovered() only: Return true after style.HoverDelayNormal elapsed (~0.40 sec) (shared between items) + requires mouse to be stationary for style.HoverStationaryDelay (once per item). |
| `NoSharedDelay` | `integer` | IsItemHovered() only: Disable shared delay system where moving from one item to the next keeps the previous timer for a short time (standard for tooltips with long delays) |
