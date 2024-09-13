#include "core/commands/BoolCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/backend/Players.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "game/rdr/data/ScriptNames.hpp"
#include "util/Joaat.hpp"

#include <script/globals/ACEHostData.hpp>

namespace YimMenu::Hooks
{
	bool Protections::ReceiveArrayUpdate(void* array, CNetGamePlayer* sender, rage::datBitBuffer* buffer, int size, int16_t cycle)
	{
		auto data = *(void**)(((__int64)array) + 0x1D8);

		auto ret =
		    BaseHook::Get<Protections::ReceiveArrayUpdate, DetourHook<decltype(&Protections::ReceiveArrayUpdate)>>()->Original()(array, sender, buffer, size, cycle);

		if (ScriptGlobal(1207480).As<void*>() == data)
		{
			auto data = ScriptGlobal(1207480).As<ACE_HOST_DATA*>();
			for (int i = 0; i < data->Missions.Datas.Size; i++)
			{
				if (data->RuntimeData.RuntimeMissionDatas[i].Locations[0].State == ACEHostRuntimeState::ACTIVE)
				{
					if (data->Missions.Datas[i].ScriptHash == "net_session_split"_J)
					{
						auto plyr = Player(sender);
						Notifications::Show("Protections", std::format("Blocked session split kick from {}", plyr.GetName()), NotificationType::Warning);
						plyr.AddDetection(Detection::TRIED_KICK_PLAYER);

						data->Missions.Datas[i].ScriptHash                          = 0;
						data->RuntimeData.RuntimeMissionDatas[i].Locations[0].State = ACEHostRuntimeState::INVALID;
					}
				}
			}
		}

		return ret;
	}
}