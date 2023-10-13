#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Nodes.hpp"
#include "game/rdr/Natives.hpp"
#include "game/backend/Protections.hpp"
#include "core/commands/BoolCommand.hpp"

#include <network/CNetGamePlayer.hpp>
#include <network/netObject.hpp>
#include <network/sync/CProjectBaseSyncDataNode.hpp>
#include <network/sync/object/CObjectCreationData.hpp>
#include <network/sync/ped/CPedCreationData.hpp>
#include <network/sync/ped/CPedTaskTreeData.hpp>
#include <network/sync/physical/CPhysicalAttachData.hpp>
#include <network/sync/pickup/CPickupCreationData.hpp>
#include <network/sync/player/CPlayerAppearanceData.hpp>
#include <network/sync/vehicle/CVehicleCreationData.hpp>
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
		}
	}

	std::unordered_set<uint32_t> g_CrashObjects = {0xD1641E60};

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
				return true;
			}

			if (data.m_ModelHash && !STREAMING::IS_MODEL_A_PED(data.m_ModelHash))
			{
				LOG(WARNING) << "Blocked mismatched ped model crash from " << Protections::GetSyncingPlayer().GetName();
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
				return true;
			}
			if (data.m_ModelHash && !STREAMING::_IS_MODEL_AN_OBJECT(data.m_ModelHash))
			{
				LOG(WARNING) << "Blocked mismatched object model crash from " << Protections::GetSyncingPlayer().GetName();
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
				return true;
			}
			if (data.m_PopulationType == 8 && data.m_ModelHash == "SHIP_GUAMA02"_J)
			{
				LOG(WARNING) << "Blocked vehicle flood from " << Protections::GetSyncingPlayer().GetName();
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

		if (tree->m_NodeCount && tree->m_NextSyncNode && SyncNodeVisitor(reinterpret_cast<CProjectBaseSyncDataNode*>(tree->m_NextSyncNode), type, object))
		{
			return true;
		}

		return false;
	}
}