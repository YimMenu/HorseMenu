#pragma once

#include "../LuaLibrary.hpp"
#include "../LuaModule.hpp"
#include "game/rdr/Pools.hpp"


namespace Terminus::LuaJIT
{
	class LuaEntitiesLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	public:
		void Register(sol::state& L) override
		{
			/*@terminus.table Entities
			*
			* function GetAllPedsAsHandles
			* return table<integer,integer> peds Array of handles
			
			* function GetAllVehiclesAsHandles
			* return table<integer,integer> vehicles Array of handles
			
			* function GetAllObjectsAsHandles
			* return table<integer,integer> objects Array of handles
			
			* function GetAllPickupsAsHandles
			* return table<integer,integer> pickups Array of handles
			@*/
			auto entities = L["Entities"].get_or_create<sol::table>();

			entities["GetAllPedsAsHandles"] = []() {
				auto peds = Pools::GetPeds();
				std::vector<int> outPeds{};
				outPeds.reserve(peds.size());

				for (auto ped : peds)
					outPeds.push_back(ped.GetHandle());

				return outPeds;
			};

			entities["GetAllVehiclesAsHandles"] = []() {
				auto vehicles = Pools::GetVehicles();
				std::vector<int> outVehs{};
				outVehs.reserve(vehicles.size());

				for (auto veh : vehicles)
					outVehs.push_back(veh.GetHandle());

				return outVehs;
			};

			entities["GetAllObjectsAsHandles"] = []() {
				auto objects = Pools::GetObjects();
				std::vector<int> outObjects{};
				outObjects.reserve(objects.size());

				for (auto obj : objects)
					outObjects.push_back(obj.GetHandle());

				return outObjects;
			};

			entities["GetAllPickupsAsHandles"] = []() {
				auto pickups = Pools::GetPickups();
				std::vector<int> outPickups{};
				outPickups.reserve(pickups.size());

				for (auto p : pickups)
					outPickups.push_back(p.GetHandle());

				return outPickups;
			};
		}
	};

	LuaEntitiesLib _LuaEntitiesLib;
}
