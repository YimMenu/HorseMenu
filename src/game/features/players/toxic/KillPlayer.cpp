#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"

namespace Terminus::Features
{
	class KillPlayer : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			player.GetPed().Kill();
		}
	};

	static KillPlayer _KillPlayer{"kill", "Kill Player", "Kills the selected player"};
}