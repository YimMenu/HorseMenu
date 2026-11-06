<!-- markdownlint-disable -->

# ImGuiSliderFlags

## Fields

| Name | Type | Description |
| --- | --- | --- |
| `None` | `integer` |  |
| `Logarithmic` | `integer` | Make the widget logarithmic (linear otherwise). Consider using ImGuiSliderFlags_NoRoundToFormat with this if using a format-string with small amount of digits. |
| `NoRoundToFormat` | `integer` | Disable rounding underlying value to match precision of the display format string (e.g. %.3f values are rounded to those 3 digits). |
| `NoInput` | `integer` | Disable CTRL+Click or Enter key allowing to input text directly into the widget. |
| `WrapAround` | `integer` | Enable wrapping around from max to min and from min to max. Only supported by DragXXX() functions for now. |
| `ClampOnInput` | `integer` | Clamp value to min/max bounds when input manually with CTRL+Click. By default CTRL+Click allows going out of bounds. |
| `ClampZeroRange` | `integer` | Clamp even if min==max==0.0f. Otherwise due to legacy reason DragXXX functions don't clamp with those values. When your clamping limits are dynamic you almost always want to use it. |
| `NoSpeedTweaks` | `integer` | Disable keyboard modifiers altering tweak speed. Useful if you want to alter tweak speed yourself based on your own logic. |
| `AlwaysClamp` | `integer` |  |
