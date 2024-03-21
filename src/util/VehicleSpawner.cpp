#include "VehicleSpawner.hpp"

namespace YimMenu
{
	extern bool SpawnVehicle(std::string model_name, int player_ped_id)
	{
		Hash model = MISC::GET_HASH_KEY(model_name.c_str());
		float offset;

		STREAMING::REQUEST_MODEL(model, 0);
		while (!STREAMING::HAS_MODEL_LOADED(model))
			ScriptMgr::Yield(0ms);
		Vector3 pCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(player_ped_id, 0.0, -10.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_A_VEHICLE(model))
		{
			Vector3 dim1, dim2;
			MISC::GET_MODEL_DIMENSIONS(model, &dim1, &dim2);

			offset = dim2.y * 1.6;

			Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(Self::PlayerPed);
			float rot   = (ENTITY::GET_ENTITY_ROTATION(Self::PlayerPed, 0)).z;

			Vehicle veh =
			    VEHICLE::CREATE_VEHICLE(model, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), pCoords.z, rot, 1, 1, 0, 0);

			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh, 0);
			ENTITY::SET_ENTITY_VISIBLE(veh, true);
			//DECORATOR::DECOR_SET_BOOL(model, "wagon_block_honor", true);
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&veh);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
			return true;
		}
		return false;
	}
};