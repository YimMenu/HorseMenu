#include "game/commands/PlayerCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "util/SpawnObject.hpp"


namespace YimMenu::Features
{
	class CagePlayerSmall : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player.GetId()), true, true);
			coords.z       = coords.z - 1.0f;
			SpawnObject(0xF3D580D3, coords, 0, 0, 0, true, true, false, false); 
		}
	};

	static CagePlayerSmall _CagePlayerSmall{"cageplayersmall", "Cage Player(Small)", "Cages the player using a smaller cage"};
}