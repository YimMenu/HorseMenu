#include "SpawnPed.hpp"

namespace YimMenu
{
	int SpawnPed(std::string model_name, Vector3 coords, float heading, bool blockNewPedMovement, bool spawnDead, bool invincible, bool invisible, int scale)
	{
		Hash model = MISC::GET_HASH_KEY(model_name.c_str());
		if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_VALID(model))
		{
			for (int i = 0; i < 30 && !STREAMING::HAS_MODEL_LOADED(model); i++)
			{
				STREAMING::REQUEST_MODEL(model, false);
				ScriptMgr::Yield();
			}

			auto ped = PED::CREATE_PED(model, coords.x, coords.y, coords.z, heading, 1, 0, 0, 0);

			ScriptMgr::Yield();
			PED::_SET_RANDOM_OUTFIT_VARIATION(ped, true);
			ENTITY::SET_ENTITY_ALPHA(ped, 255, 0);
			ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(ped, true);
			ScriptMgr::Yield();
			NETWORK::NETWORK_REGISTER_ENTITY_AS_NETWORKED(ped);

			int id = NETWORK::PED_TO_NET(ped);

			ENTITY::SET_ENTITY_SHOULD_FREEZE_WAITING_ON_COLLISION(ped, true);
			if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(ped))
			{
				NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(id, true);
				NETWORK::IS_NETWORK_ID_OWNED_BY_PARTICIPANT(id);
			}

			ScriptMgr::Yield();


			ENTITY::FREEZE_ENTITY_POSITION(ped, blockNewPedMovement);

			ENTITY::SET_ENTITY_INVINCIBLE(ped, invincible);

			ENTITY::SET_ENTITY_VISIBLE(ped, !invisible);


			PED::_SET_PED_SCALE(ped, (float)scale);

			if (spawnDead)

				PED::APPLY_DAMAGE_TO_PED(ped, ENTITY::GET_ENTITY_HEALTH(ped), 1, 21030, YimMenu::Self::PlayerPed);

			ScriptMgr::Yield();
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
			return ped;
		}
		return 0;
	};
}
