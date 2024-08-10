#include "Items.hpp"
#include "game/features/Features.hpp"
#include "misc/cpp/imgui_stdlib.h"


namespace YimMenu
{
	InputTextWithHint::InputTextWithHint(std::string label, std::string hint, std::string* buf, int flags, std::function<void()> cb, ImGuiInputTextCallback inputCallback) :
	    m_Id(label),
	    m_Hint(hint),
	    m_Buf(buf),
	    m_Flags(flags),
	    m_Callback(cb),
	    m_ImGuiInputTextCallback(inputCallback)
	{
	}

	void InputTextWithHint::Draw()
	{
		if (ImGui::InputTextWithHint(m_Id.data(), m_Hint.data(), m_Buf, m_Flags, m_ImGuiInputTextCallback))
			;
		{
			if (m_Callback != nullptr)
			{
				m_Callback();
			}
		}
	}
}