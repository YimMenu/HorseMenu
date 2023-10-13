#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Scripts.hpp"

namespace YimMenu::Features
{
	class ActivateDefensiveMode : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			uint64_t data[13]{};
			data[0] = 36;
			data[1] = Self::Id;
			data[8] = 2;
			Scripts::SendScriptEvent(data, 13, 1 << player.GetId());
		}
	};

	static ActivateDefensiveMode _ActivateDefensiveMode{"defensive", "Activate Defensive Mode", "Forces the player into defensive mode"};
}