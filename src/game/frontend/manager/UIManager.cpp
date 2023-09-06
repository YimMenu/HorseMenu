#include "UIManager.hpp"

namespace YimMenu
{
	void Submenu::DrawMiniSubmenuSelectors()
	{
		for (auto& minisubmenu : m_MiniSubMenus)
		{
			if (minisubmenu)
			{
				MiniSubmenuOption(minisubmenu);

				if (m_MiniSubMenus.back() != minisubmenu)
					ImGui::SameLine();
			}
		}
	}

	void Submenu::SetActiveMiniSubmenu(const std::shared_ptr<MiniSubmenu> menu)
	{
		m_ActiveMiniSubmenu = menu;
	}

	void Submenu::Draw()
	{
		if (m_ActiveMiniSubmenu)
		{
			m_ActiveMiniSubmenu->Draw();
		}
	}

	void Submenu::MiniSubmenuOption(const std::shared_ptr<MiniSubmenu> Menu)
	{
		auto& style = ImGui::GetStyle();

		auto button_color = style.Colors[ImGuiCol_Button];

		button_color.w += 50;

		auto menu = Menu.get();

		if (!menu)
			return;

		if (Menu == GetActiveMiniSubmenu())
			ImGui::PushStyleColor(ImGuiCol_Button, button_color);

		if (ImGui::Button(menu->m_MiniSubmenuName.data(), ImVec2(75, 35)))
		{
			Menu->m_MiniSubmenuName = menu->m_MiniSubmenuName;
			SetActiveMiniSubmenu(Menu);
		}
		if (Menu == GetActiveMiniSubmenu())
			ImGui::PopStyleColor();
	}

	void SubmenuHandler::SetActiveSubmenu(const std::shared_ptr<Submenu> submenu)
	{
		m_ActiveSubmenu = submenu;
	}

	void SubmenuHandler::RenderActiveSubmenu()
	{
		if (m_ActiveSubmenu)
		{
			m_ActiveSubmenu->Draw();
		}
	}

	void SubmenuHandler::RenderSubmenuCategories()
	{
		if (m_ActiveSubmenu)
		{
			m_ActiveSubmenu->DrawMiniSubmenuSelectors();
		}
	}

	void SubmenuHandler::UpdateActiveSubmenu()
	{
		if (m_ActiveSubmenu && GUI::IsOpen())
		{
			m_ActiveSubmenu->Update();
		}
	}

	void SubmenuHandler::UpdateOnceActiveSubmenu()
	{
		if (m_ActiveSubmenu)
		{
			m_ActiveSubmenu->UpdateOnce();
		}
	}

	std::shared_ptr<Submenu> SubmenuHandler::GetActiveSubmenu()
	{
		if (m_ActiveSubmenu)
		{
			return m_ActiveSubmenu;
		}

		return nullptr;
	}

	std::string SubmenuHandler::GetActiveSubmenuName() const
	{
		if (m_ActiveSubmenu)
		{
			return m_ActiveSubmenu->m_SubmenuName;
		}

		return "NULLSUB";
	}

	std::string SubmenuHandler::GetActiveMiniSubMenuName() const
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

	std::shared_ptr<MiniSubmenu> SubmenuHandler::GetActiveSubmenuDefaultMiniSubmenu()
	{
		if (m_ActiveSubmenu)
		{
			return m_ActiveSubmenu.get()->m_DefaultMiniSubmenu;
		}

		return nullptr;
	}

	std::shared_ptr<MiniSubmenu> SubmenuHandler::GetActiveSubmenuActiveMiniSubmenu()
	{
		if (m_ActiveSubmenu)
		{
			return m_ActiveSubmenu.get()->GetActiveMiniSubmenu();
		}

		return nullptr;
	}

	void SubmenuHandler::SubmenuOption(const std::string_view& SubmenuLogo, const std::string_view& SubmenuName, const std::shared_ptr<Submenu> Submenu_)
	{
		if (ImGui::Selectable(SubmenuName.data(), (Submenu_ == m_ActiveSubmenu)))
		{
			SetActiveSubmenu(Submenu_);
			Submenu_->m_SubmenuName = SubmenuName;
			UpdateOnceActiveSubmenu();
		}
	}
}