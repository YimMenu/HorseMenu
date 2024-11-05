#include "core/commands/BoolCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/misc/RateLimiter.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/PlayerData.hpp"
#include "game/backend/Protections.hpp"
#include "game/backend/Self.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Network.hpp"
#include "game/rdr/Nodes.hpp"
#include "game/rdr/data/PedModels.hpp"

#include <network/CNetGamePlayer.hpp>
#include <network/netObject.hpp>
#include <network/rlGamerInfo.hpp>
#include <network/sync/CProjectBaseSyncDataNode.hpp>
#include <network/sync/animal/CAnimalCreationData.hpp>
#include <network/sync/object/CObjectCreationData.hpp>
#include <network/sync/ped/CPedAttachData.hpp>
#include <network/sync/ped/CPedCreationData.hpp>
#include <network/sync/ped/CPedTaskTreeData.hpp>
#include <network/sync/physical/CPhysicalAttachData.hpp>
#include <network/sync/pickup/CPickupCreationData.hpp>
#include <network/sync/player/CPlayerAppearanceData.hpp>
#include <network/sync/player/CPlayerCreationData.hpp>
#include <network/sync/player/CPlayerGameStateUncommonData.hpp>
#include <network/sync/projectile/CProjectileCreationData.hpp>
#include <network/sync/propset/CPropSetCreationData.hpp>
#include <network/sync/vehicle/CVehicleCreationData.hpp>
#include <network/sync/vehicle/CVehicleGadgetData.hpp>
#include <network/sync/vehicle/CVehicleProximityMigrationData.hpp>
#include <ped/CPed.hpp>
#include <rage/vector.hpp>

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
#define LOG_FIELD_UNDOCUM(num, type) \
	LOG(INFO) << "\tFIELD_" << #num << ": " << *(type*)((&node->GetData<char>()) + num);
#define LOG_FIELD_UNDOCUM_C(num, type) \
	LOG(INFO) << "\tFIELD_" << #num << ": " << (int)*(type*)((&node->GetData<char>()) + num);

