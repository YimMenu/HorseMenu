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

	class MinimumSPHonor : public Command
	{
		// TODO: Automatically update honor bar like MP, PERSONA_ hashes and ScriptEvents do not apply in SP, possibly wrong SE's?
		// TODO: Add value slider that shows current honor and is adjustable
		using Command::Command;

		virtual void OnCall() override
		{
			DECORATOR::DECOR_REGISTER("honor_block", 5);
			DECORATOR::DECOR_REGISTER("honor_bank", 5);
			DECORATOR::DECOR_REGISTER("honor_override", 5);

			int value = -500;

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

			STATS::STAT_ID_SET_INT(&honorStat, value, true); // Set to -500, value may differ but, works

			DECORATOR::DECOR_SET_INT(Self::GetPed().GetHandle(), "honor_override", value);

			GRAPHICS::ANIMPOSTFX_PLAY("PlayerHonorLevelBad");

			int newStatValue = 0;
			STATS::STAT_ID_GET_INT(&honorStat, &newStatValue);
			LOG(INFO) << "New Honor:" << newStatValue;
		}
	};

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

	static MinimumSPHonor _MinimumSPHonor{"minsphonor", "Min Honor", "Sets Arthur's honor to the minimum value"};
	static MinimumHonor _MinimumHonor{"minhonor", "Min Honor", "Sets the player's honor to the minimum value", 0, false};
	static MinimumHonorAll _MinimumHonorAll{"minhonorall", "Give All Min Honor", "Sets all player's honor to the minimum value"};
}