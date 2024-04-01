#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class HorseGodmode : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
			ENTITY::SET_ENTITY_INVINCIBLE(vehicle, 1);
		}

        virtual void OnDisable() override
        {
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
			ENTITY::SET_ENTITY_INVINCIBLE(vehicle, 0);
        }
	};

	static HorseGodmode _HorseGodmode{"horsegodmode", "Godmode", "Blocks all incoming damage for your horse"};
}
