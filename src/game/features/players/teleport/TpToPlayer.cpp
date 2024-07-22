#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/rdr/Natives.hpp"
#include "game/backend/Players.hpp"
#include "game/features/Features.hpp"
#include "util/teleport.hpp"

namespace YimMenu::Features
{
	class TpToPlayer : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			if (Teleport::TeleportEntity(Self::GetPed().GetHandle(), player.GetPed().GetPosition(), false))
				g_Spectating = false;
		}
	};

	static TpToPlayer _TpToPlayer{"tptoplayer", "Teleport To Player", "Teleport to the player"};
}