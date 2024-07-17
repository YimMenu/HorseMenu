#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Scripts.hpp"

namespace YimMenu::Features
{
	void AddBounty(Player player)
	{
		uint64_t data[13]{};
		data[0]  = static_cast<uint64_t>(ScriptEvent::SCRIPT_EVENT_NOTORIETY_PRESS_CHARGES);
		data[1]  = player.GetId();
		data[4]  = 2;
		data[5]  = 5;
		data[6]  = 9;
		data[11] = 1;
		data[12] = 1;

		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				Scripts::SendScriptEvent(data, 13, 7, 1 << player.GetId());
			}

			ScriptMgr::Yield();
		}
	}
	
	class IncreaseBounty : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			AddBounty(player);
		}
	};

	static IncreaseBounty _IncreaseBounty{"increasebounty", "Increase Bounty", "Increase the players bounty", 0, false};
}