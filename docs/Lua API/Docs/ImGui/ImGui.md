<!-- markdownlint-disable -->

# ImGui

## Methods

## `PushID`

```lua
function ImGui.PushID(id) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `id` | `integer` |  |

## `PopID`

```lua
function ImGui.PopID() end
```

## `Bullet`

```lua
function ImGui.Bullet() end
```

## `Text`

```lua
function ImGui.Text(text, ...) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `text` | `string` |  |
| `...` | `any` | Optional string format arguments |

## `TextDisabled`

```lua
function ImGui.TextDisabled(text, ...) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `text` | `string` |  |
| `...` | `any` | Optional string format arguments |

## `TextWrapped`

```lua
function ImGui.TextWrapped(text, ...) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `text` | `string` |  |
| `...` | `any` | Optional string format arguments |

## `TextUnformatted`

```lua
function ImGui.TextUnformatted(text) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `text` | `string` |  |

## `TextColored`

```lua
function ImGui.TextColored(col, text, ...) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `col` | `Vector4` |  |
| `text` | `string` |  |
| `...` | `any` | Optional string format arguments |

## `BulletText`

```lua
function ImGui.BulletText(text, ...) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `text` | `string` |  |
| `...` | `any` | Optional string format arguments |

## `Button`

```lua
function ImGui.Button(label, size) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `size` | `Vector2?` | Optional button size |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | clicked |

## `SmallButton`

