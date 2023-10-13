#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	//TODO doesn't work
	class ExplodePlayer : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			auto playerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player.GetId()), true, true);
			FIRE::ADD_EXPLOSION(playerCoords.x, playerCoords.y, playerCoords.z, 29, 1.0f, true, false, 1.0f);
		}
	};

	static ExplodePlayer _ExplodePlayer{"explodeplayer", "Explode", "Spawns an explosion on the player", 1, false};
}