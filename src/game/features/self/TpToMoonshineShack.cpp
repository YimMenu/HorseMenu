#include "core/commands/Command.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "util/teleport.hpp"

namespace YimMenu::Features
{

	class TpToMoonshineShack : public Command
	{
		using Command::Command;
		static constexpr auto ShackBlip = ScriptGlobal(1297441).At(128);

		virtual void OnCall() override
		{
			if (ShackBlip.CanAccess())
			{
				Blip Shack = *ShackBlip.As<Blip*>();
				if (MAP::DOES_BLIP_EXIST(Shack))
				{
					Vector3 ShackCoords = MAP::GET_BLIP_COORDS(Shack);
					YimMenu::Teleport::TeleportEntity(Self::GetPed().GetHandle(), ShackCoords, true);
				}
				else
				{
					Notifications::Show("Moonshine Shack", "Unable to find moonshine shack blip", NotificationType::Error);
				}
			}
		}
	};

	static TpToMoonshineShack _TpToMoonshineShack{"tptomoonshineshack", "Teleport To Moonshine Shack", "Teleport to your moonshine shack"};
}