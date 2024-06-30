#pragma once
#include <mutex>

namespace YimMenu
{
	struct Message
	{
		std::string m_Sender;
		std::string m_Message;
		int m_Num;
		bool m_Remove = false;

		bool operator==(const Message& other) const
		{
			return m_Num == other.m_Num;
		}
	};

	class ChatDisplay
	{
	private:
		std::vector<Message> m_Messages = {};
		std::mutex m_mutex;

		Message ShowImpl(std::string sender, std::string message);
		void DrawImpl();
		bool EraseImpl(Message message);

		static ChatDisplay& GetInstance()
		{
			static ChatDisplay instance;
			return instance;
		}

	public:
		static Message Show(std::string sender, std::string message)
		{
			return GetInstance().ShowImpl(sender, message);
		}

		static void Draw()
		{
			GetInstance().DrawImpl();
		}

		static bool Erase(Message message)
		{
			return GetInstance().EraseImpl(message);
		}
	};

}