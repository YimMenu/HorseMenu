#pragma once
#include "game/hooks/Hooks.hpp"

namespace YimMenu::Hooks
{
	void Protections::SetTreeErrored(rage::netSyncTree* tree, bool errored)
	{
		if (errored)
			LOGF(SYNC, WARNING, "rage::netSyncTree::SetErrored called");
	}
}