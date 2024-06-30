#pragma once
#include <mutex>

namespace YimMenu
{
	struct Message
	{
		std::string m_Sender;
		std::string m_Message;
	};

	class ChatDisplay
	{
	private:
		std::vector<Message> m_Messages = {};
		std::mutex m_mutex;

		void ShowImpl(std::string sender, std::string message);
		void DrawImpl();

		static ChatDisplay& GetInstance()
		{
			static ChatDisplay instance;
			return instance;
		}

	public:
		static void Show(std::string sender, std::string message)
		{
			return GetInstance().ShowImpl(sender, message);
		}

		static void Draw()
		{
			GetInstance().DrawImpl();
		}
	};

}