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
		static constexpr auto MoonshineShack = ScriptGlobal(1297441).At(128).At(1);

		virtual void OnCall() override
		{
			if (MoonshineShack.CanAccess(true))
			{
				Vector3 ShackCoords;
				switch (*MoonshineShack.As<int*>())
				{
				case 0: ShackCoords = Vector3(1785.3f, -813.4f, 43.f); break;
				case 1: ShackCoords = Vector3(-1088.43f, 706.8f, 104.5f); break;
				case 2: ShackCoords = Vector3(-2777.04, -3051.f, 11.581f); break;
				case 3: ShackCoords = Vector3(1627.f, 821.f, 145.f); break;
				case 4: ShackCoords = Vector3(-1859.7f, -1730.3f, 109.5f); break;
				}
				if (ShackCoords != Vector3(0.f, 0.f, 0.f))
				{
					YimMenu::Teleport::TeleportEntity(Self::GetPed().GetHandle(), ShackCoords, false);
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