#pragma once

#include "../LuaLibrary.hpp"
#include "../LuaModule.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Pools.hpp"


namespace Terminus::LuaJIT
{
	class LuaEntitiesLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	private:
		template<auto GetPool>
		static int GetEntityFromBlip(int blipIndex)
		{
			if (!MAP::DOES_BLIP_EXIST(blipIndex) || !MAP::_IS_BLIP_ATTACHED_TO_ANY_ENTITY(blipIndex))
				return 0;

			for (auto ent : GetPool())
			{
				const int handle = ent.GetHandle();

				if (!ENTITY::DOES_ENTITY_EXIST(handle))
					continue;

				if (!MAP::_DOES_ENTITY_HAVE_BLIP(handle))
					continue;

				if (MAP::GET_BLIP_FROM_ENTITY(handle) == blipIndex)
					return handle;
			}

			return 0;
		}

		template<auto GetPool>
		static std::vector<int> GetEntitiesAsHandles()
		{
			auto entities = GetPool();
			std::vector<int> out{};
			out.reserve(entities.size());

			for (auto e : entities)
				out.push_back(e.GetHandle());

			return out;
		}

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
			
			* function GetPedFromBlip
			* param blipIndex<integer>
			* return integer ped entity handle or 0
			
			* function GetVehicleFromBlip
			* param blipIndex<integer>
			* return integer vehicle entity handle or 0
			
			* function GetObjectFromBlip
			* param blipIndex<integer>
			* return integer object entity handle or 0
			@*/
			auto entities = L["Entities"].get_or_create<sol::table>();

			entities["GetAllPedsAsHandles"] = []() {
				return GetEntitiesAsHandles<Pools::GetPeds>();
			};

			entities["GetAllVehiclesAsHandles"] = []() {
				return GetEntitiesAsHandles<Pools::GetVehicles>();
			};

			entities["GetAllObjectsAsHandles"] = []() {
				return GetEntitiesAsHandles<Pools::GetObjects>();
			};

			entities["GetAllPickupsAsHandles"] = []() {
				return GetEntitiesAsHandles<Pools::GetPickups>();
			};

			entities["GetPedFromBlip"] = [](int blipIndex) {
				return GetEntityFromBlip<Pools::GetPeds>(blipIndex);
			};

			entities["GetVehicleFromBlip"] = [](int blipIndex) {
				return GetEntityFromBlip<Pools::GetVehicles>(blipIndex);
			};

			entities["GetObjectFromBlip"] = [](int blipIndex) {
				return GetEntityFromBlip<Pools::GetObjects>(blipIndex);
			};
		}
	};

	LuaEntitiesLib _LuaEntitiesLib;
}
