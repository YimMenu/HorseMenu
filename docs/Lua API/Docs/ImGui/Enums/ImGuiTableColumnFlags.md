<!-- markdownlint-disable -->

# ImGuiTableColumnFlags

## Fields

| Name | Type | Description |
| --- | --- | --- |
| `None` | `integer` |  |
| `Disabled` | `integer` | Overriding/master disable flag: hide column, won't show in context menu (unlike calling TableSetColumnEnabled() which manipulates the user accessible state) |
| `DefaultHide` | `integer` | Default as a hidden/disabled column. |
| `DefaultSort` | `integer` | Default as a sorting column. |
| `WidthStretch` | `integer` | Column will stretch. Preferable with horizontal scrolling disabled (default if table sizing policy is _SizingStretchSame or _SizingStretchProp). |
| `WidthFixed` | `integer` | Column will not stretch. Preferable with horizontal scrolling enabled (default if table sizing policy is _SizingFixedFit and table is resizable). |
| `NoResize` | `integer` | Disable manual resizing. |
| `NoReorder` | `integer` | Disable manual reordering this column, this will also prevent other columns from crossing over this column. |
| `NoHide` | `integer` | Disable ability to hide/disable this column. |
| `NoClip` | `integer` | Disable clipping for this column (all NoClip columns will render in a same draw command). |
| `NoSort` | `integer` | Disable ability to sort on this field (even if ImGuiTableFlags_Sortable is set on the table). |
| `NoSortAscending` | `integer` | Disable ability to sort in the ascending direction. |
| `NoSortDescending` | `integer` | Disable ability to sort in the descending direction. |
| `NoHeaderLabel` | `integer` | TableHeadersRow() will submit an empty label for this column. Convenient for some small columns. Name will still appear in context menu or in angled headers. You may append into this cell by calling TableSetColumnIndex() right after the TableHeadersRow() call. |
| `NoHeaderWidth` | `integer` | Disable header text width contribution to automatic column width. |
| `PreferSortAscending` | `integer` | Make the initial sort direction Ascending when first sorting on this column (default). |
| `PreferSortDescending` | `integer` | Make the initial sort direction Descending when first sorting on this column. |
| `IndentEnable` | `integer` | Use current Indent value when entering cell (default for column 0). |
| `IndentDisable` | `integer` | Ignore current Indent value when entering cell (default for columns > 0). Indentation changes _within_ the cell will still be honored. |
| `AngledHeader` | `integer` | TableHeadersRow() will submit an angled header row for this column. Note this will add an extra row. |
| `IsEnabled` | `integer` | Status: is enabled == not hidden by user/api (referred to as "Hide" in _DefaultHide and _NoHide) flags. |
| `IsVisible` | `integer` | Status: is visible == is enabled AND not clipped by scrolling. |
| `IsSorted` | `integer` | Status: is currently part of the sort specs |
| `IsHovered` | `integer` | Status: is hovered by mouse |
| `WidthMask_` | `integer` |  |
| `IndentMask_` | `integer` |  |
| `StatusMask_` | `integer` |  |
| `NoDirectResize_` | `integer` | [Internal] Disable user resizing this column directly (it may however we resized indirectly from its left edge) |
