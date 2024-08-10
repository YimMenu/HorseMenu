#include "core/frontend/Notifications.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/rdr/Natives.hpp"
#include "util/Rewards.hpp"

namespace YimMenu::Features
{
	// TODO: Choose a reward, Delete individual chests, else we will have full pools.
	class SpawnGoldChest : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			auto forward     = ENTITY::GET_ENTITY_FORWARD_VECTOR(player.GetPed().GetHandle());
			auto pos         = player.GetPed().GetPosition();
			float distance   = 1.75f;
			float x          = pos.x + (forward.x * distance);
			float y          = pos.y + (forward.y * distance);
			float z          = pos.z;
			auto chestModel  = "p_steamer_trunk_001"_J;
			auto rewardModel = "mp001_s_mp_boxsm01x"_J;
			float heading    = ENTITY::GET_ENTITY_HEADING(player.GetPed().GetHandle());

			for (uint8_t i = 0; !STREAMING::HAS_MODEL_LOADED(chestModel) && i < 100; i++)
			{
				STREAMING::REQUEST_MODEL(chestModel, 1);
				ScriptMgr::Yield();
			}
			if (!STREAMING::HAS_MODEL_LOADED(chestModel))
			{
				Notifications::Show("Treasure Spawner", "Failed to load chest model", NotificationType::Error);
				return;
			}

			for (uint8_t i = 0; !STREAMING::HAS_MODEL_LOADED(rewardModel) && i < 100; i++)
			{
				STREAMING::REQUEST_MODEL(rewardModel, 1);
				ScriptMgr::Yield();
			}
			if (!STREAMING::HAS_MODEL_LOADED(rewardModel))
			{
				std::string msg = std::format("Failed to load reward model", rewardModel);
				Notifications::Show("Treasure Spawner", msg, NotificationType::Error);
				return;
			}

			auto chest = Entity(OBJECT::CREATE_OBJECT(chestModel, x, y, z + 1.085, true, false, true, false, false));
			OBJECT::PLACE_OBJECT_ON_GROUND_PROPERLY(chest.GetHandle(), true);
			ENTITY::SET_ENTITY_HEADING(chest.GetHandle(), heading);
			Vector3 boxPos = ENTITY::GET_ENTITY_COORDS(chest.GetHandle(), true, true);
			int id         = NETWORK::OBJ_TO_NET(chest.GetHandle());
			NETWORK::NETWORK_REGISTER_ENTITY_AS_NETWORKED(chest.GetHandle());
			NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(id, true);

			float offsetX = 0.075f * cos(heading);
			float offsetY = 0.075f * sin(heading);

			for (int i = 0; i < 25; ++i)
			{
				auto rewardItem =
				    Entity(OBJECT::CREATE_OBJECT(rewardModel, boxPos.x + offsetX, boxPos.y + offsetY, boxPos.z + 0.125f, true, false, true, false, false));
				ENTITY::SET_ENTITY_HEADING(rewardItem.GetHandle(), heading);
				int id = NETWORK::OBJ_TO_NET(rewardItem.GetHandle());
				NETWORK::NETWORK_REGISTER_ENTITY_AS_NETWORKED(rewardItem.GetHandle());
				NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(id, true);
			}

			ScriptMgr::Yield(50ms);

			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(chestModel);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(rewardModel);
		}
	};

	static SpawnGoldChest _SpawnGoldChest{"spawngoldchest", "Spawn Gold Chest", "Spawn a chest full of gold for the player"};
}