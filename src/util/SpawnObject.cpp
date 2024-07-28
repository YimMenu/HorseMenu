#include "SpawnObject.hpp"


namespace YimMenu
{
	void PreviewObject(uint32_t hash, Vector3 coords, float pitch, float yaw, float roll, float alpha, bool isEnabled) 
	{
		FiberPool::Push([=] {
			if (STREAMING::IS_MODEL_IN_CDIMAGE(hash) && STREAMING::IS_MODEL_VALID(hash))
			{
				if (!STREAMING::HAS_MODEL_LOADED(hash))
				{
					STREAMING::REQUEST_MODEL(hash, false);
					ScriptMgr::Yield();
				}

				Object hologram = OBJECT::CREATE_OBJECT(hash, coords.x, coords.y, coords.z, false, false, false, 0, 1);

				ENTITY::SET_ENTITY_VISIBLE(hologram, true);
				ENTITY::SET_ENTITY_ALPHA(hologram, alpha, false);
				ENTITY::SET_ENTITY_COLLISION(hologram, false, false);
				ENTITY::SET_ENTITY_INVINCIBLE(hologram, true);
				ENTITY::FREEZE_ENTITY_POSITION(hologram, true);

				ENTITY::SET_ENTITY_COORDS(hologram, coords.x, coords.y, coords.z, false, false, false, true);
				ENTITY::SET_ENTITY_ROTATION(hologram, pitch, roll, yaw, 2, true);
				ScriptMgr::Yield();

				ENTITY::DELETE_ENTITY(&hologram);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			}
		});
	}

	void SpawnObject(uint32_t hash, Vector3 coords, float pitch, float yaw, float roll, bool onGround, bool isFrozen, bool isBurning, bool isPickup, bool hasCollision)
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
				ENTITY::SET_ENTITY_ROTATION(obj, pitch, roll, yaw, 2, true); // Set rotation

				NETWORK::NETWORK_REGISTER_ENTITY_AS_NETWORKED(obj);
				int id = NETWORK::OBJ_TO_NET(obj);
				if (NETWORK::NETWORK_DOES_NETWORK_ID_EXIST(id))
				{
						OBJECT::PLACE_OBJECT_ON_GROUND_PROPERLY(obj, onGround);
						ENTITY::FREEZE_ENTITY_POSITION(obj, isFrozen);
					if (isBurning)
					{
						int fx = Joaat("exp_air_firebottle");
						FIRE::ADD_EXPLOSION_WITH_USER_VFX(coords.x, coords.y, coords.z, 2, fx, 1000.0, 0, 1, 0.0); // ONLY SETS THINGS AROUND IT ON FIRE
						OBJECT::_SET_OBJECT_BURN_INTENSITY(obj, 100.0);
					}
					if (isPickup)
					{
						OBJECT::_MAKE_ITEM_CARRIABLE(obj);
					}
					ENTITY::SET_ENTITY_COLLISION(obj, hasCollision, false);
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