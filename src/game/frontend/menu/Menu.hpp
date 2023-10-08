#pragma once
#include "game/frontend/GUI.hpp"

namespace YimMenu::Menu
{
	extern void Init();
	extern void Style();
	extern void Fonts();

	namespace Font
	{
		inline ImFont* m_DefaultFont   = nullptr;
		inline float m_DefaultFontSize = 18.0f;

	    inline ImFont* m_OptionsFont   = nullptr;
		inline float m_OptionsFontSize = 15.0f;

		inline ImFont* m_ChildTitleFont   = nullptr;
		inline float m_ChildTitleFontSize   = 14.5f;
	}
}