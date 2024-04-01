#include "SpawnPed.hpp"

namespace YimMenu
{
	extern int SpawnPed(std::string model_name, bool blockNewPedMovement, bool spawnDead, bool invincible, bool invisible, int scale)
	{
		Hash model = MISC::GET_HASH_KEY(model_name.c_str());
		if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_VALID(model))
		{
			for (int i = 0; i < 5 && !STREAMING::HAS_MODEL_LOADED(model); i++)
			{
				STREAMING::REQUEST_MODEL(model, false);
				ScriptMgr::Yield();
			}

			Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 3.0, -0.3);
			float playerRotation = ENTITY::GET_ENTITY_ROTATION(PLAYER::PLAYER_PED_ID(), 2).x;
			int ped              = PED::CREATE_PED(model, coords.x, coords.y, coords.z, playerRotation, 0, 0, 0, 0);

			ScriptMgr::Yield();
			PED::_SET_RANDOM_OUTFIT_VARIATION(ped, true);
			ENTITY::SET_ENTITY_ALPHA(ped, 255, 0);
			ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(ped, true);
			ScriptMgr::Yield();
			ENTITY::SET_OBJECT_AS_NO_LONGER_NEEDED(&ped);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
			NETWORK::NETWORK_REGISTER_ENTITY_AS_NETWORKED(ped);

			int id = NETWORK::PED_TO_NET(ped);
			if (NETWORK::NETWORK_DOES_NETWORK_ID_EXIST(id))
			{
				ENTITY::SET_ENTITY_SHOULD_FREEZE_WAITING_ON_COLLISION(ped, true);
				if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(ped))
				{
					NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(id, true);
					NETWORK::IS_NETWORK_ID_OWNED_BY_PARTICIPANT(id);
				}
			}
			ScriptMgr::Yield();

			if (blockNewPedMovement == true)
			{
				ENTITY::FREEZE_ENTITY_POSITION(ped, true);
				ScriptMgr::Yield();
			}

			if (spawnDead == true)
			{
				PED::APPLY_DAMAGE_TO_PED(ped, ENTITY::GET_ENTITY_HEALTH(ped), 1, 21030, PLAYER::PLAYER_PED_ID());
				ScriptMgr::Yield();
			}

			if (invincible == true)
			{
				ENTITY::SET_ENTITY_INVINCIBLE(ped, true);
				ScriptMgr::Yield();
			}

			if (invisible == true)
			{
				ENTITY::SET_ENTITY_VISIBLE(ped, false);
				ScriptMgr::Yield();
			}
			else
			{
				ENTITY::SET_ENTITY_VISIBLE(ped, true);
				ScriptMgr::Yield();
			}

			if (scale > 1)
			{
				PED::_SET_PED_SCALE(ped, (float)scale);
				ScriptMgr::Yield();
			}
			return ped;
		}
		return 0;
	};
}
