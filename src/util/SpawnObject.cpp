#include "SpawnObject.hpp"


namespace YimMenu
{
	void SpawnObject(uint32_t hash, Vector3 coords)
	{
		FiberPool::Push([=] {
			if (STREAMING::IS_MODEL_IN_CDIMAGE(hash) && STREAMING::IS_MODEL_VALID(hash))
			{
				if (!STREAMING::HAS_MODEL_LOADED(hash))
				{
					STREAMING::REQUEST_MODEL(hash, false);
					ScriptMgr::Yield();
				}

				Object obj = OBJECT::CREATE_OBJECT(hash, coords.x, coords.y, coords.z, true, NETWORK::NETWORK_IS_HOST_OF_THIS_SCRIPT(), 1, 0, 1);
				ScriptMgr::Yield();

				ENTITY::SET_ENTITY_VISIBLE(obj, true);

				NETWORK::NETWORK_REGISTER_ENTITY_AS_NETWORKED(obj);
				int id = NETWORK::OBJ_TO_NET(obj);
				if (NETWORK::NETWORK_DOES_NETWORK_ID_EXIST(id))
				{
					OBJECT::PLACE_OBJECT_ON_GROUND_PROPERLY(obj, true);
					ENTITY::SET_ENTITY_SHOULD_FREEZE_WAITING_ON_COLLISION(obj, true);
					NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(id, true);
					NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(obj);
				}
				ScriptMgr::Yield();

				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			}
		});
	}
}