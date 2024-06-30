#include "core/commands/BoolCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/player_database/PlayerDatabase.hpp"
#include "game/backend/Protections.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Nodes.hpp"

#include <network/CNetGamePlayer.hpp>
#include <network/netObject.hpp>
#include <network/rlGamerInfo.hpp>
#include <network/sync/CProjectBaseSyncDataNode.hpp>
#include <network/sync/object/CObjectCreationData.hpp>
#include <network/sync/ped/CPedAttachData.hpp>
#include <network/sync/ped/CPedCreationData.hpp>
#include <network/sync/ped/CPedTaskTreeData.hpp>
#include <network/sync/physical/CPhysicalAttachData.hpp>
#include <network/sync/pickup/CPickupCreationData.hpp>
#include <network/sync/player/CPlayerAppearanceData.hpp>
#include <network/sync/vehicle/CVehicleCreationData.hpp>
#include <network/sync/vehicle/CVehicleGadgetData.hpp>
#include <network/sync/vehicle/CVehicleProximityMigrationData.hpp>
#include <ped/CPed.hpp>
#include <unordered_set>


#define LOG_FIELD_H(type, field) LOG(INFO) << "\t" << #field << ": " << HEX((node->GetData<type>().field));
#define LOG_FIELD(type, field) LOG(INFO) << "\t" << #field << ": " << ((node->GetData<type>().field));
#define LOG_FIELD_C(type, field) LOG(INFO) << "\t" << #field << ": " << (int)((node->GetData<type>().field));
#define LOG_FIELD_B(type, field) LOG(INFO) << "\t" << #field << ": " << ((node->GetData<type>().field) ? "YES" : "NO");
#define LOG_FIELD_V3(type, field)                                               \
	LOG(INFO) << "\t" << #field << ": X: " << ((node->GetData<type>().field)).x \
	          << " Y: " << ((node->GetData<type>().field)).y << " Z: " << ((node->GetData<type>().field)).z;
#define LOG_FIELD_V4(type, field)                                                                           \
	LOG(INFO) << "\t" << #field << ": X: " << ((node->GetData<type>().field)).x                             \
	          << " Y: " << ((node->GetData<type>().field)).y << " Z: " << ((node->GetData<type>().field)).z \
	          << " W: " << ((node->GetData<type>().field)).w;
#define LOG_FIELD_APPLY(type, field, func) LOG(INFO) << "\t" << #field << ": " << func((node->GetData<type>().field));

namespace YimMenu::Features
{
	BoolCommand _LogClones("logclones", "Log Clones", "Log clone creates and clone syncs");
}

namespace
{
	using namespace YimMenu;

