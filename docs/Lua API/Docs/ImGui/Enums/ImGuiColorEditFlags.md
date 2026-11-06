<!-- markdownlint-disable -->

# ImGuiColorEditFlags

## Fields

| Name | Type | Description |
| --- | --- | --- |
| `None` | `integer` |  |
| `NoAlpha` | `integer` | ColorEdit, ColorPicker, ColorButton: ignore Alpha component (will only read 3 components from the input pointer). |
| `NoPicker` | `integer` | ColorEdit: disable picker when clicking on color square. |
| `NoOptions` | `integer` | ColorEdit: disable toggling options menu when right-clicking on inputs/small preview. |
| `NoSmallPreview` | `integer` | ColorEdit, ColorPicker: disable color square preview next to the inputs. (e.g. to show only the inputs) |
| `NoInputs` | `integer` | ColorEdit, ColorPicker: disable inputs sliders/text widgets (e.g. to show only the small preview color square). |
| `NoTooltip` | `integer` | ColorEdit, ColorPicker, ColorButton: disable tooltip when hovering the preview. |
| `NoLabel` | `integer` | ColorEdit, ColorPicker: disable display of inline text label (the label is still forwarded to the tooltip and picker). |
| `NoSidePreview` | `integer` | ColorPicker: disable bigger color preview on right side of the picker, use small color square preview instead. |
| `NoDragDrop` | `integer` | ColorEdit: disable drag and drop target. ColorButton: disable drag and drop source. |
| `NoBorder` | `integer` | ColorButton: disable border (which is enforced by default) |
| `AlphaOpaque` | `integer` | ColorEdit, ColorPicker, ColorButton: disable alpha in the preview,. Contrary to _NoAlpha it may still be edited when calling ColorEdit4()/ColorPicker4(). For ColorButton() this does the same as _NoAlpha. |
| `AlphaNoBg` | `integer` | ColorEdit, ColorPicker, ColorButton: disable rendering a checkerboard background behind transparent color. |
| `AlphaPreviewHalf` | `integer` | ColorEdit, ColorPicker, ColorButton: display half opaque / half transparent preview. |
| `AlphaBar` | `integer` | ColorEdit, ColorPicker: show vertical alpha bar/gradient in picker. |
| `HDR` | `integer` | (WIP) ColorEdit: Currently only disable 0.0f..1.0f limits in RGBA edition (note: you probably want to use ImGuiColorEditFlags_Float flag as well). |
| `DisplayRGB` | `integer` | ColorEdit: override _display_ type among RGB/HSV/Hex. ColorPicker: select any combination using one or more of RGB/HSV/Hex. |
| `DisplayHSV` | `integer` | " |
| `DisplayHex` | `integer` | " |
| `Uint8` | `integer` | ColorEdit, ColorPicker, ColorButton: _display_ values formatted as 0..255. |
| `Float` | `integer` | ColorEdit, ColorPicker, ColorButton: _display_ values formatted as 0.0f..1.0f floats instead of 0..255 integers. No round-trip of value via integers. |
| `PickerHueBar` | `integer` | ColorPicker: bar for Hue, rectangle for Sat/Value. |
| `PickerHueWheel` | `integer` | ColorPicker: wheel for Hue, triangle for Sat/Value. |
| `InputRGB` | `integer` | ColorEdit, ColorPicker: input and output data in RGB format. |
| `InputHSV` | `integer` | ColorEdit, ColorPicker: input and output data in HSV format. |
| `DefaultOptions_` | `integer` |  |
| `AlphaMask_` | `integer` |  |
| `DisplayMask_` | `integer` |  |
| `DataTypeMask_` | `integer` |  |
| `PickerMask_` | `integer` |  |
| `InputMask_` | `integer` |  |
