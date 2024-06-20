#include "core/commands/BoolCommand.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/backend/Protections.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"

#include <network/CNetGamePlayer.hpp>
#include <network/netObject.hpp>
#include <rage/datBitBuffer.hpp>


namespace
{
	bool IsVehicleType(eNetObjType type)
	{
		switch (type)
		{
		case eNetObjType::Automobile:
		case eNetObjType::Bike:
		case eNetObjType::Heli:
		case eNetObjType::DraftVeh:
		case eNetObjType::Boat: return true;
		}

		return false;
	}
}

namespace YimMenu::Features
{
	BoolCommand _LogEvents("logevents", "Log Network Events", "Log network events");
}

namespace YimMenu::Hooks
{
	void Protections::HandleNetGameEvent(rage::netEventMgr* eventMgr, CNetGamePlayer* sourcePlayer, CNetGamePlayer* targetPlayer, NetEventType type, int index, int handledBits, std::int16_t unk, rage::datBitBuffer* buffer)
	{
		rage::datBitBuffer new_buffer = *buffer;

		if (Features::_LogEvents.GetState() && type < NetEventType::NETWORK_EVENT_MAX)
		{
			LOG(INFO) << "NETWORK_EVENT: " << g_NetEventsToString[(int)type] << " from " << sourcePlayer->GetName();
		}

		if (type == NetEventType::NETWORK_DESTROY_VEHICLE_LOCK_EVENT)
		{
			auto net_id = new_buffer.Read<uint16_t>(13);
			if (auto object = Pointers.GetNetObjectById(net_id))
			{
				if (!IsVehicleType((eNetObjType)object->m_ObjectType))
				{
					LOG(WARNING) << "Blocked mismatched NETWORK_DESTROY_VEHICLE_LOCK_EVENT entity from " << sourcePlayer->GetName();
					Pointers.SendEventAck(eventMgr, nullptr, sourcePlayer, targetPlayer, index, handledBits);
					return;
				}
			}
		}

		if (type == NetEventType::NETWORK_INCREMENT_STAT_EVENT && sourcePlayer)
		{
			LOG(WARNING) << "Blocked report from " << sourcePlayer->GetName();
			Pointers.SendEventAck(eventMgr, nullptr, sourcePlayer, targetPlayer, index, handledBits);
			return;
		}

		if (type == NetEventType::NETWORK_PTFX_EVENT && sourcePlayer)
		{
			LOG(WARNING) << "Blocked NETWORK_PTFX_EVENT from " << sourcePlayer->GetName();
			Pointers.SendEventAck(eventMgr, nullptr, sourcePlayer, targetPlayer, index, handledBits);
			return;
		}

		if (type == NetEventType::NETWORK_CLEAR_PED_TASKS_EVENT && sourcePlayer)
		{
			LOG(WARNING) << "Blocked NETWORK_CLEAR_PED_TASKS_EVENT from " << sourcePlayer->GetName();
			Pointers.SendEventAck(eventMgr, nullptr, sourcePlayer, targetPlayer, index, handledBits);
			return;
		}

		if (type == NetEventType::SCRIPT_COMMAND_EVENT && sourcePlayer)
		{
			LOG(WARNING) << "Blocked remote native call from " << sourcePlayer->GetName();
			Pointers.SendEventAck(eventMgr, nullptr, sourcePlayer, targetPlayer, index, handledBits);
			return;
		}

		if (type == NetEventType::GIVE_PED_SCRIPTED_TASK_EVENT && sourcePlayer)
		{
			LOG(WARNING) << "Blocked Remote Ped Animation from " << sourcePlayer->GetName();
			Pointers.SendEventAck(eventMgr, nullptr, sourcePlayer, targetPlayer, index, handledBits);
			return;
		}

		if (type == NetEventType::GIVE_PED_SEQUENCE_TASK_EVENT && sourcePlayer)
		{
			LOG(WARNING) << "Blocked Remote Ped Animation from " << sourcePlayer->GetName();
			Pointers.SendEventAck(eventMgr, nullptr, sourcePlayer, targetPlayer, index, handledBits);
			return;
		}

		if (type == NetEventType::GIVE_CONTROL_EVENT && sourcePlayer)
		{
			YimMenu::Protections::SetSyncingPlayer(sourcePlayer);
		}

		BaseHook::Get<Protections::HandleNetGameEvent, DetourHook<decltype(&Protections::HandleNetGameEvent)>>()->Original()(eventMgr, sourcePlayer, targetPlayer, type, index, handledBits, unk, buffer);
	}
}