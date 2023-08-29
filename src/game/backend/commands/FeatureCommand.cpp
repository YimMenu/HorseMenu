#include "FeatureCommand.hpp"
#include "../FiberPool.hpp"
#include "game/rdr/Natives.hpp"
#include "util/Joaat.hpp"

namespace YimMenu
{
	void FeatureCommand::Call()
	{
		if (hotkey_listener)
			return;

		feature_function();
	}
}