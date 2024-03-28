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
			PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Self::PlayerPed), 1000000000.0);
		}

		virtual void OnDisable() override
		{
			PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Self::PlayerPed), 1.0);
		}
	};

	static SuperDamage _SuperDamage{"superdamage", "Super Damage", "Multiplies your damage output for instant kills"};
}
