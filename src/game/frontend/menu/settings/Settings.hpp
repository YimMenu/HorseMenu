#pragma once
#include "game/frontend/manager/UIManager.hpp"

namespace YimMenu
{
	class Settings : public Submenu
	{
	public:
		void LoadSubmenus() override;
		void Update() override;
		void UpdateOnce() override;
	};
}