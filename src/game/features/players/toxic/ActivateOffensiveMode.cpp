#include "game/commands/PlayerCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Scripts.hpp"
#include "game/rdr/Enums.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	void Offensive(Player player)
	{
		uint64_t data[13]{};
		data[0] = static_cast<uint64_t>(ScriptEvent::SCRIPT_EVENT_NOTORIETY_FORCE_NOT_PASSIVE_HORSE);
		data[1] = player.GetId();
		Scripts::SendScriptEvent(data, 13, 43, 1 << player.GetId());
	}

	class ActivateOffensiveMode : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			Offensive(player);
		}
	};

	static ActivateOffensiveMode _ActivateOffensiveMode{"offensive", "Activate Offensive Mode", "Forces the player into offensive mode"};
}