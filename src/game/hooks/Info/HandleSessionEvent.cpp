#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/backend/Players.hpp"
#include "game/hooks/Hooks.hpp"

#include <network/rlScSessionEvent.hpp>


namespace YimMenu::Hooks
{
	void Info::HandleSessionEvent(rage::rlScSessionMultiplayer* mp, CNetworkScServerConnection* cxn, rage::rlScSessionEvent* evt)
	{
		switch (evt->m_EventType)
		{
		case rage::SessionEvent::ADD_PLAYER:
		{
			auto event = reinterpret_cast<rage::rlScAddPlayerEvent*>(evt);
			LOGF(VERBOSE,
			    "Adding player RID={} RID2={} acctId={} IP={}.{}.{}.{}:{} {}",
			    event->m_Identifier.m_Handle.m_RockstarId,
			    event->m_PeerAddress.m_GamerHandle.m_RockstarId,
			    event->m_Identifier.m_AccountId,
			    event->m_PeerAddress.m_ExternalAddress.m_field1,
			    event->m_PeerAddress.m_ExternalAddress.m_field2,
			    event->m_PeerAddress.m_ExternalAddress.m_field3,
			    event->m_PeerAddress.m_ExternalAddress.m_field4,
			    event->m_PeerAddress.m_ExternalPort,
			    event->m_PeerAddress.m_RelayState);

			break;
		}
		case rage::SessionEvent::LEAVE_SESSION:
		{
			auto event = reinterpret_cast<rage::rlScLeaveSessionEvent*>(evt);
			LOG(INFO) << "Leave session: reason = " << event->m_Reason << " reason2 = " << event->m_Reason2;
			break;
		}
		}
		return BaseHook::Get<Info::HandleSessionEvent, DetourHook<decltype(&Info::HandleSessionEvent)>>()->Original()(mp, cxn, evt);
	}
}