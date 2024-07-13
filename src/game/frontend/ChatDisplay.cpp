#include "ChatDisplay.hpp"

#include "Menu.hpp"
#include "core/frontend/widgets/color_text/imgui_color_text.hpp"
#include "core/logger/LogHelper.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/pointers/Pointers.hpp"


namespace YimMenu
{
	static const ImVec4 &white = {1, 1, 1, 1}, blue = {0.000f, 0.703f, 0.917f, 1}, red = {0.976f, 0.117f, 0.265f, 1}, grey = {0.230f, 0.226f, 0.289f, 1}, lgrey = {0.630f, 0.626f, 0.689f, 1}, green = {0.000f, 0.386f, 0.265f, 1}, lime = {0.55f, 0.90f, 0.06f, 1}, yellow = {0.91f, 1.00f, 0.21f, 1}, purple = {1, 0, 1, 1}, orange = {1.00f, 0.36f, 0.09f, 1};

	void ChatDisplay::ShowImpl(std::string sender, std::string message)
	{
		if (sender.empty() || message.empty())
			return;

		Message notification{};
		notification.m_Sender  = sender;
		notification.m_Message = message;

		static const bool isBigScreen = Pointers.ScreenResX > 1600 && Pointers.ScreenResY > 900;
		static const int maxMessages  = isBigScreen ? 17 : 7;

		std::lock_guard<std::mutex> lock(m_Mutex);


		if (m_Messages.size() >= maxMessages)
		{
			m_Messages.erase(m_Messages.begin());
		}


		m_Messages.push_back(notification);
	}

	void ChatDisplay::DrawImpl()
	{
		std::lock_guard<std::mutex> lock(m_Mutex);
		int position = 0;

		float y_pos = position * 100 + 200;
		float x_pos = Pointers.ScreenResX - 470;

		ImGui::SetNextWindowSize(ImVec2(Pointers.ScreenResX - x_pos - 10, Pointers.ScreenResY - y_pos), ImGuiCond_Always);
		ImGui::SetNextWindowPos(ImVec2(x_pos, y_pos), ImGuiCond_Always);
		ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
		ImGui::PushFont(Menu::Font::g_ChatFont);

		ImGui::Begin("##chatwin", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBackground);

		for (auto& message : m_Messages)
		{
			ImGui::PushStyleColor(ImGuiCol_Text, blue);
			ImGui::TextWrapped("%s:", message.m_Sender.data());
			ImGui::PopStyleColor();
			ImGui::SameLine();
			ImGui::TextWrapped("%s", message.m_Message.data());
		}

		ImGui::PopFont();
		ImGui::PopStyleColor();
		ImGui::End();
	}
}