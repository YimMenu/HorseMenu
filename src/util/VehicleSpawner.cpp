#include "VehicleSpawner.hpp"

namespace YimMenu
{
	int SpawnVehicle(std::string modelName, Vector3 coords, float rotation, bool notNeeded)
	{
		Hash model = MISC::GET_HASH_KEY(modelName.c_str());

		STREAMING::REQUEST_MODEL(model, 0);
		for (int i = 0; i < 30 && !STREAMING::HAS_MODEL_LOADED(model); i++)
		{
			STREAMING::REQUEST_MODEL(model, false);
			ScriptMgr::Yield();
		}

		if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_A_VEHICLE(model))
		{
			Vehicle veh = VEHICLE::CREATE_VEHICLE(model, coords.x, coords.y, coords.z, rotation, TRUE, TRUE, FALSE, 0);

			ScriptMgr::Yield();
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh, 0);
			ENTITY::SET_ENTITY_VISIBLE(veh, TRUE);
			if (notNeeded)
				ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&veh);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
			return veh;
		}
		return 0;
	}
};