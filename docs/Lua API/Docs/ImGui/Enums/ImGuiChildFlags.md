<!-- markdownlint-disable -->

# ImGuiChildFlags

## Fields

| Name | Type | Description |
| --- | --- | --- |
| `None` | `integer` |  |
| `Borders` | `integer` | Show an outer border and enable WindowPadding. (IMPORTANT: this is always == 1 == true for legacy reason) |
| `AlwaysUseWindowPadding` | `integer` | Pad with style.WindowPadding even if no border are drawn (no padding by default for non-bordered child windows because it makes more sense) |
| `ResizeX` | `integer` | Allow resize from right border (layout direction). Enable .ini saving (unless ImGuiWindowFlags_NoSavedSettings passed to window flags) |
| `ResizeY` | `integer` | Allow resize from bottom border (layout direction). " |
| `AutoResizeX` | `integer` | Enable auto-resizing width. Read "IMPORTANT: Size measurement" details above. |
| `AutoResizeY` | `integer` | Enable auto-resizing height. Read "IMPORTANT: Size measurement" details above. |
| `AlwaysAutoResize` | `integer` | Combined with AutoResizeX/AutoResizeY. Always measure size even when child is hidden, always return true, always disable clipping optimization! NOT RECOMMENDED. |
| `FrameStyle` | `integer` | Style the child window like a framed item: use FrameBg, FrameRounding, FrameBorderSize, FramePadding instead of ChildBg, ChildRounding, ChildBorderSize, WindowPadding. |
| `NavFlattened` | `integer` | [BETA] Share focus scope, allow keyboard/gamepad navigation to cross over parent border to this child or between sibling child windows. |
