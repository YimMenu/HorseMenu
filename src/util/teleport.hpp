#pragma once
#include "common.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Teleport
{
    bool TeleportEntity(Entity ent, Vector3& coords);
    Vector3 GetWaypointCoords();
    bool LoadGroundAtCoords(Vector3& coords);
}