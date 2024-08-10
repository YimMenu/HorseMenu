#include "core/commands/BoolCommand.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"

#include <network/sync/player/CPlayerHealthData.hpp>


namespace YimMenu::Hooks
{
	void Spoofing::WritePlayerHealthData(void* iface, CPlayerHealthData* data)
	{
		#if 0
		BaseHook::Get<Spoofing::WritePlayerHealthData, DetourHook<decltype(&Spoofing::WritePlayerHealthData)>>()->Original()(iface, data);

		if (Features::_HideGod.GetState())
		{
			memset(data, 0, sizeof(data));
			data->m_Unused = 100.0f; // default value
		}
		#endif
	}
}