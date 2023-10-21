#include "Items.hpp"
#include "game/backend/FiberPool.hpp"

namespace YimMenu
{
	Button::Button(const std::string_view& name, std::function<void()> onClick, const ImVec2 size, const std::string_view& information) :
	    m_Name(name),
	    m_Information(information),
	    m_OnClick(onClick),
	    m_Size(size)
	{
	}

	void Button::Draw()
	{
		if (ImGui::Button(m_Name.data(), m_Size))
		{
			if (m_OnClick != nullptr)
			{
				FiberPool::Push([&] {
					m_OnClick();
				});
			}
		}
	}
}