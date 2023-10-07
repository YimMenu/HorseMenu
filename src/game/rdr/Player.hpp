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

		bool IsValid();
		int GetId();
		const char* GetName();
		CNetGamePlayer* GetHandle();
		rage::rlGamerInfo* GetGamerInfo();
		Entity GetPed();
		bool operator==(Player other);
	};
}