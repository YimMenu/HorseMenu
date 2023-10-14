#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Scripts.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/rdr/Enums.hpp"

namespace YimMenu::Features
{
	void MaxHonor(int bits)
	{
		uint64_t data[7]{};

		for (int i = 0; i < 5; i++)
		{
			data[0] = static_cast<uint64_t>(ScriptEvent::SCRIPT_EVENT_PERSONA_HONOR);
			data[1] = Self::Id;
			data[4] = 2;
			data[5] = "PERSONA_HONOR_ACTION__FME_BOUNTY_RETURNED_ALIVE"_J;
			data[6] = 1;
			Scripts::SendScriptEvent(data, 13, bits);
			data[5] = "PERSONA_HONOR_ACTION__HORSE_CARE"_J;
			Scripts::SendScriptEvent(data, 13, bits);
			data[5] = "PERSONA_HONOR_ACTION__NB_KIDNAPPED_RESCUE"_J;
			Scripts::SendScriptEvent(data, 13, bits);
			data[5] = "PERSONA_HONOR_ACTION__MISSION_POS_FIFTY"_J;
			Scripts::SendScriptEvent(data, 13, bits);
			ScriptMgr::Yield(40ms);
		}
	}

	class MaximumHonor : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			MaxHonor(1 << player.GetId());
		}
	};

	class MaximumHonorAll : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			MaxHonor(-1 & ~(1 << Self::Id));
		}
	};

	static MaximumHonor _MaximumHonor{"maxhonor", "Max Honor", "Sets the player's honor to the maximum value", 0, false};
	static MaximumHonorAll _MaximumHonorAll{"maxhonorall", "Max Honor", "Sets the player's honor to the maximum value"};
}