#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "core/player_database/PlayerDatabase.hpp"
#include "game/backend/Players.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/ScriptGlobal.hpp"


namespace YimMenu::Hooks
{
	bool Protections::ReceiveArrayUpdate(void* array, CNetGamePlayer* sender, rage::datBitBuffer* buffer, int size, int16_t cycle)
	{
		auto data        = *(void**)(((__int64)array) + 0x1D8);
		int hostStateVal = *ScriptGlobal(1207480).At(2505).At(0, 6).At(0, 3).As<int*>();

		auto ret =
		    BaseHook::Get<Protections::ReceiveArrayUpdate, DetourHook<decltype(&Protections::ReceiveArrayUpdate)>>()->Original()(array, sender, buffer, size, cycle);

		if (ScriptGlobal(1207480).As<void*>() == data && *ScriptGlobal(1207480).At(2505).At(0, 6).At(0, 3).As<int*>() == 2)
		{
			*ScriptGlobal(1207480).At(2505).At(0, 6).At(0, 3).As<int*>() = hostStateVal;

			auto plyr = Player(sender);
			Notifications::Show("Protections", std::string("Blocked Split Session Kick from ").append(plyr.GetName()), NotificationType::Warning);
			g_PlayerDatabase->AddInfraction(g_PlayerDatabase->GetOrCreatePlayer(plyr.GetRID(), plyr.GetName()), (int)PlayerDatabase::eInfraction::TRIED_KICK_PLAYER);
		}

		return ret;
	}
}