```lua
function ImGui.SmallButton(label) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | clicked |

## `ArrowButton`

```lua
function ImGui.ArrowButton(label, direction) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `direction` | `integer` | [ImGuiDir](./ImGuiDir.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | clicked |

## `InvisibleButton`

```lua
function ImGui.InvisibleButton(label, size) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `size` | `Vector2` | Button size |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | clicked |

## `Checkbox`

```lua
function ImGui.Checkbox(label, v) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `v` | `boolean` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | value |
| `boolean` | clicked |

## `RadioButton`

```lua
function ImGui.RadioButton(label, active) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `active` | `boolean` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | clicked |

## `RadioButton`

```lua
function ImGui.RadioButton(label, v, vButton) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `v` | `integer` | Current index |
| `vButton` | `integer` | Index to change to |

### Returns

| Type | Description |
| --- | --- |
| `integer` | newValue |
| `boolean` | clicked |

## `ProgressBar`

```lua
function ImGui.ProgressBar(fraction, size, overlayText) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `fraction` | `number` |  |
| `size` | `Vector2?` | Optional frame size |
| `overlayText` | `string?` | Optional overlay text. Defaults to precentage. |

## `Begin`

```lua
function ImGui.Begin(name) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `name` | `string` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | visible |

## `Begin`

```lua
function ImGui.Begin(name, windowFlags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `name` | `string` |  |
| `windowFlags` | `integer` | [ImGuiWindowFlags](./ImGuiWindowFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | visible |

## `Begin`

```lua
function ImGui.Begin(name, open, windowFlags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `name` | `string` |  |
| `open` | `boolean` |  |
| `windowFlags` | `integer?` | Optional [ImGuiWindowFlags](./ImGuiWindowFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | visible |

## `End`

```lua
function ImGui.End() end
```

## `BeginChild`

```lua
function ImGui.BeginChild(name, size) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `name` | `string` |  |
| `size` | `Vector2?` | child size. |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | visible |

## `BeginChild`

```lua
function ImGui.BeginChild(name, size, childFlags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `name` | `string` |  |
| `size` | `Vector2` | child size. |
| `childFlags` | `integer?` | [ImGuiChildFlags](./ImGuiChildFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | visible |

## `BeginChild`

```lua
function ImGui.BeginChild(name, size, childFlags, windowFlags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `name` | `string` |  |
| `size` | `Vector2` | child size. |
| `childFlags` | `integer` | [ImGuiChildFlags](./ImGuiChildFlags.md) |
| `windowFlags` | `integer?` | Optional [ImGuiWindowFlags](./ImGuiWindowFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | visible |

## `EndChild`

```lua
function ImGui.EndChild() end
```

## `OpenPopup`

```lua
function ImGui.OpenPopup(name, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `name` | `string` | Popup name |
| `flags` | `integer?` | Optional [ImGuiPopupFlags](./ImGuiPopupFlags.md) |

## `IsPopupOpen`

```lua
function ImGui.IsPopupOpen(name, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `name` | `string` | Popup name |
| `flags` | `integer?` | Optional [ImGuiPopupFlags](./ImGuiPopupFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `CloseCurrentPopup`

```lua
function ImGui.CloseCurrentPopup() end
```

## `BeginPopup`

```lua
function ImGui.BeginPopup(name, windowFlags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `name` | `string` |  |
| `windowFlags` | `integer?` | Optional [ImGuiWindowFlags](./ImGuiWindowFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | isOpen |

## `BeginPopupModal`

```lua
function ImGui.BeginPopupModal(name, windowFlags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `name` | `string` |  |
| `windowFlags` | `integer?` | Optional [ImGuiWindowFlags](./ImGuiWindowFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | visible |

## `BeginPopupModal`

```lua
function ImGui.BeginPopupModal(name, open, windowFlags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `name` | `string` |  |
| `open` | `boolean` | When true, the popup will have a `(x)` close button in the title bar. |
| `windowFlags` | `integer?` | Optional [ImGuiWindowFlags](./ImGuiWindowFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | visible |
| `boolean` | open |

## `EndPopup`

```lua
function ImGui.EndPopup() end
```

## `BeginTabBar`

```lua
function ImGui.BeginTabBar(strID, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `strID` | `string` |  |
| `flags` | `integer?` | Optional [ImGuiTabBarFlags](./ImGuiTabBarFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `EndTabBar`

```lua
function ImGui.EndTabBar() end
```

## `BeginTabItem`

```lua
function ImGui.BeginTabItem(strID) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `strID` | `string` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `BeginTabItem`

```lua
function ImGui.BeginTabItem(strID, open, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `strID` | `string` |  |
| `open` | `boolean` |  |
| `flags` | `integer?` | Optional [ImGuiTabItemFlags](./ImGuiTabItemFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `EndTabItem`

```lua
function ImGui.EndTabItem() end
```

## `TabItemButton`

```lua
function ImGui.TabItemButton(strID, flags) end
```

Creates a Tab behaving like a button. Returns true when clicked and cannot be selected in the tab bar.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `strID` | `string` |  |
| `flags` | `integer?` | Optional [ImGuiTabItemFlags](./ImGuiTabItemFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `Combo`

```lua
function ImGui.Combo(label, currentItem, itemsSeparatedByZeros) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `currentItem` | `integer` |  |
| `itemsSeparatedByZeros` | `string` | A string with items separated by null terminators. Ex: `"Item1\0Item2\0Item3"` |

### Returns

| Type | Description |
| --- | --- |
| `integer` | currentItem |
| `boolean` | opened |

## `Combo`

```lua
function ImGui.Combo(label, currentItem, items) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `currentItem` | `integer` |  |
| `items` | `{[integer]: string}` | A table of strings. Must be a contiguous string array, anything else will be ignored. |

### Returns

| Type | Description |
| --- | --- |
| `integer` | currentItem |
| `boolean` | opened |

## `BeginTable`

```lua
function ImGui.BeginTable(label, columnCount, tableFlags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `columnCount` | `integer` | child size. |
| `tableFlags` | `integer?` | Optional [ImGuiTableFlags](./ImGuiTableFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | visible |

## `BeginTable`

```lua
function ImGui.BeginTable(label, columnCount, tableFlags, outerSize, innerWidth) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `columnCount` | `integer` | child size. |
| `tableFlags` | `integer` | [ImGuiTableFlags](./ImGuiTableFlags.md) |
| `outerSize` | `Vector2` |  |
| `innerWidth` | `number?` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | visible |

## `TableSetupColumn`

```lua
function ImGui.TableSetupColumn(label, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `flags` | `integer?` | Optional [ImGuiTableColumnFlags](./ImGuiTableColumnFlags.md) |

## `TableSetupColumn`

```lua
function ImGui.TableSetupColumn(label, flags, initWidthOrWeight) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `flags` | `integer` | [ImGuiTableColumnFlags](./ImGuiTableColumnFlags.md) |
| `initWidthOrWeight` | `number?` | Optional initial column width or weight |

## `TableSetupScrollFreeze`

```lua
function ImGui.TableSetupScrollFreeze(columns, rows) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `columns` | `integer` |  |
| `rows` | `integer` |  |

## `TableHeadersRow`

```lua
function ImGui.TableHeadersRow() end
```

## `TableAngledHeadersRow`

```lua
function ImGui.TableAngledHeadersRow() end
```

Submit a row with angled headers for every column with the ImGuiTableColumnFlags_AngledHeader flag. MUST BE FIRST ROW.

## `TableNextRow`

```lua
function ImGui.TableNextRow(flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `flags` | `integer?` | Optional [ImGuiTableRowFlags](./ImGuiTableRowFlags.md) |

## `TableNextColumn`

```lua
function ImGui.TableNextColumn() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `TableSetColumnIndex`

```lua
function ImGui.TableSetColumnIndex() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `TableGetRowIndex`

```lua
function ImGui.TableGetRowIndex() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` |  |

## `TableGetColumnIndex`

```lua
function ImGui.TableGetColumnIndex() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` |  |

## `TableGetColumnCount`

```lua
function ImGui.TableGetColumnCount() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` |  |

## `TableGetColumnName`

```lua
function ImGui.TableGetColumnName(columnNumber) end
```

Returns an empty string if column didn't have a name declared by TableSetupColumn(). Pass -1 to use current column.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `columnNumber` | `integer?` |  |

### Returns

| Type | Description |
| --- | --- |
| `string` |  |

## `TableGetColumnFlags`

```lua
function ImGui.TableGetColumnFlags(columnNumber) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `columnNumber` | `integer?` |  |

### Returns

| Type | Description |
| --- | --- |
| `integer` |  |

## `TableSetColumnEnabled`

```lua
function ImGui.TableSetColumnEnabled(columnNumber, enabled) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `columnNumber` | `integer` |  |
| `enabled` | `boolean` |  |

## `TableSetBgColor`

```lua
function ImGui.TableSetBgColor(target, color, columnNumber) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `target` | `integer` | [ImGuiTableBgTarget](ImGuiTableBgTarget) |
| `color` | `integer` |  |
| `columnNumber` | `integer?` |  |

## `EndTable`

```lua
function ImGui.EndTable() end
```

## `BeginCombo`

```lua
function ImGui.BeginCombo(label, preview, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `preview` | `string` |  |
| `flags` | `integer?` | Optional [ImGuiComboFlags](./ImGuiComboFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | opened |

## `EndCombo`

```lua
function ImGui.EndCombo() end
```

## `ListBox`

```lua
function ImGui.ListBox(label, currentItem, items, heightInItems) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `currentItem` | `integer` |  |
| `items` | `{[integer]: string}` | A table of strings. Must be a contiguous string array, anything else will be ignored. |
| `heightInItems` | `integer?` | Optional max items to show. Defaults to -1 |

### Returns

| Type | Description |
| --- | --- |
| `integer` | currentItem |
| `boolean` | visible |

## `BeginListBox`

```lua
function ImGui.BeginListBox(label, size) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `size` | `Vector2?` | Optional listbox size |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | visible |

## `EndListBox`

```lua
function ImGui.EndListBox() end
```

## `Selectable`

```lua
function ImGui.Selectable(label, selected, flags, size) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `selected` | `boolean` |  |
| `flags` | `integer?` | Optional [ImGuiSelectableFlags](./ImGuiSelectableFlags.md) |
| `size` | `Vector2?` | Optional selectable size |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | clicked |

## `MenuItem`

```lua
function ImGui.MenuItem(label, selected) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `selected` | `boolean` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | selected |
| `boolean` | clicked |

## `SliderInt`

```lua
function ImGui.SliderInt(label, v, vMin, vMax) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `v` | `integer` |  |
| `vMin` | `integer` | Minimum value |
| `vMax` | `integer` | Maximum value |

### Returns

| Type | Description |
| --- | --- |
| `integer` | v |
| `boolean` | changed |

## `SliderInt`

```lua
function ImGui.SliderInt(label, v, vMin, vMax, fmt, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `v` | `integer` |  |
| `vMin` | `integer` | Minimum value |
| `vMax` | `integer` | Maximum value |
| `fmt` | `string` | format string |
| `flags` | `integer?` | Optional [ImGuiSliderFlags](./ImGuiSliderFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `integer` | v |
| `boolean` | changed |

## `SliderFloat`

```lua
function ImGui.SliderFloat(label, v, vMin, vMax) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `v` | `number` |  |
| `vMin` | `number` | Minimum value |
| `vMax` | `number` | Maximum value |

### Returns

| Type | Description |
| --- | --- |
| `number` | v |
| `boolean` | changed |

## `SliderFloat`

```lua
function ImGui.SliderFloat(label, v, vMin, vMax, fmt, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `v` | `number` |  |
| `vMin` | `number` | Minimum value |
| `vMax` | `number` | Maximum value |
| `fmt` | `string` | format string |
| `flags` | `integer?` | Optional [ImGuiSliderFlags](./ImGuiSliderFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `number` | v |
| `boolean` | changed |

## `InputInt`

```lua
function ImGui.InputInt(label, v) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `v` | `integer` |  |

### Returns

| Type | Description |
| --- | --- |
| `integer` | v |
| `boolean` | changed |

## `InputInt`

```lua
function ImGui.InputInt(label, v, step, stepFast, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `v` | `integer` |  |
| `step` | `integer` | step |
| `stepFast` | `integer` | fast step |
| `flags` | `integer?` | Optional [ImGuiInputTextFlags](./ImGuiInputTextFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `integer` | v |
| `boolean` | changed |

## `InputFloat`

```lua
function ImGui.InputFloat(label, v) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `v` | `number` |  |

### Returns

| Type | Description |
| --- | --- |
| `number` | v |
| `boolean` | changed |

## `InputFloat`

```lua
function ImGui.InputFloat(label, v, step, stepFast, fmt) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `v` | `number` |  |
| `step` | `number` | step |
| `stepFast` | `number` | fast step |
| `fmt` | `string?` | Optional format string |

### Returns

| Type | Description |
| --- | --- |
| `number` | v |
| `boolean` | changed |

## `InputFloat`

```lua
function ImGui.InputFloat(label, v, step, stepFast, fmt, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `v` | `number` |  |
| `step` | `number` | step |
| `stepFast` | `number` | fast step |
| `fmt` | `string` | format string |
| `flags` | `integer?` | Optional [ImGuiInputTextFlags](./ImGuiInputTextFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `number` | v |
| `boolean` | changed |

## `InputDouble`

```lua
function ImGui.InputDouble(label, v) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `v` | `number` |  |

### Returns

| Type | Description |
| --- | --- |
| `number` | v |
| `boolean` | changed |

## `InputDouble`

```lua
function ImGui.InputDouble(label, v, step, stepFast, fmt) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `v` | `number` |  |
| `step` | `number` | step |
| `stepFast` | `number` | fast step |
| `fmt` | `string?` | Optional format string |

### Returns

| Type | Description |
| --- | --- |
| `number` | v |
| `boolean` | changed |

## `InputDouble`

```lua
function ImGui.InputDouble(label, v, step, stepFast, fmt, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `v` | `number` |  |
| `step` | `number` | step |
| `stepFast` | `number` | fast step |
| `fmt` | `string` | format string |
| `flags` | `integer?` | Optional [ImGuiInputTextFlags](./ImGuiInputTextFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `number` | v |
| `boolean` | changed |

## `InputText`

```lua
function ImGui.InputText(label, text, bufferSize, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `text` | `string` |  |
| `bufferSize` | `integer` |  |
| `flags` | `integer?` | Optional [ImGuiInputTextFlags](./ImGuiInputTextFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `string` | text |
| `boolean` | changed |

## `InputTextWithHint`

```lua
function ImGui.InputTextWithHint(label, hint, text, bufferSize, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `hint` | `string` |  |
| `text` | `string` |  |
| `bufferSize` | `integer` |  |
| `flags` | `integer?` | Optional [ImGuiInputTextFlags](./ImGuiInputTextFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `string` | text |
| `boolean` | changed |

## `InputTextMultiline`

```lua
function ImGui.InputTextMultiline(label, text, bufferSize) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `text` | `string` |  |
| `bufferSize` | `integer` |  |

### Returns

| Type | Description |
| --- | --- |
| `string` | text |
| `boolean` | changed |

## `InputTextMultiline`

```lua
function ImGui.InputTextMultiline(label, text, bufferSize, flags, size) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `text` | `string` |  |
| `bufferSize` | `integer` |  |
| `flags` | `integer` | [ImGuiInputTextFlags](./ImGuiInputTextFlags.md) |
| `size` | `Vector2?` | Optional widget size |

### Returns

| Type | Description |
| --- | --- |
| `string` | text |
| `boolean` | changed |

## `ColorButton`

```lua
function ImGui.ColorButton(label, color) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `color` | `Vector4` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | clicked |

## `ColorButton`

```lua
function ImGui.ColorButton(label, color, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `color` | `Vector4` |  |
| `flags` | `integer?` | Optional [ImGuiColorEditFlags](./ImGuiColorEditFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | clicked |

## `ColorButton`

```lua
function ImGui.ColorButton(label, color, flags, size) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `color` | `Vector4` |  |
| `flags` | `integer` | [ImGuiColorEditFlags](./ImGuiColorEditFlags.md) |
| `size` | `Vector2?` | Optional picker size |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | clicked |

## `ColorEdit3`

```lua
function ImGui.ColorEdit3(label, outCol, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `outCol` | `Vector3` |  |
| `flags` | `integer?` | Optional [ImGuiColorEditFlags](./ImGuiInputTextFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | changed Returns true when the color changes. The vector is mutated in-place. |

## `ColorPicker3`

```lua
function ImGui.ColorPicker3(label, outCol, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `outCol` | `Vector3` |  |
| `flags` | `integer?` | Optional [ImGuiColorEditFlags](./ImGuiInputTextFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | changed Returns true when the color changes. The vector is mutated in-place. |

## `ColorEdit4`

```lua
function ImGui.ColorEdit4(label, outCol, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `outCol` | `Vector4` |  |
| `flags` | `integer?` | Optional [ImGuiColorEditFlags](./ImGuiInputTextFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | changed Returns true when the color changes. The vector is mutated in-place. |

## `ColorPicker4`

```lua
function ImGui.ColorPicker4(label, outCol, flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `outCol` | `Vector4` |  |
| `flags` | `integer?` | Optional [ImGuiColorEditFlags](./ImGuiInputTextFlags.md) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | changed Returns true when the color changes. The vector is mutated in-place. |

## `BeginDisabled`

```lua
function ImGui.BeginDisabled(cond) end
```

Disables all ImGui widgets created between this call and EndDisabled

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `cond` | `boolean?` | Optional condition |

## `EndDisabled`

```lua
function ImGui.EndDisabled() end
```

## `SameLine`

```lua
function ImGui.SameLine() end
```

## `SameLine`

```lua
function ImGui.SameLine(offsetX, spacing) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `offsetX` | `number` | X position to start at. Defaults to `0`. |
| `spacing` | `number?` | Optional spacing after the previous item. Defaults to the current item spacing. |

## `NewLine`

```lua
function ImGui.NewLine() end
```

## `Spacing`

```lua
function ImGui.Spacing() end
```

## `Separator`

```lua
function ImGui.Separator() end
```

## `SeparatorEx`

```lua
function ImGui.SeparatorEx(flags, thickness) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `flags` | `integer` | [ImGuiSeparatorFlags](./ImGuiSeparatorFlags.md) |
| `thickness` | `number?` | Optional separator thickness. Defaults to 1.0 |

## `SeparatorText`

```lua
function ImGui.SeparatorText(text) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `text` | `string` |  |

## `Indent`

```lua
function ImGui.Indent(indentX) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `indentX` | `number?` | Optional indentation width. Defaults to the current item spacing. |

## `Unindent`

```lua
function ImGui.Unindent(indentX) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `indentX` | `number?` | Optional indentation width. Defaults to the current item spacing. |

## `Dummy`

```lua
function ImGui.Dummy(size) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `size` | `Vector2` |  |

## `SetCursorPos`

```lua
function ImGui.SetCursorPos(pos) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `pos` | `Vector2` |  |

## `SetCursorPosX`

```lua
function ImGui.SetCursorPosX(x) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `x` | `number` | X position relative to the current window. |

## `SetCursorPosY`

```lua
function ImGui.SetCursorPosY(y) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `y` | `number` | Y position relative to the current window. |

## `GetCursorPos`

```lua
function ImGui.GetCursorPos() end
```

### Returns

| Type | Description |
| --- | --- |
| `Vector2` | cursorPos |

## `GetCursorPosX`

```lua
function ImGui.GetCursorPosX() end
```

### Returns

| Type | Description |
| --- | --- |
| `number` | x Current X position relative to the current window. |

## `GetCursorPosY`

```lua
function ImGui.GetCursorPosY() end
```

### Returns

| Type | Description |
| --- | --- |
| `number` | y Current Y position relative to the current window. |

## `GetContentRegionAvail`

```lua
function ImGui.GetContentRegionAvail() end
```

### Returns

| Type | Description |
| --- | --- |
| `Vector2` | avail Available content region. |

## `GetWindowWidth`

```lua
function ImGui.GetWindowWidth() end
```

### Returns

| Type | Description |
| --- | --- |
| `number` | width |

## `GetWindowHeight`

```lua
function ImGui.GetWindowHeight() end
```

### Returns

| Type | Description |
| --- | --- |
| `number` | height |

## `GetWindowSize`

```lua
function ImGui.GetWindowSize() end
```

### Returns

| Type | Description |
| --- | --- |
| `Vector2` | windowSize |

## `GetWindowPos`

```lua
function ImGui.GetWindowPos() end
```

### Returns

| Type | Description |
| --- | --- |
| `Vector2` | windowPos Current window position. |

## `GetFrameHeight`

```lua
function ImGui.GetFrameHeight() end
```

### Returns

| Type | Description |
| --- | --- |
| `number` | frameHeight |

## `GetFrameHeightWithSpacing`

```lua
function ImGui.GetFrameHeightWithSpacing() end
```

### Returns

| Type | Description |
| --- | --- |
| `number` | frameHeight Frame height with spacing. |

## `SetNextItemWidth`

```lua
function ImGui.SetNextItemWidth(width) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `width` | `number` | Width of the next item. |

## `PushItemWidth`

```lua
function ImGui.PushItemWidth(width) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `width` | `number` | Width of subsequent items. |

## `PopItemWidth`

```lua
function ImGui.PopItemWidth() end
```

## `CalcTextSize`

```lua
function ImGui.CalcTextSize(text, wrapWidth) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `text` | `string` |  |
| `wrapWidth` | `number?` |  |

### Returns

| Type | Description |
| --- | --- |
| `Vector2` | size |

## `CalcTextSize`

```lua
function ImGui.CalcTextSize(text, hideTextAfterDoubleHash, wrapWidth) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `text` | `string` |  |
| `hideTextAfterDoubleHash` | `boolean` |  |
| `wrapWidth` | `number?` |  |

### Returns

| Type | Description |
| --- | --- |
| `Vector2` | size |

## `GetItemRectMin`

```lua
function ImGui.GetItemRectMin(scale) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `scale` | `number` |  |

## `GetItemRectMin`

```lua
function ImGui.GetItemRectMin() end
```

### Returns

| Type | Description |
| --- | --- |
| `Vector2` | rectMin |

## `GetItemRectMax`

```lua
function ImGui.GetItemRectMax() end
```

### Returns

| Type | Description |
| --- | --- |
| `Vector2` | rectMax |

## `GetItemRectSize`

```lua
function ImGui.GetItemRectSize() end
```

### Returns

| Type | Description |
| --- | --- |
| `Vector2` | size |

## `GetItemID`

```lua
function ImGui.GetItemID() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` | itemID |

## `IsItemHovered`

```lua
function ImGui.IsItemHovered(flags) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `flags` | `integer?` | Optional [ImGuiHoveredFlags](ImGuiHoveredFlags) |

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsItemActive`

```lua
function ImGui.IsItemActive() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsItemFocused`

```lua
function ImGui.IsItemFocused() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsItemVisible`

```lua
function ImGui.IsItemVisible() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsItemEdited`

```lua
function ImGui.IsItemEdited() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsItemActivated`

```lua
function ImGui.IsItemActivated() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsItemDeactivated`

```lua
function ImGui.IsItemDeactivated() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsItemDeactivatedAfterEdit`

```lua
function ImGui.IsItemDeactivatedAfterEdit() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsItemToggledOpen`

```lua
function ImGui.IsItemToggledOpen() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsAnyItemHovered`

```lua
function ImGui.IsAnyItemHovered() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsAnyItemActive`

```lua
function ImGui.IsAnyItemActive() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsAnyItemFocused`

```lua
function ImGui.IsAnyItemFocused() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsItemClicked`

```lua
function ImGui.IsItemClicked(mouseBtn) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `mouseBtn` | `integer?` | 0: "left" \| 1: "right" \| 2: "middle" |

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsAnyItemHovered`

```lua
function ImGui.IsAnyItemHovered() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `PushStyleVar`

```lua
function ImGui.PushStyleVar(styleVar, v) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `styleVar` | `integer` | [ImGuiStyleVar](./ImGuiStyleVar.md) index |
| `v` | `number` | style value |

## `PushStyleVar`

```lua
function ImGui.PushStyleVar(styleVar, v) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `styleVar` | `integer` | [ImGuiStyleVar](./ImGuiStyleVar.md) index |
| `v` | `Vector2` |  |

## `PopStyleVar`

```lua
function ImGui.PopStyleVar(count) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `count` | `integer?` | Count of pushed style variables to pop. Defaults to 1; Must match the number of pushed style vars. |

## `PushStyleColor`

```lua
function ImGui.PushStyleColor(colIdx, color) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `colIdx` | `integer` | [ImGuiCol](./ImGuiCol.md) index |
| `color` | `Vector4` |  |

## `PopStyleColor`

```lua
function ImGui.PopStyleColor(count) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `count` | `integer?` | Count of pushed style colors to pop. Defaults to 1; Must match the number of pushed style cols. |

## `SetMouseCursor`

```lua
function ImGui.SetMouseCursor(cursorIdx) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `cursorIdx` | `integer` | [ImGuiMouseCursor](./ImGuiMouseCursor.md) index |

## `Toggle`

```lua
function ImGui.Toggle(label, v) end
```

Draws a toggle widget that can be used instead of a regular ImGui checkbox.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` | Tooltip text |
| `v` | `boolean` | Tooltip text |

## `Toggle`

```lua
function ImGui.Toggle(label, v, size) end
```

Draws a toggle widget that can be used instead of a regular ImGui checkbox.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `label` | `string` |  |
| `v` | `boolean` |  |
| `size` | `Vector2` |  |

### Returns

| Type | Description |
| --- | --- |
| `boolean` | value |
| `boolean` | clicked |

## `SetTooltip`

```lua
function ImGui.SetTooltip(text, ...) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `text` | `string` |  |
| `...` | `any` | Optional format args |

## `BeginTooltip`

```lua
function ImGui.BeginTooltip() end
```

## `EndTooltip`

```lua
function ImGui.EndTooltip() end
```

## `GetWindowDrawList`

```lua
function ImGui.GetWindowDrawList() end
```

### Returns

| Type | Description |
| --- | --- |
| `ImDrawList` |  |

## `GetBackgroundDrawList`

```lua
function ImGui.GetBackgroundDrawList() end
```

### Returns

| Type | Description |
| --- | --- |
| `ImDrawList` |  |

## `GetForegroundDrawList`

```lua
function ImGui.GetForegroundDrawList() end
```

### Returns

| Type | Description |
| --- | --- |
| `ImDrawList` |  |

## `GetTime`

```lua
function ImGui.GetTime() end
```

### Returns

| Type | Description |
| --- | --- |
| `number` |  |

## `GetFrameCount`

```lua
function ImGui.GetFrameCount() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` |  |

## `GetFontSize`

```lua
function ImGui.GetFontSize() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` |  |

## `ColorConvertU32ToFloat4`

```lua
function ImGui.ColorConvertU32ToFloat4(col) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `col` | `integer` | Packed 32bit integer |

### Returns

| Type | Description |
| --- | --- |
| `Vector4` | rgba Normalised RGBA |

## `ColorConvertFloat4ToU32`

```lua
function ImGui.ColorConvertFloat4ToU32(col) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `col` | `Vector4` | Normalised RGBA |

### Returns

| Type | Description |
| --- | --- |
| `integer` | u32 Packed 32bit integer |

## `ColorConvertHSVtoRGB`

```lua
function ImGui.ColorConvertHSVtoRGB(h, s, v) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `h` | `number` |  |
| `s` | `number` |  |
| `v` | `number` |  |

### Returns

| Type | Description |
| --- | --- |
| `number` | r |
| `number` | g |
| `number` | b |

## `ColorConvertRGBtoHSV`

```lua
function ImGui.ColorConvertRGBtoHSV(r, g, b) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `r` | `number` |  |
| `g` | `number` |  |
| `b` | `number` |  |

### Returns

| Type | Description |
| --- | --- |
| `number` | h |
| `number` | s |
| `number` | v |
