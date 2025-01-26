#include "game/commands/PlayerCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Object.hpp"


namespace YimMenu::Features
{
	class CagePlayerSmall : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			auto coords = player.GetPed().GetPosition();
			coords.z -= 1.0f;
			Object::Create(0xF3D580D3, coords);
		}
	};

	static CagePlayerSmall _CagePlayerSmall{"cageplayersmall", "Cage Player(Small)", "Cages the player using a smaller cage"};
}