#pragma once
#include "game/frontend/GUI.hpp"

namespace YimMenu
{
	class Option
	{
	public:
		virtual void Draw() = 0;
	};

	class OptionBox : public Option
	{
	public:
		OptionBox(const std::string_view& Name, const ImVec2& Size) :
		    m_Name(Name),
		    m_Size(Size){};

		void AddOption(std::shared_ptr<Option> Option)
		{
			m_Options.push_back(std::move(Option));
		}

		void Draw() override
		{
			ImGui::Text(m_Name.data());
			if (ImGui::BeginChild(m_Name.data(), ImVec2(0,0), true))
			{
				for (const auto& option : m_Options)
				{
					if (option)
					{
						option->Draw();
					}
				}
				ImGui::EndChild();
			}
		}

	private:
		std::string_view m_Name;
		ImVec2 m_Size;

		std::vector<std::shared_ptr<Option>> m_Options;
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
		virtual void LoadSubmenus()      = 0;
		virtual void DrawMiniSubmenuSelectors() = 0;
		virtual void Update()            = 0;
		virtual void UpdateOnce()        = 0;

		void SetActiveMiniSubmenu(const std::shared_ptr<MiniSubmenu> menu)
		{
			m_ActiveMiniSubmenu = menu;
		}

		std::shared_ptr<MiniSubmenu> GetActiveMiniSubmenu() const
		{
			return m_ActiveMiniSubmenu;
		}

		void MiniSubmenuOption(const std::shared_ptr<MiniSubmenu> Menu)
		{
			auto& style = ImGui::GetStyle();

			auto button_color = style.Colors[ImGuiCol_Button];

			button_color.w += 50;

			auto menu = Menu.get();

			if (!menu)
				return;

			if (Menu == GetActiveMiniSubmenu())
				ImGui::PushStyleColor(ImGuiCol_Button, button_color);

			if (ImGui::Button(menu->m_MiniSubmenuName.data()))
			{
				Menu->m_MiniSubmenuName = menu->m_MiniSubmenuName;
				SetActiveMiniSubmenu(Menu);
			}
			if (Menu == GetActiveMiniSubmenu())
				ImGui::PopStyleColor();
		}

		void Draw()
		{
			if (m_ActiveMiniSubmenu)
			{
				m_ActiveMiniSubmenu->Draw();
			}
		}
	private:
		std::shared_ptr<MiniSubmenu> m_ActiveMiniSubmenu;
		std::vector<std::shared_ptr<Option>> m_MiniSubmenuSelectors;

	public:
		std::string m_SubmenuName;
	};

	class SubmenuHandler
	{
	public:
		void SetActiveSubmenu(const std::shared_ptr<Submenu> submenu)
		{
			m_ActiveSubmenu = submenu;
		}

		void RenderActiveSubmenu()
		{
			if (m_ActiveSubmenu)
			{
				m_ActiveSubmenu->Draw();
			}
		}

		void RenderSubmenuCategories()
		{
			if (m_ActiveSubmenu)
			{
				m_ActiveSubmenu->DrawMiniSubmenuSelectors();
			}
		}

		void UpdateActiveSubmenu()
		{
			if (m_ActiveSubmenu && GUI::IsOpen())
			{
				m_ActiveSubmenu->Update();
			}
		}

		void UpdateOnceActiveSubmenu()
		{
			if (m_ActiveSubmenu)
			{
				m_ActiveSubmenu->UpdateOnce();
			}
		}

		std::string GetActiveSubmenuName() const
		{
			if (m_ActiveSubmenu)
			{
				return m_ActiveSubmenu->m_SubmenuName;
			
			}
			return "NULLSUB";
		}

		std::string GetActiveMiniSubMenuName() const
		{
			if (m_ActiveSubmenu)
			{
				if (m_ActiveSubmenu->GetActiveMiniSubmenu())
				{
					return m_ActiveSubmenu->GetActiveMiniSubmenu()->m_MiniSubmenuName;
				}
			}
			return "NULLSUB";
		}

		void SubmenuOption(const std::string_view& SubmenuLogo, const std::string_view& SubmenuName, const std::shared_ptr<Submenu> Submenu_)
		{
			if (ImGui::Selectable(SubmenuName.data(), (Submenu_ == m_ActiveSubmenu)))
			{
				SetActiveSubmenu(Submenu_);
				Submenu_->m_SubmenuName = SubmenuName;
				UpdateOnceActiveSubmenu();
			}
		}

	private:
		std::shared_ptr<Submenu> m_ActiveSubmenu;
	};
	inline SubmenuHandler g_SubmenuHandler;
}
