#include "core/commands/Command.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "util/teleport.hpp"

namespace YimMenu::Features
{
	class BringAllPlayers : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			for (auto& [idx, player] : Players::GetPlayers())
			{
				Teleport::TeleportPlayerToCoords(player, Self::GetPed().GetPosition());
			}
		}
	};

	static BringAllPlayers _BringAllPlayers{"bringall", "Bring", "Teleport all players to you"};
}