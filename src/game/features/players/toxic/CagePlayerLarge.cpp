#include "game/commands/PlayerCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Object.hpp"


namespace YimMenu::Features
{
	class CagePlayerLarge : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			auto coords = player.GetPed().GetPosition();
			coords.z -= 1.0f;
			Object::Create(0x99C0CFCF, coords);
		}
	};

	static CagePlayerLarge _CagePlayerLarge{"cageplayerlarge", "Cage Player(Large)", "Cages the player using a larger cage"};
}