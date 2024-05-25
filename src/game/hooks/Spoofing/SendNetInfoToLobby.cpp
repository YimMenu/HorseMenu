#include "core/commands/BoolCommand.hpp"
#include "core/commands/Commands.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Natives.hpp"
#include "util/Storage/Spoofing.hpp"

#include <network/rlGamerInfo.hpp>


namespace YimMenu::Hooks
{
	bool Spoofing::SendNetInfoToLobby(rage::rlGamerInfo* local_player, int64_t a2, int64_t a3, DWORD* a4)
	{
		if (!g_SpoofingStorage.spoofed_name.empty())
			memcpy(local_player->m_Name, g_SpoofingStorage.spoofed_name.c_str(), sizeof(local_player->m_Name));

		return BaseHook::Get<Spoofing::SendNetInfoToLobby, DetourHook<decltype(&Spoofing::SendNetInfoToLobby)>>()->Original()(local_player, a2, a3, a4);
	}
}