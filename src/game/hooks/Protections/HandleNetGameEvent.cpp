#include "core/commands/BoolCommand.hpp"
#include "core/hooking/DetourHook.hpp"
#include "core/player_database/PlayerDatabase.hpp"
#include "game/backend/Protections.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"

#include <network/CNetGamePlayer.hpp>
#include <network/netObject.hpp>
#include <network/rlGamerInfo.hpp>
#include <rage/datBitBuffer.hpp>


namespace
{
	bool IsVehicleType(NetObjType type)
	{
		switch (type)
		{
		case NetObjType::Automobile:
		case NetObjType::Bike:
		case NetObjType::Heli:
		case NetObjType::DraftVeh:
		case NetObjType::Boat: return true;
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
	static void LogScriptCommandEvent(Player sender, rage::datBitBuffer& buffer)
	{
		struct ScriptCommandEventData
		{
			bool Active;
			int NumParams;
			std::uint64_t Hash;
			std::uint32_t ScriptHash;
		} datas[7]{};

		std::uint32_t parameters[255]{};

		auto net_id = buffer.Read<uint16_t>(13);
		auto count  = buffer.Read<int>(3);
		int total_params = 0;

		for (int i = 0; i < count; i++)
		{
			datas[i].Hash = buffer.Read<uint64_t>(64);
			datas[i].NumParams = buffer.Read<uint32_t>(5);
			datas[i].ScriptHash = buffer.Read<uint32_t>(32);
			total_params += datas[i].NumParams;
		}

		for (int i = 0; i < total_params; i++)
		{
			int size = 1;
			bool one = buffer.Read<bool>(1);
			if (!one)
				size = buffer.Read<int>(7);
			parameters[i] = buffer.Read<uint64_t>(size);
		}

		int global_param_access = 0;
		for (int i = 0; i < count; i++)
		{
			std::ostringstream data;
			data << HEX(datas[i].Hash) << "(";
			for (int j = 0; j < datas[i].NumParams; j++)
			{
				data << std::to_string(parameters[global_param_access]);
				global_param_access++;
				if (j != datas[i].NumParams - 1)
					data << ", ";
			}
			data << ");";
			LOG(WARNING) << sender.GetName() << " tried to execute " << data.str();
		}
	}

	void Protections::HandleNetGameEvent(rage::netEventMgr* eventMgr, CNetGamePlayer* sourcePlayer, CNetGamePlayer* targetPlayer, NetEventType type, int index, int handledBits, std::int16_t unk, rage::datBitBuffer* buffer)
	{
		rage::datBitBuffer new_buffer = *buffer;

		if (Features::_LogEvents.GetState() && type < NetEventType::NETWORK_EVENT_MAX)
		{
			LOG(INFO) << "NETWORK_EVENT: " << g_NetEventsToString[(int)type] << " from " << sourcePlayer->GetName();
		}

		if (sourcePlayer == targetPlayer) // why does this happen?
		{
			LOG(WARNING) << "NETWORK_EVENT: " << g_NetEventsToString[(int)type] << " from " << sourcePlayer->GetName() << ", which is ourselves?!?!";
		}

		if (type == NetEventType::NETWORK_DESTROY_VEHICLE_LOCK_EVENT)
		{
			auto net_id = new_buffer.Read<uint16_t>(13);
			if (auto object = Pointers.GetNetObjectById(net_id))
			{
				if (!IsVehicleType((NetObjType)object->m_ObjectType))
				{
					LOG(WARNING) << "Blocked mismatched NETWORK_DESTROY_VEHICLE_LOCK_EVENT entity from " << sourcePlayer->GetName();
					Pointers.SendEventAck(eventMgr, nullptr, sourcePlayer, targetPlayer, index, handledBits);
					return;
				}
			}
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
			LogScriptCommandEvent(sourcePlayer, new_buffer);
			LOG(WARNING) << "Blocked remote native call from " << sourcePlayer->GetName();
			Pointers.SendEventAck(eventMgr, nullptr, sourcePlayer, targetPlayer, index, handledBits);
			g_PlayerDatabase->AddInfraction(
			    g_PlayerDatabase->GetOrCreatePlayer(sourcePlayer->GetGamerInfo()->m_GamerHandle.m_RockstarId),
			    (int)PlayerDatabase::eInfraction::REMOTE_NATIVE_CALL);
			return;
		}

		// breaks game sync
		#if 0
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

		if (type == NetEventType::EXPLOSION_EVENT && sourcePlayer)
		{
			LOG(WARNING) << "Blocked Explosion from " << sourcePlayer->GetName();
			Pointers.SendEventAck(eventMgr, nullptr, sourcePlayer, targetPlayer, index, handledBits);
			return;
		}

		if (type == NetEventType::LIGHTNING_EVENT && sourcePlayer)
		{
			LOG(WARNING) << "Blocked Lightning from " << sourcePlayer->GetName();
			Pointers.SendEventAck(eventMgr, nullptr, sourcePlayer, targetPlayer, index, handledBits);
			return;
		}
		#endif

		if (type == NetEventType::GIVE_CONTROL_EVENT && sourcePlayer)
		{
			YimMenu::Protections::SetSyncingPlayer(sourcePlayer);
		}

		BaseHook::Get<Protections::HandleNetGameEvent, DetourHook<decltype(&Protections::HandleNetGameEvent)>>()->Original()(eventMgr, sourcePlayer, targetPlayer, type, index, handledBits, unk, buffer);
	}
}