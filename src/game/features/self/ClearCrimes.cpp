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
			//Crashes??
			// Any _0{};
			// BOUNTY::_BOUNTY_REQUEST_SERVED_FULL_JAIL_SENTENCE(&_0);
		}
	};

	static ClearCrimes _ClearCrimes{"clearcrimes", "Clear Crimes", "Clears all crimes and removes all active bounties"};
}