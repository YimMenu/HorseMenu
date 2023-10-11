#pragma once
#include "common.hpp"

namespace YimMenu
{
	enum class NotificationType
	{
		Info,
		Success,
		Warning,
		Error
	};

	struct Notification
	{
		NotificationType m_Type;
		std::string m_Title;
		std::string m_Message;
        std::chrono::time_point<std::chrono::system_clock> m_created_on;
		int m_Duration;
		ImVec2 m_Size;

		std::string GetIdenfier()
		{
			return m_Title.append(m_Message);
		}
	};

    class NotificationService
    {
	private:
        std::unordered_map<std::string, Notification> m_Notifications;

	public:
        void ShowNotification(std::string title, std::string message, NotificationType type, int duration);
		void DrawTick();
    };

	inline NotificationService g_NotificationService;

}