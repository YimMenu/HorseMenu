#pragma once
#include "game/backend/ScriptMgr.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"

#include <cmath>
#include <optional>

namespace YimMenu
{
	extern int SpawnVehicle(std::string model_name, int player_ped_id, std::optional<Vector3> coords = std::nullopt);
}