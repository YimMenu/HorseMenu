#pragma once

namespace Terminus
{
	void SendChatMessage(const std::string& message);
	void RenderChatMessage(const std::string& message, const std::string& sender, ImColor color);
}