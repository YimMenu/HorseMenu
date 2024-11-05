#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "util/Joaat.hpp"

#include <unordered_set>

namespace YimMenu::Hooks
{
	const std::unordered_set<std::uint32_t> g_NetPedPools = {"CAnimalSyncData"_J, "CNetObjPedBase"_J, "CPedSyncData"_J};
	const std::unordered_set<std::uint32_t> g_NetPedPlusPlayerPools = {"CNetBlenderPed"_J, "CNetworkDamageTracker"_J};

	static int g_PedPoolsPatched = 0;
	static int g_PedPlusPlayerPoolsPatched = 0;

	int Misc::GetPoolSize(void* config, std::uint32_t hash, int def)
	{
		int value = BaseHook::Get<Misc::GetPoolSize, DetourHook<decltype(&Misc::GetPoolSize)>>()->Original()(config, hash, def);

		if (g_NetPedPools.contains(hash))
		{
			g_PedPoolsPatched++;
			value = 150;
		}
		else if (g_NetPedPlusPlayerPools.contains(hash))
		{
			g_PedPlusPlayerPoolsPatched++;
			value = 150 + 32;
		}

		if (g_NetPedPools.size() == g_PedPoolsPatched && g_NetPedPlusPlayerPools.size() == g_PedPlusPlayerPoolsPatched)
		{
			static bool once = [] {
				*Pointers.MaxNetworkPeds = 150;
				LOG(INFO) << "Network ped pools patched successfully";
				return true;
			}();
		}

		return value; 
	}
}