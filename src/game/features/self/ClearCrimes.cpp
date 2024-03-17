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
			char guid[0x20];
			BOUNTY::_BOUNTY_REQUEST_SERVED_FULL_JAIL_SENTENCE(guid);
			LAW::CLEAR_BOUNTY(guid);
			LAW::CLEAR_WANTED_SCORE(guid);
			LAW::CLEAR_PLAYER_PAST_CRIMES(guid);
		}
	};

	static ClearCrimes _ClearCrimes{"clearcrimes", "Clear Crimes", "Clears all crimes and removes all active bounties"};
}
