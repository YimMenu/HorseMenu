#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu
{
	class FlamingHooves : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnEnable() override
		{
			PED::SET_PED_CONFIG_FLAG(Self::Mount, 207, true);
		}

		virtual void OnTick() override
		{
			if (!PED::GET_PED_CONFIG_FLAG(Self::Mount, 207, true))
				PED::SET_PED_CONFIG_FLAG(Self::Mount, 207, true);
		}

		virtual void OnDisable() override
		{
			PED::SET_PED_CONFIG_FLAG(Self::Mount, 207, false);
		}
	};

	static FlamingHooves _FlamingHooves{"flaminghooves", "Flaming Hooves", "Your horse will have flaming hooves."};
}