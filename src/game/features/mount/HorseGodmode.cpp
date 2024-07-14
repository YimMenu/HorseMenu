#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	class HorseGodmode : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (Self::GetMount())
				Self::GetMount().SetInvincible(true);
		}

        virtual void OnDisable() override
        {
			if (Self::GetMount())
				Self::GetMount().SetInvincible(false);
        }
	};

	static HorseGodmode _HorseGodmode{"horsegodmode", "Godmode", "Blocks all incoming damage for your horse"};
}