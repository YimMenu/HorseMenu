#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	class Godmode : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (!Self::GetPed())
				return;

			if (Self::GetPed().IsDead())
				Self::GetPed().SetInvincible(false);
			else
				Self::GetPed().SetInvincible(true);
			Self::GetPed().SetTargetActionDisableFlag(13, true);
			Self::GetPed().SetTargetActionDisableFlag(16, true);
			Self::GetPed().SetTargetActionDisableFlag(17, true);
		}

		virtual void OnDisable() override
		{
			if (!Self::GetPed())
				return;

			Self::GetPed().SetInvincible(false);
			Self::GetPed().SetTargetActionDisableFlag(13, false);
			Self::GetPed().SetTargetActionDisableFlag(16, false);
			Self::GetPed().SetTargetActionDisableFlag(17, false);
		}
	};

	static Godmode _Godmode{"godmode", "God Mode", "Blocks all incoming damage"};
}