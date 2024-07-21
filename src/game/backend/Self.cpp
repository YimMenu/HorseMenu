#include "Self.hpp"
#include "game/rdr/Natives.hpp"
#include "game/pointers/Pointers.hpp"

namespace YimMenu
{
	Self::Self() :
	    m_SelfPed(nullptr),
	    m_SelfPlayer(nullptr),
	    m_Mount(nullptr),
	    m_Vehicle(nullptr)
	{
	}

	void Self::UpdateImpl()
	{
		m_SelfPed = Ped(Pointers.GetLocalPed(), PLAYER::PLAYER_PED_ID());
		m_SelfPlayer = Player(PLAYER::PLAYER_ID());
		if (m_SelfPed.IsValid())
		{
			m_Vehicle = m_SelfPed.GetVehicle();
			m_Mount = m_SelfPed.GetMount();
		}
	}
}