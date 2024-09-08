#pragma once
#include "game/pointers/Pointers.hpp" // game import in core

#include <mutex>


namespace YimMenu
{
	struct Message
	{
		std::string m_Sender;
		std::string m_Message;
		ImColor m_Color;
	};

	class ChatDisplay
	{
	private:
		std::vector<Message> m_Messages = {};
		std::mutex m_Mutex;

		void ShowImpl(std::string sender, std::string message, ImColor color);
		void DrawImpl();
		void ClearImpl();

		static ChatDisplay& GetInstance()
		{
			static ChatDisplay instance;
			return instance;
		}

	public:
		static void Show(std::string sender, std::string message, ImColor color)
		{
			return GetInstance().ShowImpl(sender, message, color);
		}

		static void Draw()
		{
			GetInstance().DrawImpl();
		}

		static void Clear()
		{
			GetInstance().ClearImpl();
		}
	};

}