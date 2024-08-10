#include "core/hooking/DetourHook.hpp"
#include "game/backend/PlayerData.hpp"
#include "game/backend/Self.hpp"
#include "game/hooks/Hooks.hpp"

#include <network/CNetGamePlayer.hpp>
#include <network/netObject.hpp>
#include <player/CPlayerInfo.hpp>

namespace YimMenu::Hooks
{
	bool Protections::PackCloneCreate(void* mgr, rage::netObject* object, CNetGamePlayer* dst, rage::datBitBuffer* buffer)
	{
		if (Self::GetPed() && Player(dst).IsValid() && Player(dst).GetData().m_GhostMode && object->m_ObjectId == Self::GetPed().GetNetworkObjectId())
			return false;

		return BaseHook::Get<Protections::PackCloneCreate, DetourHook<decltype(&Protections::PackCloneCreate)>>()->Original()(mgr, object, dst, buffer);
	}
}