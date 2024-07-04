#include "core/commands/Command.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class ClearCrimes : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			char guid[0x20];
			BOUNTY::_BOUNTY_REQUEST_SERVED_FULL_JAIL_SENTENCE(guid);
		}
	};

	static ClearCrimes _ClearCrimes{"clearcrimes", "Remove Bounties", "Removes all active bounties"};
}
