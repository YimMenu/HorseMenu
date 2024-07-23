#pragma once
#include "core/frontend/Notifications.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/rdr/Natives.hpp"
#include "Joaat.hpp"

namespace YimMenu
{
	void SpawnObject(uint32_t hash, Vector3 coords, float pitch, float yaw, float roll, bool onGround, bool isFrozen, bool isBurning, bool isPickup, bool hasCollision); 
	void PreviewObject(uint32_t hash, Vector3 coords, float pitch, float yaw, float roll, float alpha, bool isEnabled);
}