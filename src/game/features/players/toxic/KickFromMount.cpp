#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"

namespace YimMenu::Features
{
	class KickFromMount : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			if (player.GetPed().GetMount())
				player.GetPed().GetMount().ForceControl(); // which kicks the player out
		}
	};

	static KickFromMount _KickFromMount{"kickhorse", "Kick From Mount", "Removes the player from their horse"};
}