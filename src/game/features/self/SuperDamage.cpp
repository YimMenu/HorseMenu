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
				PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(Self::PlayerPed, std::numeric_limits<float>::max());
				PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(Self::PlayerPed, std::numeric_limits<float>::max());
				PLAYER::_SET_PLAYER_EXPLOSIVE_WEAPON_DAMAGE_MODIFIER(Self::PlayerPed, std::numeric_limits<float>::max());
		}

		virtual void OnDisable() override
		{
			// Set all player weapon damage modifiers to their defaults
			PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(Self::PlayerPed, 1.0);
			PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(Self::PlayerPed, 1.0);
			PLAYER::_SET_PLAYER_EXPLOSIVE_WEAPON_DAMAGE_MODIFIER(Self::PlayerPed, 1.0);
		}
	};

	static SuperDamage _SuperDamage{"superdamage", "Super Damage", "Multiplies your damage output for All weapons (includes melee)"};
}
