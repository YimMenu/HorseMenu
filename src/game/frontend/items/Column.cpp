#include "Items.hpp"

namespace YimMenu
{
	void Column::Draw()
	{
		ImGui::Columns(m_Columns);
		for (auto& item : m_Items)
			item->Draw();
	}

	void Column::AddColumnOffset(const int column, const int offset)
	{
		AddItem(std::make_shared<ImGuiItem>([column, offset] {
			ImGui::SetColumnOffset(column, offset);
		}));
	}

	void Column::AddNextColumn()
	{
		AddItem(std::make_shared<ImGuiItem>([] {
			ImGui::NextColumn();
		}));
	}
}