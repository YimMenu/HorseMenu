#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"
#include "util/SpawnObject.hpp"


namespace YimMenu::Features
{
	class CagePlayerSmall : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			Vector3 playerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player.GetId()), true, true);
			SpawnObject(0xF3D580D3, playerCoords);
		}
	};

	static CagePlayerSmall _CagePlayerSmall{"cageplayersmall", "Cage Player(Small)", "Cages the player using a smaller cage"};
}