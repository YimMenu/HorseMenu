#include "game/backend/Players.hpp"
#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "util/teleport.hpp"

namespace YimMenu::Features
{
	class TpToPlayerCamp: public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;
		static constexpr auto PlayerList = ScriptGlobal(1141332);

		virtual void OnCall(Player player) override
		{
			if (!PlayerList.CanAccess())
				return;

			for (int i = 0; i < 32; i++)
			{
				if (*PlayerList.At(i, 27).At(9).As<int*>() == player.GetId())
				{
					auto Camp = ScriptGlobal(1141332).At(i, 27).At(20);

					if (!Camp.CanAccess())
						return;

					Vector3 CampCoords = *Camp.As<Vector3*>();
					if (CampCoords != Vector3(0.f, 0.f, 0.f))
					{
						if(YimMenu::Teleport::TeleportEntity(Self::GetPed().GetHandle(), CampCoords + Vector3(1, 0, 0), true))
							g_Spectating = false;
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