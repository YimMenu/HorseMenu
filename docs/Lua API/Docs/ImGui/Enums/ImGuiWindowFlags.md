<!-- markdownlint-disable -->

# ImGuiWindowFlags

## Fields

| Name | Type | Description |
| --- | --- | --- |
| `None` | `integer` |  |
| `NoTitleBar` | `integer` | Disable title-bar |
| `NoResize` | `integer` | Disable user resizing with the lower-right grip |
| `NoMove` | `integer` | Disable user moving the window |
| `NoScrollbar` | `integer` | Disable scrollbars (window can still scroll with mouse or programmatically) |
| `NoScrollWithMouse` | `integer` | Disable user vertically scrolling with mouse wheel. On child window, mouse wheel will be forwarded to the parent unless NoScrollbar is also set. |
| `NoCollapse` | `integer` | Disable user collapsing window by double-clicking on it. Also referred to as Window Menu Button (e.g. within a docking node). |
| `AlwaysAutoResize` | `integer` | Resize every window to its content every frame |
| `NoBackground` | `integer` | Disable drawing background color (WindowBg, etc.) and outside border. Similar as using SetNextWindowBgAlpha(0.0f). |
| `NoSavedSettings` | `integer` | Never load/save settings in .ini file |
| `NoMouseInputs` | `integer` | Disable catching mouse, hovering test with pass through. |
| `MenuBar` | `integer` | Has a menu-bar |
| `HorizontalScrollbar` | `integer` | Allow horizontal scrollbar to appear (off by default). You may use SetNextWindowContentSize(ImVec2(width,0.0f)); prior to calling Begin() to specify width. Read code in imgui_demo in the "Horizontal Scrolling" section. |
| `NoFocusOnAppearing` | `integer` | Disable taking focus when transitioning from hidden to visible state |
| `NoBringToFrontOnFocus` | `integer` | Disable bringing window to front when taking focus (e.g. clicking on it or programmatically giving it focus) |
| `AlwaysVerticalScrollbar` | `integer` | Always show vertical scrollbar (even if ContentSize.y < Size.y) |
| `AlwaysHorizontalScrollbar` | `integer` | Always show horizontal scrollbar (even if ContentSize.x < Size.x) |
| `NoNavInputs` | `integer` | No keyboard/gamepad navigation within the window |
| `NoNavFocus` | `integer` | No focusing toward this window with keyboard/gamepad navigation (e.g. skipped by CTRL+TAB) |
| `UnsavedDocument` | `integer` | Display a dot next to the title. When used in a tab/docking context, tab is selected when clicking the X + closure is not assumed (will wait for user to stop submitting the tab). Otherwise closure is assumed when pressing the X, so if you keep submitting the tab may reappear at end of tab bar. |
| `NoNav` | `integer` |  |
| `NoDecoration` | `integer` |  |
| `NoInputs` | `integer` |  |
