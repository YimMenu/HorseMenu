#include "Notifications.hpp"

#include "core/logger/LogHelper.hpp"
#include "game/backend/FiberPool.hpp" // TODO: game import in core

namespace YimMenu
{
	void Notifications::ShowImpl(std::string title, std::string message, NotificationType type, int duration, std::function<void()> context_function, std::string context_function_name)
	{
		if (title.empty() || message.empty())
			return;

		auto exists = std::find_if(m_Notifications.begin(), m_Notifications.end(), [&](auto& notification) {
			return notification.second.GetIdentifier() == std::string(title + message);
		});

		if (exists != m_Notifications.end())
			return;

		Notification notification{};
		notification.m_Title      = title;
		notification.m_Message    = message;
		notification.m_Type       = type;
		notification.m_created_on = std::chrono::system_clock::now();
		notification.m_Duration   = duration;

		if (context_function)
		{
			notification.m_context_function = context_function;
			notification.m_context_function_name = context_function_name.empty() ? "Context Function" : context_function_name;
		}

		m_Notifications.insert(std::make_pair(title + message, notification));
	}

	// Could arguably look a bit nicer
	static void DrawNotification(Notification& notification, int position)
	{
		float y_pos = position * 100;
		float x_pos = 10;
		ImVec2 cardSize(m_CardSizeX, m_CardSizeY);

		ImGui::SetNextWindowSize(cardSize, ImGuiCond_Always);
		ImGui::SetNextWindowPos(ImVec2(x_pos + notification.m_AnimationOffset, y_pos + 10), ImGuiCond_Always);

		std::string windowTitle = "Notification " + std::to_string(position + 1);
		ImGui::Begin(windowTitle.c_str(), nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

		auto timeElapsed =
		    (float)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - notification.m_created_on)
		        .count();

		auto depletionProgress = 1.0f - (timeElapsed / (float)notification.m_Duration);

		ImGui::ProgressBar(depletionProgress, ImVec2(-1, 1), "");

		auto style = ImGui::GetStyle();
		// TODO: Add icon for type insted of colored text
		if (notification.m_Type == NotificationType::Info)
		{
			ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
			ImGui::Text(notification.m_Title.c_str());
		}
		else if (notification.m_Type == NotificationType::Success)
		{
			ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 1.0f, 0.0f, 1.0f));
			ImGui::Text(notification.m_Title.c_str());
		}
		else if (notification.m_Type == NotificationType::Warning)
		{
			ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.5f, 0.0f, 1.0f));
			ImGui::Text(notification.m_Title.c_str());
		}
		else if (notification.m_Type == NotificationType::Error)
		{
			ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
			ImGui::Text(notification.m_Title.c_str());
		}

		ImGui::PopStyleColor();

		ImGui::Separator();

		ImGui::TextWrapped("%s", notification.m_Message.c_str());

		if (notification.m_context_function)
		{
			ImGui::Spacing();
			if (ImGui::Selectable(notification.m_context_function_name.c_str()))
				FiberPool::Push([notification] {
					notification.m_context_function();
				});
		}

		ImGui::End();
	}

	void Notifications::DrawImpl()
	{
		int position             = 0;

		for (auto& [id, notification] : m_Notifications)
		{
			DrawNotification(notification, position);
			
			if(notification.m_AnimationOffset < 0)
				notification.m_AnimationOffset += m_CardAnimationSpeed;

			//Need this to account for changes in card size (x dimension), custom increments might result in odd numbers
			if(notification.m_AnimationOffset > 0)
				notification.m_AnimationOffset = 0.f;
			
			if ((float)std::chrono::duration_cast<std::chrono::milliseconds>(
			        std::chrono::system_clock::now() - notification.m_created_on)
			        .count()
			    >= notification.m_Duration)
				m_Notifications.erase(id);

			position++;
		}
	}
}