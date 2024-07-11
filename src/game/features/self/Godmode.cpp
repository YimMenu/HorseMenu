#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class Godmode : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (!Self::PlayerPed || PED::IS_PED_DEAD_OR_DYING(Self::PlayerPed, TRUE) || ENTITY::IS_ENTITY_DEAD(Self::PlayerPed))
			{
				ENTITY::SET_ENTITY_INVINCIBLE(Self::PlayerPed, FALSE);
				return;
			}

			ENTITY::SET_ENTITY_INVINCIBLE(Self::PlayerPed, TRUE);
		}

		virtual void OnDisable() override
		{
			ENTITY::SET_ENTITY_INVINCIBLE(Self::PlayerPed, FALSE);
		}
	};

	static Godmode _Godmode{"godmode", "God Mode", "Blocks all incoming damage"};
}