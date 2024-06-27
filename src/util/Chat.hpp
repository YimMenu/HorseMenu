#pragma once
#include "Packet.hpp"
#include "game/backend/Players.hpp"
#include "game/features/Features.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Player.hpp"

#include <rage/Guid.hpp>
#include <rage/datBitBuffer.hpp>


namespace YimMenu
{
	void SendChatMessage(const std::string& message);
	void RenderChatMessage(const std::string& message, const std::string& sender);
	void SerializeGamerHandle(rage::rlGamerHandle& hnd, rage::datBitBuffer& buffer);
	void DeserializeGamerHandle(rage::rlGamerHandle& hnd, rage::datBitBuffer& buffer);
	bool ReadRockstarId(uint64_t* rockstarId, rage::datBitBuffer& buffer);
	bool WriteRockstarId(uint64_t rockstarId, rage::datBitBuffer& buffer);
}