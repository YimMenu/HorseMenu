#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/backend/Protections.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/Self.hpp"
#include "game/backend/FiberPool.hpp"

#include <network/netObject.hpp>
#include <network/CNetGamePlayer.hpp>

namespace
{
	static int GetNextTokenValue(int prev_token)
	{
		for (int i = 0; i < 0x1F; i++)
		{
			if ((i << 27) - (prev_token << 27) > 0)
				return i;
		}

		return 0;
	}
}

namespace YimMenu::Hooks
{
	int Protections::GetCloneCreateResponse(void* mgr, CNetGamePlayer* sender, CNetGamePlayer* reciever, uint16_t objectId, int flags, uint16_t objectType, rage::datBitBuffer* buffer, int a8, void* guid, bool isQueued)
	{
		if (Self::GetPed() && Self::GetPed().IsNetworked() && objectId == Self::GetPed().GetNetworkObjectId())
		{
			Notifications::Show("Protections", std::format("Blocked player ped removal crash from {}", sender->GetName()), NotificationType::Warning);
			return 1;
		}

		if (Self::GetMount() && Self::GetMount().IsNetworked() && objectId == Self::GetMount().GetNetworkObjectId())
		{
			Self::GetMount().GetNetworkObject()->m_OwnershipToken = GetNextTokenValue(GetNextTokenValue(Self::GetMount().GetNetworkObject()->m_OwnershipToken));
			FiberPool::Push([] {
				if (Self::GetMount())
					Self::GetMount().ForceSync();
			});

			Notifications::Show("Protections", std::format("Blocked kick from mount from {}", sender->GetName()), NotificationType::Warning);
			return 1;
		}

		if (Self::GetVehicle() && Self::GetVehicle().IsNetworked() && objectId == Self::GetVehicle().GetNetworkObjectId())
		{
			Self::GetVehicle().GetNetworkObject()->m_OwnershipToken = GetNextTokenValue(GetNextTokenValue(Self::GetVehicle().GetNetworkObject()->m_OwnershipToken));
			FiberPool::Push([] {
				if (Self::GetVehicle())
					Self::GetVehicle().ForceSync();
			});

			Notifications::Show("Protections", std::format("Blocked kick from vehicle from {}", sender->GetName()), NotificationType::Warning);
			return 1;
		}

		auto ret = BaseHook::Get<Protections::GetCloneCreateResponse, DetourHook<decltype(&Protections::GetCloneCreateResponse)>>()->Original()(mgr, sender, reciever, objectId, flags, objectType, buffer, a8, guid, isQueued);
		return ret;
	}
}