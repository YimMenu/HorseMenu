#include "core/frontend/Notifications.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/rdr/Natives.hpp"


namespace YimMenu
{
	bool SpawnPed(std::string model_name, Player player, int playerPed)
	{
		FiberPool::Push([=] {
			Hash model = MISC::GET_HASH_KEY(model_name.c_str());
			LOG(INFO) << "FOUND HASH";
			if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_VALID(model))
			{
				if (!STREAMING::HAS_MODEL_LOADED(model))
				{
					STREAMING::REQUEST_MODEL(model, false);
					ScriptMgr::Yield();
				}

				Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, 0.0, 3.0, -0.3);
				auto ped = PED::CREATE_PED(model, coords.x, coords.y, coords.z, static_cast<float>(rand() % 360), 0, 0, 0, 0);


				ScriptMgr::Yield();
				PED::_SET_RANDOM_OUTFIT_VARIATION(ped, true);
				ENTITY::SET_ENTITY_ALPHA(ped, 255, 0);
				ENTITY::SET_ENTITY_VISIBLE(ped, true);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
				NETWORK::NETWORK_REGISTER_ENTITY_AS_NETWORKED(ped);
				NETWORK::NETWORK_SET_ENTITY_ONLY_EXISTS_FOR_PARTICIPANTS(ped, false);

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
				return true;
			}
			return false;
		});
		return false;
	}
}