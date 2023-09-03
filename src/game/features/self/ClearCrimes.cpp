#include "core/commands/Command.hpp"
#include "game/rdr/Natives.hpp"
#include "game/features/Features.hpp"

namespace YimMenu::Features
{
	class ClearCrimes : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			LAW::CLEAR_PLAYER_PAST_CRIMES(Self::Id); // does nothing
			LAW::CLEAR_BOUNTY(Self::Id); 
			LAW::SET_BOUNTY(Self::Id, 0); // does nothing
			PLAYER::CLEAR_PLAYER_WANTED_LEVEL(Self::Id); // does nothing
			LAW::CLEAR_WANTED_SCORE(Self::Id); // also does nothing

			LOG(INFO) << "Bounty: " << LAW::GET_BOUNTY(Self::Id);
		}
	};

	static ClearCrimes _ClearCrimes{"clearcrimes", "Clear Crimes", "Clears all crimes and removes all active bounties"};
}