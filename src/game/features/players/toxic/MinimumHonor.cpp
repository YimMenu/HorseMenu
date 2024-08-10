#include "game/backend/Players.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Scripts.hpp"


namespace YimMenu::Features
{
	// TODO: Refactor sender
	void MinHonor(int bits)
	{
		uint64_t data[7]{};

		for (int i = 0; i < 5; i++)
		{
			data[0] = static_cast<uint64_t>(ScriptEvent::SCRIPT_EVENT_PERSONA_HONOR);
			data[1] = Self::GetPlayer().GetId();
			data[4] = 2;
			data[5] = "PERSONA_HONOR_ACTION__MISSION_NEG_FIFTY"_J;
			data[6] = 1;
			Scripts::SendScriptEvent(data, 13, 6, bits);
			data[5] = "PERSONA_HONOR_ACTION__MISSION_NEG_FORTYFIVE"_J;
			Scripts::SendScriptEvent(data, 13, 6, bits);
			data[5] = "PERSONA_HONOR_ACTION__MURDER_RAMPAGE"_J;
			Scripts::SendScriptEvent(data, 13, 6, bits);
			data[5] = "PERSONA_HONOR_ACTION__MURDER_BUTCHER"_J;
			Scripts::SendScriptEvent(data, 13, 6, bits);
			ScriptMgr::Yield(40ms);
		}
	}

	class MinimumHonor : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			MinHonor(1 << player.GetId());
		}
	};

	class MinimumHonorAll : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			for (const auto& [idx, _] : Players::GetPlayers())
			{
				MinHonor(1 << idx);
			}
		}
	};

	static MinimumHonor _MinimumHonor{"minhonor", "Min Honor", "Sets the player's honor to the minimum value", 0, false};
	static MinimumHonorAll _MinimumHonorAll{"minhonorall", "Give All Min Honor", "Sets all player's honor to the minimum value"};
}