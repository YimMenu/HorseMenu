#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	class Godmode : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (Self::GetPed().IsDead())
				Self::GetPed().SetInvincible(false);
			else
				Self::GetPed().SetInvincible(true);
		}

		virtual void OnDisable() override
		{
			Self::GetPed().SetInvincible(true);
		}
	};

	static Godmode _Godmode{"godmode", "God Mode", "Blocks all incoming damage"};
}