#pragma once
#include "game/frontend/GUI.hpp"

namespace YimMenu::Menu
{
	extern void Init();
	extern void SetupStyle();
	extern void SetupFonts();

	namespace Font
	{
		inline ImFont* sm_DefaultFont   = nullptr;
		inline float sm_DefaultFontSize = 18.0f;

	    inline ImFont* sm_OptionsFont   = nullptr;
		inline float sm_OptionsFontSize = 15.0f;

		inline ImFont* sm_ChildTitleFont   = nullptr;
		inline float sm_ChildTitleFontSize   = 14.5f;
	}
}