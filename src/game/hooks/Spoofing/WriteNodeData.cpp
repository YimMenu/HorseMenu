#include "core/commands/BoolCommand.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/backend/NodeHooks.hpp"
#include "game/backend/Self.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Nodes.hpp"

#include <network/netObject.hpp>
#include <network/sync/CProjectBaseSyncDataNode.hpp>
#include <rage/datBitBuffer.hpp>

namespace YimMenu::Features
{
	BoolCommand _LogOutgoingClones("logoutgoingclones", "Log Outgoing Clones", "Log clone creates and clone syncs");

}

namespace YimMenu::Hooks
{
	void Spoofing::WriteNodeData(CProjectBaseSyncDataNode* node, rage::netObject* object, rage::datBitBuffer* buffer, void* logger, bool update)
	{
		auto orig_buffer = *buffer;
		bool node_dirty  = false;
		Nodes::Init();
		auto& id = Nodes::Find(reinterpret_cast<uint64_t>(node));

		BaseHook::Get<Spoofing::WriteNodeData, DetourHook<decltype(&Spoofing::WriteNodeData)>>()->Original()(node, object, buffer, logger, update);

		if (update && Features::_LogOutgoingClones.GetState())
		{
			auto player = Self::GetPlayer();
			YimMenu::Hooks::Protections::LogSyncNode(node, id, static_cast<NetObjType>(object->m_ObjectType), object, player);
		}

		if (NodeHooks::ModifyNodeData(node, object))
			node_dirty = true;

		if (node_dirty)
		{
			*buffer = orig_buffer;
			BaseHook::Get<Spoofing::WriteNodeData, DetourHook<decltype(&Spoofing::WriteNodeData)>>()->Original()(node, object, buffer, logger, false);
		}
	}
}