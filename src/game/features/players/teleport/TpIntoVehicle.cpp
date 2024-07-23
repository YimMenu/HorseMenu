#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/rdr/Natives.hpp"
#include "game/features/Features.hpp"
#include "util/teleport.hpp"

namespace YimMenu::Features
{
	class TpIntoVehicle : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			if (Teleport::WarpIntoVehicle(Self::GetPed().GetHandle(), player.GetPed().GetVehicle().GetHandle()))
				g_Spectating = false;
		}
	};

	static TpIntoVehicle _TpIntoVehicle{"tpintovehicle", "Teleport Into Vehicle", "Teleport into the players vehicle"};
}