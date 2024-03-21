#pragma once
#include "Ped.hpp"

class CNetGamePlayer;

namespace rage
{
	class rlGamerInfo;
}

namespace YimMenu
{
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
		bool operator==(Player other);
	};
	static_assert(sizeof(Player) == 8, "don't add anything else to Player");
}