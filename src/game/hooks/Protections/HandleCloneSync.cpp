#include "core/hooking/DetourHook.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/Protections.hpp"
#include "game/backend/Self.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Enums.hpp"
#include "game/pointers/Pointers.hpp"

#include <network/CNetGamePlayer.hpp>

namespace YimMenu::Hooks
{
	int Protections::HandleCloneSync(void* mgr, CNetGamePlayer* src, CNetGamePlayer* dst, uint16_t objectType, uint16_t objectId, rage::datBitBuffer* buffer, int a7, int a8, void* a9)
	{
		if (Self::GetPed() && Self::GetPed().GetNetworkObjectId() == objectId)
		{
			Notifications::Show("Protections", std::format("Blocked player sync crash from {}", src->GetName()), NotificationType::Warning);
			Player(src).AddDetection(Detection::TRIED_CRASH_PLAYER);
			return 0;
		}

		if (Self::GetMount() && Self::GetMount().GetNetworkObjectId() == objectId && Self::GetMount().HasControl())
		{
			Notifications::Show("Protections", std::format("Blocked kick from mount from {}", src->GetName()), NotificationType::Warning);
			return 0;
		}

		YimMenu::Protections::SetSyncingPlayer(src);
		auto result = BaseHook::Get<Protections::HandleCloneSync, DetourHook<decltype(&Protections::HandleCloneSync)>>()->Original()(mgr, src, dst, objectType, objectId, buffer, a7, a8, a9);
		YimMenu::Protections::SetSyncingPlayer(nullptr);
		return result;
	}
}