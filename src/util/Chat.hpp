#pragma once
#include "Packet.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/Players.hpp"
#include "game/features/Features.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Player.hpp"
#include "util/Helpers.hpp"

#include <rage/Guid.hpp>
#include <rage/datBitBuffer.hpp>


namespace YimMenu
{
	void SendChatMessage(const std::string& message);
	void RenderChatMessage(const std::string& message, const std::string& sender);
}