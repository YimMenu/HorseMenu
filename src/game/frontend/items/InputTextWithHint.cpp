#include "Items.hpp"
#include "misc/cpp/imgui_stdlib.h"

namespace YimMenu
{
	//Need to modify imgui to accept strings instead of char*
	InputTextWithHint::InputTextWithHint(std::string label, std::string hint, std::string* buf, ImGuiInputTextFlags_ flag , std::function<void()> cb) :
	    m_Id(label),
	    m_Hint(hint),
		m_Buf(buf),
	    m_Flag(flag),
	    m_Callback(cb)
	{
	}

	void InputTextWithHint::Draw()
	{
		ImGui::InputTextWithHint(m_Id.data(), m_Hint.data(), m_Buf, m_Flag);
		if (m_Callback != nullptr)
		{
			if (ImGui::IsItemDeactivatedAfterEdit())
			{
				m_Callback();
			}
		}

		if (ImGui::IsItemActive())
			;//TODO add block controls
		
	}
}