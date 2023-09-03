#pragma once
#include "game/frontend/manager/UIManager.hpp"

namespace YimMenu
{
	class Self : public Submenu
	{
	public:
		void LoadSubmenus() override;
		void DrawMiniSubmenuSelectors() override;
		void Update() override;
		void UpdateOnce() override;

	private:
		std::vector<std::shared_ptr<MiniSubmenu>> m_MiniSubMenus;
	};
}