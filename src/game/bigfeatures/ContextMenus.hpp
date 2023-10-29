#pragma once
#include "ContextMenu.hpp"
#include "core/commands/Commands.hpp"
#include "game/backend/Players.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"
#include "util/teleport.hpp"


namespace YimMenu
{
	inline ContextOperationsMenu ContextMenuDefault = ContextOperationsMenu("Default", {ContextMenuOperation{"Error", [&] {

	                                                                                                         }}});

	inline ContextOperationsMenu ContextMenuPlayers = ContextOperationsMenu("Players",
	    {
	        ContextMenuOperation{"Set Selected",
	            [&] {
		            for (auto [id, plyr] : YimMenu::Players::GetPlayers())
			            if (plyr.IsValid() && plyr.GetPed().GetPointer<void*>())
				            if (ContextMenu::GetEntityHandle() == PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(id))
				            {
					            YimMenu::Players::SetSelected(id);
					            break;
				            }
	            }},
	        {"Teleport to",
	            [&] {
		            auto playerPos = ENTITY::GET_ENTITY_COORDS(ContextMenu::GetEntityHandle(), false, true);
		            Teleport::TeleportEntity(Self::PlayerPed, playerPos, false);
	            }},
	        {"Teleport Behind",
	            [&] {
		            auto playerCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(ContextMenu::GetEntityHandle(), 0, -10, 0);
		            if (Teleport::TeleportEntity(Self::PlayerPed, playerCoords, true))
			            g_Spectating = false;
	            }},
	        {"Explode",
	            [&] {
		            auto playerPos = ENTITY::GET_ENTITY_COORDS(ContextMenu::GetEntityHandle(), false, true);
		            FIRE::ADD_EXPLOSION(playerPos.x, playerPos.y, playerPos.z, 22, 1.0f, true, false, 1.0f);
	            }},
	        {"Set Defensive",
	            [&] {
		            int playerId = -1;
		            for (auto [id, plyr] : YimMenu::Players::GetPlayers())
			            if (plyr.IsValid() && plyr.GetPed().GetPointer<void*>())
				            if (ContextMenu::GetEntityHandle() == PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(id))
				            {
					            playerId = id;
					            break;
				            }
		            Commands::GetCommand<PlayerCommand>("defensive"_J)->Call(playerId);
	            }},
	        {"Set Offensive",
	            [&] {
		            int playerId = -1;
		            for (auto [id, plyr] : YimMenu::Players::GetPlayers())
			            if (plyr.IsValid() && plyr.GetPed().GetPointer<void*>())
				            if (ContextMenu::GetEntityHandle() == PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(id))
				            {
					            playerId = id;
					            break;
				            }
		            Commands::GetCommand<PlayerCommand>("offensive"_J)->Call(playerId);
	            }},
	    });
}