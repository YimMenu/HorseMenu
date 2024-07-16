#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Scripts.hpp"

namespace YimMenu::Features
{
	void ParlayEnd(int bits)
	{
		uint64_t data[7]{};
		data[0] = static_cast<uint64_t>(ScriptEvent::SCRIPT_EVENT_PARLEY);
		data[1] = Self::GetPlayer().GetId();
		data[4] = 5;
		data[5] = 11;
		data[6] = 9;
		Scripts::SendScriptEvent(data, 9, bits);
	}

	class EndParlay : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			ParlayEnd(1 << player.GetId());
		}
	};

	static EndParlay _EndParlay{"endparlay", "End Parlay", "End a parlay with the player", 0, false};
}