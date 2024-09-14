#include "Category.hpp"

namespace YimMenu
{
	void Category::Draw()
	{
		for (auto& item : m_Items)
			item->Draw();
	}

	int Category::GetLength()
	{
		if (m_Length.has_value())
			return m_Length.value();
		
		m_Length = static_cast<int>(std::max(ImGui::CalcTextSize(m_Name.c_str()).x + 25.0f, 75.0f));
		return m_Length.value();
	}
}