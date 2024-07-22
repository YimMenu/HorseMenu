#pragma once
#include <script/types.hpp>

namespace YimMenu
{
	// TODO: move these out
	inline bool g_Spectating    = false;
	inline int g_SpectateId     = -1;
	inline bool g_BlockControls = false;

	void FeatureLoop();
	void BlockControlsForUI();
	void SpectateTick();
	void ContextMenuTick();
}