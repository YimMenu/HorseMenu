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
		std::function<void()> m_context_function;
		std::string m_context_function_name;

		std::string GetIdentifier()
		{
			return m_Title + m_Message;
		}
	};

    class NotificationService
    {
	private:
        std::unordered_map<std::string, Notification> m_Notifications;

	public:
		//duration is in milliseconds
        void ShowNotification(std::string title, std::string message, NotificationType type = NotificationType::Info, int duration = 5000, std::function<void()> context_function = nullptr, std::string context_function_name = "");
		void DrawTick();
    };

	inline NotificationService g_NotificationService;

}