	void LogNode(CProjectBaseSyncDataNode* node, SyncNodeId id, eNetObjType type, rage::netObject* object)
	{
		if (!object)
			return; // TODO: log creation queue syncs

		if (Protections::GetSyncingPlayer().IsValid())
			LOG(INFO) << Protections::GetSyncingPlayer().GetName() << ": " << id.name << ", " << object->m_ObjectId;
		else
			LOG(INFO) << "UNKNOWN: " << id.name << object->m_ObjectId;

		switch (id)
		{
		case "CPedCreationDataNode"_J:
			LOG_FIELD(CPedCreationData, m_PopulationType);
			LOG_FIELD_H(CPedCreationData, m_ModelHash);
			LOG_FIELD_B(CPedCreationData, m_BannedPed);
			break;
		case "CObjectCreationDataNode"_J:
			LOG_FIELD(CObjectCreationData, m_ObjectType);
			LOG_FIELD_H(CObjectCreationData, m_ModelHash);
			break;
		case "CPlayerAppearanceDataNode"_J:
			LOG_FIELD_H(CPlayerAppearanceData, m_ModelHash);
			LOG_FIELD_B(CPlayerAppearanceData, m_BannedPlayerModel);
			break;
		case "CVehicleCreationDataNode"_J:
			LOG_FIELD(CVehicleCreationData, m_PopulationType);
			LOG_FIELD_H(CVehicleCreationData, m_ModelHash);
			break;
		case "CPickupCreationDataNode"_J:
			LOG_FIELD_H(CPickupCreationData, m_PickupHash);
			LOG_FIELD_H(CPickupCreationData, m_ModelHash);
			break;
		case "CPhysicalAttachDataNode"_J:
			LOG_FIELD_B(CPhysicalAttachData, m_IsAttached);
			LOG_FIELD(CPhysicalAttachData, m_AttachObjectId);
			LOG_FIELD_V3(CPhysicalAttachData, m_Offset);
			LOG_FIELD_V4(CPhysicalAttachData, m_Orientation);
			LOG_FIELD_V3(CPhysicalAttachData, m_ParentOffset);
			LOG_FIELD(CPhysicalAttachData, m_OtherAttachBone);
			LOG_FIELD(CPhysicalAttachData, m_AttachBone);
			LOG_FIELD(CPhysicalAttachData, m_AttachFlags);
			break;
		case "CVehicleProximityMigrationDataNode"_J:
			LOG_FIELD(CVehicleProximityMigrationData, m_NumPassengers);
			LOG_FIELD_B(CVehicleProximityMigrationData, m_OverridePopulationType);
			LOG_FIELD(CVehicleProximityMigrationData, m_PopulationType);
			LOG_FIELD(CVehicleProximityMigrationData, m_Flags);
			LOG_FIELD(CVehicleProximityMigrationData, m_Timestamp);
			LOG_FIELD_B(CVehicleProximityMigrationData, m_HasPositionData);
			LOG_FIELD_V3(CVehicleProximityMigrationData, m_Position);
			LOG_FIELD_V3(CVehicleProximityMigrationData, m_Velocity);
			LOG_FIELD(CVehicleProximityMigrationData, m_UnkAmount);
			break;
		case "CPedTaskTreeDataNode"_J:
			LOG_FIELD(CPedTaskTreeData, m_Trees[0].m_TreeType);
			for (int i = 0; i < node->GetData<CPedTaskTreeData>().GetNumTaskTrees(); i++)
			{
				LOG_FIELD(CPedTaskTreeData, m_Trees[i].m_NumTasks);
				LOG_FIELD_B(CPedTaskTreeData, m_Trees[i].m_SequenceTree);
				for (int j = 0; j < node->GetData<CPedTaskTreeData>().m_Trees[i].m_NumTasks; j++)
				{
					LOG_FIELD(CPedTaskTreeData, m_Trees[i].m_Tasks[j].m_TaskType);
				}
			}
			LOG_FIELD_H(CPedTaskTreeData, m_ScriptCommand);
			LOG_FIELD(CPedTaskTreeData, m_ScriptTaskStage);
			break;
		case "CPedAttachDataNode"_J:
			LOG_FIELD_B(CPedAttachData, m_IsAttached);
			LOG_FIELD(CPedAttachData, m_AttachObjectId);
			break;
		case "CVehicleGadgetDataNode"_J:
			LOG_FIELD_B(CVehicleGadgetNodeData, m_has_position);
			LOG_FIELD(CVehicleGadgetNodeData, m_position[0]);
			LOG_FIELD(CVehicleGadgetNodeData, m_position[1]);
			LOG_FIELD(CVehicleGadgetNodeData, m_position[2]);
			LOG_FIELD(CVehicleGadgetNodeData, m_position[3]);
			LOG_FIELD(CVehicleGadgetNodeData, m_num_gadgets);
			if (node->GetData<CVehicleGadgetNodeData>().m_num_gadgets <= 2)
			{
				for (int i = 0; i < node->GetData<CVehicleGadgetNodeData>().m_num_gadgets; i++)
				{
					LOG_FIELD(CVehicleGadgetNodeData, m_gadgets[i].m_type);
				}
			}
			break;
		}
	}

