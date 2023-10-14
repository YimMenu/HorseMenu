#include "Player.hpp"
#include "game/pointers/Pointers.hpp"

#include <network/CNetGamePlayer.hpp>
#include <player/CPlayerInfo.hpp>

namespace YimMenu
{
	bool Player::IsValid()
	{
		if (m_NetPlayer && m_NetPlayer->IsValid())
			m_Handle = m_NetPlayer->m_ActiveIndex;
		else
			return false;

		return true;
	}

	int Player::GetId()
	{
		if (!IsValid())
			return 255;

		return m_NetPlayer->m_PlayerIndex;
	}

	const char* Player::GetName()
	{
		if (!IsValid())
			return "Null Player!";

		return m_NetPlayer->GetName();
	}

	CNetGamePlayer* Player::GetHandle()
	{
		return Pointers.GetNetPlayerFromPid(m_Handle);
	}

	rage::rlGamerInfo* Player::GetGamerInfo()
	{
		if (!IsValid())
			return nullptr;

		return m_NetPlayer->GetGamerInfo();
	}

	Entity Player::GetPed()
	{
		if (!IsValid() || !m_NetPlayer->m_PlayerInfo)
			return nullptr;

		return m_NetPlayer->m_PlayerInfo->m_Ped;
	}

	bool Player::operator==(Player other)
	{
		return m_Handle == other.m_Handle;
	}
}