#pragma once
#include "Player.hpp"

namespace rage
{
	class netObject;
}

namespace YimMenu::Network
{
	extern void ForceRemoveNetworkEntity(std::uint16_t net_id, int ownership_token = -1, bool delete_locally = true, Player for_player = nullptr);
	extern void ForceRemoveNetworkEntity(rage::netObject* object, bool delete_locally = true, Player for_player = nullptr);
	extern void ForceRemoveAnimScene(int handle);
}