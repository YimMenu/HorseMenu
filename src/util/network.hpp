#pragma once
#include "../../build/_deps/rdr_classes-src/entity/fwEntity.hpp"
#include "../../build/_deps/rdr_classes-src/network/netObject.hpp"
#include "common.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Network
{
	inline bool NetWorkHasControlOfNetObject(rage::netObject* net_object, int ent)
	{
		/*LOG(INFO) << "m_OwnerId: " << (int) net_object->m_OwnerId; 
		LOG(INFO) << "m_MigratingOwnerId: " << (int)net_object->m_MigratingOwnerId; 
		LOG(INFO) << "m_IsRemotelyControlled: " << (int)net_object->m_IsRemotelyControlled; 
		LOG(INFO) << "m_Unk: " << (int) net_object->m_Unk; 
		LOG(INFO) << "========================================================================"; */
		return !net_object->m_IsRemotelyControlled || NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(ent);
	}

	//Cannot get this to work (e.g for player mounts)
	inline bool RequestControlOfEntity(int ent, int timeout = 50)
	{
		if (!*Pointers.IsSessionStarted)
			return true;

		auto fwEntity = reinterpret_cast<rage::fwEntity*>(Pointers.HandleToPtr(ent));

		if (!fwEntity)
			return false;

		auto netObject = fwEntity->m_NetObject;

		if (!netObject)
			return false;

		if (NetWorkHasControlOfNetObject(netObject, ent))
			return true;

		for (int i = 0; i < timeout; i++)
		{
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(ent);
			NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netObject->m_ObjectId);
			Pointers.RequestControlOfNetObject(&netObject, false);

			if (NetWorkHasControlOfNetObject(netObject, ent))
				return true;

			ScriptMgr::Yield();
		}

		return NetWorkHasControlOfNetObject(netObject, ent);
	}
}