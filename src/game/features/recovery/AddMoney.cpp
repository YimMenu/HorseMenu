#include "core/commands/Command.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::Features
{
	class GiveStoryCash : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			// Give the player $10,000, the added 0's are cents.  Ex: 1000000 = $10,000.00
			MONEY::_MONEY_INCREMENT_CASH_BALANCE(1000000, 0);
		}
	};

	static GiveStoryCash _GiveStoryCash{"givestorycash", "Add Cash", "Adds $10,000 to Arthurs cash"};
}