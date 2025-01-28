#include "core/commands/Command.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "util/teleport.hpp"

namespace YimMenu::Features
{

	class TpToCamp : public Command
	{
		using Command::Command;
		static constexpr auto PlayerList = ScriptGlobal(1141332);

		virtual void OnCall() override
		{
			if (!PlayerList.CanAccess(true))
				return;

			for (int i = 0; i < 32; i++)
			{
				if (*PlayerList.At(i, 27).At(9).As<int*>() == Self::GetPlayer().GetId() && *PlayerList.At(i, 27).As<int*>() != 3)
				{
					auto Camp = ScriptGlobal(1141332).At(i, 27).At(20);

					if (!Camp.CanAccess(true))
						return;

					Vector3 CampCoords = *Camp.As<Vector3*>();
					if (CampCoords != Vector3(0.f, 0.f, 0.f))
					{
						YimMenu::Teleport::TeleportEntity(Self::GetPed().GetHandle(), CampCoords + Vector3(1, 0, 0), true);
					}
					else
					{
						Notifications::Show("Camp", "Unable to find camp", NotificationType::Error);
					}
					break;
				}
			}
		}
	};

	static TpToCamp _TpToCamp{"tptocamp", "Teleport To Camp", "Teleport to your camp"};
}