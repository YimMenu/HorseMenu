#include "Player.hpp"

#include "game/pointers/Pointers.hpp"

#include <network/CNetGamePlayer.hpp>
#include <player/CPlayerInfo.hpp>

namespace YimMenu
{
	Player::Player(uint8_t id)
	{
		m_Handle = Pointers.GetNetPlayerFromPid(id);
	}

	bool Player::IsValid()
	{
		return m_Handle && m_Handle->IsValid();
	}

	int Player::GetId()
	{
		if (!IsValid())
			return 255;

		return m_Handle->m_PlayerIndex;
	}

	const char* Player::GetName()
	{
		if (!IsValid())
			return "Null Player!";

		return m_Handle->GetName();
	}

	CNetGamePlayer* Player::GetHandle()
	{
		return m_Handle;
	}

	rage::rlGamerInfo* Player::GetGamerInfo()
	{
		if (!IsValid())
			return nullptr;

		return m_Handle->GetGamerInfo();
	}

	Ped Player::GetPed()
	{
		if (!IsValid() || !m_Handle->m_PlayerInfo)
			return nullptr;

		return m_Handle->m_PlayerInfo->m_Ped;
	}

	bool Player::IsHost()
	{
		return m_Handle->IsHost();
	}

	bool Player::operator==(Player other)
	{
		return m_Handle == other.m_Handle;
	}
}