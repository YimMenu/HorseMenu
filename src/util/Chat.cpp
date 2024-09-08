#include "Chat.hpp"
#include "core/frontend/widgets/imgui_colors.h"
#include "game/rdr/Packet.hpp"
#include "game/frontend/ChatDisplay.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/Self.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Player.hpp"
#include "util/Helpers.hpp"

#include <rage/Guid.hpp>
#include <rage/datBitBuffer.hpp>
#include <network/rlGamerInfo.hpp>

namespace YimMenu
{
	void SendChatMessage(const std::string& message)
	{
		if (!*Pointers.IsSessionStarted)
			return;

		auto self = Self::GetPlayer();
		Packet msg{};
		msg.WriteMessageHeader(NetMessageType::TEXT_CHAT);
		Helpers::WriteBufferString(message.c_str(), 256, &msg.GetBuffer());
		msg.GetBuffer().Write<uint64_t>(self.GetGamerInfo()->m_HostToken, 64);
		msg.GetBuffer().Write<bool>(false, 1);

		for (auto& player : Players::GetPlayers())
		{
			if (player.second.IsValid())
			{
				msg.Send(player.second.GetMessageId(), 7);
			}
		}

		RenderChatMessage(message, self.GetName(), ImGui::Colors::Green);
	}

	void RenderChatMessage(const std::string& message, const std::string& sender, ImColor color)
	{
		ChatDisplay::Show(sender, message, color);
	}
}