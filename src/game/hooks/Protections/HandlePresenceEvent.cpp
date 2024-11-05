#include "core/commands/BoolCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
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
	void Protections::HandlePresenceEvent(int localGamerIndex, __int64 data, __int64 source)
	{
		const auto payload = *(char**)(data + 8);

		if (Features::_LogPresenceEvents.GetState())
		{
			LOG(VERBOSE) << "HandlePresenceEvent :: " << payload;
		}

		BaseHook::Get<Protections::HandlePresenceEvent, DetourHook<decltype(&Protections::HandlePresenceEvent)>>()->Original()(localGamerIndex, data, source);

		#if 0
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

		std::string sender_str = "NULL";
		if (!event_payload["d"].is_null() && !event_payload["d"]["n"].is_null())
		{
			sender_str = event_payload["d"]["n"];
		}

		uint32_t presence_hash = Joaat(event_payload["e"].get<std::string_view>());

		if (Features::_LogPresenceEvents.GetState())
		{
			LOG(VERBOSE) << "Hash of Presence Event: " << std::to_string(presence_hash) << " Sender: " << sender_str << " Channel: " << std::string(channel);
			LOG(VERBOSE) << "Payload(Raw JSON): " << json.dump();
		}

		switch (presence_hash)
		{
		case (uint32_t)PresenceEvents::PRESENCE_ADMIN_JOIN_EVENT:
		{
			Notifications::Show("Presence Event", std::string("A Rockstar Games Admin ").append(sender_str).append(" is joining your game!"), NotificationType::Warning);
			LOG(WARNING) << "A Rockstar Games Admin(" << sender_str << ")"
			             << "is joining your game";
			break;
		}
		case (uint32_t)PresenceEvents::PRESENCE_TEXT_MESSAGE:
		{
			Notifications::Show("Presence Event", std::string("Blocked Text Message from ").append(sender_str), NotificationType::Warning);
			LOG(WARNING) << "Blocked Text Message from " << sender_str;
			return true;
		}
		case (uint32_t)PresenceEvents::PRESENCE_JOIN_REQUEST:
		{
			Notifications::Show("Presence Event", std::string(sender_str).append(" is joining"), NotificationType::Warning);
			LOG(WARNING) << "Received Join Request from " << sender_str;
			break;
		}
		case (uint32_t)PresenceEvents::PRESENCE_STAT_UPDATE:
		{
			Notifications::Show("Presence Event", std::string("Received Stat Update from ").append(sender_str), NotificationType::Warning);
			LOG(WARNING) << "Received Stat Update from " << sender_str;
			break;
		}
		}

		return ret;
		#endif
	}
}