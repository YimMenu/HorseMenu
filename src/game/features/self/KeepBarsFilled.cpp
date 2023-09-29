#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class KeepBarsFilled : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			auto health_bar  = ENTITY::GET_ENTITY_HEALTH(Self::PlayerPed);
			auto stamina_bar = PLAYER::_GET_PLAYER_STAMINA(Self::Id);
			auto deadeye_bar = PLAYER::_GET_PLAYER_DEAD_EYE(Self::Id);

			if (health_bar < ENTITY::GET_ENTITY_MAX_HEALTH(Self::PlayerPed, false) && !PED::IS_PED_DEAD_OR_DYING(Self::PlayerPed, true) && !ENTITY::IS_ENTITY_DEAD(Self::PlayerPed))
				ENTITY::SET_ENTITY_HEALTH(Self::PlayerPed, ENTITY::GET_ENTITY_MAX_HEALTH(Self::PlayerPed, false), 0);
			if (stamina_bar < PED::_GET_PED_MAX_STAMINA(Self::PlayerPed))
				PED::_CHANGE_PED_STAMINA(Self::PlayerPed, PED::_GET_PED_MAX_STAMINA(Self::PlayerPed));
			if (deadeye_bar < PLAYER::_GET_PLAYER_MAX_DEAD_EYE(Self::Id, 0))
				PLAYER::_SPECIAL_ABILITY_RESTORE_BY_AMOUNT(Self::Id, PLAYER::_GET_PLAYER_MAX_DEAD_EYE(Self::Id, false), 0, 0, 1);
		}
	};

	static KeepBarsFilled _KeepBarsFilled{"keepbarsfilled", "Keep Bars Filled", "Keeps your Health, Stamina and Deadeye filled"};
}