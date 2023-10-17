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
			DWORD test[7];
			BOUNTY::_BOUNTY_REQUEST_SERVED_FULL_JAIL_SENTENCE(&test);
		}
	};

	static ClearCrimes _ClearCrimes{"clearcrimes", "Clear Crimes", "Clears all crimes and removes all active bounties"};
}