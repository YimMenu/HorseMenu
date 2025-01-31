#include "game/backend/Players.hpp"
#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "util/teleport.hpp"

#include <script/globals/NetCampHostData.hpp>

namespace YimMenu::Features
{
	static bool IsPlayerUsingCamp(NET_HOST_CAMP& camp, int id)
	{
		if (camp.Owner == id)
			return true;

		for (int i = 0; i < camp.TentOwners.Size; i++)
			if (camp.TentOwners[i] == id)
				return true;

		return false;
	}

	class TpToPlayerCamp: public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;
		static constexpr auto netCampHostData = ScriptGlobal(1141332);

		virtual void OnCall(Player player) override
		{
			if (!netCampHostData.CanAccess(true))
				return;

			for (int i = 0; i < 32; i++)
			{
				if (IsPlayerUsingCamp(netCampHostData.As<NetCampHostData*>()->Camps[i], player.GetId()))
				{
					Vector3 CampCoords = netCampHostData.As<NetCampHostData*>()->Camps[i].Position;
					if (CampCoords != Vector3(0.f, 0.f, 0.f))
					{
						YimMenu::Teleport::TeleportEntity(Self::GetPed().GetHandle(), CampCoords + Vector3(1, 0, 0), true);
					}
					else
					{
						Notifications::Show("Camp", "Unable to find player's camp", NotificationType::Error);
					}
					break;
				}
			}
		}
	};

	static TpToPlayerCamp _TpToPlayerCamp{"tptoplayercamp", "Teleport To Player's Camp", "Teleport to the player's camp"};
}