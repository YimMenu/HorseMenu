#pragma once
#include "Ped.hpp"

class CNetGamePlayer;
union netAddress;

namespace rage
{
	class rlGamerInfo;
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

		bool IsValid();
		int GetId();
		const char* GetName();
		CNetGamePlayer* GetHandle();
		rage::rlGamerInfo* GetGamerInfo();
		Ped GetPed();
		bool IsHost();
		uint32_t GetMessageId();
		uint64_t GetRID();
		netAddress GetExternalIpAddress();
		netAddress GetInternalIpAddress();
		netAddress GetRelayIpAddress();
		netAddress GetUnkIpAddress();
		uint16_t GetExternalPort();
		uint16_t GetInternalPort();
		uint16_t GetRelayPort();
		uint16_t GetUnkPort();
		uint32_t GetRelayState();
		PlayerData& GetData();

		bool operator==(Player other);
		inline operator bool();
	};
	static_assert(sizeof(Player) == 8, "don't add anything else to Player");
}