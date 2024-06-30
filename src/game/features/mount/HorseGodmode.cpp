#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	// Doesn't work
	class HorseGodmode : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			ENTITY::SET_ENTITY_INVINCIBLE(Self::Mount, true);
		}

        virtual void OnDisable() override
        {
			ENTITY::SET_ENTITY_INVINCIBLE(Self::Mount, false);
        }
	};

	static HorseGodmode _HorseGodmode{"horsegodmode", "Godmode", "Blocks all incoming damage for your horse"};
}
