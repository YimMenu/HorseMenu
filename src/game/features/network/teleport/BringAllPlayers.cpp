#include "core/commands/Command.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "util/teleport.hpp"

namespace Terminus::Features
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

	class AllPlayersOcean : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			for (auto& [idx, player] : Players::GetPlayers())
			{
				Teleport::TeleportPlayerToCoords(player, rage::vector3(-74.2f, -1640.9f, 125.9f));
			}
		}
	};

	static BringAllPlayers _BringAllPlayers{"bringall", "Bring", "Teleport all players to you"};

	static AllPlayersOcean _AllPlayersOcean{"tpalltoocean", "Teleport All to Ocean", "Teleport all players to Flat Iron Lake"};
}