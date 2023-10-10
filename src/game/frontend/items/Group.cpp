#include "Items.hpp"
#include "core/commands/Command.hpp"
#include "core/commands/Commands.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/frontend/Menu.hpp"

namespace YimMenu
{
	Group::Group(const std::string& name, ImVec2 size) :
	    m_Name(name),
	    m_Size(size)
	{
	}

	void Group::Draw()
	{
		if (ImGui::BeginChild(m_Name.insert(0, "##").c_str(), m_Size, true))
		{
			ImGui::PushFont(Menu::Font::g_ChildTitleFont);
			ImGui::Text(m_Name.erase(0, 2).c_str());
			ImGui::PopFont();
			ImGui::Separator();
			ImGui::Spacing();

			for (auto& item : m_Items)
				item->Draw();
		}
		ImGui::EndChild();
	}
}