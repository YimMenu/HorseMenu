#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"
#include "util/SpawnObject.hpp"


namespace YimMenu::Features
{
	class CagePlayerLarge : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			Vector3 playerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player.GetId()), true, true);
			SpawnObject(0x99C0CFCF, playerCoords);
		}
	};

	static CagePlayerLarge _CagePlayerLarge{"cageplayerlarge", "Cage Player(Large)", "Cages the player using a larger cage"};
}