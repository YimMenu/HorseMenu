#include "core/commands/BoolCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "core/player_database/PlayerDatabase.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Enums.hpp"
#include "util/Joaat.hpp"

#include <network/rlGamerInfo.hpp>
#include <nlohmann/json.hpp>


namespace YimMenu::Features
{
	BoolCommand _LogPresenceEvents{"logpresenceevents", "Log Presence Events", "Logs Presence Events"};
}


namespace YimMenu::Hooks
{
	bool Protections::HandlePresenceEvent(uint64_t a1, rage::rlGamerInfo* gamerInfo, unsigned int sender, const char** payload, const char* channel)
	{
		const char* key = "gm.evt";
		std::string p(*payload);

		nlohmann::json json = nlohmann::json::parse(p);
		if (json[key].is_null())
		{
			if (json["gta5.game.event"].is_null())
			{
				return true; // block it
			}

			key = "gta5.game.event";
		}

		nlohmann::json& event_payload = json[key];
		LOG(VERBOSE) << event_payload.dump();
		if (event_payload["e"].is_null() || event_payload["d"].is_null())
		{
			return true;
		}

		std::string sender_str = "NULL";
		if (!event_payload["d"]["n"].is_null())
		{
			sender_str = event_payload["d"]["n"];
		}

		uint32_t presence_hash = Joaat(event_payload["e"].get<std::string_view>());

		if (Features::_LogPresenceEvents.GetState())
		{
			LOG(VERBOSE) << "Hash of Presence Event: " << std::to_string(presence_hash) << " Sender: " << sender_str << " Channel: " << channel;
		}

		switch (presence_hash)
		{
		case (uint32_t)ePresenceEvents::PRESENCE_ADMIN_JOIN_EVENT:
		{
			Notifications::Show("Presence Event", std::string("A Rockstar Games Admin ").append(sender_str).append(" is joining your game!"), NotificationType::Warning);
			break;
		}
		case (uint32_t)ePresenceEvents::PRESENCE_TEXT_MESSAGE:
		{
			Notifications::Show("Presence Event", std::string("Blocked Text Message from ").append(sender_str), NotificationType::Warning);
			return true;
		}
		case (uint32_t)ePresenceEvents::PRESENCE_JOIN_REQUEST:
		{
			if (auto plyr = g_PlayerDatabase->GetPlayer(gamerInfo->m_GamerHandle.m_rockstar_id); plyr != nullptr && plyr->block_join)
			{
				Notifications::Show("Presence Event", std::string("Blocked ").append(sender_str).append(" from joining"), NotificationType::Warning);
				return true;
			}
			else
				break;
		}
		case (uint32_t)ePresenceEvents::PRESENCE_STAT_UPDATE:
		{
			Notifications::Show("Presence Event", std::string("Received Stat Update"), NotificationType::Warning);
			break;
		}
		}

		return BaseHook::Get<Protections::HandlePresenceEvent, DetourHook<decltype(&Protections::HandlePresenceEvent)>>()
		    ->Original()(a1, gamerInfo, sender, payload, channel);
	}
}