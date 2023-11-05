#pragma once
#include <script/types.hpp>

namespace YimMenu
{
	namespace Self
	{
		// TODO
		inline ::Ped PlayerPed;
		inline ::Player Id;
		inline Vector3 Pos;
		inline Vector3 Rot;
		inline Vehicle Veh;
		inline ::Ped Mount;
		inline bool IsOnMount;
	}

	// TODO: move these out
	inline bool g_Spectating = false;
	inline int g_SpectateId = -1;
	inline bool g_BlockControls = false;

	void FeatureLoop();
	void BlockControlsForUI();
	void BlockAllControls();
	void SpectateTick();
	void UpdatePlayerInfo();
	void ContextMenuTick();
}