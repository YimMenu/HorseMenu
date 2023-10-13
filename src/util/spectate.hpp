#pragma once
#include "game/rdr/Natives.hpp"

namespace YimMenu
{
    inline bool g_Spectating = false;

    //TODO doesn't work as intended
    inline void SpectatePlayer(Player player)
    {
        if (!player.IsValid())
            return;

        NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(g_Spectating, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player.GetId()));

    }
}