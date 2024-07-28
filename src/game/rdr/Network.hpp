#pragma once

namespace YimMenu::Network
{
	extern void ForceRemoveNetworkEntity(std::uint16_t net_id, int ownership_token = -1, bool delete_locally = true);
}