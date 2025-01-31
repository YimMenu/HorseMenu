#include "core/commands/Command.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "util/teleport.hpp"

namespace YimMenu::Features
{
	class TpToNazar : public Command
	{
		using Command::Command;
		static constexpr auto NazarLocation = ScriptGlobal(1051832).At(4681);

		virtual void OnCall() override
		{
			if (NazarLocation.CanAccess(true))
				YimMenu::Teleport::TeleportEntity(Self::GetPed().GetHandle(), *NazarLocation.As<Vector3*>(), true);
		}
	};

	static TpToNazar _TpToNazar{"tptonazar", "Teleport To Madam Nazar", "Teleport to Madam Nazar's current location"};
}