#include "Player.hpp"
#include <network/CNetGamePlayer.hpp>
#include <player/CPlayerInfo.hpp>

namespace YimMenu
{
	constexpr bool Player::IsValid()
	{
		return m_Handle && m_Handle->IsValid();
	}

	constexpr int Player::GetId()
	{
		return m_Handle->m_PlayerIndex;
	}

	constexpr const char* Player::GetName()
	{
		return m_Handle->GetName();
	}
	
	constexpr CNetGamePlayer* Player::GetHandle()
	{
		return m_Handle;
	}

	constexpr rage::rlGamerInfo* Player::GetGamerInfo()
	{
		return m_Handle->GetGamerInfo();
	}

	constexpr Entity Player::GetPed()
	{
		if (!m_Handle->m_PlayerInfo)
			return nullptr;

		return m_Handle->m_PlayerInfo->m_Ped;
	}
}