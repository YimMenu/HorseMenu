#include "Category.hpp"

namespace YimMenu
{
	void Category::Draw()
	{
		for (auto& item : m_Items)
			item->Draw();
	}
}