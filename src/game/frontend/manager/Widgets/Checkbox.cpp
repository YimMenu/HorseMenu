#include "Widgets.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/frontend/imguiwidgets/toggle/imgui_toggle.hpp"

namespace YimMenu
{
	Checkbox::Checkbox(const std::string_view& Name, bool* Value, std::function<void()> OnClick, const std::string_view& Information) :
	    m_Name(Name),
	    m_Information(Information),
	    m_OnClick(OnClick),
	    m_Value(Value)
	{
	}

	void Checkbox::Draw()
	{
		if (ImGui::Toggle(m_Name.data(), m_Value))
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