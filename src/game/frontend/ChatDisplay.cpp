#include "ChatDisplay.hpp"

#include "core/logger/LogHelper.hpp"
#include "game/backend/FiberPool.hpp"
#include "core/frontend/widgets/color_text/imgui_color_text.hpp"
#include "game/pointers/Pointers.hpp"
#include "Menu.hpp"


namespace YimMenu
{

	void ChatDisplay::ShowImpl(std::string sender, std::string message)
	{
		if (sender.empty() || message.empty())
			return;

		Message notification{};
		notification.m_Sender  = sender;
		notification.m_Message = message;

		std::lock_guard<std::mutex> lock(m_mutex);

		if (m_Messages.size() >= 20)
		{
			m_Messages.erase(m_Messages.begin());
		}

		m_Messages.push_back(notification);
	}

	void ChatDisplay::DrawImpl()
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		int position = 0;

		float y_pos = position * 100 + 200;
		float x_pos = Pointers.ScreenResX - 430;

		ImGui::SetNextWindowSize(ImVec2(Pointers.ScreenResX - x_pos - 10, Pointers.ScreenResY - y_pos), ImGuiCond_Always);
		ImGui::SetNextWindowPos(ImVec2(x_pos, y_pos), ImGuiCond_Always);
		ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
		ImGui::PushFont(Menu::Font::g_ChatFont);

		ImGui::Begin("##chatwin", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBackground);

		for (auto& message : m_Messages)
		{
			std::string str = std::format("$b{}$w: {}\n", message.m_Sender, message.m_Message);
			ImGui::ColorfulText(str, {{'b', ImGui::blue}, {'w', ImGui::white}});
		}

		ImGui::PopFont();
		ImGui::PopStyleColor();
		ImGui::End();
	}
}