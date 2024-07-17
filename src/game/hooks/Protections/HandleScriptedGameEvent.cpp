#include "core/commands/BoolCommand.hpp"
#include "core/hooking/DetourHook.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/misc/RateLimiter.hpp"
#include "game/backend/Protections.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/data/TickerEvents.hpp"
#include "game/backend/Players.hpp"

#include <network/CNetGamePlayer.hpp>
#include <network/CScriptedGameEvent.hpp>

namespace YimMenu::Features
{
	BoolCommand _LogScriptEvents("logtses", "Log Script Events", "Log script events");
}

namespace YimMenu::Hooks
{
	bool Protections::HandleScriptedGameEvent(CScriptedGameEvent* event, CNetGamePlayer* src, CNetGamePlayer* dst)
	{
		if (Features::_LogScriptEvents.GetState())
		{
			std::string script_args = "{ ";
			for (std::size_t i = 0; i < event->m_DataSize / 8; i++)
			{
				if (i)
					script_args += ", ";

				script_args += std::to_string((int)event->m_Data[i]);
			}
			script_args += " };";

			LOG(VERBOSE) << "Script Event:\n"
			             << "\tPlayer: " << src->GetName() << "\n"
			             << "\tArgs: " << script_args 
				         << "\tScript: " << HEX(event->m_ScriptId.m_ScriptHash) 
				         << "\tHas Metadata Index: " << (event->m_HasScriptMetadataIdx ? "YES" : "NO")
				         << "\tID Overriden: " << (event->m_ScriptIdOverridden ? "YES" : "NO") 
						 << "\tMetadata Index: " << event->m_ScriptMetadataIndex;
		}

		auto evnt_id = static_cast<ScriptEvent>((int)event->m_Data[0]);
		switch (evnt_id)
		{
		case ScriptEvent::SCRIPT_EVENT_PERSONA_HONOR:
		{
			if (event->m_Data[4] == 2)
			{
				Notifications::Show("Protections", std::format("Blocked honor manipulation from {}", src->GetName()), NotificationType::Warning);
				return true;
			}
			break;
		}
		case ScriptEvent::SCRIPT_EVENT_NOTORIETY_FORCE_PASSIVE:
		{
			if (event->m_Data[8] ==	2)
			{
				Notifications::Show("Protections", std::format("Blocked force defensive mode from {}", src->GetName()), NotificationType::Warning);
				return true;
			}
			break;
		}
		case ScriptEvent::SCRIPT_EVENT_NOTORIETY_PRESS_CHARGES:
		{
			if (event->m_Data[11] && event->m_Data[4] == 2 || event->m_Data[4] == 3)
			{
				Notifications::Show("Protections", std::format("Blocked press charges from {}", src->GetName()), NotificationType::Warning);
				return true;
			}
			break;
		}
		case ScriptEvent::SCRIPT_EVENT_PARLAY:
		{
			if (event->m_Data[4] == 3)
			{
				Notifications::Show("Protections", std::format("Blocked start parlay from {}", src->GetName()), NotificationType::Warning);
				return true;
			}
			if (event->m_Data[4] == 5)
			{
				Notifications::Show("Protections", std::format("Blocked end parlay from {}", src->GetName()), NotificationType::Warning);
				return true;
			}
			break;
		}
		}

		return BaseHook::Get<Protections::HandleScriptedGameEvent, DetourHook<decltype(&Protections::HandleScriptedGameEvent)>>()
		    ->Original()(event, src, dst);
	}
}