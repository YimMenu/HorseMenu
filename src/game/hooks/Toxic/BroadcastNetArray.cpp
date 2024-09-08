#include "core/commands/BoolCommand.hpp"
#include "core/commands/IntCommand.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/Self.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/ScriptGlobal.hpp"

#include <random>
#include <script/globals/ACEHostData.hpp>
#include <script/globals/PlayerPersonaData.hpp>

namespace YimMenu::Hooks
{
	unsigned int Toxic::BroadcastNetArray(void* array, CNetGamePlayer* target, rage::datBitBuffer* buffer, std::uint16_t counter, std::uint32_t* elem_start)
	{
		auto data = *(void**)(((__int64)array) + 0x1D8);

		ACEHostRuntimeState oldHostStateVal{};
		bool needToUseSessionSplitKick = ScriptGlobal(1207480).As<void*>() == data && Player(target).GetData().m_UseSessionSplitKick;
		if (needToUseSessionSplitKick)
		{
			oldHostStateVal =
			    ScriptGlobal(1207480).As<ACE_HOST_DATA*>()->RuntimeData.RuntimeMissionDatas[0].Locations[0].State;
			ScriptGlobal(1207480).As<ACE_HOST_DATA*>()->RuntimeData.RuntimeMissionDatas[0].Locations[0].State = ACEHostRuntimeState::ACTIVE;
			*Pointers.NetArrayPatch = 0xEB;
		}

		auto ret = BaseHook::Get<Toxic::BroadcastNetArray, DetourHook<decltype(&Toxic::BroadcastNetArray)>>()->Original()(array, target, buffer, counter, elem_start);

		if (needToUseSessionSplitKick)
		{
			ScriptGlobal(1207480).As<ACE_HOST_DATA*>()->RuntimeData.RuntimeMissionDatas[0].Locations[0].State = oldHostStateVal;
			*Pointers.NetArrayPatch = 0x74;
		}

		return ret;
	}
}