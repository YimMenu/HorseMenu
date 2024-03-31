#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class SuperDamage : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
				const float DAMAGE_MULT = 100000000.0;
				PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_PED_ID()), DAMAGE_MULT);
				PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_PED_ID()), DAMAGE_MULT);
				PLAYER::_SET_PLAYER_EXPLOSIVE_WEAPON_DAMAGE_MODIFIER(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_PED_ID()), DAMAGE_MULT);
		}

		virtual void OnDisable() override
		{
			// Set all player weapon damage modifiers to their defaults
			PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_PED_ID()), 1.0);
			PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_PED_ID()), 1.0);
			PLAYER::_SET_PLAYER_EXPLOSIVE_WEAPON_DAMAGE_MODIFIER(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_PED_ID()), 1.0);
		}
	};

	static SuperDamage _SuperDamage{"superdamage", "Super Damage", "Multiplies your damage output for All weapons (includes melee)"};
}
