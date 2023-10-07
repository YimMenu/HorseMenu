#include "Player.hpp"

#include <network/CNetGamePlayer.hpp>
#include <player/CPlayerInfo.hpp>

namespace YimMenu
{
	bool Player::IsValid()
	{
		return m_Handle && m_Handle->IsValid();
	}

	int Player::GetId()
	{
		if (!m_Handle)
			return -1;

		return m_Handle->m_PlayerIndex;
	}

	const char* Player::GetName()
	{
		if (!m_Handle)
			return "INVALID";

		return m_Handle->GetName();
	}

	CNetGamePlayer* Player::GetHandle()
	{
		return m_Handle;
	}

	rage::rlGamerInfo* Player::GetGamerInfo()
	{
		if (!m_Handle)
			return nullptr;

		return m_Handle->GetGamerInfo();
	}

	Entity Player::GetPed()
	{
		if (!m_Handle || !m_Handle->m_PlayerInfo)
			return nullptr;

		return m_Handle->m_PlayerInfo->m_Ped;
	}

	bool Player::operator==(Player other)
	{
		return m_Handle == other.m_Handle;
	}
}