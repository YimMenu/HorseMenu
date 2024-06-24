#pragma once
#include "core/frontend/Notifications.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu
{
	void SpawnObject(uint32_t hash, Vector3 coords);
}