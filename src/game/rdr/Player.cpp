#include "Player.hpp"

#include "game/backend/Players.hpp"
#include "game/pointers/Pointers.hpp"

#include <network/CNetGamePlayer.hpp>
#include <network/netPeerAddress.hpp>
#include <player/CPlayerInfo.hpp>


namespace YimMenu
{
	Player::Player(uint8_t id)
	{
		m_Handle = Pointers.GetNetPlayerFromPid(id);
	}

	bool Player::IsValid()
	{
		return m_Handle && m_Handle->IsValid() && m_Handle->m_PlayerInfo;
	}

	int Player::GetId()
	{
		if (!IsValid())
		{
			if (!*Pointers.IsSessionStarted)
				return 0;

			return 255;
		}

		return m_Handle->m_PlayerIndex;
	}

	const char* Player::GetName()
	{
		if (!IsValid())
		{
			return "Null Player!";
		}

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
		if (!IsValid())
			return nullptr;

		return m_Handle->m_PlayerInfo->m_Ped;
	}

	bool Player::IsHost()
	{
		return m_Handle->IsHost();
	}

	uint32_t Player::GetMessageId()
	{
		return m_Handle->m_MessageId;
	}

	uint64_t Player::GetRID()
	{
		if (!IsValid())
			return 0;

		return m_Handle->m_PlayerInfo->m_GamerInfo.m_GamerHandle.m_RockstarId;
	}

	netAddress Player::GetExternalIpAddress()
	{
		if (!IsValid())
			return (netAddress)0;

		return m_Handle->m_PlayerInfo->m_GamerInfo.m_ExternalAddress;
	}

	netAddress Player::GetInternalIpAddress()
	{
		if (!IsValid())
			return (netAddress)0;

		return m_Handle->m_PlayerInfo->m_GamerInfo.m_InternalAddress;
	}

	netAddress Player::GetRelayIpAddress()
	{
		if (!IsValid())
			return (netAddress)0;

		return m_Handle->m_PlayerInfo->m_GamerInfo.m_RelayAddress;
	}

	netAddress Player::GetUnkIpAddress()
	{
		if (!IsValid())
			return (netAddress)0;

		return m_Handle->m_PlayerInfo->m_GamerInfo.m_UnkAddress;
	}

	uint16_t Player::GetExternalPort()
	{
		if (!IsValid())
			return 0;

		return m_Handle->m_PlayerInfo->m_GamerInfo.m_ExternalPort;
	}

	uint16_t Player::GetInternalPort()
	{
		if (!IsValid())
			return 0;

		return m_Handle->m_PlayerInfo->m_GamerInfo.m_InternalPort;
	}

	uint16_t Player::GetRelayPort()
	{
		if (!IsValid())
			return 0;

		return m_Handle->m_PlayerInfo->m_GamerInfo.m_RelayPort;
	}

	uint16_t Player::GetUnkPort()
	{
		if (!IsValid())
			return 0;

		return m_Handle->m_PlayerInfo->m_GamerInfo.m_UnkPort;
	}

	uint32_t Player::GetRelayState()
	{
		if (!IsValid())
			return 0;

		return m_Handle->m_PlayerInfo->m_GamerInfo.m_RelayState;
	}

	PlayerData& Player::GetData()
	{
		return Players::GetPlayerData(GetId());
	}

	bool Player::operator==(Player other)
	{
		return m_Handle == other.m_Handle;
	}

	inline Player::operator bool()
	{
		return IsValid();
	}
}