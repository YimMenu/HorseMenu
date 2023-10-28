#pragma once
#include "ContextMenu.hpp"
#include "game/backend/Players.hpp"
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
	        {"Teleport to player",
	            [&] {
		            auto playerPos = ENTITY::GET_ENTITY_COORDS(ContextMenu::GetEntityHandle(), false, true);
		            Teleport::TeleportEntity(Self::PlayerPed, playerPos, false);
	            }},
	        {"Explode",
	            [&] {
		            auto playerPos = ENTITY::GET_ENTITY_COORDS(ContextMenu::GetEntityHandle(), false, true);
		            FIRE::ADD_EXPLOSION(playerPos.x, playerPos.y, playerPos.z, 22, 1.0f, true, false, 1.0f);
	            }},

	    });
}