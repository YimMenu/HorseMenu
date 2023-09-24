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
		CNetGamePlayer* m_Handle;
	public:
		constexpr Player(CNetGamePlayer* handle) :
			m_Handle(handle)
		{
		}

		constexpr bool IsValid();
		constexpr int GetId();
		constexpr const char* GetName();
		constexpr CNetGamePlayer* GetHandle();
		constexpr rage::rlGamerInfo* GetGamerInfo();
		constexpr Entity GetPed();
	};
}