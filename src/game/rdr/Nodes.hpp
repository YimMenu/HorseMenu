#pragma once
#include "Enums.hpp"
#include "util/Joaat.hpp"

#include <network/sync/netSyncTree.hpp>
#include <rage/joaat.hpp>

// Taken from https://github.com/YimMenu/YimMenu/blob/207e5457f9fca9e638168b1f26ec210116d7ad7d/src/util/sync_trees.hpp
// Credits to Aure7138

namespace YimMenu
{
	struct SyncNodeId
	{
		rage::joaat_t id;
		const char* name;

		constexpr SyncNodeId()
		{
			id   = 0;
			name = "INVALID NODE ID!";
		}

		template<size_t N>
		constexpr SyncNodeId(char const (&pp)[N])
		{
			id   = Joaat(pp);
			name = pp;
		}

		// implicit conversion
		constexpr operator rage::joaat_t() const
		{
			return id;
		}
	};

	// Sync Node Virtual Function Table address to all sync node identifiers that also have that vft address.
	using SyncNodeVftToIds = std::unordered_map<uint64_t, SyncNodeId>;

	// Sync Tree node array index to node identifier.
	using SyncTreeNodeArrayIndexToNodeId = std::vector<SyncNodeId>;

	struct SyncNodeFinder
	{
		static constexpr size_t sm_SyncTreeCount = size_t(eNetObjType::Max);

		std::array<SyncNodeVftToIds, sm_SyncTreeCount> m_SyncTressSyncNodeAddrToIds;
		std::array<SyncTreeNodeArrayIndexToNodeId, sm_SyncTreeCount> m_SyncTreeNodeIdsMap;

		SyncNodeFinder();
	};

	class Nodes
	{
	private:
		SyncNodeFinder m_Finder;
		bool m_Initialized = false;
		std::mutex m_InitMutex;

		SyncNodeId& FindImpl(eNetObjType obj_type, uintptr_t addr);
		SyncNodeVftToIds& GetNodesForTypeImpl(eNetObjType obj_type);
		void InitImpl();

		static Nodes& GetInstance()
		{
			static Nodes Instance;
			return Instance;
		}

	public:
		static void Init()
		{
			std::lock_guard guard(GetInstance().m_InitMutex);
			if (!GetInstance().m_Initialized)
				GetInstance().InitImpl();
		}

		static void Reset()
		{
			std::lock_guard guard(GetInstance().m_InitMutex);
			GetInstance().m_Finder.m_SyncTressSyncNodeAddrToIds = {};
			GetInstance().m_Initialized                         = false;
		}

		static SyncNodeId& Find(eNetObjType obj_type, uintptr_t addr)
		{
			return GetInstance().FindImpl(obj_type, addr);
		}

		static SyncNodeVftToIds& GetNodesForType(eNetObjType obj_type)
		{
			return GetInstance().GetNodesForTypeImpl(obj_type);
		}
	};
}