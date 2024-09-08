#include "game/backend/Self.hpp"
#include "game/backend/Players.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "core/commands/BoolCommand.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Scripts.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	void KickFromMission(Player player)
	{
		uint64_t data[6]{};
		data[0] = static_cast<uint64_t>(ScriptEvent::SCRIPT_EVENT_NET_VS_MISSION_INTRO);
		data[1] = player.GetId();
		data[2] = NETWORK::GET_NETWORK_TIME_ACCURATE();
		data[3] = 0;
		data[4] = 11;
		data[5] = 0;

		Scripts::SendScriptEvent(data, 6, 42, 1 << player.GetId());
	}

	class KickFromMissionLobby : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			KickFromMission(player);
		}
	};

	static KickFromMissionLobby _KickFromMissionLobby{"kickfrommissionlobby", "Kick From Mission Lobby", "Kick the player from your mission lobby", 0, false};
}