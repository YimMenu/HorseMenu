#pragma once
#include "game/pointers/Pointers.hpp" // game import in core

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

		Message ShowImpl(std::string sender, std::string message);
		void DrawImpl();

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
	};

}