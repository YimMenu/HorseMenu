#include <unordered_set>

#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Nodes.hpp"
#include "game/rdr/Natives.hpp"
#include "game/backend/Protections.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/BoolCommand.hpp"
#include "util/Joaat.hpp"

#include <network/CNetGamePlayer.hpp>
#include <network/netObject.hpp>
#include <network/sync/CProjectBaseSyncDataNode.hpp>
#include <network/sync/object/CObjectCreationData.hpp>
#include <network/sync/ped/CPedCreationData.hpp>
#include <network/sync/player/CPlayerAppearanceData.hpp>

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

namespace
{
	using namespace YimMenu;

	void LogNode(CProjectBaseSyncDataNode* node, SyncNodeId id, rage::netObject* object)
	{
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
		}
	}

	std::unordered_set<uint32_t> g_CrashObjects = {0xD1641E60};

	bool ShouldBlockNode(CProjectBaseSyncDataNode* node, SyncNodeId id, rage::netObject* object)
	{
		switch (id)
		{
		case "CPedCreationDataNode"_J: 
		{
			// this is a really bad protection, but it works
			auto& data = node->GetData<CPedCreationData>();
			if (data.m_PopulationType == 8 && data.m_ModelHash == "CS_MP_BOUNTYHUNTER"_J)
			{
				LOG(WARNING) << "Blocked possible unknown ped crash from " << Protections::GetSyncingPlayer().GetName();
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
		}

		return false;
	}

	bool SyncNodeVisitor(CProjectBaseSyncDataNode* node, rage::netObject* object)
	{
		if (node->IsParentNode())
		{
			for (auto child = node->m_FirstChild; child; child = child->m_NextSibling)
			{
				if (SyncNodeVisitor(reinterpret_cast<CProjectBaseSyncDataNode*>(child), object))
					return true;
			}
		}
		else if (node->IsDataNode())
		{
			if (!node->IsActive())
				return false;

			static auto cmd = Commands::GetCommand<BoolCommand>("keepcoresfilled"_J); // TODO
			if (cmd->GetState())
				LogNode(node, Nodes::Find((eNetObjType)object->m_ObjectType, (uint64_t)node), object);
			return ShouldBlockNode(node, Nodes::Find((eNetObjType)object->m_ObjectType, (uint64_t)node), object);
		}

		return false;
	}

	bool ShouldBlockSync(rage::netSyncTree* tree, rage::netObject* object)
	{
		if (tree->m_NodeCount && tree->m_NextSyncNode && SyncNodeVisitor(reinterpret_cast<CProjectBaseSyncDataNode*>(tree->m_NextSyncNode), object))
		{
			return true;
		}

		return false;
	}
}

namespace YimMenu::Hooks
{
	bool Protections::CanApplyData(rage::netSyncTree* tree, rage::netObject* object)
	{
		Nodes::Init();

		if (!BaseHook::Get<Protections::CanApplyData, DetourHook<decltype(&Protections::CanApplyData)>>()->Original()(tree, object))
			return false;

		if (ShouldBlockSync(tree, object))
			return false;

		return true;
	}
}