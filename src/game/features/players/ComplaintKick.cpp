#include "game/backend/Players.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"


namespace YimMenu::Features
{
	class ComplaintKick : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			for (auto& player_iter : Players::GetPlayers())
			{
				if (player_iter.second == player)
				{
					Players::SetKickTarget(player_iter.second.GetId());
					break;
				}
			}
		}
	};

	static ComplaintKick _ComplaintKick{"complaintkick", "Complaint Kick", "Kicks the player using the complaint system!"};
}