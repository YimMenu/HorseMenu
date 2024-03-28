#pragma once
#include "core/frontend/Notifications.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/rdr/Natives.hpp"


namespace YimMenu
{
	extern int SpawnPed(std::string model_name, Player player, int playerPed, bool blockNewPedMovement, bool spawnDead, bool invincible, bool invisible, int scale);
}