#include "core/frontend/Notifications.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"


namespace YimMenu::Features
{

	class Ragdoll : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			PED::SET_PED_TO_RAGDOLL(PLAYER::GET_PLAYER_PED(player.GetId()), 5000, 5000, 0, true, true, nullptr);
		}
	};

	static Ragdoll _Ragdoll{"ragdoll", "Ragdoll", "Ragdolls the player for 5 seconds"};
}