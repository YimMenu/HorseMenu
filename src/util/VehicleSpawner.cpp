#include "VehicleSpawner.hpp"

namespace YimMenu
{
	int SpawnVehicle(std::string model_name, Vector3 coords, float rotation)
	{
		Hash model = MISC::GET_HASH_KEY(model_name.c_str());

		STREAMING::REQUEST_MODEL(model, 0);
		while (!STREAMING::HAS_MODEL_LOADED(model))
			ScriptMgr::Yield();

		if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_A_VEHICLE(model))
		{
			Vehicle veh = VEHICLE::CREATE_VEHICLE(model, coords.x, coords.y, coords.z, rotation, 1, 1, 0, 0);

			ScriptMgr::Yield();
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh, 0);
			ENTITY::SET_ENTITY_VISIBLE(veh, true);
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&veh);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
			return veh;
		}
		return 0;
	}
};