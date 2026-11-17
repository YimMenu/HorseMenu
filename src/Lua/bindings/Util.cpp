#pragma once

#include "../LuaLibrary.hpp"
#include "../LuaModule.hpp"
#include "util/Joaat.hpp"
#include "util/teleport.hpp"
#include "game/pointers/Pointers.hpp"


namespace Terminus::LuaJIT
{
	class LuaUtilLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	public:
		void Register(sol::state& L) override
		{

			/*@terminus.table Util
			* description
				Provides general utility functions.

			* function Joaat Computes the Jenkins one-at-a-time hash of a string.
			* param str<string>
			* return integer hash

			* function WarpIntoVehicle Warps the ped into the provided vehicle.
			* param ped<integer> ped handle
			* param vehicle<integer> vehicle handle
			* return boolean success

			* function LoadGroundAtCoords Loads ground at the provided coordinates.
			* param coords<Vector3>
			* return boolean success

			* function GetWaypointCoords Returns the current waypoint coordinates. If no waypoint is set, returns a zero vector.
			* return Vector3 waypoint

			* function TeleportPlayerToCoords
			* param player<Player>
			* param coords<Vector3>
			* return boolean success

			* function Teleport Teleports the entity to the desired coordinates.
			* param entity<integer> entity handle
			* param coords<Vector3>
			* param loadGround<boolean?> Load ground at the destination before teleporting the entity. Prevents falling through the map.
			* return boolean success
			
			* function GetScreenResolution Returns the game's screen resolution or a zero vector on failure.
			* return Vector2
			@*/
			auto util                  = L["Util"].get_or_create<sol::table>();
			util["Joaat"]              = &Joaat;
			util["WarpIntoVehicle"]    = &Teleport::WarpIntoVehicle;
			util["LoadGroundAtCoords"] = &Teleport::LoadGroundAtCoords;
			util["GetWaypointCoords"]  = &Teleport::GetWaypointCoords;

			util["TeleportPlayerToCoords"] = [](Player& player, Vector3& coords) {
				return Teleport::TeleportPlayerToCoords(player, coords);
			};

			util["Teleport"] = [](int entity, Vector3& coords, sol::optional<bool> loadGround) {
				return Teleport::TeleportEntity(entity, coords, loadGround.value_or(false));
			};

			util["GetScreenResolution"] = []() {
				auto x = Pointers.ScreenResX;
				auto y = Pointers.ScreenResY;
				if (!x || !y)
					return ImVec2();

				return ImVec2(*x, *y);
			};
		}
	};

	LuaUtilLib _LuaUtilLib;
}
