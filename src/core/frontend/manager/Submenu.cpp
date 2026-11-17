#include "Submenu.hpp"

namespace Terminus
{
	void Submenu::SetActiveCategory(const std::shared_ptr<Category> category)
	{
		if (m_ActiveCategory == category)
			return;

		m_ActiveCategory = category;
	}

	void Submenu::AddCategory(std::shared_ptr<Category>&& category)
	{
		if (!m_ActiveCategory)
			m_ActiveCategory = category;

		m_Categories.push_back(std::move(category));
	}

	void Submenu::DrawCategorySelectors()
	{
		if (m_Categories.size() == 1)
		{
			SetActiveCategory(m_Categories.back());
			return;
		}

		for (auto& category : m_Categories)
		{
			if (category)
			{
				auto& style = ImGui::GetStyle();
				auto color  = style.Colors[ImGuiCol_Button];
				color.w -= 0.5;

				auto active = category == GetActiveCategory();

				if (!active)
					ImGui::PushStyleColor(ImGuiCol_Button, color);

				if (ImGui::Button(category->m_Name.data(), ImVec2(category->GetLength(), 35)))
				{
					SetActiveCategory(category);
				}

				if (!active)
					ImGui::PopStyleColor();

				if (m_Categories.back() != category)
					ImGui::SameLine();
			}
		}
	}

	void Submenu::Draw()
	{
		if (m_ActiveCategory)
		{
			m_ActiveCategory->Draw();
		}
	}
}