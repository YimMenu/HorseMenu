#pragma once
#include "core/commands/ColorCommand.hpp"

namespace YimMenu::ColorCustomization
{
	extern ColorCommand _MenuWindowBg;
	extern ColorCommand _MenuChildBg;
	extern ColorCommand _MenuTextColor;
	extern ColorCommand _MenuButtonColor;
	extern ColorCommand _MenuButtonHovered;
	extern ColorCommand _MenuButtonActive;
	extern ColorCommand _MenuBorderColor;

	void ApplyMenuColors();
	void ResetToDefaultColors();
	void DrawColorSettings();
}