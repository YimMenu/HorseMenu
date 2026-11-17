#pragma once

#include "../LuaLibrary.hpp"
#include "../LuaModule.hpp"
#include "game/backend/Self.hpp"
#include "util/teleport.hpp"


namespace Terminus::LuaJIT
{
	class LuaSelfLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	public:
		void Register(sol::state& L) override
		{
			/*@terminus.class LocalPlayer
			* description
				Provides functions to output text to console and log file.

			* method GetPed Returns the local player's [Ped](lua://Ped) class instance.
			* return Ped ped

			* method GetPlayer Returns the local player's [Player](lua://Player) class instance.
			* return Player player

			* method GetMount Returns the local player's mount if any.
			* return Ped mount

			* method GetVehicle Returns the local player's vehicle if any.
			* return Vehicle vehicle

			* method Teleport
			* param coords<Vector3>
			* param loadGround<boolean?> Optional: load ground at the coordinates before teleporting. Prevents falling through the map.
			@*/
			L.new_usertype<Self>("LocalPlayer", sol::no_constructor,
			    // clang-format off
				"GetPed",     &Self::GetPed, 
				"GetPlayer",  &Self::GetPlayer,
				"GetMount",   &Self::GetMount,
				"GetVehicle", &Self::GetVehicle,

				"Teleport", [](const Self& self, Vector3& coords, sol::optional<bool> loadGround) {
					if (!Teleport::TeleportEntity(self.GetPed().GetHandle(), coords, loadGround.value_or(false)))
						LOG(WARNING) << "Failed to teleport LocalPlayer to coordinates!";
				}
			);
		}
	};

	LuaSelfLib _LuaSelfLib;
}
