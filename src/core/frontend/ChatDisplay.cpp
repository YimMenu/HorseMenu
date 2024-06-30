#include "ChatDisplay.hpp"

#include "core/logger/LogHelper.hpp"
#include "game/backend/FiberPool.hpp"

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

		int nextPos        = m_Messages.back().m_Num + 1;
		notification.m_Num = nextPos;
		auto result        = m_Messages.emplace_back(notification);

		if (m_Messages.size() > 10)
		{
			m_Messages.erase(m_Messages.begin());
		}

		return notification;
	}

	bool ChatDisplay::EraseImpl(Message message)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		for (auto& msg : m_Messages)
		{
			if (msg.m_Num == message.m_Num)
			{
				message.m_Remove = true;
				return true;
			}
		}

		return false;
	}

	static void DrawMessage(Message& message, int position)
	{
		float y_pos     = position * 100;
		float x_pos     = 90;
		std::string str = std::string(message.m_Sender).append(": ").append(message.m_Message);

		ImGui::SetNextWindowSize(ImVec2(350.f, 100.f), ImGuiCond_Always);
		ImGui::SetNextWindowPos(ImVec2(x_pos, y_pos + 10), ImGuiCond_Always);

		std::string windowTitle = "Chat " + std::to_string(position + 1);
		ImGui::Begin(windowTitle.c_str(), nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

		ImGui::TextWrapped("%s", str.c_str());

		ImGui::End();
	}

	void ChatDisplay::DrawImpl()
	{
		std::vector<Message> keys_to_erase;
		{
			std::lock_guard<std::mutex> lock(m_mutex);
			int position = 0;

			for (auto& message : m_Messages)
			{
				DrawMessage(message, position);

				if (m_Messages.size() > 10)
				{
					keys_to_erase.push_back(message);
				}

				if (message.m_Remove)
				{
					keys_to_erase.emplace_back(message);
				}

				position++;
			}
		}
		std::lock_guard<std::mutex> lock(m_mutex);
		for (const auto& key : keys_to_erase)
		{
			m_Messages.erase(std::find(m_Messages.begin(), m_Messages.end(), key));
		}
	}
}