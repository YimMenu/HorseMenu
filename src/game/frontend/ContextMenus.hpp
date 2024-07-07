#pragma once
#include "ContextMenu.hpp"
#include "core/commands/Commands.hpp"
#include "game/backend/Players.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "util/teleport.hpp"


namespace YimMenu
{
	inline ContextOperationsMenu ContextMenuDefault = ContextOperationsMenu("Default", {ContextMenuOperation{"Error", [&](Entity) {}}});

	inline ContextOperationsMenu ContextMenuPlayers = ContextOperationsMenu("Players",
	    {
	        ContextMenuOperation{"Set Selected",
	            [&](Entity entity) {
		            YimMenu::Players::SetSelected(entity.As<Ped>().GetPlayer());
	            }},
	        {"Teleport to",
	            [&](Entity entity) {
		            Teleport::TeleportEntity(Self::GetPed().GetHandle(), entity.GetPosition(), false);
	            }},
	        {"Teleport Behind",
	            [&](Entity entity) {
		            auto playerCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(entity.GetHandle(), 0, -10, 0);
		            Teleport::TeleportEntity(Self::GetPed().GetHandle(), {playerCoords.x, playerCoords.y, playerCoords.z}, true);
	            }},
	        {"Explode",
	            [&](Entity entity) {
		            Commands::GetCommand<PlayerCommand>("explode"_J)->Call(entity.As<Ped>().GetPlayer());
	            }},
	        {"Set Defensive",
	            [&](Entity entity) {
		            Commands::GetCommand<PlayerCommand>("defensive"_J)->Call(entity.As<Ped>().GetPlayer());
	            }},
	        {"Set Offensive",
	            [&](Entity entity) {
		            Commands::GetCommand<PlayerCommand>("offensive"_J)->Call(entity.As<Ped>().GetPlayer());
	            }},
	    });

	inline ContextOperationsMenu ContextMenuPeds = ContextOperationsMenu("Peds",
	    {
	        ContextMenuOperation{"Explode",
	            [&](Entity entity) {
		            auto pedCoords = ENTITY::GET_ENTITY_COORDS(entity.GetHandle(), true, true);
		            FIRE::ADD_EXPLOSION(pedCoords.x, pedCoords.y, pedCoords.z, (int)ExplosionTypes::UNK, 10.0f, true, false, 1.0f);
	            }},
	        {"Kill",
	            [&](Entity entity) {
		            ENTITY::SET_ENTITY_HEALTH(entity.GetHandle(), 0, 0);
	            }},
	        {"Apply Force",
	            [&](Entity entity) {
		            auto currentCoords = ENTITY::GET_ENTITY_COORDS(entity.GetHandle(), true, true);
		            ENTITY::APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(entity.GetHandle(),
		                1,
		                currentCoords.x - 3,
		                currentCoords.y,
		                currentCoords.z,
		                true,
		                false,
		                true,
		                false);
	            }},
	        {"Copy Hash",
	            [&](Entity entity) {
		            Hash modelHash = ENTITY::GET_ENTITY_MODEL(entity.GetHandle());

		            ImGui::SetClipboardText(std::format("0x{:08X}", (joaat_t)modelHash).c_str());
		            LOG(INFO) << std::format("Copied hash 0x{:08X}", (joaat_t)modelHash).c_str();
		            Notifications::Show("Context Menu", std::format("Copied hash 0x{:08X}", (joaat_t)modelHash).c_str(), NotificationType::Info);
	            }},
	    });
}