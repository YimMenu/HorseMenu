<!-- markdownlint-disable -->

# ImGuiInputTextFlags

## Fields

| Name | Type | Description |
| --- | --- | --- |
| `None` | `integer` |  |
| `CharsDecimal` | `integer` | Allow 0123456789.+-* / |
| `CharsHexadecimal` | `integer` | Allow 0123456789ABCDEFabcdef |
| `CharsScientific` | `integer` | Allow 0123456789.+-* /eE (Scientific notation input) |
| `CharsUppercase` | `integer` | Turn a..z into A..Z |
| `CharsNoBlank` | `integer` | Filter out spaces, tabs |
| `AllowTabInput` | `integer` | Pressing TAB input a '\t' character into the text field |
| `EnterReturnsTrue` | `integer` | Return 'true' when Enter is pressed (as opposed to every time the value was modified). Consider using IsItemDeactivatedAfterEdit() instead! |
| `EscapeClearsAll` | `integer` | Escape key clears content if not empty, and deactivate otherwise (contrast to default behavior of Escape to revert) |
| `CtrlEnterForNewLine` | `integer` | In multi-line mode, validate with Enter, add new line with Ctrl+Enter (default is opposite: validate with Ctrl+Enter, add line with Enter). |
| `ReadOnly` | `integer` | Read-only mode |
| `Password` | `integer` | Password mode, display all characters as '*', disable copy |
| `AlwaysOverwrite` | `integer` | Overwrite mode |
| `AutoSelectAll` | `integer` | Select entire text when first taking mouse focus |
| `ParseEmptyRefVal` | `integer` | InputFloat(), InputInt(), InputScalar() etc. only: parse empty string as zero value. |
| `DisplayEmptyRefVal` | `integer` | InputFloat(), InputInt(), InputScalar() etc. only: when value is zero, do not display it. Generally used with ImGuiInputTextFlags_ParseEmptyRefVal. |
| `NoHorizontalScroll` | `integer` | Disable following the cursor horizontally |
| `NoUndoRedo` | `integer` | Disable undo/redo. Note that input text owns the text data while active, if you want to provide your own undo/redo stack you need e.g. to call ClearActiveID(). |
| `ElideLeft` | `integer` | When text doesn't fit, elide left side to ensure right side stays visible. Useful for path/filenames. Single-line only! |
| `CallbackCompletion` | `integer` | Callback on pressing TAB (for completion handling) |
| `CallbackHistory` | `integer` | Callback on pressing Up/Down arrows (for history handling) |
| `CallbackAlways` | `integer` | Callback on each iteration. User code may query cursor position, modify text buffer. |
| `CallbackCharFilter` | `integer` | Callback on character inputs to replace or discard them. Modify 'EventChar' to replace or discard, or return 1 in callback to discard. |
| `CallbackResize` | `integer` | Callback on buffer capacity changes request (beyond 'buf_size' parameter value), allowing the string to grow. Notify when the string wants to be resized (for string types which hold a cache of their Size). You will be provided a new BufSize in the callback and NEED to honor it. (see misc/cpp/imgui_stdlib.h for an example of using this) |
| `CallbackEdit` | `integer` | Callback on any edit. Note that InputText() already returns true on edit + you can always use IsItemEdited(). The callback is useful to manipulate the underlying buffer while focus is active. |
| `WordWrap` | `integer` | InputTextMultine(): word-wrap lines that are too long. |
