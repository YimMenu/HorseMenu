#include "Widgets.hpp"
#include "game/backend/FiberPool.hpp"

namespace YimMenu
{
	Button::Button(const std::string_view& Name, std::function<void()> OnClick, const ImVec2 Size, const std::string_view& Information) :
	    m_Name(Name),
	    m_Information(Information),
	    m_OnClick(OnClick),
	    m_Size(Size)
	{
	}

	void Button::Draw()
	{
		if (ImGui::Button(m_Name.data(), m_Size))
		{
			if (m_OnClick != nullptr)
			{
				FiberPool::Push([this] {
					m_OnClick();
				});
			}
		}
	}
}