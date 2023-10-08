#pragma once
#include "game/frontend/GUI.hpp"
#include "game/frontend/menu/Menu.hpp"

namespace YimMenu
{
	class NextColumn
	{
	public:
		NextColumn()
		{
			ImGui::NextColumn();
		}
	};

	class ColumnOffset
	{
	public:
		ColumnOffset(int column, int offset) :
		    m_Column(column),
		    m_Offset(offset)
		{
			ImGui::SetColumnOffset(m_Column, m_Offset);
		}
	 
	private:
		int m_Column;
		int m_Offset;
	};

	class Column
	{
	public:
		Column(std::function<void()> content, int amount) :
		    m_Content(content),
		    m_Amount(amount)
		{
			//TODO: Register in a global map to make it searchable
		}

		void Draw()
		{
			ImGui::Columns(m_Amount, 0);

			if (m_Content)
				m_Content();
		}

	private:
		std::function<void()> m_Content;
		int m_Amount;
	};

	class Child
	{
	public:
		Child(std::string_view name, std::function<void()> content, ImVec2 size = {0, 0}) :
		    m_ChildName(name),
		    m_Content(content),
		    m_Size(size)
		{
			//TODO: Register in a global map to make it searchable
		}

		void Draw()
		{
			if (ImGui::BeginChild(m_ChildName.insert(0, "##").c_str(), m_Size, true))
			{
				ImGui::PushFont(Menu::Font::m_ChildTitleFont);
				ImGui::Text(m_ChildName.erase(0, 2).c_str());
				ImGui::PopFont();
				ImGui::Separator();
				ImGui::Spacing();

				if (m_Content)
					m_Content();
	
			}
			ImGui::EndChild();
		}

	private:
		std::function<void()> m_Content;
		ImVec2 m_Size;

	public:
		std::string m_ChildName;
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
		std::vector<std::shared_ptr<MiniSubmenu>> m_MiniSubmenus;
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
