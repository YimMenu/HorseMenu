#pragma once
#include "game/rdr/Natives.hpp"

namespace YimMenu
{
    inline bool g_Spectating = false;
	inline int g_SpectatingID{-1};

    //TODO doesn't work as intended
    inline void SpectatePlayer(Player player)
    {
		if (g_Spectating && !player.IsValid())
			NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(g_Spectating, g_SpectatingID);
        else if (!player.IsValid())
            return;

		g_SpectatingID = player.GetId();
        NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(g_Spectating, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player.GetId()));
    }
}

