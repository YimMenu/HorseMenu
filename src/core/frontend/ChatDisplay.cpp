#include "ChatDisplay.hpp"

namespace YimMenu
{

	Message ChatDisplay::ShowImpl(std::string sender, std::string message)
	{
		if (sender.empty() || message.empty())
			return {};

		Message notification{};
		notification.m_Sender  = sender;
		notification.m_Message = message;

		std::lock_guard<std::mutex> lock(m_mutex);
		m_Messages.emplace_back(notification);

		if (m_Messages.size() > 9)
		{
			m_Messages.erase(m_Messages.begin());
		}

		return notification;
	}

	static void DrawMessage(Message& message, int position)
	{
		float y_pos     = position * 100;
		float x_pos     = Pointers.ScreenResX - 200;
		std::string str = std::string(message.m_Sender).append(": ").append(message.m_Message);

		ImGui::SetNextWindowSize(ImVec2(125.f, 100.f), ImGuiCond_Always);
		ImGui::SetNextWindowPos(ImVec2(x_pos, y_pos + 10), ImGuiCond_Always);

		std::string windowTitle = "Chat " + std::to_string(position + 1);
		ImGui::Begin(windowTitle.c_str(), nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBackground);

		ImGui::TextWrapped("%s", str.c_str());

		ImGui::End();
	}

	void ChatDisplay::DrawImpl()
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		int position = 0;

		for (auto& message : m_Messages)
		{
			DrawMessage(message, position);
			position++;
		}
	}
}