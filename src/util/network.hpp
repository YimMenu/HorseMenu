#pragma once
#include "common.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

// TODO: remove this file

namespace YimMenu::Network
{
	inline bool NetWorkHasControlEntity(int ent)
	{
		return NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(ent);
	}

	//Won't work on player mounts
	inline bool RequestControlOfEntity(int ent, int timeout = 100)
	{
		if (!*Pointers.IsSessionStarted)
			return true;

		if (NetWorkHasControlEntity(ent))
			return true;

		for (int i = 0; i < timeout; i++)
		{
			if (NetWorkHasControlEntity(ent))
				return true;
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(ent);

			ScriptMgr::Yield();
		}

		return NetWorkHasControlEntity(ent);
	}
}