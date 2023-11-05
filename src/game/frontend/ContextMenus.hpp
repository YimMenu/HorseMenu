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
	inline ContextOperationsMenu ContextMenuDefault = ContextOperationsMenu("Default", {ContextMenuOperation{"Error", [&] (Entity){

	                                                                                                         }}});

	inline ContextOperationsMenu ContextMenuPlayers = ContextOperationsMenu("Players",
	    {
	        ContextMenuOperation{"Set Selected",
	            [&] (Entity entity) {
		            for (auto& [id, plyr] : YimMenu::Players::GetPlayers())
			            if (plyr.IsValid() && plyr.GetPed().GetPointer<void*>())
				            if (entity == PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(id))
				            {
					            YimMenu::Players::SetSelected(id);
					            break;
				            }
	            }},
	        {"Teleport to",
	            [&] (Entity entity) {
		            Teleport::TeleportEntity(Self::PlayerPed, entity.GetPosition(), false);
	            }},
	        {"Teleport Behind",
	            [&] (Entity entity) {
		            auto playerCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(entity.GetHandle(), 0, -10, 0);
		            if (Teleport::TeleportEntity(Self::PlayerPed, {playerCoords.x, playerCoords.y, playerCoords.z}, true))
			            g_Spectating = false;
	            }},
	        {"Explode",
	            [&] (Entity entity) {
		            int playerId = -1;
		            for (auto& [id, plyr] : YimMenu::Players::GetPlayers())
			            if (plyr.IsValid() && plyr.GetPed().GetPointer<void*>())
				            if (entity == PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(id))
				            {
					            playerId = id;
					            break;
				            }
		            Commands::GetCommand<PlayerCommand>("explode"_J)->Call(playerId);
	            }},
	        {"Set Defensive",
	            [&] (Entity entity) {
		            int playerId = -1;
		            for (auto& [id, plyr] : YimMenu::Players::GetPlayers())
			            if (plyr.IsValid() && plyr.GetPed().GetPointer<void*>())
				            if (entity == PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(id))
				            {
					            playerId = id;
					            break;
				            }
		            Commands::GetCommand<PlayerCommand>("defensive"_J)->Call(playerId);
	            }},
	        {"Set Offensive",
	            [&] (Entity entity) {
		            int playerId = -1;
		            for (auto& [id, plyr] : YimMenu::Players::GetPlayers())
			            if (plyr.IsValid() && plyr.GetPed().GetPointer<void*>())
				            if (entity == PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(id))
				            {
					            playerId = id;
					            break;
				            }
		            Commands::GetCommand<PlayerCommand>("offensive"_J)->Call(playerId);
	            }},
	    });
}