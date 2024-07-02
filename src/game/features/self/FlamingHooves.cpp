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
			PED::SET_PED_CONFIG_FLAG(Self::Mount, 207, TRUE);
		}

		virtual void OnTick() override
		{
			if (!PED::GET_PED_CONFIG_FLAG(Self::Mount, 207, TRUE))
				PED::SET_PED_CONFIG_FLAG(Self::Mount, 207, TRUE);
		}

		virtual void OnDisable() override
		{
			PED::SET_PED_CONFIG_FLAG(Self::Mount, 207, FALSE);
		}
	};

	static FlamingHooves _FlamingHooves{"flaminghooves", "Flaming Hooves", "Your horse will have flaming hooves."};
}