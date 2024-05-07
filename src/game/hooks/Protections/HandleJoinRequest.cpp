#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "core/player_database/PlayerDatabase.hpp"
#include "game/backend/Protections.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"

#include <network/rlGamerInfo.hpp>


namespace rage
{
	class CJoinRequestContext;
	class CMsgJoinResponse;
}


namespace YimMenu::Hooks
{
	bool Protections::HandleJoinRequest(int64_t network, int64_t session, rage::rlGamerInfo* player_info, rage::CJoinRequestContext* ctx)
	{
		// Use Player::GetRID() once #116 is merged
		if (auto player = g_PlayerDatabase.GetPlayer(player_info->m_GamerHandle.m_rockstar_id); player && player->block_join)
		{
			rage::CMsgJoinResponse response{};
			response.m_status_code = 1;
			Pointers.WriteJoinResponseData(&response, ctx->m_join_response_data, 512, &ctx->m_join_response_size);
			Notifications::Show("Block Join", player->name.append("has been blocked from joining!"));
			return false;
		}
		else
		{
			return BaseHook::Get<Protections::HandleJoinRequest, DetourHook<decltype(&Protections::HandleJoinRequest)>>()
			    ->Original()(network, session, player_info, ctx);
		}
	}
}