namespace YimMenu::Hooks
{
	void Protections::LogSyncNode(CProjectBaseSyncDataNode* node, SyncNodeId& id, NetObjType type, rage::netObject* object, Player& player)
	{
		int object_id = -1;

		if (object)
			object_id = object->m_ObjectId;

		if (player.IsValid())
			LOG(INFO) << player.GetName() << ": " << id.name << ", " << object_id;
		else
			LOG(INFO) << "UNKNOWN: " << id.name << " " << object_id;

		switch (id)
		{
		case "CPedCreationNode"_J:
			LOG_FIELD(CPedCreationData, m_PopulationType);
			LOG_FIELD_H(CPedCreationData, m_ModelHash);
			LOG_FIELD_B(CPedCreationData, m_BannedPed);
			break;
		case "CAnimalCreationNode"_J:
			LOG_FIELD(CAnimalCreationData, m_PopulationType);
			LOG_FIELD_H(CAnimalCreationData, m_ModelHash);
			LOG_FIELD_B(CAnimalCreationData, m_BannedPed);
			break;
		case "CObjectCreationNode"_J:
			LOG_FIELD(CObjectCreationData, m_ObjectType);
			LOG_FIELD_H(CObjectCreationData, m_ModelHash);
			break;
		case "CPlayerAppearanceNode"_J:
			LOG_FIELD_H(CPlayerAppearanceData, m_ModelHash);
			LOG_FIELD_B(CPlayerAppearanceData, m_BannedPlayerModel);
			break;
		case "CVehicleCreationNode"_J:
			LOG_FIELD(CVehicleCreationData, m_PopulationType);
			LOG_FIELD_H(CVehicleCreationData, m_ModelHash);
			break;
		case "CPickupCreationNode"_J:
			LOG_FIELD_H(CPickupCreationData, m_PickupHash);
			LOG_FIELD_H(CPickupCreationData, m_ModelHash);
			break;
		case "CPhysicalAttachNode"_J:
			LOG_FIELD_B(CPhysicalAttachData, m_IsAttached);
			LOG_FIELD(CPhysicalAttachData, m_AttachObjectId);
			LOG_FIELD_V3(CPhysicalAttachData, m_Offset);
			LOG_FIELD_V4(CPhysicalAttachData, m_Orientation);
			LOG_FIELD_V3(CPhysicalAttachData, m_ParentOffset);
			LOG_FIELD(CPhysicalAttachData, m_OtherAttachBone);
			LOG_FIELD(CPhysicalAttachData, m_AttachBone);
			LOG_FIELD(CPhysicalAttachData, m_AttachFlags);
			break;
		case "CVehicleProximityMigrationNode"_J:
			LOG_FIELD(CVehicleProximityMigrationData, m_NumPassengers);
			LOG_FIELD_B(CVehicleProximityMigrationData, m_OverridePopulationType);
			LOG_FIELD(CVehicleProximityMigrationData, m_PopulationType);
			LOG_FIELD(CVehicleProximityMigrationData, m_Flags);
			LOG_FIELD(CVehicleProximityMigrationData, m_Timestamp);
			LOG_FIELD_B(CVehicleProximityMigrationData, m_HasPositionData);
			LOG_FIELD_V3(CVehicleProximityMigrationData, m_Position);
			LOG_FIELD(CVehicleProximityMigrationData, m_UnkAmount);
			break;
		case "CPedTaskTreeNode"_J:
			LOG_FIELD(CPedTaskTreeData, m_Trees[0].m_TreeType);
			for (int i = 0; i < node->GetData<CPedTaskTreeData>().GetNumTaskTrees(); i++)
			{
				LOG_FIELD(CPedTaskTreeData, m_Trees[i].m_NumTasks);
				LOG_FIELD_B(CPedTaskTreeData, m_Trees[i].m_SequenceTree);
				for (int j = 0; j < node->GetData<CPedTaskTreeData>().m_Trees[i].m_NumTasks; j++)
				{
					LOG_FIELD(CPedTaskTreeData, m_Trees[i].m_Tasks[j].m_TaskType);
					LOG_FIELD(CPedTaskTreeData, m_Trees[i].m_Tasks[j].m_TaskUnk1);
					LOG_FIELD(CPedTaskTreeData, m_Trees[i].m_Tasks[j].m_TaskTreeType);
					LOG_FIELD(CPedTaskTreeData, m_Trees[i].m_Tasks[j].m_TaskSequenceId);
					LOG_FIELD(CPedTaskTreeData, m_Trees[i].m_Tasks[j].m_TaskTreeDepth);
				}
			}
			LOG_FIELD_H(CPedTaskTreeData, m_ScriptCommand);
			LOG_FIELD(CPedTaskTreeData, m_ScriptTaskStage);
			break;
		case "CPedAttachNode"_J:
			LOG_FIELD_B(CPedAttachData, m_IsAttached);
			LOG_FIELD(CPedAttachData, m_AttachObjectId);
			break;
		case "CVehicleGadgetNode"_J:
			LOG_FIELD_B(CVehicleGadgetData, m_HasPosition);
			LOG_FIELD(CVehicleGadgetData, m_Position[0]);
			LOG_FIELD(CVehicleGadgetData, m_Position[1]);
			LOG_FIELD(CVehicleGadgetData, m_Position[2]);
			LOG_FIELD(CVehicleGadgetData, m_Position[3]);
			LOG_FIELD(CVehicleGadgetData, m_NumGadgets);
			if (node->GetData<CVehicleGadgetData>().m_NumGadgets <= 2)
			{
				for (int i = 0; i < node->GetData<CVehicleGadgetData>().m_NumGadgets; i++)
				{
					LOG_FIELD(CVehicleGadgetData, m_Gadgets[i].m_Type);
				}
			}
			break;
		case "CPropSetCreationNode"_J:
			LOG_FIELD_H(CPropSetCreationData, m_Hash);
			LOG_FIELD_H(CPropSetCreationData, m_Type);
			break;
		case "CProjectileCreationNode"_J:
			LOG_FIELD_UNDOCUM(4, int);
			LOG_FIELD_UNDOCUM(8, int);
			LOG_FIELD_UNDOCUM(0x2C, int);
			break;
		case "CTrainGameStateUncommonNode"_J:
			LOG_FIELD_UNDOCUM(0, int);
			LOG_FIELD_UNDOCUM(4, int);
			LOG_FIELD_UNDOCUM(8, int);
			LOG_FIELD_UNDOCUM_C(12, char); // config index
			LOG_FIELD_UNDOCUM_C(13, char);
			LOG_FIELD_UNDOCUM_C(14, char);
			LOG_FIELD_UNDOCUM_C(15, char);
			LOG_FIELD_UNDOCUM_C(16, char);
			LOG_FIELD_UNDOCUM_C(17, char);
			LOG_FIELD_UNDOCUM_C(18, char);
			LOG_FIELD_UNDOCUM_C(19, char);
			LOG_FIELD_UNDOCUM_C(20, char);
			LOG_FIELD_UNDOCUM_C(21, char);
			LOG_FIELD_UNDOCUM_C(22, char);
			LOG_FIELD_UNDOCUM_C(23, char);
			LOG_FIELD_UNDOCUM_C(24, char);
			break;
		case "CTrainGameStateNode"_J:
			LOG_FIELD_UNDOCUM(0, int);
			LOG_FIELD_UNDOCUM(4, int);
			LOG_FIELD_UNDOCUM(8, int);
			LOG_FIELD_UNDOCUM(12, int);
			LOG_FIELD_UNDOCUM(16, int);
			LOG_FIELD_UNDOCUM(20, int);
			LOG_FIELD_UNDOCUM(24, int); // whistle sequence
			LOG_FIELD_UNDOCUM_C(28, char);
			LOG_FIELD_UNDOCUM_C(29, char);
			LOG_FIELD_UNDOCUM_C(30, char); // track index?
			LOG_FIELD_UNDOCUM_C(31, char);
			LOG_FIELD_UNDOCUM_C(32, char);
			LOG_FIELD_UNDOCUM_C(33, char);
			LOG_FIELD_UNDOCUM_C(34, char);
			LOG_FIELD_UNDOCUM_C(35, char);
			LOG_FIELD_UNDOCUM_C(36, char);
			LOG_FIELD_UNDOCUM_C(37, char);
			LOG_FIELD_UNDOCUM_C(38, char);
			LOG_FIELD_UNDOCUM_C(39, char);
			LOG_FIELD_UNDOCUM_C(40, char);
			break;
		case "CTrainControlNode"_J:
			LOG_FIELD_UNDOCUM(160, float);
			LOG_FIELD_UNDOCUM_C(164, char);
			break;
		case "CAnimSceneCreationNode"_J:
			LOG_FIELD_UNDOCUM(0, int);
			LOG_FIELD_UNDOCUM(4, int);
			LOG_FIELD_UNDOCUM(8, int);
			LOG_FIELD_UNDOCUM(12, int);
			LOG_FIELD_UNDOCUM_C(16, char);
			//LOG_FIELD_UNDOCUM(32, __int128);
			//LOG_FIELD_UNDOCUM(48, __int128);
			//LOG_FIELD_UNDOCUM(64, __int128);
			//LOG_FIELD_UNDOCUM(80, __int128);
			//LOG_FIELD_UNDOCUM(96, __int128);
			LOG_FIELD_UNDOCUM(112, int16_t);
			LOG_FIELD_UNDOCUM(114, int16_t);
			break;
		case "CAnimSceneFrequentNode"_J:
			LOG_FIELD_UNDOCUM(0, int);
			LOG_FIELD_UNDOCUM_C(4, char);
			LOG_FIELD_UNDOCUM(8, int);
			LOG_FIELD_UNDOCUM(12, int);
			break;
		case "CAnimSceneInfrequentNode"_J:
			LOG_FIELD_UNDOCUM(16, int);
			LOG_FIELD_UNDOCUM_C(20, char);
			LOG_FIELD_UNDOCUM(24, int16_t);
			LOG_FIELD_UNDOCUM_C(26, char);
			LOG_FIELD_UNDOCUM(32, int64_t);
			LOG_FIELD_UNDOCUM(40, int64_t);
			break;
		case "CPedGameStateCommonNode"_J:
			LOG_FIELD_UNDOCUM(0, int);
			LOG_FIELD_UNDOCUM(4, int);
			LOG_FIELD_UNDOCUM(8, int);
			LOG_FIELD_UNDOCUM(12, int);
			LOG_FIELD_UNDOCUM(16, int);
			LOG_FIELD_UNDOCUM(20, float);
			LOG_FIELD_UNDOCUM(24, float);
			LOG_FIELD_UNDOCUM(28, float);
			LOG_FIELD_UNDOCUM(32, float);
			LOG_FIELD_UNDOCUM(36, float);
			LOG_FIELD_UNDOCUM_C(40, char);
			LOG_FIELD_UNDOCUM(44, int);
			LOG_FIELD_UNDOCUM_C(48, char);
			LOG_FIELD_UNDOCUM_C(50, char);
			LOG_FIELD_UNDOCUM_C(51, char);
			LOG_FIELD_UNDOCUM_C(52, char);
			LOG_FIELD_UNDOCUM_C(53, char);
			LOG_FIELD_UNDOCUM_C(54, char);
			LOG_FIELD_UNDOCUM_C(55, char);
			break;
		case "CPedSectorPosMapNode"_J:
			LOG_FIELD_UNDOCUM(0, float);
			LOG_FIELD_UNDOCUM(4, float);
			LOG_FIELD_UNDOCUM(8, float);
			LOG_FIELD_UNDOCUM_C(12, bool); // using ragdoll?
			LOG_FIELD_UNDOCUM_C(13, char);
			break;
		case "CPedSectorPosNavMeshNode"_J:
			LOG_FIELD_UNDOCUM(0, float);
			LOG_FIELD_UNDOCUM(4, float);
			LOG_FIELD_UNDOCUM(8, float);
			break;
		case "CPedMovementNode"_J:
			LOG_FIELD_UNDOCUM(32, int);
			LOG_FIELD_UNDOCUM(44, int);
			LOG_FIELD_UNDOCUM(64, float);
			LOG_FIELD_UNDOCUM(68, int);
			LOG_FIELD_UNDOCUM(72, int);
			LOG_FIELD_UNDOCUM(76, int);
			LOG_FIELD_UNDOCUM(80, int);
			LOG_FIELD_UNDOCUM(84, int);
			LOG_FIELD_UNDOCUM(88, int);
			LOG_FIELD_UNDOCUM_C(92, char);
			LOG_FIELD_UNDOCUM_C(97, char);
			break;
		case "CDraftVehControlNode"_J:
			LOG_FIELD_UNDOCUM(32, int);
			LOG_FIELD_UNDOCUM(36, int);
			LOG_FIELD_UNDOCUM(40, int);
			LOG_FIELD_UNDOCUM(44, int);
			LOG_FIELD_UNDOCUM(48, int);
			LOG_FIELD_UNDOCUM_C(52, char);
			LOG_FIELD_UNDOCUM_C(53, char);
			LOG_FIELD_UNDOCUM_C(54, char);
			LOG_FIELD_UNDOCUM(56, int);
			LOG_FIELD_UNDOCUM(60, int);
			break;
		case "Node_14359d020"_J:
			//LOG_FIELD_UNDOCUM(16, OWORD);
			//LOG_FIELD_UNDOCUM(32, OWORD);
			//LOG_FIELD_UNDOCUM(48, OWORD);
			LOG_FIELD_UNDOCUM(64, int);
			LOG_FIELD_UNDOCUM(100, int);
			LOG_FIELD_UNDOCUM(140, int);
			//LOG_FIELD_UNDOCUM(160, __m128i);
			LOG_FIELD_UNDOCUM(176, int16_t);
			LOG_FIELD_UNDOCUM(178, int16_t);
			LOG_FIELD_UNDOCUM(180, int16_t);
			LOG_FIELD_UNDOCUM(184, int);
			LOG_FIELD_UNDOCUM(188, int);
			LOG_FIELD_UNDOCUM(196, int);
			LOG_FIELD_UNDOCUM(200, int);
			LOG_FIELD_UNDOCUM(204, int);
			LOG_FIELD_UNDOCUM(208, int);
			LOG_FIELD_UNDOCUM(212, int);
			LOG_FIELD_UNDOCUM(216, int);
			LOG_FIELD_UNDOCUM_C(220, char);
			LOG_FIELD_UNDOCUM_C(221, char);
			LOG_FIELD_UNDOCUM_C(222, char);
			LOG_FIELD_UNDOCUM_C(223, char);
			LOG_FIELD_UNDOCUM_C(224, char);
			LOG_FIELD_UNDOCUM_C(225, char);
			LOG_FIELD_UNDOCUM_C(226, char);
			LOG_FIELD_UNDOCUM(356, int);
			LOG_FIELD_UNDOCUM(360, int);
			LOG_FIELD_UNDOCUM(364, int);
			LOG_FIELD_UNDOCUM(368, int);
			LOG_FIELD_UNDOCUM(216, int);
			LOG_FIELD_UNDOCUM(372, int);
			LOG_FIELD_UNDOCUM(376, int);
			break;
		case "CVehicleControlNode"_J:
			LOG_FIELD_UNDOCUM(4, int);
			LOG_FIELD_UNDOCUM(8, int);
			LOG_FIELD_UNDOCUM(12, int);
			LOG_FIELD_UNDOCUM(16, int);
			LOG_FIELD_UNDOCUM(20, int);
			LOG_FIELD_UNDOCUM_C(24, char);
			LOG_FIELD_UNDOCUM_C(25, char);
			LOG_FIELD_UNDOCUM_C(26, char);
			LOG_FIELD_UNDOCUM_C(27, char);
			break;
		case "CVehicleAngVelocityNode"_J:
			LOG_FIELD_UNDOCUM(0, int);
			LOG_FIELD_UNDOCUM(4, int);
			LOG_FIELD_UNDOCUM(8, int);
			LOG_FIELD_UNDOCUM_C(12, char);
			break;
		case "CDraftVehHorseHealthNode"_J:
			LOG_FIELD_UNDOCUM_C(158, char);
			LOG_FIELD_UNDOCUM_C(656, char);
			break;
		case "CVehicleGameStateNode"_J:
			LOG_FIELD_UNDOCUM_C(1, char);
			LOG_FIELD_UNDOCUM_C(2, char);
			LOG_FIELD_UNDOCUM_C(3, char);
			LOG_FIELD_UNDOCUM_C(4, char);
			LOG_FIELD_UNDOCUM_C(5, char);
			LOG_FIELD_UNDOCUM(8, int);
			LOG_FIELD_UNDOCUM(12, int);
			LOG_FIELD_UNDOCUM(16, int);
			LOG_FIELD_UNDOCUM(20, int);
			LOG_FIELD_UNDOCUM(24, int);
			LOG_FIELD_UNDOCUM(28, int);
			LOG_FIELD_UNDOCUM(32, int);
			LOG_FIELD_UNDOCUM(36, int);
			LOG_FIELD_UNDOCUM(40, int);
			LOG_FIELD_UNDOCUM(44, int16_t);
			LOG_FIELD_UNDOCUM(46, int16_t);
			LOG_FIELD_UNDOCUM(50, int16_t);
			LOG_FIELD_UNDOCUM(52, int16_t);
			LOG_FIELD_UNDOCUM_C(54, char);
			LOG_FIELD_UNDOCUM(55, int);
			LOG_FIELD_UNDOCUM(59, int16_t);
			LOG_FIELD_UNDOCUM_C(61, char);
			LOG_FIELD_UNDOCUM_C(62, char);
			LOG_FIELD_UNDOCUM_C(63, char);
			LOG_FIELD_UNDOCUM_C(104, char);
			LOG_FIELD_UNDOCUM_C(105, char);
			LOG_FIELD_UNDOCUM_C(106, char);
			LOG_FIELD_UNDOCUM_C(107, char);
			LOG_FIELD_UNDOCUM_C(108, char);
			LOG_FIELD_UNDOCUM_C(109, char);
			LOG_FIELD_UNDOCUM_C(110, char);
			LOG_FIELD_UNDOCUM_C(111, char);
			LOG_FIELD_UNDOCUM_C(112, char);
			LOG_FIELD_UNDOCUM_C(114, char);
			LOG_FIELD_UNDOCUM_C(115, char);
			LOG_FIELD_UNDOCUM_C(116, char);
			LOG_FIELD_UNDOCUM_C(117, char);
			LOG_FIELD_UNDOCUM_C(118, char);
			LOG_FIELD_UNDOCUM_C(119, char);
			LOG_FIELD_UNDOCUM_C(120, char);
			LOG_FIELD_UNDOCUM_C(121, char);
			LOG_FIELD_UNDOCUM_C(123, char);
			LOG_FIELD_UNDOCUM_C(124, char);
			LOG_FIELD_UNDOCUM_C(125, char);
			LOG_FIELD_UNDOCUM_C(126, char);
			LOG_FIELD_UNDOCUM_C(127, char);
			LOG_FIELD_UNDOCUM_C(128, char);
			LOG_FIELD_UNDOCUM_C(129, char);
			LOG_FIELD_UNDOCUM_C(130, char);
			LOG_FIELD_UNDOCUM_C(131, char); // has seat manager
			LOG_FIELD_UNDOCUM_C(132, char); // depends on the value of tunable 0xF03033E4
			break;
		case "CPedStandingOnObjectNode"_J:
			LOG_FIELD_UNDOCUM_C(0, int16_t);
			LOG_FIELD_UNDOCUM(16, float); // also __m128i, not sure
			LOG_FIELD_UNDOCUM(20, float);
			LOG_FIELD_UNDOCUM(24, float);
			LOG_FIELD_UNDOCUM(32, int);
			LOG_FIELD_UNDOCUM(36, int);
			LOG_FIELD_UNDOCUM(40, int);
			LOG_FIELD_UNDOCUM_C(44, char);
			LOG_FIELD_UNDOCUM_C(45, char);
			break;
		case "Node_143594ab8"_J:
			LOG_FIELD_UNDOCUM_C(0, char);
			LOG_FIELD_UNDOCUM_C(1, char);
			LOG_FIELD_UNDOCUM_C(2, char);
			LOG_FIELD_UNDOCUM_C(3, char);
			LOG_FIELD_UNDOCUM_C(4, char);
			LOG_FIELD_UNDOCUM_C(5, char);
			LOG_FIELD_UNDOCUM_C(6, char);
			LOG_FIELD_UNDOCUM_C(7, char);
			LOG_FIELD_UNDOCUM_C(8, char);
			LOG_FIELD_UNDOCUM_C(9, char);
			LOG_FIELD_UNDOCUM(12, int);
			LOG_FIELD_UNDOCUM(16, int);
			LOG_FIELD_UNDOCUM(20, int);
			break;
		case "CVehicleScriptGameStateNode"_J:
			LOG_FIELD_UNDOCUM_C(96, char);
			LOG_FIELD_UNDOCUM_C(97, char);
			LOG_FIELD_UNDOCUM_C(98, char);
			LOG_FIELD_UNDOCUM_C(99, char);
			LOG_FIELD_UNDOCUM_C(100, char);
			LOG_FIELD_UNDOCUM_C(101, char);
			LOG_FIELD_UNDOCUM_C(102, char);
			LOG_FIELD_UNDOCUM_C(103, char);
			LOG_FIELD_UNDOCUM_C(104, char);
			LOG_FIELD_UNDOCUM_C(105, char);
			LOG_FIELD_UNDOCUM_C(106, char);
			LOG_FIELD_UNDOCUM_C(107, char);
			LOG_FIELD_UNDOCUM_C(108, char);
			LOG_FIELD_UNDOCUM_C(109, char);
			LOG_FIELD_UNDOCUM_C(110, char);
			LOG_FIELD_UNDOCUM_C(111, char);
			LOG_FIELD_UNDOCUM_C(112, char);
			LOG_FIELD_UNDOCUM_C(113, char);
			LOG_FIELD_UNDOCUM_C(114, char);
			LOG_FIELD_UNDOCUM_C(115, char);
			LOG_FIELD_UNDOCUM_C(116, char);
			LOG_FIELD_UNDOCUM_C(117, char);
			LOG_FIELD_UNDOCUM_C(118, char);
			LOG_FIELD_UNDOCUM_C(119, char);
			LOG_FIELD_UNDOCUM_C(120, char);
			LOG_FIELD_UNDOCUM_C(121, char);
			LOG_FIELD_UNDOCUM_C(122, char);
			LOG_FIELD_UNDOCUM(124, int32_t);
			LOG_FIELD_UNDOCUM(128, int16_t);
			LOG_FIELD_UNDOCUM(132, int32_t);
			LOG_FIELD_UNDOCUM(136, int32_t);
			LOG_FIELD_UNDOCUM_C(140, char);
			LOG_FIELD_UNDOCUM_C(141, char);
			LOG_FIELD_UNDOCUM_C(142, char);
			break;
		case "CPhysicalGameState"_J:
			LOG_FIELD_UNDOCUM_C(0, char);
			LOG_FIELD_UNDOCUM_C(1, char);
			LOG_FIELD_UNDOCUM_C(2, char);
			LOG_FIELD_UNDOCUM_C(3, char);
			LOG_FIELD_UNDOCUM_C(4, char);
			LOG_FIELD_UNDOCUM_C(5, char);
			LOG_FIELD_UNDOCUM_C(6, char);
			LOG_FIELD_UNDOCUM_C(7, char);
			LOG_FIELD_UNDOCUM_C(8, char);
			LOG_FIELD_UNDOCUM_C(9, char);
			LOG_FIELD_UNDOCUM(12, int32_t);
			LOG_FIELD_UNDOCUM(16, int32_t);
			LOG_FIELD_UNDOCUM(20, int32_t);
			break;
		case "CEntityScriptGameStateNode"_J:
			LOG_FIELD_UNDOCUM_C(0, char);
			LOG_FIELD_UNDOCUM_C(1, char);
			LOG_FIELD_UNDOCUM_C(2, char);
			break;
		case "CPedScriptGameStateUncommonNode"_J:
			LOG_FIELD_UNDOCUM(16, int32_t);
			LOG_FIELD_UNDOCUM_C(27, char);
			LOG_FIELD_UNDOCUM(32, int32_t);
			LOG_FIELD_UNDOCUM(36, int16_t);
			LOG_FIELD_UNDOCUM(38, int32_t);
			LOG_FIELD_UNDOCUM_C(40, char);
			LOG_FIELD_UNDOCUM_C(41, char);
			LOG_FIELD_UNDOCUM_C(42, char);
			LOG_FIELD_UNDOCUM_C(43, char);
			break;
		case "CPedEmotionalLocoNode"_J:
			LOG_FIELD_UNDOCUM_C(0, char);
			LOG_FIELD_UNDOCUM(4, int32_t);
			LOG_FIELD_UNDOCUM(12, int32_t); // some pointer
			break;
		case "CPropSetGameStateNode"_J:
			LOG_FIELD_UNDOCUM_C(1, char);
			LOG_FIELD_UNDOCUM_C(91, char);
			LOG_FIELD_UNDOCUM_C(181, char);
			LOG_FIELD_UNDOCUM(272, int32_t);
			LOG_FIELD_UNDOCUM_C(276, char);
			LOG_FIELD_UNDOCUM_C(277, char);
			break;
		case "CPlayerGameStateUncommonNode"_J:
			LOG_FIELD_UNDOCUM_C(0, char);
			LOG_FIELD_UNDOCUM_C(1, char);
			LOG_FIELD_UNDOCUM_C(2, char);
			LOG_FIELD_UNDOCUM_C(3, char);
			LOG_FIELD_UNDOCUM_C(4, char);
			LOG_FIELD_UNDOCUM_C(5, char);
			LOG_FIELD_UNDOCUM_C(6, char);
			LOG_FIELD_UNDOCUM_C(7, char);
			LOG_FIELD_UNDOCUM_C(8, char);
			LOG_FIELD_UNDOCUM(76, int64_t);
			LOG_FIELD_UNDOCUM(84, int32_t);
			LOG_FIELD_UNDOCUM(88, int16_t);
			LOG_FIELD_UNDOCUM(92, int32_t);
			LOG_FIELD_UNDOCUM_C(96, char);
			LOG_FIELD_UNDOCUM_C(97, char);
			LOG_FIELD_UNDOCUM(98, int16_t);
			LOG_FIELD_UNDOCUM_C(100, char);
			LOG_FIELD_UNDOCUM_C(101, char);
			LOG_FIELD_UNDOCUM(104, int32_t);
			LOG_FIELD_UNDOCUM(108, int32_t);
			LOG_FIELD_UNDOCUM(112, int32_t);
			LOG_FIELD_UNDOCUM(116, float);
			LOG_FIELD_UNDOCUM(120, int16_t);
			LOG_FIELD_UNDOCUM(144, int16_t);
			LOG_FIELD_UNDOCUM(146, int16_t);
			LOG_FIELD_UNDOCUM_C(148, char);
			LOG_FIELD_UNDOCUM_C(149, char);
			LOG_FIELD_UNDOCUM_C(150, char);
			LOG_FIELD_UNDOCUM_C(151, char);
			LOG_FIELD_UNDOCUM_C(152, char);
			LOG_FIELD_UNDOCUM_C(153, char);
			LOG_FIELD_UNDOCUM_C(154, char);
			LOG_FIELD_UNDOCUM_C(155, char);
			break;
		case "CPhysicalGameStateNode"_J:
			LOG_FIELD_UNDOCUM_C(0, char);
			LOG_FIELD_UNDOCUM_C(1, char);
			LOG_FIELD_UNDOCUM_C(2, char);
			LOG_FIELD_UNDOCUM_C(3, char);
			LOG_FIELD_UNDOCUM_C(4, char);
			LOG_FIELD_UNDOCUM_C(5, char);
			LOG_FIELD_UNDOCUM_C(6, char);
			LOG_FIELD_UNDOCUM_C(7, char);
			LOG_FIELD_UNDOCUM_C(8, char);
			LOG_FIELD_UNDOCUM_C(9, char);
			LOG_FIELD_UNDOCUM(12, int32_t);
			LOG_FIELD_UNDOCUM(16, int32_t);
			LOG_FIELD_UNDOCUM(20, int32_t);
			break;
		case "CDynamicEntityGameStateNode"_J:
			LOG_FIELD_UNDOCUM(0, int32_t);
			LOG_FIELD_UNDOCUM_C(4, char);
			LOG_FIELD_UNDOCUM(8, int32_t);
			LOG_FIELD_UNDOCUM(12, int64_t);
			break;
		case "CPedInteractionNode"_J:
			LOG_FIELD_UNDOCUM(0, int16_t);
			LOG_FIELD_UNDOCUM(2, int16_t);
			LOG_FIELD_UNDOCUM(4, int32_t);
			LOG_FIELD_UNDOCUM(8, int32_t);
			LOG_FIELD_UNDOCUM(12, int32_t);
			LOG_FIELD_UNDOCUM(16, int32_t);
			LOG_FIELD_UNDOCUM(28, int32_t);
			LOG_FIELD_UNDOCUM(32, int32_t);
			LOG_FIELD_UNDOCUM(36, int32_t);
			LOG_FIELD_UNDOCUM(40, int32_t);
			LOG_FIELD_UNDOCUM(44, int16_t);
			LOG_FIELD_UNDOCUM(48, int16_t);
			LOG_FIELD_UNDOCUM_C(50, char);
			LOG_FIELD_UNDOCUM_C(51, char);
			break;
		case "CPhysicalScriptGameStateNode"_J:
			LOG_FIELD_UNDOCUM_C(0, char);
			LOG_FIELD_UNDOCUM_C(1, char);
			LOG_FIELD_UNDOCUM_C(2, char);
			LOG_FIELD_UNDOCUM_C(3, char);
			LOG_FIELD_UNDOCUM_C(4, char);
			LOG_FIELD_UNDOCUM_C(5, char);
			LOG_FIELD_UNDOCUM_C(6, char);
			LOG_FIELD_UNDOCUM_C(7, char);
			LOG_FIELD_UNDOCUM_C(8, char);
			LOG_FIELD_UNDOCUM_C(9, char);
			LOG_FIELD_UNDOCUM_C(10, char);
			LOG_FIELD_UNDOCUM_C(11, char);
			LOG_FIELD_UNDOCUM_C(12, char);
			LOG_FIELD_UNDOCUM_C(13, char);
			LOG_FIELD_UNDOCUM_C(14, char);
			LOG_FIELD_UNDOCUM_C(15, char);
			LOG_FIELD_UNDOCUM_C(16, char);
			LOG_FIELD_UNDOCUM(20, int32_t);
			LOG_FIELD_UNDOCUM(24, int32_t);
			LOG_FIELD_UNDOCUM(28, float);
			LOG_FIELD_UNDOCUM(32, int32_t);
			break;
		case "CEntityScriptInfoNode"_J:
			LOG_FIELD_UNDOCUM_C(0, char);
			//LOG_FIELD_UNDOCUM_C(8, void*);
			LOG_FIELD_UNDOCUM_C(64, char);
			LOG_FIELD_UNDOCUM(68, int32_t);
			//LOG_FIELD_UNDOCUM(72, __m128i);
			LOG_FIELD_UNDOCUM(312, int32_t);
			break;
		case "CDoorDamageNode"_J:
			LOG_FIELD_UNDOCUM(0, int32_t);
			LOG_FIELD_UNDOCUM(4, int64_t);  // oword
			LOG_FIELD_UNDOCUM(20, int64_t); // oword
			break;
		case "CPedOrientationNode"_J:
			LOG_FIELD_UNDOCUM(0, float);
			LOG_FIELD_UNDOCUM(4, float);
			LOG_FIELD_UNDOCUM_C(8, char);
			LOG_FIELD_UNDOCUM_C(9, char);
			break;
		case "CPedWeaponNode"_J:
			LOG_FIELD_UNDOCUM(4, int16_t);
			LOG_FIELD_UNDOCUM_C(6, char);
			LOG_FIELD_UNDOCUM_C(7, char);
			LOG_FIELD_UNDOCUM(8, int);
			LOG_FIELD_UNDOCUM(476, int32_t);
			LOG_FIELD_UNDOCUM(480, int32_t);
			LOG_FIELD_UNDOCUM(484, int32_t);
			LOG_FIELD_UNDOCUM(488, int32_t);
			LOG_FIELD_UNDOCUM_C(492, char);
			LOG_FIELD_UNDOCUM_C(493, char);
			LOG_FIELD_UNDOCUM_C(494, char);
			LOG_FIELD_UNDOCUM_C(495, char);
			LOG_FIELD_UNDOCUM_C(496, char);
			LOG_FIELD_UNDOCUM_C(497, char);
			LOG_FIELD_UNDOCUM_C(498, char);
			LOG_FIELD_UNDOCUM_C(799, char);
			// untested
			LOG_FIELD_UNDOCUM(16, int64_t);
			LOG_FIELD_UNDOCUM(24, int32_t);
			LOG_FIELD_UNDOCUM(32, int16_t);
			LOG_FIELD_UNDOCUM(40, int32_t);
			break;
		case "CPedInventoryNode"_J:
			LOG_FIELD_UNDOCUM(4000, int);
			LOG_FIELD_UNDOCUM(4080, int);
			LOG_FIELD_UNDOCUM(4084, int);
			LOG_FIELD_UNDOCUM(4184, int);
			LOG_FIELD_UNDOCUM(4284, int);
			LOG_FIELD_UNDOCUM_C(4288, char);
			LOG_FIELD_UNDOCUM_C(4308, char);
			LOG_FIELD_UNDOCUM_C(4328, char);
			LOG_FIELD_UNDOCUM_C(5328, char);
			LOG_FIELD_UNDOCUM_C(5353, char);
			break;
		case "Node_14359d660"_J:
			LOG_FIELD_UNDOCUM(36, uint32_t);
			for (int i = 0; i < 16; i++)
			{
				LOG_FIELD_UNDOCUM(36 * i + 56, uint32_t);
				LOG_FIELD_UNDOCUM(36 * i + 60, uint32_t);
				LOG_FIELD_UNDOCUM(36 * i + 64, uint32_t);
				LOG_FIELD_UNDOCUM(36 * i + 68, uint32_t);
				LOG_FIELD_UNDOCUM(36 * i + 72, uint32_t);
			}
			break;
		case "CDraftVehGameStateNode"_J: 
			LOG_FIELD_UNDOCUM_C(0, char);
			LOG_FIELD_UNDOCUM_C(1, char);
			LOG_FIELD_UNDOCUM_C(2, char);
			LOG_FIELD_UNDOCUM_C(3, char);
			LOG_FIELD_UNDOCUM_C(4, char);
			break;
		case "CPhysicalHealthNode"_J:
			LOG_FIELD_UNDOCUM(0, int);
			LOG_FIELD_UNDOCUM(4, int);
			LOG_FIELD_UNDOCUM(8, int16_t);
			LOG_FIELD_UNDOCUM(10, int);
			LOG_FIELD_UNDOCUM(16, int);
			LOG_FIELD_UNDOCUM_C(20, char);
			LOG_FIELD_UNDOCUM_C(21, char);
			break;
		case "Node_143599c30"_J:
			LOG_FIELD_UNDOCUM(80, int);
			LOG_FIELD_UNDOCUM_C(84, char);
			LOG_FIELD_UNDOCUM_C(85, char);
			break;
		case "CAutomobileCreationNode"_J:
			LOG_FIELD_UNDOCUM_C(0, char);
			for (int i = 0; i < 10; ++i)
			{
				LOG_FIELD_UNDOCUM(14 + i, int);
			}
			LOG_FIELD_UNDOCUM(24, int);
			break;
		case "CDraftVehCreationNodeThing"_J:
			LOG_FIELD_UNDOCUM(0, int);
			LOG_FIELD_UNDOCUM_C(48, char);
			break;
		}
	}
}