	std::unordered_set<uint32_t> g_CrashObjects = {0xD1641E60, 0x6927D266};
	std::unordered_set<uint32_t> g_FishModels   = {
        "A_C_Crawfish_01"_J,
        "A_C_FishBluegil_01_ms"_J,
        "A_C_FishBluegil_01_sm"_J,
        "A_C_FishBullHeadCat_01_ms"_J,
        "A_C_FishBullHeadCat_01_sm"_J,
        "A_C_FishChainPickerel_01_ms"_J,
        "A_C_FishChainPickerel_01_sm"_J,
        "A_C_FishChannelCatfish_01_lg"_J,
        "A_C_FishChannelCatfish_01_XL"_J,
        "A_C_FishLakeSturgeon_01_lg"_J,
        "A_C_FishLargeMouthBass_01_lg"_J,
        "A_C_FishLargeMouthBass_01_ms"_J,
        "A_C_FishLongNoseGar_01_lg"_J,
        "A_C_FishMuskie_01_lg"_J,
        "A_C_FishNorthernPike_01_lg"_J,
        "A_C_FishPerch_01_ms"_J,
        "A_C_FishPerch_01_sm"_J,
        "A_C_FishRainbowTrout_01_lg"_J,
        "A_C_FishRainbowTrout_01_ms"_J,
        "A_C_FishRedfinPickerel_01_ms"_J,
        "A_C_FishRedfinPickerel_01_sm"_J,
        "A_C_FishRockBass_01_ms"_J,
        "A_C_FishRockBass_01_sm"_J,
        "A_C_FishSalmonSockeye_01_lg"_J,
        "A_C_FishSalmonSockeye_01_ml"_J,
        "A_C_FishSalmonSockeye_01_ms"_J,
        "A_C_FishSmallMouthBass_01_lg"_J,
        "A_C_FishSmallMouthBass_01_ms"_J,
    };

	std::unordered_set<uint32_t> g_birdModels = {
	    "a_c_prairiechicken_01"_J,
	    "a_c_cormorant_01"_J,
	    "a_c_crow_01"_J,
	    "a_c_duck_01"_J,
	    "a_c_eagle_01"_J,
	    "a_c_goosecanada_01"_J,
	    "a_c_hawk_01"_J,
	    "a_c_owl_01"_J,
	    "a_c_pelican_01"_J,
	    "a_c_pigeon"_J,
	    "a_c_raven_01"_J,
	    "a_c_cardinal_01"_J,
	    "a_c_seagull_01"_J,
	    "a_c_songbird_01"_J,
	    "a_c_turkeywild_01"_J,
	    "a_c_turkey_01"_J,
	    "a_c_turkey_02"_J,
	    "a_c_vulture_01"_J,
	    "a_c_bluejay_01"_J,
	    "a_c_cedarwaxwing_01"_J,
	    "a_c_rooster_01"_J,
	    "mp_a_c_chicken_01"_J,
	    "a_c_chicken_01"_J,
	    "a_c_californiacondor_01"_J,
	    "a_c_cranewhooping_01"_J,
	    "a_c_egret_01"_J,
	    "a_c_heron_01"_J,
	    "a_c_loon_01"_J,
	    "a_c_oriole_01"_J,
	    "a_c_carolinaparakeet_01"_J,
	    "a_c_parrot_01"_J,
	    "a_c_pelican_01"_J,
	    "a_c_pheasant_01"_J,
	    "a_c_pigeon"_J,
	    "a_c_quail_01"_J,
	    "a_c_redfootedbooby_01"_J,
	    "a_c_robin_01"_J,
	    "a_c_roseatespoonbill_01"_J,
	    "a_c_seagull_01"_J,
	    "a_c_sparrow_01"_J,
	    "a_c_vulture_01"_J,
	    "a_c_woodpecker_01"_J,
	    "a_c_woodpecker_02"_J,
	};

