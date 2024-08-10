#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Natives.hpp"
#include "util/Storage/Spoofing.hpp"

#include <network/rlGamerInfo.hpp>


namespace YimMenu::Hooks
{
	bool Spoofing::SendNetInfoToLobby(rage::rlGamerInfo* local_player, int64_t a2, int64_t a3, DWORD* a4)
	{
		if (g_SpoofingStorage.spoofName)
		{
			memcpy(local_player->m_Name, g_SpoofingStorage.spoofedName.c_str(), sizeof(local_player->m_Name));
		}

		if (g_SpoofingStorage.spoofIP)
		{
			netAddress addr;
			addr.m_field1 = g_SpoofingStorage.spoofedIP[0];
			addr.m_field2 = g_SpoofingStorage.spoofedIP[1];
			addr.m_field3 = g_SpoofingStorage.spoofedIP[2];
			addr.m_field4 = g_SpoofingStorage.spoofedIP[3];

			memcpy(&(local_player->m_ExternalAddress), &addr, sizeof(local_player->m_ExternalAddress));
		}

		if (g_SpoofingStorage.spoofRID)
		{
			memcpy(&(local_player->m_GamerHandle.m_RockstarId), &g_SpoofingStorage.spoofedRID, sizeof(local_player->m_GamerHandle.m_RockstarId));
		}

		return BaseHook::Get<Spoofing::SendNetInfoToLobby, DetourHook<decltype(&Spoofing::SendNetInfoToLobby)>>()->Original()(local_player, a2, a3, a4);
	}
}