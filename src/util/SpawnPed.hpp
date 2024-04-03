#pragma once
#include "core/frontend/Notifications.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"


namespace YimMenu
{
	extern int SpawnPed(std::string model_name, Vector3 coords, float heading = 0.0f, bool blockNewPedMovement = false, bool spawnDead = false, bool invincible = false, bool invisible = false, int scale = 1);
}