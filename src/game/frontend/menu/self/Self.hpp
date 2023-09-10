#pragma once
#include "game/frontend/manager/UIManager.hpp"

namespace YimMenu::Submenus
{
	class Self : public Submenu
	{
	public:
		void LoadSubmenus() override;
		void Update() override;
		void UpdateOnce() override;
	};
}