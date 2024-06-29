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

		int nextPos = m_Messages.back().first + 1;
		auto result = m_Messages.insert(std::make_pair(nextPos, notification));

		return notification;
	}

	bool ChatDisplay::EraseImpl(Message message)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		for (auto& [id, n] : m_Messages)
		{
			if (id == message.m_Num)
			{
				n.m_Remove = true;
				return true;
			}
		}

		return false;
	}

	static void DrawMessage(Message& message, int position)
	{
		float y_pos = position * 100;
		float x_pos = 10;
		ImVec2 cardSize(m_CardSizeX, m_CardSizeY);

		ImGui::SetNextWindowSize(cardSize, ImGuiCond_Always);
		ImGui::SetNextWindowPos(ImVec2(x_pos, y_pos + 10), ImGuiCond_Always);

		std::string windowTitle = "Chat " + std::to_string(position + 1);
		ImGui::Begin(windowTitle.c_str(), nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

		ImGui::TextWrapped("%s", std::string(message.m_Sender).append(": ").append(message.m_Message).c_str());

		ImGui::End();
	}

	void ChatDisplay::DrawImpl()
	{
		std::vector<int> keys_to_erase;
		{
			std::lock_guard<std::mutex> lock(m_mutex);
			int position = 0;

			for (auto& [id, message] : m_Messages)
			{
				DrawMessage(message, position);

				if (m_Messages.size() > 10)
				{
					keys_to_erase.push_back(id);
				}

				if (message.m_Remove)
				{
					keys_to_erase.push_back(id);
				}

				position++;
			}
		}
		std::lock_guard<std::mutex> lock(m_mutex);
		for (const auto& key : keys_to_erase)
		{
			m_Messages.erase(key);
		}
	}
}