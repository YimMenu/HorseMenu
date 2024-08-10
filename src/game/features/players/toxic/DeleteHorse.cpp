#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/rdr/Network.hpp"

namespace YimMenu::Features
{
	class DeleteHorse : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			if (player.GetPed().GetMount())
				Network::ForceRemoveNetworkEntity(player.GetPed().GetMount().GetNetworkObjectId());
		}
	};

	static DeleteHorse _DeleteHorse{"deletehorse", "Delete Horse", "Delete the player's horse"};
}