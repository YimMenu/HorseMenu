#pragma once
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

#include <cmath>

namespace YimMenu
{
	extern int SpawnVehicle(std::string modelName, Vector3 coords, float rotation, bool notNeeded = true);
}