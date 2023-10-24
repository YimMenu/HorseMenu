#pragma once
#include "game/backend/FiberPool.hpp"
#include "game/rdr/Natives.hpp"
#include "common.hpp"
#include "../../build/_deps/rdr_classes-src/network/netObject.hpp"
#include "../../build/_deps/rdr_classes-src/entity/fwEntity.hpp"
#include "game/backend/ScriptMgr.hpp"

namespace YimMenu::Network
{
	inline bool NetWorkHasControlOfNetObject(rage::netObject* net_object)
	{
		return !net_object || !net_object->m_IsRemotelyControlled;
	}

	//Won't work on player mounts, not tested on anything else
	inline bool RequestControlOfEntity(int ent, int timeout = 300)
	{
		if (!*Pointers.IsSessionStarted)
			return true;

		auto fwEntity = reinterpret_cast<rage::fwEntity*>(Pointers.HandleToPtr);

		if (!fwEntity)
			return false;

		auto netObject = fwEntity->m_NetObject;

		if (!netObject || !*Pointers.IsSessionStarted)
			return false;

		if (NetWorkHasControlOfNetObject(netObject))
			return true;

		for (int i = 0; i < timeout; i++)
		{
			Pointers.RequestControlOfNetObject(netObject, true);
			
			if (NetWorkHasControlOfNetObject(netObject))
				return true;
			ScriptMgr::Yield();
		}

		return NetWorkHasControlOfNetObject(netObject);
	}
}