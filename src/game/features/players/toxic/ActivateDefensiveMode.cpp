#include "game/commands/PlayerCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Scripts.hpp"
#include "game/rdr/Enums.hpp"

namespace YimMenu::Features
{
	class ActivateDefensiveMode : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			uint64_t data[13]{};
			data[0] = static_cast<uint64_t>(ScriptEvent::SCRIPT_EVENT_NOTORIETY_FORCE_PASSIVE);
			data[1] = Self::GetPlayer().GetId();
			data[8] = 2;
			Scripts::SendScriptEvent(data, 13, 1 << player.GetId());
		}
	};

	static ActivateDefensiveMode _ActivateDefensiveMode{"defensive", "Activate Defensive Mode", "Forces the player into defensive mode"};
}