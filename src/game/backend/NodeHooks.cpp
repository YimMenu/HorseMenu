#include "NodeHooks.hpp"

#include <network/netObject.hpp>

namespace YimMenu
{
	NodeHooks::Hook::Hook(SyncNodeId node, std::function<bool(rage::netObject* object, Player target)> inScope, std::function<void(rage::netObject* object, Player target, CProjectBaseSyncDataNode* node)> modifyFunc, bool perPlayer, bool forceInScope) :
	    m_Node(node),
	    m_InScopeCallback(inScope),
	    m_Callback(modifyFunc),
	    m_PerPlayer(perPlayer),
	    m_ForceInScope(forceInScope),
	    m_Enabled(false)
	{
	}

	void NodeHooks::Hook::Enable()
	{
		m_Enabled = true;
	}

	void NodeHooks::Hook::Disable()
	{
		m_Enabled = false;
	}

	std::shared_ptr<NodeHooks::Hook> NodeHooks::TryGetHook(CProjectBaseSyncDataNode* node)
	{
		auto object = GetSyncingObject();

		if (!Nodes::IsInitialized())
			return nullptr;

		auto& node_id = Nodes::Find(reinterpret_cast<uint64_t>(node));

		if (auto it = m_Hooks.find(node_id); it != m_Hooks.end() && it->second->m_Enabled && it->second->m_InScopeCallback(object, it->second->m_PerPlayer ? GetSyncingPlayer() : nullptr))
			return it->second;

		return nullptr;
	}

	rage::netObject* NodeHooks::GetSyncingObject()
	{
		std::lock_guard lock(m_Mutex);
		if (auto it = m_SyncingObjects.find(GetCurrentThreadId()); it != m_SyncingObjects.end())
			return it->second;

		return nullptr;
	}

	Player NodeHooks::GetSyncingPlayer()
	{
		std::lock_guard lock(m_Mutex);
		if (auto it = m_SyncingPlayers.find(GetCurrentThreadId()); it != m_SyncingPlayers.end())
			return it->second;

		return nullptr;
	}

	std::shared_ptr<NodeHooks::Hook> NodeHooks::AddHookImpl(SyncNodeId node, std::function<bool(rage::netObject* object, Player target)> inScope, std::function<void(rage::netObject* object, Player target, CProjectBaseSyncDataNode* node)> modifyFunc, bool perPlayer, bool forceInScope)
	{
		auto hook = std::make_shared<Hook>(node, inScope, modifyFunc, perPlayer, forceInScope);
		m_Hooks.emplace(node, std::move(hook));
		return m_Hooks[node];
	}

	bool NodeHooks::ShouldSkipNodeCacheImpl(CProjectBaseSyncDataNode* node)
	{
		if (auto hook = TryGetHook(node))
			return hook->m_PerPlayer;

		return false;
	}

	bool NodeHooks::ShouldForceInScopeImpl(CProjectBaseSyncDataNode* node)
	{
		if (auto hook = TryGetHook(node))
			return hook->m_ForceInScope;

		return false;
	}

	bool NodeHooks::ModifyNodeDataImpl(CProjectBaseSyncDataNode* node, rage::netObject* object)
	{
		SetSyncingObjectImpl(object);
		if (auto hook = TryGetHook(node))
		{
			hook->m_Callback(object, GetSyncingPlayer(), node);
			return true;
		}

		return false;
	}

	void NodeHooks::SetSyncingObjectImpl(rage::netObject* object)
	{
		std::lock_guard lock(m_Mutex);
		if (auto it = m_SyncingObjects.find(GetCurrentThreadId()); it != m_SyncingObjects.end())
			it->second = object;
		else
			m_SyncingObjects.emplace(GetCurrentThreadId(), object);
	}

	void NodeHooks::SetSyncingPlayerImpl(Player player)
	{
		std::lock_guard lock(m_Mutex);
		if (auto it = m_SyncingPlayers.find(GetCurrentThreadId()); it != m_SyncingPlayers.end())
			it->second = player;
		else
			m_SyncingPlayers.emplace(GetCurrentThreadId(), player);
	}
}