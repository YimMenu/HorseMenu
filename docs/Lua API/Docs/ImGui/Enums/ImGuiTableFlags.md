<!-- markdownlint-disable -->

# ImGuiTableFlags

## Fields

| Name | Type | Description |
| --- | --- | --- |
| `None` | `integer` |  |
| `Resizable` | `integer` | Enable resizing columns. |
| `Reorderable` | `integer` | Enable reordering columns in header row (need calling TableSetupColumn() + TableHeadersRow() to display headers) |
| `Hideable` | `integer` | Enable hiding/disabling columns in context menu. |
| `Sortable` | `integer` | Enable sorting. Call TableGetSortSpecs() to obtain sort specs. Also see ImGuiTableFlags_SortMulti and ImGuiTableFlags_SortTristate. |
| `NoSavedSettings` | `integer` | Disable persisting columns order, width and sort settings in the .ini file. |
| `ContextMenuInBody` | `integer` | Right-click on columns body/contents will display table context menu. By default it is available in TableHeadersRow(). |
| `RowBg` | `integer` | Set each RowBg color with ImGuiCol_TableRowBg or ImGuiCol_TableRowBgAlt (equivalent of calling TableSetBgColor with ImGuiTableBgFlags_RowBg0 on each row manually) |
| `BordersInnerH` | `integer` | Draw horizontal borders between rows. |
| `BordersOuterH` | `integer` | Draw horizontal borders at the top and bottom. |
| `BordersInnerV` | `integer` | Draw vertical borders between columns. |
| `BordersOuterV` | `integer` | Draw vertical borders on the left and right sides. |
| `BordersH` | `integer` | Draw horizontal borders. |
| `BordersV` | `integer` | Draw vertical borders. |
| `BordersInner` | `integer` | Draw inner borders. |
| `BordersOuter` | `integer` | Draw outer borders. |
| `Borders` | `integer` | Draw all borders. |
| `NoBordersInBody` | `integer` | [ALPHA] Disable vertical borders in columns Body (borders will always appear in Headers). -> May move to style |
| `NoBordersInBodyUntilResize` | `integer` | [ALPHA] Disable vertical borders in columns Body until hovered for resize (borders will always appear in Headers). -> May move to style |
| `SizingFixedFit` | `integer` | Columns default to _WidthFixed or _WidthAuto (if resizable or not resizable), matching contents width. |
| `SizingFixedSame` | `integer` | Columns default to _WidthFixed or _WidthAuto (if resizable or not resizable), matching the maximum contents width of all columns. Implicitly enable ImGuiTableFlags_NoKeepColumnsVisible. |
| `SizingStretchProp` | `integer` | Columns default to _WidthStretch with default weights proportional to each columns contents widths. |
| `SizingStretchSame` | `integer` | Columns default to _WidthStretch with default weights all equal, unless overridden by TableSetupColumn(). |
| `NoHostExtendX` | `integer` | Make outer width auto-fit to columns, overriding outer_size.x value. Only available when ScrollX/ScrollY are disabled and Stretch columns are not used. |
| `NoHostExtendY` | `integer` | Make outer height stop exactly at outer_size.y (prevent auto-extending table past the limit). Only available when ScrollX/ScrollY are disabled. Data below the limit will be clipped and not visible. |
| `NoKeepColumnsVisible` | `integer` | Disable keeping column always minimally visible when ScrollX is off and table gets too small. Not recommended if columns are resizable. |
| `PreciseWidths` | `integer` | Disable distributing remainder width to stretched columns (width allocation on a 100-wide table with 3 columns: Without this flag: 33,33,34. With this flag: 33,33,33). With larger number of columns, resizing will appear to be less smooth. |
| `NoClip` | `integer` | Disable clipping rectangle for every individual columns (reduce draw command count, items will be able to overflow into other columns). Generally incompatible with TableSetupScrollFreeze(). |
| `PadOuterX` | `integer` | Default if BordersOuterV is on. Enable outermost padding. Generally desirable if you have headers. |
| `NoPadOuterX` | `integer` | Default if BordersOuterV is off. Disable outermost padding. |
| `NoPadInnerX` | `integer` | Disable inner padding between columns (double inner padding if BordersOuterV is on, single inner padding if BordersOuterV is off). |
| `ScrollX` | `integer` | Enable horizontal scrolling. Require 'outer_size' parameter of BeginTable() to specify the container size. Changes default sizing policy. Because this creates a child window, ScrollY is currently generally recommended when using ScrollX. |
| `ScrollY` | `integer` | Enable vertical scrolling. Require 'outer_size' parameter of BeginTable() to specify the container size. |
| `SortMulti` | `integer` | Hold shift when clicking headers to sort on multiple column. TableGetSortSpecs() may return specs where (SpecsCount > 1). |
| `SortTristate` | `integer` | Allow no sorting, disable default sorting. TableGetSortSpecs() may return specs where (SpecsCount == 0). |
| `HighlightHoveredColumn` | `integer` | Highlight column headers when hovered (may evolve into a fuller highlight) |
| `SizingMask_` | `integer` |  |
