#include "game/backend/NativeHooks.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "game/rdr/Scripts.hpp"
#include "core/frontend/Notifications.hpp"

namespace Terminus::Features
{
	// TODO: Refactor sender
	void MaxHonor(int bits)
	{
		uint64_t data[7]{};

		for (int i = 0; i < 5; i++)
		{
			data[0] = static_cast<uint64_t>(ScriptEvent::SCRIPT_EVENT_PERSONA_HONOR);
			data[1] = Self::GetPlayer().GetId();
			data[4] = 2;
			data[5] = "PERSONA_HONOR_ACTION__FME_BOUNTY_RETURNED_ALIVE"_J;
			data[6] = 1;
			Scripts::SendScriptEvent(data, 13, 6, bits);
			data[5] = "PERSONA_HONOR_ACTION__HORSE_CARE"_J;
			Scripts::SendScriptEvent(data, 13, 6, bits);
			data[5] = "PERSONA_HONOR_ACTION__NB_KIDNAPPED_RESCUE"_J;
			Scripts::SendScriptEvent(data, 13, 6, bits);
			data[5] = "PERSONA_HONOR_ACTION__MISSION_POS_FIFTY"_J;
			Scripts::SendScriptEvent(data, 13, 6, bits);
			ScriptMgr::Yield(40ms);
		}
	}

	class MaximumSPHonor : public Command
	{
		// TODO: Automatically update honor bar like MP, PERSONA_ hashes and ScriptEvents do not apply in SP, possibly wrong SE's?
		// TODO: Add value slider that shows current honor and is adjustable
		using Command::Command;

		virtual void OnCall() override
		{
			DECORATOR::DECOR_REGISTER("honor_block", 5);
			DECORATOR::DECOR_REGISTER("honor_bank", 5);
			DECORATOR::DECOR_REGISTER("honor_override", 5);

			int value = 500;

			auto honorPtr = ScriptGlobal(40).At(11095 + 35).As<int*>();
			if (honorPtr)
				*honorPtr = value;

			struct StatId
			{
				int hash;
				int padding;
			};
			StatId honorStat;
			honorStat.hash = Joaat("HONOR_CURRENT");
			honorStat.padding = 0;

			int statValue = 0;
			STATS::STAT_ID_GET_INT(&honorStat, &statValue);
			LOG(INFO) << "Current Honor:" << statValue;

			STATS::STAT_ID_SET_INT(&honorStat, value, true); // Set to 500, value may differ but, works

			DECORATOR::DECOR_SET_INT(Self::GetPed().GetHandle(), "honor_override", value);

			GRAPHICS::ANIMPOSTFX_PLAY("PlayerHonorLevelGood");

			int newStatValue = 0;
			STATS::STAT_ID_GET_INT(&honorStat, &newStatValue);
			LOG(INFO) << "New Honor:" << newStatValue;
		}
	};

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
			for (const auto& [idx, _] : Players::GetPlayers())
			{
				MaxHonor(1 << idx);
			}
		}
	};

	static MaximumSPHonor _MaximumSPHonor{"maxsphonor", "Max Honor", "Sets Arthur's honor to the maximum value"};
	static MaximumHonor _MaximumHonor{"maxhonor", "Max Honor", "Sets the player's honor to the maximum value", 0, false};
	static MaximumHonorAll _MaximumHonorAll{"maxhonorall", "Give All Max Honor", "Sets all player's honor to the maximum value"};
}