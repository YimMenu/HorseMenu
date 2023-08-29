#include "non_looped.hpp"
#include "../looped/self/SelfLooped.hpp"
#include "../../rdr/Natives.hpp"
#include "core/commands/FeatureCommand.hpp"

namespace YimMenu
{
	void non_looped::ClearCrimes()
	{
		LAW::CLEAR_PLAYER_PAST_CRIMES(Self::id);
		LAW::CLEAR_BOUNTY(Self::id);
		LAW::SET_BOUNTY(Self::id, 0);
		LAW::SET_PLAYER_TURNED_IN_BOUNTY_IN_REGION(Self::id, 0xA7A3F0C3);

		LOG(INFO) << "Bounty: " << LAW::GET_BOUNTY(Self::id);
	}

	static FeatureCommand command{"clearcrimes", "Clear Crimes", non_looped::ClearCrimes};
}