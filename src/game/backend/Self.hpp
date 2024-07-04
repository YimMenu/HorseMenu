#pragma once
#include "game/rdr/Player.hpp"
#include "game/rdr/Ped.hpp"
#include "game/rdr/Entity.hpp"

namespace YimMenu
{
	class Self
	{
		Ped m_SelfPed;
		Player m_SelfPlayer;
		Ped m_Mount;
		Entity m_Vehicle;

	public:
		static Ped GetPed()
		{
			return GetInstance().m_SelfPed;
		}

		static Player GetPlayer()
		{
			return GetInstance().m_SelfPlayer;
		}

		static Ped GetMount()
		{
			return GetInstance().m_Mount;
		}

		static Entity GetVehicle()
		{
			return GetInstance().m_Vehicle;
		}

		static void Update()
		{
			GetInstance().UpdateImpl();
		}

	private:
		Self();
		void UpdateImpl();

		static Self& GetInstance()
		{
			static Self Instance;
			return Instance;
		}
	};
}