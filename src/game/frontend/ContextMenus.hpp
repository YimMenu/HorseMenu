#pragma once
#include "ContextMenu.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"
#include "util/teleport.hpp"

namespace YimMenu
{
	inline ContextOperationsMenu ContextMenuDefault = ContextOperationsMenu("Default",
	    {
	        ContextMenuOperation{"Error",
	            [&] {
		            
	            }}
	    });

	inline ContextOperationsMenu ContextMenuPlayers = ContextOperationsMenu("Players",
	{
	        ContextMenuOperation
		{"Teleport to player", [&] {
			auto playerPos = ENTITY::GET_ENTITY_COORDS(ContextMenu::GetEntityHandle(), false, true);
			Teleport::TeleportEntity(Self::PlayerPed, playerPos);
		}},
		{"Explode", [&] {
			auto playerPos = ENTITY::GET_ENTITY_COORDS(ContextMenu::GetEntityHandle(), false, true);
		    FIRE::ADD_EXPLOSION(playerPos.x, playerPos.y, playerPos.z, 22, 1.0f, true, false, 1.0f);
		}},

	});
}