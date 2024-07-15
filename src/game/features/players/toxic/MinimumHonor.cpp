#include "game/backend/ScriptMgr.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Scripts.hpp"
#include "game/rdr/Enums.hpp"

namespace YimMenu::Features
{
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
			Scripts::SendScriptEvent(data, 13, bits);
			data[5] = "PERSONA_HONOR_ACTION__MISSION_NEG_FORTYFIVE"_J;
			Scripts::SendScriptEvent(data, 13, bits);
			data[5] = "PERSONA_HONOR_ACTION__MURDER_RAMPAGE"_J;
			Scripts::SendScriptEvent(data, 13, bits);
			data[5] = "PERSONA_HONOR_ACTION__MURDER_BUTCHER"_J;
			Scripts::SendScriptEvent(data, 13, bits);
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
			MinHonor(-1 & ~(1 << Self::GetPlayer().GetId()));
		}
	};

	static MinimumHonor _MinimumHonor{"minhonor", "Min Honor", "Sets the player's honor to the minimum value", 0, false};
	static MinimumHonorAll _MinimumHonorAll{"minhonorall", "Min Honor", "Sets the player's honor to the minimum value"};
}