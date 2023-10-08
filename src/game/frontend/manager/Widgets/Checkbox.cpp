#include "Widgets.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/frontend/imguiwidgets/toggle/imgui_toggle.hpp"

namespace YimMenu
{
	Checkbox::Checkbox(const std::string_view& name, bool* value, std::function<void()> onClick, const std::string_view& information) :
	    m_Name(name),
	    m_Information(information),
	    m_OnClick(onClick),
	    m_Value(value)
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