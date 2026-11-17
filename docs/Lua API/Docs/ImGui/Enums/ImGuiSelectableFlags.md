<!-- markdownlint-disable -->

# ImGuiSelectableFlags

## Fields

| Name | Type | Description |
| --- | --- | --- |
| `None` | `integer` |  |
| `NoAutoClosePopups` | `integer` | Clicking this doesn't close parent popup window (overrides ImGuiItemFlags_AutoClosePopups) |
| `SpanAllColumns` | `integer` | Frame will span all columns of its container table (text will still fit in current column) |
| `AllowDoubleClick` | `integer` | Generate press events on double clicks too |
| `Disabled` | `integer` | Cannot be selected, display grayed out text |
| `AllowOverlap` | `integer` | (WIP) Hit testing to allow subsequent widgets to overlap this one |
| `Highlight` | `integer` | Make the item be displayed as if it is hovered |
| `SelectOnNav` | `integer` | Auto-select when moved into, unless Ctrl is held. Automatic when in a BeginMultiSelect() block. |
