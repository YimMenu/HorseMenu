#pragma once

namespace YimMenu
{
	static inline float m_CardSizeX = 350.f;
	static inline float m_CardSizeY = 100.f;
	static inline float m_CardAnimationSpeed = 50.f;

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
		float m_AnimationOffset = -m_CardSizeX;
		bool erasing = false;

		std::string GetIdentifier()
		{
			return std::string(m_Title).append(m_Message);
		}
	};

    class Notifications
    {
	private:
		std::unordered_map<std::string, Notification> m_Notifications = {};

		// duration is in milliseconds
		Notification ShowImpl(std::string title, std::string message, NotificationType type, int duration, std::function<void()> context_function, std::string context_function_name);
		void DrawImpl();
		bool EraseImpl(Notification notification);

		static Notifications& GetInstance()
		{
			static Notifications instance;
			return instance;
		}

	public:
		static Notification Show(std::string title, std::string message, NotificationType type = NotificationType::Info, int duration = 5000 ,std::function<void()> context_function = nullptr, std::string context_function_name = "")
		{
			return GetInstance().ShowImpl(title, message, type, duration, context_function, context_function_name);
		}

		static void Draw()
		{
			GetInstance().DrawImpl();
		}

		static bool Erase(Notification notification)
		{
			return GetInstance().EraseImpl(notification);
		}

    };

}