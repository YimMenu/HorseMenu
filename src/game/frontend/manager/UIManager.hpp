#pragma once
#include "game/frontend/GUI.hpp"

namespace YimMenu
{
	class Option
	{
	public:
		virtual void Draw() = 0;
	};

	class MiniSubmenu
	{
	public:
		MiniSubmenu(std::string_view name, std::function<void()> content) :
			m_MiniSubmenuName(name),
			m_Content(content)
		{
			//TODO: Register in a global map to make it searchable
		}

		void Draw()
		{
			if (m_Content)
				m_Content();
		}

	private:
		std::function<void()> m_Content;

	public:
		std::string m_MiniSubmenuName;
	};

	class Submenu
	{
	public:
		virtual void LoadSubmenus() = 0;
		virtual void Update()     = 0;
		virtual void UpdateOnce() = 0;

		std::shared_ptr<MiniSubmenu> GetActiveMiniSubmenu() const
		{
			return m_ActiveMiniSubmenu;
		}

		void DrawMiniSubmenuSelectors();
		void SetActiveMiniSubmenu(const std::shared_ptr<MiniSubmenu> menu);
		void MiniSubmenuOption(const std::shared_ptr<MiniSubmenu> Menu);
		void Draw();

	private:
		std::shared_ptr<MiniSubmenu> m_ActiveMiniSubmenu;

	public:
		std::vector<std::shared_ptr<MiniSubmenu>> m_MiniSubMenus;
		std::shared_ptr<MiniSubmenu> m_DefaultMiniSubmenu;
		std::string m_SubmenuName;
	};

	class SubmenuHandler
	{
	public:
		void SetActiveSubmenu(const std::shared_ptr<Submenu> submenu);
		void RenderActiveSubmenu();
		void RenderSubmenuCategories();
		void UpdateActiveSubmenu();
		void UpdateOnceActiveSubmenu();
		std::shared_ptr<Submenu> GetActiveSubmenu();
		std::string GetActiveSubmenuName() const;
		std::string GetActiveMiniSubMenuName() const;
		std::shared_ptr<MiniSubmenu> GetActiveSubmenuDefaultMiniSubmenu();
		std::shared_ptr<MiniSubmenu> GetActiveSubmenuActiveMiniSubmenu();
		void SubmenuOption(const std::string_view& SubmenuLogo, const std::string_view& SubmenuName, const std::shared_ptr<Submenu> Submenu_);

	private:
		std::shared_ptr<Submenu> m_ActiveSubmenu;
	};
	inline SubmenuHandler g_SubmenuHandler;
}
