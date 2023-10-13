#pragma once
#include "Entity.hpp"

class CNetGamePlayer;

namespace rage
{
	class rlGamerInfo;
}

namespace YimMenu
{
	class Player
	{
		uint8_t m_Handle;
		CNetGamePlayer* m_NetPlayer;

	public:
		Player() :
		    m_Handle(0),
		    m_NetPlayer(nullptr)
		{
		}

		Player(uint8_t handle) :
		    m_Handle(handle),
		    m_NetPlayer(GetHandle())
		{
		}

		constexpr Player(CNetGamePlayer* netGamePlayer) :
		    m_Handle(255),
		    m_NetPlayer(netGamePlayer)
		{
		}

		bool IsValid();
		int GetId();
		const char* GetName();
		CNetGamePlayer* GetHandle();
		rage::rlGamerInfo* GetGamerInfo();
		Entity GetPed();
		bool operator==(Player other);
	};
}