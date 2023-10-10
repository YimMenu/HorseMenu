#pragma once
#include "game/frontend/GUI.hpp"

namespace YimMenu::Menu
{
	extern void Init();
	extern void SetupStyle();
	extern void SetupFonts();

	namespace Font
	{
		inline ImFont* g_DefaultFont   = nullptr;
		inline float g_DefaultFontSize = 18.0f;

	    inline ImFont* g_OptionsFont   = nullptr;
		inline float g_OptionsFontSize = 15.0f;

		inline ImFont* g_ChildTitleFont   = nullptr;
		inline float g_ChildTitleFontSize   = 14.5f;
	}
}