#include "core/commands/BoolCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Natives.hpp"

#include <network/sync/player/CPlayerHealthData.hpp>


namespace YimMenu::Features
{
	BoolCommand _HideGod("hidegod", "Hide Godmode", "Hides godmode from other players");
}

namespace YimMenu::Hooks
{
	void Spoofing::WritePlayerHealthData(void* iface, CPlayerHealthData* data)
	{
		BaseHook::Get<Spoofing::WritePlayerHealthData, DetourHook<decltype(&Spoofing::WritePlayerHealthData)>>()->Original()(iface, data);

		if (Features::_HideGod.GetState())
		{
			memset(data, 0, sizeof(data));
			data->m_Unused = 100.0f; // default value
		}
	}
}