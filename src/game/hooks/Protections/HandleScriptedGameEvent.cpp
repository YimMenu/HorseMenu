#include "core/commands/BoolCommand.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/backend/Protections.hpp"
#include "game/hooks/Hooks.hpp"

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
				         << "\tID Overriden: " << (event->m_ScriptIdOverridden ? "YES" : "NO");
		}

		if (event->m_Data[0] == 201)
			return true; // TMP TMP TMP

		return BaseHook::Get<Protections::HandleScriptedGameEvent, DetourHook<decltype(&Protections::HandleScriptedGameEvent)>>()
		    ->Original()(event, src, dst);
	}
}