	std::unordered_set<uint32_t> g_CageModels = {0x99C0CFCF, 0xF3D580D3, 0xEE8254F6, 0xC2D200FE};
	// note that object can be nullptr here if it hasn't been created yet (i.e. in the creation queue)
	bool ShouldBlockNode(CProjectBaseSyncDataNode* node, SyncNodeId id, eNetObjType type, rage::netObject* object)
	{
		switch (id)
		{
		case "CPedCreationDataNode"_J:
		{
			// this is a really bad protection, but it works
			auto& data = node->GetData<CPedCreationData>();
			if (/*data.m_PopulationType == 8 && */ data.m_ModelHash == "CS_MP_BOUNTYHUNTER"_J)
			{
				LOG(WARNING) << "Blocked possible unknown ped crash from " << Protections::GetSyncingPlayer().GetName();
				Notifications::Show("Protections",
				    std::string("Blocked possible unknown ped crash from ").append(Protections::GetSyncingPlayer().GetName()),
				    NotificationType::Warning);
				g_PlayerDatabase->AddInfraction(g_PlayerDatabase->GetOrCreatePlayer(Protections::GetSyncingPlayer().GetRID(),
				                                    Protections::GetSyncingPlayer().GetName()),
				    (int)PlayerDatabase::eInfraction::TRIED_CRASH_PLAYER);
				return true;
			}

			if (data.m_ModelHash && !STREAMING::IS_MODEL_A_PED(data.m_ModelHash))
			{
				LOG(WARNING) << "Blocked mismatched ped model crash from " << Protections::GetSyncingPlayer().GetName();
				Notifications::Show("Protections",
				    std::string("Blocked mismatched ped model crash from ").append(Protections::GetSyncingPlayer().GetName()),
				    NotificationType::Warning);
				g_PlayerDatabase->AddInfraction(g_PlayerDatabase->GetOrCreatePlayer(Protections::GetSyncingPlayer().GetRID(),
				                                    Protections::GetSyncingPlayer().GetName()),
				    (int)PlayerDatabase::eInfraction::TRIED_CRASH_PLAYER);
				return true;
			}
			break;
		}
		case "CObjectCreationDataNode"_J:
		{
			auto& data = node->GetData<CObjectCreationData>();
			if (g_CrashObjects.count(data.m_ModelHash))
			{
				LOG(WARNING) << "Blocked invalid object crash from " << Protections::GetSyncingPlayer().GetName();
				Notifications::Show("Protections",
				    std::string("Blocked invalid object crash from ").append(Protections::GetSyncingPlayer().GetName()),
				    NotificationType::Warning);
				g_PlayerDatabase->AddInfraction(g_PlayerDatabase->GetOrCreatePlayer(Protections::GetSyncingPlayer().GetRID(),
				                                    Protections::GetSyncingPlayer().GetName()),
				    (int)PlayerDatabase::eInfraction::TRIED_CRASH_PLAYER);
				return true;
			}
			if (data.m_ModelHash && !STREAMING::_IS_MODEL_AN_OBJECT(data.m_ModelHash))
			{
				LOG(WARNING) << "Blocked mismatched object model crash from " << Protections::GetSyncingPlayer().GetName();
				Notifications::Show("Protections",
				    std::string("Blocked mismatched object model crash from ").append(Protections::GetSyncingPlayer().GetName()),
				    NotificationType::Warning);
				g_PlayerDatabase->AddInfraction(g_PlayerDatabase->GetOrCreatePlayer(Protections::GetSyncingPlayer().GetRID(),
				                                    Protections::GetSyncingPlayer().GetName()),
				    (int)PlayerDatabase::eInfraction::TRIED_CRASH_PLAYER);
				return true;
			}
			if (g_CageModels.count(data.m_ModelHash))
			{
				LOG(WARNING) << "Blocked potential cage spawn from " << Protections::GetSyncingPlayer().GetName();
				Notifications::Show("Protections",
				    std::string("Blocked potential cage spawn from ").append(Protections::GetSyncingPlayer().GetName()),
				    NotificationType::Warning);
				return true;
			}
			break;
		}
		case "CPlayerAppearanceDataNode"_J:
		{
			auto& data = node->GetData<CPlayerAppearanceData>();
			if (data.m_ModelHash && !STREAMING::IS_MODEL_A_PED(data.m_ModelHash))
			{
				LOG(WARNING) << "Blocked mismatched player model crash from " << Protections::GetSyncingPlayer().GetName();
				Notifications::Show("Protections",
				    std::string("Blocked mismatched player model crash from ").append(Protections::GetSyncingPlayer().GetName()),
				    NotificationType::Warning);
				g_PlayerDatabase->AddInfraction(
				    g_PlayerDatabase->GetOrCreatePlayer(Protections::GetSyncingPlayer().GetGamerInfo()->m_GamerHandle.m_rockstar_id,
				        Protections::GetSyncingPlayer().GetName()),
				    (int)PlayerDatabase::eInfraction::TRIED_CRASH_PLAYER);
				return true;
			}

			if (data.m_ModelHash && (g_FishModels.count(data.m_ModelHash) || g_birdModels.count(data.m_ModelHash)))
			{
				LOG(WARNING) << "Blocked player model switch crash from " << Protections::GetSyncingPlayer().GetName();
				Notifications::Show("Protections",
				    std::string("Blocked player model switch crash from ").append(Protections::GetSyncingPlayer().GetName()),
				    NotificationType::Warning);
				g_PlayerDatabase->AddInfraction(
				    g_PlayerDatabase->GetOrCreatePlayer(Protections::GetSyncingPlayer().GetGamerInfo()->m_GamerHandle.m_rockstar_id,
				        Protections::GetSyncingPlayer().GetName()),
				    (int)PlayerDatabase::eInfraction::TRIED_CRASH_PLAYER);
				return true;
			}
			break;
		}
		case "CVehicleCreationDataNode"_J:
		{
			auto& data = node->GetData<CVehicleCreationData>();
			if (data.m_ModelHash && !STREAMING::IS_MODEL_A_VEHICLE(data.m_ModelHash))
			{
				LOG(WARNING) << "Blocked mismatched vehicle model crash from " << Protections::GetSyncingPlayer().GetName();
				Notifications::Show("Protections",
				    std::string("Blocked mismatched vehicle model crash from ").append(Protections::GetSyncingPlayer().GetName()),
				    NotificationType::Warning);
				g_PlayerDatabase->AddInfraction(
				    g_PlayerDatabase->GetOrCreatePlayer(Protections::GetSyncingPlayer().GetGamerInfo()->m_GamerHandle.m_rockstar_id,
				        Protections::GetSyncingPlayer().GetName()),
				    (int)PlayerDatabase::eInfraction::TRIED_CRASH_PLAYER);
				return true;
			}
			if (data.m_PopulationType == 8 && data.m_ModelHash == "SHIP_GUAMA02"_J)
			{
				LOG(WARNING) << "Blocked vehicle flood from " << Protections::GetSyncingPlayer().GetName();
				Notifications::Show("Protections",
				    std::string("Blocked vehicle flood from ").append(Protections::GetSyncingPlayer().GetName()),
				    NotificationType::Warning);
				return true;
			}
			break;
		}
		case "CPhysicalAttachDataNode"_J:
		{
			auto& data = node->GetData<CPhysicalAttachData>();
			if (auto local = Pointers.GetLocalPed(); local && local->m_NetObject)
			{
				if (data.m_IsAttached && data.m_AttachObjectId == local->m_NetObject->m_ObjectId)
				{
					LOG(WARNING) << "Blocked attachment from " << Protections::GetSyncingPlayer().GetName();
					Notifications::Show("Protections",
					    std::string("Blocked attachment from ").append(Protections::GetSyncingPlayer().GetName()),
					    NotificationType::Warning);
					g_PlayerDatabase->AddInfraction(g_PlayerDatabase->GetOrCreatePlayer(
					                                    Protections::GetSyncingPlayer().GetGamerInfo()->m_GamerHandle.m_rockstar_id,
					                                    Protections::GetSyncingPlayer().GetName()),
					    (int)PlayerDatabase::eInfraction::TRIED_ATTACH);
					return true;
				}

				if (data.m_IsAttached && object && object->m_ObjectType == (uint16_t)eNetObjType::Trailer)
				{
					LOG(WARNING) << "Blocked physical trailer attachment crash from " << Protections::GetSyncingPlayer().GetName();
					Notifications::Show("Protections",
					    std::string("Blocked physical trailer attachment crash from ")
					        .append(Protections::GetSyncingPlayer().GetName()),
					    NotificationType::Warning);
					return true;
				}
			}
			break;
		}
		case "CVehicleProximityMigrationDataNode"_J:
		{
			auto& data = node->GetData<CVehicleProximityMigrationData>();
			if (auto local = Pointers.GetLocalPed(); local && local->m_NetObject)
			{
				for (int i = 0; i < 17; i++)
				{
					if (data.m_PassengersActive[i] && data.m_PassengerObjectIds[i] == local->m_NetObject->m_ObjectId)
					{
						// TODO: add more checks
						LOG(WARNING) << "Blocked remote teleport from " << Protections::GetSyncingPlayer().GetName();
						Notifications::Show("Protections",
						    std::string("Blocked remote teleport from ")
						        .append(Protections::GetSyncingPlayer().GetName()),
						    NotificationType::Warning);
						g_PlayerDatabase->AddInfraction(
						    g_PlayerDatabase->GetOrCreatePlayer(
						        Protections::GetSyncingPlayer().GetGamerInfo()->m_GamerHandle.m_rockstar_id,
						        Protections::GetSyncingPlayer().GetName()),
						    (int)PlayerDatabase::eInfraction::REMOTE_TELEPORT);
						return true;
					}
				}
			}
			break;
		}
		case "CPedTaskTreeDataNode"_J:
		{
			auto& data = node->GetData<CPedTaskTreeData>();

			if (data.m_ScriptCommand == 0x2E85A751 && data.m_ScriptTaskStage == 1)
			{
				// TODO: really bad protection
				LOG(WARNING) << "Blocked unknown task crash from " << Protections::GetSyncingPlayer().GetName();
				return true;
			}

			break;
		}
		case "CPedAttachDataNode"_J:
		{
			auto& data = node->GetData<CPedAttachData>();
			if (auto local = Pointers.GetLocalPed(); local && local->m_NetObject)
			{
				if (data.m_IsAttached && data.m_AttachObjectId == local->m_NetObject->m_ObjectId)
				{
					LOG(WARNING) << "Blocked ped attachment from " << Protections::GetSyncingPlayer().GetName();
					Notifications::Show("Protections",
					    std::string("Blocked ped attachment from ").append(Protections::GetSyncingPlayer().GetName()),
					    NotificationType::Warning);
					g_PlayerDatabase->AddInfraction(g_PlayerDatabase->GetOrCreatePlayer(
					                                    Protections::GetSyncingPlayer().GetGamerInfo()->m_GamerHandle.m_rockstar_id,
					                                    Protections::GetSyncingPlayer().GetName()),
					    (int)PlayerDatabase::eInfraction::TRIED_ATTACH);
					return true;
				}

				if (data.m_IsAttached && object && object->m_ObjectType == (uint16_t)eNetObjType::Trailer)
				{
					LOG(WARNING) << "Blocked trailer ped attachment crash from " << Protections::GetSyncingPlayer().GetName();
					Notifications::Show("Protections",
					    std::string("Blocked trailer ped attachment crash from ").append(Protections::GetSyncingPlayer().GetName()),
					    NotificationType::Warning);
					return true;
				}
			}
			break;
		}
		case "CPropSetCreationDataNode"_J:
		{
			auto& data = node->GetData<int>();
			//"Rainbow smash crash" from Nightfall
			int64_t a2   = (int64_t)&data;
			Hash hash    = *(int32_t*)(a2 + 16);
			int32_t type = *(int32_t*)(a2 + 28);
			if (hash == 0x97D540A4 || hash == 0x3701844F || type == 0xFFFFFFFFFFFFFFFF)
			{
				LOG(WARNING) << "Blocked invalid propset from " << Protections::GetSyncingPlayer().GetName();
				Notifications::Show("Protections",
				    std::string("Blocked invalid propset from ").append(Protections::GetSyncingPlayer().GetName()),
				    NotificationType::Warning);
				g_PlayerDatabase->AddInfraction(
				    g_PlayerDatabase->GetOrCreatePlayer(Protections::GetSyncingPlayer().GetGamerInfo()->m_GamerHandle.m_rockstar_id,
				        Protections::GetSyncingPlayer().GetName()),
				    (int)PlayerDatabase::eInfraction::TRIED_CRASH_PLAYER);
				return true;
			}
			break;
		}
		}

		return false;
	}

	bool SyncNodeVisitor(CProjectBaseSyncDataNode* node, eNetObjType type, rage::netObject* object)
	{
		if (node->IsParentNode())
		{
			for (auto child = node->m_FirstChild; child; child = child->m_NextSibling)
			{
				if (SyncNodeVisitor(reinterpret_cast<CProjectBaseSyncDataNode*>(child), type, object))
					return true;
			}
		}
		else if (node->IsDataNode())
		{
			if (!node->IsActive())
				return false;

			if (YimMenu::Features::_LogClones.GetState())
				LogNode(node, Nodes::Find(type, (uint64_t)node), type, object);
			return ShouldBlockNode(node, Nodes::Find(type, (uint64_t)node), type, object);
		}

		return false;
	}
}

namespace YimMenu::Hooks::Protections
{
	bool ShouldBlockSync(rage::netSyncTree* tree, eNetObjType type, rage::netObject* object)
	{
		Nodes::Init();

		if (g_Running /*something getting nulled before last iteration*/ && tree->m_NodeCount && tree->m_NextSyncNode && SyncNodeVisitor(reinterpret_cast<CProjectBaseSyncDataNode*>(tree->m_NextSyncNode), type, object))
		{
			return true;
		}

		return false;
	}
}
