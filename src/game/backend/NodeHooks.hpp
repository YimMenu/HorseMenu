#pragma once
#include "game/rdr/Nodes.hpp"
#include "game/rdr/Player.hpp"
#include "util/Joaat.hpp"

#include <network/sync/CProjectBaseSyncDataNode.hpp>

namespace rage
{
	class scrProgram;
}

namespace YimMenu
{
	class NodeHooks
	{
	public:
		struct Hook
		{
			SyncNodeId m_Node;
			std::function<bool(rage::netObject* object, Player target)> m_InScopeCallback;
			std::function<void(rage::netObject* object, Player target, CProjectBaseSyncDataNode* node)> m_Callback;
			bool m_PerPlayer;
			bool m_ForceInScope;
			bool m_Enabled;

			Hook(SyncNodeId node, std::function<bool(rage::netObject* object, Player target)> inScope, std::function<void(rage::netObject* object, Player target, CProjectBaseSyncDataNode* node)> modifyFunc, bool perPlayer = false, bool forceInScope = false);
			void Enable();
			void Disable();
		};

		static std::shared_ptr<Hook> AddHook(SyncNodeId node, std::function<bool(rage::netObject* object, Player target)> inScope, std::function<void(rage::netObject* object, Player target, CProjectBaseSyncDataNode* node)> modifyFunc, bool perPlayer = false, bool forceInScope = false)
		{
			return GetInstance().AddHookImpl(node, inScope, modifyFunc, perPlayer, forceInScope);
		}

		static bool ShouldSkipNodeCache(CProjectBaseSyncDataNode* node)
		{
			return GetInstance().ShouldSkipNodeCacheImpl(node);
		}

		static bool ShouldForceInScope(CProjectBaseSyncDataNode* node)
		{
			return GetInstance().ShouldForceInScopeImpl(node);
		}

		static bool ModifyNodeData(CProjectBaseSyncDataNode* node, rage::netObject* object)
		{
			return GetInstance().ModifyNodeDataImpl(node, object);
		}

		static void SetSyncingObject(rage::netObject* object)
		{
			GetInstance().SetSyncingObjectImpl(object);
		}

		static void SetSyncingPlayer(Player player)
		{
			GetInstance().SetSyncingPlayerImpl(player);
		}

	private:
		static NodeHooks& GetInstance()
		{
			static NodeHooks Instance;
			return Instance;
		}

		std::shared_ptr<Hook> TryGetHook(CProjectBaseSyncDataNode* node);
		rage::netObject* GetSyncingObject();
		Player GetSyncingPlayer();

		std::shared_ptr<Hook> AddHookImpl(SyncNodeId node, std::function<bool(rage::netObject* object, Player target)> inScope, std::function<void(rage::netObject* object, Player target, CProjectBaseSyncDataNode* node)> modifyFunc, bool perPlayer = false, bool forceInScope = false);
		bool ShouldSkipNodeCacheImpl(CProjectBaseSyncDataNode* node);
		bool ShouldForceInScopeImpl(CProjectBaseSyncDataNode* node);
		bool ModifyNodeDataImpl(CProjectBaseSyncDataNode* node, rage::netObject* object);
		void SetSyncingObjectImpl(rage::netObject* object);
		void SetSyncingPlayerImpl(Player player);

		std::mutex m_Mutex;
		std::unordered_map<SyncNodeId, std::shared_ptr<Hook>> m_Hooks;
		std::unordered_map<int, rage::netObject*> m_SyncingObjects;
		std::unordered_map<int, Player> m_SyncingPlayers;
	};
}