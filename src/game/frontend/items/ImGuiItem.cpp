#include "Items.hpp"
#include "game/backend/FiberPool.hpp"

namespace Terminus
{
	ImGuiItem::ImGuiItem(std::function<void()> callback) :
	    m_Callback(callback)
	{
	}

	void ImGuiItem::Draw()
	{
		m_Callback();
	}
}