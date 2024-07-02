#pragma once
#include "core/frontend/manager/UIManager.hpp"

namespace YimMenu::Submenus
{
	class Self : public Submenu
	{
	public:
		Self();
	};
}

namespace YimMenu::SelfStorage
{
	/* WHISTLE MODIFIERS */
	inline float pitch;
	inline float clarity;
	inline float shape;
}