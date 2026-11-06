---@meta

---@class ImGui
ImGui = {}

---@param id integer 
function ImGui.PushID(id) end

function ImGui.PopID() end

function ImGui.Bullet() end

---@param text string 
---@param ... any Optional string format arguments
function ImGui.Text(text, ...) end

---@param text string 
---@param ... any Optional string format arguments
function ImGui.TextDisabled(text, ...) end

---@param text string 
---@param ... any Optional string format arguments
function ImGui.TextWrapped(text, ...) end

---@param text string 
function ImGui.TextUnformatted(text) end

---@param col Vector4 
---@param text string 
---@param ... any Optional string format arguments
function ImGui.TextColored(col, text, ...) end

---@param text string 
---@param ... any Optional string format arguments
function ImGui.BulletText(text, ...) end

---@param label string 
---@param size Vector2? Optional button size
---@return boolean clicked
function ImGui.Button(label, size) end

---@param label string 
---@return boolean clicked
function ImGui.SmallButton(label) end

---@param label string 
---@param direction integer [ImGuiDir](lua://ImGuiDir)
---@return boolean clicked
function ImGui.ArrowButton(label, direction) end

---@param label string 
---@param size Vector2 Button size
---@return boolean clicked
function ImGui.InvisibleButton(label, size) end

---@param label string 
---@param v boolean 
---@return boolean value
---@return boolean clicked
function ImGui.Checkbox(label, v) end

---@param label string 
---@param active boolean 
---@return boolean clicked
function ImGui.RadioButton(label, active) end

---@param label string 
---@param v integer Current index
---@param vButton integer Index to change to
---@return integer newValue
---@return boolean clicked
function ImGui.RadioButton(label, v, vButton) end

---@param fraction number 
---@param size Vector2? Optional frame size
---@param overlayText string? Optional overlay text. Defaults to precentage.
function ImGui.ProgressBar(fraction, size, overlayText) end

---@param name string 
---@return boolean visible
function ImGui.Begin(name) end

---@param name string 
---@param windowFlags integer [ImGuiWindowFlags](lua://ImGuiWindowFlags)
---@return boolean visible
function ImGui.Begin(name, windowFlags) end

---@param name string 
---@param open boolean 
---@param windowFlags integer? Optional [ImGuiWindowFlags](lua://ImGuiWindowFlags)
---@return boolean visible
function ImGui.Begin(name, open, windowFlags) end

function ImGui.End() end

---@param name string 
---@param size Vector2? child size.
---@return boolean visible
function ImGui.BeginChild(name, size) end

---@param name string 
---@param size Vector2 child size.
---@param childFlags integer? [ImGuiChildFlags](lua://ImGuiChildFlags)
---@return boolean visible
function ImGui.BeginChild(name, size, childFlags) end

---@param name string 
---@param size Vector2 child size.
---@param childFlags integer [ImGuiChildFlags](lua://ImGuiChildFlags)
---@param windowFlags integer? Optional [ImGuiWindowFlags](lua://ImGuiWindowFlags)
---@return boolean visible
function ImGui.BeginChild(name, size, childFlags, windowFlags) end

function ImGui.EndChild() end

---@param name string Popup name
---@param flags integer? Optional [ImGuiPopupFlags](lua://ImGuiPopupFlags)
function ImGui.OpenPopup(name, flags) end

---@param name string Popup name
---@param flags integer? Optional [ImGuiPopupFlags](lua://ImGuiPopupFlags)
---@return boolean 
function ImGui.IsPopupOpen(name, flags) end

function ImGui.CloseCurrentPopup() end

---@param name string 
---@param windowFlags integer? Optional [ImGuiWindowFlags](lua://ImGuiWindowFlags)
---@return boolean isOpen
function ImGui.BeginPopup(name, windowFlags) end

---@param name string 
---@param windowFlags integer? Optional [ImGuiWindowFlags](lua://ImGuiWindowFlags)
---@return boolean visible
function ImGui.BeginPopupModal(name, windowFlags) end

---@param name string 
---@param open boolean When true, the popup will have a `(x)` close button in the title bar.
---@param windowFlags integer? Optional [ImGuiWindowFlags](lua://ImGuiWindowFlags)
---@return boolean visible
---@return boolean open
function ImGui.BeginPopupModal(name, open, windowFlags) end

function ImGui.EndPopup() end

---@param strID string 
---@param flags integer? Optional [ImGuiTabBarFlags](lua://ImGuiTabBarFlags)
---@return boolean 
function ImGui.BeginTabBar(strID, flags) end

function ImGui.EndTabBar() end

---@param strID string 
---@return boolean 
function ImGui.BeginTabItem(strID) end

---@param strID string 
---@param open boolean 
---@param flags integer? Optional [ImGuiTabItemFlags](lua://ImGuiTabItemFlags)
---@return boolean 
function ImGui.BeginTabItem(strID, open, flags) end

function ImGui.EndTabItem() end

-- Creates a Tab behaving like a button. Returns true when clicked and cannot be selected in the tab bar.
---@param strID string 
---@param flags integer? Optional [ImGuiTabItemFlags](lua://ImGuiTabItemFlags)
---@return boolean 
function ImGui.TabItemButton(strID, flags) end

---@param label string 
---@param currentItem integer 
---@param itemsSeparatedByZeros string A string with items separated by null terminators. Ex: `"Item1\0Item2\0Item3"`
---@return integer currentItem
---@return boolean opened
function ImGui.Combo(label, currentItem, itemsSeparatedByZeros) end

---@param label string 
---@param currentItem integer 
---@param items {[integer]: string} A table of strings. Must be a contiguous string array, anything else will be ignored.
---@return integer currentItem
---@return boolean opened
function ImGui.Combo(label, currentItem, items) end

---@param label string 
---@param columnCount integer child size.
---@param tableFlags integer? Optional [ImGuiTableFlags](lua://ImGuiTableFlags)
---@return boolean visible
function ImGui.BeginTable(label, columnCount, tableFlags) end

---@param label string 
---@param columnCount integer child size.
---@param tableFlags integer [ImGuiTableFlags](lua://ImGuiTableFlags)
---@param outerSize Vector2 
---@param innerWidth number? 
---@return boolean visible
function ImGui.BeginTable(label, columnCount, tableFlags, outerSize, innerWidth) end

---@param label string 
---@param flags integer? Optional [ImGuiTableColumnFlags](lua://ImGuiTableColumnFlags)
function ImGui.TableSetupColumn(label, flags) end

---@param label string 
---@param flags integer [ImGuiTableColumnFlags](lua://ImGuiTableColumnFlags)
---@param initWidthOrWeight number? Optional initial column width or weight
function ImGui.TableSetupColumn(label, flags, initWidthOrWeight) end

---@param columns integer 
---@param rows integer 
function ImGui.TableSetupScrollFreeze(columns, rows) end

function ImGui.TableHeadersRow() end

-- Submit a row with angled headers for every column with the ImGuiTableColumnFlags_AngledHeader flag. MUST BE FIRST ROW.
function ImGui.TableAngledHeadersRow() end

---@param flags integer? Optional [ImGuiTableRowFlags](lua://ImGuiTableRowFlags)
function ImGui.TableNextRow(flags) end

---@return boolean 
function ImGui.TableNextColumn() end

---@return boolean 
function ImGui.TableSetColumnIndex() end

---@return integer 
function ImGui.TableGetRowIndex() end

---@return integer 
function ImGui.TableGetColumnIndex() end

---@return integer 
function ImGui.TableGetColumnCount() end

-- Returns an empty string if column didn't have a name declared by TableSetupColumn(). Pass -1 to use current column.
---@param columnNumber integer? 
---@return string 
function ImGui.TableGetColumnName(columnNumber) end

---@param columnNumber integer? 
---@return integer 
function ImGui.TableGetColumnFlags(columnNumber) end

---@param columnNumber integer 
---@param enabled boolean 
function ImGui.TableSetColumnEnabled(columnNumber, enabled) end

---@param target integer [ImGuiTableBgTarget](ImGuiTableBgTarget)
---@param color integer 
---@param columnNumber integer? 
function ImGui.TableSetBgColor(target, color, columnNumber) end

function ImGui.EndTable() end

---@param label string 
---@param preview string 
---@param flags integer? Optional [ImGuiComboFlags](lua://ImGuiComboFlags)
---@return boolean opened
function ImGui.BeginCombo(label, preview, flags) end

function ImGui.EndCombo() end

---@param label string 
---@param currentItem integer 
---@param items {[integer]: string} A table of strings. Must be a contiguous string array, anything else will be ignored.
---@param heightInItems integer? Optional max items to show. Defaults to -1
---@return integer currentItem
---@return boolean visible
function ImGui.ListBox(label, currentItem, items, heightInItems) end

---@param label string 
---@param size Vector2? Optional listbox size
---@return boolean visible
function ImGui.BeginListBox(label, size) end

function ImGui.EndListBox() end

---@param label string 
---@param selected boolean 
---@param flags integer? Optional [ImGuiSelectableFlags](lua://ImGuiSelectableFlags)
---@param size Vector2? Optional selectable size
---@return boolean clicked
function ImGui.Selectable(label, selected, flags, size) end

---@param label string 
---@param selected boolean 
---@return boolean selected
---@return boolean clicked
function ImGui.MenuItem(label, selected) end

---@param label string 
---@param v integer 
---@param vMin integer Minimum value
---@param vMax integer Maximum value
---@return integer v
---@return boolean changed
function ImGui.SliderInt(label, v, vMin, vMax) end

---@param label string 
---@param v integer 
---@param vMin integer Minimum value
---@param vMax integer Maximum value
---@param fmt string format string
---@param flags integer? Optional [ImGuiSliderFlags](lua://ImGuiSliderFlags)
---@return integer v
---@return boolean changed
function ImGui.SliderInt(label, v, vMin, vMax, fmt, flags) end

---@param label string 
---@param v number 
---@param vMin number Minimum value
---@param vMax number Maximum value
---@return number v
---@return boolean changed
function ImGui.SliderFloat(label, v, vMin, vMax) end

---@param label string 
---@param v number 
---@param vMin number Minimum value
---@param vMax number Maximum value
---@param fmt string format string
---@param flags integer? Optional [ImGuiSliderFlags](lua://ImGuiSliderFlags)
---@return number v
---@return boolean changed
function ImGui.SliderFloat(label, v, vMin, vMax, fmt, flags) end

---@param label string 
---@param v integer 
---@return integer v
---@return boolean changed
function ImGui.InputInt(label, v) end

---@param label string 
---@param v integer 
---@param step integer step
---@param stepFast integer fast step
---@param flags integer? Optional [ImGuiInputTextFlags](lua://ImGuiInputTextFlags)
---@return integer v
---@return boolean changed
function ImGui.InputInt(label, v, step, stepFast, flags) end

---@param label string 
---@param v number 
---@return number v
---@return boolean changed
function ImGui.InputFloat(label, v) end

---@param label string 
---@param v number 
---@param step number step
---@param stepFast number fast step
---@param fmt string? Optional format string
---@return number v
---@return boolean changed
function ImGui.InputFloat(label, v, step, stepFast, fmt) end

---@param label string 
---@param v number 
---@param step number step
---@param stepFast number fast step
---@param fmt string format string
---@param flags integer? Optional [ImGuiInputTextFlags](lua://ImGuiInputTextFlags)
---@return number v
---@return boolean changed
function ImGui.InputFloat(label, v, step, stepFast, fmt, flags) end

---@param label string 
---@param v number 
---@return number v
---@return boolean changed
function ImGui.InputDouble(label, v) end

---@param label string 
---@param v number 
---@param step number step
---@param stepFast number fast step
---@param fmt string? Optional format string
---@return number v
---@return boolean changed
function ImGui.InputDouble(label, v, step, stepFast, fmt) end

---@param label string 
---@param v number 
---@param step number step
---@param stepFast number fast step
---@param fmt string format string
---@param flags integer? Optional [ImGuiInputTextFlags](lua://ImGuiInputTextFlags)
---@return number v
---@return boolean changed
function ImGui.InputDouble(label, v, step, stepFast, fmt, flags) end

---@param label string 
---@param text string 
---@param bufferSize integer 
---@param flags integer? Optional [ImGuiInputTextFlags](lua://ImGuiInputTextFlags)
---@return string text
---@return boolean changed
function ImGui.InputText(label, text, bufferSize, flags) end

---@param label string 
---@param hint string 
---@param text string 
---@param bufferSize integer 
---@param flags integer? Optional [ImGuiInputTextFlags](lua://ImGuiInputTextFlags)
---@return string text
---@return boolean changed
function ImGui.InputTextWithHint(label, hint, text, bufferSize, flags) end

---@param label string 
---@param text string 
---@param bufferSize integer 
---@return string text
---@return boolean changed
function ImGui.InputTextMultiline(label, text, bufferSize) end

---@param label string 
---@param text string 
---@param bufferSize integer 
---@param flags integer [ImGuiInputTextFlags](lua://ImGuiInputTextFlags)
---@param size Vector2? Optional widget size
---@return string text
---@return boolean changed
function ImGui.InputTextMultiline(label, text, bufferSize, flags, size) end

---@param label string 
---@param color Vector4 
---@return boolean clicked
function ImGui.ColorButton(label, color) end

---@param label string 
---@param color Vector4 
---@param flags integer? Optional [ImGuiColorEditFlags](lua://ImGuiColorEditFlags)
---@return boolean clicked
function ImGui.ColorButton(label, color, flags) end

---@param label string 
---@param color Vector4 
---@param flags integer [ImGuiColorEditFlags](lua://ImGuiColorEditFlags)
---@param size Vector2? Optional picker size
---@return boolean clicked
function ImGui.ColorButton(label, color, flags, size) end

---@param label string 
---@param outCol Vector3 
---@param flags integer? Optional [ImGuiColorEditFlags](lua://ImGuiInputTextFlags)
---@return boolean changed Returns true when the color changes. The vector is mutated in-place.
function ImGui.ColorEdit3(label, outCol, flags) end

---@param label string 
---@param outCol Vector3 
---@param flags integer? Optional [ImGuiColorEditFlags](lua://ImGuiInputTextFlags)
---@return boolean changed Returns true when the color changes. The vector is mutated in-place.
function ImGui.ColorPicker3(label, outCol, flags) end

---@param label string 
---@param outCol Vector4 
---@param flags integer? Optional [ImGuiColorEditFlags](lua://ImGuiInputTextFlags)
---@return boolean changed Returns true when the color changes. The vector is mutated in-place.
function ImGui.ColorEdit4(label, outCol, flags) end

---@param label string 
---@param outCol Vector4 
---@param flags integer? Optional [ImGuiColorEditFlags](lua://ImGuiInputTextFlags)
---@return boolean changed Returns true when the color changes. The vector is mutated in-place.
function ImGui.ColorPicker4(label, outCol, flags) end

-- Disables all ImGui widgets created between this call and EndDisabled
---@param cond boolean? Optional condition
function ImGui.BeginDisabled(cond) end

function ImGui.EndDisabled() end

function ImGui.SameLine() end

---@param offsetX number X position to start at. Defaults to `0`.
---@param spacing number? Optional spacing after the previous item. Defaults to the current item spacing.
function ImGui.SameLine(offsetX, spacing) end

function ImGui.NewLine() end

function ImGui.Spacing() end

function ImGui.Separator() end

---@param flags integer [ImGuiSeparatorFlags](lua://ImGuiSeparatorFlags)
---@param thickness number? Optional separator thickness. Defaults to 1.0
function ImGui.SeparatorEx(flags, thickness) end

---@param text string 
function ImGui.SeparatorText(text) end

---@param indentX number? Optional indentation width. Defaults to the current item spacing.
function ImGui.Indent(indentX) end

---@param indentX number? Optional indentation width. Defaults to the current item spacing.
function ImGui.Unindent(indentX) end

---@param size Vector2 
function ImGui.Dummy(size) end

---@param pos Vector2 
function ImGui.SetCursorPos(pos) end

---@param x number X position relative to the current window.
function ImGui.SetCursorPosX(x) end

---@param y number Y position relative to the current window.
function ImGui.SetCursorPosY(y) end

---@return Vector2 cursorPos
function ImGui.GetCursorPos() end

---@return number x Current X position relative to the current window.
function ImGui.GetCursorPosX() end

---@return number y Current Y position relative to the current window.
function ImGui.GetCursorPosY() end

---@return Vector2 avail Available content region.
function ImGui.GetContentRegionAvail() end

---@return number width
function ImGui.GetWindowWidth() end

---@return number height
function ImGui.GetWindowHeight() end

---@return Vector2 windowSize
function ImGui.GetWindowSize() end

---@return Vector2 windowPos Current window position.
function ImGui.GetWindowPos() end

---@return number frameHeight
function ImGui.GetFrameHeight() end

---@return number frameHeight Frame height with spacing.
function ImGui.GetFrameHeightWithSpacing() end

---@param width number Width of the next item.
function ImGui.SetNextItemWidth(width) end

---@param width number Width of subsequent items.
function ImGui.PushItemWidth(width) end

function ImGui.PopItemWidth() end

---@param text string 
---@param wrapWidth number? 
---@return Vector2 size
function ImGui.CalcTextSize(text, wrapWidth) end

---@param text string 
---@param hideTextAfterDoubleHash boolean 
---@param wrapWidth number? 
---@return Vector2 size
function ImGui.CalcTextSize(text, hideTextAfterDoubleHash, wrapWidth) end

---@param scale number 
function ImGui.GetItemRectMin(scale) end

---@return Vector2 rectMin
function ImGui.GetItemRectMin() end

---@return Vector2 rectMax
function ImGui.GetItemRectMax() end

---@return Vector2 size
function ImGui.GetItemRectSize() end

---@return integer itemID
function ImGui.GetItemID() end

---@param flags integer? Optional [ImGuiHoveredFlags](ImGuiHoveredFlags)
---@return boolean 
function ImGui.IsItemHovered(flags) end

---@return boolean 
function ImGui.IsItemActive() end

---@return boolean 
function ImGui.IsItemFocused() end

---@return boolean 
function ImGui.IsItemVisible() end

---@return boolean 
function ImGui.IsItemEdited() end

---@return boolean 
function ImGui.IsItemActivated() end

---@return boolean 
function ImGui.IsItemDeactivated() end

---@return boolean 
function ImGui.IsItemDeactivatedAfterEdit() end

---@return boolean 
function ImGui.IsItemToggledOpen() end

---@return boolean 
function ImGui.IsAnyItemHovered() end

---@return boolean 
function ImGui.IsAnyItemActive() end

---@return boolean 
function ImGui.IsAnyItemFocused() end

---@param mouseBtn integer? 0: "left" | 1: "right" | 2: "middle"
---@return boolean 
function ImGui.IsItemClicked(mouseBtn) end

---@return boolean 
function ImGui.IsAnyItemHovered() end

---@param styleVar integer [ImGuiStyleVar](lua://ImGuiStyleVar) index
---@param v number style value
function ImGui.PushStyleVar(styleVar, v) end

---@param styleVar integer [ImGuiStyleVar](lua://ImGuiStyleVar) index
---@param v Vector2 
function ImGui.PushStyleVar(styleVar, v) end

---@param count integer? Count of pushed style variables to pop. Defaults to 1; Must match the number of pushed style vars.
function ImGui.PopStyleVar(count) end

---@param colIdx integer [ImGuiCol](lua://ImGuiCol) index
---@param color Vector4 
function ImGui.PushStyleColor(colIdx, color) end

---@param count integer? Count of pushed style colors to pop. Defaults to 1; Must match the number of pushed style cols.
function ImGui.PopStyleColor(count) end

---@param cursorIdx integer [ImGuiMouseCursor](lua://ImGuiMouseCursor) index
function ImGui.SetMouseCursor(cursorIdx) end

-- Draws a toggle widget that can be used instead of a regular ImGui checkbox.
---@param label string Tooltip text
---@param v boolean Tooltip text
function ImGui.Toggle(label, v) end

-- Draws a toggle widget that can be used instead of a regular ImGui checkbox.
---@param label string 
---@param v boolean 
---@param size Vector2 
---@return boolean value
---@return boolean clicked
function ImGui.Toggle(label, v, size) end

---@param text string 
---@param ... any Optional format args
function ImGui.SetTooltip(text, ...) end

function ImGui.BeginTooltip() end

function ImGui.EndTooltip() end

---@return ImDrawList 
function ImGui.GetWindowDrawList() end

---@return ImDrawList 
function ImGui.GetBackgroundDrawList() end

---@return ImDrawList 
function ImGui.GetForegroundDrawList() end

---@return number 
function ImGui.GetTime() end

---@return integer 
function ImGui.GetFrameCount() end

---@return integer 
function ImGui.GetFontSize() end

---@param col integer Packed 32bit integer
---@return Vector4 rgba Normalised RGBA
function ImGui.ColorConvertU32ToFloat4(col) end

---@param col Vector4 Normalised RGBA
---@return integer u32 Packed 32bit integer
function ImGui.ColorConvertFloat4ToU32(col) end

---@param h number 
---@param s number 
---@param v number 
---@return number r
---@return number g
---@return number b
function ImGui.ColorConvertHSVtoRGB(h, s, v) end

---@param r number 
---@param g number 
---@param b number 
---@return number h
---@return number s
---@return number v
function ImGui.ColorConvertRGBtoHSV(r, g, b) end
