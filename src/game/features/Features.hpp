#pragma once
#include <script/types.hpp>

namespace YimMenu
{
	namespace Self
	{
		inline Ped PlayerPed;
		inline ::Player Id;
		inline Vector3 Pos;
		inline Vector3 Rot;
		inline Vehicle Veh;
		inline Ped Mount;
		inline bool IsOnMount;
	}

	inline bool g_Spectating = false;
	inline int g_SpectateId = -1;

	void FeatureLoop();
	void BlockControlsForUI();
	void SpectateTick();
}