#include "core/commands/BoolCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Enums.hpp"
#include "util/Joaat.hpp"

#include <nlohmann/json.hpp>


namespace YimMenu::Features
{
	BoolCommand _LogPresenceEvents{"logpresenceevents", "Log Presence Events", "Logs Presence Events"};
}


namespace YimMenu::Hooks
{
	bool Protections::HandlePresenceEvent(uint64_t a1, uint64_t a2, uint64_t a3, int64_t payload_original, uint64_t a5)
	{
		LOG(VERBOSE) << "CALLED";
		try
		{
			const auto payload = reinterpret_cast<char**>(payload_original);
			const char* key    = "gm.evt";

			nlohmann::json json = nlohmann::json::parse(*payload);
			LOG(VERBOSE) << "RAW JSON";
			LOG(VERBOSE) << json.dump();
			if (json[key].is_null())
			{
				if (json["gta5.game.event"].is_null())
				{
					return true; // block it
				}

				key = "gta5.game.event";
			}

			nlohmann::json& event_payload = json[key];
			if (event_payload["e"].is_null() || event_payload["d"].is_null())
			{
				return true;
			}

			std::string sender = "NULL";
			if (!event_payload["d"]["n"].is_null())
			{
				sender = event_payload["d"]["n"];
			}

			uint32_t presence_hash = Joaat(event_payload["e"].get<std::string_view>());

			if (Features::_LogPresenceEvents.GetState())
			{
				LOG(VERBOSE) << "Hash of Presence Event: " << std::to_string(presence_hash) << " Sender: " << sender;
			}


			switch (presence_hash)
			{
			case (uint32_t)ePresenceEvents::PRESENCE_ADMIN_JOIN_EVENT:
			{
				Notifications::Show("Presence Event", std::string("A Rockstar Games Admin ").append(sender).append(" is joining your game!"), NotificationType::Warning);
				break;
			}
			case (uint32_t)ePresenceEvents::PRESENCE_TEXT_MESSAGE:
			{
				Notifications::Show("Presence Event", std::string("Blocked Text Message from ").append(sender), NotificationType::Warning);
				return true;
			}
			case (uint32_t)ePresenceEvents::PRESENCE_JOIN_REQUEST:
			{
				Notifications::Show("Presence Event", std::string("Blocked Join from ").append(sender), NotificationType::Warning);
				return true;
			}
			case (uint32_t)ePresenceEvents::PRESENCE_STAT_UPDATE:
			{
				Notifications::Show("Presence Event", std::string("Received Stat Update"), NotificationType::Warning);
				break;
			}
			}
		}
		catch (std::exception& ex)
		{
			LOG(WARNING) << "HandlePresenceEvent threw an exception: " << ex.what();
			return true; // block it for safety
		}

		return BaseHook::Get<Protections::HandlePresenceEvent, DetourHook<decltype(&Protections::HandlePresenceEvent)>>()
		    ->Original()(a1, a2, a3, payload_original, a5);
	}
}