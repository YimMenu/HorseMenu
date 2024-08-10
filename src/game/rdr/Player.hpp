#pragma once
#include "Ped.hpp"
#include "game/backend/Detections.hpp"

#include <script/globals/PlayerPersonaData.hpp>
#include <script/globals/PlayerStatusSyncData.hpp>

class CNetGamePlayer;
union netAddress;

namespace rage
{
	class rlGamerInfo;
	class rlGamerInfoBase;
}

namespace YimMenu
{
	class PlayerData;

	class Player
	{
		CNetGamePlayer* m_Handle;

	public:
		Player() :
		    m_Handle(nullptr)
		{
		}

		Player(uint8_t id);

		constexpr Player(CNetGamePlayer* netGamePlayer) :
		    m_Handle(netGamePlayer)
		{
		}

		// object
		bool IsValid() const;
		int GetId();
		const char* GetName();
		CNetGamePlayer* GetHandle();
		rage::rlGamerInfo* GetGamerInfo();
		Ped GetPed();
		bool IsHost();
		bool IsFriend();
		uint32_t GetMessageId();
		uint64_t GetRID();
		netAddress GetExternalAddress();
		netAddress GetInternalAddress();
		netAddress GetRelayAddress();
		uint16_t GetExternalPort();
		uint16_t GetInternalPort();
		uint16_t GetRelayPort();
		uint32_t GetRelayState();
		int GetRank();
		int GetHonor();
		Language GetLanguage();
		District GetDistrict();
		Region GetRegion();
		float GetAverageLatency();
		float GetAveragePacketLoss();
		rage::rlGamerInfoBase* GetConnectPeerAddress();

		// backend/data store (should be refactored?)
		PlayerData& GetData();
		bool IsModder();
		void AddDetection(Detection det);

		bool operator==(Player other);

		inline operator bool()
		{
			return IsValid();
		}

		inline operator int() = delete;
	};
	static_assert(sizeof(Player) == 8, "don't add anything else to Player");
}