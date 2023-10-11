#include "NotificationService.hpp"
#include "core/logger/LogHelper.hpp"

namespace YimMenu
{
	void NotificationService::ShowNotification(std::string title, std::string message, NotificationType type, int duration)
	{
		if (title.empty() || message.empty())
			return;

		auto exists = std::find_if(m_Notifications.begin(), m_Notifications.end(), [&](auto& notification) {
			return notification.second.GetIdenfier() == title.append(message);
		});
		if (exists != m_Notifications.end())
			return;

		Notification notification{};
		notification.m_Title      = title;
		notification.m_Message    = message;
		notification.m_Type       = type;
		notification.m_created_on = std::chrono::system_clock::now();
		notification.m_Duration   = duration;
		m_Notifications.insert(std::make_pair(title.append(message), notification));
	}

	void DrawNotification(Notification& notification, int position)
	{
	  	float y_pos = position * 75;
		ImVec2 cardSize(300, 75); // Initialize with a minimum width

		// Create a window for each notification card
		ImGui::SetNextWindowSize(cardSize, ImGuiCond_Always);
		ImGui::SetNextWindowPos(ImVec2(10, y_pos + 10), ImGuiCond_Always);

		std::string windowTitle = "Notification " + std::to_string(position + 1);
		ImGui::Begin(windowTitle.c_str(), nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

		if (notification.m_Type == NotificationType::Info)
			ImGui::Text("Info: %s", notification.m_Title.c_str());
		else if (notification.m_Type == NotificationType::Success)
			ImGui::Text("Success: %s", notification.m_Title.c_str());

        ImGui::Separator();

		ImGui::TextWrapped("%s", notification.m_Message.c_str());

		ImGui::End();
	}

	void NotificationService::DrawTick()
	{
		int position = 0;
		for (auto& [id, notification] : m_Notifications)
		{
			DrawNotification(notification, position);
			position++;

 			if ((float)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - notification.m_created_on).count() >= notification.m_Duration)
				m_Notifications.erase(id);
		}
	}
}