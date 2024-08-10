#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/rdr/Network.hpp"

namespace YimMenu::Features
{
	class DeleteVehicle : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			if (player.GetPed().GetVehicle())
				Network::ForceRemoveNetworkEntity(player.GetPed().GetVehicle().GetNetworkObjectId());
		}
	};

	static DeleteVehicle _DeleteVehicle{"deletevehicle", "Delete Vehicle", "Delete the player's vehicle"};
}