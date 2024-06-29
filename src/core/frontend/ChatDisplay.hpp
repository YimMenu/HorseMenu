#pragma once
#include <mutex>

namespace YimMenu
{
	static inline float m_CardSizeX = 350.f;
	static inline float m_CardSizeY = 100.f;

	struct Message
	{
		std::string m_Sender;
		std::string m_Message;
		int m_Num;
		bool m_Remove = false;
	};

	class ChatDisplay
	{
	private:
		std::unordered_map<int, Message> m_Messages = {};
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