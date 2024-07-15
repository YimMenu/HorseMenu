#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu
{
	class FlamingHooves : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			// TODO: cleanup when player leaves horse?
			if (Self::GetMount())
				Self::GetMount().SetConfigFlag(PedConfigFlag::FlamingHoovesActive, true);
		}

		virtual void OnDisable() override
		{
			if (Self::GetMount())
				Self::GetMount().SetConfigFlag(PedConfigFlag::FlamingHoovesActive, false);
		}
	};

	static FlamingHooves _FlamingHooves{"flaminghooves", "Flaming Hooves", "Your horse will have flaming hooves."};
}