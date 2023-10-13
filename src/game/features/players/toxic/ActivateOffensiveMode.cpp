#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Scripts.hpp"

namespace YimMenu::Features
{
	class ActivateOffensiveMode : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			uint64_t data[13]{};
			data[0] = 37;
			data[1] = Self::Id;
			Scripts::SendScriptEvent(data, 13, 1 << player.GetId());
		}
	};

	static ActivateOffensiveMode _ActivateOffensiveMode{"offensive", "Activate Offensive Mode", "Forces the player into offensive mode"};
}