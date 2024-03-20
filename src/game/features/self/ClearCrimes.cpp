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
			BOUNTY::_BOUNTY_REQUEST_PAY_OFF_BOUNTY(guid); // Pays bounty from your wallet like visiting the post clerk
		}
	};

	static ClearCrimes _ClearCrimes{"clearcrimes", "Pay Bounties", "Pays all active bounties (Like a mobile post clerk)"};
}
