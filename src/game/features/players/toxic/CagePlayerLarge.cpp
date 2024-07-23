#include "game/commands/PlayerCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "util/SpawnObject.hpp"


namespace YimMenu::Features
{
	class CagePlayerLarge : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			auto coords = player.GetPed().GetPosition(); 
			coords.z -= 1.0f;
			SpawnObject(0x99C0CFCF, coords, 0, 0, 0, true, true, false, false, true); 
		}
	};

	static CagePlayerLarge _CagePlayerLarge{"cageplayerlarge", "Cage Player(Large)", "Cages the player using a larger cage"};
}
