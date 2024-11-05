#include "Player.hpp"

#include "game/backend/Players.hpp"
#include "game/backend/PlayerDatabase.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "game/rdr/Natives.hpp"

#include <network/CFriend.hpp>
#include <network/CNetGamePlayer.hpp>
#include <network/CNetworkPlayerMgr.hpp>
#include <network/netPeerAddress.hpp>
#include <network/rlScPeerConnection.hpp>
#include <network/CNetworkScSession.hpp>
#include <player/CPlayerInfo.hpp>


namespace YimMenu
{
	Player::Player(uint8_t id)
	{
		m_Handle = Pointers.GetNetPlayerFromPid(id);
	}

	bool Player::IsValid() const
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
			return "Invalid";
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

	bool Player::IsFriend()
	{
		if (!IsValid())
			return false;

		for (int i = 0; i < 250; i++)
		{
			if (!Pointers.FriendRegistry[i])
				break;

			if (Pointers.FriendRegistry[i]->m_RockstarId == GetRID())
				return true;
		}

		return false;
	}

	uint32_t Player::GetMessageId()
	{
		return m_Handle->m_MessageId;
	}

	uint64_t Player::GetRID()
	{
		if (!IsValid())
			return 0;

		return m_Handle->m_PlayerInfo->m_GamerInfo.m_GamerHandle2.m_RockstarId;
	}

	netAddress Player::GetExternalAddress()
	{
		if (auto addr = GetConnectPeerAddress())
			return addr->m_ExternalAddress;

		return {};
	}

	netAddress Player::GetInternalAddress()
	{
		if (auto addr = GetConnectPeerAddress())
			return addr->m_InternalAddress;

		return {};
	}

	netAddress Player::GetRelayAddress()
	{
		if (auto addr = GetConnectPeerAddress())
			return addr->m_RelayAddress;

		return {};
	}

	uint16_t Player::GetExternalPort()
	{
		if (auto addr = GetConnectPeerAddress())
			return addr->m_ExternalPort;

		return {};
	}

	uint16_t Player::GetInternalPort()
	{
		if (auto addr = GetConnectPeerAddress())
			return addr->m_InternalPort;

		return {};
	}

	uint16_t Player::GetRelayPort()
	{
		if (auto addr = GetConnectPeerAddress())
			return addr->m_RelayPort;

		return {};
	}

	uint32_t Player::GetConnectionType()
	{
		if (auto addr = Pointers.GetPeerAddressByMessageId(Pointers.NetworkPlayerMgr->m_NetConnectionManager, GetMessageId()))
			return addr->m_connection_type;

		return {};
	}

	int Player::GetRank()
	{
		if (!IsValid())
			return -1;

		auto data = ScriptGlobal(1155150).As<PLAYER_PERSONA_DATA*>();
		return data->Entries[GetId()].Rank;
	}

	int Player::GetHonor()
	{
		if (!IsValid())
			return -1;

		auto data = ScriptGlobal(1155150).As<PLAYER_PERSONA_DATA*>();
		return data->Entries[GetId()].HonorInfo.HonorLevel;
	}

	Language Player::GetLanguage()
	{
		if (!IsValid())
			return Language::UNDEFINED;

		auto data = ScriptGlobal(1101558).As<PLAYER_STATUS_SYNC_DATA*>();
		return data->Entries[GetId()].PlayerLanguage;
	}

	District Player::GetDistrict()
	{
		if (!IsValid())
			return District::INVALID;

		auto data = ScriptGlobal(1101558).As<PLAYER_STATUS_SYNC_DATA*>();
		return data->Entries[GetId()].CurrentDistrict;
	}

	Region Player::GetRegion()
	{
		if (!IsValid())
			return Region::INVALID;

		auto data = ScriptGlobal(1101558).As<PLAYER_STATUS_SYNC_DATA*>();
		return data->Entries[GetId()].CurrentRegion;
	}

	float Player::GetAverageLatency()
	{
		if (!IsValid())
			return -1.f;

		return NETWORK::NETWORK_GET_AVERAGE_LATENCY(GetId());
	}

	float Player::GetAveragePacketLoss()
	{
		if (!IsValid())
			return -1.f;

		return NETWORK::NETWORK_GET_AVERAGE_PACKET_LOSS(GetId());
	}

	rage::rlGamerInfoBase* Player::GetConnectPeerAddress()
	{
		if (!IsValid())
			return nullptr;

		auto sess = *Pointers.ScSession;

		if (!sess)
			return nullptr;

		auto session = sess->m_SessionMultiplayer;

		if (!session)
			return nullptr;

		auto peer = session->GetPlayerByIndex(GetId());

		if (!peer)
			return nullptr;

		return &peer->m_SessionPeer->m_Connection->m_PeerAddress;
	}

	rage::netPeerAddress* Player::GetAddress()
	{
		if (auto addr = Pointers.GetPeerAddressByMessageId(Pointers.NetworkPlayerMgr->m_NetConnectionManager, GetMessageId()))
			return addr;

		return nullptr;
	}

	PlayerData& Player::GetData()
	{
		return Players::GetPlayerData(GetId());
	}

	bool Player::IsModder()
	{
		return !GetData().m_Detections.empty();
	}

	void Player::AddDetection(Detection det)
	{
		if (!GetData().m_Detections.contains(det))
		{
			GetData().m_Detections.insert(det);
			g_PlayerDatabase->AddDetection(g_PlayerDatabase->GetOrCreatePlayer(GetRID(), GetName()), det);
		}
	}

	bool Player::operator==(Player other)
	{
		return m_Handle == other.m_Handle;
	}
}